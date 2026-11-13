/* panel_blurfree_set_parameter  (FUN_a014bac4)
 *
 * Store one blur-reduction parameter selected by its number 0..18.
 * Name basis: proven - dispatches to the nineteen panel_blurfree_set_* routines
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014bac4 @ 0xa014bac4-0xa014bc58 (101 words), flags -mcpu=v8 -O3 -g.
 * Source form: one switch with one case per number (cases 4..11 are separate arms with the channel bit written
 * out). The value is an unsigned short parameter, converted to the unsigned char or unsigned short of the setter;
 * every call is a tail call.
 */
extern void panel_blurfree_set_on_time(unsigned short);
extern void panel_blurfree_set_first_pwm_freq(unsigned short);
extern void panel_blurfree_set_channel_delays(unsigned char, unsigned char);
extern void panel_blurfree_set_cycle_length(unsigned short);
extern void panel_blurfree_set_reference_delay(unsigned char);
extern void panel_blurfree_set_task_threshold(unsigned short);
extern void panel_blurfree_set_second_pwm_freq(unsigned short);
extern void panel_blurfree_set_duty_offset(unsigned short);
extern void panel_blurfree_set_second_port(unsigned char);
extern void panel_blurfree_set_second_channel_mask(unsigned char);
extern void panel_blurfree_set_channel_mask(unsigned char);
extern void panel_blurfree_set_reversed_mode(unsigned char);


/* Parameter numbers (the first argument). */
enum {
    BLURFREE_PARAM_SECOND_CHANNEL_MASK = 0,     /* second mask of PWM channels */
    BLURFREE_PARAM_CHANNEL_MASK        = 1,     /* mask of the PWM channels used for blur reduction */
    BLURFREE_PARAM_ON_TIME             = 2,     /* on-time of the first PWM signal */
    BLURFREE_PARAM_FIRST_PWM_FREQ      = 3,     /* frequency of the first PWM signal */
    BLURFREE_PARAM_DELAY_CHANNEL_0     = 4,     /* 4..11: delay of PWM channel number - 4 (bit 1 << (number - 4)) */
    BLURFREE_PARAM_DELAY_CHANNEL_7     = 11,
    BLURFREE_PARAM_CYCLE_LENGTH        = 12,    /* cycle length of the first PWM signal */
    BLURFREE_PARAM_REFERENCE_DELAY     = 13,
    BLURFREE_PARAM_TASK_THRESHOLD      = 14,    /* threshold of the periodic blur-reduction task */
    BLURFREE_PARAM_REVERSED_MODE       = 15,    /* duty cycle applied reversed (0 or 1) */
    BLURFREE_PARAM_DUTY_OFFSET         = 16,
    BLURFREE_PARAM_SECOND_PWM_FREQ     = 17,    /* frequency of the second PWM signal, in hundredths */
    BLURFREE_PARAM_SECOND_PORT         = 18     /* port of the second PWM signal */
};

/*
 * Store the value of one blur-reduction parameter: forwards "value" to the panel_blurfree_set_* routine that
 * keeps the parameter. A number above 18 does nothing.
 *
 *   number  BLURFREE_PARAM_*: 0..3, 12..18 select one parameter; 4..11 select the delay of one of eight PWM
 *           channels (the setter gets the channel bit 1 << (number - 4) with the value)
 *   value   the new value; converted to the byte or halfword the setter takes
 *
 * Callers: panel_blurfree_apply_user_mode, pq_apply_settings_by_mask (numbers 4..11, one per bit of its mask) and
 * APPBlurFree_AfterMute (on-time 0x3FF).
 */
void panel_blurfree_set_parameter(unsigned int number, unsigned short value)
{
    switch (number) {
    case BLURFREE_PARAM_SECOND_CHANNEL_MASK:
        panel_blurfree_set_second_channel_mask(value);
        break;
    case BLURFREE_PARAM_CHANNEL_MASK:
        panel_blurfree_set_channel_mask(value);
        break;
    case BLURFREE_PARAM_ON_TIME:
        panel_blurfree_set_on_time(value);
        break;
    case BLURFREE_PARAM_FIRST_PWM_FREQ:
        panel_blurfree_set_first_pwm_freq(value);
        break;
    case 4:
        panel_blurfree_set_channel_delays(0x1, value);
        break;
    case 5:
        panel_blurfree_set_channel_delays(0x2, value);
        break;
    case 6:
        panel_blurfree_set_channel_delays(0x4, value);
        break;
    case 7:
        panel_blurfree_set_channel_delays(0x8, value);
        break;
    case 8:
        panel_blurfree_set_channel_delays(0x10, value);
        break;
    case 9:
        panel_blurfree_set_channel_delays(0x20, value);
        break;
    case 10:
        panel_blurfree_set_channel_delays(0x40, value);
        break;
    case BLURFREE_PARAM_DELAY_CHANNEL_7:
        panel_blurfree_set_channel_delays(0x80, value);
        break;
    case BLURFREE_PARAM_CYCLE_LENGTH:
        panel_blurfree_set_cycle_length(value);
        break;
    case BLURFREE_PARAM_REFERENCE_DELAY:
        panel_blurfree_set_reference_delay(value);
        break;
    case BLURFREE_PARAM_TASK_THRESHOLD:
        panel_blurfree_set_task_threshold(value);
        break;
    case BLURFREE_PARAM_REVERSED_MODE:
        panel_blurfree_set_reversed_mode(value);
        break;
    case BLURFREE_PARAM_DUTY_OFFSET:
        panel_blurfree_set_duty_offset(value);
        break;
    case BLURFREE_PARAM_SECOND_PWM_FREQ:
        panel_blurfree_set_second_pwm_freq(value);
        break;
    case BLURFREE_PARAM_SECOND_PORT:
        panel_blurfree_set_second_port(value);
        break;
    }
}
