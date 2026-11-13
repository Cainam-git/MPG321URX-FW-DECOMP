/* ipc_set_dp_tx_drive_levels  (FUN_a013844c)
 *
 * Send the base swing and pre-emphasis bytes of the four lanes of a DP output to the input processor.
 *   output: DP output
 *   pairs: eight bytes: two per lane 0..3
 * Name basis: derived - command 0x59 through the mailbox portal 1 sender with four byte pairs; its handler in
 *   the input program calls dp_tx_set_drive_level_base once per lane; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013844c @ 0xa013844c, flags -mcpu=v8 -O3 -g.
 * Source form: plain msg[4 + 2i] = src[2i]; msg[5 + 2i] = src[2i + 1] with a u8 counter (the scheduler puts the +1
 * store first); one 12-byte message array; bytes 1..3 are not written.
 */
#define IPC_CMD_SET_DP_TX_DRIVE_LEVELS 0x59     /* mailbox command 0x59 */
#define IPC_SEND_NO_WAIT               0        /* ipc_send_command: do not wait for the input processor */
#define LANES                          4
extern void ipc_send_command(int, int, unsigned char *, int);

/*
 * Send one byte pair per lane of a DisplayPort output to the input processor (mailbox command 0x59). For each
 * lane 0..3 the input processor passes the pair, with the output and the lane, to dp_tx_set_drive_level_base.
 *
 *   output  DP output (message byte 0)
 *   pairs   eight bytes: the pair of lane n at pairs[2n] and pairs[2n + 1] (message bytes 4 + 2n and 5 + 2n)
 *
 * No routine of the main program calls it.
 */
void ipc_set_dp_tx_drive_levels(unsigned char output, const unsigned char *pairs)
{
    unsigned char msg[12];
    unsigned char lane;

    msg[0] = output;
    for (lane = 0; lane < LANES; lane++) {
        msg[4 + lane * 2] = pairs[lane * 2];
        msg[5 + lane * 2] = pairs[lane * 2 + 1];
    }
    ipc_send_command(IPC_CMD_SET_DP_TX_DRIVE_LEVELS, 0xc, msg, IPC_SEND_NO_WAIT);
}
