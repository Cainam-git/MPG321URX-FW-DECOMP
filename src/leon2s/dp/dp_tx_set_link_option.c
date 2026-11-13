/* dp_tx_set_link_option  (FUN_a00858cc)
 *
 * Store the link option byte of a DP output.
 *   port
 *   option: value
 * Name basis: descriptive - byte after the rate and lane-count limits, passed to the rate set-up by
 *   dp_tx_set_link_rate; caller ipc_dispatch_command
 *
 * Matching notes
 * --------------
 * FUN_a00858cc (leon2s 0xa00858cc-0xa00858f0, 36 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: dp_tx_link_option_port0 is volatile, as in dp_tx_set_link_rate and dp_tx_handle_test_request: in every
 * function that accesses it the firmware keeps the access out of the branch delay slot, which GCC does only
 * for volatile objects. dp_tx_link_option_others is accessed normally.
 */
extern volatile unsigned char dp_tx_link_option_port0;
extern unsigned char dp_tx_link_option_others;

/*
 * Store the link option byte of an output: output 0 has its own byte, all other outputs share one.
 * dp_tx_set_link_rate passes it to dp_tx_phy_set_link_rate.
 *   port:   output
 *   option: value to store
 * Called by ipc_dispatch_command.
 */
void dp_tx_set_link_option(unsigned char port, unsigned char option)
{
    if (port == 0)
        dp_tx_link_option_port0 = option;
    else
        dp_tx_link_option_others = option;
}
