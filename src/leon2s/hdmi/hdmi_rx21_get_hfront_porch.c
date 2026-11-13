/* hdmi_rx21_get_hfront_porch  (FUN_a00a27dc)
 *
 * Return the horizontal front porch of an HDMI 2.1 input.
 *   receiver: HDMI 2.1 receiver 0/1
 * Returns: pixels
 * Name basis: derived - record halfword +0x28, subtracted with sync width from the blanking in
 *   hdmi_rx21_get_hback_porch
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a27dc @ 0xa00a27dc, flags -mcpu=v8 -Os -g.
 * receiver is masked to its low byte as in the firmware.
 */
/* One HDMI 2.1 input record (400 bytes per receiver, table at 0xA807D7E0). Only the field read here is named. */
struct rx21_record {
    unsigned char before[40];
    unsigned short hfront_porch;                  /* +0x28 */
    unsigned char after[400 - 40 - 2];
};
extern struct rx21_record hdmi_rx21_input_records[];

/*
 * Horizontal front porch; hdmi_rx21_get_hback_porch subtracts it from the blanking.
 * receiver is 0 or 1; the result is in pixels.
 */
unsigned short hdmi_rx21_get_hfront_porch(unsigned int receiver)
{
    return hdmi_rx21_input_records[receiver & 0xff].hfront_porch;
}
