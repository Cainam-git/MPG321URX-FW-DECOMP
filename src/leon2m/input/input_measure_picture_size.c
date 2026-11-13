/* input_measure_picture_size  (FUN_a014e4b8)
 *
 * Measure the incoming picture and report whether its two size results reach 300 and 200.
 * Returns: 1 when both results are large enough
 * Name basis: derived - waits for the measurement-done bit, reads four 16-bit results; returns 1 when the
 *   first (registers 0x41:0x40 times 8) is >= 300 and the second (0x3D:0x3C) >= 200
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e4b8, flags -mcpu=v8 -O3 -g.
 * Source form: the shifted values are written '(high | low) * 8' (the shift form swaps the 'or' operands); the
 * result is an unsigned char, 0 unless the poll succeeded, returned as 'result & 1' through one exit (the exit
 * keeps the 'and'). measure_channel_index is the static helper of the other channel routines, inlined.
 */

/* Registers of the input capture block, as used by this measurement. */
#define MEASURE_REG_SETUP        0x37           /* written with MEASURE_SETUP_VALUE before the measurement */
#define MEASURE_SETUP_VALUE      0x16
#define MEASURE_REG_OPTION       0x4a           /* bit 7 (0x80) is set or cleared by the port's format code */
#define MEASURE_REG_START        0x36           /* write 0, then 1 to start; bit 0 reads 0 when the result is ready */
#define MEASURE_REG_FIRST_LOW    0x40           /* 16-bit results: low byte, high byte at +1 */
#define MEASURE_REG_SECOND_LOW   0x3c
#define MEASURE_REG_THIRD_LOW    0x3e
#define MEASURE_REG_FOURTH_LOW   0x38
#define MEASURE_REG_PAIR         0x4c           /* pair read by pq_block_read16 after the results */
#define MEASURE_START_DELAY      20             /* timer_sleep_ticks argument between start and polling */
#define MEASURE_TIMEOUT_TICKS    100            /* polling stops when the tick counter has advanced this far */
#define FIRST_SIZE_MIN           300            /* a measurement is plausible from this first size ... */
#define SECOND_SIZE_MIN          200            /* ... and this second size */

/* Channel record: bits 12..15 of word 0 are the port, which is also the index of its capture block. */
struct channel_record { unsigned int top : 16; unsigned int port : 4; unsigned int low : 12; unsigned char rest[0x74]; };
/* Port record: byte +0x28 is the format code. */
struct port_record { unsigned char pad[0x28]; unsigned char format_code; unsigned char tail; };
extern struct channel_record channel_records[4];
extern struct port_record port_records[];
extern int dbg_printf();
extern unsigned char input_capture_read8(unsigned char block, unsigned char reg);
extern void input_capture_write8(unsigned char block, unsigned char reg, unsigned char val);
extern void input_capture_update_bits(unsigned char block, unsigned char reg, unsigned char mask, unsigned char set);
extern void pq_block_read16(unsigned char block, unsigned char reg);
extern void timer_sleep_ticks(int ticks);
extern unsigned short timer_get_ticks16(void);

/* Channels 0..3 map to themselves; any other value gives -1. */
static int measure_channel_index(int channel)
{
    switch (channel) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

/*
 * Start a measurement in the capture block of a channel's port, wait for it and read four results.
 *
 * channel: 0..3. Any other value prints "SYS remapping channel OOR" and uses channel 0.
 * first_size, second_size, third_value, fourth_value: receive the four results. first_size and third_value are
 * the 16-bit register pairs 0x41:0x40 and 0x3f:0x3e times 8; second_size and fourth_value are 0x3d:0x3c and
 * 0x39:0x38 as they are. They are written only when the measurement finished.
 * Returns 1 when the measurement finished and first_size >= 300 and second_size >= 200; 0 when it did not finish
 * in time (about 100 ticks after the start delay) or the sizes are smaller.
 *
 * Steps: write 0x16 to register 0x37; set or clear bit 7 of register 0x4a (cleared when the format code in the
 * port record is 0, 1, 0x1a or 0x1b, set otherwise); write 0 then 1 to register 0x36; wait 20 ticks; poll
 * bit 0 of register 0x36 until it reads 0. After the results it reads register pair 0x4c of the block and
 * discards the value.
 * Caller: pq_detect_ch1_input_change, which measures channel 1 and keeps the four results.
 */
unsigned char input_measure_picture_size(unsigned char channel, unsigned short *first_size, unsigned short *second_size, unsigned short *third_value, unsigned short *fourth_value)
{
    unsigned char index, block, format_code, done, clear_option_bit = 1;
    unsigned char result;
    unsigned short start_ticks;
    unsigned int high_byte;

    index = measure_channel_index(channel);
    if (index > 3) { dbg_printf("SYS remapping channel OOR\r\n"); index = 0; }
    block = channel_records[index].port;
    format_code = port_records[block].format_code;
    if (format_code > 1 && format_code != 0x1a && format_code != 0x1b)
        clear_option_bit = 0;
    input_capture_write8(block, MEASURE_REG_SETUP, MEASURE_SETUP_VALUE);
    if (clear_option_bit)
        input_capture_update_bits(block, MEASURE_REG_OPTION, 0x80, 0);
    else
        input_capture_update_bits(block, MEASURE_REG_OPTION, 0x80, 1);
    done = 0;
    input_capture_write8(block, MEASURE_REG_START, 0);
    input_capture_write8(block, MEASURE_REG_START, 1);
    timer_sleep_ticks(MEASURE_START_DELAY);
    start_ticks = timer_get_ticks16();
    do {
        if (!(input_capture_read8(block, MEASURE_REG_START) & 1)) {
            done = 1;
            break;
        }
    } while (timer_get_ticks16() - start_ticks < MEASURE_TIMEOUT_TICKS);
    result = 0;
    if (done) {
        high_byte = input_capture_read8(block, MEASURE_REG_FIRST_LOW + 1) << 8;
        *first_size = (high_byte | input_capture_read8(block, MEASURE_REG_FIRST_LOW)) * 8;
        high_byte = input_capture_read8(block, MEASURE_REG_SECOND_LOW + 1) << 8;
        *second_size = high_byte | input_capture_read8(block, MEASURE_REG_SECOND_LOW);
        high_byte = input_capture_read8(block, MEASURE_REG_THIRD_LOW + 1) << 8;
        *third_value = (high_byte | input_capture_read8(block, MEASURE_REG_THIRD_LOW)) * 8;
        high_byte = input_capture_read8(block, MEASURE_REG_FOURTH_LOW + 1) << 8;
        *fourth_value = high_byte | input_capture_read8(block, MEASURE_REG_FOURTH_LOW);
        pq_block_read16(block, MEASURE_REG_PAIR);
        result = 1;
        if (*first_size < FIRST_SIZE_MIN || *second_size < SECOND_SIZE_MIN)
            result = 0;
    }
    return result & 1;
}
