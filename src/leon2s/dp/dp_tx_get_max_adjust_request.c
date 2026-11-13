/* dp_tx_get_max_adjust_request  (FUN_a0086fb0)
 *
 * Return the highest adjust request over the lanes.
 *   p: status record
 *   mode: lane count (low 4 bits used)
 * Name basis: descriptive - byte maximum of the swing or pre-emphasis requests of the status record
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0086fb0 (0xa0086fb0-0xa0087074, 196 bytes, 49 words), flags -mcpu=v8 -Os -g.
 * Source form: every step is written 'if (v < p[k]) v = p[k];', so each load is its own block-local value;
 * the firmware gives them fresh registers (%i2, %i1, %i0) and re-masks both sides with and 0xff. One shared
 * temp variable gives one global register instead. 'p[k] > v' gives the same code as 'v < p[k]'.
 */
/*
 * Find the largest values among the swing fields and among the pre-emphasis fields of a status record.
 * The swing fields are bytes 8..0xb of the record (see dp_tx_read_link_status), the pre-emphasis fields bytes
 * 0xc..0xf. For mode 4 all four of each group are compared, for mode 2 and 3 the first two, for mode 0 and 1
 * only the first.
 *   status: 16-byte record filled by dp_tx_read_link_status
 *   mode:   lane count (low 4 bits used)
 *   max_swing:        receives the largest of status[8..]
 *   max_pre_emphasis: receives the largest of status[0xc..]
 */
void dp_tx_get_max_adjust_request(unsigned char *status, int mode, unsigned char *max_swing, unsigned char *max_pre_emphasis)
{
    unsigned char swing = status[8];
    unsigned char pre_emphasis = status[0xc];
    mode &= 0xf;
    if (mode > 1) {
        if (swing < status[9])
            swing = status[9];
        if (pre_emphasis < status[0xd])
            pre_emphasis = status[0xd];
        if (mode == 4) {
            if (swing < status[0xa])
                swing = status[0xa];
            if (swing < status[0xb])
                swing = status[0xb];
            if (pre_emphasis < status[0xe])
                pre_emphasis = status[0xe];
            if (pre_emphasis < status[0xf])
                pre_emphasis = status[0xf];
        }
    }
    *max_swing = swing;
    *max_pre_emphasis = pre_emphasis;
}
