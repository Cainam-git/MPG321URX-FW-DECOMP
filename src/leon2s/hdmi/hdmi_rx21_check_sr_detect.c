/* hdmi_rx21_check_sr_detect  (SR_detect_fail_ch)
 *
 * Check each lane of an HDMI 2.1 receiver for scrambler-reset detection and return the failing lanes.
 *   port: HDMI 2.1 receiver 0 or 1 (PHY 2 or 3 is chosen from it)
 * Returns: 0 = all good; else lanes without SR detect (bit n = lane n) ORed with the 4 FLT error bits of PHY
 *   register 0x2D00
 * Note: Label SR_detect_fail_ch is the printed result variable.
 * Name basis: derived - prints 'Ch%d, no SR detect with 1ms delay', 'SR_detect_fail_ch = 0x%02X', 'FLT Error';
 *   register 0x2D00
 *
 * Matching notes
 * --------------
 * leon2s SR_detect_fail_ch @ 0xa009a698-0xa009ae98 (2048 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the per-lane registers are chosen by if / else-if chains on the lane index (a switch becomes a balanced
 *    compare tree);
 *  - the error nibble is an unsigned char variable (flt_error) that is reused for the final mask;
 *  - the link training record is a byte array [port][0xB0] indexed with the LTS_* offsets.
 */

#define PHY_RX21_0              2       /* PHY numbers of the HDMI 2.1 receivers 0 / 1 */
#define PHY_RX21_1              3

/* Bytes of the link training record (0xB0 bytes per receiver, hdmi_rx21_lts_records). */
#define LTS_LANE_COUNT          0       /* 0, 3 or 4 */
#define LTS_FRL_RATE_IN_PHY     2       /* 'u8FRL_Rate_SetInPhy' */
#define LTS_BYTE_0x3A           0x3a    /* 1 sets bit 28 of PHY register 0x2D08 here */

/* Per-lane PHY registers (lanes 0..3). Bit 14 is cleared and set again; bit 21 clear afterwards is reported
   as 'no SR detect'. */
#define PHY_LANE0_REG_2E08      0x2e08
#define PHY_LANE1_REG_2E18      0x2e18
#define PHY_LANE2_REG_2E28      0x2e28
#define PHY_LANE3_REG_2E38      0x2e38
#define LANE_RESTART_BIT        0xe
#define SR_DETECT_BIT           0x15

/* PHY registers of the second check; bits 28..31 of PHY_REG_2D00 are printed as 'FLT Error'. */
#define PHY_REG_2D00            0x2d00
#define PHY_REG_2D04            0x2d04
#define PHY_REG_2D08            0x2d08
#define PHY_REG_2D0C            0x2d0c  /* lanes 0 / 1: bits 8..15 / 24..31 */
#define PHY_REG_2D10            0x2d10  /* lanes 2 / 3: bits 8..15 / 24..31 */
#define PHY_REG_2E04            0x2e04
#define PHY_REG_2E5C            0x2e5c
#define FLT_ERROR_SHIFT         28

#define HDMI_MSG_HDMI21         0x800   /* dbg_hdmi_message_flags bit 11: the '[HDMI21]' lines */

extern unsigned char hdmi_rx21_lts_records[][0xb0];
extern unsigned short hdmi_rx21_lane_freqs[];       /* lane frequencies of DRV_HDMI21_PHY_Freq_Detection, 4 per port */
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const void *, ...);
extern void DRV_HDMI21_PHY_Freq_Detection(unsigned char);
extern void DRV_HDMI21_PHY_PICDR_Reset(unsigned char);
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);
extern void hdmi_phy_write_bit(int, unsigned int, unsigned char, unsigned short);
extern unsigned int hdmi_phy_test_bit(unsigned int, unsigned char, unsigned short);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);
extern void timer_delay_long_units(unsigned short);

/*
 * Check the lanes of an HDMI 2.1 receiver after link training.
 *
 *   port  HDMI 2.1 receiver 0 or 1 (PHY 2 / 3); any other value returns 0
 *
 * Returns the lanes without SR detect (bit n = lane n) ORed with the 'FLT Error' nibble of PHY register
 * 0x2D00; 0 = all good. Called by DRV_HDMI21_RXDetect_FSM_LTS_Chk_Err and DRV_HDMI21_RXDetect_FSM_LTS_P,
 * which treat a non-zero result as failing lanes.
 *
 * Phases:
 *   1. Lane clocks: measure them (DRV_HDMI21_PHY_Freq_Detection); when one lane in use differs from the value
 *      that belongs to frl_rate_in_phy, reset the clock recovery once (DRV_HDMI21_PHY_PICDR_Reset).
 *   2. SR detect: clear bits 4..7 of register 0x2E5C, set bit 28 of 0x2D08 from byte 0x3A of the record,
 *      clear and set LANE_RESTART_BIT of each lane in use, wait one delay unit ('1ms delay'), then note each
 *      lane whose SR_DETECT_BIT is clear (lane 3 only with 4 lanes).
 *   3. Second check: fixed writes to 0x2D08 and 0x2E04, per-lane fields of 0x2D04, 0x2D0C and 0x2D10, a bit
 *      sequence on 0x2D00, one delay unit; bits 28..31 of 0x2D00 are ORed into the result.
 *   4. All good: clear the low byte of 0x2D00 and the lane bytes of 0x2D0C / 0x2D10 again.
 */
unsigned char hdmi_rx21_check_sr_detect(unsigned char port)
{
    unsigned char failed = 0;
    unsigned short expected_freq = 0;
    unsigned char phy;
    unsigned char lane;
    unsigned char rate;
    unsigned char flt_error;

    if (port == 0)
        phy = PHY_RX21_0;
    else if (port == 1)
        phy = PHY_RX21_1;
    else
        return 0;

    /* 1. Lane clocks against the value of the FRL rate set in the PHY (other rates: 0). */
    DRV_HDMI21_PHY_Freq_Detection(port);
    rate = hdmi_rx21_lts_records[port][LTS_FRL_RATE_IN_PHY];
    if (rate == 6)
        expected_freq = 0x4b0;
    else if (rate == 5)
        expected_freq = 1000;
    else if (rate == 4)
        expected_freq = 800;
    else if ((unsigned char)(rate - 2) <= 1)
        expected_freq = 600;
    else if (rate == 1)
        expected_freq = 300;
    for (lane = 0; lane < hdmi_rx21_lts_records[port][LTS_LANE_COUNT]; lane++) {
        if (hdmi_rx21_lane_freqs[port * 4 + lane] != expected_freq) {
            DRV_HDMI21_PHY_PICDR_Reset(phy);
            break;
        }
    }

    /* 2. SR detect of each lane. */
    hdmi_phy_update_reg(phy, PHY_REG_2E5C, 0xffffff0f, 0);
    hdmi_phy_write_bit(hdmi_rx21_lts_records[port][LTS_BYTE_0x3A] == 1, 0x1c, phy, PHY_REG_2D08);
    for (lane = 0; lane < hdmi_rx21_lts_records[port][LTS_LANE_COUNT]; lane++) {
        if (lane == 0)
            hdmi_phy_write_bit(0, LANE_RESTART_BIT, phy, PHY_LANE0_REG_2E08);
        else if (lane == 1)
            hdmi_phy_write_bit(0, LANE_RESTART_BIT, phy, PHY_LANE1_REG_2E18);
        else if (lane == 2)
            hdmi_phy_write_bit(0, LANE_RESTART_BIT, phy, PHY_LANE2_REG_2E28);
        else if (lane == 3)
            hdmi_phy_write_bit(0, LANE_RESTART_BIT, phy, PHY_LANE3_REG_2E38);
    }
    for (lane = 0; lane < hdmi_rx21_lts_records[port][LTS_LANE_COUNT]; lane++) {
        if (lane == 0)
            hdmi_phy_write_bit(1, LANE_RESTART_BIT, phy, PHY_LANE0_REG_2E08);
        else if (lane == 1)
            hdmi_phy_write_bit(1, LANE_RESTART_BIT, phy, PHY_LANE1_REG_2E18);
        else if (lane == 2)
            hdmi_phy_write_bit(1, LANE_RESTART_BIT, phy, PHY_LANE2_REG_2E28);
        else if (lane == 3)
            hdmi_phy_write_bit(1, LANE_RESTART_BIT, phy, PHY_LANE3_REG_2E38);
    }
    timer_delay_long_units(1);
    if (hdmi_phy_test_bit(SR_DETECT_BIT, phy, PHY_LANE0_REG_2E08) == 0) {
        if ((dbg_hdmi_message_flags & HDMI_MSG_HDMI21) != 0)
            dbg_printf("[HDMI21]: Ch%d, no SR detect with 1ms delay\n\n", 0);
        failed = 1;
    }
    if (hdmi_phy_test_bit(SR_DETECT_BIT, phy, PHY_LANE1_REG_2E18) == 0) {
        if ((dbg_hdmi_message_flags & HDMI_MSG_HDMI21) != 0)
            dbg_printf("[HDMI21]: Ch%d, no SR detect with 1ms delay\n\n", 1);
        failed |= 2;
    }
    if (hdmi_phy_test_bit(SR_DETECT_BIT, phy, PHY_LANE2_REG_2E28) == 0) {
        if ((dbg_hdmi_message_flags & HDMI_MSG_HDMI21) != 0)
            dbg_printf("[HDMI21]: Ch%d, no SR detect with 1ms delay\n\n", 2);
        failed |= 4;
    }
    if (hdmi_phy_test_bit(SR_DETECT_BIT, phy, PHY_LANE3_REG_2E38) == 0 && hdmi_rx21_lts_records[port][LTS_LANE_COUNT] == 4) {
        if ((dbg_hdmi_message_flags & HDMI_MSG_HDMI21) != 0)
            dbg_printf("[HDMI21]: Ch%d, no SR detect with 1ms delay\n\n", 3);
        failed |= 8;
    }
    if ((dbg_hdmi_message_flags & HDMI_MSG_HDMI21) != 0)
        dbg_printf("[HDMI21]: SR_detect_fail_ch = 0x%02X\n\n", failed);

    /* 3. Second check through PHY register 0x2D00. */
    hdmi_phy_update_reg(phy, PHY_REG_2D08, 0xffffff0f, 0x10);
    hdmi_phy_write_bit(1, 8, phy, PHY_REG_2E04);
    hdmi_phy_write_bit(1, 0xc, phy, PHY_REG_2E04);
    hdmi_phy_write_bit(1, 0x19, phy, PHY_REG_2D08);
    for (lane = 0; lane < hdmi_rx21_lts_records[port][LTS_LANE_COUNT]; lane++) {
        /* A 4-bit field per lane in 0x2D04 (bits 16..31: values 5, 6, 7, 8) and 0xFF in its 0x2D0C / 0x2D10 byte. */
        if (lane == 0)
            hdmi_phy_update_reg(phy, PHY_REG_2D04, 0xfff0ffff, 0x50000);
        else if (lane == 1)
            hdmi_phy_update_reg(phy, PHY_REG_2D04, 0xff0fffff, 0x600000);
        else if (lane == 2)
            hdmi_phy_update_reg(phy, PHY_REG_2D04, 0xf0ffffff, 0x7000000);
        else if (lane == 3)
            hdmi_phy_update_reg(phy, PHY_REG_2D04, 0x0fffffff, 0x80000000);
        if (lane == 0)
            hdmi_phy_update_reg(phy, PHY_REG_2D0C, 0xffff00ff, 0xff00);
        else if (lane == 1)
            hdmi_phy_update_reg(phy, PHY_REG_2D0C, 0x00ffffff, 0xff000000);
        else if (lane == 2)
            hdmi_phy_update_reg(phy, PHY_REG_2D10, 0xffff00ff, 0xff00);
        else if (lane == 3)
            hdmi_phy_update_reg(phy, PHY_REG_2D10, 0x00ffffff, 0xff000000);
    }
    hdmi_phy_update_reg(phy, PHY_REG_2D00, 0xffffff00, 0);
    hdmi_phy_write_bit(1, 0xb, phy, PHY_REG_2D00);
    hdmi_phy_write_bit(1, 0xc, phy, PHY_REG_2D00);
    hdmi_phy_write_bit(1, 0, phy, PHY_REG_2D00);
    hdmi_phy_write_bit(1, 1, phy, PHY_REG_2D00);
    hdmi_phy_write_bit(0, 1, phy, PHY_REG_2D00);
    hdmi_phy_write_bit(1, 3, phy, PHY_REG_2D00);
    hdmi_phy_write_bit(0, 3, phy, PHY_REG_2D00);
    hdmi_phy_write_bit(1, 1, phy, PHY_REG_2D00);
    hdmi_phy_write_bit(0, 1, phy, PHY_REG_2D00);
    hdmi_phy_write_bit(1, 5, phy, PHY_REG_2D00);
    timer_delay_long_units(1);
    flt_error = hdmi_phy_read_reg(phy, PHY_REG_2D00) >> FLT_ERROR_SHIFT;
    if ((dbg_hdmi_message_flags & HDMI_MSG_HDMI21) != 0)
        dbg_printf("[HDMI21]: FLT Error = 0x%02X\n\n", flt_error & 0xf);
    flt_error = flt_error | failed;
    if ((dbg_hdmi_message_flags & HDMI_MSG_HDMI21) != 0)
        dbg_printf("[HDMI21]: Final FLT Error = 0x%02X\n\n", flt_error);

    /* 4. All good: clear what the second check set. */
    if (flt_error == 0) {
        hdmi_phy_update_reg(phy, PHY_REG_2D00, 0xffffff00, 0);
        for (lane = 0; lane < hdmi_rx21_lts_records[port][LTS_LANE_COUNT]; lane++) {
            if (lane == 0)
                hdmi_phy_update_reg(phy, PHY_REG_2D0C, 0xffff00ff, 0);
            else if (lane == 1)
                hdmi_phy_update_reg(phy, PHY_REG_2D0C, 0x00ffffff, 0);
            else if (lane == 2)
                hdmi_phy_update_reg(phy, PHY_REG_2D10, 0xffff00ff, 0);
            else if (lane == 3)
                hdmi_phy_update_reg(phy, PHY_REG_2D10, 0x00ffffff, 0);
        }
    }
    return flt_error;
}
