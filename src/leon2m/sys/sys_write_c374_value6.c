/* sys_write_c374_value6  (FUN_a011d1fc)
 *
 * Write 6 to register 0xCF03C374.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * FUN_a011d1fc (leon2m 0xa011d1fc-0xa011d214, 24 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: a volatile register store (the store stays before retl).
 */
#define REG_C374 (*(volatile unsigned int *)0xcf03c374)

/* Write 6 to register 0xCF03C374. Nothing calls this routine. */
void sys_write_c374_value6(void)
{
    REG_C374 = 6;
}
