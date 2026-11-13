/* hdmi_tx_set_regs_39_30  (FUN_a008e484)
 *
 * Set HDMI TX register 0x39 bits 0..1 and register 0x30 by mode.
 *   port: HDMI TX port
 *   mode: 1 or 2
 * Name basis: descriptive - mode 1 -> (0,0,6), 2 -> (1,1,0), other -> 0
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008e484 @ 0xa008e484, flags -mcpu=v8 -Os -g.
 * Source form: the externs are declared without prototypes; all three locals start at 0 and the if chain assigns
 * them as the decompiler wrote it. The unused parameters pass the argument registers on (the last write
 * forwards the last two).
 */
extern int hdmi_tx_reg_write8();
extern int hdmi_tx_reg_update_bits();

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */

/*
 * Set bits 0 and 1 of HDMI TX register 0x39 and write HDMI TX register 0x30, by mode:
 *   mode 1: bit 0 = 0, bit 1 = 0, register 0x30 = 6;
 *   mode 2: bit 0 = 1, bit 1 = 1, register 0x30 = 0;
 *   any other mode: bit 0 = 0, bit 1 = 0, register 0x30 = 0.
 *   port: HDMI TX port.  unused_3 to unused_6: not used here; unused_5 and unused_6 are passed on in the
 *   last write.
 * Called by hdmi_tx_phy_setup_frl and hdmi_tx_phy_tune_for_tmds_clock.
 */
void hdmi_tx_set_regs_39_30(unsigned char port, unsigned char mode, unsigned int unused_3, unsigned int unused_4,
                 unsigned int unused_5, unsigned int unused_6)

{
  unsigned char bit0;
  unsigned char bit1;
  unsigned char reg30;
  
  bit0 = 0;
  bit1 = 0;
  reg30 = 0;
  if ((mode != '\0') && (reg30 = 6, mode != '\x01')) {
    bit0 = 1;
    bit1 = 1;
    reg30 = 0;
    if (mode != '\x02') {
      bit0 = 0;
      bit1 = 0;
    }
  }
  hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 0x39, 1, bit0);
  hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 0x39, 2, bit1);
  hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x30, reg30, unused_5, unused_6);
}
