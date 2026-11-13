/* dbg_report_stack_overflow  (FUN_a00b1cb0)
 *
 * Print the stack overflow message with two core register values.
 * Name basis: proven - prints 'Stack Pointer Overflow!'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b1cb0 @ 0xa00b1cb0-0xa00b1cdc (11 words), flags -mcpu=v8 -Os -g.
 * The call to dbg_printf is a tail call (the caller's return address is handed on; the last word is the nop the
 * compiler places behind such a call sequence).
 * Source form: the registers as volatile fixed-address macros (as in sys_core_setup_unit_0320); the register at ...324 is
 * read after the one at ...328 is read, the format string as written below.
 */
#define CORE_UNIT_0320_ADDRESS (*(volatile unsigned int *)0x9f120324)  /* sys_core_setup_unit_0320 writes 0xa807e000 here */
#define CORE_UNIT_0328_VALUE   (*(volatile unsigned int *)0x9f120328)  /* printed first; meaning not shown */

extern int dbg_printf(const char *, ...);

/*
 * Print "Stack Pointer Overflow! <0x9f120328> over <0x9f120324>" (eight hex digits each) on the debug serial
 * port. No call in the code targets it; its address is stored in the start values (initialised data).
 */
void dbg_report_stack_overflow(void)
{
    dbg_printf("\r\nStack Pointer Overflow! %08lX over %08lX\r\n", CORE_UNIT_0328_VALUE, CORE_UNIT_0320_ADDRESS);
}
