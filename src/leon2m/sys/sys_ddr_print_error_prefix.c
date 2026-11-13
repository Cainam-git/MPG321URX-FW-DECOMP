/* sys_ddr_print_error_prefix  (FUN_a00e0bc0)
 *
 * Print the prefix 'ddr_err: ' in front of an error message.
 * Name basis: proven - prints 'ddr_err: '
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0bc0 @ 0xa00e0bc0 (-mcpu=v8 -O2 -g)
 * Source form: the text is a string literal; the print routine is declared without a parameter list, as the
 * decompiler had it.
 */
extern int dbg_printf();

/* Print the prefix "ddr_err: " in front of an error message of the memory interface code. */
void sys_ddr_print_error_prefix(void)
{
    dbg_printf("ddr_err: ");
}
