/* input_block_check_reg10_and_9  (FUN_a01235b4)
 *
 * Return a yes/no result from registers 0x10 and 9 of an input block.
 * Returns: 0 or 1
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01235b4 @ 0xa01235b4, flags -mcpu=v8 -O3 -g.
 * Source form: three separate tests with return 1, the last one returned as the value of the compare; whether the
 * original used || is not shown.
 */
extern int input_unit_read8(int, int);

#define INPUT_REG_0x10 0x10
#define INPUT_REG_0x09 0x09

/*
 * Return 1 when register 0x10 (low nibble) and register 9 of the given input block hold one of the value pairs
 * (0x8, 0xFF), (0x4, 0x0F) or (0x2, 0x03), else 0.
 *
 *   block  number of the input block
 */
int input_block_check_reg10_and_9(unsigned char block)
{
    unsigned char low_nibble_reg10 = input_unit_read8(block & 0xff, INPUT_REG_0x10) & 0xf;
    unsigned char reg9 = input_unit_read8(block & 0xff, INPUT_REG_0x09) & 0xff;

    if (low_nibble_reg10 == 8 && reg9 == 0xff)
        return 1;
    if (low_nibble_reg10 == 4 && reg9 == 0xf)
        return 1;
    return (low_nibble_reg10 == 2 && reg9 == 3);
}
