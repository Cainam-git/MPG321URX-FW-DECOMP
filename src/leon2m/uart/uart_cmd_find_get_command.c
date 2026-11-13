/* uart_cmd_find_get_command  (FUN_a00bb1c4)
 *
 * Return the get command row whose id matches the received frame.
 * Returns: row 0..0x82, or 0xFF
 * Note: Uncalled copy; the same code is inlined in uart_cmd_run_tool_task. 0xFF entries match anything.
 * Name basis: derived - rows 0..0x82 of the 8-byte command table (sys_cmd_frame8_get_char)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bb1c4, flags -mcpu=v8 -O3 -g.
 * Source form: the table byte is read twice (once for the 0xff test, once for the compare), as in the firmware.
 */
extern unsigned char sys_cmd_frame8_get_char(unsigned short, unsigned short);
extern unsigned char uart_cmd_rx_record[];

#define COMMAND_ID_FIRST    2       /* the 5-character command id is in bytes 2..6 */
#define COMMAND_ID_LAST     6
#define COMMAND_ANY_CHAR    0xff    /* a table byte that matches any received character */
#define NO_COMMAND          0xff

/* Find the row of the get command table (uart_cmd_get_rows) whose id characters (bytes 2..6) equal those of the
   frame in uart_cmd_rx_record. Returns the first matching row, or NO_COMMAND. Not called; uart_cmd_run_tool_task
   has the same loop in its code. */
unsigned char uart_cmd_find_get_command(void)
{
    unsigned char row, j;

    for (row = 0; row <= 0x82; row++) {
        for (j = COMMAND_ID_FIRST; j <= COMMAND_ID_LAST; j++) {
            if (sys_cmd_frame8_get_char(row, j) != COMMAND_ANY_CHAR && sys_cmd_frame8_get_char(row, j) != uart_cmd_rx_record[j])
                break;
        }
        if (j == COMMAND_ID_LAST + 1)
            return row;
    }
    return NO_COMMAND;
}
