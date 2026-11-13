/* sys_ddr_phy_clear_reg0_bit0  (FUN_a00e005c)
 *
 * Clear bit 0 of register 0 of a memory interface.
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e005c @ 0xa00e005c-0xa00e0078 (7 words), flags -mcpu=v8 -O2 -g.
 * Source form: a plain call, compiled as a tail call. The caller's return address is handed on, so the callee
 * returns straight to this routine's caller. The last word is the nop the compiler places behind such a call
 * sequence.
 */
extern void sys_ddr_phy_update_bits(int, unsigned int, unsigned int, unsigned int);

/*
 * Clear bit 0 (mask 1, value 0) of register 0 of memory interface phy (0..2). Nothing in the image calls it or
 * stores its address.
 */
void sys_ddr_phy_clear_reg0_bit0(int phy)
{
    sys_ddr_phy_update_bits(phy, 0, 1, 0);
}
