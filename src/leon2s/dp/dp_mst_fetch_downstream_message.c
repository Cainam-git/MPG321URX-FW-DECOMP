/* dp_mst_fetch_downstream_message  (FUN_a00db784)
 *
 * Read a 48-byte message chunk from the output's DPCD 0x1400 or 0x1600 over AUX.
 * Name basis: proven - 0x1400 = down reply, 0x1600 = up request in the DisplayPort standard
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00db784 @ 0xa00db784-0xa00db9d4, -mcpu=v8 -Os -g.
 * Code linked 0xF10000 above its load address (func_0xa0f8.... calls, s_9f1c.... strings).
 * Same module as dp_mst_forward_down_request. The three reads of each branch are separate calls of
 * dp_tx_aux_request_copy (the same code as dp_tx_aux_request).
 */

#define OPTION_DOWN_REPLY_READY  0x10   /* bit 4 of the option byte: a down reply waits at the output */
#define OPTION_UP_REQUEST_READY  0x20   /* bit 5: an up request waits at the output */
#define KIND_DOWN_REPLY          0      /* value stored in dp_mst_up_message_kinds[] */
#define KIND_UP_REQUEST          1
#define AUX_CMD_READ             0x90
#define AUX_CMD_WRITE            0x80
#define DOWN_REPLY_ADDRESS       0x1400 /* DPCD addresses of the 48-byte message buffers of the output */
#define UP_REQUEST_ADDRESS       0x1600
#define ACK_ADDRESS              0x2003 /* the bit read above is written back here */
#define MST_REQUEST_ALLOCATE_PAYLOAD 0x11

extern unsigned char dp_mst_message_state_up_write_index;
extern unsigned char dp_mst_message_state_option_byte;
extern unsigned char dp_mst_up_message_kinds[];
/* Messages fetched from the output: 16 rows of 0x30 bytes (dp_mst_up_message_rows). */
extern unsigned char dp_mst_up_message_rows[][48];
extern int dbg_print_string(const char *);
extern unsigned char dp_tx_aux_request_copy(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);
extern unsigned char dp_tx_aux_request(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);
extern int dp_mst_update_payload_table(unsigned char, unsigned char, unsigned char);
extern void dp_mst_wait_downstream_ready(void);

/*
 * Read one 48-byte message that the output has ready and store it in the ring of fetched messages. Called by
 * dp_mst_downstream_task whenever bit 4 or 5 of the option byte is set; no parameters, no result.
 *
 * Bit 4 means a down reply is ready: the row at the up write index gets kind 0 and is read from DPCD 0x1400
 * in three AUX reads of 16 bytes. Bit 5 means an up request: kind 1, read from 0x1600. (When both bits are
 * set the down reply is taken first; with neither the routine returns.) If one of the three reads fails, a
 * line is printed and the routine returns at once with the bit still set, so the next call tries again.
 * (The three lines of the 0x1600 branch carry the same texts as the 0x1400 branch, "Read 0x1400h" and so on.)
 *
 * After the reads the bit is cleared in the option byte. When the low nibble of the first header byte is not 0
 * the write index steps on (modulo 16), so the message stays in the ring; with 0 the next fetch overwrites it.
 * The bit is then written to DPCD 0x2003 of the output (a failed write prints a line). Last, a message whose body
 * starts with request number 0x11 and whose bytes at body offsets 3 and 4 are both 0 removes the payload with
 * the id at body offset 2 (dp_mst_update_payload_table(id, 1, 0), then dp_mst_wait_downstream_ready).
 */
void dp_mst_fetch_downstream_message(void)
{
    unsigned char *row;
    unsigned char f;
    int v;
    unsigned char n;

    row = dp_mst_up_message_rows[dp_mst_message_state_up_write_index];
    f = 0;
    if (dp_mst_message_state_option_byte & OPTION_DOWN_REPLY_READY) {
        dp_mst_up_message_kinds[dp_mst_message_state_up_write_index] = KIND_DOWN_REPLY;
        if (!dp_tx_aux_request_copy(0, AUX_CMD_READ, DOWN_REPLY_ADDRESS, 0xf, row)) {
            dbg_print_string("Read 0x1400h --> FALSE!\r");
            return;
        }
        if (!dp_tx_aux_request_copy(0, AUX_CMD_READ, DOWN_REPLY_ADDRESS + 0x10, 0xf, row + 0x10)) {
            dbg_print_string("Read 0x1410h --> FALSE!\r");
            return;
        }
        if (!dp_tx_aux_request_copy(0, AUX_CMD_READ, DOWN_REPLY_ADDRESS + 0x20, 0xf, row + 0x20)) {
            dbg_print_string("Read 0x1420h --> FALSE!\r");
            return;
        }
        f |= OPTION_DOWN_REPLY_READY;
        dp_mst_message_state_option_byte &= ~OPTION_DOWN_REPLY_READY;
    } else if (dp_mst_message_state_option_byte & OPTION_UP_REQUEST_READY) {
        dp_mst_up_message_kinds[dp_mst_message_state_up_write_index] = KIND_UP_REQUEST;
        if (!dp_tx_aux_request_copy(0, AUX_CMD_READ, UP_REQUEST_ADDRESS, 0xf, row)) {
            dbg_print_string("Read 0x1400h --> FALSE!\r");
            return;
        }
        if (!dp_tx_aux_request_copy(0, AUX_CMD_READ, UP_REQUEST_ADDRESS + 0x10, 0xf, row + 0x10)) {
            dbg_print_string("Read 0x1410h --> FALSE!\r");
            return;
        }
        if (!dp_tx_aux_request_copy(0, AUX_CMD_READ, UP_REQUEST_ADDRESS + 0x20, 0xf, row + 0x20)) {
            dbg_print_string("Read 0x1420h --> FALSE!\r");
            return;
        }
        f |= OPTION_UP_REQUEST_READY;
        dp_mst_message_state_option_byte &= ~OPTION_UP_REQUEST_READY;
    } else
        return;
    v = (row[0] >> 4) - 1;
    n = v / 2;
    if (v & 1)
        n = v / 2 + 1;
    if (row[0] & 0xf)
        dp_mst_message_state_up_write_index = (dp_mst_message_state_up_write_index + 1) & 0xf;
    if (!dp_tx_aux_request(0, AUX_CMD_WRITE, ACK_ADDRESS, 0, &f))
        dbg_print_string("IRQHPDHandler : AUX_W Fail\r");
    if (row[n + 3] == MST_REQUEST_ALLOCATE_PAYLOAD && row[n + 6] == 0 && row[n + 7] == 0) {
        dp_mst_update_payload_table(row[n + 5], 1, 0);
        dp_mst_wait_downstream_ready();
    }
}
