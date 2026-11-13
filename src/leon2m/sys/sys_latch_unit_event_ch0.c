/* sys_latch_unit_event_ch0  (FUN_a002ef0c)
 *
 * Run the ROM step if its checks pass; clear two unit 0 registers, call the hook, mark event bit 0.
 * Note: The checks: picture block register 0x54 bits 0-1 and the FRC control registers 0xCF011AA0..AC. Always
 *   sets control bit 0 and bit 0 of 0xA802C9E4.
 * Name basis: descriptive - code only; no direct caller (handler); family with
 *   sys_latch_unit_event_ch1..sys_latch_unit_event_ch7
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002ef0c @ 0xa002ef0c..0xa002efd4 (200 bytes, 50 words)
 * Flags: -mcpu=v8 -O3 -g.
 * What it does (code facts): st = func_0x00092254(0, 0x54) (call to the absolute ROM address
 * 0x92254); only when (st & 3) == 0 AND 0xcf011aa0 & 0xf == 0 AND bit 7 of 0xcf011aa4,
 * 0xcf011aa8 and 0xcf011aac are all clear, it calls func_0x000ee758() (ROM 0xee758). Then it
 * clears the registers 0xcf006b30 and 0xcf006b34, calls the hook pointer sys_unit0_hook if it
 * is non-null, calls reg_set_channel_ctrl_bit(0, 1) and sets bit 0 of sys_unit_event_bits.
 * Callers: no direct 'call 0xa002ef0c' in asm/leon2m (reached via a pointer/table).
 * Aids: none. The hook takes NO argument ('void (*)(void)'). With an argument, 'sys_unit0_hook(0)', gcc sets
 * %o0 = 0 for the hook in the 'be' delay slot and reorg does not advance the branch past the clr %o0 at the join
 * (be target +84 vs fw +88); with no hook argument the delay-slot clr %o0 is reg_set_channel_ctrl_bit's first argument
 * stolen from the target, exactly as in the fw. The function returns nothing.
 * reg_set_channel_ctrl_bit = (bit, on): (int, unsigned char).
 */
extern int pq_block_read8(int, int);
extern int ipc_api_clear_audio_level_steps(void);
extern void reg_set_channel_ctrl_bit(unsigned int, unsigned char);
extern unsigned int sys_unit_event_bits;
extern void (*sys_unit0_hook)(void);

#define BLK_BLANK_MODE 0x54             /* picture block register read from block 0 */
#define UNIT_EVENT_CH0 0x01             /* bit 0 of sys_unit_event_bits: unit 0 */

/* Registers cleared at the end (unit 0). */
#define unit0_reg_0 (*(volatile unsigned int *)0xcf006b30)
#define unit0_reg_4 (*(volatile unsigned int *)0xcf006b34)
/* reg_sys_frc_active_control and the three registers after it; bit 7 of each of the last three is tested. */
#define reg_sys_frc_active_control (*(volatile unsigned int *)0xcf011aa0)
#define frc_control_1 (*(volatile unsigned int *)0xcf011aa4)
#define frc_control_2 (*(volatile unsigned int *)0xcf011aa8)
#define frc_control_3 (*(volatile unsigned int *)0xcf011aac)

/*
 * Handler of unit 0. It has no direct caller; it is reached through a pointer.
 *
 * It reads register 0x54 of picture block 0. Only when bits 0 and 1 of that value are clear, the low nibble of
 * reg_sys_frc_active_control is zero and bit 7 of each of the next three FRC control registers is clear, it calls
 * ipc_api_clear_audio_level_steps. After that, always: clear the two registers at 0xCF006B30 and 0xCF006B34, call
 * the unit 0 hook when one is registered, set control bit 0 (reg_set_channel_ctrl_bit) and mark event bit 0.
 */
void sys_latch_unit_event_ch0(void)
{
  unsigned int status = pq_block_read8(0, BLK_BLANK_MODE);

  if ((status & 3) == 0) {
    if ((reg_sys_frc_active_control & 0xf) == 0) {
      if ((frc_control_1 & 0x80) == 0) {
        if ((frc_control_2 & 0x80) == 0) {
          if ((frc_control_3 & 0x80) == 0)
            ipc_api_clear_audio_level_steps();
        }
      }
    }
  }
  unit0_reg_0 = 0;
  unit0_reg_4 = 0;
  if (sys_unit0_hook != 0)
    sys_unit0_hook();
  reg_set_channel_ctrl_bit(0, 1);
  sys_unit_event_bits |= UNIT_EVENT_CH0;
}
