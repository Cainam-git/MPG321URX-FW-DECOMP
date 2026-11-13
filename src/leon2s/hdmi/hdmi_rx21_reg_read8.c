/* hdmi_rx21_reg_read8  (FUN_a00a69b4)
 *
 * Read a byte register of an HDMI 2.1 receiver.
 *   receiver: receiver 0/1
 *   reg: register
 * Returns: byte
 * Name basis: derived - block table 0xA00B4D98 = 0x9000 / 0xA000, the HDMI 2.1 receiver blocks
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a69b4 @ 0xa00a69b4, flags -mcpu=v8 -Os -g.
 * One of seven identical helpers, one per register block (base tables at 0xa00b4d40/4d6c/4d7a/4d90/4d94/4d98/4d9c).
 * The base table is declared as a single unsigned short and indexed through its address.
 */
/* The base of each HDMI 2.1 receiver's registers is a 16-bit entry of this table (0x9000 / 0xA000). */
extern unsigned short hdmi_rx21_reg_bases;

/* Read the low byte of register reg of HDMI 2.1 receiver 0 or 1 (address 0xCF000000 | ((base + reg) * 4)).
   Any other receiver reads 0. */
unsigned int hdmi_rx21_reg_read8(unsigned int receiver, unsigned short reg)

{
  unsigned int value;

  value = 0;
  if ((receiver & 0xff) < 2) {
    value = *(volatile unsigned int *)(((unsigned short)(&hdmi_rx21_reg_bases)[receiver & 0xff] + (reg & 0xffff)) * 4 |
                     0xcf000000) & 0xff;
  }
  return value;
}
