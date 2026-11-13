/* hdmi_rx21_get_hactive  (FUN_a00a27a4)
 *
 * Return the horizontal active width of an HDMI 2.1 input.
 *   receiver: HDMI 2.1 receiver 0/1
 * Returns: pixels
 * Name basis: proven - record halfword +0x1E = DE (mode info print, H_ACTIVE in
 *   hdmi_rx21_detect_timing_change)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a27a4 @ 0xa00a27a4, flags -mcpu=v8 -Os -g.
 * receiver is masked to its low byte as in the firmware.
 */
/* One HDMI 2.1 input record (400 bytes per receiver, table at 0xA807D7E0). Only the field read here is named. */
struct rx21_record {
    unsigned char before[30];
    unsigned short hactive;                  /* +0x1E */
    unsigned char after[400 - 30 - 2];
};
extern struct rx21_record hdmi_rx21_input_records[];

/*
 * Active width of the picture (the "DE" value of the mode info print).
 * receiver is 0 or 1; the result is in pixels.
 */
unsigned short hdmi_rx21_get_hactive(unsigned int receiver)
{
    return hdmi_rx21_input_records[receiver & 0xff].hactive;
}
