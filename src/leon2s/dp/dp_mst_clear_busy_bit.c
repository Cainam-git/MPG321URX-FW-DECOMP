/* dp_mst_clear_busy_bit  (FUN_a00d7ca4)
 *
 * Clear bit 7 of the port's control word at +0xC0.
 * Name basis: descriptive - port chosen by the byte at 0xA8078832
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d7ca4 @ 0xa00d7ca4 (-mcpu=v8 -Os -g)
 * The pointer is read into a local and used for the volatile read and the write (+0xc0).
 */
extern unsigned char dp_mst_message_state_port;
extern int dp_mst_ctl_reg_blocks[];
/*
 * Clear bit 7 of the word at byte offset 0xC0 of the control register block of the current port
 * (dp_mst_ctl_reg_blocks[dp_mst_message_state_port]).
 *
 * Called by dp_mst_handle_query_stream_enc_status after it has read its answer from the registers, and by
 * dp_mst_handle_remote_dpcd_write after it has written the data byte for DPCD address 0x160.
 */
void dp_mst_clear_busy_bit(void)
{
    int block;

    block = dp_mst_ctl_reg_blocks[(unsigned int)dp_mst_message_state_port];
    *(volatile unsigned int *)(block + 0xc0) = *(volatile unsigned int *)(block + 0xc0) & 0xffffff7f;
    return;
}
