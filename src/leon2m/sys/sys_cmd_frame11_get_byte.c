/* sys_cmd_frame11_get_byte  (FUN_a015468c)
 *
 * Return byte b of row a of the 11-byte command frame table.
 *   row
 *   column
 * Returns: table byte
 * Name basis: derived - table accessor at 0x1a7a6e; used by the command matcher uart_cmd_find_set_command
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015468c @ 0xa015468c-0xa01546ec (24 words), flags -mcpu=v8 -g (no optimisation level): both
 * parameters are spilled to the stack and reloaded.
 */
extern const unsigned char uart_cmd_set_rows11[][11];   /* the PC tool 'set' command rows of 11 bytes at 0x1A7A6E */

/*
 * Return byte 'column' of row 'row' of the 11-byte-row table of 'set' commands. The rows are ASCII frames in
 * which 0xFF marks an unused byte.
 *
 * Callers: uart_cmd_find_set_command and uart_cmd_find_set_command_port2.
 */
unsigned char sys_cmd_frame11_get_byte(unsigned short row, unsigned short column)
{
    return uart_cmd_set_rows11[row][column];
}
