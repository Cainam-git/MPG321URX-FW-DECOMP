/* hdcp_tx_hdmi_state_forward_16_bytes  (FUN_a00cc1d4)
 *
 * State handler: read 16 bytes from the engine and send them to the receiver.
 * Name basis: descriptive - one state handler of the per-output copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_hdmi_run_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cc1d4 @ 0xa00cc1d4-0xa00cc2f8, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - word 0 of the record is a bit-field group; GCC keeps the field mask 0xfffcffff in a register for the
 *    first stores;
 *  - the prototype of hdmi_tx_ddc_write (u8, u8 *, u8, u8, u16) decides the order of the argument set-up;
 *  - the status bytes are a two-byte struct.
 */

/* Protection record of an output (24 bytes, docs/DATA.md; the fields used here). */
struct hdcp_tx_record {
    unsigned int bits_28_31 : 4;        /* bit 28: repeater */
    unsigned int tries_left : 4;        /* bits 24..27 */
    unsigned int bits_22_23 : 2;
    unsigned int bit21 : 1;
    unsigned int bits_18_20 : 3;
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, read by hdcp_tx_select_next_state */
    unsigned int state_and_count : 16;  /* +2 state, +3 device_count */
    unsigned int word_0x4;
    unsigned int word_0x8;
    unsigned int word_0xc;
    unsigned int word_0x10;             /* counter, see hdcp_tx_hdmi_state_send_stream_manage */
    unsigned int word_0x14;
};

/* The two RXSTATUS bytes (hdcp_tx_hdmi_read_rx_status). */
struct rx_status {
    unsigned char length_lo;            /* message length, bits 0..7 */
    unsigned char hi;                   /* bits 0..1: message length bits 8..9; bit 3: RXSTATUS_BIT3 */
};

/* Result of a state handler. hdcp_tx_select_next_state picks the next state from it; for this state (0x4B),
   with bit23 set in both cases: STEP_NEXT -> 0x4C, STEP_OTHER -> 0x4E, STEP_BACK -> 0x40. */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2
};

#define RXSTATUS_BIT3       8           /* set: STEP_BACK */

#define HDCP_DDC_DEVICE     0x74        /* device address used for all handshake reads and writes */
#define DDC_WRITE_MESSAGE   0x60        /* offset a message is written to */
#define MESSAGE_LENGTH      0x11        /* byte 0 and the 16 engine bytes */
#define MESSAGE_FIRST_BYTE  0xf

#define PROT_REG_DATA_2     0x12        /* second data register of the protection block */
#define ENGINE_CMD_0C       0xc         /* hdcp_tx_engine_start_command code */
#define BLOCK_LENGTH        0x10

extern struct hdcp_tx_record hdcp_tx_records[];
extern struct rx_status hdcp_tx_status_bytes;
extern unsigned char hdcp_tx_result_block[];
extern unsigned int hdcp_tx_hdmi_read_rx_status(unsigned char, struct rx_status *);
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern unsigned char hdcp_tx_reg_read(unsigned char, unsigned char);
extern int hdmi_tx_ddc_write(unsigned char, unsigned char *, unsigned char, unsigned char, unsigned short);

/*
 * State 0x4B of an HDMI output: read 16 bytes from the engine and send them to the downstream device.
 *
 *   port  the HDMI output, 0 or 1
 *
 * Called by hdcp_tx_hdmi_run_state in state 0x4B. The result is step_result: STEP_NEXT, or STEP_OTHER when
 * bit 21 of the record's word 0 is set (hdcp_tx_hdmi_state_read_second_result sets it), or STEP_BACK when the
 * status bytes cannot be read or bit 3 of the high status byte is set.
 *
 * In order:
 *   1. Engine command 0x0C: read 16 bytes from register 0x12 into hdcp_tx_result_block bytes 1..16, with
 *      byte 0 = 0x0F.
 *   2. Write the 0x11 bytes to the device (DDC offset 0x60).
 *   3. Count one up in word_0x10 of the record.
 */
void hdcp_tx_hdmi_state_forward_16_bytes(unsigned char port)
{
    unsigned char i;

    hdcp_tx_records[port].step_result = STEP_NEXT;
    if ((unsigned char)hdcp_tx_hdmi_read_rx_status(port, &hdcp_tx_status_bytes) != 0) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    if (hdcp_tx_status_bytes.hi & RXSTATUS_BIT3) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    hdcp_tx_engine_start_command(port, ENGINE_CMD_0C, 0x8000);
    for (i = 0; i < BLOCK_LENGTH; i++)
        hdcp_tx_result_block[1 + i] = hdcp_tx_reg_read(port, PROT_REG_DATA_2);
    hdcp_tx_result_block[0] = MESSAGE_FIRST_BYTE;
    hdmi_tx_ddc_write(port, hdcp_tx_result_block, HDCP_DDC_DEVICE, DDC_WRITE_MESSAGE, MESSAGE_LENGTH);
    hdcp_tx_records[port].word_0x10++;
    if (hdcp_tx_records[port].bit21)
        hdcp_tx_records[port].step_result = STEP_OTHER;
}
