/* ipc_get_hdmi_tx_registers  (FUN_a0137fcc)
 *
 * Ask the input processor to read eight registers of an HDMI output.
 * Returns: reply value
 * Name basis: derived - command 0x45 through the mailbox portal 1 sender; unused; mailbox command 0x45, whose
 *   handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137fcc @ 0xa0137fcc, flags -mcpu=v8 -O3 -g.
 * Source form: the message is a zeroed 4-byte array with the port stored afterwards; the two reply words are
 * read into locals before the four sums.
 */
#define IPC_CMD_GET_HDMI_TX_REGISTERS 0x45      /* mailbox command 0x45 */
#define IPC_SEND_NO_WAIT              0         /* ipc_send_command: do not wait for the input processor */
extern int ipc_send_command();
extern void ipc_wait_reply(int);
extern unsigned int ipc_reply_words[];

/*
 * Read eight registers of one HDMI transmitter port through the input processor (mailbox command 0x45) and
 * add them up in pairs. The reply bytes 0..7 are the registers 0x3A..0x3D and 0x60..0x63 of bank 0 (all zero
 * for a port above 1). They arrive in reply words 1 and 2, the first byte in the low bits.
 *
 *   port  HDMI transmitter port
 *   out   four halfwords: reply byte 0 + 1, byte 2 + 3, byte 4 + 5, byte 6 + 7
 *
 * No routine of the main program calls it.
 */
void ipc_get_hdmi_tx_registers(unsigned char port, unsigned short *out)
{
    unsigned char msg[4] = {0};
    unsigned int word1, word2;

    msg[0] = port;
    ipc_send_command(IPC_CMD_GET_HDMI_TX_REGISTERS, 4, msg, IPC_SEND_NO_WAIT);
    ipc_wait_reply(1);
    word1 = ipc_reply_words[1];
    word2 = ipc_reply_words[2];
    out[0] = (word1 & 0xff) + ((word1 >> 8) & 0xff);
    out[1] = ((word1 >> 16) & 0xff) + (word1 >> 24);
    out[2] = (word2 & 0xff) + ((word2 >> 8) & 0xff);
    out[3] = ((word2 >> 16) & 0xff) + (word2 >> 24);
}
