/* hdmi_tx_sys_reg_update_bits  (FUN_a00a8260)
 *
 * Set or clear masked bits of a byte register of an HDMI transmitter system block.
 *   port: HDMI TX port
 *   reg: register
 *   bits
 *   set: 1 = set
 * Name basis: derived - block table 0xA00B4D40; callers hdmi_tx_set_regfd_mode, hdmi_tx_set_bank4_mode, the
 *   packet switch
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a8260, flags -mcpu=v8 -Os -g.
 * Source form: the register address is computed twice (once for the read, once for the store) with a different
 * form of the register argument each time (shift pair for the read, unsigned short cast for the store); the
 * variable that holds the register value is an unsigned char.
 */
extern unsigned char hdmi_tx_sys_reg_bases;

#define REGISTER_SPACE 0xcf000000       /* register address = REGISTER_SPACE | ((block base + register) * 4) */
#define HDMI_TX_SYS_PORTS 2             /* the two HDMI transmitter system blocks */

/*
 * Set or clear bits of a byte register of an HDMI transmitter system block.
 *   port: HDMI TX port (0 or 1; any other value does nothing)
 *   reg:  register number inside the system block
 *   bits: the bits to change
 *   set:  1 = set the bits, any other value = clear them
 * The base of each block comes from the halfword table hdmi_tx_sys_reg_bases.
 */
void hdmi_tx_sys_reg_update_bits(unsigned int port, short reg, unsigned int bits, unsigned int set)
{
  unsigned int reg_number;
  unsigned char value;
  if ((port & 0xff) < HDMI_TX_SYS_PORTS)
  {
    reg_number = reg;
    reg_number = (((*((unsigned short *) ((&hdmi_tx_sys_reg_bases) + ((port & 0xff) * 2)))) + ((reg_number << 16) >> 16)) * 4) | REGISTER_SPACE;
    value = *((unsigned int *) reg_number);
    if ((set & 0xff) == 1)
    {
      value |= bits;
    }
    else
    {
      value &= ~bits;
    }
    *((unsigned int *) ((((*((unsigned short *) ((&hdmi_tx_sys_reg_bases) + ((port & 0xff) * 2)))) + (unsigned short)reg) * 4) | REGISTER_SPACE)) = value & 0xff;
  }
}
