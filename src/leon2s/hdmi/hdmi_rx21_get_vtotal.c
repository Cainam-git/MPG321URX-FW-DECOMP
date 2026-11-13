/* hdmi_rx21_get_vtotal  (FUN_a00a27f8)
 *
 * Return the vertical total of an HDMI 2.1 input.
 *   receiver: HDMI 2.1 receiver 0/1
 * Returns: lines
 * Name basis: proven - record halfword +0x1C = V_Total (mode info print); caller input_read_port_timing
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a27f8 @ 0xa00a27f8, flags -mcpu=v8 -Os -g.
 * receiver is masked to its low byte as in the firmware.
 */
/* One HDMI 2.1 input record (400 bytes per receiver, table at 0xA807D7E0). Only the field read here is named. */
struct rx21_record {
    unsigned char before[28];
    unsigned short vtotal;                  /* +0x1C */
    unsigned char after[400 - 28 - 2];
};
extern struct rx21_record hdmi_rx21_input_records[];

/*
 * Total lines per frame (V_Total of the mode info print).
 * receiver is 0 or 1; the result is in lines.
 */
unsigned short hdmi_rx21_get_vtotal(unsigned int receiver)
{
    return hdmi_rx21_input_records[receiver & 0xff].vtotal;
}
