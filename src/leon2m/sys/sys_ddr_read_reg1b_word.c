/* sys_ddr_read_reg1b_word  (FUN_a00e4030)
 *
 * Read the 16-bit value of registers 0x1B / 0x1C of a memory interface.
 * Returns: value
 * Name basis: descriptive - used by the gate and deskew training
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e4030 @ 0xa00e4030, flags -mcpu=v8 -O2 -g.
 * Source form: the first read (register 0x1c) is held in a local and shifted after the second call is set up.
 */
extern unsigned int sys_ddr_phy_read_field(unsigned int, unsigned int, unsigned int, unsigned int); /* 0xa00e0754 */

/*
 * Read registers 0x1b and 0x1c of memory interface `unit` as one 16-bit value: register 0x1c is the high byte,
 * register 0x1b the low byte.
 */
unsigned int sys_ddr_read_reg1b_word(unsigned int unit)
{
    unsigned int high_byte;

    high_byte = sys_ddr_phy_read_field(unit, 0x1c, 0xff, 0);
    return (high_byte << 8) | sys_ddr_phy_read_field(unit, 0x1b, 0xff, 0);
}
