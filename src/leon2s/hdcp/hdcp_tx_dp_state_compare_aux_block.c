/* hdcp_tx_dp_state_compare_aux_block  (FUN_a00ce4cc)
 *
 * Read a 32-byte block over AUX and compare it with the engine's result block.
 * Name basis: descriptive - one state handler of the per-port copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_dp_run_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ce4cc @ 0xa00ce4cc (-mcpu=v8 -Os -g)
 * Source form: the variable i is first the word index port * 6 of the record (its halfword type is kept) and then
 * the loop counter; the record is addressed as an array of unsigned words.
 */
extern unsigned int hdcp_tx_records[];
extern unsigned char hdcp_tx_result_block[];
extern unsigned char hdcp_tx_work_block[];
extern int hdcp_tx_clear_ksv_table(unsigned char);
extern int hdcp_tx_hdmi_run_fixed_block(unsigned char);
extern int dp_tx_aux_request_copy(int, int, int, int, unsigned char *);

#define RECORD_WORDS            6       /* a record is 24 bytes = 6 words */
#define STEP_RESULT_SHIFT       16
#define STEP_RESULT_MASK        (3 << STEP_RESULT_SHIFT)        /* word 0 bits 16..17: STEP_BACK 0 .. STEP_AGAIN 3 */
#define STEP_NEXT_BITS          (1 << STEP_RESULT_SHIFT)
#define STEP_AGAIN_BITS         (3 << STEP_RESULT_SHIFT)
#define AUX_CMD_READ            0x90    /* AUX command of the reads here */
#define AUX_ADDR_0x69493        0x69493
#define AUX_ADDR_FIRST_HALF     0x692c0
#define AUX_ADDR_SECOND_HALF    0x692d0
#define AUX_ARG4_0xF            0xf     /* 4th argument of the two 16-byte reads */
#define BLOCK_BYTES             32
#define HALF_BYTES              16
#define STATUS_BIT1             2       /* bit 1 of the byte read from 0x69493 */

/*
 * State 0x45 of hdcp_tx_dp_run_state: read 32 bytes over AUX and compare them with the result block of the engine.
 *
 * Sets step_result to STEP_NEXT and reads the byte at AUX address 0x69493. If its bit 1 is clear, step_result
 * becomes STEP_AGAIN and the routine ends. Otherwise the 16 bytes at 0x692c0 and the 16 bytes at 0x692d0 are
 * read into hdcp_tx_work_block (bytes 0..15 and 16..31), hdcp_tx_hdmi_run_fixed_block(port) is called, and the
 * 32 bytes of hdcp_tx_work_block are compared with hdcp_tx_result_block. At the first difference step_result
 * becomes STEP_BACK and hdcp_tx_clear_ksv_table(port) is called.
 */
void hdcp_tx_dp_state_compare_aux_block(unsigned char port_arg)
{
    unsigned char read_buffer[HALF_BYTES];
    unsigned short i;
    unsigned char port;

    port = port_arg & 0xff;
    i = port * RECORD_WORDS;
    hdcp_tx_records[i] = (hdcp_tx_records[i] & ~STEP_RESULT_MASK) | STEP_NEXT_BITS;

    dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_ADDR_0x69493, 0, read_buffer);

    if ((read_buffer[0] & STATUS_BIT1) == 0) {
        hdcp_tx_records[i] = hdcp_tx_records[i] | STEP_AGAIN_BITS;
    } else {
        dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_ADDR_FIRST_HALF, AUX_ARG4_0xF, read_buffer);
        for (i = 0; i < HALF_BYTES; i++)
            hdcp_tx_work_block[i] = read_buffer[i];

        dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_ADDR_SECOND_HALF, AUX_ARG4_0xF, read_buffer);
        for (i = 0; i < HALF_BYTES; i++)
            hdcp_tx_work_block[i + HALF_BYTES] = read_buffer[i];

        hdcp_tx_hdmi_run_fixed_block(port);

        for (i = 0; i < BLOCK_BYTES; i++) {
            if (hdcp_tx_result_block[i] != hdcp_tx_work_block[i]) {
                hdcp_tx_records[port * RECORD_WORDS] = hdcp_tx_records[port * RECORD_WORDS] & ~STEP_RESULT_MASK;
                hdcp_tx_clear_ksv_table(port);
                break;
            }
        }
    }
}
