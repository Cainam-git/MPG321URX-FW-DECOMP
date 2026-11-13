/* sys_latch_unit_event_ch7  (FUN_a002f0e0)
 *
 * Clear the two unit 7 registers at 0xCF008730/34 and mark event bit 7.
 * Note: No control bit write for this unit; event bits collect in word 0xA802C9E4.
 * Name basis: descriptive - code only; family of identical per-unit handlers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002f0e0 @ 0xa002f0e0, flags -mcpu=v8 -O2 -g (section default).
 * Leaf. The stores are in the order register 0, event bit, register 4, as in the firmware.
 */
#define UNIT_EVENT_CH7 0x80             /* bit 7 of sys_unit_event_bits: unit 7 */

/* The two registers of unit 7 that are cleared. */
#define unit7_reg_0 (*(volatile unsigned int *)0xcf008730)
#define unit7_reg_4 (*(volatile unsigned int *)0xcf008734)
extern unsigned int sys_unit_event_bits;

/*
 * Handler of unit 7: clear its two registers at 0xCF008730 and 0xCF008734 and mark event bit 7 in
 * sys_unit_event_bits. Unlike units 0 to 3 it does not call reg_set_channel_ctrl_bit.
 */
void sys_latch_unit_event_ch7(void)
{
    unit7_reg_0 = 0;
    sys_unit_event_bits |= UNIT_EVENT_CH7;
    unit7_reg_4 = 0;
}
