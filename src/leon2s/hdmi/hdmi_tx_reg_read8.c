/* hdmi_tx_reg_read8  (FUN_a00a7fd8)
 *
 * Read a byte register of a bank of an HDMI transmitter.
 *   port: HDMI TX port 0/1
 *   bank: bank 0..5
 *   reg: register
 * Returns: byte, 0 when invalid
 * Name basis: proven - block table 0xA00B4D44 = 2 ports x 6 banks (0 core/packets, 1 PHY, 2/3 EMP, 4 FRL)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a7fd8 @ 0xa00a7fd8, flags -mcpu=v8 -Os -g.
 * The two range tests are kept as separate flag variables; the base table is a byte symbol indexed by byte
 * offset ((port * 6 + bank) * 2).
 */
/* Base of the registers of each bank of each HDMI transmitter port: 16-bit entries, six banks per port
   (index port * 6 + bank). Bank 1 is the PHY, bank 2 the HDR dynamic metadata packet, bank 3 the VTEM packet. */
extern unsigned char hdmi_tx_reg_bases;

/* Read the low byte of register reg of a bank (0..5) of HDMI transmitter port 0 or 1 (address
   0xCF000000 | ((base + reg) * 4)). Any other port or bank reads 0. */
short hdmi_tx_reg_read8(unsigned int port, unsigned short bank, unsigned short reg)
{
  unsigned int value;
  unsigned int bad_port;
  unsigned int bad_bank;

  value = 0;
  bad_port = (port & 0xff) > 1;
  bad_bank = ((unsigned char)bank) > 5;
  if (bad_port || bad_bank) {
    return value;
  }
  value = *(volatile unsigned int *)((*(unsigned short *)(&hdmi_tx_reg_bases + ((port & 0xff) * 6 + ((unsigned char)bank)) * 2) + (reg & 0xffff))
                    * 4 | 0xcf000000) & 0xff;
  return value;
}
