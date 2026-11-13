/* hdmi_rx21_get_vback_porch  (FUN_a00a284c)
 *
 * Return the vertical back porch of an HDMI 2.1 input.
 *   receiver: HDMI 2.1 receiver 0/1
 * Returns: lines
 * Name basis: derived - record halfword +0x2A; same slot as hdmi_get_saved_vback_porch in
 *   input_read_port_timing
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a284c @ 0xa00a284c, flags -mcpu=v8 -Os -g.
 * receiver is masked to its low byte as in the firmware.
 */
/* One HDMI 2.1 input record (400 bytes per receiver, table at 0xA807D7E0). Only the field read here is named. */
struct rx21_record {
    unsigned char before[42];
    unsigned short vback_porch;                  /* +0x2A */
    unsigned char after[400 - 42 - 2];
};
extern struct rx21_record hdmi_rx21_input_records[];

/*
 * Vertical back porch.
 * receiver is 0 or 1; the result is in lines.
 */
unsigned short hdmi_rx21_get_vback_porch(unsigned int receiver)
{
    return hdmi_rx21_input_records[receiver & 0xff].vback_porch;
}
