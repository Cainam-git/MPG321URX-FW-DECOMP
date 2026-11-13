/* hdmi_rx21_measure_pixel_clock  (FUN_a0097680)
 *
 * Measure the pixel clock of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver
 *   hold: non-zero = latch first
 * Name basis: derived - count * 960 scaled, divided by pixel repetition + 1; caller FSM_MODE_DETECT_STANDBY
 *   ('Abnormal Pixel Clock')
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0097680 @ 0xa0097680-0xa00977cc, flags -mcpu=v8 -Os -g.
 * Source form: the wait count is set to 50 before the first reg_set_bit call; the wait loop leaves with 'break' when
 * the count is 0 and the test after the loop returns 0; every register block access goes through
 * hdmi_rx21_reg_blocks[port].
 */
#define MEASURE_LATCH_BIT      0x18     /* bit 24 of the word at block 8 + 0x38 */
#define MEASURE_READY_BIT      0x19     /* bit 25 of the same word */
#define MEASURE_WAIT_TRIES     50       /* delay units waited for the ready bit */

/* One entry of the table at 0xA807DB00 (0x34 bytes per receiver): the addresses of the register blocks. */
struct hdmi_rx21_reg_blocks {
    volatile unsigned int *block0;
    unsigned int blocks_1_to_7[7];
    volatile unsigned int *block8;
    unsigned char blocks_9_to_12[0x34 - 0x24];
};
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern void reg_set_bit(unsigned int, volatile unsigned int *);
extern unsigned int reg_test_bit(unsigned int, volatile unsigned int *);
extern void timer_delay_long_units(unsigned int);

/*
 * Measure the pixel clock of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 *   hold: non-zero = set bit 24 of the word at block 8 + 0x38 first and wait up to 50 delay units for its
 *     bit 25; the result is 0 when that bit does not come. With 0 the bit is set after the reading instead.
 * With bit 25 set, the count at block 8 + 0x40 is scaled to ((count * 960) << s) + 0x8000) >> 16, where s is bit 12
 * of the word at block 0 + 8, and divided by bits 6..7 of that word plus 1. Otherwise the result is 0.
 * The result is compared with the stored pixel clock of the receiver and stored by hdmi_rx21_store_clock.
 * Called by FSM_MODE_DETECT_STANDBY (with hold 0).
 */
unsigned short hdmi_rx21_measure_pixel_clock(unsigned char port, unsigned char hold)
{
    unsigned short clock = 0;
    unsigned char tries;
    unsigned int count;

    if (hold) {
        tries = MEASURE_WAIT_TRIES;
        reg_set_bit(MEASURE_LATCH_BIT, ARR_a807db00[port].block8 + 0xe);
        while (reg_test_bit(MEASURE_READY_BIT, ARR_a807db00[port].block8 + 0xe) == 0) {
            timer_delay_long_units(1);
            if (tries == 0)
                break;
            tries--;
        }
        if (tries == 0)
            return 0;
    }
    if (reg_test_bit(MEASURE_READY_BIT, ARR_a807db00[port].block8 + 0xe)) {
        count = ARR_a807db00[port].block8[0x10];
        clock = (((count * 960) << reg_test_bit(0xc, ARR_a807db00[port].block0 + 2)) + 0x8000 >> 16) /
            (((ARR_a807db00[port].block0[2] & 0xc0) >> 6) + 1);
    }
    if (hold == 0)
        reg_set_bit(MEASURE_LATCH_BIT, ARR_a807db00[port].block8 + 0xe);
    return clock;
}
