/* sys_ddr_read_reg17_word  (FUN_a00e3ff4)
 *
 * Read the 16-bit value of registers 0x17 / 0x18 of a memory interface.
 * Returns: value
 * Name basis: descriptive - used by the write levelling
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e3ff4 @ 0xa00e3ff4, flags -mcpu=v8 -O2 -g.
 * Source form: the first read (register 0x18) is held in a local and shifted after the second call is set up.
 */
extern unsigned int sys_ddr_phy_read_field(unsigned int, unsigned int, unsigned int, unsigned int); /* 0xa00e0754 */

/*
 * Read registers 0x17 and 0x18 of memory interface `unit` as one 16-bit value: register 0x18 is the high byte,
 * register 0x17 the low byte.
 *
 * The routine that sends mode register 6 reads this value, sets or clears a bit in it and sends it back.
 */
unsigned int sys_ddr_read_reg17_word(unsigned int unit)
{
    unsigned int high_byte;

    high_byte = sys_ddr_phy_read_field(unit, 0x18, 0xff, 0);
    return (high_byte << 8) | sys_ddr_phy_read_field(unit, 0x17, 0xff, 0);
}
