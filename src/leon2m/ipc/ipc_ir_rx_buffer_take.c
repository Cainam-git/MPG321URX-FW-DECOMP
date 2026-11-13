/* ipc_ir_rx_buffer_take  (FUN_a01348a0)
 *
 * Take up to n bytes from the infrared message buffer and close the gap.
 * Returns: number of bytes taken
 * Name basis: derived - copies from the buffer that ipc_8051_decode_message fills from message type 5 ('IR'),
 *   then moves the rest down
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01348a0 @ 0xa01348a0-0xa013497c (55 words), flags -mcpu=v8 -O3 -g.
 * Source form: the counters are halfwords.
 */

extern unsigned short ipc_ir_rx_buffer_count;     /* bytes held in ipc_ir_rx_buffer */
extern unsigned char ipc_ir_rx_buffer[];

/*
 * Remove up to n bytes from the front of ipc_ir_rx_buffer, copy them to dst and move the bytes that remain to the
 * start of the buffer.
 *
 *   dst  destination for the bytes taken
 *   n    most bytes to take
 *
 * Returns the number taken: n, or the count held when that is smaller. Nothing calls it directly; it is
 * reached through a table. The only code that fills the buffer is ipc_8051_decode_message, which stores the
 * bytes of 8051 message type 5 (infrared pulse lengths) in it.
 */
unsigned short ipc_ir_rx_buffer_take(unsigned char *dst, unsigned short n)
{
    unsigned short taken = ipc_ir_rx_buffer_count;
    unsigned short i, j;

    if (n < taken)
        taken = n;
    for (i = 0; i < taken; i++)
        dst[i] = ipc_ir_rx_buffer[i];
    /* Close the gap: the bytes behind the ones taken move to the start. */
    for (i = taken, j = 0; i < ipc_ir_rx_buffer_count; i++, j++)
        ipc_ir_rx_buffer[j] = ipc_ir_rx_buffer[i];
    ipc_ir_rx_buffer_count -= taken;
    return taken;
}
