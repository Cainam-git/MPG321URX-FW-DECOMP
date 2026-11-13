/* hdmi_phy_set_rate_fields  (FUN_a0075360)
 *
 * Set the bit fields of PHY register block 0x3630 for the port's link rate.
 *   phy
 * Name basis: descriptive - upper fields chosen by byte 2 of the HDMI 2.1 port row (> 5); callers PHY_EQ step
 *   and DRV_HDMI21_Set_PHY
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0075360 @ 0xa0075360, flags -mcpu=v8 -Os.
 * Source form: the receiver index is (phy != 2), not (phy == 2): 'cmp %g0,%g1 ; addx %g0,0' computes
 * (x != K).
 */
extern void hdmi_phy_update_reg(unsigned int, unsigned int, unsigned int, unsigned int);
extern void hdmi_phy_write_bit(unsigned int, unsigned int, unsigned int, unsigned int);
#define LTS_FRL_RATE_IN_PHY 2   /* byte +2 of a 0xb0-byte link-training record ("u8FRL_Rate_SetInPhy") */

extern unsigned char hdmi_rx21_lts_records[][0xb0];

/* Sets the bit fields of PHY register 0x3630: bits 0..3 = 2, bits 4..6 = 1, bits 8..10, 11..13 and
 * 21..23 = 0. Bits 14..15, 16..17 and 18..20 are each set to 1 when the link-training record's
 * byte +2 (rate set in the PHY) is above 5, otherwise to 0. Finally it clears bits 26..30.
 * The record is that of the receiver (PHY 2 -> record 0, otherwise record 1).
 *   phy: PHY page */
void hdmi_phy_set_rate_fields(unsigned char phy)
{
    int idx = (phy != 2);
    unsigned char flag = hdmi_rx21_lts_records[idx][LTS_FRL_RATE_IN_PHY];

    hdmi_phy_update_reg(phy, 0x3630, 0xfffffff0, 2);
    hdmi_phy_update_reg(phy, 0x3630, 0xffffff8f, 0x10);
    hdmi_phy_update_reg(phy, 0x3630, 0xfffff8ff, 0);
    hdmi_phy_update_reg(phy, 0x3630, 0xffffc7ff, 0);
    hdmi_phy_update_reg(phy, 0x3630, 0xff1fffff, 0);
    hdmi_phy_update_reg(phy, 0x3630, 0xff1fffff, 0);

    if (flag > 5) {
        hdmi_phy_update_reg(phy, 0x3630, 0xffff3fff, 0x4000);
        hdmi_phy_update_reg(phy, 0x3630, 0xfffcffff, 0x10000);
        hdmi_phy_update_reg(phy, 0x3630, 0xffe3ffff, 0x40000);
    } else {
        hdmi_phy_update_reg(phy, 0x3630, 0xffff3fff, 0);
        hdmi_phy_update_reg(phy, 0x3630, 0xfffcffff, 0);
        hdmi_phy_update_reg(phy, 0x3630, 0xffe3ffff, 0);
    }

    hdmi_phy_write_bit(0, 0x1a, phy, 0x3630);
    hdmi_phy_write_bit(0, 0x1b, phy, 0x3630);
    hdmi_phy_write_bit(0, 0x1c, phy, 0x3630);
    hdmi_phy_write_bit(0, 0x1d, phy, 0x3630);
    hdmi_phy_write_bit(0, 0x1e, phy, 0x3630);
}
