/* ipc_8051_disable_ddc_slave  (FUN_a0133e58)
 *
 * Tell the 8051 to switch the DDC/CI slave of the given ports off (command 0x08).
 * Name basis: derived - ipc_send_8051_command with command 0x08; 8051 command 0x08; the handler in the 8051
 *   program (ddc_disable_slave) shows what it does
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0133e58, flags -mcpu=v8 -O2 -g. ipc_send_8051_command is declared without a prototype, as the
 * firmware's own calls need.
 */
extern int ipc_send_8051_command();

#define IPC_8051_CMD_DISABLE_DDC_SLAVE  0x08
#define IPC_SEND_WAIT_TAKEN             1   /* return when the 8051 has taken the command */

/*
 * Command 0x08: the 8051 switches the DDC/CI slave off on the input ports in the mask.
 *   port_mask: byte 1, one bit per input port
 */
void ipc_8051_disable_ddc_slave(unsigned char port_mask)

{
  ipc_send_8051_command(IPC_8051_CMD_DISABLE_DDC_SLAVE,port_mask,0,0,IPC_SEND_WAIT_TAKEN);
  return;
}
