/* sys_latch_unit_event_ch3  (FUN_a002f04c)
 *
 * Clear the two unit 3 registers at 0xCF007730/34, set control bit 3 and mark event bit 3.
 *   param_1: returned unchanged
 * Returns: param_1
 * Note: Event bits collect in word 0xA802C9E4.
 * Name basis: descriptive - code only; family of identical per-unit handlers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002f04c @ 0xa002f04c, flags -mcpu=v8 -O3 -g.
 * Clears 0xCF007730 and 0xCF007734, calls reg_set_channel_ctrl_bit(3, 1), sets bit 3 of sys_unit_event_bits and returns its first
 * argument. reg_set_channel_ctrl_bit is declared with an empty parameter list.
 */
extern unsigned int sys_unit_event_bits;
extern int reg_set_channel_ctrl_bit();

#define UNIT_EVENT_CH3 0x08             /* bit 3 of sys_unit_event_bits: unit 3 */

/* The two registers of unit 3 that are cleared. */
#define unit3_reg_0 (*(volatile unsigned int *)0xcf007730)
#define unit3_reg_4 (*(volatile unsigned int *)0xcf007734)

/*
 * Handler of unit 3: clear its two registers at 0xCF007730 and 0xCF007734, set control bit 3 with
 * reg_set_channel_ctrl_bit(3, 1) and mark event bit 3 in sys_unit_event_bits. The first argument is returned
 * unchanged; the second is not used.
 * Units 0 to 3 have the same handler; the registers of consecutive units lie 0x400 apart.
 */
unsigned int sys_latch_unit_event_ch3(unsigned int value, unsigned int unused)
{
  unit3_reg_0 = 0;
  unit3_reg_4 = 0;
  reg_set_channel_ctrl_bit(3, 1);
  sys_unit_event_bits = sys_unit_event_bits | UNIT_EVENT_CH3;
  return value;
}
