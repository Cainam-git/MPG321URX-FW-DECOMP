/* dp_tx_set_pattern_and_levels  (FUN_a008642c)
 *
 * Write the training pattern and the drive level of all four lanes.
 *   param_1: output
 *   param_2: pattern code
 * Returns: 1 on success
 * Name basis: derived - five bytes from DPCD 0x102: pattern, then (pre-emphasis << 3) | swing per lane
 *
 * Matching notes
 * --------------
 * FUN_a008642c (leon2s 0xa008642c-0xa00864d4, 168 bytes), flags -mcpu=v8 -Os -g.
 * Source form: bytes 2..4 are copied from byte 1. Same layout as dp_tx_set_training_pattern.
 */
extern unsigned char dp_tx_aux_request(unsigned int, unsigned int, unsigned int, char, unsigned int);

/*
 * Write five bytes starting at DPCD 0x102 (0x80 command): byte 0 is the pattern byte (pattern 0, 1, 2, 3 give
 * 0x21, 0x22, 0x23, 0x07; any other value gives 0), bytes 1..4 are all (pre_emphasis << 3) | swing, where a
 * swing or pre_emphasis above 2 gets bit 2 set. Returns 1 when the request succeeded.
 *   port:         link output
 *   pattern:      pattern code 0..3
 *   count:        length - 1 field of the request (low 4 bits)
 *   swing:        level of each lane
 *   pre_emphasis: level of each lane
 */
unsigned char dp_tx_set_pattern_and_levels(unsigned int port, unsigned int pattern, unsigned int count, unsigned char swing, unsigned char pre_emphasis)
{
    unsigned char buf[5];
    unsigned char code;
    code = (unsigned char)pattern;
    if (code == 0)
        buf[0] = 0x21;
    else if (code == 1)
        buf[0] = 0x22;
    else if (code == 2)
        buf[0] = 0x23;
    else if (code == 3)
        buf[0] = 7;
    else
        buf[0] = 0;
    if (swing > 2)
        swing |= 4;
    if (pre_emphasis > 2)
        pre_emphasis |= 4;
    buf[1] = (pre_emphasis << 3) | swing;
    buf[2] = buf[1];
    buf[3] = buf[1];
    buf[4] = buf[1];
    return dp_tx_aux_request((unsigned char)port, 0x80, 0x102, count & 0xf, (unsigned int)buf) != 0;
}
