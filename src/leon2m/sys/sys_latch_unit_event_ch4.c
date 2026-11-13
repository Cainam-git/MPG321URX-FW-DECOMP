/* sys_latch_unit_event_ch4  (FUN_a002f088)
 *
 * Clear the two unit 4 registers at 0xCF007B30/34 and mark event bit 4.
 * Note: No control bit write for this unit; event bits collect in word 0xA802C9E4.
 * Name basis: descriptive - code only; family of identical per-unit handlers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002f088 @ 0xa002f088, flags -mcpu=v8 -O2 -g (section default).
 * Leaf. The stores are in the order register 0, event bit, register 4, as in the firmware.
 */
#define UNIT_EVENT_CH4 0x10             /* bit 4 of sys_unit_event_bits: unit 4 */

/* The two registers of unit 4 that are cleared. */
#define unit4_reg_0 (*(volatile unsigned int *)0xcf007b30)
#define unit4_reg_4 (*(volatile unsigned int *)0xcf007b34)
extern unsigned int sys_unit_event_bits;

/*
 * Handler of unit 4: clear its two registers at 0xCF007B30 and 0xCF007B34 and mark event bit 4 in
 * sys_unit_event_bits. Unlike units 0 to 3 it does not call reg_set_channel_ctrl_bit.
 */
void sys_latch_unit_event_ch4(void)
{
    unit4_reg_0 = 0;
    sys_unit_event_bits |= UNIT_EVENT_CH4;
    unit4_reg_4 = 0;
}
