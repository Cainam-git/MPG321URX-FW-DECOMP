/* usb_cc_test_both_lines_high  (FUN_CODE_dc24)
 *
 * Report whether both CC line readings are high.
 * Returns: flag bit 0x1C
 * Note: Not called anywhere.
 * Name basis: derived - CC readings 0xA672/0xA673 above 0xD4; no caller
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dc24 @ 0xdc24..0xdc3b (23 bytes), OPTIMIZE(7,SPEED).
 * The result is the bit flag itself (returned in the carry).
 */
#define CC_LINE_HIGH_LEVEL 0xd4   /* readings above this count as high */

extern unsigned char xdata usb_cc_line_readings[2];
extern bit usb_cc_both_lines_high_flag;

/* Set flag bit 0x1C and return it when both CC line readings are above
 * CC_LINE_HIGH_LEVEL; otherwise clear it. Nothing in the bank calls it. */
bit usb_cc_test_both_lines_high(void)
{
    usb_cc_both_lines_high_flag = 0;
    if (usb_cc_line_readings[0] > CC_LINE_HIGH_LEVEL && usb_cc_line_readings[1] > CC_LINE_HIGH_LEVEL)
        usb_cc_both_lines_high_flag = 1;
    return usb_cc_both_lines_high_flag;
}
