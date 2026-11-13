/* input_block0_set_regaf_bit7  (FUN_a010b39c)
 *
 * Set bit 7 of register 0xAF of input block 0.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010b39c @ 0xa010b39c, flags -mcpu=v8 -O2 -g (section default).
 * Source form: input_capture_update_bits is declared as an unprototyped int-returning routine; the last argument
 * is the char constant '\x01'.
 */
extern int input_capture_update_bits();

/*
 * Set bit 7 of register 0xAF of input block 0.
 *
 * No routine in the image calls it.
 */
void input_block0_set_regaf_bit7(void)
{
    input_capture_update_bits(0, 0xaf, 0x80, '\x01');
}
