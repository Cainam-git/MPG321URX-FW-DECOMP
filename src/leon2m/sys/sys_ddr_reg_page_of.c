/* sys_ddr_reg_page_of  (FUN_a00e02d8)
 *
 * Return the page number of a register number.
 * Name basis: derived - bits 8..11
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e02d8 @ 0xa00e02d8 (-mcpu=v8 -O2 -g)
 * Source form: unsigned int parameter and result, one shift-and-mask expression.
 */
/* Page number of a memory interface register number: bits 8..11 (see sys_ddr_phy_write for the page scheme). */
unsigned int sys_ddr_reg_page_of(unsigned int addr)
{
    return addr >> 8 & 0xf;
}
