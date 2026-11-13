/* hdmi_capture_vendor_packet  (FUN_a0090498)
 *
 * Copy the received vendor-specific packet of an HDMI receiver.
 *   port: HDMI 2.0 receiver
 *   buf: record area
 * Note: When byte 0 of the packet area is 0, 0x22 bytes are cleared: the packet copy and the three flag bytes
 *   (seen, update, hold) behind it in the receiver record.
 * Name basis: derived - packet area 0x280 on status reg 0x72 bit 1; record bytes from +0x6B
 *
 * Matching notes
 * --------------
 * FUN_a0090498 @ 0xa0090498-0xa0090568 (52 words), flags -mcpu=v8 -Os -g.
 * Source form: byte 0 is kept in an unsigned int local (the firmware masks, compares and stores the masked
 * value); the loop stores bytes 4,5,6,7 in ascending order and the tail stores 0x1c,0x1d,0x1e in ascending
 * order (the scheduler then gives the firmware's 7,5,6,4 / 1e,1d,1c).
 */

#define RX_VENDOR_PACKET        0x280   /* packet area, read with reg_read_list_word */
#define PACKET_COPY_LAST_WORD   0x29c
#define PACKET_COPY_BYTES       0x22    /* the packet array (0x1f bytes) and the three flag bytes after it */

extern unsigned int reg_read_list_word(unsigned int, unsigned int, unsigned short);
extern int lib_memset(unsigned char *, unsigned int, unsigned int);

/* Copies the vendor-specific packet area of receiver "port" (registers 0x280..0x29F, read as 32-bit words)
   into buf: bytes 0..3 from the first word, bytes 4..0x1b from the six words after it, bytes 0x1c..0x1e from the
   low three bytes of the word at 0x29C. Returns 1. When byte 0 of the area is 0, buf is cleared instead and the
   result is 0. buf is the vendor_packet array of the receiver record (see hdmi_poll_rx_status); the clear covers
   0x22 bytes, which is the array and the three flag bytes behind it (seen, update, hold). */
int hdmi_capture_vendor_packet(unsigned char port, unsigned char *buf)
{
    unsigned int word;
    unsigned int next_word;
    int loop;
    unsigned int byte0;

    word = reg_read_list_word(0, port, RX_VENDOR_PACKET);
    byte0 = word & 0xff;
    buf[0] = byte0;
    if (byte0 != 0) {
        buf[1] = (unsigned char)(word >> 8); buf[2] = (unsigned char)(word >> 0x10); buf[3] = (unsigned char)(word >> 0x18);
        for (loop = 0; loop <= 0x17; loop = loop + 4) {
            next_word = reg_read_list_word(0, port, loop + 0x284);
            buf[loop + 4] = (unsigned char)next_word; buf[loop + 5] = (unsigned char)(next_word >> 8); buf[loop + 6] = (unsigned char)(next_word >> 0x10); buf[loop + 7] = (unsigned char)(next_word >> 0x18);
        }
        word = reg_read_list_word(0, port, PACKET_COPY_LAST_WORD);
        buf[0x1c] = (unsigned char)word; buf[0x1d] = (unsigned char)(word >> 8); buf[0x1e] = (unsigned char)(word >> 0x10);
        return 1;
    }
    lib_memset(buf, 0, PACKET_COPY_BYTES);
    return 0;
}
