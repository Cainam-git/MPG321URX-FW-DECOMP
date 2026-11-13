/* dp_mst_set_enable  (FUN_a00dc040)
 *
 * Store the MST service's enable byte and clear four state bytes when it is 0.
 * Name basis: descriptive - byte at 0xA807883A; bytes 0xA80787FC..FF
 *
 * Matching notes
 * --------------
 * FUN_a00dc040 (leon2s 0xa00dc040-0xa00dc078, 56 bytes, leaf), flags -mcpu=v8 -Os -g.
 * The four index bytes are separate symbols (each has its own sethi).
 */
extern unsigned char dp_mst_message_state_enable;
extern unsigned char dp_mst_message_state_fwd_write_index;
extern unsigned char dp_mst_message_state_fwd_read_index;
extern unsigned char dp_mst_message_state_up_write_index;
extern unsigned char dp_mst_message_state_up_read_index;
/*
 * Store the enable byte of the MST service. When it is 0, the read and write indexes of the forward ring and of
 * the up-request ring are cleared as well. Called by dp_tx_run_hpd_actions with 0 when the sink of output 0 is
 * unplugged and with 1 before the link of output 0 is trained.
 */
void dp_mst_set_enable(unsigned char enable)
{
    dp_mst_message_state_enable = enable;
    if (enable == 0) {
        dp_mst_message_state_fwd_write_index = 0;
        dp_mst_message_state_fwd_read_index = 0;
        dp_mst_message_state_up_write_index = 0;
        dp_mst_message_state_up_read_index = 0;
    }
}
