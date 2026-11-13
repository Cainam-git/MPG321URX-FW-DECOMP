/* hdmi_tx_set_color_depth  (FUN_a0091f14)
 *
 * Set the colour depth (8, 10 or 12 bits) of an HDMI TX port.
 *   port_arg: HDMI TX port
 *   bits_per_colour
 * Name basis: proven - prints '8bit_Depth' / '10bit_Depth' / '12bit_Depth'; regs 0x12F and 0x4A
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091f14 @ 0xa0091f14-0xa0092064 (336 bytes, 84 words), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the port is taken once into an unsigned char local; the depth is tested as (bits_per_colour & 0xff);
 *  - reg_12f is an unsigned int, reg_4a an unsigned char;
 *  - dbg_print_string takes one argument (the texts have no format; the firmware sets only %o0); the texts are
 *    the symbols DAT_a0068e90 / ea8 / ec0 / ed8.
 */
extern unsigned int dbg_print_string(const char *text);
/* The firmware's texts: "\033[0m\t\t - 8bit_Depth\n", "... - 10bit_Depth\n", "... - 12bit_Depth\n" and
   "... - 8bit_Depth default\n". */
extern const char DAT_a0068e90[], DAT_a0068ea8[], DAT_a0068ec0[], DAT_a0068ed8[];
extern void hdmi_tx_set_deep_color_bit(unsigned char port, unsigned char on);
extern int hdmi_tx_reg_read8();
extern void hdmi_tx_reg_write8();

#define TX_BANK_0           0
#define TX_REG_12F          0x12f   /* bits 3..4: depth field, bit 5: set for every depth, bit 6: deep colour bit */
#define TX_REG_12F_KEEP     0xffffff87  /* bits 3..6 cleared */
#define TX_REG_4A           0x4a    /* bits 6..7: depth field; bits 0..4 kept, bit 5 cleared */
#define TX_REG_4A_KEEP      0x1f

/*
 * Program the colour depth of an HDMI TX port. hdmi_tx_run_step calls it in TX_STEP_PACKETS_BYPASS and
 * TX_STEP_PACKETS_OWN_AVI with the channel's color_depth (8 when dsc_enable is set, in the bypass step also
 * when ctrl_bit30 is set) and with 8 in TX_STEP_DSC.
 *
 *   port              HDMI TX port
 *   bits_per_colour   8, 10 or 12; any other value is set up as 8 (and printed as '8bit_Depth default')
 *
 * The deep colour bit (bit 6 of register 0x12F) is cleared first, then registers 0x12F and 0x4A of bank 0
 * get their depth fields:
 *
 *   bits per colour   0x12F bits 3..4   0x4A bits 6..7   deep colour bit
 *         8                 0                 0              off
 *        10                 1                 1              on
 *        12                 2                 2              on
 */
void hdmi_tx_set_color_depth(unsigned int port_arg, int bits_per_colour)
{
  unsigned int reg_12f;
  unsigned char reg_4a;
  unsigned char port;

  port = (unsigned char)port_arg;
  hdmi_tx_set_deep_color_bit(port,0);
  reg_12f = hdmi_tx_reg_read8(port,TX_BANK_0,TX_REG_12F) & TX_REG_12F_KEEP;
  reg_4a = hdmi_tx_reg_read8(port,TX_BANK_0,TX_REG_4A) & TX_REG_4A_KEEP;

  if ((bits_per_colour & 0xff) == 8) {
    dbg_print_string(DAT_a0068e90);
    hdmi_tx_reg_write8(port,TX_BANK_0,TX_REG_12F,(reg_12f | 0x20) & 0xa7);
    hdmi_tx_reg_write8(port,TX_BANK_0,TX_REG_4A,reg_4a);
    hdmi_tx_set_deep_color_bit(port,0);
  }
  else if ((bits_per_colour & 0xff) == 10) {
    dbg_print_string(DAT_a0068ea8);
    hdmi_tx_reg_write8(port,TX_BANK_0,TX_REG_12F,(reg_12f | 0x28) & 0xaf);
    hdmi_tx_reg_write8(port,TX_BANK_0,TX_REG_4A,reg_4a | 0x40);
    hdmi_tx_set_deep_color_bit(port,1);
  }
  else if ((bits_per_colour & 0xff) == 12) {
    dbg_print_string(DAT_a0068ec0);
    hdmi_tx_reg_write8(port,TX_BANK_0,TX_REG_12F,(reg_12f | 0x30) & 0xb7);
    hdmi_tx_reg_write8(port,TX_BANK_0,TX_REG_4A,reg_4a | 0x80);
    hdmi_tx_set_deep_color_bit(port,1);
  }
  else {
    /* Any other value: the 8-bit set-up. */
    dbg_print_string(DAT_a0068ed8);
    hdmi_tx_reg_write8(port,TX_BANK_0,TX_REG_12F,(reg_12f | 0x20) & 0xa7);
    hdmi_tx_reg_write8(port,TX_BANK_0,TX_REG_4A,reg_4a);
    hdmi_tx_set_deep_color_bit(port,0);
  }
  return;
}
