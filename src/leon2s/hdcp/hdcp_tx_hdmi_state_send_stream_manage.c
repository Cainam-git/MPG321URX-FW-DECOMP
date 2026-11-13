/* hdcp_tx_hdmi_state_send_stream_manage  (FUN_a00cc2f8)
 *
 * State handler: for a repeater, load the stream counter into the engine and send message 0x10.
 * Note: Message 0x10 of HDCP 2.x is RepeaterAuth_Stream_Manage; a waiting receiver message gives 'again'.
 * Name basis: derived - one state handler of the per-output copy-protection state machine, called from
 *   hdcp_tx_hdmi_run_state; writes 8 bytes starting with 0x10 to DDC device 0x74 offset 0x60; prints the
 *   engine bytes
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cc2f8 @ 0xa00cc2f8-0xa00cc5f8, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the status bytes are a plain byte array; the high byte is copied into a local and the length joined with +
 *    as an unsigned short;
 *  - the first read loop prints each register value with the text "%02X "; the second loop stores the register
 *    value straight into hdcp_tx_message_buffer[i + 1] and prints that element (the element address is
 *    computed before the call);
 *  - the counter bytes are written by shifting word_0x10 right by (2 - i) * 8.
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
    unsigned int word_0x10;             /* 24-bit counter, written to the engine by this routine */
    unsigned char pad_0x14[4];
};

/* Result of a state handler. hdcp_tx_select_next_state picks the next state from it; for this state (0x4C):
   STEP_NEXT -> 0x4D, STEP_BACK -> 0x40, STEP_AGAIN -> state kept. */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_AGAIN = 3
};

/* The two RXSTATUS bytes in hdcp_tx_status_bytes. */
#define STATUS_LENGTH_LO    0           /* message length, bits 0..7 */
#define STATUS_HI           1           /* bits 0..1: message length bits 8..9 */
#define RXSTATUS_LENGTH_HI  3
#define RXSTATUS_BITS_2_3   0xc         /* either bit set: STEP_BACK */

#define HDCP_DDC_DEVICE     0x74        /* device address used for all handshake reads and writes */
#define DDC_WRITE_MESSAGE   0x60        /* offset a message is written to */
#define MESSAGE_LENGTH      8           /* byte 0 and the 7 engine bytes */
#define MESSAGE_FIRST_BYTE  0x10
#define COUNTER_BYTES       3

#define PROT_REG_DATA       1           /* bytes to and from the engine */
#define PROT_REG_6          6           /* 0x90 / 0xF0 are written to it; bit 7 reads 1 while busy */
#define PROT_REG_DATA_2     0x12        /* second data register of the protection block */
#define ENGINE_CMD_0D       0xd         /* hdcp_tx_engine_start_command codes, in the order they are given */
#define ENGINE_CMD_10       0x10
#define ENGINE_CMD_END      0           /* code 0, length 0 */

extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned char hdcp_tx_status_bytes[];
extern unsigned char hdcp_tx_message_buffer[];
extern unsigned char hdcp_tx_hdmi_read_rx_status(unsigned char, unsigned char *);
extern void hdcp_tx_reg_write(unsigned char, unsigned short, unsigned char);
extern unsigned char hdcp_tx_reg_read(unsigned char, unsigned short);
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern int hdmi_tx_ddc_write(unsigned char, unsigned char *, unsigned char, unsigned char, unsigned short);
extern int dbg_printf(const char *, ...);

/*
 * State 0x4C of an HDMI output, only for a repeater: give the engine the 24-bit counter, read 7 bytes back and
 * send them to the downstream device.
 *
 *   port  the HDMI output, 0 or 1
 *
 * Called by hdcp_tx_hdmi_run_state in state 0x4C. The result is step_result: STEP_NEXT after the transfer;
 * STEP_AGAIN when bit 22 of the record's word 0 is clear or the downstream device has a message waiting
 * (message length not 0); STEP_BACK when the status bytes cannot be read or bit 2 or bit 3 of the high status
 * byte is set. When the repeater bit is clear nothing is done and step_result is left as it was.
 *
 * In order:
 *   1. The checks above, in the order bit 22, status read, status bits, message length.
 *   2. Write 0x90 to protection register 6. Engine command 0x0D; write to register 1: the 3 counter bytes
 *      (word_0x10, high byte first), 0, 1, 0, 0, the 3 counter bytes again, 0x80. Count word_0x10 one up.
 *      Wait until bit 7 of register 6 reads 0 (no limit).
 *   3. Engine command 0x10 with length 0x4020: read 32 bytes of register 0x12 and print them.
 *   4. Engine command 0 with length 0. Write 0xF0 to register 6 and wait until its bit 7 reads 0 again.
 *   5. Engine command 0x0D: read 7 bytes of register 1 into hdcp_tx_message_buffer bytes 1..7 and print
 *      them. Byte 0 = 0x10. Write the 8 bytes to the device (DDC offset 0x60).
 */
void hdcp_tx_hdmi_state_send_stream_manage(unsigned char port)
{
    unsigned char status_hi;
    unsigned short message_length;
    unsigned char i;

    if (hdcp_tx_records[port].bit22 == 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
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
    if (message_length != 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    if (hdcp_tx_records[port].repeater == 0)
        return;
    hdcp_tx_reg_write(port, PROT_REG_6, 0x90);
    hdcp_tx_engine_start_command(port, ENGINE_CMD_0D, 0x8000);
    /* The counter, high byte first. */
    for (i = 0; i < COUNTER_BYTES; i++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, hdcp_tx_records[port].word_0x10 >> ((2 - i) * 8));
    hdcp_tx_reg_write(port, PROT_REG_DATA, 0);
    hdcp_tx_reg_write(port, PROT_REG_DATA, 1);
    hdcp_tx_reg_write(port, PROT_REG_DATA, 0);
    hdcp_tx_reg_write(port, PROT_REG_DATA, 0);
    for (i = 0; i < COUNTER_BYTES; i++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, hdcp_tx_records[port].word_0x10 >> ((2 - i) * 8));
    hdcp_tx_reg_write(port, PROT_REG_DATA, 0x80);
    hdcp_tx_records[port].word_0x10++;
    while (hdcp_tx_reg_read(port, PROT_REG_6) & 0x80)
        ;
    hdcp_tx_engine_start_command(port, ENGINE_CMD_10, 0x4020);
    for (i = 0; i < 0x20; i++)
        dbg_printf("%02X ", hdcp_tx_reg_read(port, PROT_REG_DATA_2));
    hdcp_tx_engine_start_command(port, ENGINE_CMD_END, 0);
    hdcp_tx_reg_write(port, PROT_REG_6, 0xf0);
    while (hdcp_tx_reg_read(port, PROT_REG_6) & 0x80)
        ;
    hdcp_tx_engine_start_command(port, ENGINE_CMD_0D, 0x8000);
    for (i = 0; i < 7; i++) {
        hdcp_tx_message_buffer[i + 1] = hdcp_tx_reg_read(port, PROT_REG_DATA);
        dbg_printf("%02X ", hdcp_tx_message_buffer[i + 1]);
    }
    hdcp_tx_message_buffer[0] = MESSAGE_FIRST_BYTE;
    hdmi_tx_ddc_write(port, hdcp_tx_message_buffer, HDCP_DDC_DEVICE, DDC_WRITE_MESSAGE, MESSAGE_LENGTH);
    hdcp_tx_records[port].step_result = STEP_NEXT;
}
