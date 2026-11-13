/* dp_tx_set_lane_drive_levels  (FUN_a0086540)
 *
 * Write the voltage swing and pre-emphasis of the lanes to the sink.
 *   port: output
 *   lane_count
 *   swing
 *   pre_emphasis: pre-emphasis
 * Returns: 1 on success
 * Name basis: derived - DPCD 0x103 TRAINING_LANEx_SET, 'max reached' bit 2 set above level 2
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0086540 @ 0xa0086540 (-mcpu=v8 -Os -g)
 * Source form: the tests keep their empty then-arms and the masks written as in the build; the combined byte
 * goes through a local before it fills the four buffer bytes.
 */
extern unsigned char dp_tx_aux_request(unsigned int port, unsigned int mode, unsigned int address, char count, unsigned int buf);

/*
 * Write the drive level byte of each lane to DPCD 0x103 (0x80 command): (pre_emphasis << 3) | swing, where a
 * swing or pre_emphasis above 2 gets bit 2 set. Four identical bytes are sent; the length field of the request
 * is (lane_count & 0xf) - 1. Returns 1 when the request succeeded.
 *   port:         link output
 *   lane_count:   number of lanes
 *   swing:        level
 *   pre_emphasis: level
 */
unsigned char dp_tx_set_lane_drive_levels(unsigned int port, unsigned int lane_count, unsigned char swing, unsigned char pre_emphasis)
{
    unsigned char buffer[4];
    unsigned char level_byte;
    
    if ((unsigned char)swing <= 2) {
        // do nothing
    } else {
        swing |= 4;
    }
    
    if ((pre_emphasis & 0xff) <= 2) {
        // do nothing
    } else {
        pre_emphasis |= 4;
    }
    
    level_byte = ((pre_emphasis & 0xff) << 3) | (unsigned char)swing;
    buffer[0] = (level_byte & 0xff);
    buffer[1] = (unsigned char)level_byte;
    buffer[2] = (unsigned char)level_byte;
    buffer[3] = (unsigned char)level_byte;
    
    return (dp_tx_aux_request(port & 0xff, 0x80, 0x103, (short)((lane_count & 0xf) - 1), (unsigned int)buffer) != 0) ? 1 : 0;
}
