/* DRV_HDMI21_RXDetect_FSM_LTS_2  (DRV_HDMI21_RXDetect_FSM_LTS_2)
 *
 * Run link training state 2 of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: proven - original name printed through the state name table; next state 7 (no FRL) or 3
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI21_RXDetect_FSM_LTS_2 @ 0xa0098330, flags -mcpu=v8 -Os -g.
 * Source form: the records are addressed through two separate local pointers (one shared pointer or
 * inline indexing reorders the multiply and add). The print takes three arguments (format, name, port).
 */
#define HDMI_MSG_HDMI21 0x800   /* debug message bit: '[HDMI21]' lines (dbg_hdmi_message_flags) */
#define LTS_LAST_STATE_WORD 0xc   /* word +0x30 of the 0xb0-byte link-training record: state last reported */
#define BLOCK6_WORD 6             /* word +0x18 of the 0x34-byte register-block row: block 6 */
#define B6_LANE_REQ_01 0xa0       /* register of block 6 */
#define B6_LANE_REQ_01_BIT 0x16

/* States of the HDMI 2.1 receive state machine (index into hdmi_rx21_rx_detect_state_handlers). */
enum {
    RX_DETECT_LTS_2 = 2,
    RX_DETECT_LTS_3 = 3,
    RX_DETECT_LTS_L = 7
};

extern unsigned int dbg_hdmi_message_flags;
extern unsigned int hdmi_rx21_rx_detect_states[];
extern unsigned char hdmi_rx21_lts_records[];
extern unsigned char hdmi_rx21_reg_blocks[];
extern int dbg_printf(const char *, ...);
extern int hdmi_rx21_frl_rate_is_zero(unsigned int);
extern void reg_set_bit(unsigned int, int);

/* Link training state 2: sets bit 22 of register 0xa0 in register block 6 of the receiver, then
 * goes to state 7 when the FRL rate the source requests is 0, otherwise to state 3 (LTS_3). Prints its name
 * and the port when the state differs from the last state reported for this receiver.
 *   port: HDMI 2.1 receiver 0 or 1
 * Returns 0. */
unsigned int DRV_HDMI21_RXDetect_FSM_LTS_2(unsigned char port)
{
    unsigned int *rec;          /* link-training record of this receiver */
    unsigned int *blocks;       /* register-block row of this receiver */

    rec = (unsigned int *)(hdmi_rx21_lts_records + port * 0xb0);
    if (hdmi_rx21_rx_detect_states[port] != rec[LTS_LAST_STATE_WORD]) {
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21) {
            dbg_printf("[HDMI21]: \033[1m=%s, Port ID = %d=\n\033[m", "DRV_HDMI21_RXDetect_FSM_LTS_2", port);
        }
        rec[LTS_LAST_STATE_WORD] = hdmi_rx21_rx_detect_states[port];
    }

    blocks = (unsigned int *)(hdmi_rx21_reg_blocks + port * 0x34);
    reg_set_bit(B6_LANE_REQ_01_BIT, blocks[BLOCK6_WORD] + B6_LANE_REQ_01);
    if (hdmi_rx21_frl_rate_is_zero(port) & 0xff) {
        hdmi_rx21_rx_detect_states[port] = RX_DETECT_LTS_L;
    } else {
        hdmi_rx21_rx_detect_states[port] = RX_DETECT_LTS_3;
    }
    return 0;
}
