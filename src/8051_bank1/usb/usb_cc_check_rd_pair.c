/* usb_cc_check_rd_pair  (FUN_CODE_c698)
 *
 * Report whether exactly one CC line shows a pull-down (Rd) level.
 * Returns: 1 when exactly one line is in range
 * Note: No caller in the bank-1 image.
 * Name basis: derived - prints 'get two rd'; CC readings 0xA672/0xA673 in 0x42..0xC7
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c698 @ 0xC698..0xC6EC (84 bytes)  Byte-exact with OPTIMIZE(8,SPEED) (no register file).
 * Source form: the result is a local bit, returned in the carry; both range flags are unsigned char.
 * Twin of usb_cc_check_rp_pair, which uses another range.
 */
extern unsigned char xdata usb_cc_line_readings[2];
extern void lib_printf517(void *fmt, ...) large;

/*
 * Check the two CC line readings (usb_cc_line_readings[0] and [1]) against
 * the range 0x42..0xC7. Returns 1 when exactly one reading is in range. When
 * both are in range it returns 0 and prints "get two rd : %02bx %02bx" with
 * both readings (format string at code 0xB52A). No caller in the bank-1 image.
 */
bit usb_cc_check_rd_pair(void)
{
    bit one_line_in_range;
    unsigned char line0_in_range, line1_in_range;
    one_line_in_range = 0;
    line0_in_range = 0;
    line1_in_range = 0;
    if (usb_cc_line_readings[0] > 0x41 && usb_cc_line_readings[0] < 0xc8) line0_in_range = 1;
    if (usb_cc_line_readings[1] > 0x41 && usb_cc_line_readings[1] < 0xc8) line1_in_range = 1;
    if ((line0_in_range | line1_in_range) && line0_in_range != line1_in_range) one_line_in_range = 1;
    if ((line0_in_range | line1_in_range) && line0_in_range == line1_in_range) lib_printf517((void code *)0xb52a, usb_cc_line_readings[0], usb_cc_line_readings[1]);
    return one_line_in_range;
}
