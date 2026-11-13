/* hdcp_tx_dp_state_send_engine_result  (FUN_a00cf6bc)
 *
 * State handler: run an engine step and send its result over AUX.
 * Name basis: descriptive - one state handler of the per-port copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_dp_run_state
 *
 * Matching notes
 * --------------
 * FUN_a00cf6bc (leon2s, 0xa00cf6bc-0xa00cf7b4, 62 words). Flags -mcpu=v8 -Os -g.
 * Source form: the record word is a bit-field (bit 21 is tested with 'srl 0x15; btst 1'; a mask test gives
 * sethi/btst); the two AUX routines return int (void prototypes reorder the argument set-up).
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
extern unsigned char hdcp_tx_reg_read(unsigned char, unsigned short);
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern int dp_tx_aux_request(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);
extern int dp_tx_aux_request_copy(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);

#define AUX_CMD_READ            0x90    /* AUX command of the read */
#define AUX_CMD_WRITE           0x80    /* AUX command of the write */
#define AUX_ADDR_0x69493        0x69493
#define AUX_ADDR_0x693E0        0x693e0
#define AUX_ARG4_0xF            0xf     /* 4th argument of the write */
#define ENGINE_CMD_0C           0xc     /* engine command code, here with length 0x8000 */
#define RESULT_BYTES            16

/*
 * State 0x4B of hdcp_tx_dp_run_state: send 16 bytes from the protection engine to the receiver over AUX.
 *
 * Sets step_result to STEP_NEXT, reads AUX address 0x69493 (the byte is not used), starts engine command 0x0c
 * with length 0x8000 and reads 16 bytes one by one from register 1 of the output's protection block. The bytes
 * are written to AUX address 0x693e0. If bit 21 of the record's word 0 is set, step_result becomes STEP_OTHER.
 */
void hdcp_tx_dp_state_send_engine_result(unsigned char port)
{
    unsigned char buffer[RESULT_BYTES];
    unsigned short i;

    hdcp_tx_records[port].step_result = STEP_NEXT;
    dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_ADDR_0x69493, 0, buffer);
    hdcp_tx_engine_start_command(port, ENGINE_CMD_0C, 0x8000);
    i = 0;
    do {
        buffer[i] = hdcp_tx_reg_read(port, 1);
        i++;
    } while (i <= RESULT_BYTES - 1);
    dp_tx_aux_request(0, AUX_CMD_WRITE, AUX_ADDR_0x693E0, AUX_ARG4_0xF, buffer);
    if (hdcp_tx_records[port].b21)
        hdcp_tx_records[port].step_result = STEP_OTHER;
}
