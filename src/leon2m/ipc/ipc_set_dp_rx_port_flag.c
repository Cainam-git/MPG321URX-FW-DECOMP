/* ipc_set_dp_rx_port_flag  (FUN_a01392d0)
 *
 * Ask the input processor to set a flag of a DisplayPort receiver port.
 * Note: No routine calls it.
 * Name basis: derived - command 0x30 through the mailbox portal 1 sender; unused; mailbox command 0x30, whose
 *   handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01392d0 @ 0xa01392d0 (-mcpu=v8 -O2 -g).
 * The routine is declared void but ends in 'return 0;', so the compiler sets no value in %i0 before 'ret; restore'.
 */
extern int ipc_send_command();

#define IPC_CMD_SET_DP_RX_FLAG_128 0x30         /* mailbox command 0x30 */
#define IPC_SEND_NO_WAIT           0            /* do not wait for the reply slot */

/*
 * Send mailbox command 0x30 to the input processor with one data byte, the number of a DisplayPort receiver
 * port. The input processor sets the byte at +0x128 of that port's record to 1 (ports 0 and 1 only).
 * Returns nothing.
 */
void ipc_set_dp_rx_port_flag(unsigned char port)
{
    ipc_send_command(IPC_CMD_SET_DP_RX_FLAG_128, 1, &port, IPC_SEND_NO_WAIT);
    return 0;
}
