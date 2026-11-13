/* DRV_HDMI21_RX_SCDC_Chk_Err  (DRV_HDMI21_RX_SCDC_Chk_Err)
 *
 * Read the SCDC error counters of an HDMI 2.1 receiver and flag bad lanes.
 *   rx: HDMI 2.1 receiver 0/1
 * Returns: bit per lane over the limit
 * Name basis: proven - original name in the state name table; prints 'ch%d -OK- SCDC', 'u8Scdc_Error_Ch'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI21_RX_SCDC_Chk_Err @ 0xa0098bb0-0xa0098e88, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - a plain unsigned char parameter rx (not unsigned int) and a separate unsigned int phy;
 *  - the result variable is an unsigned char, which makes the early 'return 0' keep its own clear;
 *  - the routine name is a string literal in the call, the three result texts are the firmware constants
 *    DAT_a0069ce8 / DAT_a0069d20 / DAT_a0069d60;
 *  - the error count is printed as the expression 'err[lane] & 0x7fff', not a local, so GCC folds it to 0 in
 *    the '== 0x8000' arm.
 */
#define PHY_RX21_0 2                    /* PHY index of HDMI 2.1 receiver 0 (receiver 1 is 3) */
#define HDMI_MSG_HDMI21 0x800           /* debug flag bit 11: the "[HDMI21]" lines */

#define PHY_REG_2E60        0x2e60      /* PHY register: bit 20 set, bit 16 pulsed before the counts are read */
#define PHY_REG_SCDC_ERR_01 0x2e64      /* each half: valid flag in bit 15, SCDC error count in bits 0..14 (lane 0 / lane 1) */
#define PHY_REG_SCDC_ERR_23 0x2e68      /* same for lane 2 / lane 3 */
#define SCDC_ERR_VALID      0x8000      /* a raw half equal to this: valid, count 0 */
#define SCDC_ERR_LIMIT      0x801e      /* raw halves up to this are "-OK-", above it "-NG-" */

/* The fields of the link training record (0xB0 bytes, table at 0xA807D680) used here. */
struct hdmi_rx21_lts_record {
    unsigned char lane_count;           /* +0 */
    unsigned char pad_0x1[0x19];
    unsigned short scdc_error_counts[(0xb0 - 0x1a) / 2];  /* +0x1A: count of lane l and pre-AEQ R index r at [l * 2 + r] */
};
extern struct hdmi_rx21_lts_record hdmi_rx21_lts_records[];
/* Per lane: index of the pre-AEQ R value that DRV_HDMI21_Set_PHY_PreAEQ writes (0 or 1). */
extern unsigned char hdmi_rx21_pre_aeq_r_indexes[];
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern void hdmi_phy_write_bit(int mode, unsigned int bit, unsigned char phy, unsigned short reg);
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);
extern void timer_delay_units(unsigned int);
extern void timer_delay_long_units(unsigned int);
extern const char DAT_a0067868[];               /* "[HDMI21]: =%s=" (bold) */
extern const char DAT_a0069ce8[];               /* "Port%c , ch%d -OK- SCDC %ld" (green) */
extern const char DAT_a0069d20[];               /* "Port%c , ch%d -OK- SCDC 0x%04x < 0x1f" (red) */
extern const char DAT_a0069d60[];               /* "Port%c , ch%d -NG- SCDC 0x%04x > 0x1f" (red) */

/*
 * Read the SCDC error counts of the lanes of an HDMI 2.1 receiver, keep them in its link training record and
 * tell which lanes are over the limit.
 *
 *   rx  HDMI 2.1 receiver 0 or 1 (any other value returns 0 at once)
 *
 * Returns a bit per lane (bit 0 = lane 0): 1 for a lane whose raw count is above SCDC_ERR_LIMIT.
 *
 * Bit 20 and bit 16 of PHY register 0x2E60 are set, bit 16 is cleared again after a short wait, and after a
 * longer wait the counts of PHY_REG_SCDC_ERR_01 / _23 are read for as many lanes as the record gives
 * (lane_count). The low 15 bits of each lane's count go into scdc_error_counts[lane * 2 + R index], where the
 * R index is the lane's current pre-AEQ R index (the value DRV_HDMI21_Set_PHY_PreAEQ uses). A raw value of
 * SCDC_ERR_VALID (count 0) or up to SCDC_ERR_LIMIT is "-OK-", anything above is "-NG-" and sets the lane's bit
 * in the result. With debug flag bit 11 set each lane and the result "u8Scdc_Error_Ch" are printed.
 *
 * Called from DRV_HDMI21_RXDetect_FSM_LTS_Chk_SCDC_Err.
 */
unsigned char DRV_HDMI21_RX_SCDC_Chk_Err(unsigned char rx)
{
    unsigned int err[4] = {0, 0, 0, 0};         /* raw register halves, one per lane */
    unsigned int phy;                           /* PHY of the receiver: 2 or 3 */
    unsigned char bad_lanes = 0;
    unsigned char lane;

    if (rx == 0)
        phy = PHY_RX21_0;
    else if (rx == 1)
        phy = PHY_RX21_0 + 1;
    else
        return 0;
    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
        dbg_printf(DAT_a0067868, "DRV_HDMI21_RX_SCDC_Chk_Err");
    hdmi_phy_write_bit(1, 0x14, phy, PHY_REG_2E60);
    hdmi_phy_write_bit(1, 0x10, phy, PHY_REG_2E60);
    timer_delay_units(1);
    hdmi_phy_write_bit(0, 0x10, phy, PHY_REG_2E60);
    timer_delay_long_units(1);
    for (lane = 0; lane < hdmi_rx21_lts_records[rx].lane_count; lane++) {
        if (lane == 0)
            err[0] = hdmi_phy_read_reg(phy & 0xff, PHY_REG_SCDC_ERR_01) & 0xffff;
        else if (lane == 1)
            err[1] = hdmi_phy_read_reg(phy & 0xff, PHY_REG_SCDC_ERR_01) >> 16;
        else if (lane == 2)
            err[2] = hdmi_phy_read_reg(phy & 0xff, PHY_REG_SCDC_ERR_23) & 0xffff;
        else
            err[lane] = hdmi_phy_read_reg(phy & 0xff, PHY_REG_SCDC_ERR_23) >> 16;
        hdmi_rx21_lts_records[rx].scdc_error_counts[lane * 2 + hdmi_rx21_pre_aeq_r_indexes[lane]] = err[lane] & 0x7fff;
        if (err[lane] == SCDC_ERR_VALID) {
            if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                dbg_printf(DAT_a0069ce8, (char)(phy + 'A'), lane, err[lane] & 0x7fff);
            bad_lanes &= ~(1 << lane);
        } else if (err[lane] <= SCDC_ERR_LIMIT) {
            if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                dbg_printf(DAT_a0069d20, (char)(phy + 'A'), lane, err[lane] & 0x7fff);
            bad_lanes &= ~(1 << lane);
        } else {
            if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
                dbg_printf(DAT_a0069d60, (char)(phy + 'A'), lane, err[lane] & 0x7fff);
            bad_lanes |= 1 << lane;
        }
    }
    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
        dbg_printf("[HDMI21]: u8Scdc_Error_Ch = 0x%02x \n", bad_lanes & 0xff);
    return bad_lanes;
}
