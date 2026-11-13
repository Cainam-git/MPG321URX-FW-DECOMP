/* sys_latch_unit_event_ch6  (FUN_a002f0b4)
 *
 * Clear the two unit 6 registers at 0xCF008330/34 and mark event bit 6.
 * Note: No control bit write for this unit; event bits collect in word 0xA802C9E4.
 * Name basis: descriptive - code only; family of identical per-unit handlers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002f0b4 @ 0xa002f0b4, flags -mcpu=v8 -O2 -g (section default).
 * Leaf. The stores are in the order register 0, event bit, register 4, as in the firmware.
 */
#define UNIT_EVENT_CH6 0x40             /* bit 6 of sys_unit_event_bits: unit 6 */

/* The two registers of unit 6 that are cleared. */
#define unit6_reg_0 (*(volatile unsigned int *)0xcf008330)
#define unit6_reg_4 (*(volatile unsigned int *)0xcf008334)
extern unsigned int sys_unit_event_bits;

/*
 * Handler of unit 6: clear its two registers at 0xCF008330 and 0xCF008334 and mark event bit 6 in
 * sys_unit_event_bits. Unlike units 0 to 3 it does not call reg_set_channel_ctrl_bit.
 */
void sys_latch_unit_event_ch6(void)
{
    unit6_reg_0 = 0;
    sys_unit_event_bits |= UNIT_EVENT_CH6;
    unit6_reg_4 = 0;
}
