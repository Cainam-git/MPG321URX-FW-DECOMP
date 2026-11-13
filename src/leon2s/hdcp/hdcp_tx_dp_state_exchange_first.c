/* hdcp_tx_dp_state_exchange_first  (FUN_a00ce66c)
 *
 * State handler: read a block over AUX, start an engine step and store its result (first form).
 * Name basis: descriptive - one state handler of the per-port copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_dp_run_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ce66c @ 0xa00ce66c-0xa00ce864, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: word 0 of the record is handled as a whole word (hdcp_tx_records is an
 * unsigned int array, 6 words per record, index port * 6) and the parameter is masked with 0xff first; the last
 * loop writes to a 5-byte array at +0xa of hdcp_tx_ksv_table (see the comment at the loop). The register reads
 * are int-returning, cast to unsigned char at the store.
 */
extern unsigned int hdcp_tx_records[];
extern unsigned char hdcp_tx_receiver_ids[];
struct ksv_table_head { unsigned char pad[0xa]; unsigned char row_2[5]; };    /* row 2 of hdcp_tx_ksv_table */
extern struct ksv_table_head hdcp_tx_ksv_table;
extern int hdcp_tx_reg_write(unsigned char, unsigned char, unsigned char);
extern int hdcp_tx_reg_read(unsigned char, unsigned char);
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern int dp_tx_aux_request_copy(int, int, int, int, unsigned char *);

#define RECORD_WORDS            6       /* a record is 24 bytes = 6 words */
#define STEP_RESULT_SHIFT       16
#define STEP_RESULT_MASK        (3 << STEP_RESULT_SHIFT)        /* word 0 bits 16..17: STEP_BACK 0 .. STEP_AGAIN 3 */
#define STEP_NEXT_BITS          (1 << STEP_RESULT_SHIFT)
#define STEP_AGAIN_BITS         (3 << STEP_RESULT_SHIFT)
#define AUX_CMD_READ            0x90
#define AUX_RXSTATUS            0x69493     /* one byte; bit 2 must be set to go on */
#define AUX_BLOCK               0x692e0     /* 16 bytes read here */
#define RXSTATUS_BIT2           4
#define BLOCK_BYTES             16
#define HALF_BYTES              8
#define PROT_REG_DATA           1           /* protection block register: bytes to and from the engine */
#define KSV_LENGTH              5

/*
 * State 0x46 of the DisplayPort output: when the receiver reports it is ready, collect 16 bytes from the engine,
 * send the engine 16 bytes read from the receiver and the 16 collected ones, and keep the output's receiver id.
 *
 *   port  the output, 2
 *
 * Called by hdcp_tx_dp_run_state in state 0x46. It reports through step_result (STEP_*), written on word 0 of
 * the record as a whole.
 *
 *   1. step_result = STEP_NEXT.
 *   2. Read the byte at AUX 0x69493 (channel 0). Bit 2 clear gives STEP_AGAIN and ends the routine.
 *   3. Read 16 bytes at AUX 0x692E0. Engine command 1 (length 0x8000) and 8 bytes read from register 1 of the
 *      output's protection block, then command 3 and 8 more: the 16 bytes go to a local buffer. Command 5
 *      follows, and the 16 bytes read over AUX are written to register 1, then the 16 bytes read from the engine.
 *   4. The 5 bytes of the output's row in hdcp_tx_receiver_ids are copied to row 2 of hdcp_tx_ksv_table (the
 *      row at +0xa is always written, whatever port is; port is 2 for this state machine).
 */
void hdcp_tx_dp_state_exchange_first(unsigned char port)
{
    unsigned char engine_bytes[BLOCK_BYTES];
    unsigned char receiver_bytes[BLOCK_BYTES];
    unsigned short i;
    unsigned int idx;

    port = port & 0xff;
    idx = port * RECORD_WORDS;
    hdcp_tx_records[idx] = (hdcp_tx_records[idx] & ~STEP_RESULT_MASK) | STEP_NEXT_BITS;

    dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_RXSTATUS, 0, receiver_bytes);

    if ((receiver_bytes[0] & RXSTATUS_BIT2) == 0) {
        hdcp_tx_records[idx] = hdcp_tx_records[idx] | STEP_AGAIN_BITS;
    } else {
        dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_BLOCK, BLOCK_BYTES - 1, receiver_bytes);

        hdcp_tx_engine_start_command(port, 1, 0x8000);
        for (i = 0; i < HALF_BYTES; i++) {
            engine_bytes[i] = (unsigned char)hdcp_tx_reg_read(port, PROT_REG_DATA);
        }

        hdcp_tx_engine_start_command(port, 3, 0x8000);
        for (i = HALF_BYTES; i < BLOCK_BYTES; i++) {
            engine_bytes[i] = (unsigned char)hdcp_tx_reg_read(port, PROT_REG_DATA);
        }

        hdcp_tx_engine_start_command(port, 5, 0x8000);
        for (i = 0; i < BLOCK_BYTES; i++) {
            hdcp_tx_reg_write(port, PROT_REG_DATA, receiver_bytes[i]);
        }

        for (i = 0; i < BLOCK_BYTES; i++) {
            hdcp_tx_reg_write(port, PROT_REG_DATA, engine_bytes[i]);
        }

        for (i = 0; i < KSV_LENGTH; i++) {
            hdcp_tx_ksv_table.row_2[i] = hdcp_tx_receiver_ids[port * KSV_LENGTH + i];
        }
    }
}
