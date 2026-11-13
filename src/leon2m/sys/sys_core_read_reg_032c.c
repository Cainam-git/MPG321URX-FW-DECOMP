/* sys_core_read_reg_032c  (FUN_a00de9c0)
 *
 * Read core register 0x9F02032C.
 * Returns: word
 * Name basis: descriptive - used by the crash information print
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00de9c0 @ 0xa00de9c0, flags -mcpu=v8 -O2 -g.
 * Source form: declared void; the call to reg_read32 is a tail call, so its result is the value the caller
 * receives (callers declare the routine as returning unsigned int).
 */
extern int reg_read32();

/* Read the core register 0x9F02032C. The stack report (dbg_print_stack_usage) prints it as "Max". */
void sys_core_read_reg_032c(void)

{
  reg_read32(0x9f02032c);
  return;
}
