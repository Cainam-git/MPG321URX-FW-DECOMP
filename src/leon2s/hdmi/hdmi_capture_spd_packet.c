/* hdmi_capture_spd_packet  (FUN_a0090568)
 *
 * Copy the received SPD InfoFrame of an HDMI receiver.
 *   port: HDMI 2.0 receiver
 *   buf: record area
 * Note: When byte 0 of the packet area is 0, 0x22 bytes are cleared: the packet copy and the three flag bytes
 *   (seen, update, hold) behind it in the receiver record.
 * Name basis: derived - packet area 0x160 (SPD, type 0x83 at 0x164); skipped when FreeSync/VTEM flags are
 *   present
 *
 * Matching notes
 * --------------
 * FUN_a0090568 @ 0xa0090568-0xa0090638 (52 words), flags -mcpu=v8 -Os -g.
 * Source form: the same as hdmi_capture_vendor_packet.
 */

#define RX_SPD_PACKET           0x160   /* packet area, read with reg_read_list_word */
#define PACKET_COPY_LAST_WORD   0x17c
#define PACKET_COPY_BYTES       0x22    /* the packet array (0x1f bytes) and the three flag bytes after it */

extern unsigned int reg_read_list_word(unsigned int, unsigned int, unsigned short);
extern int lib_memset(unsigned char *, unsigned int, unsigned int);

/* Same copy as hdmi_capture_vendor_packet, for the SPD packet area at register 0x160 (the area that
   hdmi_detect_vrr_signalling reads). Words 0x164..0x178 go to buf[4..0x1b] and the low three bytes of the word
   at 0x17C to buf[0x1c..0x1e]. Returns 1, or 0 with buf cleared when byte 0 of the area is 0. hdmi_poll_rx_status
   calls it only when hdmi_detect_vrr_signalling reports no flags. */
int hdmi_capture_spd_packet(unsigned char port, unsigned char *buf)
{
    unsigned int word;
    unsigned int next_word;
    int loop;
    unsigned int byte0;

    word = reg_read_list_word(0, port, RX_SPD_PACKET);
    byte0 = word & 0xff;
    buf[0] = byte0;
    if (byte0 != 0) {
        buf[1] = (unsigned char)(word >> 8); buf[2] = (unsigned char)(word >> 0x10); buf[3] = (unsigned char)(word >> 0x18);
        for (loop = 0; loop <= 0x17; loop = loop + 4) {
            next_word = reg_read_list_word(0, port, loop + 0x164);
            buf[loop + 4] = (unsigned char)next_word; buf[loop + 5] = (unsigned char)(next_word >> 8); buf[loop + 6] = (unsigned char)(next_word >> 0x10); buf[loop + 7] = (unsigned char)(next_word >> 0x18);
        }
        word = reg_read_list_word(0, port, PACKET_COPY_LAST_WORD);
        buf[0x1c] = (unsigned char)word; buf[0x1d] = (unsigned char)(word >> 8); buf[0x1e] = (unsigned char)(word >> 0x10);
        return 1;
    }
    lib_memset(buf, 0, PACKET_COPY_BYTES);
    return 0;
}
