/* DRV_HDMI_EQScan_FSM_Done  (DRV_HDMI_EQScan_FSM_Done)
 *
 * EQ scan step: store the final modes, enable BCH and print the EQ exit message.
 *   port: PHY
 * Note: State function of the EQ scan table run by hdmi_eq_run_scan_fsm.
 * Name basis: proven - original name printed: 'DRV_HDMI_EQScan_FSM_Done'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_EQScan_FSM_Done @ 0xa007f670, flags -mcpu=v8 -Os -g.
 * Source form: the receiver index k = port & 1 is taken from an unsigned int copy of the port (a direct
 * 'port & 1' folds the byte mask away); the first format string is a separate symbol (it is not next to
 * the other two in the firmware).
 */
#define HDMI_MSG_EQ_FLOW 2      /* debug message bit: '[EQ]' lines (dbg_hdmi_message_flags) */

/* Entry of hdmi_phy_records: one per HDMI PHY (24 bytes). */
struct hdmi_phy_record {
    unsigned char bytes_0x0_to_0x3[4];
    unsigned char clock_ratio_mode;     /* +4: result of hdmi_eq_get_clock_ratio_mode */
    unsigned char scramble_mode;        /* +5: result of hdmi_eq_get_scramble_mode */
    unsigned char bytes_0x6_to_0x17[0x18 - 6];
};
/* Entry of hdmi_rx21_reg_blocks: register block bases of one receiver (0x34 bytes); block 3 is word 3. */
struct rx21_reg_blocks { unsigned char pad[0xc]; unsigned int block3; unsigned char rest[0x34 - 0x10]; };
extern struct hdmi_phy_record hdmi_phy_records[];
extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern unsigned char hdmi_eq_error_mode_flags[];
extern unsigned char hdmi_eq_skew_fail_counts[];
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern unsigned char hdmi_eq_get_clock_ratio_mode(unsigned char);
extern unsigned char hdmi_eq_get_scramble_mode(unsigned char);
extern void reg_set_bit(unsigned int, unsigned int);
extern void hdmi_rx21_config_bch(unsigned int);
static const char fn_[] = "DRV_HDMI_EQScan_FSM_Done";

/* Last step of the equaliser scan: stores the clock-ratio and scramble modes in the PHY's record,
 * sets bit 11 of register 0x7c in register block 3 of the receiver, calls hdmi_rx21_config_bch, clears
 * the PHY's error-handling flag (printing "Error Handing Occur!!" if it was 1) and its pass count.
 *   port: PHY index (the letter in the prints is 'A' + port)
 * Returns 0. */
int DRV_HDMI_EQScan_FSM_Done(unsigned char port)
{
    unsigned int pi = port;
    unsigned char k = pi & 1;   /* receiver number */

    if (dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW)
        dbg_printf("[EQ]: \033[1m%s: Port%c\n\033[m", fn_, (char)(port + 'A'));
    hdmi_phy_records[port].clock_ratio_mode = hdmi_eq_get_clock_ratio_mode(port);
    hdmi_phy_records[port].scramble_mode = hdmi_eq_get_scramble_mode(port);
    reg_set_bit(0xb, hdmi_rx21_reg_blocks[k].block3 + 0x7c);
    hdmi_rx21_config_bch(port);
    if (hdmi_eq_error_mode_flags[port] == 1) {
        hdmi_eq_error_mode_flags[port] = 0;
        if (dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW)
            dbg_printf("[EQ]: \x1b[1mPort%c : Error Handing Occur!!\n\x1b[m", (char)(port + 'A'));
    }
    if (dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW)
        dbg_printf("[EQ]: \x1b[32;1m# Port%c %s (EXIT)\n\x1b[m", (char)(port + 'A'), fn_);
    hdmi_eq_skew_fail_counts[port] = 0;
    return 0;
}
