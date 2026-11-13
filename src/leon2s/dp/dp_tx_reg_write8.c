/* dp_tx_reg_write8  (FUN_a00a78fc)
 *
 * Write a byte register of a DP / eDP transmitter.
 *   output: output 0..4
 *   reg: register
 *   value
 * Name basis: proven - block table 0xA00B4D7A; AUX request registers 0x30/0x31
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: the base table is declared as an unsigned char and the entry is read through a cast to
 * unsigned short at byte offset output * 2; the store is through a non-volatile pointer.
 */
extern unsigned char dp_tx_reg_bases;

/*
 * Write a byte register of a DP transmitter output (output 0 = DPTX, 1..4 = eDP). Outputs above 4 write
 * nothing. Counterpart of dp_tx_reg_read8; same address scheme.
 *
 *   output: 0..4
 *   reg:    register number
 *   value:  only the low byte is written
 */
void dp_tx_reg_write8(unsigned int output, unsigned short reg, unsigned int value)

{
  if ((output & 0xff) < 5) {
    *(unsigned int *)(((unsigned int)*(unsigned short *)(&dp_tx_reg_bases + (output & 0xff) * 2) + (reg & 0xffff)) * 4 |
             0xcf000000) = value & 0xff;
  }
}
