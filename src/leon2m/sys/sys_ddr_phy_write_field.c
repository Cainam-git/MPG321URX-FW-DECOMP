/* sys_ddr_phy_write_field  (FUN_a00e0774)
 *
 * Write a bit field of a register of a memory interface.
 * Name basis: proven - sys_ddr_phy_update_bits with the value shifted left
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0774 @ 0xa00e0774-0xa00e0784 (4 words), flags -mcpu=v8 -O2 -g.
 * Source form: a plain call compiled as a tail call (sll, then call with the caller's return address handed on).
 * The shift count is the 4th parameter and the value the 5th. The built object has a trailing alignment nop after
 * the range (outside the function's 16 bytes).
 */
extern void sys_ddr_phy_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);

/*
 * Write `value` into the bit field of register addr of memory interface phy that the mask selects: the value is
 * shifted left by `shift` and only the bits of mask change.
 */
void sys_ddr_phy_write_field(unsigned int phy, unsigned int addr, unsigned int mask, unsigned int shift,
                             unsigned int value)
{
    sys_ddr_phy_update_bits(phy, addr, mask, value << shift);
}
