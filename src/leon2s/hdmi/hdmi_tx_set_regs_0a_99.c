/* hdmi_tx_set_regs_0a_99  (FUN_a008e2c0)
 *
 * Set the mode fields of HDMI TX registers 0x0A and 0x99.
 *   port: HDMI TX port
 *   mode
 *   v: value for mode 3
 * Name basis: descriptive - mode 0..2 -> 1, 3 -> value, other -> 3
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008e2c0 @ 0xa008e2c0-0xa008e3c0, flags -mcpu=v8 -Os -g.
 * Source form: same as hdmi_tx_set_regs_08_98 (int mode, six parameters, read results kept as full words). The
 * three case bodies with level = 1 are written separately: grouped labels let GCC fold the switch into a range
 * test. level_byte = level & 0xff is one variable shared by both shifts. The last write is a tail call.
 */
extern unsigned int hdmi_tx_reg_read8(unsigned char, unsigned char, unsigned short);
extern void hdmi_tx_reg_write8(unsigned char, unsigned char, unsigned short, unsigned char);

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */

/*
 * Set fields of HDMI TX registers 0x0A and 0x99 from a mode. The level written is 1 for modes 0, 1 and 2,
 * mode3_level for mode 3 and 3 for every other mode. Then:
 *   - register 0x0A: bits 6..7 = level, then bits 0..1 = level (two writes);
 *   - register 0x99: bits 6..7 = level, then bits 4..5 = level (two writes).
 *   port: HDMI TX port.  mode: 0..3 as above.  mode3_level: level used when mode is 3.
 *   unused_4 to unused_6: not used.
 * Called by hdmi_tx_phy_setup_frl and hdmi_tx_phy_tune_for_tmds_clock.
 */
void hdmi_tx_set_regs_0a_99(unsigned int port, int mode, unsigned int mode3_level, unsigned int unused_4, unsigned int unused_5, unsigned int unused_6)
{
    unsigned int level;
    unsigned int level_high;
    unsigned int level_byte;

    mode &= 0xff;
    switch (mode) {
    case 0:
        level = 1;
        break;
    case 1:
        level = 1;
        break;
    case 2:
        level = 1;
        break;
    case 3:
        level = mode3_level;
        break;
    default:
        level = 3;
        break;
    }
    port &= 0xff;
    level_byte = level & 0xff;
    level_high = level_byte << 6;
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 10, (hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, 10) & 0x3f) | level_high);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 10, (hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, 10) & ~3) | level);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x99, (hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, 0x99) & 0x3f) | level_high);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x99, (hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, 0x99) & ~0x30) | (level_byte << 4));
}
