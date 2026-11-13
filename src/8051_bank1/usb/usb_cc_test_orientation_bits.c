/* usb_cc_test_orientation_bits  (FUN_CODE_da74)
 *
 * Report whether both orientation bits of the Type-C CC status are set.
 * Returns: 1 when both set
 * Name basis: derived - bits 2..3 of byte 0x10 of the CC block; selects which CC reading the line tests use
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_da74 @ 0xda74
 * Options: OPTIMIZE(8,SPEED).
 */
extern bit DAT_BIT_0018;
extern unsigned char * xdata usb_cc_block_ptr;

/* Returns 1 when bits 2 and 3 of byte 0x10 of the selected Type-C port's
 * register block (usb_cc_block_ptr) are both set, else 0. Also clears flag
 * bit 0x18. */
unsigned char usb_cc_test_orientation_bits(void)
{
    unsigned char result;
    DAT_BIT_0018 = 0;
    result = 0;
    if ((usb_cc_block_ptr[0x10] & 0x0c) == 0x0c) result++;
    return result;
}
