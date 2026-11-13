/* sys_cmd_frame42_get_byte  (FUN_a0154750)
 *
 * Return byte b of row a of the 42-byte command frame table.
 *   row
 *   column
 * Returns: table byte
 * Name basis: derived - table accessor at 0x1a81cf; used by the command matcher uart_cmd_find_set_command
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0154750, flags -g only (no -mcpu=v8, no optimisation level): the row offset row * 42 is built from
 * shifts and adds, as SPARC v7 has no multiply instruction.
 */
extern const unsigned char uart_cmd_set_rows42[][42];   /* the PC tool 'set' command rows of 42 bytes at 0x1A81CF */

/*
 * Return byte 'column' of row 'row' of the 42-byte-row table of 'set' commands.
 *
 * Callers: uart_cmd_find_set_command and uart_cmd_find_set_command_port2.
 */
unsigned char sys_cmd_frame42_get_byte(unsigned short row, unsigned short column)
{
    return uart_cmd_set_rows42[row][column];
}
