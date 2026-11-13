/* sys_ddr_write_phy_reg_multi  (FUN_a00e2040)
 *
 * Write a register of one memory interface, or of all three.
 * Name basis: derived - interface 3 or 0xFF = all; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e2040 @ 0xa00e2040-0xa00e20dc (39 words).
 * Source form: the loop bounds are the two conditional expressions written in the for statement (separate
 * variables give an orcc/subx test instead of the firmware's addx/btst).
 */
extern void sys_ddr_phy_write(int, unsigned short, unsigned char);

/*
 * Write `value` to register addr of memory interface phy. The interface numbers 3 and 0xff mean "all": the write
 * is then made on interfaces 0, 1 and 2. Nothing in the image calls it.
 */
void sys_ddr_write_phy_reg_multi(int phy, unsigned short addr, unsigned char value)
{
    int i;

    for (i = (phy == 3 || phy == 0xff) ? 0 : phy; i <= ((phy == 3 || phy == 0xff) ? 2 : phy); i++)
        sys_ddr_phy_write(i, addr, value);
}
