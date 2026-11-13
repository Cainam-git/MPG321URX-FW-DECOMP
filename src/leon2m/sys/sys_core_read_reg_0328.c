/* sys_core_read_reg_0328  (FUN_a00de9a8)
 *
 * Read core register 0x9F020328.
 * Returns: word
 * Name basis: descriptive - used by the crash information print
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00de9a8 @ 0xa00de9a8, flags -mcpu=v8 -O2 -g.
 * Source form: declared void; the call to reg_read32 is a tail call, so its result is the value the caller
 * receives (callers declare the routine as returning unsigned int).
 */
extern int reg_read32();

/*
 * Read the core register 0x9F020328. The stack report (dbg_print_stack_usage) prints it as "Min" and
 * dbg_print_stack_overflow as the first value of "Stack Pointer Overflow".
 */
void sys_core_read_reg_0328(void)

{
  reg_read32(0x9f020328);
  return;
}
