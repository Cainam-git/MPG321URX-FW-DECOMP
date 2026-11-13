/* ipc_8051_disable_internal_edid  (FUN_a0133f84)
 *
 * Tell the 8051 to switch the internal EDID of a port off.
 * Name basis: derived - 8051 commands 0x02 and 0x0F; the counterpart of the routine that prints 'Enable
 *   Internal EDID'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0133f84, flags -mcpu=v8 -O2 -g. ipc_send_8051_command is declared without a prototype, as the
 * firmware's own calls need.
 */
extern int ipc_send_8051_command();

#define IPC_8051_CMD_DISABLE_EDID        0x02
#define IPC_8051_CMD_CLEAR_EDID_ENTRIES  0x0f
#define IPC_SEND_WAIT_TAKEN              1  /* return when the 8051 has taken the command */

/*
 * Switch the internal EDID off on the input ports in the mask: command 0x02 (switch the EDID slaves off) and
 * command 0x0F (clear the extra EDID entry), in this order.
 *   port_mask: byte 1 of both commands, one bit per input port
 */
void ipc_8051_disable_internal_edid(unsigned char port_mask)

{
  
  ipc_send_8051_command(IPC_8051_CMD_DISABLE_EDID,port_mask,0,0,IPC_SEND_WAIT_TAKEN);
  ipc_send_8051_command(IPC_8051_CMD_CLEAR_EDID_ENTRIES,port_mask,0,0,IPC_SEND_WAIT_TAKEN);
  return;
}
