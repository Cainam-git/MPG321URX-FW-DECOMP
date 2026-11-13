/* sys_latch_unit_event_ch1  (FUN_a002efd4)
 *
 * Clear the two unit 1 registers at 0xCF006F30/34, set control bit 1 and mark event bit 1.
 *   param_1: returned unchanged
 * Returns: param_1
 * Note: Event bits collect in word 0xA802C9E4.
 * Name basis: descriptive - code only; family of identical per-unit handlers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002efd4 @ 0xa002efd4, flags -mcpu=v8 -O3 -g.
 * Clears 0xCF006F30 and 0xCF006F34, calls reg_set_channel_ctrl_bit(1, 1), sets bit 1 of sys_unit_event_bits and returns its first
 * argument. reg_set_channel_ctrl_bit is declared with an empty parameter list.
 */
extern unsigned int sys_unit_event_bits;
extern int reg_set_channel_ctrl_bit();

#define UNIT_EVENT_CH1 0x02             /* bit 1 of sys_unit_event_bits: unit 1 */

/* The two registers of unit 1 that are cleared. */
#define unit1_reg_0 (*(volatile unsigned int *)0xcf006f30)
#define unit1_reg_4 (*(volatile unsigned int *)0xcf006f34)

/*
 * Handler of unit 1: clear its two registers at 0xCF006F30 and 0xCF006F34, set control bit 1 with
 * reg_set_channel_ctrl_bit(1, 1) and mark event bit 1 in sys_unit_event_bits. The first argument is returned
 * unchanged; the second is not used.
 * Units 0 to 3 have the same handler; the registers of consecutive units lie 0x400 apart.
 */
unsigned int sys_latch_unit_event_ch1(unsigned int value, unsigned int unused)
{
  unit1_reg_0 = 0;
  unit1_reg_4 = 0;
  reg_set_channel_ctrl_bit(1, 1);
  sys_unit_event_bits = sys_unit_event_bits | UNIT_EVENT_CH1;
  return value;
}
