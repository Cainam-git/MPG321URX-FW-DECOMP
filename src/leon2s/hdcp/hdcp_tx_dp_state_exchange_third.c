/* hdcp_tx_dp_state_exchange_third  (FUN_a00cea60)
 *
 * State handler: start an engine step and read the answer block over AUX (third form).
 * Name basis: descriptive - one state handler of the per-port copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_dp_run_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cea60 @ 0xa00cea60-0xa00cec18, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: hdcp_tx_records is an unsigned char array and word 0 of the record is
 * reached as *(unsigned int *)(hdcp_tx_records + port * 24); the loops are do-while loops with unsigned short
 * counters; the second copy goes to hdcp_tx_work_block[i + 0x10] (the firmware reloads the table base and
 * stores at +0x10).
 */
extern unsigned char hdcp_tx_records[];
extern unsigned char hdcp_tx_result_block[];
extern unsigned char hdcp_tx_work_block[];
extern int hdcp_tx_reg_read(unsigned char, int);
extern void hdcp_tx_engine_start_command(unsigned char, int, unsigned short);
extern int dp_tx_aux_request_copy(int, int, int, int, void *);

#define RECORD_SIZE             24
#define STEP_RESULT_SHIFT       16
#define STEP_RESULT_MASK        (3 << STEP_RESULT_SHIFT)        /* word 0 bits 16..17: STEP_BACK 0 .. STEP_AGAIN 3 */
#define STEP_NEXT_BITS          (1 << STEP_RESULT_SHIFT)
#define STEP_OTHER_BITS         (2 << STEP_RESULT_SHIFT)
#define AUX_CMD_READ            0x90
#define AUX_ANSWER_FIRST        0x692f8     /* 16 bytes: work block bytes 0..15 */
#define AUX_ANSWER_SECOND       0x69308     /* 16 bytes: work block bytes 16..31 */
#define HALF_BYTES              0x10
#define BLOCK_BYTES             0x20
#define ENGINE_CMD_9            9           /* hdcp_tx_engine_start_command code */
#define PROT_REG_DATA           1           /* protection block register: bytes from the engine */

/*
 * State 0x48 of the DisplayPort output: read the engine's 32-byte result, read the receiver's 32-byte answer, and
 * report whether they are equal.
 *
 *   port  the output, 2
 *
 * Called by hdcp_tx_dp_run_state in state 0x48. It reports through step_result (STEP_*), written on word 0 of
 * the record as a whole.
 *
 *   1. step_result = STEP_NEXT.
 *   2. Engine command 9 (length 0x8000); 32 bytes read from register 1 of the output's protection block go to
 *      hdcp_tx_result_block.
 *   3. Two 16-byte AUX reads (channel 0, 0x692F8 and 0x69308) fill hdcp_tx_work_block.
 *   4. At the first byte where the two blocks differ step_result is STEP_OTHER.
 */
void hdcp_tx_dp_state_exchange_third(unsigned char port_arg)
{
    unsigned char port;
    unsigned short i;
    unsigned char answer[HALF_BYTES];

    port = port_arg & 0xff;
    *(unsigned int *)(hdcp_tx_records + port * RECORD_SIZE) =
        (*(unsigned int *)(hdcp_tx_records + port * RECORD_SIZE) & ~STEP_RESULT_MASK) | STEP_NEXT_BITS;

    hdcp_tx_engine_start_command(port, ENGINE_CMD_9, 0x8000);

    i = 0;
    do {
        hdcp_tx_result_block[i] = (unsigned char)hdcp_tx_reg_read(port, PROT_REG_DATA);
        i = i + 1;
    } while (i < BLOCK_BYTES);

    dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_ANSWER_FIRST, HALF_BYTES - 1, answer);

    i = 0;
    do {
        hdcp_tx_work_block[i] = answer[i];
        i = i + 1;
    } while (i < HALF_BYTES);

    dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_ANSWER_SECOND, HALF_BYTES - 1, answer);

    i = 0;
    do {
        hdcp_tx_work_block[i + HALF_BYTES] = answer[i];
        i = i + 1;
    } while (i < HALF_BYTES);

    i = 0;
    do {
        if (hdcp_tx_result_block[i] != hdcp_tx_work_block[i]) {
            *(unsigned int *)(hdcp_tx_records + port * RECORD_SIZE) =
                (*(unsigned int *)(hdcp_tx_records + port * RECORD_SIZE) & ~STEP_RESULT_MASK) | STEP_OTHER_BITS;
            break;
        }
        i = i + 1;
    } while (i < BLOCK_BYTES);
}
