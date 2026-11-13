/* input_block0_clear_regad_set_regaf  (FUN_a010b36c)
 *
 * Clear bit 0 of register 0xAD and set bit 7 of register 0xAF of input block 0.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010b36c @ 0xa010b36c, flags -mcpu=v8 -O2 -g (section default).
 * Source form: input_capture_update_bits is declared as an unprototyped int-returning routine; the last argument
 * of the first call is the char constant '\0', that of the second '\x01'.
 */
extern int input_capture_update_bits();

/*
 * Clear bit 0 of register 0xAD, then set bit 7 of register 0xAF, of input block 0.
 *
 * No routine in the image calls it.
 */
void input_block0_clear_regad_set_regaf(void)
{
    input_capture_update_bits(0, 0xad, 1, '\0');
    input_capture_update_bits(0, 0xaf, 0x80, '\x01');
}
