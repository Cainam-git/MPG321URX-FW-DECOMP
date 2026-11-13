/* hdmi_phy_set_power  (FUN_a007381c)
 *
 * Run the PHY register power-on or power-off sequence of an HDMI port.
 *   p1: PHY
 *   p2: 1 = on
 * Name basis: derived - callers TMDS_PowerOn (p2 = 1) and TMDS_PowerOff (p2 = 0)
 *
 * Matching notes
 * --------------
 * leon2s hdmi_phy_set_power (FUN_a007381c) @ 0xa007381c, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the routine is declared with six parameters although its callers pass two (hdmi_phy_restore_power passes
 *    six); pass_3..pass_6 are handed on unchanged to the last call of each sequence
 *    (hdmi_phy_power_on_final_step(phy, 1, pass_3..pass_6), hdmi_phy_write_bit(..., pass_5, pass_6));
 *  - the callees are declared without parameter lists.
 */
extern void hdmi_phy_power_on_final_step();
extern int hdmi_phy_power_off_first_step();
extern int hdmi_phy_clear_ctrl_bits();
extern int hdmi_phy_run_ctrl_sequence();
extern void hdmi_phy_write_bit();
extern void hdmi_phy_update_reg();

#define PHY_POWER_ON        1           /* value of "on" */

/* PHY registers (paged per PHY by hdmi_phy_write_bit / hdmi_phy_update_reg). */
#define PHY_REG_1C00        0x1c00
#define PHY_REG_1C04        0x1c04
#define PHY_REG_1F0C        0x1f0c
#define REG_1F0C_BIT14      0xe         /* set on, cleared off; hdmi_phy_restore_power runs power-on again when it reads 0 */
#define PHY_REG_1F40        0x1f40
#define PHY_REG_2C34        0x2c34
#define REG_2C34_KEEP       0xfffff3ff  /* keeps all but bits 10..11 */
#define REG_2C34_BITS_10_11_ON 0x400    /* bits 10..11 = 1; power-off writes 0 */
#define PHY_REG_2E5C        0x2e5c
#define PHY_REG_3608        0x3608
#define PHY_REG_3618        0x3618
#define PHY_REG_361C        0x361c      /* also written by hdmi_phy_run_ctrl_sequence */

/* Control register of each of the three channels. */
#define PHY_CH_REG(ch, reg) (0x1100 + 0x400 * (ch) + (reg))
#define CH_REG_CTRL         0x00
#define CH_CTRL_BIT21       0x15

/*
 * Switch the receiving PHY of an HDMI input on or off by a fixed sequence of register bit writes.
 *
 *   phy            the PHY (0..3; 2 and 3 are the HDMI 2.1 receivers)
 *   on             1: power-on sequence; any other value: power-off sequence
 *   pass_3..pass_6 not used: only handed on to the last call, which takes fewer parameters
 *
 * Called by TMDS_PowerOn (on = 1), TMDS_PowerOff (on = 0) and hdmi_phy_restore_power (on = 1). TMDS_PowerOn
 * and TMDS_PowerOff write more PHY bits after this call (bit 7 of 0x1C04 and 0x2C04, the low byte of 0x1000)
 * and record the state with hdmi_phy_set_power_flag.
 *
 * Power-on: sets bits 13 and 14 of 0x1F0C; sets bits 2, 7, 16 and 17 and clears bit 15 of 0x1C04; clears
 * bit 31 of 0x2E5C; sets bits 21 and 27 of 0x1C00, bit 24 of 0x1F40 and bits 8 and 9 of 0x3608; runs
 * hdmi_phy_run_ctrl_sequence on 0x361C and then sets its bits 16 and 18; writes 1 into bits 10..11 of 0x2C34,
 * sets its bits 16..19 and clears bit 25; ends with hdmi_phy_power_on_final_step.
 * Power-off: starts with hdmi_phy_power_off_first_step and hdmi_phy_clear_ctrl_bits; clears bit 14 of 0x1F0C,
 * bits 2, 15 and 16 of 0x1C04, bits 21 and 27 of 0x1C00, bits 8 and 9 of 0x3608, bits 0, 16 and 18 of 0x361C,
 * bit 29 of 0x3618 and bits 10..11 and 16..20 of 0x2C34; sets bit 31 of 0x2E5C and bit 25 of 0x2C34; ends by
 * setting bit 21 of the three channel control registers. Bit 13 of 0x1F0C, bits 7 and 17 of 0x1C04 and bit 24
 * of 0x1F40 are left as they are.
 */
void hdmi_phy_set_power(unsigned char phy, unsigned char on, unsigned int pass_3, unsigned int pass_4,
                        unsigned int pass_5, unsigned int pass_6)
{
    if (on == PHY_POWER_ON) {
        hdmi_phy_write_bit(1, 13, phy, PHY_REG_1F0C);
        hdmi_phy_write_bit(1, REG_1F0C_BIT14, phy, PHY_REG_1F0C);
        hdmi_phy_write_bit(1, 16, phy, PHY_REG_1C04);
        hdmi_phy_write_bit(0, 15, phy, PHY_REG_1C04);
        hdmi_phy_write_bit(1, 2, phy, PHY_REG_1C04);
        hdmi_phy_write_bit(1, 7, phy, PHY_REG_1C04);
        hdmi_phy_write_bit(0, 31, phy, PHY_REG_2E5C);
        hdmi_phy_write_bit(1, 17, phy, PHY_REG_1C04);
        hdmi_phy_write_bit(1, 21, phy, PHY_REG_1C00);
        hdmi_phy_write_bit(1, 27, phy, PHY_REG_1C00);
        hdmi_phy_write_bit(1, 24, phy, PHY_REG_1F40);
        hdmi_phy_write_bit(1, 8, phy, PHY_REG_3608);
        hdmi_phy_write_bit(1, 9, phy, PHY_REG_3608);
        hdmi_phy_run_ctrl_sequence(phy);
        hdmi_phy_write_bit(1, 16, phy, PHY_REG_361C);
        hdmi_phy_update_reg(phy, PHY_REG_2C34, REG_2C34_KEEP, REG_2C34_BITS_10_11_ON);
        hdmi_phy_write_bit(1, 16, phy, PHY_REG_2C34);
        hdmi_phy_write_bit(1, 17, phy, PHY_REG_2C34);
        hdmi_phy_write_bit(1, 18, phy, PHY_REG_2C34);
        hdmi_phy_write_bit(1, 19, phy, PHY_REG_2C34);
        hdmi_phy_write_bit(0, 25, phy, PHY_REG_2C34);
        hdmi_phy_write_bit(1, 18, phy, PHY_REG_361C);
        hdmi_phy_power_on_final_step(phy, 1, pass_3, pass_4, pass_5, pass_6);
        return;
    }
    hdmi_phy_power_off_first_step(phy);
    hdmi_phy_clear_ctrl_bits(phy);
    hdmi_phy_write_bit(0, REG_1F0C_BIT14, phy, PHY_REG_1F0C);
    hdmi_phy_write_bit(0, 16, phy, PHY_REG_1C04);
    hdmi_phy_write_bit(0, 15, phy, PHY_REG_1C04);
    hdmi_phy_write_bit(0, 2, phy, PHY_REG_1C04);
    hdmi_phy_write_bit(0, 21, phy, PHY_REG_1C00);
    hdmi_phy_write_bit(0, 27, phy, PHY_REG_1C00);
    hdmi_phy_write_bit(1, 31, phy, PHY_REG_2E5C);
    hdmi_phy_write_bit(0, 8, phy, PHY_REG_3608);
    hdmi_phy_write_bit(0, 9, phy, PHY_REG_3608);
    hdmi_phy_write_bit(0, 0, phy, PHY_REG_361C);
    hdmi_phy_write_bit(0, 16, phy, PHY_REG_361C);
    hdmi_phy_write_bit(0, 29, phy, PHY_REG_3618);
    hdmi_phy_update_reg(phy, PHY_REG_2C34, REG_2C34_KEEP, 0);
    hdmi_phy_write_bit(0, 16, phy, PHY_REG_2C34);
    hdmi_phy_write_bit(0, 17, phy, PHY_REG_2C34);
    hdmi_phy_write_bit(0, 18, phy, PHY_REG_2C34);
    hdmi_phy_write_bit(0, 19, phy, PHY_REG_2C34);
    hdmi_phy_write_bit(0, 20, phy, PHY_REG_2C34);
    hdmi_phy_write_bit(1, 25, phy, PHY_REG_2C34);
    hdmi_phy_write_bit(0, 18, phy, PHY_REG_361C);
    hdmi_phy_write_bit(1, CH_CTRL_BIT21, phy, PHY_CH_REG(0, CH_REG_CTRL));
    hdmi_phy_write_bit(1, CH_CTRL_BIT21, phy, PHY_CH_REG(1, CH_REG_CTRL));
    hdmi_phy_write_bit(1, CH_CTRL_BIT21, phy, PHY_CH_REG(2, CH_REG_CTRL), pass_5, pass_6);
    return;
}
