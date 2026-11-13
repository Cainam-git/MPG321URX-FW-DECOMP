/* sys_core_read_reg_0324  (FUN_a00de9e0)
 *
 * Read core register 0x9F020324.
 * Returns: word
 * Name basis: descriptive - used by the crash information print
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00de9e0 @ 0xa00de9e0, flags -mcpu=v8 -O2 -g.
 * Source form: declared void; the call to reg_read32 is a tail call, so its result is the value the caller
 * receives (callers declare the routine as returning unsigned int).
 */
extern int reg_read32();

/*
 * Read the core register 0x9F020324. The stack report (dbg_print_stack_usage) compares "Min" with it and prints
 * Pass when Min is above it; dbg_print_stack_overflow prints it as the second value.
 */
void sys_core_read_reg_0324(void)

{
  reg_read32(0x9f020324);
  return;
}
