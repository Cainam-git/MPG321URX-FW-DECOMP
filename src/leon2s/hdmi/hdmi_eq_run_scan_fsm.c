/* hdmi_eq_run_scan_fsm  (FSM_EQSCAN_DONE)
 *
 * Run the EQ scan state machine of a port until a step waits, then report the result.
 *   port: PHY
 * Note: The old label is the final state's name, not the routine's.
 * Name basis: proven - calls the state table of DRV_HDMI_EQScan_FSM_* steps; prints 'finish FSM_EQSCAN_DONE'
 *   and the RVGA lines
 *
 * Matching notes
 * --------------
 * leon2s FSM_EQSCAN_DONE @ 0xa0079460, flags -mcpu=v8 -Os -g.
 * The old label is the name of the final state, not of the routine; the routine is named
 * hdmi_eq_run_scan_fsm.
 */
#define EQSCAN_STATE_DONE 0x10      /* last state of hdmi_eq_scan_state_handlers */
#define RVGA_INDEX_CH0 9            /* bytes +9, +0xa, +0xb of hdmi_eq_port_records[port]: RVGA index of channel 0..2 */

/* Entry of hdmi_phy_records: one per HDMI PHY (24 bytes). */
struct hdmi_phy_record {
    unsigned char power;                /* +0 */
    unsigned char eq_done;              /* +1: set to 1 here when the scan has reached its last state */
    unsigned char bytes_0x2_to_0x5[4];
    unsigned char byte_0x6;             /* must be 1 for the scan to run */
    unsigned char bytes_0x7_to_0x17[0x18 - 7];
};
/* EQ scan record of one PHY (12 bytes, hdmi_eq_scan_records). */
struct eq_scan_record { unsigned int state; unsigned int word_0x4; unsigned char byte_0x8; unsigned char pad[3]; };
extern struct hdmi_phy_record hdmi_phy_records[];
extern struct eq_scan_record hdmi_eq_scan_records[];
extern unsigned char hdmi_eq_port_records[][0x898];
extern unsigned char (*const hdmi_eq_scan_state_handlers[])(unsigned char);
extern const unsigned char hdmi_eq_rvga_values[];
extern int dbg_printf(const char *, ...);
extern unsigned int hdmi_phy_clock_in_range(unsigned char);
extern unsigned int hdmi_rx21_read_frl_rate(unsigned char);
extern void hdmi_eq_monitor_errors(unsigned char, unsigned char);

/* Runs the equaliser scan of a PHY. It does nothing unless the clock is in range
 * (hdmi_phy_clock_in_range), the lane field (hdmi_rx21_read_frl_rate) is 0 and byte +6 of the PHY
 * record is 1. Then it calls the handler of the current state (hdmi_eq_scan_state_handlers[state]) again
 * and again until one returns 0. When the scan then stands in its last state (0x10) it prints
 * "finish FSM_EQSCAN_DONE", calls hdmi_eq_monitor_errors(port, 1), prints the RVGA index and value of
 * the three channels and sets the PHY's eq_done byte.
 *   port: PHY index (the letter in the prints is 'A' + port) */
void hdmi_eq_run_scan_fsm(unsigned char port)
{
    if ((unsigned char)hdmi_phy_clock_in_range(port) != 1)
        return;
    if ((unsigned char)hdmi_rx21_read_frl_rate(port))
        return;
    if (hdmi_phy_records[port].byte_0x6 != 1)
        return;
    while (hdmi_eq_scan_state_handlers[hdmi_eq_scan_records[port].state](port))
        ;
    if (hdmi_eq_scan_records[port].state != EQSCAN_STATE_DONE)
        return;
    dbg_printf("finish FSM_EQSCAN_DONE %d\r\n", 99);
    hdmi_eq_monitor_errors(port, 1);
    dbg_printf("Port%c, CH0, RVGA_Idx = %d, RVGA_Value = 0x%02x\n", (char)(port + 'A'), hdmi_eq_port_records[port][RVGA_INDEX_CH0], hdmi_eq_rvga_values[hdmi_eq_port_records[port][RVGA_INDEX_CH0]]);
    dbg_printf("Port%c, CH1, RVGA_Idx = %d, RVGA_Value = 0x%02x\n", (char)(port + 'A'), hdmi_eq_port_records[port][RVGA_INDEX_CH0 + 1], hdmi_eq_rvga_values[hdmi_eq_port_records[port][RVGA_INDEX_CH0 + 1]]);
    dbg_printf("Port%c, CH2, RVGA_Idx = %d, RVGA_Value = 0x%02x\n", (char)(port + 'A'), hdmi_eq_port_records[port][RVGA_INDEX_CH0 + 2], hdmi_eq_rvga_values[hdmi_eq_port_records[port][RVGA_INDEX_CH0 + 2]]);
    hdmi_phy_records[port].eq_done = 1;
}
