/* hdmi_rx21_set_pll_ctrl_bit5  (FUN_a009645c)
 *
 * Set or clear bit 5 of the FRL PLL control register of a receiver.
 *   port: receiver
 *   on: 1 = set
 * Name basis: descriptive - 0xCF0146FC (port 0) / 0xCF01473C; caller FRL_PLL
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009645c @ 0xa009645c (-mcpu=v8 -Os -g)
 * Source form: the register is read-modify-written through a volatile word; the clear mask is 0xffffffdf.
 */
#define FRL_PLL_CTRL_RX0   (*(volatile unsigned int *)0xcf0146fc)   /* control register for receiver 0 */
#define FRL_PLL_CTRL_RX1   (*(volatile unsigned int *)0xcf01473c)   /* control register for receiver 1 */
#define PLL_CTRL_BIT5      0x20

/*
 * Set or clear bit 5 of the PLL control register of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver; 0 uses the register at 0xCF0146FC, any other value the one at 0xCF01473C
 *   on: 1 = set, any other value = clear
 * Called by FRL_PLL, which sets it for two ranges of its target value.
 */
void hdmi_rx21_set_pll_ctrl_bit5(unsigned char port, unsigned char on)

{
  if (on == '\x01') {
    if (port == '\0') {
      FRL_PLL_CTRL_RX0 = FRL_PLL_CTRL_RX0 | PLL_CTRL_BIT5;
    }
    else {
      FRL_PLL_CTRL_RX1 = FRL_PLL_CTRL_RX1 | PLL_CTRL_BIT5;
    }
  }
  else if (port == '\0') {
    FRL_PLL_CTRL_RX0 = FRL_PLL_CTRL_RX0 & 0xffffffdf;
  }
  else {
    FRL_PLL_CTRL_RX1 = FRL_PLL_CTRL_RX1 & 0xffffffdf;
  }
  return;
}
