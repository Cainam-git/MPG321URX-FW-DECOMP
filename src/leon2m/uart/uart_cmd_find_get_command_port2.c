/* uart_cmd_find_get_command_port2  (FUN_a00bb86c)
 *
 * Return the get command row matching the frame received on port 2.
 * Returns: row, or 0xFF
 * Note: Uncalled copy (inlined in uart_cmd_poll_port2).
 * Name basis: derived - same table walk as uart_cmd_find_get_command on 0xA802D040
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bb86c, flags -mcpu=v8 -O3 -g.
 * Source form: the table byte is read twice (once for the 0xff test, once for the compare), as in the firmware.
 */
extern unsigned char sys_cmd_frame8_get_char(unsigned short, unsigned short);
extern unsigned char uart_cmd_rx_record_port2[];

#define COMMAND_ANY_CHAR    0xff    /* a table byte that matches any received character */
#define NO_COMMAND          0xff

/* Find the row of the get command table (uart_cmd_get_rows) whose id characters (bytes 2..6) equal those of the
   frame in uart_cmd_rx_record_port2. Returns the first matching row, or NO_COMMAND. Not called;
   uart_cmd_poll_port2 has the same loop in its code. */
unsigned char uart_cmd_find_get_command_port2(void)
{
    unsigned char row, j;

    for (row = 0; row <= 0x82; row++) {
        for (j = 2; j <= 6; j++) {
            if (sys_cmd_frame8_get_char(row, j) != COMMAND_ANY_CHAR && sys_cmd_frame8_get_char(row, j) != uart_cmd_rx_record_port2[j])
                break;
        }
        if (j == 7)
            return row;
    }
    return NO_COMMAND;
}
