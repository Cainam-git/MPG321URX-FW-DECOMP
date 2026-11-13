/* input_block_is_regcc_zero  (FUN_a0123590)
 *
 * Return whether register 0xCC of an input block reads 0.
 * Returns: 0 or 1
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0123590 @ 0xa0123590, flags -mcpu=v8 -O2 -g.
 * Source form: the "== 0" compares the low byte of the register value after it was stored in an int.
 */
extern int input_unit_read8(int, int);

#define INPUT_REG_0xCC 0xcc

/*
 * Return 1 when register 0xCC of the given input block reads 0, else 0.
 *
 *   block  number of the input block
 */
int input_block_is_regcc_zero(int block)
{
    int value = input_unit_read8(block & 0xff, INPUT_REG_0xCC);
    return (value & 0xff) == 0;
}
