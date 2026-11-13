/* dp_mst_send_up_message_step  (FUN_a00daa98)
 *
 * Send the next message fetched from the output (down reply or up request) on to the source.
 * Returns: 1, or 0 when a first chunk was dropped
 * Note: Record kind 0 (read from DPCD 0x1400) raises ready bit 4, kind 1 (0x1600) bit 5 of control word 0xCCC.
 * Name basis: derived - row at the up read index is written to the port's registers; the kind byte chooses
 *   ready bit 4 or 5; dp_mst_fetch_downstream_message stores kind 0 for DPCD 0x1400 and 1 for 0x1600
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00daa98 @ 0xa00daa98-0xa00dabf8, -mcpu=v8 -Os -g.
 * Source form: the record pointer is taken into a local before the kind is read; dp_mst_is_record_changed is
 * tested through (unsigned char).
 */

#define UP_FLAG_START         0x80      /* flag byte of the unpacked header: first chunk of a message */
#define UP_FLAG_END           0x40      /* ... last chunk of a message */
#define TX_STATE_IDLE         0
#define TX_STATE_UP_MESSAGE   4         /* more chunks of the record sequence follow */
#define REG_READY_WORD        (0xccc / 4)
#define READY_BIT_KIND_0      0x10      /* ready bit of records of kind 0 */
#define READY_BIT_KIND_1      0x20      /* ready bit of records of kind 1 */

/* The unpacked header (dp_mst_unpack_header, 24 bytes): byte +0x12 holds the flag bits. */
struct hdr { unsigned int w[4]; unsigned int hi : 16; unsigned int flags : 8; unsigned int b3 : 8; unsigned int w5; };
union buf { struct hdr h; unsigned char b[24]; };

extern unsigned char dp_mst_message_state_up_read_index;
extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_up_sent_flag;
extern unsigned char dp_mst_message_state_up_pending_flag;
extern unsigned char dp_mst_message_state_tx_states[];
extern unsigned char dp_mst_up_message_kinds[];
/* Messages fetched from the output: 16 rows of 0x30 bytes (dp_mst_up_message_rows). */
extern unsigned char dp_mst_up_message_rows[][0x30];
extern volatile unsigned int *dp_mst_ctl_reg_blocks[];
extern void dp_mst_unpack_header(unsigned char *, unsigned char *);
extern int dp_mst_is_record_changed(void);
extern void dp_mst_trim_up_message_record(void);
extern void dp_mst_write_record_tail(void);
extern void dp_mst_clear_ready_bit(unsigned char);
extern void dp_set_reg30_bit6(unsigned char);

/*
 * Send the next stored message from the output (the ring filled by dp_mst_fetch_downstream_message) towards the
 * source: write it into the current port's registers and raise the ready bit. Called by dp_mst_transmit_task.
 * Returns 1 normally, 0 when the message was a first chunk that was dropped.
 *
 * The record is the row at the up read index; dp_mst_up_message_kinds[index] is its kind (0 = read from DPCD
 * 0x1400, 1 = read from 0x1600) and chooses the ready bit (bit 4 for kind 0, bit 5 for kind 1 of word 0xccc of
 * the control block). The record is written only when the pending flag is clear and the record is not dropped.
 * It is dropped (drop = 1) when its header has the start flag and dp_mst_is_record_changed() is non-zero; then
 * dp_mst_clear_ready_bit(0) is called at the end, which sets the pending flag, so that the records that follow
 * are not written either. Writing a record means: dp_mst_trim_up_message_record (header, count lowered by
 * one), dp_mst_write_record_tail (rest of the record), the ready bit and dp_set_reg30_bit6.
 * A record with the end flag sets the "up sent" flag, clears the pending flag and returns the transmit state to 0;
 * any other record leaves the state at 4 (dp_mst_transmit_task then calls this routine again). Each call
 * consumes one record: the up read index steps on (modulo 16).
 */
int dp_mst_send_up_message_step(void)
{
    union buf buf;
    unsigned char *record;
    unsigned char kind, drop;

    record = dp_mst_up_message_rows[dp_mst_message_state_up_read_index & 0xf];
    kind = dp_mst_up_message_kinds[dp_mst_message_state_up_read_index];
    dp_mst_message_state_up_sent_flag = 0;
    dp_mst_unpack_header(buf.b, record);
    drop = 0;
    if ((buf.h.flags & UP_FLAG_START) && (unsigned char)dp_mst_is_record_changed() != 0)
        drop = 1;
    if (dp_mst_message_state_up_pending_flag == 0 && drop == 0) {
        dp_mst_trim_up_message_record();
        dp_mst_write_record_tail();
        if (kind == 0)
            dp_mst_ctl_reg_blocks[dp_mst_message_state_port][REG_READY_WORD] |= READY_BIT_KIND_0;
        else
            dp_mst_ctl_reg_blocks[dp_mst_message_state_port][REG_READY_WORD] |= READY_BIT_KIND_1;
        dp_set_reg30_bit6(dp_mst_message_state_port);
    }
    if (buf.h.flags & UP_FLAG_END) {
        dp_mst_message_state_tx_states[dp_mst_message_state_port] = TX_STATE_IDLE;
        dp_mst_message_state_up_sent_flag = 1;
        dp_mst_message_state_up_pending_flag = 0;
    } else {
        dp_mst_message_state_tx_states[dp_mst_message_state_port] = TX_STATE_UP_MESSAGE;
    }
    dp_mst_message_state_up_read_index = (dp_mst_message_state_up_read_index + 1) & 0xf;
    if (drop) {
        dp_mst_clear_ready_bit(0);
        return 0;
    }
    return 1;
}
