/* usb_cc_test_both_lines_low  (FUN_CODE_dc0d)
 *
 * Report whether both CC line readings are low.
 * Returns: flag bit 0x1A
 * Note: Not called anywhere.
 * Name basis: derived - CC readings 0xA672/0xA673 below 0x13; no caller
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dc0d @ 0xdc0d..0xdc24 (23 bytes), OPTIMIZE(7,SPEED).
 * The result is the bit flag itself (returned in the carry).
 */
#define CC_LINE_ZERO_LEVEL 0x13   /* readings below this count as low */

extern unsigned char xdata usb_cc_line_readings[2];
extern bit usb_cc_both_lines_low_flag;

/* Set flag bit 0x1A and return it when both CC line readings are below
 * CC_LINE_ZERO_LEVEL; otherwise clear it. Nothing in the bank calls it. */
bit usb_cc_test_both_lines_low(void)
{
    usb_cc_both_lines_low_flag = 0;
    if (usb_cc_line_readings[0] < CC_LINE_ZERO_LEVEL && usb_cc_line_readings[1] < CC_LINE_ZERO_LEVEL)
        usb_cc_both_lines_low_flag = 1;
    return usb_cc_both_lines_low_flag;
}
