/* hdmi_tx_check_timing  (FUN_a0094c54)
 *
 * Print the HDMI TX output timing, or report that the PSTABLE flag failed.
 *   port: HDMI TX port 0/1
 * Name basis: proven - prints 'HTOTAL = .., HDE = .., HSW, HFP', 'VTOTAL ..' and 'PSTABLE flag is failed';
 *   step (9)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0094c54 @ 0xa0094c54-0xa0094e40, -mcpu=v8 -Os -g.
 * Source form: the sixteen register values are unsigned char locals read in the order below (three live in the stack
 * frame); the PSTABLE failure text goes to dbg_print_string as a tail call.
 */
extern short hdmi_tx_reg_read8(unsigned int, unsigned short, unsigned short);
extern int dbg_printf(const char *, ...);
extern int dbg_print_string(const char *);

/*
 * Print the timing the transmitter reports, or say that its PSTABLE flag failed.
 *   port: HDMI TX port 0/1
 * All values are bank 0 registers read as byte pairs (low byte in the lower register, high byte in the next).
 * Register 9 bit 0 is the PSTABLE flag. With it set, two lines are printed, vertical then horizontal:
 *   total (0x3C/0x3D vertical, 0x3A/0x3B horizontal), DE (0x62/0x63, 0x60/0x61), SW (0x66/0x67, 0x64/0x65),
 *   FP (0x6A/0x6B, 0x68/0x69);
 * with it clear only 'PSTABLE flag is failed' is printed. The values are read in every case.
 * Called by hdmi_tx_run_setup_steps at step (9), 'Check PSTABLE/Timing'.
 */
void hdmi_tx_check_timing(unsigned char port)
{
    unsigned char vde_low, vde_high, vsw_low, vsw_high, vfp_low, vfp_high, vtotal_low, vtotal_high;
    unsigned char hde_low, hde_high, hsw_low, hsw_high, hfp_low, hfp_high, htotal_low, htotal_high;

    vde_low = hdmi_tx_reg_read8(port, 0, 0x62);
    vde_high = hdmi_tx_reg_read8(port, 0, 0x63);
    vsw_low = hdmi_tx_reg_read8(port, 0, 0x66);
    vsw_high = hdmi_tx_reg_read8(port, 0, 0x67);
    vfp_low = hdmi_tx_reg_read8(port, 0, 0x6a);
    vfp_high = hdmi_tx_reg_read8(port, 0, 0x6b);
    vtotal_low = hdmi_tx_reg_read8(port, 0, 0x3c);
    vtotal_high = hdmi_tx_reg_read8(port, 0, 0x3d);
    hde_low = hdmi_tx_reg_read8(port, 0, 0x60);
    hde_high = hdmi_tx_reg_read8(port, 0, 0x61);
    hsw_low = hdmi_tx_reg_read8(port, 0, 0x64);
    hsw_high = hdmi_tx_reg_read8(port, 0, 0x65);
    hfp_low = hdmi_tx_reg_read8(port, 0, 0x68);
    hfp_high = hdmi_tx_reg_read8(port, 0, 0x69);
    htotal_low = hdmi_tx_reg_read8(port, 0, 0x3a);
    htotal_high = hdmi_tx_reg_read8(port, 0, 0x3b);
    if (hdmi_tx_reg_read8(port, 0, 9) & 1) {
        dbg_printf("\x1b[0m\t\t - VTOTAL = 0x%02x%02x, VDE = 0x%02x%02x, VSW = 0x%02x%02x, VFP = 0x%02x%02x \n",
                     vtotal_high, vtotal_low, vde_high, vde_low, vsw_high, vsw_low, vfp_high, vfp_low);
        dbg_printf("\x1b[0m\t\t - HTOTAL = 0x%02x%02x, HDE = 0x%02x%02x, HSW = 0x%02x%02x, HFP = 0x%02x%02x \n",
                     htotal_high, htotal_low, hde_high, hde_low, hsw_high, hsw_low, hfp_high, hfp_low);
    } else
        dbg_print_string("\x1b[0m\t\t - PSTABLE flag is failed \n");
}
