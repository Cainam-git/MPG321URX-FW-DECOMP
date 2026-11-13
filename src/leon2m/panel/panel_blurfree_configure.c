/* panel_blurfree_configure  (FUN_a01502c4)
 *
 * Validate the blur-reduction PWM parameters and store the derived period, duty and delay.
 * Note: Rejects out-of-range parameters with an error print.
 * Name basis: proven - prints 'ucFirstPort error', 'ucFirstPWMDuty error', 'ucFirstPWMFreq error', ...
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01502c4 @ 0xa01502c4-0xa0150768 (297 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - period_ns (1000000000 / hz) is a static helper, used three times;
 *  - the delay conversion (time -> delay steps) is written out at each of its three uses, its result stored
 *    straight into reference_delay / channel_delay;
 *  - the wrap test is 'if (part_ns <= delay_ns) gap_ns = delay_ns - part_ns; else gap_ns = frame_ns + delay_ns -
 *    part_ns;';
 *  - duty_offset is an unsigned short, updated by 'duty_offset = p->trim + duty_offset - 128' before the call of
 *    panel_pwm_init_group;
 *  - the locals are declared in this order: on_steps before channel_delay, reference_delay, reversed, then
 *    cycle_steps, then second_freq_hz and duty_offset;
 *  - the stores are written in the order second port, duty offset, second frequency, first frequency, on time
 *    (the compiler emits them in another order).
 */

/* The blur reduction parameters, as panel_blurfree_apply_user_mode fills them. The field names are the firmware's
   own (they are printed in the error texts). */
struct blurfree_params {
    unsigned char ucFirstPort;          /* +0x00 mask of the PWM channels of the first signal (bit i = channel i) */
    unsigned char ucFirstPWMDuty;       /* +0x01 duty of the first signal in percent, 1..100 */
    unsigned char ucFirstPWMFreq;       /* +0x02 frequency of the first signal, 31..239 */
    unsigned char ucFirstPWMDelay;      /* +0x03 delay of the first signal in delay steps, 0..128 */
    unsigned char ucSecondPort;         /* +0x04 the port of the second signal, not 0 */
    unsigned char pad5;
    unsigned short usSecondPWMFreq;     /* +0x06 frequency of the second signal in 100 Hz units, 21..500 */
    unsigned char ucSecondPWMNum;       /* +0x08 cycles of the second signal per frame, 1..50 */
    unsigned char pad9;
    unsigned short ucFrameRate;         /* +0x0a frame rate, 31..400 */
    unsigned char trim;                 /* +0x0c added to the duty offset; 128 = no change */
};

/* Limits of the parameters. */
#define DUTY_MIN         1
#define DUTY_MAX         100
#define FIRST_FREQ_MIN   31
#define FIRST_FREQ_MAX   239
#define FIRST_DELAY_MAX  128
#define SECOND_FREQ_MIN  21
#define SECOND_FREQ_MAX  500
#define SECOND_COUNT_MIN 1
#define SECOND_COUNT_MAX 50
#define FRAME_RATE_MIN   31
#define FRAME_RATE_MAX   400

/* A delay of n steps is n * 85.33 us plus a fixed 82 us (in ns: n * 8533 / 100 * 1000 + 82000). The way back
   from a time in us is (us * 100 - 8200) / 8533, and 0 for 82 us or less. */
#define DELAY_STEP_X100  8533
#define DELAY_BASE_NS    82000
#define DELAY_BASE_US    82
#define DUTY_SCALE_SHIFT 10             /* on time, cycle and duty offset are in 1/1024 of the first PWM period */
#define TRIM_ZERO        128

extern unsigned char panel_blurfree_second_port;
extern unsigned short panel_blurfree_first_pwm_freq, panel_blurfree_duty_offset, panel_blurfree_second_pwm_freq, panel_blurfree_cycle_length, panel_blurfree_on_time;
extern unsigned char panel_blurfree_channel_delays, panel_blurfree_channel_delay_1, panel_blurfree_channel_delay_2, panel_blurfree_channel_delay_3, panel_blurfree_channel_delay_4, panel_blurfree_channel_delay_5,
    panel_blurfree_channel_delay_6, panel_blurfree_channel_delay_7;
extern unsigned char panel_blurfree_reversed_mode, panel_blurfree_reference_delay, panel_blurfree_channel_mask, panel_blurfree_second_channel_mask;
extern int dbg_printf(const char *fmt, ...);
extern void panel_pwm_init_group();

/* The length of one cycle at hz: in nanoseconds when hz is in Hz. */
static int period_ns(int hz)
{
    return 1000000000 / hz;
}

/*
 * Check the blur reduction parameters and turn them into the values the blur reduction PWM works with.
 *
 *   p  the parameters (struct blurfree_params); panel_blurfree_apply_user_mode is the caller.
 *
 * Phases:
 *  1. Check each field against its range. The first one out of range is printed as "<field> error" and nothing
 *     is stored.
 *  2. Timing of one frame: the second signal takes ucSecondPWMNum of its cycles; the rest of the frame
 *     (rest_ns) is shared by the first signal's on and off time. If the second signal does not fit into the
 *     frame, return without a print.
 *  3. Normal case: when half the off time is shorter than the requested delay, keep the delay as given; the
 *     reference delay is the difference, in delay steps.
 *  4. Otherwise the reversed case: the duty becomes 100 - duty, and the channel delay and the reference delay are
 *     worked out from the gap between the new on time and the delay (wrapped around the frame). When that gap is
 *     shorter than the new off time, print "BlurFree Error! (rev,delay)" and store nothing.
 *  5. Store everything: second port, duty offset, frequencies, on time, reference delay, cycle length, the
 *     channel masks, the delay of each channel in ucFirstPort, and the reversed flag. panel_pwm_init_group is
 *     called with the second port first (it takes no argument and writes fixed values).
 */
void panel_blurfree_configure(struct blurfree_params *p)
{
    unsigned char first_channels, duty, first_freq, first_delay, second_port, second_count;
    unsigned short second_freq, frame_rate;
    unsigned int burst_ns, frame_ns, rest_ns, delay_ns, step_ns, on_steps, gap_ns, part_ns, time_us;
    unsigned char channel_delay, reference_delay, reversed;
    unsigned int cycle_steps;
    unsigned short second_freq_hz, duty_offset;

    /* 1. Range checks. */
    first_channels = p->ucFirstPort;
    if (first_channels == 0) {
        dbg_printf("ucFirstPort error\r\n");
        return;
    }
    duty = p->ucFirstPWMDuty;
    if (duty < DUTY_MIN || duty > DUTY_MAX) {
        dbg_printf("ucFirstPWMDuty error\r\n");
        return;
    }
    first_freq = p->ucFirstPWMFreq;
    if (first_freq < FIRST_FREQ_MIN || first_freq > FIRST_FREQ_MAX) {
        dbg_printf("ucFirstPWMFreq error\r\n");
        return;
    }
    first_delay = p->ucFirstPWMDelay;
    if (first_delay > FIRST_DELAY_MAX) {
        dbg_printf("ucFirstPWMDelay error\r\n");
        return;
    }
    second_port = p->ucSecondPort;
    if (second_port == 0) {
        dbg_printf("ucSecondPort error\r\n");
        return;
    }
    second_freq = p->usSecondPWMFreq;
    if (second_freq < SECOND_FREQ_MIN || second_freq > SECOND_FREQ_MAX) {
        dbg_printf("usSecondPWMFreq error\r\n");
        return;
    }
    second_count = p->ucSecondPWMNum;
    if (second_count < SECOND_COUNT_MIN || second_count > SECOND_COUNT_MAX) {
        dbg_printf("ucSecondPWMNum error\r\n");
        return;
    }
    frame_rate = p->ucFrameRate;
    if (frame_rate < FRAME_RATE_MIN || frame_rate > FRAME_RATE_MAX) {
        dbg_printf("ucFrameRate error\r\n");
        return;
    }

    /* 2. Timing of one frame. */
    channel_delay = first_delay;
    reversed = 0;
    second_freq_hz = second_freq * 100;
    duty_offset = (duty << DUTY_SCALE_SHIFT) / 100;
    burst_ns = period_ns(second_freq_hz) * second_count;
    frame_ns = period_ns(frame_rate);
    if (frame_ns < burst_ns)
        return;
    rest_ns = frame_ns - burst_ns;
    delay_ns = first_delay * 8533U / 100 * 1000 + DELAY_BASE_NS;
    step_ns = period_ns(first_freq) >> DUTY_SCALE_SHIFT;
    on_steps = duty * rest_ns / 100 / step_ns;
    cycle_steps = rest_ns / step_ns;
    gap_ns = (100 - duty) * rest_ns / 200;          /* half the off time */
    if (gap_ns < delay_ns) {
        /* 3. Normal case. */
        time_us = (delay_ns - gap_ns) / 1000;
        reference_delay = time_us > DELAY_BASE_US ? (time_us * 100 - 8200) / DELAY_STEP_X100 : 0;
    } else {
        /* 4. Reversed case. */
        duty = 100 - duty;
        part_ns = duty * rest_ns / 100;             /* the new on time */
        on_steps = part_ns / step_ns;
        duty_offset = (duty << DUTY_SCALE_SHIFT) / 100;
        if (part_ns <= delay_ns)
            gap_ns = delay_ns - part_ns;
        else
            gap_ns = frame_ns + delay_ns - part_ns;
        part_ns = (100 - duty) * rest_ns / 100;     /* the new off time */
        if (gap_ns < part_ns) {
            dbg_printf("BlurFree Error! (rev,delay)\r\n");
            return;
        }
        time_us = gap_ns / 1000;
        channel_delay = time_us > DELAY_BASE_US ? (time_us * 100 - 8200) / DELAY_STEP_X100 : 0;
        time_us = (gap_ns - part_ns / 2) / 1000;
        reference_delay = time_us > DELAY_BASE_US ? (time_us * 100 - 8200) / DELAY_STEP_X100 : 0;
        reversed = 1;
    }

    /* 5. Store the results. */
    duty_offset = p->trim + duty_offset - TRIM_ZERO;
    panel_pwm_init_group(second_port);
    panel_blurfree_second_port = second_port;
    panel_blurfree_duty_offset = duty_offset;
    panel_blurfree_second_pwm_freq = second_freq_hz;
    panel_blurfree_first_pwm_freq = first_freq;
    panel_blurfree_on_time = on_steps;
    panel_blurfree_reference_delay = reference_delay;
    panel_blurfree_cycle_length = cycle_steps;
    panel_blurfree_channel_mask = first_channels;
    panel_blurfree_second_channel_mask = first_channels;
    /* The same delay for every channel of the first signal. */
    if (first_channels & 0x01)
        panel_blurfree_channel_delays = channel_delay;
    if (first_channels & 0x02)
        panel_blurfree_channel_delay_1 = channel_delay;
    if (first_channels & 0x04)
        panel_blurfree_channel_delay_2 = channel_delay;
    if (first_channels & 0x08)
        panel_blurfree_channel_delay_3 = channel_delay;
    if (first_channels & 0x10)
        panel_blurfree_channel_delay_4 = channel_delay;
    if (first_channels & 0x20)
        panel_blurfree_channel_delay_5 = channel_delay;
    if (first_channels & 0x40)
        panel_blurfree_channel_delay_6 = channel_delay;
    if (first_channels & 0x80)
        panel_blurfree_channel_delay_7 = channel_delay;
    panel_blurfree_reversed_mode = reversed;
}
