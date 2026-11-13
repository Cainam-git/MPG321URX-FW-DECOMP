/* hdmi_rx21_get_hsync_width  (FUN_a00a27c0)
 *
 * Return the horizontal sync width of an HDMI 2.1 input.
 *   receiver: HDMI 2.1 receiver 0/1
 * Returns: pixels
 * Name basis: derived - record halfword +0x24; same slot as hdmi_get_saved_hsync_width in
 *   input_read_port_timing
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a27c0 @ 0xa00a27c0, flags -mcpu=v8 -Os -g.
 * receiver is masked to its low byte as in the firmware.
 */
/* One HDMI 2.1 input record (400 bytes per receiver, table at 0xA807D7E0). Only the field read here is named. */
struct rx21_record {
    unsigned char before[36];
    unsigned short hsync_width;                  /* +0x24 */
    unsigned char after[400 - 36 - 2];
};
extern struct rx21_record hdmi_rx21_input_records[];

/*
 * Width of the horizontal sync pulse.
 * receiver is 0 or 1; the result is in pixels.
 */
unsigned short hdmi_rx21_get_hsync_width(unsigned int receiver)
{
    return hdmi_rx21_input_records[receiver & 0xff].hsync_width;
}
