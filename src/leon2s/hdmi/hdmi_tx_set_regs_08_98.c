/* hdmi_tx_set_regs_08_98  (FUN_a008e0f0)
 *
 * Set the mode nibbles of HDMI TX registers 0x08, 0x98 and 0x99 from a mode.
 *   port: HDMI TX port
 *   mode
 *   v: value for mode 3
 * Name basis: descriptive - mode 0/1/3/other -> 0/4/value/0xF
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008e0f0 @ 0xa008e0f0-0xa008e200, flags -mcpu=v8 -Os -g.
 * Source form: int parameters kept in their registers (mode and port are masked in place: firmware
 * 'and %i1,0xff,%i1'); six parameters (level lands in the free %i3); hdmi_tx_reg_read8 returns a full word here
 * (the firmware keeps 'and -16'; a u8 prototype folds it to 0xf0); the last write is duplicated into both arms
 * (crossjumped; this keeps the u8 conversion 'and 0xff' in the else arm only). The mode switch is compared
 * signed, so mode is an int.
 */
extern unsigned int hdmi_tx_reg_read8(unsigned char, unsigned char, unsigned short);
extern void hdmi_tx_reg_write8(unsigned char, unsigned char, unsigned short, unsigned char);

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */

/*
 * Set the nibbles of HDMI TX registers 0x08, 0x98 and 0x99 from a mode. The level written is 0 for mode 0,
 * 4 for mode 1, mode3_level for mode 3 and 0x0F for every other mode (mode 2 included). Then:
 *   - register 0x08: bits 4..7 = level, low nibble kept;
 *   - register 0x98: bits 0..3 = level, then bits 4..7 = level (two writes);
 *   - register 0x99: bits 0..3 = level, except for mode 2, where the low nibble becomes 8; bits 4..7 kept.
 *   port: HDMI TX port.  mode: 0..3 as above.  mode3_level: level used when mode is 3.
 *   unused_4 to unused_6: not used.
 * Called by hdmi_tx_phy_setup_frl, hdmi_tx_phy_tune_for_tmds_clock and hdmi_tx_set_txffe_mode.
 */
void hdmi_tx_set_regs_08_98(unsigned int port, int mode, unsigned int mode3_level, unsigned int unused_4, unsigned int unused_5, unsigned int unused_6)
{
    unsigned int level;
    unsigned int level_high;
    unsigned int reg99;

    mode &= 0xff;
    level = 0;
    switch (mode) {
    case 0:
        break;
    case 1:
        level = 4;
        break;
    case 3:
        level = mode3_level;
        break;
    default:
        level = 0xf;
        break;
    }
    port &= 0xff;
    level_high = (level & 0xff) << 4;
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 8, (hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, 8) & 0xf) | level_high);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x98, (hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, 0x98) & ~0xf) | level);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x98, (hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, 0x98) & 0xf) | level_high);
    reg99 = hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, 0x99) & ~0xf;
    if (mode == 2)
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x99, (reg99 | 8) & 0xf8);
    else
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x99, reg99 | level);
}
