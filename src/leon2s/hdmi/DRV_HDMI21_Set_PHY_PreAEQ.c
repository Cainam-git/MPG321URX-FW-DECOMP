/* DRV_HDMI21_Set_PHY_PreAEQ  (DRV_HDMI21_Set_PHY_PreAEQ)
 *
 * Write the pre-AEQ R/C values of the four HDMI 2.1 lanes and restart them.
 *   port: PHY
 * Name basis: proven - original name printed: 'DRV_HDMI21_Set_PHY_PreAEQ'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI21_Set_PHY_PreAEQ @ 0xa007fffc-0xa0080244 (including the ret/restore tail), flags -mcpu=v8 -Os -g
 * (section default).
 * Source forms the exact build depends on:
 *  - the PHY appears as an unsigned char copy p, as 'phy & 0xff' in the unsigned int q (first part, lane
 *    writes) and as a later unsigned char copy r;
 *  - the lane loop keeps the always-true 'if (i <= 3)' around the register write;
 *  - the routine name is a static const char array, not a string literal in the call.
 */
#define PHY_RX21_0 2                    /* PHY index of HDMI 2.1 receiver 0 (receiver 1 is 3) */
#define HDMI_MSG_HDMI21 0x800           /* debug flag bit 11: the "[HDMI21]" lines */

#define FRL_RATE_IN_PHY_FIRST 4         /* frl_rate_in_phy 4..6 take the FUN_a0079f80 call */
/* Lane EQ register (hdmi_rx21_lane_eq_regs): R value in bits 0..3, C value in bits 8..23; the other bits stay. */
#define LANE_EQ_KEEP_MASK   0xff0000f0
#define LANE_EQ_C_SHIFT     8

extern unsigned char hdmi_rx21_lts_records[][0xb0];      /* link training records: +2 frl_rate_in_phy, +0x34 = 1 when frl_rate >= 4 */
/* Per lane: index of the R value and of the C value written (0 or 1; set by DRV_HDMI21_RXDetect_FSM_LTS_Chk_SCDC_Err). */
extern unsigned char hdmi_rx21_pre_aeq_r_indexes[];     /* R index */
extern unsigned char hdmi_rx21_pre_aeq_c_indexes[];     /* C index */
extern unsigned int hdmi_rx21_initial_rct_values[];     /* the R values: 3, 8 */
extern unsigned int hdmi_rx21_initial_cft_values[];     /* the C values: 3, 0xff */
extern unsigned short hdmi_rx21_lane_eq_regs[4];        /* PHY register of each lane: 0x2178, 0x2578, 0x2978, 0x3178 */
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern const char DAT_a0067868[];               /* "[HDMI21]: =%s=" (bold) */
extern void DRV_HDMI21_LMS_To_EQ(unsigned char);
extern void hdmi_phy_switch_channel_bit21(unsigned char port, unsigned char on, unsigned char mode);
extern void hdmi_phy_update_reg(unsigned char, unsigned short, unsigned int, unsigned int);
extern void timer_delay_long_units(unsigned int);
extern void hdmi_rx21_setup_lanes_all(unsigned char);
extern void hdmi_rx21_set_lane_bit7_all(unsigned char);
extern void DRV_HDMI21_Print_SCDC_Error(unsigned char);
extern void hdmi_rx21_clear_lane_bit7_all(unsigned char);
extern void hdmi_rx21_print_lane_rct(unsigned char);
extern void DRV_HDMI21_IQ_Scan_byCED(unsigned char);        /* DRV_HDMI21_IQ_Scan_byCED */
extern void hdmi_rx21_set_lane_ctrl_all(unsigned char);
extern void hdmi_rx21_clear_lane_ctrl_all(unsigned char);
static const char fn_[] = "DRV_HDMI21_Set_PHY_PreAEQ";

/*
 * Write the pre-AEQ R and C values into the four lanes of an HDMI 2.1 receiver and restart the lanes.
 *
 *   phy   PHY of the receiver: 2 or 3 (HDMI 2.1 receiver 0 or 1). Any other value returns at once.
 *   full  not 0: also run the longer lane restart with two SCDC error prints (see below)
 *
 * Called from DRV_HDMI21_RXDetect_FSM_LTS_Chk_SCDC_Err, with full 1.
 *
 * In order: for frl_rate_in_phy 4..6 call FUN_a0079f80; hdmi_phy_switch_channel_bit21 on; for each of the four
 * lanes write the lane's R value (table entry hdmi_rx21_pre_aeq_r_indexes[lane]) and C value (entry
 * hdmi_rx21_pre_aeq_c_indexes[lane]) into its EQ register, with debug flag bit 11 set printing both first;
 * hdmi_phy_switch_channel_bit21 off; wait. A record without byte 0x34 ends here. Otherwise the lanes are set
 * up (hdmi_rx21_setup_lanes_all, hdmi_rx21_set_lane_bit7_all); with full this is followed by: print the SCDC
 * errors, hdmi_rx21_clear_lane_bit7_all, FUN_a007f7c8, DRV_HDMI21_IQ_Scan_byCED, set the lane control
 * (hdmi_rx21_set_lane_ctrl_all), wait, clear it, print the SCDC errors again. The last call is FUN_a007f7c8.
 * The same closing sequence is in DRV_HDMI21_ReStart_AEQ2.
 */
void DRV_HDMI21_Set_PHY_PreAEQ(unsigned int phy, unsigned char full)
{
    unsigned char p = phy;
    unsigned char rx;                   /* receiver 0 or 1 */
    unsigned int q;
    unsigned char i;
    unsigned char r;

    if (p == PHY_RX21_0)
        rx = 0;
    else if (p == PHY_RX21_0 + 1)
        rx = 1;
    else
        return;
    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
        dbg_printf(DAT_a0067868, fn_);
    if ((unsigned char)(hdmi_rx21_lts_records[rx][2] - FRL_RATE_IN_PHY_FIRST) <= 2)
        DRV_HDMI21_LMS_To_EQ(p);
    q = phy & 0xff;
    hdmi_phy_switch_channel_bit21(q, 1, 1);
    for (i = 0; i <= 3; i++) {
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_printf("[HDMI21]: ## jay debug ==> PreAEQ CH%d Set AEQ_R 0x%08lx ##\n", i, hdmi_rx21_initial_rct_values[hdmi_rx21_pre_aeq_r_indexes[i]]);
        if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
            dbg_printf("[HDMI21]: ## jay debug ==> PreAEQ CH%d Set AEQ_C 0x%08lx ##\n", i, hdmi_rx21_initial_cft_values[hdmi_rx21_pre_aeq_c_indexes[i]]);
        if (i <= 3)
            hdmi_phy_update_reg(q, hdmi_rx21_lane_eq_regs[i], LANE_EQ_KEEP_MASK,
                         (hdmi_rx21_initial_rct_values[hdmi_rx21_pre_aeq_r_indexes[i]] & 0xf) | ((hdmi_rx21_initial_cft_values[hdmi_rx21_pre_aeq_c_indexes[i]] & 0xffff) << LANE_EQ_C_SHIFT));
    }
    r = phy;
    hdmi_phy_switch_channel_bit21(r, 0, 1);
    timer_delay_long_units(1);
    if (hdmi_rx21_lts_records[rx][0x34] == 0)
        return;
    hdmi_rx21_setup_lanes_all(r);
    hdmi_rx21_set_lane_bit7_all(r);
    if (full) {
        DRV_HDMI21_Print_SCDC_Error(r);
        hdmi_rx21_clear_lane_bit7_all(r);
        hdmi_rx21_print_lane_rct(r);
        DRV_HDMI21_IQ_Scan_byCED(r);
        hdmi_rx21_set_lane_ctrl_all(r);
        timer_delay_long_units(1);
        hdmi_rx21_clear_lane_ctrl_all(r);
        DRV_HDMI21_Print_SCDC_Error(r);
    }
    hdmi_rx21_print_lane_rct(r);
}
