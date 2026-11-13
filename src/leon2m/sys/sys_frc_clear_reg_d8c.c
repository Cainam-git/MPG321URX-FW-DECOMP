/* sys_frc_clear_reg_d8c  (FUN_a0112fcc)
 *
 * Write 0 to register 0xCF011D8C.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * FUN_a0112fcc (leon2m 0xa0112fcc-0xa0112fe0, 20 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: a volatile register store (the store stays before retl).
 */
#define FRC_REG_D8C (*(volatile unsigned int *)0xcf011d8c)

/* Write 0 to register 0xCF011D8C. Nothing calls this routine. */
void sys_frc_clear_reg_d8c(void)
{
    FRC_REG_D8C = 0;
}
