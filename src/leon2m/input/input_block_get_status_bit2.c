/* input_block_get_status_bit2  (FUN_a0121258)
 *
 * Return status bit 2 of an input block.
 * Returns: 0 or 1
 * Name basis: descriptive - bit 2 of block register 0; many callers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0121258 @ 0xa0121258, flags -mcpu=v8 -O2 -g (section default).
 * Source form: input_capture_read8 is declared (unsigned char, int) returning int; the result is tested with
 * '(result & 4) == 0 ? 0 : 1'.
 */
extern int input_capture_read8(unsigned char, int);

/*
 * Return bit 2 of register 0 of an input block: 1 when set, else 0. input_block_check_signal writes this bit.
 */
int input_block_get_status_bit2(unsigned char blk) {
    int reg = input_capture_read8(blk, 0);
    return (reg & 4) == 0 ? 0 : 1;
}
