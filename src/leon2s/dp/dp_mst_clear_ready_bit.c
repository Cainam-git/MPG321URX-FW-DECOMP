/* dp_mst_clear_ready_bit  (FUN_a00da960)
 *
 * Set the pending flag when nothing was sent; on request clear the ready bit of the last record kind.
 * Note: The kind is that of the record before the up read index: kind 0 clears bit 4, else bit 5 of word
 *   0xCCC.
 * Name basis: descriptive - bit 4 or 5 of register word 0xCCC; kind byte at up read index - 1
 *
 * Matching notes
 * --------------
 * FUN_a00da960 (leon2s 0xa00da960-0xa00da9e8, 136 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: the kind byte is read into a local first (the firmware loads it before the flag store).
 */
extern unsigned char dp_mst_message_state_up_sent_flag;
extern unsigned char dp_mst_message_state_up_pending_flag;
extern unsigned char dp_mst_message_state_up_read_index;
extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_up_message_kinds[];
extern volatile unsigned int *dp_mst_ctl_reg_blocks[];
#define READY_BIT_KIND_0  0x10  /* ready bit of messages of kind 0 */
#define READY_BIT_KIND_1  0x20  /* ready bit of messages of kind 1 */

/*
 * Set dp_mst_message_state_up_pending_flag when dp_mst_message_state_up_sent_flag is clear. When `clear_bit` is
 * non-zero, also clear the ready bit of the kind of the up message record before the read index
 * (dp_mst_up_message_kinds[up read index - 1]): bit 4 for kind 0, bit 5 otherwise, in word 0x333 (byte 0xCCC)
 * of the control register block of the current port.
 *
 * Called by dp_mst_send_up_message_step with 0 when it drops a record, and by dp_mst_transmit_task with 1 when
 * an up message stays unanswered.
 */
void dp_mst_clear_ready_bit(unsigned char clear_bit)
{
    unsigned char kind = dp_mst_up_message_kinds[dp_mst_message_state_up_read_index - 1];

    if (dp_mst_message_state_up_sent_flag == 0)
        dp_mst_message_state_up_pending_flag = 1;
    if (clear_bit != 0) {
        if (kind == 0)
            dp_mst_ctl_reg_blocks[dp_mst_message_state_port][0x333] &= ~READY_BIT_KIND_0;
        else
            dp_mst_ctl_reg_blocks[dp_mst_message_state_port][0x333] &= ~READY_BIT_KIND_1;
    }
}
