/* sys_ddr_update_phy_bits_multi  (FUN_a00e20dc)
 *
 * Replace masked bits of a register of one memory interface, or of all three.
 * Name basis: derived - interface 3 or 0xFF = all; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e20dc @ 0xa00e20dc-0xa00e2180 (41 words).
 * Source form: the loop bounds are the two conditional expressions written in the for statement (separate
 * variables give an orcc/subx test instead of the firmware's addx/btst).
 */
extern void sys_ddr_phy_update_bits(int, unsigned short, unsigned char, unsigned char);

/*
 * Change the bits of mask in register addr of memory interface phy to the matching bits of `value`. The
 * interface numbers 3 and 0xff mean "all": the change is then made on interfaces 0, 1 and 2. Nothing in the
 * image calls it.
 */
void sys_ddr_update_phy_bits_multi(int phy, unsigned short addr, unsigned char mask, unsigned char value)
{
    int i;

    for (i = (phy == 3 || phy == 0xff) ? 0 : phy; i <= ((phy == 3 || phy == 0xff) ? 2 : phy); i++)
        sys_ddr_phy_update_bits(i, addr, mask, value);
}
