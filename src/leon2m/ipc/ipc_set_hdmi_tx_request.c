/* ipc_set_hdmi_tx_request  (FUN_a0137e10)
 *
 * Ask the input processor to store a full HDMI output request (source, clock, format).
 * Name basis: derived - command 0x42 through the mailbox portal 1 sender; unused; mailbox command 0x42, whose
 *   handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0137e10 @ 0xa0137e10, flags -mcpu=v8 -O3 -g.
 * Source form: the message bytes are stored in ascending order; the record is a struct of 1-bit fields (the two
 * leading halfwords) followed by single bytes, and byte +3 is a separate unsigned char member after the four flag
 * bits of the second halfword; the flag_c15 term is written '(unsigned char)req->h2_flag_15 << 5' (the bit is
 * masked with 'and 0xff' before the shift).
 */
#define IPC_CMD_SET_HDMI_TX_REQUEST 0x42        /* mailbox command 0x42 */
#define IPC_SEND_NO_WAIT            0           /* ipc_send_command: do not wait for the input processor */

/*
 * The request record of one HDMI transmitter port, as this routine reads it. The first halfword is 16 flag bits
 * (bit15 first); the second halfword has four flag bits, four unused bits and the source code. Fields that are
 * only copied are named by their offset.
 */
struct hdmi_tx_request {
    unsigned short bit15:1, bit14:1, bit13:1, bit12:1, bit11:1, bit10:1, bit9:1, bit8:1,
                   bit7:1, bit6:1, bit5:1, bit4:1, bit3:1, bit2:1, bit1:1, bit0:1;
    unsigned short h2_bit15:1, h2_bit14:1, h2_bit13:1, h2_bit12:1, h2_unused:4;
    unsigned char source_code;                  /* +3 */
    unsigned short pixel_clock;                 /* +4 */
    unsigned char byte_0x6, byte_0x7, byte_0x8, byte_0x9, byte_0xa, byte_0xb, byte_0xc, byte_0xd, byte_0xe;
    unsigned char input_code;                   /* +0xf */
};
extern void ipc_send_command(unsigned int cmd, unsigned char len, unsigned char *p, unsigned char wait);

/*
 * Send the full request of one HDMI transmitter port to the input processor (mailbox command 0x42). The input
 * processor stores it, marks the request pending and applies it to the port. The 32-byte message is built from
 * the record; message bytes 15..17 and 19..31 are not written.
 *
 *   port  HDMI transmitter port
 *   req   the request record
 *
 * No routine of the main program calls it.
 */
void ipc_set_hdmi_tx_request(unsigned char port, struct hdmi_tx_request *req)
{
    unsigned char msg[32];

    msg[0] = port;
    msg[1] = req->source_code;
    msg[2] = req->pixel_clock;
    msg[3] = req->pixel_clock >> 8;
    /* Bytes 4, 7 and 10 collect single flag bits of the record. */
    msg[4] = req->bit13 << 7 | req->bit11 << 6 | req->bit10 << 5 | req->byte_0x6;
    msg[5] = req->byte_0x7;
    msg[6] = req->byte_0xa << 4 | req->byte_0x9;
    msg[7] = req->bit12 | req->bit9 << 1 | req->bit8 << 2 | req->bit14 << 3 | req->bit5 << 4 | req->bit4 << 5 | req->bit3 << 6 | req->h2_bit12 << 7;
    msg[8] = req->byte_0x8;
    msg[9] = req->byte_0xb;
    msg[10] = req->bit7 | req->bit6 << 1 | req->bit2 << 2 | req->bit1 << 3 | req->bit0 << 4 | (unsigned char)req->h2_bit15 << 5 | req->h2_bit14 << 6 | req->h2_bit13 << 7;
    msg[11] = req->byte_0xc;
    msg[12] = req->byte_0xd;
    msg[13] = req->byte_0xe;
    msg[14] = 0;
    msg[18] = req->input_code;
    ipc_send_command(IPC_CMD_SET_HDMI_TX_REQUEST, 0x20, msg, IPC_SEND_NO_WAIT);
}
