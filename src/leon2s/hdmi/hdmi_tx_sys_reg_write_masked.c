/* hdmi_tx_sys_reg_write_masked  (FUN_a00a8210)
 *
 * Replace the masked bits of a register of an HDMI transmitter system block.
 *   port: HDMI TX port
 *   reg: register
 *   mask
 *   bits
 * Name basis: derived - block table 0xA00B4D40 (0x6000 / 0x6100); caller hdmi_tx_reset_keep_packets
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a8210, flags -mcpu=v8 -Os -g.
 * Source form: the register is reached through a plain (not volatile) unsigned int pointer; the stored value is
 * masked to 8 bits after the merge.
 */
extern unsigned char hdmi_tx_sys_reg_bases;

#define REGISTER_SPACE 0xcf000000       /* register address = REGISTER_SPACE | ((block base + register) * 4) */
#define HDMI_TX_SYS_PORTS 2             /* the two HDMI transmitter system blocks */

/*
 * Replace the masked bits of a byte register of an HDMI transmitter system block: the bits in `mask` are
 * cleared, then the bits in `bits` are ORed in. Only the low 8 bits are stored.
 *   port: HDMI TX port (0 or 1; any other value does nothing)
 *   reg:  register number inside the system block
 *   mask: bits to clear
 *   bits: bits to set after the clearing
 * The base of each block comes from the halfword table hdmi_tx_sys_reg_bases.
 */
void hdmi_tx_sys_reg_write_masked(unsigned int port, unsigned short reg, unsigned int mask, unsigned int bits)

{
  unsigned int *reg_addr;

  if ((port & 0xff) < HDMI_TX_SYS_PORTS) {
    reg_addr = (unsigned int *)(((unsigned int)*(unsigned short *)(&hdmi_tx_sys_reg_bases + (port & 0xff) * 2) + (reg & 0xffff))
                      * 4 | REGISTER_SPACE);
    *reg_addr = (*reg_addr & ~mask | bits) & 0xff;
  }
  return;
}
