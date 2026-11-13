/* hdcp_tx_dp_state_send_32_bytes  (FUN_a00ce420)
 *
 * State handler: fetch 32 bytes from the engine and send them over AUX.
 * Name basis: descriptive - one state handler of the per-port copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_dp_run_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ce420 @ 0xa00ce420-0xa00ce4cc (43 words), flags -mcpu=v8 -Os -g.
 * Source form: the store goes through a local pointer 'unsigned char *p = &hdcp_tx_message_buffer;' declared in
 * the loop body, which gives the firmware's base+index operand order (stb [%i4+%l0]); an integer address or
 * &buffer[i] gives index+base. Word 0 of the record is handled as a whole.
 */
/* Word 0 of a copy-protection record (24 bytes, array hdcp_tx_records), used as a whole. Its bits 16..17 hold the
   step result: 0 = STEP_BACK, 1 = STEP_NEXT, 2 = STEP_OTHER, 3 = STEP_AGAIN. */
struct hdcp_tx_record_words {
    unsigned int word0;
    unsigned char rest[0x14];
};

#define STEP_RESULT_SHIFT       16
#define STEP_RESULT_MASK        (3 << STEP_RESULT_SHIFT)        /* word 0 bits 16..17 */
extern struct hdcp_tx_record_words hdcp_tx_records[];
extern unsigned char hdcp_tx_message_buffer;
extern int hdcp_tx_reg_read();
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern int dp_tx_aux_request();

#define STEP_NEXT               1
#define ENGINE_CMD_5            5       /* engine command code, here with length 0x8000 */
#define AUX_CMD_WRITE           0x80    /* AUX command of the writes here */
#define AUX_ADDR_FIRST_HALF     0x692a0
#define AUX_ADDR_SECOND_HALF    0x692b0
#define AUX_ARG4_0xF            0xf     /* 4th argument of each write and of the 16-byte reads of the sibling handlers */

/*
 * State 0x44 of hdcp_tx_dp_run_state: send 32 bytes from the protection engine to the receiver over AUX.
 *
 * Sets step_result to STEP_NEXT, starts engine command 5 with length 0x8000 and reads 32 bytes one by one from
 * register 1 of the output's protection block into hdcp_tx_message_buffer. The first 16 bytes are then written to
 * AUX address 0x692a0 and the second 16 bytes to 0x692b0.
 */
void hdcp_tx_dp_state_send_32_bytes(unsigned char port_arg)

{
  unsigned char i;
  unsigned char index;
  unsigned char port;

  port = port_arg & 0xff;
  hdcp_tx_records[port].word0 =
       (hdcp_tx_records[port].word0 & ~STEP_RESULT_MASK) | (STEP_NEXT << STEP_RESULT_SHIFT);
  hdcp_tx_engine_start_command(port, ENGINE_CMD_5, 0x8000);
  i = 0;
  do {
    unsigned char *p = &hdcp_tx_message_buffer;
    index = i;
    p[index] = hdcp_tx_reg_read(port, 1);
    i = i + 1;
  } while (i <= 0x1f);
  dp_tx_aux_request(0, AUX_CMD_WRITE, AUX_ADDR_FIRST_HALF, AUX_ARG4_0xF, &hdcp_tx_message_buffer);
  dp_tx_aux_request(0, AUX_CMD_WRITE, AUX_ADDR_SECOND_HALF, AUX_ARG4_0xF, &hdcp_tx_message_buffer + 0x10);
}
