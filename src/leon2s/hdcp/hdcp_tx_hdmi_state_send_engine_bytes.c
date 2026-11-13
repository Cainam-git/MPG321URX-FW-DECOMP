/* hdcp_tx_hdmi_state_send_engine_bytes  (FUN_a00caee4)
 *
 * State handler: fetch bytes from the engine and send them to the receiver.
 * Name basis: descriptive - one state handler of the per-output copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_hdmi_run_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00caee4 @ 0xa00caee4-0xa00caf78 (37 words), flags -mcpu=v8 -Os -g.
 * Source form: the last call is a tail call; the buffer base serves both the stores and the call argument.
 */
/* Copy-protection record of one video output (24 bytes, array hdcp_tx_records). */
struct hdcp_tx_record {
    unsigned int f31 : 1;               /* bit 31 */
    unsigned int f30 : 1;
    unsigned int f29 : 1;
    unsigned int repeater : 1;          /* bit 28 */
    unsigned int tries_left : 4;        /* bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int b22 : 1;
    unsigned int b21 : 1;
    unsigned int b20 : 1;
    unsigned int b19 : 1;
    unsigned int b18 : 1;
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, written by the state handlers */
    unsigned char state;                /* +2: state of the handshake, the case value of the run_state switch */
    unsigned char device_count;         /* +3 */
    unsigned char level;                /* +4 */
    unsigned char count_overflow;       /* +5 */
    unsigned char level_overflow;       /* +6 */
    unsigned char byte_0x7;
    unsigned char byte_0x8;
    unsigned char engine_unit;          /* +9: 0xFF = none */
    unsigned char bytes_0xa_0xb[2];
    unsigned int word_0xc;
    unsigned int word_0x10;
    unsigned char byte_0x14;
    unsigned char byte_0x15;
    unsigned short halfword_0x16;
};
/* Result of a state handler, read by hdcp_tx_select_next_state. STEP_AGAIN keeps the state until the time limit of
   the state has run out (hdcp_tx_service_port then turns it into STEP_BACK). */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};
extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned char hdcp_tx_message_buffer[];
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern unsigned char hdcp_tx_reg_read(unsigned char, unsigned short);
extern void hdmi_tx_ddc_write(unsigned char, unsigned char *, int, int, int);

#define ENGINE_CMD_5            5               /* engine command code, here with length 0x8000 */
#define MESSAGE_PAYLOAD_BYTES   0x20            /* bytes taken from the engine */
#define HDCP_DDC_DEVICE         0x74            /* device address used for all handshake reads and writes */
#define MESSAGE_OFFSET          0x60            /* offset written to on that device */

/*
 * State 0x44 of hdcp_tx_hdmi_run_state: send 32 bytes from the protection engine to the receiver.
 *
 * Sets step_result to STEP_NEXT, starts engine command 5 with length 0x8000, reads 32 bytes one by one from
 * register 1 of the output's protection block into hdcp_tx_message_buffer[1..32], puts the command code 5 in
 * hdcp_tx_message_buffer[0] and writes the 33 bytes to the receiver (device 0x74, offset 0x60).
 */
void hdcp_tx_hdmi_state_send_engine_bytes(unsigned char port)
{
    unsigned char i;

    hdcp_tx_records[port].step_result = STEP_NEXT;
    hdcp_tx_message_buffer[0] = ENGINE_CMD_5;
    hdcp_tx_engine_start_command(port, ENGINE_CMD_5, 0x8000);
    for (i = 0; i < MESSAGE_PAYLOAD_BYTES; i++)
        hdcp_tx_message_buffer[1 + i] = hdcp_tx_reg_read(port, 1);
    hdmi_tx_ddc_write(port, hdcp_tx_message_buffer, HDCP_DDC_DEVICE, MESSAGE_OFFSET, MESSAGE_PAYLOAD_BYTES + 1);
}
