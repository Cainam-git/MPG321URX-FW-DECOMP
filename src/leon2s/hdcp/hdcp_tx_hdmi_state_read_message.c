/* hdcp_tx_hdmi_state_read_message  (FUN_a00ca8c4)
 *
 * State handler: read a message from the receiver and store its parts.
 * Name basis: descriptive - one state handler of the per-output copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_hdmi_run_state
 *
 * Matching notes
 * --------------
 * FUN_a00ca8c4 (leon2s, 0xa00ca8c4-0xa00cab10, 588 bytes), flags -mcpu=v8 -Os -g.
 * Word 0 of the record is a group of bit-fields (big-endian, first field = bit 31). The empty counting loops
 * (u16 counter) are part of the build. hdcp_tx_hash_message_buffer is declared with an argument although it takes
 * none; the argument is part of the build. Same record and buffers as hdcp_tx_hdmi_state_read_result_block.
 */
/* Copy-protection record of one video output (24 bytes, array hdcp_tx_records); word 0 is a group of bit-fields,
   bit 31 first. */
struct hdcp_tx_record {
    unsigned int bit31 : 1;
    unsigned int bit30 : 1;
    unsigned int bit29 : 1;
    unsigned int repeater : 1;          /* bit 28 */
    unsigned int tries_left : 4;        /* bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int bit22 : 1;
    unsigned int bit21 : 1;
    unsigned int bit20 : 1;
    unsigned int bit19 : 1;             /* set by hdcp_tx_hdmi_state_compare_results once its comparison has passed */
    unsigned int bit18 : 1;
    unsigned int step_result : 2;       /* bits 16..17: result of the state handler (STEP_*) */
    unsigned char state;                /* +2 */
    unsigned char device_count;         /* +3 */
    unsigned char level;                /* +4 */
    unsigned char count_overflow;       /* +5 */
    unsigned char level_overflow;       /* +6 */
    unsigned char byte_0x7;
    unsigned char byte_0x8;
    unsigned char engine_unit;          /* +9: engine unit given to the output */
    unsigned char pad_a[6];
    unsigned int word_0x10;
    unsigned char pad_14[4];
};

/* Result of a state handler; hdcp_tx_select_next_state picks the next state from it. */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};

extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned char hdcp_tx_status_bytes[];
extern unsigned char hdcp_tx_message_buffer[];
extern unsigned char hdcp_tx_receiver_ids[];
extern unsigned char hdcp_tx_message_tail[];
extern unsigned char hdcp_tx_engine_buffer[];
extern unsigned char hdcp_tx_hdmi_read_rx_status(unsigned char, unsigned char *);
extern unsigned char hdmi_tx_ddc_start(unsigned char, unsigned char, unsigned char, unsigned short);
extern void hdcp_tx_hdmi_read_message(unsigned char, unsigned char *, unsigned short);
extern void hdcp_tx_engine_write_block(unsigned int, unsigned char *, unsigned char, unsigned char, unsigned short);
extern void hdcp_tx_hash_message_buffer(unsigned char *);

#define HDCP_DDC_DEVICE     0x74        /* device address of the receiver on the output's DDC channel */
#define DDC_MESSAGE_OFFSET  0x80        /* offset the message is read from */
#define LENGTH_HIGH_MASK    3           /* the length is ((status[1] & 3) << 8) + status[0] */
#define STATUS_HIGH_BITS_2_3 0xc        /* any of these bits in status[1] ends the state with STEP_BACK */
#define MESSAGE_FIRST_BYTE  3           /* hdcp_tx_message_buffer[0] must have this value */
#define RECEIVER_ID_SIZE    5           /* buffer bytes 1..5 */
#define TAIL_OFFSET         0x86        /* buffer bytes 0x86..0x88 */
#define TAIL_SIZE           3
#define ENGINE_BLOCK_LENGTH 0xc00       /* length argument of hdcp_tx_engine_write_block for the 0x180-byte buffer */

/*
 * State handler of an HDMI output (state 65 = 0x41 of hdcp_tx_hdmi_run_state). port = output 0 or 1.
 *
 * Reads the receiver's message into hdcp_tx_message_buffer and keeps two parts of it. The result is
 * left in step_result: STEP_NEXT moves the output to state 0x42; STEP_AGAIN keeps the state so that the handler
 * runs again; STEP_BACK returns the output to state 0.
 *
 * Decisions in order:
 *  1. The receiver's two status bytes are read (hdcp_tx_hdmi_read_rx_status) into hdcp_tx_status_bytes. A read
 *     error gives STEP_BACK.
 *  2. The message length is ((status[1] & 3) << 8) + status[0]. Any of bits 2..3 of status[1] gives STEP_BACK;
 *     a length of 0 gives STEP_AGAIN (nothing to read yet).
 *  3. The DDC master is set up for that many bytes (hdmi_tx_ddc_start; an error gives STEP_BACK) and the message
 *     is read. hdcp_tx_message_buffer[0] must then be 3, else STEP_BACK.
 *  4. After three empty delay loops, buffer bytes 1..5 are copied to the output's row in hdcp_tx_receiver_ids
 *     (5 bytes per output) and buffer bytes 0x86..0x88 to hdcp_tx_message_tail.
 *  5. When bit 19 of the record is clear, hdcp_tx_engine_buffer is sent to the engine unit of the output
 *     (write mode 0) and buffer bytes 1..0x8a are written through hdcp_tx_hash_message_buffer.
 */
void hdcp_tx_hdmi_state_read_message(unsigned char port)
{
    unsigned char status_high;
    unsigned short message_length;
    unsigned short k;

    hdcp_tx_records[port].step_result = STEP_NEXT;
    if (hdcp_tx_hdmi_read_rx_status(port, hdcp_tx_status_bytes)) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    status_high = hdcp_tx_status_bytes[1];
    message_length = ((status_high & LENGTH_HIGH_MASK) << 8) + hdcp_tx_status_bytes[0];
    if (status_high & STATUS_HIGH_BITS_2_3) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    if (message_length == 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    if (hdmi_tx_ddc_start(port, HDCP_DDC_DEVICE, DDC_MESSAGE_OFFSET, message_length)) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    hdcp_tx_hdmi_read_message(port, hdcp_tx_message_buffer, message_length);
    if (hdcp_tx_message_buffer[0] != MESSAGE_FIRST_BYTE) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    for (k = 0; k < 0x8a; k++)
        ;
    for (k = 0; k < 0x180; k++)
        ;
    for (k = 0; k < 0xb; k++)
        ;
    for (k = 0; k < RECEIVER_ID_SIZE; k++)
        hdcp_tx_receiver_ids[port * RECEIVER_ID_SIZE + k] = hdcp_tx_message_buffer[k + 1];
    for (k = 0; k < 0x80; k++)
        ;
    for (k = 0; k < TAIL_SIZE; k++)
        hdcp_tx_message_tail[k] = hdcp_tx_message_buffer[k + TAIL_OFFSET];
    for (k = 0; k < 2; k++)
        ;
    if (!hdcp_tx_records[port].bit19) {
        hdcp_tx_engine_write_block(hdcp_tx_records[port].engine_unit, hdcp_tx_engine_buffer, 0, 0, ENGINE_BLOCK_LENGTH);
        hdcp_tx_hash_message_buffer(&hdcp_tx_message_buffer[1]);
    }
}
