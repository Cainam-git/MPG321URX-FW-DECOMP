/* usb_cc_test_active_line_high  (FUN_CODE_d7f7)
 *
 * Report whether the CC line of the current orientation reads high.
 * Returns: flag bit 0x1D
 * Note: Not called anywhere.
 * Name basis: derived - picks reading 0xA672 or 0xA673 by usb_cc_test_orientation_bits, threshold 0xD4
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d7f7 @ 0xd7f7..0xd81c (37 B)
 * Nothing in the bank-1 image calls or jumps to 0xD7F7 (the 'AJMP 0xD802' Ghidra shows at 0xDAC4 is inside the
 * ?C?LSTKXDATA constant of timer_set_crystal_rates).
 */
#define CC_LINE_HIGH_LEVEL 0xd4  /* a reading above this is high */

extern unsigned char xdata usb_cc_line_readings, usb_cc_line_reading_second;
extern bit usb_cc_active_line_high_flag;
extern unsigned char usb_cc_test_orientation_bits(void);

/*
 * Return 1 when the CC line of the current plug orientation reads high (above 0xD4): the first reading when
 * usb_cc_test_orientation_bits returns 0, the second when it returns 1. The result is also left in
 * usb_cc_active_line_high_flag. Nothing in the image calls this routine.
 */
bit usb_cc_test_active_line_high(void)
{
    unsigned char orientation;

    usb_cc_active_line_high_flag = 0;
    orientation = usb_cc_test_orientation_bits();
    if (orientation == 0 && usb_cc_line_readings > CC_LINE_HIGH_LEVEL) usb_cc_active_line_high_flag = 1;
    if (orientation == 1 && usb_cc_line_reading_second > CC_LINE_HIGH_LEVEL) usb_cc_active_line_high_flag = 1;
    return usb_cc_active_line_high_flag;
}
