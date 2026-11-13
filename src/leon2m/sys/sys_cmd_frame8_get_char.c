/* sys_cmd_frame8_get_char  (FUN_a015463c)
 *
 * Return character b of row a of the 8-byte command frame table.
 *   row
 *   column
 * Returns: table byte
 * Name basis: derived - table accessor; row 2 is the text '580040:'; used by the command parser at
 *   0xa00bac3c..
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015463c @ 0xa015463c, flags -mcpu=v8 -g (no optimisation level): both parameters are spilled to the
 * stack and reloaded.
 */
extern const unsigned char uart_cmd_get_rows[][8];      /* the PC tool 'get' command rows at 0x1A7656 */

/*
 * Return character 'column' of row 'row' of the 'get' command table (8 characters per row).
 *
 * Called by the PC tool command routines (uart_cmd_build_get_reply, UartSetI2CEnable and about thirty others in
 * src/leon2m/FUN_a00b*.c to uart/uart_cmd_run_tool_task.c).
 */
unsigned char sys_cmd_frame8_get_char(unsigned short row, unsigned short column)
{
    return uart_cmd_get_rows[row][column];
}
