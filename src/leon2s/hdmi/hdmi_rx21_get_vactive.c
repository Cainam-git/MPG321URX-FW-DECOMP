/* hdmi_rx21_get_vactive  (FUN_a00a2814)
 *
 * Return the vertical active height of an HDMI 2.1 input.
 *   receiver: HDMI 2.1 receiver 0/1
 * Returns: lines
 * Name basis: proven - record halfword +0x20 = DE_Line (mode info print, V_ACTIVE in
 *   hdmi_rx21_detect_timing_change)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2814 @ 0xa00a2814, flags -mcpu=v8 -Os -g.
 * receiver is masked to its low byte as in the firmware.
 */
/* One HDMI 2.1 input record (400 bytes per receiver, table at 0xA807D7E0). Only the field read here is named. */
struct rx21_record {
    unsigned char before[32];
    unsigned short vactive;                  /* +0x20 */
    unsigned char after[400 - 32 - 2];
};
extern struct rx21_record hdmi_rx21_input_records[];

/*
 * Active lines of the picture (the "DE_Line" value of the mode info print).
 * receiver is 0 or 1; the result is in lines.
 */
unsigned short hdmi_rx21_get_vactive(unsigned int receiver)
{
    return hdmi_rx21_input_records[receiver & 0xff].vactive;
}
