/* sys_ddr_print_fatal_prefix  (FUN_a00e0bd8)
 *
 * Print the prefix '[FATAL] ddr_fatal: ' in front of an error message.
 * Name basis: proven - prints '[FATAL] ddr_fatal: '
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0bd8 @ 0xa00e0bd8 (-mcpu=v8 -O2 -g)
 * Source form: the text is a string literal; the print routine is declared without a parameter list, as the
 * decompiler had it.
 */
extern int dbg_printf();

/* Print the prefix "[FATAL] ddr_fatal: " in front of a fatal error message of the memory interface code. */
void sys_ddr_print_fatal_prefix(void)
{
    dbg_printf("[FATAL] ddr_fatal: ");
}
