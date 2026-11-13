/* sys_ddr_phy_set_bits  (FUN_a00e0740)
 *
 * Set the masked bits of a register of a memory interface.
 * Name basis: proven - sys_ddr_phy_update_bits with value = mask
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0740 @ 0xa00e0740 (-mcpu=v8 -O2 -g)
 * Source form: sys_ddr_phy_update_bits is declared without a parameter list, as the decompiler had it.
 */
extern int sys_ddr_phy_update_bits();

/*
 * Set the bits of mask in register addr of memory interface phy: the mask is passed as both mask and value, so
 * every bit of the mask becomes 1 and the other bits stay as they are.
 */
void sys_ddr_phy_set_bits(int phy, unsigned int addr, unsigned int mask)
{
    sys_ddr_phy_update_bits(phy, addr, mask, mask);
}
