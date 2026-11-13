/* dp_tx_set_ctrl_bit1  (FUN_a0088f4c)
 *
 * Clear bit 1 of control register 0xCF018E80 for mode 1, set it otherwise.
 *   mode
 * Name basis: descriptive - single register update
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: the mode compare is against the character constant '\x01'.
 */
#define _DAT_cf018e80 (*(volatile unsigned int *)0xcf018e80)

/*
 * Clear bit 1 of register 0xCF018E80 when mode is 1, set it for any other value.
 *
 *   mode: 1 = clear the bit
 *
 * Called by dp_tx_set_reg70_bit4 (with mode 1) when output 0 is switched off.
 */
void dp_tx_set_ctrl_bit1(unsigned char mode)
{
  if (mode == '\x01') {
    _DAT_cf018e80 = _DAT_cf018e80 & 0xfffffffd;
  }
  else {
    _DAT_cf018e80 = _DAT_cf018e80 | 2;
  }
  return;
}
