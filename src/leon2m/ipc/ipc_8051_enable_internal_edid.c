/* ipc_8051_enable_internal_edid  (FUN_a0133fbc)
 *
 * Tell the 8051 to switch the internal EDID of a port on.
 * Name basis: proven - prints 'Enable Internal EDID'; 8051 commands 0x01 and 0x0E
 *
 * Matching notes
 * --------------
 * FUN_a0133fbc, flags -mcpu=v8 -O2 -g. The two size flags are unsigned char locals set to 1; the first is passed as
 * (flag & 1), the second is tested with == 1; a plain truth test changes the block order.
 */
extern unsigned char dbg_is_print_enabled(int);
extern int dbg_printf();
extern void ipc_send_8051_command(unsigned char cmd, unsigned char arg1, unsigned char arg2, unsigned char arg3, unsigned char mode);

#define DBG_MAILBOX                    0x20 /* debug class of the 8051 mailbox prints */
#define IPC_8051_CMD_ENABLE_EDID       0x01
#define IPC_8051_CMD_SET_EDID_ENTRIES  0x0e
#define IPC_SEND_WAIT_TAKEN            1    /* return when the 8051 has taken the command */
#define EDID_SLAVE_ADDRESS             0xa0 /* byte 2 of command 0x01 */
#define EDID_LONG_THRESHOLD            0x80 /* longer EDIDs are sent with the 256-byte flag */
#define EDID_EXTENDED_THRESHOLD        0x100    /* longer EDIDs also get command 0x0E */

/*
 * Switch the internal EDID on for the input ports in the mask. Callers: edid_enable_internal_edid, startup_load_port_edids,
 * edid_write_port_edid and edid_set_port_internal_edid.
 *   port_mask:   one bit per input port (byte 1 of both commands)
 *   length:      EDID length in bytes
 *   entry_value: byte 2 of command 0x0E, the value the 8051 stores in the extra EDID entry of each port
 * Command 0x01 goes out always, with the slave address 0xA0 and byte 3 = 1 when the EDID is longer than 128 bytes
 * (256-byte mode). Command 0x0E goes out only when the EDID is longer than 256 bytes.
 */
void ipc_8051_enable_internal_edid(unsigned char port_mask, unsigned short length, unsigned char entry_value)
{
    unsigned char big = 0, huge = 0;

    if (dbg_is_print_enabled(DBG_MAILBOX))
        dbg_printf("\nEnable Internal EDID : %d\r\n", port_mask);
    if (length > EDID_LONG_THRESHOLD)
        big = 1;
    ipc_send_8051_command(IPC_8051_CMD_ENABLE_EDID, port_mask, EDID_SLAVE_ADDRESS, big & 1, IPC_SEND_WAIT_TAKEN);
    if (length > EDID_EXTENDED_THRESHOLD)
        huge = 1;
    if (huge == 1)
        ipc_send_8051_command(IPC_8051_CMD_SET_EDID_ENTRIES, port_mask, entry_value, 0, IPC_SEND_WAIT_TAKEN);
}
