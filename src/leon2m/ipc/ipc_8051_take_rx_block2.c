/* ipc_8051_take_rx_block2  (FUN_a0132b8c)
 *
 * Copy the second block received from the 8051 to the caller's buffer when its ready flag is set.
 * Returns: 1 when a block was copied
 * Note: Clears the ready flag; no routine calls it (ipc_8051_request_and_wait carries an inlined copy).
 * Name basis: derived - ipc_8051_rx_block2_ready_flag (0xA802CB93) and ipc_8051_rx_block2_length (0xA802CB92);
 *   same code inline in ipc_8051_request_and_wait
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0132b8c @ 0xa0132b8c-0xa0132bfc (28 words), flags -mcpu=v8 -O3 -g.
 * Source form: the length byte is read again on every step of the copy; the result is returned as (r & 1).
 */
extern unsigned char ipc_8051_rx_block2_ready_flag, ipc_8051_rx_block2_length;
extern unsigned char ipc_8051_rx_block_buffer[];

/*
 * Copy the I2C answer block the 8051 sent (message type 2, filled by ipc_8051_decode_message) to dst, when its
 * ready flag is 1: the first ipc_8051_rx_block2_length bytes of ipc_8051_rx_block_buffer. The ready flag is
 * cleared.
 *
 *   dst  receives the bytes
 *
 * Returns 1 when a block was copied, 0 when none was waiting. ipc_8051_request_and_wait carries an inlined copy
 * of this one; nothing calls it.
 */
unsigned char ipc_8051_take_rx_block2(unsigned char *dst)
{
    unsigned char taken = 0;
    unsigned char i;

    if (ipc_8051_rx_block2_ready_flag == 1) {
        for (i = 0; i < ipc_8051_rx_block2_length; i++)
            dst[i] = ipc_8051_rx_block_buffer[i];
        ipc_8051_rx_block2_ready_flag = 0;
        taken = 1;
    }
    return taken & 1;
}
