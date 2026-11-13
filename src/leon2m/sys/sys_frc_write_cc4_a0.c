/* sys_frc_write_cc4_a0  (FUN_a0109b58)
 *
 * Write 0xA0 to converter register 0xCF011CC4.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0109b58 @ 0xa0109b58, flags -mcpu=v8 -O2 -g.
 * Source form: a volatile register store (the store stays before retl).
 */
#define REG_CF011CC4 (*(volatile unsigned int *)0xcf011cc4)

/* Write 0xA0 to the register 0xCF011CC4. Nothing in the image calls it. */
void sys_frc_write_cc4_a0(void)
{
    REG_CF011CC4 = 0xa0;
}
