/* hdmi_tx_set_ddc_clock_divider  (FUN_a0091c84)
 *
 * Set the 10-bit clock divider of the HDMI TX DDC master.
 *   port: HDMI TX port
 *   divider
 * Name basis: descriptive - regs 0xF6/0xF7 next to the DDC master registers 0xED..0xF5; value clamped to
 *   0x3FF, start value 100
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091c84 @ 0xa0091c84-0xa0091cf4 (112 bytes = 28 words incl. the trailing pad nop), flags
 * -mcpu=v8 -Os -g.
 * The register 0xF7 read returns a word masked with 0xff, so an int prototype is honest. A u8 'hi' is formed
 * before the first write: the mask is applied at the read ('r = f() & ~0xc'); int 'r & 0xf3' forms give another
 * schedule. The last write is a tail call.
 */
extern int hdmi_tx_reg_read8(unsigned char, unsigned char, unsigned short);
extern void hdmi_tx_reg_write8(unsigned char, unsigned char, unsigned short, unsigned char);

#define DDC_DIVIDER_LOW_REG 0xf6        /* divider bits 7..0 */
#define DDC_DIVIDER_HIGH_REG 0xf7       /* bits 3..2 hold divider bits 9..8 */
#define DDC_DIVIDER_MAX 0x3ff           /* the divider is 10 bits wide */

/*
 * Set the clock divider of the DDC master of HDMI TX 'port' (bank 0). 'divider' is clamped to 0x3FF; bits 7..0
 * go to register 0xF6 and bits 9..8 replace bits 3..2 of register 0xF7.
 */
void hdmi_tx_set_ddc_clock_divider(unsigned char port, unsigned short divider)
{
  int high_reg;
  int high_new;

  high_reg = hdmi_tx_reg_read8(port, 0, DDC_DIVIDER_HIGH_REG) & ~0xc;
  if (divider > DDC_DIVIDER_MAX)
    divider = DDC_DIVIDER_MAX;
  high_new = high_reg | (divider >> 8);
  hdmi_tx_reg_write8(port, 0, DDC_DIVIDER_LOW_REG, divider & 0xff);
  hdmi_tx_reg_write8(port, 0, DDC_DIVIDER_HIGH_REG, high_new);
}
