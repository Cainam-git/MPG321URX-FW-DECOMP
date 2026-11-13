/* dp_reg_read8  (FUN_a00a6bb8)
 *
 * Read a byte register of a DP receiver.
 *   receiver: receiver 0/1
 *   reg: register
 * Returns: byte, 0 for other ports
 * Name basis: proven - block table 0xA00B4D94 (DP receivers 0/1); mailbox command 0x22
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: the base table is declared as a single unsigned short and indexed through its address; the
 * receiver number and register are masked as in the firmware (& 0xff, & 0xffff).
 */
extern unsigned short dp_reg_bases;

/*
 * Read a byte register of a DP receiver (receivers 0 and 1).
 *
 *   receiver: 0 or 1; any other value reads 0
 *   reg:      register number
 *
 * The register is the word at 0xCF000000 | ((dp_reg_bases[receiver] + reg) * 4); the low byte is returned.
 * Same scheme as the other register helpers of the block tables at 0xA00B4D40 .. 0xA00B4D9C.
 */
unsigned int dp_reg_read8(unsigned int receiver, unsigned short reg)

{
  unsigned int value;
  
  value = 0;
  if ((receiver & 0xff) < 2) {
    value = *(volatile unsigned int *)(((unsigned short)(&dp_reg_bases)[receiver & 0xff] + (reg & 0xffff)) * 4 |
                     0xcf000000) & 0xff;
  }
  return value;
}
