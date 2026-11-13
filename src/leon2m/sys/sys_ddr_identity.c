/* sys_ddr_identity  (FUN_a00e02e4)
 *
 * Return the argument unchanged.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e02e4 @ 0xa00e02e4 (-mcpu=v8 -O2 -g)
 * Source form: the parameter and the result are unsigned char.
 */
/*
 * Return the argument unchanged. As an unsigned char result it is the low byte of a register number, the part
 * inside the page; sys_ddr_dump_phy_reg uses it for that.
 */
unsigned char sys_ddr_identity(unsigned char value)
{
    return value;
}
