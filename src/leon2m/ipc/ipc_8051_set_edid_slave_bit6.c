/* ipc_8051_set_edid_slave_bit6  (FUN_a01340b0)
 *
 * Have the 8051 set or clear bit 6 of a port's EDID slave control register (command 0x1F).
 * Name basis: derived - ipc_send_8051_command with command 0x1F; 8051 command 0x1F; the handler in the 8051
 *   program (edid_set_port_control_bit6) shows what it does
 *
 * Matching notes
 * --------------
 * FUN_a01340b0, flags -mcpu=v8 -O2 -g. ipc_send_8051_command is declared without a prototype, as the firmware's
 * own calls need. Both branches end in their own call and return.
 */
extern int ipc_send_8051_command();

#define IPC_8051_CMD_EDID_SLAVE_BIT6  0x1f
#define IPC_SEND_WAIT_TAKEN           1 /* return when the 8051 has taken the command */

/*
 * Command 0x1F: the 8051 sets or clears bit 6 of the EDID slave control register of one port.
 *   port: byte 1, one-hot port (0x01..0x40)
 *   set:  non-zero sends 1 in bytes 2 and 3 (the 8051 sets the bit when byte 2 is 1), 0 sends 0 (bit cleared)
 */
void ipc_8051_set_edid_slave_bit6(unsigned char port, unsigned char set)

{
  if (set != '\0') {
    ipc_send_8051_command(IPC_8051_CMD_EDID_SLAVE_BIT6,port,1,1,IPC_SEND_WAIT_TAKEN);
    return;
  }
  ipc_send_8051_command(IPC_8051_CMD_EDID_SLAVE_BIT6,port,0,0,IPC_SEND_WAIT_TAKEN);
  return;
}
