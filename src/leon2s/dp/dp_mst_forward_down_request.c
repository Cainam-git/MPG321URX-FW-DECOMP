/* dp_mst_forward_down_request  (FUN_a00db53c)
 *
 * Send a stored down request on to the output over AUX, with payload handling.
 * Name basis: derived - 16-byte blocks through dp_tx_aux_request; special handling of requests 0x11 and 0x14
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00db53c @ 0xa00db53c-0xa00db784, -mcpu=v8 -Os -g.
 * Code linked 0xF10000 above its load address (func_0xa0f8.... calls, s_9f1c.... strings).
 * Source forms: the payload size is an unsigned short local (the firmware masks it again at each use);
 * dp_mst_update_payload_table is declared with an int result (argument set-up order).
 */

#define MST_REQUEST_ALLOCATE_PAYLOAD    0x11
#define MST_REQUEST_CLEAR_PAYLOAD_TABLE 0x14
#define AUX_CMD_WRITE                   0x80
#define DOWN_REQUEST_ADDRESS            0x1000  /* DPCD address of the output the request is written to */
#define BLOCK_BYTES                     16

extern unsigned char dp_mst_message_state_fwd_read_index;
extern unsigned char dp_mst_message_state_fwd_queued_flag;
extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_forward_messages[];
/* Forward rows: header + body of each stored down request, 16 rows of 0x30 bytes (dp_mst_forward_rows). */
extern unsigned char dp_mst_forward_rows[][48];
extern int dbg_printf(const char *, ...);
extern unsigned char dp_tx_aux_request(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);
extern int dp_mst_update_payload_table(unsigned char, unsigned char, unsigned char);
extern void dp_mst_wait_downstream_ready(void);

#define R(a) (*(volatile unsigned int *)(a))

/*
 * Send the stored down request at the forward read index on to the output over AUX, after the payload
 * handling that some requests need. Called by dp_mst_forward_task when the forward ring is not empty; no
 * parameters, no result.
 *
 * The row is the packed message (header addr_bytes + 3 bytes long, then the body; the first body byte is the
 * request number); dp_mst_forward_messages[index] is its total length.
 *  - Request 0x11 (ALLOCATE_PAYLOAD): when the two bytes at body offsets 3 and 4 are not both 0, the payload table
 *    is updated first for the payload id at body offset 2 (dp_mst_update_payload_table(id, 0, 0), then
 *    dp_mst_wait_downstream_ready); two lines are printed around it.
 *  - Request 0x14 (CLEAR_PAYLOAD_ID_TABLE): the table is cleared (dp_mst_update_payload_table(0, 1, 1)). When the
 *    forward queued flag is 1 (set by dp_mst_queue_clear_payload_table_request) the low bytes of the registers 0xCF013000
 *    and 0xCF0189E0 are saved, bit 7 of the first and bit 0 of the second are set around
 *    dp_mst_wait_downstream_ready, then both are restored and the flag is cleared.
 *  - The row is then written to the output in blocks of 16 bytes at DPCD 0x1000 + 16 * block (AUX write; the last
 *    block is shorter). A failed block prints a line with the port; the remaining blocks are still written.
 * At the end the forward read index steps on (modulo 16).
 */
void dp_mst_forward_down_request(void)
{
    unsigned char *row;
    int v;
    unsigned char n, j, ok;
    unsigned char len;
    unsigned short size;
    unsigned char s1, s2;

    size = 0;
    s1 = 0;
    s2 = 0;
    row = dp_mst_forward_rows[dp_mst_message_state_fwd_read_index & 0xf];
    v = (row[0] >> 4) - 1;
    n = v / 2;
    len = dp_mst_forward_messages[dp_mst_message_state_fwd_read_index];
    if (v & 1)
        n = v / 2 + 1;
    if (row[n + 3] == MST_REQUEST_ALLOCATE_PAYLOAD) {
        if (row[n + 6] == 0 && row[n + 7] == 0)
            ok = 1;
        else {
            size = row[n + 5];
            ok = 0;
        }
        if (!ok) {
            dbg_printf("AllocatePLDIDTable : %d, %d\r\n", size, 0);
            dp_mst_update_payload_table(size, 0, 0);
            dp_mst_wait_downstream_ready();
            dbg_printf("\033[1;33mTrigger %s to other REQ\r\n\033[m", "ACT");
        }
    } else if (row[n + 3] == MST_REQUEST_CLEAR_PAYLOAD_TABLE) {
        dp_mst_update_payload_table(0, 1, 1);
        if (dp_mst_message_state_fwd_queued_flag == 1) {
            s1 = R(0xcf013000);
            s2 = R(0xcf0189e0);
            R(0xcf013000) |= 0x80;
            R(0xcf0189e0) |= 1;
        }
        dp_mst_wait_downstream_ready();
        if (dp_mst_message_state_fwd_queued_flag == 1) {
            R(0xcf013000) = s1;
            R(0xcf0189e0) = s2;
            dp_mst_message_state_fwd_queued_flag = 0;
        }
    }
    for (j = 0; (j << 4) < len; j++) {
        if ((j << 4) + BLOCK_BYTES > len) {
            if (!dp_tx_aux_request(0, AUX_CMD_WRITE, DOWN_REQUEST_ADDRESS + (j << 4), (signed char)(len - (j << 4) - 1), row + (j << 4)))
                dbg_printf("OtherReqBuf_Update FAIL(%d)\r\n", dp_mst_message_state_port);
        } else {
            if (!dp_tx_aux_request(0, AUX_CMD_WRITE, DOWN_REQUEST_ADDRESS + (j << 4), BLOCK_BYTES - 1, row + (j << 4)))
                dbg_printf("OtherReqBuf_Update FAIL(%d)\r\n", dp_mst_message_state_port);
        }
    }
    dp_mst_message_state_fwd_read_index = (dp_mst_message_state_fwd_read_index + 1) & 0xf;
}
