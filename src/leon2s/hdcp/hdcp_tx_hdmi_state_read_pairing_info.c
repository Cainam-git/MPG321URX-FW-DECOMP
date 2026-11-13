/* hdcp_tx_hdmi_state_read_pairing_info  (FUN_a00cb1d4)
 *
 * State handler: read the receiver's 16-byte message, store it with 16 engine bytes and keep its id.
 * Note: Nothing is sent to the receiver; a receiver sends a 17-byte message only as HDCP 2.x pairing
 *   information.
 * Name basis: derived - one state handler of the per-output copy-protection state machine, called from
 *   hdcp_tx_hdmi_run_state; reads 17 bytes from DDC device 0x74 offset 0x80, writes them and 16 engine bytes
 *   with engine command 5, copies the receiver id into hdcp_tx_ksv_table
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cb1d4 @ 0xa00cb1d4-0xa00cb3e8, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the message length is joined with + as an unsigned short ((hi & 3) << 8) + lo;
 *  - the counters are unsigned char; the record's word 0 is a bit-field group;
 *  - the status bytes are a two-byte struct, the message buffers plain byte arrays.
 */

/* Protection record of an output (24 bytes, docs/DATA.md; the fields used here). */
struct hdcp_tx_record {
    unsigned int bits_29_31 : 3;
    unsigned int repeater : 1;          /* bit 28 */
    unsigned int tries_left : 4;        /* bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int bits_18_22 : 5;
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, read by hdcp_tx_select_next_state */
    unsigned int state : 8;             /* +2: the state hdcp_tx_hdmi_run_state dispatches on */
    unsigned char rest[20];
};

/* The two RXSTATUS bytes (hdcp_tx_hdmi_read_rx_status). */
struct rx_status {
    unsigned char length_lo;            /* message length, bits 0..7 */
    unsigned char hi;                   /* bits 0..1: message length bits 8..9; bits 2 and 3: RXSTATUS_BITS_2_3 */
};

/* Result of a state handler. hdcp_tx_select_next_state picks the next state from it; for this state (0x46):
   STEP_NEXT -> 0x47, STEP_BACK and STEP_OTHER -> 0x40, STEP_AGAIN -> state kept. */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};

#define RXSTATUS_LENGTH_HI  3           /* mask of the length bits in the high byte */
#define RXSTATUS_BITS_2_3   0xc         /* either bit set: STEP_BACK */

#define HDCP_DDC_DEVICE     0x74        /* device address used for all handshake reads and writes */
#define DDC_MESSAGE         0x80        /* offset the message is read from */
#define MESSAGE_LENGTH      0x11        /* bytes read: byte 0 and the 16 bytes used */

#define PROT_REG_DATA       1           /* bytes to and from the engine */
#define ENGINE_CMD_READ_A   1           /* hdcp_tx_engine_start_command codes, in the order they are given */
#define ENGINE_CMD_READ_B   3
#define ENGINE_CMD_WRITE    5
#define HALF_LENGTH         8           /* bytes read from the engine after each of the first two commands */
#define BLOCK_LENGTH        16
#define ID_LENGTH           5           /* bytes of a receiver id and of a stored key-selection value */

extern struct hdcp_tx_record hdcp_tx_records[];
extern struct rx_status hdcp_tx_status_bytes;
extern unsigned char hdcp_tx_message_buffer[];
extern unsigned char hdcp_tx_ksv_table[];
extern unsigned char hdcp_tx_receiver_ids[];
extern unsigned int hdcp_tx_hdmi_read_rx_status(unsigned char, struct rx_status *);
extern unsigned int hdmi_tx_ddc_start(unsigned char, unsigned char, unsigned char, unsigned char);
extern unsigned int hdmi_tx_ddc_read(unsigned char, unsigned char *, unsigned char);
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern unsigned char hdcp_tx_reg_read(unsigned char, unsigned char);
extern void hdcp_tx_reg_write(unsigned char, unsigned char, unsigned char);

/*
 * State 0x46 of an HDMI output: take the 16 bytes the downstream device has waiting, pass them through the
 * engine and store the output's receiver id as its key-selection value.
 *
 *   port  the HDMI output, 0 or 1
 *
 * Called by hdcp_tx_hdmi_run_state in state 0x46. The result is step_result: STEP_NEXT when everything went
 * through; STEP_BACK when the status bytes cannot be read, bit 2 or bit 3 of the high status byte is set, or
 * the DDC read fails; STEP_AGAIN when the message length is 0 (the state is then kept and the handler runs
 * again).
 *
 * In order:
 *   1. Read the status bytes; the message length is 10 bits (low byte and the two low bits of the high byte).
 *   2. Read 0x11 bytes of the message (DDC offset 0x80) into hdcp_tx_message_buffer.
 *   3. Engine command 1: read 8 bytes from the engine; engine command 3: read 8 more (16 bytes in all).
 *   4. Engine command 5: write message bytes 1..16, then the 16 bytes read in step 3, back to the engine.
 *   5. Copy the output's receiver id (5 bytes) into hdcp_tx_ksv_table.
 */
void hdcp_tx_hdmi_state_read_pairing_info(unsigned char port)
{
    unsigned char engine_bytes[BLOCK_LENGTH];
    unsigned char i;
    unsigned short message_length;

    hdcp_tx_records[port].step_result = STEP_NEXT;
    if ((unsigned char)hdcp_tx_hdmi_read_rx_status(port, &hdcp_tx_status_bytes) != 0) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    message_length = ((hdcp_tx_status_bytes.hi & RXSTATUS_LENGTH_HI) << 8) + hdcp_tx_status_bytes.length_lo;
    if ((hdcp_tx_status_bytes.hi & RXSTATUS_BITS_2_3) != 0) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    if (message_length == 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    if ((unsigned char)hdmi_tx_ddc_start(port, HDCP_DDC_DEVICE, DDC_MESSAGE, MESSAGE_LENGTH) != 0) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    if ((unsigned char)hdmi_tx_ddc_read(port, hdcp_tx_message_buffer, MESSAGE_LENGTH) != 0) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    hdcp_tx_engine_start_command(port, ENGINE_CMD_READ_A, 0x8000);
    for (i = 0; i < HALF_LENGTH; i++)
        engine_bytes[i] = hdcp_tx_reg_read(port, PROT_REG_DATA);
    hdcp_tx_engine_start_command(port, ENGINE_CMD_READ_B, 0x8000);
    for (i = HALF_LENGTH; i < BLOCK_LENGTH; i++)
        engine_bytes[i] = hdcp_tx_reg_read(port, PROT_REG_DATA);
    hdcp_tx_engine_start_command(port, ENGINE_CMD_WRITE, 0x8000);
    for (i = 0; i < BLOCK_LENGTH; i++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, hdcp_tx_message_buffer[i + 1]);
    for (i = 0; i < BLOCK_LENGTH; i++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, engine_bytes[i]);
    for (i = 0; i < ID_LENGTH; i++)
        hdcp_tx_ksv_table[port * ID_LENGTH + i] = hdcp_tx_receiver_ids[port * ID_LENGTH + i];
}
