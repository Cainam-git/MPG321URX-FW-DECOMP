/* dbg_print_stack_overflow  (FUN_a002cea8)
 *
 * Print the stack pointer overflow report with the two stack check registers.
 * Note: Registers 0x9F020328 (value) and 0x9F020324 (limit).
 * Name basis: proven - text 'Stack Pointer Overflow! %08X over %08X'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002cea8 @ 0xa002cea8, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: reg_read32 and dbg_printf are declared without a prototype; both registers are read before
 * the print.
 */
extern int reg_read32();
extern int dbg_printf();

#define CORE_REG_0324 0x9f020324        /* startup_init_core writes the address 0xA803E400 here */
#define CORE_REG_0328 0x9f020328

/*
 * Print the stack overflow report: register 0x9F020328 "over" register 0x9F020324.
 * Registered by startup_init_core (and sys_core_setup_unit_0320) as the handler of interrupt level 1,
 * source 4 (bit 0x10).
 */
void dbg_print_stack_overflow(void)
{
  unsigned int value_0328;
  int value_0324;

  value_0328 = reg_read32(CORE_REG_0328);
  value_0324 = reg_read32(CORE_REG_0324);
  dbg_printf("\r\nStack Pointer Overflow! %08X over %08X\r\n", value_0328, value_0324);
}