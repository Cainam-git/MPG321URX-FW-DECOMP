/* hdcp_tx_dp_state_check_link_bits  (FUN_a00cd4fc)
 *
 * State handler: check the link status of the DisplayPort output.
 * Name basis: descriptive - one state handler of the per-output copy-protection state machine; called from
 *   hdcp_tx_dp_run_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cd4fc @ 0xa00cd4fc-0xa00cd5e4 (58 words), flags -mcpu=v8 -Os -g.
 * Source form: the field is read as a 2-bit bit-field (the firmware loads the halfword); the arm with a failed
 * read ends with the store buf[0] = 0, which is kept.
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
extern unsigned char dp_tx_aux_read_byte(unsigned int, unsigned int, unsigned int, unsigned char *);
extern unsigned int dp_tx_reg_read8(unsigned char, unsigned int);
extern void dp_tx_reg_write8(unsigned char, unsigned int, unsigned int);

#define AUX_CMD_READ            0x90    /* AUX command of the read here */
#define AUX_ADDR_0x68029        0x68029
#define DP_REG_0x21             0x21    /* register of the DisplayPort output read and written below */
#define DP_REG_0x21_BIT7        0x80

/*
 * State 0x14 of hdcp_tx_dp_run_state: check bit 0 of the byte at AUX address 0x68029.
 *
 * Unless step_result is already STEP_OTHER, the byte is read; when the read fails (non-zero return) or bit 0 of
 * the byte is clear, step_result becomes STEP_AGAIN and the routine ends. Otherwise step_result becomes
 * STEP_NEXT, and if bit 7 of register 0x21 of the output is set, 0x80 is written back to that register.
 */
void hdcp_tx_dp_state_check_link_bits(unsigned char port)
{
    unsigned char byte_read[24];

    if (hdcp_tx_records[port].step_result != STEP_OTHER) {
        if (dp_tx_aux_read_byte(0, AUX_CMD_READ, AUX_ADDR_0x68029, byte_read) != 0) {
            hdcp_tx_records[port].step_result = STEP_AGAIN;
            byte_read[0] = 0;
            return;
        }
        if ((byte_read[0] & 1) == 0) {
            hdcp_tx_records[port].step_result = STEP_AGAIN;
            return;
        }
    }
    hdcp_tx_records[port].step_result = STEP_NEXT;
    if (dp_tx_reg_read8(port, DP_REG_0x21) & DP_REG_0x21_BIT7)
        dp_tx_reg_write8(port, DP_REG_0x21, DP_REG_0x21_BIT7);
}
