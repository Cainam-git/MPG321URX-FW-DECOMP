/* hdmi_capture_avi_infoframe  (FUN_a00907f0)
 *
 * Copy the received AVI InfoFrame of an HDMI receiver.
 *   port: HDMI 2.0 receiver
 *   buf: record area
 * Note: When the packet is absent or not type 0x82, 0x16 bytes are cleared: the packet copy (0x13 bytes) and
 *   the three flag bytes (seen, update, hold) behind it.
 * Name basis: proven - packet area 0x140, header 0x82 = CTA-861 AVI InfoFrame
 *
 * Matching notes
 * --------------
 * FUN_a00907f0 (leon2s, 0xa00907f0-0xa00908d0, 56 words), flags -mcpu=v8 -Os -g.
 * Source form: the third parameter of reg_read_list_word is an unsigned short (the firmware shifts loop + 0x144
 * left and right by 16); the last three stores are in ascending order 0x10, 0x11, 0x12; the port is masked at each
 * call.
 */

#define RX_AVI_PACKET           0x140   /* packet area, read with reg_read_list_word */
#define PACKET_COPY_LAST_WORD   0x150
#define PACKET_COPY_BYTES       0x16    /* the packet array (0x13 bytes) and the three flag bytes after it */
#define INFOFRAME_TYPE_AVI      0x82

extern unsigned int reg_read_list_word(unsigned int, unsigned int, unsigned short);
extern int lib_memset(unsigned char *, unsigned int, unsigned int);

/* Copies the AVI packet area of receiver "port" (registers 0x140..0x153) into buf, like
   hdmi_capture_hdr_packet, but only when byte 0 of the area is the type 0x82 and byte 2 is not 0. Then buf gets
   bytes 0..3, the words 0x144..0x14C as bytes 4..0xf and the low three bytes of the word at 0x150 as bytes
   0x10..0x12, and the result is 1. Otherwise buf is cleared (0x16 bytes: the array and the three flag bytes
   behind it) and the result is 0. buf is the avi_packet array of the receiver record. */
int hdmi_capture_avi_infoframe(unsigned char port, unsigned char *buf)
{
    unsigned int word;
    unsigned int next_word;
    unsigned int byte_2;
    unsigned int byte_0;
    int loop;

    word = reg_read_list_word(0, port & 0xff, RX_AVI_PACKET);
    byte_0 = word & 0xff;
    byte_2 = (word >> 0x10) & 0xff;
    buf[0] = (unsigned char)byte_0;
    buf[2] = (unsigned char)byte_2;
    if (byte_0 == INFOFRAME_TYPE_AVI) {
        if (byte_2 != 0) {
            buf[1] = (unsigned char)(word >> 8);
            buf[3] = (unsigned char)(word >> 0x18);
            for (loop = 0; loop <= 0xb; loop = loop + 4) {
                next_word = reg_read_list_word(0, port & 0xff, loop + 0x144);
                buf[loop + 5] = (unsigned char)(next_word >> 8);
                buf[loop + 6] = (unsigned char)(next_word >> 0x10);
                buf[loop + 4] = (unsigned char)next_word;
                buf[loop + 7] = (unsigned char)(next_word >> 0x18);
            }
            next_word = reg_read_list_word(0, port & 0xff, PACKET_COPY_LAST_WORD);
            buf[0x10] = (unsigned char)next_word;
            buf[0x11] = (unsigned char)(next_word >> 8);
            buf[0x12] = (unsigned char)(next_word >> 0x10);
            return 1;
        }
    }
    lib_memset(buf, 0, PACKET_COPY_BYTES);
    return 0;
}
