/* sys_latch_unit_event_ch2  (FUN_a002f010)
 *
 * Clear the two unit 2 registers at 0xCF007330/34, set control bit 2 and mark event bit 2.
 *   param_1: returned unchanged
 * Returns: param_1
 * Note: Event bits collect in word 0xA802C9E4.
 * Name basis: descriptive - code only; family of identical per-unit handlers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002f010 @ 0xa002f010, flags -mcpu=v8 -O3 -g.
 * Clears 0xCF007330 and 0xCF007334, calls reg_set_channel_ctrl_bit(2, 1), sets bit 2 of sys_unit_event_bits and returns its first
 * argument. reg_set_channel_ctrl_bit is declared with an empty parameter list.
 */
extern unsigned int sys_unit_event_bits;
extern int reg_set_channel_ctrl_bit();

#define UNIT_EVENT_CH2 0x04             /* bit 2 of sys_unit_event_bits: unit 2 */

/* The two registers of unit 2 that are cleared. */
#define unit2_reg_0 (*(volatile unsigned int *)0xcf007330)
#define unit2_reg_4 (*(volatile unsigned int *)0xcf007334)

/*
 * Handler of unit 2: clear its two registers at 0xCF007330 and 0xCF007334, set control bit 2 with
 * reg_set_channel_ctrl_bit(2, 1) and mark event bit 2 in sys_unit_event_bits. The first argument is returned
 * unchanged; the second is not used.
 * Units 0 to 3 have the same handler; the registers of consecutive units lie 0x400 apart.
 */
unsigned int sys_latch_unit_event_ch2(unsigned int value, unsigned int unused)
{
  unit2_reg_0 = 0;
  unit2_reg_4 = 0;
  reg_set_channel_ctrl_bit(2, 1);
  sys_unit_event_bits = sys_unit_event_bits | UNIT_EVENT_CH2;
  return value;
}
