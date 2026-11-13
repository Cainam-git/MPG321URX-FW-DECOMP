/* hdmi_tx_sys_reg_read8  (FUN_a00a82e4)
 *
 * Read a byte register of an HDMI transmitter system block.
 *   port: unit
 *   reg: register
 * Returns: byte, 0 for an invalid unit
 * Name basis: derived - block table 0xA00B4D40 (0x6000 / 0x6100); caller hdmi_tx_reset_keep_packets
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a82e4, flags -mcpu=v8 -Os -g.
 * Source form: the register is read through a volatile unsigned int pointer.
 */
extern unsigned char hdmi_tx_sys_reg_bases;

#define REGISTER_SPACE 0xcf000000       /* register address = REGISTER_SPACE | ((block base + register) * 4) */
#define HDMI_TX_SYS_PORTS 2             /* the two HDMI transmitter system blocks */

/*
 * Read a byte register of an HDMI transmitter system block.
 *   port: HDMI TX port (0 or 1)
 *   reg:  register number inside the system block
 * Returns the low 8 bits of the register, or 0 for any other port.
 */
unsigned int hdmi_tx_sys_reg_read8(unsigned int port, unsigned short reg)

{
  unsigned int value;

  value = 0;
  if ((port & 0xff) < HDMI_TX_SYS_PORTS) {
    value = *(volatile unsigned int *)((*(unsigned short *)(&hdmi_tx_sys_reg_bases + (port & 0xff) * 2) + (reg & 0xffff))
                      * 4 | REGISTER_SPACE) & 0xff;
  }
  return value;
}
