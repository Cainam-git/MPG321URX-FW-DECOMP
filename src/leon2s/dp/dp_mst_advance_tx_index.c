/* dp_mst_advance_tx_index  (FUN_a00da388)
 *
 * Step past the head message of the reply ring and clear its ready bit when asked.
 * Name basis: descriptive - bit 4 or 5 of register word 0xCCC
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00da388 @ 0xa00da388-0xa00da49c, -mcpu=v8 -Os -g.
 * dp_mst_ctl_reg_blocks[] holds register-block pointers (volatile, as in the other users of the table).
 * Source form: kind is an unsigned int (no and 0xff after the ldub); the wrap test is written '== 0' first.
 */
extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_reply_read_indexes[];
extern unsigned char dp_mst_reply_step_bytes[];
extern unsigned char dp_mst_reply_chunk_rows[][16];
extern unsigned short dp_mst_message_state_reply_offsets[];
extern unsigned char dp_mst_message_state_tx_states[];
extern unsigned char dp_mst_message_state_notify_action;
extern unsigned int dp_mst_notify_ticks;
extern volatile unsigned int *dp_mst_ctl_reg_blocks[];
extern unsigned int timer_get_ticks(void);
#define REG_READY_WORD    (0xccc / 4)
#define READY_BIT_KIND_0  0x10  /* ready bit of messages of kind 0 */
#define READY_BIT_KIND_1  0x20  /* ready bit of messages of kind 1 */

/*
 * Leave the message at the head of the reply ring of the current port.
 *   clear_ready: non-zero to clear the ready bit of the message kind (0 when a message is dropped before
 *                its first chunk, 1 when a sent chunk stays unanswered, as called from dp_mst_transmit_task)
 *
 * 1. When dp_mst_reply_step_bytes[port] is 0 (the message was sent completely and the read index has already
 *    moved on), the read index first steps back by one (0 wraps to 15), so that the entry used below is the one
 *    just sent.
 * 2. kind = dp_mst_reply_chunk_rows[port][read index]. When it is 1, dp_mst_message_state_notify_action is
 *    set to 1 and dp_mst_notify_ticks gets the present time.
 * 3. The position in the body ring moves on by dp_mst_reply_step_bytes[port] (modulo 0x200), the read index
 *    steps on by one (modulo 16) and the transmit state of the port becomes 0.
 * 4. With clear_ready set, bit 4 (kind 0) or bit 5 (kind not 0) of word 0xCCC of the control register block of
 *    the port is cleared.
 */
void dp_mst_advance_tx_index(unsigned char clear_ready)
{
    unsigned int kind;

    if (dp_mst_reply_step_bytes[dp_mst_message_state_port] == 0) {
        if (dp_mst_message_state_reply_read_indexes[dp_mst_message_state_port] == 0)
            dp_mst_message_state_reply_read_indexes[dp_mst_message_state_port] = 15;
        else
            dp_mst_message_state_reply_read_indexes[dp_mst_message_state_port] = dp_mst_message_state_reply_read_indexes[dp_mst_message_state_port] - 1;
    }
    kind = dp_mst_reply_chunk_rows[dp_mst_message_state_port][dp_mst_message_state_reply_read_indexes[dp_mst_message_state_port]];
    if (kind == 1) {
        dp_mst_message_state_notify_action = kind;
        dp_mst_notify_ticks = timer_get_ticks();
    }
    dp_mst_message_state_reply_offsets[dp_mst_message_state_port] = (dp_mst_message_state_reply_offsets[dp_mst_message_state_port] + dp_mst_reply_step_bytes[dp_mst_message_state_port]) & 0x1ff;
    dp_mst_message_state_reply_read_indexes[dp_mst_message_state_port] = (dp_mst_message_state_reply_read_indexes[dp_mst_message_state_port] + 1) & 0xf;
    dp_mst_message_state_tx_states[dp_mst_message_state_port] = 0;
    if (clear_ready) {
        if (kind == 0)
            dp_mst_ctl_reg_blocks[dp_mst_message_state_port][REG_READY_WORD] &= ~READY_BIT_KIND_0;
        else
            dp_mst_ctl_reg_blocks[dp_mst_message_state_port][REG_READY_WORD] &= ~READY_BIT_KIND_1;
    }
}
