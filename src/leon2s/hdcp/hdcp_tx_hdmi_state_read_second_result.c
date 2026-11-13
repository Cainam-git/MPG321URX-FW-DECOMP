/* hdcp_tx_hdmi_state_read_second_result  (FUN_a00cc5f8)
 *
 * State handler: read 32 bytes of the engine into the second buffer and compare.
 * Name basis: descriptive - one state handler of the per-output copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_hdmi_run_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cc5f8 @ 0xa00cc5f8-0xa00cc834, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the status bytes are a plain byte array; the high byte is copied into a local and the length joined with +
 *    as an unsigned short;
 *  - the engine register read is declared int-returning and stored through (u8);
 *  - the compare loop sets the result and leaves with break; bit 21 is set after the loop on every path that
 *    gets that far.
 */

/* Protection record of an output (24 bytes, docs/DATA.md; the fields used here). */
struct hdcp_tx_record {
    unsigned int bits_29_31 : 3;
    unsigned int repeater : 1;          /* bit 28 */
    unsigned int tries_left : 4;        /* bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int bit22 : 1;
    unsigned int bit21 : 1;
    unsigned int bits_18_20 : 3;
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, read by hdcp_tx_select_next_state */
    unsigned char state;                /* +2 */
    unsigned char device_count;         /* +3 */
    unsigned char level;                /* +4 */
    unsigned char count_overflow;       /* +5 */
    unsigned char level_overflow;       /* +6 */
    unsigned char byte_0x7;
    unsigned char byte_0x8;
    unsigned char engine_unit;          /* +9 */
    unsigned char pad_0xa[6];
    unsigned int word_0x10;             /* 24-bit counter, see hdcp_tx_hdmi_state_send_stream_manage */
    unsigned char pad_0x14[4];
};

/* Result of a state handler. hdcp_tx_select_next_state picks the next state from it; for this state (0x4D):
   STEP_NEXT -> 0x4E, STEP_OTHER -> 0x4C, STEP_BACK -> 0x40, STEP_AGAIN -> state kept. */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};

/* The two RXSTATUS bytes in hdcp_tx_status_bytes. */
#define STATUS_LENGTH_LO    0           /* message length, bits 0..7 */
#define STATUS_HI           1           /* bits 0..1: message length bits 8..9 */
#define RXSTATUS_LENGTH_HI  3
#define RXSTATUS_BITS_2_3   0xc         /* either bit set: STEP_BACK */

#define HDCP_DDC_DEVICE     0x74        /* device address used for all handshake reads and writes */
#define DDC_MESSAGE         0x80        /* offset the message is read from */
#define MESSAGE_LENGTH      0x21        /* byte 0 and the 32 bytes used */
#define COUNTER_LIMIT       0xffffff    /* highest value of the 24-bit counter */

#define PROT_REG_DATA       1           /* bytes to and from the engine */
#define ENGINE_CMD_0E       0xe         /* hdcp_tx_engine_start_command code */
#define BLOCK_LENGTH        0x20

extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned char hdcp_tx_status_bytes[];
extern unsigned char hdcp_tx_message_buffer[];
extern unsigned char hdcp_tx_work_block[];
extern unsigned char hdcp_tx_result_block[];
extern unsigned char hdcp_tx_hdmi_read_rx_status(unsigned char, unsigned char *);
extern void hdcp_tx_engine_start_command(unsigned char, int, unsigned short);
extern int hdcp_tx_reg_read(unsigned char, int);
extern unsigned char hdmi_tx_ddc_start(unsigned char, unsigned char, unsigned char, unsigned char);
extern unsigned char hdmi_tx_ddc_read(unsigned char, unsigned char *, unsigned char);

/*
 * State 0x4D of an HDMI output, only for a repeater: read 32 bytes from the engine, read the 32 bytes the
 * downstream device has waiting, and compare the two.
 *
 *   port  the HDMI output, 0 or 1
 *
 * Called by hdcp_tx_hdmi_run_state in state 0x4D. The result is step_result: STEP_NEXT when the blocks are
 * equal; STEP_OTHER when they differ; STEP_BACK when they differ and the counter word_0x10 is 0xFFFFFF, when
 * the status bytes cannot be read, bit 2 or bit 3 of the high status byte is set, or the DDC read fails;
 * STEP_AGAIN when the message length is 0. When the repeater bit is clear it returns at once with STEP_NEXT.
 * Bit 21 of word 0 is set on every path that reaches the compare (hdcp_tx_hdmi_state_forward_16_bytes tests it).
 *
 * In order:
 *   1. Status read and checks as in hdcp_tx_hdmi_state_read_result_block.
 *   2. Engine command 0x0E: read 32 bytes of the engine into hdcp_tx_result_block.
 *   3. Read 0x21 bytes of the message (DDC offset 0x80) into hdcp_tx_message_buffer and copy bytes 1..32 to
 *      hdcp_tx_work_block.
 *   4. Compare the two blocks; at the first difference the result is STEP_BACK or STEP_OTHER as above.
 */
void hdcp_tx_hdmi_state_read_second_result(unsigned char port)
{
    unsigned char status_hi;
    unsigned short message_length;
    unsigned char i;

    hdcp_tx_records[port].step_result = STEP_NEXT;
    if (!hdcp_tx_records[port].repeater)
        return;
    if (hdcp_tx_hdmi_read_rx_status(port, hdcp_tx_status_bytes)) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    status_hi = hdcp_tx_status_bytes[STATUS_HI];
    message_length = ((status_hi & RXSTATUS_LENGTH_HI) << 8) + hdcp_tx_status_bytes[STATUS_LENGTH_LO];
    if (status_hi & RXSTATUS_BITS_2_3) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    if (message_length == 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    hdcp_tx_engine_start_command(port, ENGINE_CMD_0E, 0x8000);
    for (i = 0; i < BLOCK_LENGTH; i++)
        hdcp_tx_result_block[i] = hdcp_tx_reg_read(port, PROT_REG_DATA);
    if (hdmi_tx_ddc_start(port, HDCP_DDC_DEVICE, DDC_MESSAGE, MESSAGE_LENGTH)
        || hdmi_tx_ddc_read(port, hdcp_tx_message_buffer, MESSAGE_LENGTH)) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    for (i = 0; i < BLOCK_LENGTH; i++)
        hdcp_tx_work_block[i] = hdcp_tx_message_buffer[i + 1];
    for (i = 0; i < BLOCK_LENGTH; i++) {
        if (hdcp_tx_result_block[i] != hdcp_tx_work_block[i]) {
            /* At the counter's limit the result is STEP_BACK instead of STEP_OTHER. */
            if (hdcp_tx_records[port].word_0x10 == COUNTER_LIMIT)
                hdcp_tx_records[port].step_result = STEP_BACK;
            else
                hdcp_tx_records[port].step_result = STEP_OTHER;
            break;
        }
    }
    hdcp_tx_records[port].bit21 = 1;
}
