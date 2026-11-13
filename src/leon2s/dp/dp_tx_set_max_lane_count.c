/* dp_tx_set_max_lane_count  (FUN_a0085888)
 *
 * Store the maximum lane count (1, 2 or 4) of a DP output.
 *   port
 *   mode: lane choice
 * Name basis: derived - maps 0/1/other to 1/2/4 next to the rate byte; caller ipc_dispatch_command
 *
 * Matching notes
 * --------------
 * FUN_a0085888 (leon2s 0xa0085888-0xa00858cc, 68 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: both byte arrays are volatile (see dp_tx_set_max_link_rate). GCC merges the two stores into
 * one store through a selected address.
 */
extern volatile unsigned char dp_tx_limits_others[];     /* see dp_tx_set_max_link_rate for the layout */
extern volatile unsigned char dp_tx_limits_port0[];

/*
 * Store the maximum lane count of an output: mode 0 gives 1, mode 1 gives 2, any other mode gives 4. It goes
 * to byte 1 of the pair of output 0, or of the pair of the other outputs.
 *   port: output (0 or other)
 *   mode: lane choice
 * Called by ipc_dispatch_command.
 */
void dp_tx_set_max_lane_count(unsigned char port, unsigned char mode)
{
    unsigned char lanes;
    switch (mode) {
    case 0: lanes = 1; break;
    case 1: lanes = 2; break;
    default: lanes = 4; break;
    }
    if (port == 0)
        dp_tx_limits_port0[1] = lanes;
    else
        dp_tx_limits_others[1] = lanes;
}
