/* ipc_8051_read_port_memory  (FUN_a013562c)
 *
 * Ask the 8051 for a block of a port's memory and wait for the bytes.
 * Name basis: derived - 8051 command 0x0D, then flush and poll until the data has arrived; used by the EDID
 *   read
 *
 * Matching notes
 * --------------
 * FUN_a013562c, flags -mcpu=v8 -O3 -g. Source form: the divisor 16 is held in a local (the firmware divides with
 * sdiv by the immediate 16). The helper ipc_8051_take_rx_block, a separate function in the original image
 * (ipc_8051_take_rx_block), is inlined here as a static function.
 */
extern unsigned char ipc_8051_rx_block_ready_flag, ipc_8051_rx_block_length;
extern unsigned char ipc_8051_rx_block_buffer[];
extern void ipc_send_8051_command(unsigned char cmd, unsigned char arg1, unsigned char arg2, unsigned char arg3, unsigned char mode);
extern void ipc_8051_tx_queue_flush(void);
extern void ipc_8051_poll_messages(void);

#define IPC_8051_CMD_READ_EDID_RAM  0x0d
#define IPC_SEND_NO_WAIT            0   /* send and return at once */
#define EDID_RAM_ROW_BYTES          16  /* the 8051 takes the offset in rows of 16 bytes */

/*
 * If the 8051 has delivered a block of read-back bytes (ready flag set), copy it to dst, clear the flag and return 1;
 * otherwise return 0. The block is filled by ipc_8051_decode_message.
 */
static unsigned char ipc_8051_take_rx_block(unsigned char *dst)
{
    unsigned char taken = 0;
    unsigned char i;

    if (ipc_8051_rx_block_ready_flag == 1) {
        for (i = 0; i < ipc_8051_rx_block_length; i++)
            dst[i] = ipc_8051_rx_block_buffer[i];
        ipc_8051_rx_block_ready_flag = 0;
        taken = 1;
    }
    return taken & 1;
}

/*
 * Read bytes of the 8051's EDID RAM. Command 0x0D asks the 8051 to send the bytes back as a message; this routine
 * then flushes the outgoing queue and polls the incoming slots until the block has arrived, with no time limit.
 * Callers: edid_read_port_edid and edid_write_port_edid.
 *   offset: byte offset in the EDID RAM, sent as offset / 16 (byte 2)
 *   count:  number of bytes, byte 3
 *   dst:    buffer that receives the block
 */
void ipc_8051_read_port_memory(unsigned short offset, unsigned char count, unsigned char *dst)
{
    int row_bytes = EDID_RAM_ROW_BYTES;

    ipc_send_8051_command(IPC_8051_CMD_READ_EDID_RAM, 0, offset / row_bytes, count, IPC_SEND_NO_WAIT);
    while (!ipc_8051_take_rx_block(dst)) {
        ipc_8051_tx_queue_flush();
        ipc_8051_poll_messages();
    }
}
