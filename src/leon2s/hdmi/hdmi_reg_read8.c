/* hdmi_reg_read8  (FUN_a00a657c)
 *
 * Read a byte register of an HDMI 2.0 receiver.
 *   receiver: receiver 0/1
 *   reg: register
 * Returns: byte, 0 for other ports
 * Name basis: proven - block table 0xA00B4D9C (HDMI 2.0 receivers 0/1); used for registers 0x3A.. (timing) and
 *   packets
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a657c @ 0xa00a657c, flags -mcpu=v8 -Os -g.
 * One of seven identical helpers, one per register block (base tables at 0xa00b4d40/4d6c/4d7a/4d90/4d94/4d98/4d9c).
 * The base table is declared as a single unsigned short and indexed through its address.
 */
/* Register address = 0xCF000000 | ((base + reg) * 4); the base of each HDMI 2.0 receiver is a 16-bit entry of this table. */
extern unsigned short hdmi_reg_bases;

/* Read the low byte of register reg of HDMI 2.0 receiver 0 or 1. Any other receiver reads 0. Used for the
   timing registers (0x3A..) and the packet registers. */
unsigned int hdmi_reg_read8(unsigned int receiver, unsigned short reg)

{
  unsigned int value;

  value = 0;
  if ((receiver & 0xff) < 2) {
    value = *(volatile unsigned int *)(((unsigned short)(&hdmi_reg_bases)[receiver & 0xff] + (reg & 0xffff)) * 4 |
                     0xcf000000) & 0xff;
  }
  return value;
}
