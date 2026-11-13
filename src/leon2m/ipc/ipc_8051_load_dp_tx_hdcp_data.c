/* ipc_8051_load_dp_tx_hdcp_data  (FUN_a0133dec)
 *
 * Tell the 8051 to load the copy-protection data of the DisplayPort output (command 0x21).
 * Name basis: derived - ipc_send_8051_command with command 0x21; unused; 8051 command 0x21; the handler in the
 *   8051 program (hdcp_load_dptx_key_data, prints CMD_WRITE_DPTXHDCP) shows what it does
 *
 * Matching notes
 * --------------
 * FUN_a0133dec, flags -mcpu=v8 -O2 -g. Tail call of ipc_send_8051_command.
 */
extern void ipc_send_8051_command(unsigned char cmd, unsigned char arg1, unsigned char arg2, unsigned char arg3, unsigned char mode);

#define IPC_8051_CMD_LOAD_DPTX_HDCP  0x21
#define IPC_SEND_WAIT_TAKEN          1  /* return when the 8051 has taken the command */

/* Command 0x21: the 8051 loads the HDCP data block of the DisplayPort transmitter (it prints
   CMD_WRITE_DPTXHDCP). No arguments. Nothing in the firmware calls this routine. */
void ipc_8051_load_dp_tx_hdcp_data(void)
{
    ipc_send_8051_command(IPC_8051_CMD_LOAD_DPTX_HDCP, 0, 0, 0, IPC_SEND_WAIT_TAKEN);
}
