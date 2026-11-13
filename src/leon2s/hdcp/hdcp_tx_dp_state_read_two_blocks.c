/* hdcp_tx_dp_state_read_two_blocks  (FUN_a00cfb40)
 *
 * State handler: read 32 bytes over AUX (0x69473) and compare them with 32 bytes from the engine.
 * Note: Gives 'again' while timer 0xD is above 0x32; a difference gives result 2, or 0 when the counter word
 *   +0x10 is 0xFFFFFF.
 * Name basis: descriptive - one state handler of the per-port copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_dp_run_state; AUX reads of 16 bytes at 0x69473 and 0x69483, engine
 *   command 0xE
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cfb40 @ 0xa00cfb40-0xa00cfd38, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: word 0 and the word at +0x10 of the record are plain unsigned int
 * members (the record is a struct of words); the loops are do-while loops with unsigned short counters; the
 * second copy goes to hdcp_tx_work_block[i + 0x10]. Same layout as hdcp_tx_dp_state_exchange_third.
 */
#define STEP_RESULT_SHIFT   16
#define STEP_RESULT_MASK    (3 << STEP_RESULT_SHIFT)        /* word 0 bits 16..17: STEP_BACK 0 .. STEP_AGAIN 3 */
#define STEP_NEXT_BITS      (1 << STEP_RESULT_SHIFT)
#define STEP_OTHER_BITS     (2 << STEP_RESULT_SHIFT)
#define STEP_AGAIN_BITS     (3 << STEP_RESULT_SHIFT)
#define AUX_CMD_READ        0x90
#define AUX_FIRST_HALF      0x69473     /* 16 bytes: work block bytes 0..15 */
#define AUX_SECOND_HALF     0x69483     /* 16 bytes: work block bytes 16..31 */
#define HALF_BYTES          0x10
#define BLOCK_BYTES         0x20
#define TIMER_OUTPUT_2      0xd         /* hdcp_tx_get_timer number: output 2 + 0xb */
#define TIMER_LIMIT         0x32        /* ticks */
#define COUNTER_LIMIT       0xffffff    /* highest value of the 24-bit counter word_0x10 */
#define ENGINE_CMD_0E       0xe         /* hdcp_tx_engine_start_command code */
#define PROT_REG_DATA       1           /* protection block register: bytes from the engine */

/* Protection record of an output (24 bytes), as words: word 0 holds the bit-fields and state bytes. */
struct hdcp_tx_record_words {
    unsigned int word0;
    unsigned int words_0x4_0xc[3];
    unsigned int word_0x10;             /* 24-bit counter */
    unsigned int word_0x14;
};
extern struct hdcp_tx_record_words hdcp_tx_records[];
extern unsigned char hdcp_tx_result_block[];
extern unsigned char hdcp_tx_work_block[];
extern int hdcp_tx_reg_read(unsigned char, int);
extern void hdcp_tx_engine_start_command(unsigned char, int, unsigned short);
extern unsigned int hdcp_tx_get_timer(int);
extern int dp_tx_aux_request_copy(int, int, int, int, void *);

/*
 * State 0x4D of the DisplayPort output: read the receiver's 32-byte answer, read the engine's 32-byte result,
 * and report whether they are equal.
 *
 *   port_arg  the output, 2
 *
 * Called by hdcp_tx_dp_run_state in state 0x4D. It reports through step_result (STEP_*), written on word 0 of
 * the record as a whole.
 *
 *   1. step_result = STEP_NEXT. When timer 0xD of hdcp_tx_get_timer (the timer of output 2, port + 0xB) is
 *      above 0x32 ticks: STEP_AGAIN and the routine ends.
 *   2. Two 16-byte AUX reads (channel 0, 0x69473 and 0x69483) fill hdcp_tx_work_block.
 *   3. Engine command 0x0E (length 0x8000); 32 bytes read from register 1 of the output's protection block go
 *      to hdcp_tx_result_block.
 *   4. At the first byte where the two blocks differ: STEP_BACK when the record's counter word_0x10 is
 *      0xFFFFFF, else STEP_OTHER.
 */
void hdcp_tx_dp_state_read_two_blocks(unsigned char port_arg)
{
    unsigned char port;
    unsigned short i;
    unsigned char answer[HALF_BYTES];

    port = port_arg & 0xff;
    hdcp_tx_records[port].word0 =
        (hdcp_tx_records[port].word0 & ~STEP_RESULT_MASK) | STEP_NEXT_BITS;

    if (hdcp_tx_get_timer(TIMER_OUTPUT_2) > TIMER_LIMIT) {
        hdcp_tx_records[port].word0 |= STEP_AGAIN_BITS;
        return;
    }

    dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_FIRST_HALF, HALF_BYTES - 1, answer);

    i = 0;
    do {
        hdcp_tx_work_block[i] = answer[i];
        i = i + 1;
    } while (i < HALF_BYTES);

    dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_SECOND_HALF, HALF_BYTES - 1, answer);

    i = 0;
    do {
        hdcp_tx_work_block[i + HALF_BYTES] = answer[i];
        i = i + 1;
    } while (i < HALF_BYTES);

    hdcp_tx_engine_start_command(port, ENGINE_CMD_0E, 0x8000);

    i = 0;
    do {
        hdcp_tx_result_block[i] = (unsigned char)hdcp_tx_reg_read(port, PROT_REG_DATA);
        i = i + 1;
    } while (i < BLOCK_BYTES);

    i = 0;
    do {
        if (hdcp_tx_result_block[i] != hdcp_tx_work_block[i]) {
            if (hdcp_tx_records[port].word_0x10 == COUNTER_LIMIT)
                hdcp_tx_records[port].word0 &= ~STEP_RESULT_MASK;
            else
                hdcp_tx_records[port].word0 =
                    (hdcp_tx_records[port].word0 & ~STEP_RESULT_MASK) | STEP_OTHER_BITS;
            break;
        }
        i = i + 1;
    } while (i < BLOCK_BYTES);
}
