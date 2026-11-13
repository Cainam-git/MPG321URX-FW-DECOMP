/* usb_cc_check_rp_pair  (FUN_CODE_be50)
 *
 * Report whether exactly one CC line shows a pull-up (Rp) level.
 * Returns: 1 when exactly one line is in range and neither reading is above 0x9D
 * Note: No caller in the bank-1 image.
 * Name basis: derived - prints 'get two rp'; CC readings 0xA672/0xA673 in 0x14..0x9C
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_be50, no caller in the image. Keil keeps first_in_range | second_in_range in R5 for both tests
 * (common subexpression).
 */
extern unsigned char xdata usb_cc_line_readings[2];
extern void lib_printf517(void *fmt, ...) large;
/*
 * usb_cc_check_rp_pair - look at the two CC line readings (usb_cc_line_readings[0] and [1]). A reading counts as
 * "in range" when it lies in 0x14..0x9C. Returns 1 when exactly one of the two is in range, and 0 otherwise; it also
 * returns 0 when either reading is above 0x9D. When both are in range it prints "get two rp" with both readings
 * (and returns 0). No caller in the bank-1 image.
 */
bit usb_cc_check_rp_pair(void)
{
    bit exactly_one;
    unsigned char first_in_range, second_in_range;
    exactly_one = 0;
    first_in_range = 0;
    second_in_range = 0;
    if (usb_cc_line_readings[0] > 0x13 && usb_cc_line_readings[0] < 0x9d) first_in_range = 1;
    if (usb_cc_line_readings[1] > 0x13 && usb_cc_line_readings[1] < 0x9d) second_in_range = 1;
    if ((first_in_range | second_in_range) && first_in_range != second_in_range) exactly_one = 1;
    if (usb_cc_line_readings[0] > 0x9d || usb_cc_line_readings[1] > 0x9d) exactly_one = 0;
    if ((first_in_range | second_in_range) && first_in_range == second_in_range) lib_printf517((void code *)0xb50f, usb_cc_line_readings[0], usb_cc_line_readings[1]);
    return exactly_one;
}
