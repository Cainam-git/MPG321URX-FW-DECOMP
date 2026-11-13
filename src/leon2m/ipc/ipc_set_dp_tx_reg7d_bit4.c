/* ipc_set_dp_tx_reg7d_bit4  (FUN_a0138180)
 *
 * Ask the input processor to set or clear a control bit of a DisplayPort output.
 * Name basis: derived - command 0x63 through the mailbox portal 1 sender; unused; mailbox command 0x63, whose
 *   handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138180 @ 0xa0138180, flags -mcpu=v8 -O2 -g.
 * Source form: the message is a 4-byte array initialised with the two parameters; the print comes before the
 * send and its result is not used.
 */
#define IPC_CMD_SET_DP_TX_FASTMUTE_PATTERN 0x63 /* mailbox command 0x63 */
#define IPC_SEND_NO_WAIT                   0    /* ipc_send_command: do not wait for the input processor */
extern int dbg_printf();
extern int ipc_send_command();

/*
 * Print the two values ('MailBoxSub_SeteDPTXFastMutePattern') and ask the input processor to set or clear
 * bit 4 of register 0x7D of one DisplayPort output (mailbox command 0x63).
 *
 *   output  DP output
 *   on      1 sets the bit, any other value clears it
 *
 * No routine of the main program calls it.
 */
void ipc_set_dp_tx_reg7d_bit4(unsigned char output, unsigned char on)
{
    unsigned char msg[4] = {output, on};
    dbg_printf("MailBoxSub_SeteDPTXFastMutePattern (%d) %d\r\n", output & 0xff, on & 0xff);
    ipc_send_command(IPC_CMD_SET_DP_TX_FASTMUTE_PATTERN, 4, msg, IPC_SEND_NO_WAIT);
}
