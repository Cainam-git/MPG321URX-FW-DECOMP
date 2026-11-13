/* dp_status_reg_read8  (FUN_a00a6f78)
 *
 * Read a byte register of a DP receiver status block.
 *   unit
 *   reg: register
 * Returns: byte, 0 for an invalid unit
 * Name basis: derived - block table 0xA00B4D90 (0xEC0 / 0xFC0); callers audio_dp_status_bit6,
 *   dp_get_color_depth, reg_read_port_indirect
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: the base table is declared as a single unsigned short and indexed through its address.
 */
extern unsigned short dp_status_reg_bases;

/*
 * Read a byte register of a DP receiver status block (units 0 and 1).
 *
 *   unit: 0 or 1; any other value reads 0
 *   reg:  register number
 *
 * Address scheme as in dp_reg_read8, with the base table dp_status_reg_bases (0xA00B4D90). The status
 * routines of the audio and receiver code use it, for example audio_dp_status_bit6.
 */
unsigned int dp_status_reg_read8(unsigned int unit, unsigned short reg)

{
  unsigned int value;
  
  value = 0;
  if ((unit & 0xff) < 2) {
    value = *(volatile unsigned int *)(((unsigned short)(&dp_status_reg_bases)[unit & 0xff] + (reg & 0xffff)) * 4 |
                     0xcf000000) & 0xff;
  }
  return value;
}
