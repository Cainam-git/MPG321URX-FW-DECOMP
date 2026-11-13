/* dp_tx_set_lane_count  (FUN_a0087794)
 *
 * Program the lane count of a DP output, keeping enhanced framing.
 *   port: output
 *   lane_count
 * Name basis: derived - register 3 = count | bit 7 from the caps record (default 0x84)
 *
 * Matching notes
 * --------------
 * FUN_a0087794 (leon2s 0xa0087794-0xa0087824, 144 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the value expression is written out in each arm; the last call is a tail call.
 */
struct dp_tx_caps_record { unsigned char byte_0; unsigned char rest[5]; };
extern struct dp_tx_caps_record dp_tx_sink_caps_records[];    /* 6-byte caps record per output */
extern unsigned char dp_tx_reg_read8(unsigned int, unsigned short);
extern void dp_tx_reg_write8(unsigned char, unsigned short, unsigned char);
extern void dp_tx_reg_update_bits(unsigned int, short, unsigned int, unsigned int);

/*
 * Write the lane count into register 3 of a link output, keeping bit 6 of its old value. Bit 7 is added
 * when bit 4 of byte 0 of the output's caps record is set, and bit 4 of register 0x78 is cleared in that
 * case, else set.
 *   port:       link output
 *   lane_count: value for the low bits of register 3
 */
void dp_tx_set_lane_count(unsigned char port, unsigned int lane_count)
{
    unsigned int old = dp_tx_reg_read8(port, 3);
    if (dp_tx_sink_caps_records[port].byte_0 & 0x10) {
        dp_tx_reg_write8(port, 3, lane_count | (old & 0x40) | 0x80);
        dp_tx_reg_update_bits(port, 0x78, 0x10, 0);
    } else {
        dp_tx_reg_write8(port, 3, lane_count | (old & 0x40));
        dp_tx_reg_update_bits(port, 0x78, 0x10, 1);
    }
}
