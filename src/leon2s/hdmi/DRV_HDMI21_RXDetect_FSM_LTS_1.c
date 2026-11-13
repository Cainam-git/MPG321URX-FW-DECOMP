/* DRV_HDMI21_RXDetect_FSM_LTS_1  (DRV_HDMI21_RXDetect_FSM_LTS_1)
 *
 * Run link training state 1 of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: proven - original name printed through the state name table ('=%s=')
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI21_RXDetect_FSM_LTS_1 @ 0xa0098240, flags -mcpu=v8 -Os -g.
 * Source form: the print strings are symbols; same form as the twin DRV_HDMI21_RXDetect_FSM_LTS_2
 * (record pointer plus state array).
 */
#define HDMI_MSG_HDMI21 0x800   /* debug message bit: '[HDMI21]' lines (dbg_hdmi_message_flags) */
#define LTS_LAST_STATE_WORD 0xc   /* word +0x30 of the 0xb0-byte link-training record: state last reported */
#define PHY_RECORD_SIZE 24        /* bytes per entry of hdmi_phy_records */
#define PHY_RECORD_BYTE_6 6

/* States of the HDMI 2.1 receive state machine (index into hdmi_rx21_rx_detect_state_handlers). */
enum {
    RX_DETECT_LTS_2 = 2,
    RX_DETECT_LTS_3 = 3,
    RX_DETECT_LTS_L = 7
};

extern unsigned int dbg_hdmi_message_flags;
extern unsigned int hdmi_rx21_rx_detect_states[];
extern unsigned char hdmi_rx21_lts_records[];
extern unsigned char hdmi_phy_records[];
extern char DAT_a0067868[];
extern int dbg_printf(const char *, ...);
extern unsigned char hdmi_rx21_get_phy_index(unsigned char);

/* Link training state 1: wait until byte +6 of the receiver's PHY record is 1 (the code prints
 * "RX2&3 H21 cable true" then), and move on to state 2. Prints its name when the state differs from the
 * last state reported for this receiver.
 *   port: HDMI 2.1 receiver 0 or 1
 * Returns 0. */
unsigned int DRV_HDMI21_RXDetect_FSM_LTS_1(unsigned char port)
{
    unsigned char phy_index;    /* entry of hdmi_phy_records that belongs to this receiver */
    unsigned int *rec;          /* link-training record of this receiver */

    phy_index = hdmi_rx21_get_phy_index(port);
    rec = (unsigned int *)(hdmi_rx21_lts_records + port * 0xb0);
    if (hdmi_rx21_rx_detect_states[port] != rec[LTS_LAST_STATE_WORD]) {
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_printf(DAT_a0067868, "DRV_HDMI21_RXDetect_FSM_LTS_1");
        rec[LTS_LAST_STATE_WORD] = hdmi_rx21_rx_detect_states[port];
    }
    if (hdmi_phy_records[phy_index * PHY_RECORD_SIZE + PHY_RECORD_BYTE_6] == 1) {
        dbg_printf("\033[31;1mRX2&3 H21 cable true\n\n\033[m");
        hdmi_rx21_rx_detect_states[port] = RX_DETECT_LTS_2;
    }
    return 0;
}
