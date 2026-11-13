/* hdmi_rx21_force_mode_detect_standby  (MODEDET_handler)
 *
 * Send the mode detection of an HDMI 2.1 receiver back to state 0 (wait for EQ) if its EQ is not done.
 *   port: HDMI 2.1 receiver 0/1
 * Note: Label MODEDET_handler is not printed by the firmware. The printed text says 'StandBy', but the state
 *   set is 0, not the STANDBY state 5.
 * Name basis: proven - prints 'EQ Not Ready Force Back To StandBy', 'Sync Lost Alarm and Disable Interrupt'
 *
 * Matching notes
 * --------------
 * MODEDET_handler (leon2s 0xa009c8b0-0xa009c9b4, 260 bytes, including the ret/restore tail), flags -mcpu=v8 -Os -g
 * (section default). The parameter is an unsigned char; the firmware ends with a sibling call to
 * hdmi_rx21_clear_mode_status.
 */

/* Message groups of dbg_hdmi_message_flags. */
#define HDMI_MSG_MODEDET_FLOW   0x04

#define MODEDET_STATE_WAIT_EQ_END   0   /* hdmi_rx21_modedet_wait_eq_done */

/* PHY numbers of the two HDMI 2.1 receivers. */
#define PHY_RX21_0              2
#define PHY_RX21_1              3

#define RX21_RECORD_SIZE        400     /* bytes per receiver in hdmi_rx21_input_records */
#define RX21_MODE_DETECTED      1       /* record byte: set by DRV_HDMI_ModeDetect_FSM_Complete */

#define EVENTS_OFF              0       /* second argument of the two event routines */

/* Mode-detection state of one HDMI 2.1 receiver (24 bytes). */
struct rx21_mode_detect_state {
    unsigned int state;                 /* MODEDET_STATE_* */
    unsigned char pll_check_count;
    unsigned char _5[0x18 - 5];
};
/* HDMI PHY record (24 bytes per PHY, hdmi_phy_records). */
struct hdmi_phy_record {
    unsigned char power;
    unsigned char eq_done;              /* the EQ scan sets it at its end */
    unsigned char _2[0x18 - 2];
};
extern struct rx21_mode_detect_state hdmi_rx21_mode_detect_states[];
extern struct hdmi_phy_record hdmi_phy_records[];
extern unsigned char hdmi_rx21_input_records[];        /* HDMI 2.1 receiver records */
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern void hdmi_rx21_enable_sync_events(unsigned char, unsigned char);
extern void DRV_HDMI_Setup_IntIRQ_Events(unsigned int, unsigned int);
extern void hdmi_rx21_clear_mode_status(unsigned char);

/*
 * Put the mode detection of an HDMI 2.1 receiver back into state 0 (wait for EQ) when the EQ scan of its PHY
 * is no longer done.
 *
 *   port  HDMI 2.1 receiver 0 or 1 (printed as the letter 'A' + port); other values return at once
 *
 * Called by hdmi_rx21_run_mode_detect_fsm for each receiver before it runs the current state.
 *
 * Nothing happens while the state is already 0 or while eq_done of the PHY (2 for receiver 0, 3 for
 * receiver 1) is 1. Otherwise the state becomes 0; when a mode was detected, the sync events and the
 * interrupt events of the receiver are switched off ("Sync Lost Alarm and Disable Interrupt"); last the
 * detected-mode status is cleared (hdmi_rx21_clear_mode_status).
 */
void hdmi_rx21_force_mode_detect_standby(unsigned char port)
{
    unsigned char phy;

    if (port == 0)
        phy = PHY_RX21_0;
    else if (port == 1)
        phy = PHY_RX21_1;
    else
        return;
    if (hdmi_rx21_mode_detect_states[port].state == MODEDET_STATE_WAIT_EQ_END)
        return;
    if (hdmi_phy_records[phy].eq_done == 1)
        return;
    hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_WAIT_EQ_END;
    if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
        dbg_printf("[MODEDET]: Port%c EQ Not Ready Force Back To StandBy\n", (char)(port + 'A'));
    if (hdmi_rx21_input_records[port * RX21_RECORD_SIZE + RX21_MODE_DETECTED]) {
        hdmi_rx21_enable_sync_events(port, EVENTS_OFF);
        DRV_HDMI_Setup_IntIRQ_Events(port, EVENTS_OFF);
        if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
            dbg_printf("[MODEDET]: Port%c Sync Lost Alarm and Disable Interrupt\n", (char)(port + 'A'));
    }
    hdmi_rx21_clear_mode_status(port);
}
