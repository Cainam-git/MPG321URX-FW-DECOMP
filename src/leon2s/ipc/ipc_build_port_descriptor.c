/* ipc_build_port_descriptor  (FUN_a006fbac)
 *
 * Build the 4-word mailbox descriptor of one input port.
 * Name basis: proven - port record flags, type and timing halfwords; read by the main processor's port table
 *   code
 *
 * Matching notes
 * --------------
 * FUN_a006fbac (leon2s 0xa006fbac), flags -mcpu=v8 -Os -g.
 * Word 0 is written in three steps (assign, then two '|='). buf[1] is written as 'buf[1] = buf[1] | a | b'
 * (left to right), not 'buf[1] |= a | b'.
 */
/* One port record, 20 bytes (docs/DATA.md, input_port_records). */
struct PortRec {
    unsigned char b0, b1;
    unsigned short h2, h4, h6, h8, ha;
    unsigned char bc;
    unsigned char flags;                /* +0xD: the flags published to the main processor */
    unsigned char be, bf, b10, b11, b12, b13;
};
extern struct PortRec input_port_records[];
extern void ipc_set_message_checksum(unsigned int *buf, unsigned char n);

#define PORT_DESCRIPTOR_WORDS 4

/*
 * Build the 4-word descriptor of one input port in the message buffer.
 *
 *   id   port id; goes into the low byte of word 0
 *   n    index of the port record (the caller passes id - 1)
 *   buf  receives the four words
 *
 * word 0: id | record byte +0xD << 8 | record byte +0xE << 16
 * word 1: record byte +0xC | (record byte +0x12 & 0x1f) << 8 | record halfword +2 << 16
 * word 2: record halfword +4 | halfword +6 << 16
 * word 3: record halfword +8 | halfword +0xA << 16
 * The checksum byte is then added by ipc_set_message_checksum. The caller (ipc_publish_port_status) writes the
 * buffer to the mailbox slot of the port.
 */
void ipc_build_port_descriptor(unsigned char id, unsigned char n, unsigned int *buf)
{
    struct PortRec *r = &input_port_records[n];
    buf[0] = id;
    buf[0] |= r->flags << 8;
    buf[0] |= r->be << 16;
    buf[1] = r->bc;
    buf[1] = buf[1] | (r->b12 & 0x1f) << 8 | r->h2 << 16;
    buf[2] = r->h4 | r->h6 << 16;
    buf[3] = r->h8 | r->ha << 16;
    ipc_set_message_checksum(buf, PORT_DESCRIPTOR_WORDS);
}
