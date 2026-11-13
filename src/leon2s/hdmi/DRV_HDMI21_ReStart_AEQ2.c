/* DRV_HDMI21_ReStart_AEQ2  (DRV_HDMI21_ReStart_AEQ2)
 *
 * Restart adaptive equalisation of the HDMI 2.1 lanes for the current link rate.
 *   port: PHY
 * Name basis: proven - original name printed: 'DRV_HDMI21_ReStart_AEQ2'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI21_ReStart_AEQ2 @ 0xa007fde0-0xa007fffc (including the ret/restore tail), flags -mcpu=v8 -Os -g
 * (section default).
 * Source forms the exact build depends on:
 *  - the receiver's PHY appears as an unsigned char copy p (PHY test), as 'phy & 0xff' (the first
 *    hdmi_phy_switch_channel_bit21 call and the lane writes) and as a later unsigned char copy q;
 *  - the rate test and the lane mask test are two nested ifs, not one condition;
 *  - the last call FUN_a007f7c8 is a sibling call.
 */
#define PHY_RX21_0 2                    /* PHY index of HDMI 2.1 receiver 0 (receiver 1 is 3) */
#define HDMI_MSG_HDMI21 0x800           /* debug flag bit 11: the "[HDMI21]" lines */

#define FRL_RATE_FIRST      4           /* link rates 4..6 take the per-lane PHY writes */
#define B0_CONTROL_4        4           /* register block 0, byte offset; bit 8 is pulsed here */
#define PHY_REG_LANE_01     0x360c      /* PHY register: one 16-bit half per lane, lanes 0 and 1 */
#define PHY_REG_LANE_23     0x3610      /* lanes 2 and 3 */
#define LANE_VALUE          0x3d0       /* written to the lane's half of those registers */

/* Register block 0 address of an HDMI 2.1 receiver (first word of a row of the 13-word table at 0xA807DB00). */
struct hdmi_rx21_reg_blocks { unsigned int block0; unsigned char block1_12[0x34 - 4]; };
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned char hdmi_rx21_lts_records[][0xb0];      /* link training records: +1 frl_rate, +0x34 = 1 when frl_rate >= 4 */
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern void DRV_HDMI21_LMS_To_EQ(unsigned char);
extern void hdmi_phy_switch_channel_bit21(unsigned char port, unsigned char on, unsigned char mode);
extern void hdmi_phy_update_reg(unsigned char, unsigned short, unsigned int, unsigned int);
extern void reg_set_bit(unsigned int, unsigned int);
extern void reg_clear_bit(unsigned int, unsigned int);
extern void timer_delay_long_units(unsigned int);
extern void hdmi_rx21_setup_lanes_all(unsigned char);
extern void hdmi_rx21_set_lane_bit7_all(unsigned char);
extern void DRV_HDMI21_Print_SCDC_Error(unsigned char);
extern void hdmi_rx21_clear_lane_bit7_all(unsigned char);
extern void hdmi_rx21_print_lane_rct(unsigned char);
extern void DRV_HDMI21_IQ_Scan_byCED(unsigned char);        /* DRV_HDMI21_IQ_Scan_byCED */
extern void hdmi_rx21_set_lane_ctrl_all(unsigned char);
extern void hdmi_rx21_clear_lane_ctrl_all(unsigned char);
static const char fn_[] = "DRV_HDMI21_ReStart_AEQ2";

/*
 * Restart the adaptive equalisation of an HDMI 2.1 receiver for its current FRL rate.
 *
 *   phy        PHY of the receiver: 2 or 3 (HDMI 2.1 receiver 0 or 1). Any other value returns at once.
 *   lane_mask  bit per lane (bit 0 = lane 0): lanes whose PHY setting is rewritten; used for FRL rates 4..6 only
 *   full       not 0: after the restart also run the lane set-up with two SCDC error prints around it
 *
 * Called from DRV_HDMI21_RXDetect_FSM_LTS_P with lane_mask 0 and full 1.
 *
 * In order: for a record with byte 0x34 set (FRL rate 4 or more) call FUN_a0079f80; hdmi_phy_switch_channel_bit21
 * on; for FRL rate 4..6 each lane of lane_mask gets the value 0x3D0 in its half of PHY register 0x360C (lanes
 * 0, 1) or 0x3610 (lanes 2, 3); hdmi_phy_switch_channel_bit21 off; bit 8 of B0_CONTROL_4 is set and, after a
 * wait, cleared. Without byte 0x34 that is all. With it the lane set-up follows
 * (hdmi_rx21_setup_lanes_all, hdmi_rx21_set_lane_bit7_all); with full this is followed by: print the SCDC
 * errors, hdmi_rx21_clear_lane_bit7_all, FUN_a007f7c8, DRV_HDMI21_IQ_Scan_byCED, set the lane control
 * (hdmi_rx21_set_lane_ctrl_all), wait, clear it, print the SCDC errors again. The last call is FUN_a007f7c8.
 */
void DRV_HDMI21_ReStart_AEQ2(unsigned int phy, unsigned char lane_mask, unsigned char full)
{
    unsigned char p = phy;
    unsigned char rx;                   /* receiver 0 or 1 */
    unsigned char rate;
    unsigned char i;
    unsigned char q;

    if (p == PHY_RX21_0)
        rx = 0;
    else if (p == PHY_RX21_0 + 1)
        rx = 1;
    else
        return;
    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
        dbg_printf("[HDMI21]: \x1b[1m=%s=\n\x1b[m", fn_);
    rate = hdmi_rx21_lts_records[rx][1];
    if (hdmi_rx21_lts_records[rx][0x34])
        DRV_HDMI21_LMS_To_EQ(p);
    hdmi_phy_switch_channel_bit21(phy & 0xff, 1, 1);
    if ((unsigned char)(rate - FRL_RATE_FIRST) <= 2)
    if (lane_mask) {
        for (i = 0; i <= 3; i++) {
            if ((lane_mask >> i) & 1) {
                if (i == 0)
                    hdmi_phy_update_reg(phy & 0xff, PHY_REG_LANE_01, 0xffff0000, LANE_VALUE);
                else if (i == 1)
                    hdmi_phy_update_reg(phy & 0xff, PHY_REG_LANE_01, 0xffff, LANE_VALUE << 16);
                else if (i == 2)
                    hdmi_phy_update_reg(phy & 0xff, PHY_REG_LANE_23, 0xffff0000, LANE_VALUE);
                else
                    hdmi_phy_update_reg(phy & 0xff, PHY_REG_LANE_23, 0xffff, LANE_VALUE << 16);
            }
        }
    }
    q = phy;
    hdmi_phy_switch_channel_bit21(q, 0, 1);
    reg_set_bit(8, ARR_a807db00[rx].block0 + B0_CONTROL_4);
    timer_delay_long_units(1);
    reg_clear_bit(8, ARR_a807db00[rx].block0 + B0_CONTROL_4);
    if (hdmi_rx21_lts_records[rx][0x34] == 0)
        return;
    hdmi_rx21_setup_lanes_all(q);
    hdmi_rx21_set_lane_bit7_all(q);
    if (full) {
        DRV_HDMI21_Print_SCDC_Error(q);
        hdmi_rx21_clear_lane_bit7_all(q);
        hdmi_rx21_print_lane_rct(q);
        DRV_HDMI21_IQ_Scan_byCED(q);
        hdmi_rx21_set_lane_ctrl_all(q);
        timer_delay_long_units(1);
        hdmi_rx21_clear_lane_ctrl_all(q);
        DRV_HDMI21_Print_SCDC_Error(q);
    }
    hdmi_rx21_print_lane_rct(q);
}
