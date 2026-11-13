/* sys_ddr_phy_read_field  (FUN_a00e0754)
 *
 * Read a bit field of a register of a memory interface.
 * Returns: field
 * Name basis: proven - masked read shifted right
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0754 @ 0xa00e0754 (-mcpu=v8 -O2 -g)
 * Source form: the unsigned int types of the parameters, the local and the result make the compiler emit srl
 * rather than sra.
 */
extern unsigned int sys_ddr_phy_read_masked(unsigned int, unsigned int, unsigned int);

/*
 * Read register addr of memory interface phy, keep the bits of mask and shift them right by `shift`, so the
 * field starts at bit 0.
 */
unsigned int sys_ddr_phy_read_field(unsigned int phy, unsigned int addr, unsigned int mask, unsigned int shift)
{
    unsigned int result = sys_ddr_phy_read_masked(phy, addr, mask);
    return result >> shift;
}
