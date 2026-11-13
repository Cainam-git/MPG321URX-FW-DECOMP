/* dp_mst_set_flag_6099  (FUN_a00dc034)
 *
 * Store the flag byte at 0xA8076099.
 * Name basis: descriptive - set from the output's hot-plug handling
 *
 * Matching notes
 * --------------
 * FUN_a00dc034 (leon2s 0xa00dc034-0xa00dc040, 12 bytes, leaf), flags -mcpu=v8 -Os -g.
 */
extern unsigned char dp_mst_notify_state;
/*
 * Store the state of the MST notification sequence (dp_mst_notify_state). dp_tx_run_hpd_actions passes 1 for
 * output 0 when the link was lost or the sink was unplugged, and 0 after the link was trained again.
 * dp_mst_notify_task reads the byte: 0 or 1 starts a notification step, after which the byte is 2.
 */
void dp_mst_set_flag_6099(unsigned char state)
{
    dp_mst_notify_state = state;
}
