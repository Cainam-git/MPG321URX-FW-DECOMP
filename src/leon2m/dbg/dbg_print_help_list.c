/* dbg_print_help_list  (FUN_a00dd660)
 *
 * Print every line of the debug command list.
 * Name basis: derived - null-terminated list of text pointers at 0xA8025C68; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dd660 @ 0xa00dd660-0xa00dd6b0 (20 words).
 */
extern const char *dbg_help_lines[];
extern int dbg_printf(const char *fmt, ...);

/*
 * Print each text of the list dbg_help_lines (ended by a null pointer) on its own line on the debug serial port.
 * Nothing in the image calls this routine.
 */
void dbg_print_help_list(void)
{
    int i;

    for (i = 0; dbg_help_lines[i] != 0; i++)
        dbg_printf("\n%s", dbg_help_lines[i]);
}
