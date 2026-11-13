/* sys_ddr_get_step  (FUN_a00dffcc)
 *
 * Return the current training step.
 * Returns: step
 * Name basis: derived - word at 0xA802B530; unused
 *
 * Matching notes
 * --------------
 * FUN_a00dffcc (leon2m 0xa00dffcc-0xa00dffd8, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: a direct read of the extern symbol (sethi %hi + load with the %lo offset in the retl delay slot).
 */
extern unsigned int sys_ddr_step_record;

/*
 * Return the step number that sys_ddr_set_step stored (the first word of sys_ddr_step_record). Nothing in the
 * image calls it.
 */
unsigned int sys_ddr_get_step(void)
{
    return sys_ddr_step_record;
}
