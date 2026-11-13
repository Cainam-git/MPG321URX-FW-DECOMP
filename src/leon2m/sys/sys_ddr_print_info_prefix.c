/* sys_ddr_print_info_prefix  (FUN_a00e0ba8)
 *
 * Print the prefix 'ddr: ' in front of an information message.
 * Name basis: derived - prints 'ddr: '
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0ba8 @ 0xa00e0ba8 (-mcpu=v8 -O2 -g)
 * Source form: the text is a string literal; the print routine is declared without a parameter list, as the
 * decompiler had it.
 */
extern int dbg_printf();

/* Print the prefix "ddr: " in front of an information message of the memory interface code. */
void sys_ddr_print_info_prefix(void)
{
    dbg_printf("ddr: ");
}
