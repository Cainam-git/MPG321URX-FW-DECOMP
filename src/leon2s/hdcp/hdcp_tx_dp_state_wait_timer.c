/* hdcp_tx_dp_state_wait_timer  (FUN_a00d00e0)
 *
 * State handler: wait for a port timer, then switch two register bits.
 * Name basis: descriptive - one state handler of the per-port copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_dp_run_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d00e0 @ 0xa00d00e0-0xa00d01f4 (69 words), flags -mcpu=v8 -Os -g.
 * Source form: the 'timer != 0' arm comes first; word 0 of the record is handled as a whole; the three
 * 0xcf... control registers are volatile words. In the bit-0 arm 0xcf018d54 is set before 0xcf018ddc is cleared.
 */
/* Word 0 of a copy-protection record (24 bytes, array hdcp_tx_records), used as a whole. Its bits 16..17 are
   step_result, see struct hdcp_tx_record in hdcp_tx_task's sibling files. */
struct hdcp_tx_record_words {
    unsigned int word0;
    unsigned char rest[0x14];
};

#define STEP_RESULT_SHIFT       16
#define STEP_RESULT_MASK        (3 << STEP_RESULT_SHIFT)        /* word 0 bits 16..17 */
extern struct hdcp_tx_record_words hdcp_tx_records[];
extern int hdcp_tx_get_timer(unsigned int);
extern void dp_tx_reg_update_bits(unsigned char, unsigned int, unsigned int, unsigned int);
extern unsigned int dp_tx_ctl_reg_read8(unsigned int, unsigned int);

#define R(a) (*(volatile unsigned int *)(a))

#define STEP_NEXT               1
#define STEP_AGAIN              3
#define WORD0_BIT22             0x400000        /* bit 22 of word 0 */
#define TIMER_PORT_BASE         8               /* timer number = port + 8 */
#define REG_HDCP_TX_DP_CONTROL  0xcf018d00      /* reg_hdcp_tx_dp_control */
#define REG_CF018D54            0xcf018d54
#define REG_CF018DDC            0xcf018ddc
#define REG_CF018E50            0xcf018e50

/*
 * State 0x10 of hdcp_tx_dp_run_state: wait for the timer of the output, then switch some register bits.
 *
 * Sets step_result to STEP_NEXT. While timer port + 8 is not 0, step_result becomes STEP_AGAIN. When it has run
 * out, bit 22 of word 0 is cleared, bit 5 of register 0 of the output's block (dp_tx_reg_update_bits) is set and
 * cleared again, and the control registers are changed: with bit 0 of dp_tx_ctl_reg_read8(0, 6) set, bit 1 of
 * 0xcf018d54 is set and bit 0 of 0xcf018ddc is cleared, otherwise bit 1 of 0xcf018d54 is cleared; then bit 5 of
 * 0xcf018d54, bits 0 and 1 of 0xcf018d00 and bits 0 and 4 of 0xcf018e50 are cleared.
 */
void hdcp_tx_dp_state_wait_timer(unsigned char port)
{
    hdcp_tx_records[port].word0 = (hdcp_tx_records[port].word0 & ~STEP_RESULT_MASK) | (STEP_NEXT << STEP_RESULT_SHIFT);
    if (hdcp_tx_get_timer(port + TIMER_PORT_BASE) != 0) {
        hdcp_tx_records[port].word0 |= STEP_AGAIN << STEP_RESULT_SHIFT;
    } else {
        hdcp_tx_records[port].word0 &= ~WORD0_BIT22;
        dp_tx_reg_update_bits(port, 0, 0x20, 1);
        dp_tx_reg_update_bits(port, 0, 0x20, 0);
        if (dp_tx_ctl_reg_read8(0, 6) & 1) {
            R(REG_CF018D54) |= 2;
            R(REG_CF018DDC) &= ~1;
        } else {
            R(REG_CF018D54) &= ~2;
        }
        R(REG_CF018D54) &= ~0x20;
        R(REG_HDCP_TX_DP_CONTROL) &= ~3;
        R(REG_CF018E50) &= ~0x11;
    }
}
