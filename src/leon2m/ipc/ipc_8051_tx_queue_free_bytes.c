/* ipc_8051_tx_queue_free_bytes  (FUN_a0132bfc)
 *
 * Return the free room of the outgoing queue in bytes.
 * Returns: free bytes
 * Name basis: derived - from the read and write index of the ring, 16 bytes per entry; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0132bfc @ 0xa0132bfc-0xa0132c54 (22 words), flags -mcpu=v8 -O3 -g. A leaf routine without a
 * register window.
 */
extern unsigned char ipc_8051_tx_queue_read_index, ipc_8051_tx_queue_write_index;

/*
 * Return the free room of the queue of messages to the 8051, in bytes of message data.
 * The queue is a ring of entries of 20 bytes with indexes 0..0x24 (see uart_send_bytes); each entry carries up to
 * 16 data bytes. The free entry count is 0x24 when write and read index are equal and one less than the gap
 * otherwise (one entry always stays unused); the result is that count times 16.
 * Nothing calls this routine.
 */
unsigned short ipc_8051_tx_queue_free_bytes(void)
{
    unsigned char write_index = ipc_8051_tx_queue_write_index, read_index = ipc_8051_tx_queue_read_index;
    unsigned short free_entries = 0x24;

    if (write_index > read_index)
        free_entries = read_index - write_index + 0x24;
    else if (write_index < read_index)
        free_entries = read_index - write_index - 1;
    return free_entries << 4;
}
