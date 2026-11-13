/* sys_core_setup_unit_0320  (FUN_a00de6d4)
 *
 * Start the unit at core register 0x9F020320 and register its interrupt handler.
 * Name basis: descriptive - value 5, a buffer address and irq_set_source_handler(1, 0x10, ...); called from
 *   startup_init_core
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00de6d4 @ 0xa00de6d4, flags -mcpu=v8 -O2 -g.
 * Source form: reg_write32 and irq_set_source_handler are declared without a prototype.
 */
#define CORE_REG_0320 0x9f020320
#define CORE_REG_0324 0x9f020324

extern int dbg_print_stack_overflow();
extern int irq_set_source_handler();
extern void reg_write32();

/*
 * Write 5 to the core register 0x9F020320 and the address 0xA803E400 to 0x9F020324, then register
 * dbg_print_stack_overflow as the handler for interrupt source 1, number 0x10. The reports of the stack
 * routines read these registers back (dbg_print_stack_usage, dbg_print_stack_overflow).
 * Called from startup_init_core.
 */
void sys_core_setup_unit_0320(void)

{
  reg_write32(CORE_REG_0320, 5);
  reg_write32(CORE_REG_0324, 0xa803e400);
  irq_set_source_handler(1, 0x10, dbg_print_stack_overflow);
  return;
}
