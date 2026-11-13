/* dp_mst_set_reply_ready  (FUN_a00d7bf8)
 *
 * Write bit 3 of control word 0xF7 while it still reads as set, then set bit 7 of word 0x30.
 * Note: At most 1000 writes of bit 3.
 * Name basis: descriptive - bit 3 of register word 0xF7 (written again while it reads 1), then bit 7 of word
 *   0x30
 *
 * Matching notes
 * --------------
 * FUN_a00d7bf8 (leon2s 0xa00d7bf8-0xa00d7ca4, 172 bytes, leaf), flags -mcpu=v8 -Os -g.
 * The register block is re-read through the table and the port index at every access (the firmware reloads
 * both each time).
 * Source form: one for loop whose condition tests the bit before the counter.
 */
extern unsigned char dp_mst_message_state_port;
extern volatile unsigned int *dp_mst_ctl_reg_blocks[];
/*
 * Work on word 0xF7 and word 0x30 of the control register block of the current port
 * (dp_mst_ctl_reg_blocks[dp_mst_message_state_port]).
 *
 * While bit 3 of word 0xF7 reads as set, the bit is written again (read-modify-write); this is repeated at
 * most 1000 times. Then bit 7 of word 0x30 is set.
 *
 * Called by dp_mst_handle_query_stream_enc_status and dp_mst_handle_remote_dpcd_write before the reply is
 * filled in.
 */
void dp_mst_set_reply_ready(void)
{
    unsigned short tries;

    for (tries = 0; (dp_mst_ctl_reg_blocks[dp_mst_message_state_port][0xf7] & 8) && tries < 1000; tries++)
        dp_mst_ctl_reg_blocks[dp_mst_message_state_port][0xf7] |= 8;
    dp_mst_ctl_reg_blocks[dp_mst_message_state_port][0x30] |= 0x80;
}
