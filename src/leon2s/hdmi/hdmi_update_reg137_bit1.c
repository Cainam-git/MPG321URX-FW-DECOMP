/* hdmi_update_reg137_bit1  (FUN_a008f744)
 *
 * Set or clear bit 1 of HDMI receiver register 0x137 from status regs 0x281/0x282.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: descriptive - reg 0x282 & (reg 0x281 & 0xF); caller the receiver status poll
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008f744 @ 0xa008f744-0xa008f79c (22 words), flags -mcpu=v8 -Os -g.
 * Source form: the read of register 0x282 is written first in the '&' (the other order does not give the
 * firmware's 'btst'); both arms are one tail call.
 */

#define RX_REG_137  0x137
#define RX_REG_281  0x281
#define RX_REG_282  0x282

extern unsigned int hdmi_reg_read8(unsigned int, unsigned short);
extern void hdmi_reg_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);

/* Called by hdmi_poll_rx_status when bit 7 of status register 0x74 is set. Bit 1 of register 0x137 is set when
   register 0x282 has a bit in common with the low four bits of register 0x281, and cleared otherwise. */
void hdmi_update_reg137_bit1(unsigned char port)
{
    unsigned int low_nibble = hdmi_reg_read8(port, RX_REG_281) & 0xf;
    if (hdmi_reg_read8(port, RX_REG_282) & low_nibble)
        hdmi_reg_update_bits(port, RX_REG_137, 2, 1);
    else
        hdmi_reg_update_bits(port, RX_REG_137, 2, 0);
}
