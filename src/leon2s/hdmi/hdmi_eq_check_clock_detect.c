/* hdmi_eq_check_clock_detect  (EQ_handler_3)
 *
 * Restart the EQ flow of a port when its clock-detect state changes.
 *   port: PHY
 * Note: The old label is not printed by the firmware.
 * Name basis: proven - prints 'CDKT Chg State To %d. Restart EQ Flow', 'CLK unstable1. Clean u8EQDone'
 *
 * Matching notes
 * --------------
 * leon2s EQ_handler_3 @ 0xa007afdc-0xa007b2a0 (708 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - port is an unsigned int parameter (raw in the index arithmetic, masked per call);
 *  - rx is initialised at its declaration;
 *  - hdmi_eq_scan_records is an array of {state, word_0x4, byte_0x8} records as in
 *    DRV_HDMI_EQScan_FSM_PHY_PreAEQ;
 *  - the independent stores are written in the firmware's order, and the clock-detect bit is read a second
 *    time for the stored value and a third time for the print.
 */
/* HDMI PHY record (24 bytes per PHY, table at 0xA807CC64). */
struct hdmi_phy_record {
    unsigned char power;                /* +0 */
    unsigned char eq_done;              /* +1: 1 = equaliser finished */
    unsigned char eq_reset_request;     /* +2 */
    unsigned char clock_detect;         /* +3: bit 28 of PHY register 0x1C04 as seen by this routine last time */
    unsigned char bytes_0x4[3];
    unsigned char option;               /* +7: set by mailbox command 0x15 */
    unsigned char bytes_0x8[0x18 - 8];
};
/* The fields of the link training record (0xB0 bytes per HDMI 2.1 receiver) used here. */
struct hdmi_rx21_lts_record {
    unsigned char lane_count;           /* +0 */
    unsigned char frl_rate;             /* +1: FRL rate taken over by hdmi_rx21_update_frl_rate */
    unsigned char bytes_0x2[0xb0 - 2];
};
extern struct hdmi_phy_record hdmi_phy_records[];
/* The scan state of one port (12 bytes per port, table at 0xA807CCC4). */
struct eq_scan_record {
    unsigned int state;                 /* index into hdmi_eq_scan_state_handlers; 0 = start the scan again */
    unsigned int word_0x4;
    unsigned char byte_0x8;
    unsigned char pad[3];
};
extern struct eq_scan_record hdmi_eq_scan_records[];
extern unsigned char hdmi_eq_port_records[][0x898];
extern struct hdmi_rx21_lts_record hdmi_rx21_lts_records[];
extern unsigned char hdmi_eq_tmds_bit_ratio_guess[];
extern unsigned char hdmi_eq_keep_results_flags[];
extern unsigned char hdmi_eq_saved_bit_ratio[];
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern int hdmi_phy_clock_changed(unsigned char);
extern unsigned int hdmi_phy_test_bit(unsigned int, unsigned char, unsigned short);
extern void hdmi_rx21_set_frl_clock_wrapper(unsigned char, unsigned char);
extern unsigned char hdmi_scdc_bit_ratio_40(unsigned char);

#define HDMI_MSG_EQ_FLOW        2       /* bit of dbg_hdmi_message_flags: the "[EQ]" lines */
#define EQSCAN_STATE_PHY_INIT   0       /* first state of hdmi_eq_scan_state_handlers */
#define PHY_REG_1C04            0x1c04
#define CLOCK_DETECT_BIT        0x1c    /* clock-detect bit of PHY register 0x1C04 */
#define PHY_REG_3600            0x3600  /* bit 0 tested before the receiver clock is set */
#define PHY_RX21_0              2       /* PHY 2 = HDMI 2.1 receiver 0 */
#define WORK_BYTE_0x37          0x37    /* byte of the 0x898-byte scan work record, set to 1 on a restart */
#define LINE_CLOCK_UNSTABLE1    0x2b1   /* number printed with "CLK unstable1" */

/*
 * Follows the clock-detect bit of a PHY and restarts its equaliser flow when it changes or the clock moves.
 *   port: PHY index (the letter in the prints is 'A' + port)
 * In order:
 *  1. The clock-detect bit (bit 28 of PHY register 0x1C04) differs from the one kept in the PHY record:
 *     if the old value was set, set hdmi_eq_tmds_bit_ratio_guess[port]; keep the new value; start the scan again
 *     (state PHY_INIT), set byte 0x37 of the scan work record and clear eq_done. When the clock is now
 *     detected and bit 0 of PHY register 0x3600 is set, set the receiver clock for the FRL rate of the
 *     link-training record (receiver 0 for PHY 2, receiver 1 otherwise). Print "CDKT Chg State To n.
 *     Restart EQ Flow"; with the clock detected and hdmi_phy_clock_changed true, clear the recheck flag
 *     and print "CLK unstable1. Clean u8EQDone".
 *  2. Unchanged bit, clock detected and hdmi_phy_clock_changed true: print "CLK unstable2. Restart EQ Flow"
 *     if eq_done was 1, then start the scan again and clear eq_done as in step 1.
 *  3. The SCDC bit-clock ratio (hdmi_scdc_bit_ratio_40) differs from the one saved in
 *     hdmi_eq_saved_bit_ratio and the PHY record's option byte is not 1: save the new ratio, start the scan
 *     again and clear eq_done.
 */
void hdmi_eq_check_clock_detect(unsigned int port)
{
    unsigned char rx = port != PHY_RX21_0;
    unsigned char clock_detect;

    if (hdmi_phy_records[port].clock_detect != (hdmi_phy_test_bit(CLOCK_DETECT_BIT, port, PHY_REG_1C04) != 0)) {
        if (hdmi_phy_records[port].clock_detect)
            hdmi_eq_tmds_bit_ratio_guess[port] = 1;
        clock_detect = hdmi_phy_test_bit(CLOCK_DETECT_BIT, port, PHY_REG_1C04) != 0;
        hdmi_phy_records[port].clock_detect = clock_detect;
        hdmi_eq_scan_records[port].state = EQSCAN_STATE_PHY_INIT;
        hdmi_eq_port_records[port][WORK_BYTE_0x37] = 1;
        hdmi_phy_records[port].eq_done = 0;
        if (clock_detect) {
            if (hdmi_phy_test_bit(0, port, PHY_REG_3600))
                hdmi_rx21_set_frl_clock_wrapper(rx, hdmi_rx21_lts_records[rx].frl_rate);
        }
        if (dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW)
            dbg_printf("[EQ]: \x1b[36;1m# Port%c CDKT Chg State To %d. Restart EQ Flow\n\x1b[m", (char)(port + 'A'),
                         hdmi_phy_test_bit(CLOCK_DETECT_BIT, port, PHY_REG_1C04) != 0);
        if (hdmi_phy_records[port].clock_detect && (unsigned char)hdmi_phy_clock_changed(port)) {
            hdmi_eq_keep_results_flags[port] = 0;
            if (dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW)
                dbg_printf("[EQ]: # Port%c CLK unstable1. Clean u8EQDone (%d)\n\n", (char)(port + 'A'), LINE_CLOCK_UNSTABLE1);
        }
    } else if (hdmi_phy_records[port].clock_detect && (unsigned char)hdmi_phy_clock_changed(port)) {
        if (hdmi_phy_records[port].eq_done == 1) {
            if (dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW)
                dbg_printf("[EQ]: # Port%c CLK unstable2. Restart EQ Flow\n", (char)(port + 'A'));
        }
        hdmi_phy_records[port].eq_done = 0;
        hdmi_eq_scan_records[port].state = EQSCAN_STATE_PHY_INIT;
        hdmi_eq_port_records[port][WORK_BYTE_0x37] = 1;
    }
    if (hdmi_eq_saved_bit_ratio[port] != hdmi_scdc_bit_ratio_40(port) && hdmi_phy_records[port].option != 1) {
        hdmi_eq_saved_bit_ratio[port] = hdmi_scdc_bit_ratio_40(port);
        hdmi_eq_scan_records[port].state = EQSCAN_STATE_PHY_INIT;
        hdmi_phy_records[port].eq_done = 0;
    }
}
