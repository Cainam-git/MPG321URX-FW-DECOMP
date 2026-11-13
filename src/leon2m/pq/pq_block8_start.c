/* pq_block8_start  (FUN_a01185d4)
 *
 * Start picture block 8 again after a short wait.
 * Name basis: descriptive - register sequence with a delay, then 1 to 0xCF012E80
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01185d4 @ 0xa01185d4-0xa0118628 (21 words), flags -mcpu=v8 -O3 -g.
 * Source form: only the 0xCF... registers are volatile; BLOCK8_E80 gets the constant 1 after the wait.
 */
#define REG(a) (*(volatile unsigned int *)(a))

#define FRC_CHANNEL_ON      0xcf011800
#define FRC_CTRL            0xcf011a00
#define BLOCK8_FRC_BIT      0x20            /* set in both here, cleared by pq_block8_stop */
#define BLOCK8_E00          0xcf012e00      /* bit 0 cleared by pq_block8_stop */
#define BLOCK8_E80          0xcf012e80      /* 1 here, 0 in pq_block8_stop */
#define START_WAIT_TICKS    0x32            /* timer_sleep_ticks: 50 */

extern void timer_sleep_ticks(int);

/*
 * Set again the three bits that pq_block8_stop clears, wait 50 ticks, then write 1 to BLOCK8_E80.
 *
 * Called by sys_frc_enable_channels, sys_frc_switch_mode, pq_apply_response_level and the memory test
 * routines (dbg_ddr_*).
 */
void pq_block8_start(void)
{
  REG(FRC_CHANNEL_ON) |= BLOCK8_FRC_BIT;
  REG(FRC_CTRL) |= BLOCK8_FRC_BIT;
  REG(BLOCK8_E00) |= 1;
  timer_sleep_ticks(START_WAIT_TICKS);
  REG(BLOCK8_E80) = 1;
}
