/* dp_tx_reg_read8  (FUN_a00a78b4)
 *
 * Read a byte register of a DP / eDP transmitter.
 *   output: unit
 *   reg: register
 * Returns: byte, 0 for an invalid unit
 * Name basis: proven - block table 0xA00B4D7A (outputs 0..4: DPTX, eDP 1..4)
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: the base table is declared as an unsigned char and the entry is read through a cast to
 * unsigned short at byte offset output * 2.
 */
extern unsigned char dp_tx_reg_bases;

/*
 * Read a byte register of a DP transmitter output (output 0 = DPTX, 1..4 = eDP).
 *
 *   output: 0..4; any other value reads 0
 *   reg:    register number
 *
 * The register is the word at 0xCF000000 | ((base[output] + reg) * 4), with the halfword table
 * dp_tx_reg_bases (0xA00B4D7A); the low byte is returned.
 */
unsigned char dp_tx_reg_read8(unsigned int output, unsigned short reg)

{
  unsigned int value;
  
  value = 0;
  if ((output & 0xff) < 5) {
    value = *(volatile unsigned int *)((*(unsigned short *)(&dp_tx_reg_bases + (output & 0xff) * 2) + (reg & 0xffff))
                      * 4 | 0xcf000000) & 0xff;
  }
  return value;
}
