/* fwupd_port_reset_control  (FUN_a0123654)
 *
 * Set bit 0 and then clear bit 1 of the update port's control register.
 * Name basis: descriptive - register 0xCF03C780; unused
 *
 * Matching notes
 * --------------
 * FUN_a0123654 (leon2m 0xa0123654-0xa012367c, 40 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: two read-modify-writes of one volatile word register.
 */
#define REG (*(volatile unsigned int *)0xcf03c780)

/*
 * Set bit 0 of the register at 0xCF03C780, then clear its bit 1 (two separate read-modify-writes).
 * The purpose of the register is not shown. Nothing calls this routine.
 */
void fwupd_port_reset_control(void)
{
    REG |= 1;
    REG &= ~2u;
}
