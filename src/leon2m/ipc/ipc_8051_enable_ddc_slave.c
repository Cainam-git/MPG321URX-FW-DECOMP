/* ipc_8051_enable_ddc_slave  (FUN_a0133e7c)
 *
 * Tell the 8051 the DDC/CI slave address of the given ports and switch it on (command 0x07).
 * Name basis: derived - ipc_send_8051_command with command 0x07; 8051 command 0x07; the handler in the 8051
 *   program (ddc_set_slave_address, ddc_enable_slave) shows what it does
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0133e7c, flags -mcpu=v8 -O2 -g. ipc_send_8051_command is declared without a prototype, as the
 * firmware's own calls need.
 */
extern int ipc_send_8051_command();

#define IPC_8051_CMD_ENABLE_DDC_SLAVE  0x07
#define IPC_SEND_WAIT_TAKEN            1    /* return when the 8051 has taken the command */

/*
 * Command 0x07: the 8051 sets the DDC/CI slave address of the input ports in the mask, switches the slave on and
 * arms it.
 *   port_mask: byte 1, one bit per input port
 *   address:   byte 2, the slave address (the 8051 passes it to ddc_set_slave_address)
 */
void ipc_8051_enable_ddc_slave(unsigned char port_mask, unsigned char address)

{
  ipc_send_8051_command(IPC_8051_CMD_ENABLE_DDC_SLAVE,port_mask,address,0,IPC_SEND_WAIT_TAKEN);
  return;
}
