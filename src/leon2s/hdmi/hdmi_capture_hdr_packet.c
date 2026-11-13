/* hdmi_capture_hdr_packet  (FUN_a0090638)
 *
 * Copy the received HDR (DRM) InfoFrame of an HDMI receiver.
 *   port: HDMI 2.0 receiver
 *   buf: the hdr_packet array of the receiver record that receives the copy
 * Note: When the packet is absent or not type 0x87, 0x22 bytes are cleared: the packet copy and the three flag
 *   bytes (seen, update, hold) behind it in the receiver record.
 * Name basis: proven - packet area 0x1B0, header 0x87 = CTA-861 Dynamic Range and Mastering InfoFrame
 *
 * Matching notes
 * --------------
 * FUN_a0090638 @ 0xa0090638-0xa0090718 (56 words), flags -mcpu=v8 -Os -g.
 * Source form: bytes 0 and 2 of the area are held in unsigned int locals (byte_0, byte_2) and the type and
 * the byte-2 test are nested ifs, as in hdmi_capture_avi_infoframe.
 */

#define RX_HDR_PACKET           0x1b0   /* packet area, read with reg_read_list_word */
#define PACKET_COPY_LAST_WORD   0x1cc
#define PACKET_COPY_BYTES       0x22    /* the packet array (0x1f bytes) and the three flag bytes after it */
#define INFOFRAME_TYPE_HDR      0x87

extern unsigned int reg_read_list_word(unsigned int, unsigned int, unsigned short);
extern int lib_memset(unsigned char *, unsigned int, unsigned int);

/* Copies the HDR packet area of receiver "port" (registers 0x1B0..0x1CF, read as 32-bit words) into buf, like
   hdmi_capture_vendor_packet, but only when byte 0 of the area is the type 0x87 and byte 2 is not 0. Then buf
   gets bytes 0..3, words 0x1B4..0x1C8 as bytes 4..0x1b and the low three bytes of the word at 0x1CC as bytes
   0x1c..0x1e, and the result is 1. Otherwise buf is cleared (0x22 bytes: the array and the three flag bytes
   behind it) and the result is 0. buf is the hdr_packet array of the receiver record. */
int hdmi_capture_hdr_packet(unsigned char port, unsigned char *buf)
{
    unsigned int word;
    unsigned int next_word;
    unsigned int byte_2;
    unsigned int byte_0;
    int loop;

    word = reg_read_list_word(0, port, RX_HDR_PACKET);
    byte_0 = word & 0xff;
    byte_2 = (word >> 0x10) & 0xff;
    buf[0] = (unsigned char)byte_0;
    buf[2] = (unsigned char)byte_2;
    if (byte_0 == INFOFRAME_TYPE_HDR) {
        if (byte_2 != 0) {
            buf[1] = (unsigned char)(word >> 8);
            buf[3] = (unsigned char)(word >> 0x18);
            for (loop = 0; loop <= 0x17; loop = loop + 4) {
                next_word = reg_read_list_word(0, port, loop + 0x1b4);
                buf[loop + 5] = (unsigned char)(next_word >> 8);
                buf[loop + 6] = (unsigned char)(next_word >> 0x10);
                buf[loop + 4] = (unsigned char)next_word;
                buf[loop + 7] = (unsigned char)(next_word >> 0x18);
            }
            next_word = reg_read_list_word(0, port, PACKET_COPY_LAST_WORD);
            buf[0x1c] = (unsigned char)next_word;
            buf[0x1d] = (unsigned char)(next_word >> 8);
            buf[0x1e] = (unsigned char)(next_word >> 16);
            return 1;
        }
    }
    lib_memset(buf, 0, PACKET_COPY_BYTES);
    return 0;
}
