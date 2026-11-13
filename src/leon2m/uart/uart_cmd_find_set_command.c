/* uart_cmd_find_set_command  (FUN_a00bb260)
 *
 * Return the set command row whose id matches the received frame.
 *   port: not used
 * Returns: row, or 0xFF
 * Note: Rows 0..0x8C of the 11-byte table, 0x8D..0x99 of the 26-byte table, 0x99 for the 42-byte frame.
 * Name basis: derived - sys_cmd_frame11/26/42_get_byte; caller uart_cmd_run_tool_task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bb260, flags -mcpu=v8 -O3 -g.
 * Source form: three loops, one per frame length; each table byte is read twice (once for the 0xff test, once for the
 * compare), as in the firmware. The parameter port is not used.
 */
extern unsigned char uart_cmd_rx_record[];
extern unsigned char sys_cmd_frame11_get_byte(unsigned short row, unsigned short column);
extern unsigned char sys_cmd_frame26_get_byte(unsigned short row, unsigned short column);
extern unsigned char sys_cmd_frame42_get_byte(unsigned short row, unsigned short column);

#define COMMAND_ANY_CHAR    0xff    /* a table byte that matches any received character */
#define NO_COMMAND          0xff

/*
 * Find the row of the set command tables whose characters equal those of the frame in uart_cmd_rx_record. The
 * frame's bytes 2.. are compared; a table byte of 0xff matches any character. The three tables are tried in
 * turn:
 *   11-byte frames  rows 0..0x8c   compare bytes 2..9      result = row
 *   26-byte frames  rows 0..0xc    compare bytes 2..0x18   result = 0x8d + row
 *   42-byte frame   row 0          compare bytes 2..5      result = 0x99
 * Returns NO_COMMAND when no row matches. port is not used. Called by uart_cmd_run_tool_task.
 */
unsigned char uart_cmd_find_set_command(unsigned char port)
{
    unsigned char row, j;

    for (row = 0; row <= 0x8c; row++) {
        for (j = 2; j <= 9; j++)
            if (sys_cmd_frame11_get_byte(row, j) != COMMAND_ANY_CHAR && sys_cmd_frame11_get_byte(row, j) != uart_cmd_rx_record[j])
                break;
        if (j == 10)
            return row;
    }
    for (row = 0; row <= 0xc; row++) {
        for (j = 2; j <= 0x18; j++)
            if (sys_cmd_frame26_get_byte(row, j) != COMMAND_ANY_CHAR && sys_cmd_frame26_get_byte(row, j) != uart_cmd_rx_record[j])
                break;
        if (j == 0x19)
            return row + 0x8d;
    }
    for (row = 0; row <= 0; row++) {
        for (j = 2; j <= 5; j++)
            if (sys_cmd_frame42_get_byte(row, j) != COMMAND_ANY_CHAR && sys_cmd_frame42_get_byte(row, j) != uart_cmd_rx_record[j])
                break;
        if (j == 6)
            return 0x99;
    }
    return NO_COMMAND;
}
