/* dp_mst_send_down_reply_step  (FUN_a00da49c)
 *
 * Send the next chunk of a down reply and raise the ready bit.
 * Name basis: derived - header and body writes, then ready bit 4 or 5 of control word 0xCCC
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00da49c @ 0xa00da49c-0xa00da6ac, -mcpu=v8 -Os -g.
 * Source form: the port, the arrays and the tables are written out at every use (the firmware reloads
 * dp_mst_message_state_port after each call); the order of the four stores in each counter-step arm
 * (reply_step_bytes, reply flag, read index, tx state) is the firmware's.
 */

/* Chunk limits and states. */
#define CHUNK_BODY_FIRST      0x2a      /* largest body written per chunk here (set at the start of a message) */
#define CHUNK_LENGTH_FULL     0x2b      /* length byte of a full chunk: body + checksum */
#define TX_STATE_IDLE         0
#define TX_STATE_DOWN_REPLY   2         /* more chunks of the down reply follow */
#define REG_READY_WORD        (0xccc / 4)
#define READY_BIT_KIND_0      0x10      /* ready bit of messages of kind 0 */
#define READY_BIT_KIND_1      0x20      /* ready bit of messages of kind 1 */

extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_reply_read_indexes[];
extern unsigned char dp_mst_port_reply_flags[];
extern unsigned char dp_mst_reply_chunk_rows[][16];
extern unsigned char dp_mst_reply_headers[][16];
extern unsigned char dp_mst_reply_step_bytes[];
extern unsigned char dp_mst_message_state_tx_states[];
extern unsigned char dp_mst_message_state_max_body_bytes;
extern volatile unsigned int *dp_mst_ctl_reg_blocks[];
extern unsigned char dp_mst_is_reply_unmatched(void);
extern void dp_mst_advance_tx_index(unsigned char);
extern void dp_mst_write_chunk_header(unsigned char, unsigned char, unsigned char);
extern void dp_mst_write_chunk_body(unsigned char);
extern void dp_set_reg30_bit6(unsigned char);

/*
 * Send the next chunk of the down reply at the head of the current port's reply ring: write its header and
 * body into the port's registers and raise the ready bit. Called by dp_mst_transmit_task. Returns 1 when a chunk
 * was written and signalled, 0 when the message was dropped (nothing is written then).
 *
 * Per-port state it uses: the read index of the reply ring; dp_mst_reply_headers[port][index] = body length of
 * the message; dp_mst_reply_chunk_rows[port][index] = kind of the message (0 or 1, chooses the message area
 * and the ready bit); dp_mst_reply_step_bytes[port] = body bytes still to send; dp_mst_port_reply_flags[port]
 * = 1 before the first chunk of a message, 0 while later chunks follow.
 *
 * First chunk (flag 1): the chunk body size is set to 0x2a. When dp_mst_is_reply_unmatched reports non-zero the
 * message is dropped (dp_mst_advance_tx_index with 0) and 0 is returned. A body longer than 0x2a goes out
 * as a first chunk of 0x2a bytes (start flag, no end flag), the transmit state becomes 2 and the flag 0; a body of
 * up to 0x2a goes out as one chunk with start and end flag, and the read index steps on and the state returns
 * to 0. Later chunks (flag 0): a rest smaller than the chunk size goes out as the last chunk (end flag, the read
 * index steps on, flag 1); otherwise a middle chunk of the chunk size goes out. The chunk length byte of the
 * header is the body bytes + 1 (the checksum that dp_mst_write_chunk_body adds).
 *
 * At the end the ready bit (bit 4 for kind 0, bit 5 for kind 1 of word 0xccc of the control block) is set and
 * dp_set_reg30_bit6 is called for the port.
 */
int dp_mst_send_down_reply_step(void)
{
    unsigned char flag, x, v;

    x = dp_mst_reply_chunk_rows[dp_mst_message_state_port][dp_mst_message_state_reply_read_indexes[dp_mst_message_state_port]];
    flag = dp_mst_port_reply_flags[dp_mst_message_state_port];
    if (flag == 1) {
        v = dp_mst_reply_headers[dp_mst_message_state_port][dp_mst_message_state_reply_read_indexes[dp_mst_message_state_port]];
        dp_mst_message_state_max_body_bytes = CHUNK_BODY_FIRST;
        dp_mst_reply_step_bytes[dp_mst_message_state_port] = v;
        if (dp_mst_is_reply_unmatched()) {
            dp_mst_advance_tx_index(0);
            return 0;
        }
        if (v > CHUNK_BODY_FIRST) {
            dp_mst_write_chunk_header(1, 0, CHUNK_LENGTH_FULL);
            dp_mst_write_chunk_body(dp_mst_reply_step_bytes[dp_mst_message_state_port]);
            dp_mst_message_state_tx_states[dp_mst_message_state_port] = TX_STATE_DOWN_REPLY;
            dp_mst_reply_step_bytes[dp_mst_message_state_port] -= dp_mst_message_state_max_body_bytes;
            dp_mst_port_reply_flags[dp_mst_message_state_port] = 0;
        } else {
            dp_mst_write_chunk_header(1, 1, v + 1);
            dp_mst_write_chunk_body(dp_mst_reply_step_bytes[dp_mst_message_state_port]);
            dp_mst_reply_step_bytes[dp_mst_message_state_port] = 0;
            dp_mst_port_reply_flags[dp_mst_message_state_port] = flag;
            dp_mst_message_state_reply_read_indexes[dp_mst_message_state_port] = (dp_mst_message_state_reply_read_indexes[dp_mst_message_state_port] + 1) & 0xf;
            dp_mst_message_state_tx_states[dp_mst_message_state_port] = TX_STATE_IDLE;
        }
    } else if (dp_mst_reply_step_bytes[dp_mst_message_state_port] < dp_mst_message_state_max_body_bytes) {
        /* last chunk of a long message */
        dp_mst_write_chunk_header(0, 1, dp_mst_reply_step_bytes[dp_mst_message_state_port] + 1);
        dp_mst_write_chunk_body(dp_mst_reply_step_bytes[dp_mst_message_state_port]);
        dp_mst_reply_step_bytes[dp_mst_message_state_port] = 0;
        dp_mst_port_reply_flags[dp_mst_message_state_port] = 1;
        dp_mst_message_state_reply_read_indexes[dp_mst_message_state_port] = (dp_mst_message_state_reply_read_indexes[dp_mst_message_state_port] + 1) & 0xf;
        dp_mst_message_state_tx_states[dp_mst_message_state_port] = TX_STATE_IDLE;
    } else {
        /* middle chunk */
        dp_mst_write_chunk_header(0, 0, dp_mst_message_state_max_body_bytes + 1);
        dp_mst_write_chunk_body(dp_mst_reply_step_bytes[dp_mst_message_state_port]);
        dp_mst_reply_step_bytes[dp_mst_message_state_port] -= dp_mst_message_state_max_body_bytes;
    }
    if (x == 0)
        dp_mst_ctl_reg_blocks[dp_mst_message_state_port][REG_READY_WORD] |= READY_BIT_KIND_0;
    else
        dp_mst_ctl_reg_blocks[dp_mst_message_state_port][REG_READY_WORD] |= READY_BIT_KIND_1;
    dp_set_reg30_bit6(dp_mst_message_state_port);
    return 1;
}
