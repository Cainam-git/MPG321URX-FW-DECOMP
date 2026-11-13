/* usb_cc_test_lines_split  (FUN_CODE_d785)
 *
 * Report whether one CC line reads high and the other low.
 * Returns: flag bit 0x1E
 * Note: Not called anywhere.
 * Name basis: derived - compares the two CC readings 0xA672/0xA673 against 0xD4 and 0x41
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d785 @ 0xd785..0xd7ac (39 bytes), OPTIMIZE(7,SPEED).
 * Bit result (carry). Nothing in bank 1 calls, jumps to or stores the address 0xD785.
 */
#define CC_LINE_HIGH_LEVEL 0xd4  /* a reading above this is high */
#define CC_LINE_LOW_LEVEL  0x41  /* a reading below this is low */

extern unsigned char xdata usb_cc_line_readings[2];
extern bit usb_cc_lines_split_flag;

/*
 * Return 1 when one of the two CC line readings is above 0xD4 and the other below 0x41 (either way round). The
 * result is also left in usb_cc_lines_split_flag. Nothing in the image calls this routine.
 */
bit usb_cc_test_lines_split(void)
{
    usb_cc_lines_split_flag = 0;
    if (usb_cc_line_readings[0] > CC_LINE_HIGH_LEVEL && usb_cc_line_readings[1] < CC_LINE_LOW_LEVEL)
        usb_cc_lines_split_flag = 1;
    if (usb_cc_line_readings[1] > CC_LINE_HIGH_LEVEL && usb_cc_line_readings[0] < CC_LINE_LOW_LEVEL)
        usb_cc_lines_split_flag = 1;
    return usb_cc_lines_split_flag;
}
