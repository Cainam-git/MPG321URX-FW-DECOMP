/* dp_mst_count_pending_chunks  (FUN_a00dbf24)
 *
 * Add up the fill levels of the four chunk rings.
 * Name basis: descriptive - only for port 0; stored at 0xA807883E
 *
 * Matching notes
 * --------------
 * FUN_a00dbf24 (leon2s 0xa00dbf24-0xa00dc034, 272 bytes), flags -mcpu=v8 -Os -g.
 * Leaf. The port index is reloaded after the first store.
 */
extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_pending_chunks;
extern unsigned char dp_mst_message_state_rx_read_indexes[];
extern unsigned char dp_mst_message_state_rx_write_indexes[];
extern unsigned char dp_mst_message_state_reply_read_indexes[];
extern unsigned char dp_mst_message_state_reply_write_indexes[];
extern unsigned char dp_mst_message_state_up_read_index;
extern unsigned char dp_mst_message_state_up_write_index;
extern unsigned char dp_mst_message_state_fwd_read_index;
extern unsigned char dp_mst_message_state_fwd_write_index;
/* Add the entries held by one 16-entry ring to the sum: write index - read index, plus 0x10 when the read
 * index is the larger. */
static inline void add_used(unsigned char write_index, unsigned char read_index)
{
    if (write_index >= read_index)
        dp_mst_message_state_pending_chunks += write_index - read_index;
    else
        dp_mst_message_state_pending_chunks += write_index - read_index + 0x10;
}

/*
 * Count the entries waiting in the four rings of the MST service and store the sum in
 * dp_mst_message_state_pending_chunks: the receive ring and the reply ring of the current port, the forward
 * ring and the up-request ring. Only done while the current port is 0 (otherwise nothing changes).
 * Called by dp_mst_task; its result is the returned value.
 */
void dp_mst_count_pending_chunks(void)
{
    if (dp_mst_message_state_port == 0) {
        dp_mst_message_state_pending_chunks = 0;
        add_used(dp_mst_message_state_rx_write_indexes[dp_mst_message_state_port], dp_mst_message_state_rx_read_indexes[dp_mst_message_state_port]);
        add_used(dp_mst_message_state_reply_write_indexes[dp_mst_message_state_port], dp_mst_message_state_reply_read_indexes[dp_mst_message_state_port]);
        add_used(dp_mst_message_state_fwd_write_index, dp_mst_message_state_fwd_read_index);
        add_used(dp_mst_message_state_up_write_index, dp_mst_message_state_up_read_index);
    }
}
