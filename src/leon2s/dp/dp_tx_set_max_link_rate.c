/* dp_tx_set_max_link_rate  (FUN_a0085830)
 *
 * Store the maximum link rate code (RBR/HBR/HBR2/HBR3) of a DP output.
 *   port
 *   mode: rate choice
 * Name basis: derived - maps 0/1/3/other to 0x06/0x0A/0x1E/0x14 (DisplayPort rate codes); limit read by
 *   dp_tx_choose_link_config
 *
 * Matching notes
 * --------------
 * FUN_a0085830 (leon2s 0xa0085830-0xa0085888, 88 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: both byte arrays are volatile, as in dp_tx_set_max_lane_count and dp_tx_set_link_option: the
 * firmware keeps every access to them out of branch delay slots, which GCC does only for volatile objects.
 */
/*
 * The limits of each output are two bytes: the link rate code first, the lane count second. The pair of
 * output 0 is at dp_tx_limits_port0 (0xa807cd68), the pair shared by all other outputs at
 * dp_tx_limits_others (0xa807cd00); the two labels name the second byte of each pair, not the array.
 */
extern volatile unsigned char dp_tx_limits_others[];
extern volatile unsigned char dp_tx_limits_port0[];

/*
 * Store the maximum link rate code of an output. Mode 0 gives 0x06, mode 1 gives 0x0a, mode 3 gives 0x1e and
 * any other mode gives 0x14. The code goes to byte 0 of the pair of output 0, or of the pair of the other
 * outputs. dp_tx_choose_link_config reads the limit.
 *   port: output (0 or other)
 *   mode: rate choice
 */
void dp_tx_set_max_link_rate(unsigned char port, unsigned char mode)
{
    unsigned char rate_code;
    switch (mode) {
    case 0: rate_code = 6; break;
    case 1: rate_code = 0xa; break;
    case 3: rate_code = 0x1e; break;
    default: rate_code = 0x14; break;
    }
    if (port == 0)
        dp_tx_limits_port0[0] = rate_code;
    else
        dp_tx_limits_others[0] = rate_code;
}
