/* sys_ddr_reset_fifos  (FUN_a00e0090)
 *
 * Pulse the reset bits of a memory interface's registers 0x2CE and 0x2CD.
 * Name basis: derived - run between training steps
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0090 @ 0xa00e0090 (-mcpu=v8 -O2 -g)
 * Source form: sys_ddr_phy_update_bits is declared without a parameter list, as the decompiler had it.
 */
extern void sys_ddr_delay(unsigned int);
extern void sys_ddr_phy_update_bits();

/*
 * Write a fixed sequence of masked register writes to memory interface phy (0..2), one delay unit apart:
 * mask 0x8f of register 0x2ce is set to 0x80 and then to 0x8f, the same for register 0x2cd, then bit 7 (mask
 * 0x80) of register 0x5a is cleared and set again.
 */
void sys_ddr_reset_fifos(unsigned int phy)
{
    sys_ddr_phy_update_bits(phy, 0x2ce, 0x8f, 0x80);
    sys_ddr_delay(1);
    sys_ddr_phy_update_bits(phy, 0x2ce, 0x8f, 0x8f);
    sys_ddr_delay(1);
    sys_ddr_phy_update_bits(phy, 0x2cd, 0x8f, 0x80);
    sys_ddr_delay(1);
    sys_ddr_phy_update_bits(phy, 0x2cd, 0x8f, 0x8f);
    sys_ddr_delay(1);
    sys_ddr_phy_update_bits(phy, 0x5a, 0x80, 0);
    sys_ddr_delay(1);
    sys_ddr_phy_update_bits(phy, 0x5a, 0x80, 0x80);
}
