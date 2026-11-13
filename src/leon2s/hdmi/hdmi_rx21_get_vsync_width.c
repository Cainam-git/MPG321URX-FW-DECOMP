/* hdmi_rx21_get_vsync_width  (FUN_a00a2830)
 *
 * Return the vertical sync width of an HDMI 2.1 input.
 *   receiver: HDMI 2.1 receiver 0/1
 * Returns: lines
 * Name basis: derived - record halfword +0x26; same slot as hdmi_get_saved_vsync_width in
 *   input_read_port_timing
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2830 @ 0xa00a2830, flags -mcpu=v8 -Os -g.
 * receiver is masked to its low byte as in the firmware.
 */
/* One HDMI 2.1 input record (400 bytes per receiver, table at 0xA807D7E0). Only the field read here is named. */
struct rx21_record {
    unsigned char before[38];
    unsigned short vsync_width;                  /* +0x26 */
    unsigned char after[400 - 38 - 2];
};
extern struct rx21_record hdmi_rx21_input_records[];

/*
 * Width of the vertical sync pulse.
 * receiver is 0 or 1; the result is in lines.
 */
unsigned short hdmi_rx21_get_vsync_width(unsigned int receiver)
{
    return hdmi_rx21_input_records[receiver & 0xff].vsync_width;
}
