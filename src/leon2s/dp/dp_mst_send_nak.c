/* dp_mst_send_nak  (FUN_a00d9474)
 *
 * Answer an unsupported MST request with a refusal that carries the device's 16-byte id.
 * Name basis: proven - default case of the dispatcher: 19-byte reply with the request number, 16 id bytes and
 *   two reason bytes
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d9474 @ 0xa00d9474-0xa00d9524 (44 words), flags -mcpu=v8 -Os -g.
 * Source form: the packet is a union of a bit-field view of the first word (bit 7 and the 7-bit id of byte 0)
 * and a byte view of 20 bytes.
 */
extern unsigned char dp_mst_message_state_port;
extern volatile unsigned int *dp_mst_ctl_reg_blocks[];
extern void dp_mst_send_reply(void *, int, int, int, int);
#define MST_REPLY_NAK       0xf     /* reply type 15: dp_mst_pack_byte_run copies the 19 bytes */
#define NAK_LENGTH          0x13    /* bytes of the reply */
#define NAK_ID_BYTES        16      /* bytes 1..16 */
#define CTL_REG_ID_WORD     (0xd00 / 4)

/* The reply: byte 0 = bit 7 set and the request number in bits 0..6, bytes 1..16 = the low bytes of 16 registers,
 * byte 17 and byte 18 = the two reason bytes. */
union nak_packet {
    struct {
        unsigned int bit31 : 1;
        unsigned int request : 7;
        unsigned int rest : 24;
    } h;
    unsigned char b[20];
};

/*
 * Answer a request that has no handler: build a 19-byte reply (type 15) and queue it.
 *   request:    request number of the refused message, stored in the low 7 bits of byte 0 (bit 7 is set)
 *   reason_1, reason_2: stored unchanged in bytes 17 and 18
 * Bytes 1..16 are the low bytes of the 16 registers starting at byte offset +0xD00 of the control register
 * block of the current port. After the reply is queued, bit 5 of the first word of that block is set.
 * Called by dp_mst_dispatch_request, with reasons 4 and 0.
 */
void dp_mst_send_nak(unsigned char request, unsigned char reason_1, unsigned char reason_2)
{
    union nak_packet packet;
    unsigned char i;

    packet.h.bit31 = 1;
    packet.h.request = request;
    for (i = 0; i < NAK_ID_BYTES; i++)
        packet.b[i + 1] = dp_mst_ctl_reg_blocks[dp_mst_message_state_port][CTL_REG_ID_WORD + i];
    packet.b[17] = reason_1;
    packet.b[18] = reason_2;
    dp_mst_send_reply(&packet, 2, 1, MST_REPLY_NAK, NAK_LENGTH);
    dp_mst_ctl_reg_blocks[dp_mst_message_state_port][0] |= 0x20;
}
