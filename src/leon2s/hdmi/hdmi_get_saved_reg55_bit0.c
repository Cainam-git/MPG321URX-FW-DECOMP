/* hdmi_get_saved_reg55_bit0  (FUN_a0090f60)
 *
 * Return the saved register 0x55 bit 0 of an HDMI receiver.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: descriptive - record byte +0x8F; caller CONV2HDMITX_UpdateInterface
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0090f60 @ 0xa0090f60 (-mcpu=v8 -Os -g)
 * Source form: the record array is declared as a struct at its base address 0xA807D3E4 (the firmware builds the
 * base with sethi/or); the index is the argument masked with 0xff.
 */

/* Receiver record of an HDMI 2.0 port (0xB0 bytes, see struct hdmi_rx_record in hdmi_poll_rx_status). The part
   that hdmi_save_link_timing fills starts at +0x8D. */
struct hdmi_rx_record_timing {
    unsigned char bytes_0x00[0x8d];
    unsigned char hdmi_mode;                /* +0x8D */
    unsigned char color_depth;              /* +0x8E: bits per colour */
    unsigned char hsync_positive;           /* +0x8F */
    unsigned char vsync_positive;           /* +0x90 */
    unsigned char byte_0x91;
    unsigned short pixel_clock;             /* +0x92 */
    unsigned short tmds_clock;              /* +0x94 */
    unsigned short htotal;                  /* +0x96 */
    unsigned short hactive;                 /* +0x98 */
    unsigned short hfront_porch;            /* +0x9A */
    unsigned short hsync_width;             /* +0x9C */
    unsigned short vtotal;                  /* +0x9E */
    unsigned short vactive;                 /* +0xA0 */
    unsigned short vback_porch;             /* +0xA2 */
    unsigned short vsync_width;             /* +0xA4 */
    unsigned char bytes_0xa6[0xb0 - 0xa6];
};
extern struct hdmi_rx_record_timing hdmi_rx_records[];

/* Returns the hsync_positive byte of the record of receiver "port": bit 0 of register 0x55, saved by
   hdmi_save_link_timing. */
unsigned char hdmi_get_saved_reg55_bit0(unsigned int port)
{
    return hdmi_rx_records[(port & 0xff)].hsync_positive;
}
