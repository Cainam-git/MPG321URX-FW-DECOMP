/* hdmi_capture_audio_infoframe  (FUN_a0090718)
 *
 * Copy the received audio InfoFrame of an HDMI receiver.
 *   port: HDMI 2.0 receiver
 *   buf: record area
 * Note: When the packet is absent or not type 0x84, 0x11 bytes are cleared: the packet copy (0x0E bytes) and
 *   the three flag bytes (seen, update, hold) behind it.
 * Name basis: proven - packet area 0x180, header 0x84 = CTA-861 Audio InfoFrame
 *
 * Matching notes
 * --------------
 * FUN_a0090718 @ 0xa0090718-0xa00907f0 (54 words), flags -mcpu=v8 -Os -g.
 * Source form: the same as hdmi_capture_hdr_packet.
 */

#define RX_AUDIO_PACKET         0x180   /* packet area, read with reg_read_list_word */
#define PACKET_COPY_LAST_WORD   0x18c
#define PACKET_COPY_BYTES       0x11    /* the packet array (0xe bytes) and the three flag bytes after it */
#define INFOFRAME_TYPE_AUDIO    0x84

extern unsigned int reg_read_list_word(unsigned int, unsigned int, unsigned short);
extern int lib_memset(unsigned char *, unsigned int, unsigned int);

/* Copies the audio packet area of receiver "port" (registers 0x180..0x18F) into buf, like
   hdmi_capture_hdr_packet, but only when byte 0 of the area is the type 0x84 and byte 2 is not 0. Then buf gets
   bytes 0..3, the words 0x184 and 0x188 as bytes 4..0xb and the low two bytes of the word at 0x18C as bytes
   0xc and 0xd, and the result is 1. Otherwise buf is cleared (0x11 bytes: the array and the three flag bytes
   behind it) and the result is 0. buf is the audio_packet array of the receiver record. */
int hdmi_capture_audio_infoframe(unsigned char port, unsigned char *buf)
{
    unsigned int word;
    unsigned int next_word;
    unsigned int byte_2;
    unsigned int byte_0;
    int loop;

    word = reg_read_list_word(0, port, RX_AUDIO_PACKET);
    byte_0 = word & 0xff;
    byte_2 = (word >> 0x10) & 0xff;
    buf[0] = (unsigned char)byte_0;
    buf[2] = (unsigned char)byte_2;
    if (byte_0 == INFOFRAME_TYPE_AUDIO) {
        if (byte_2 != 0) {
            buf[1] = (unsigned char)(word >> 8);
            buf[3] = (unsigned char)(word >> 0x18);
            for (loop = 0; loop <= 7; loop = loop + 4) {
                next_word = reg_read_list_word(0, port, loop + 0x184);
                buf[loop + 5] = (unsigned char)(next_word >> 8);
                buf[loop + 6] = (unsigned char)(next_word >> 0x10);
                buf[loop + 4] = (unsigned char)next_word;
                buf[loop + 7] = (unsigned char)(next_word >> 0x18);
            }
            next_word = reg_read_list_word(0, port, PACKET_COPY_LAST_WORD);
            buf[0xc] = (unsigned char)next_word;
            buf[0xd] = (unsigned char)(next_word >> 8);
            return 1;
        }
    }
    lib_memset(buf, 0, PACKET_COPY_BYTES);
    return 0;
}
