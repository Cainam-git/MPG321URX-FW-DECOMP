/* input_block0_toggle_pre_frc  (FUN_a00f9880)
 *
 * Toggle the pre-converter bit of input block 0 with a short wait in between.
 * Name basis: proven - prints 'toggle for preFRC'; bit 3 of register 3
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f9880 @ 0xa00f9880, flags -mcpu=v8 -O2 -g.
 * The wait is called as FUN_4008d1a0 (the alias of timer_sleep_ticks).
 */
extern unsigned char sys_frc_get_enable_bit4(void);
extern unsigned char input_capture_read8(unsigned char blk, unsigned char reg);
extern void input_capture_update_bits(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern int timer_sleep_ticks(int, ...);
extern int dbg_printf(const char *fmt, ...);

/* Switch bit 3 of register 3 of capture block 0 off and on again, with a wait of 0x28 + 1 timer ticks between,
 * and print "toggle for preFRC". Does nothing unless the converter enable bit (sys_frc_get_enable_bit4) is set
 * and bit 3 of register 3 is set. Called by sys_channel0_apply_timing_block and sys_channel_apply_output_timing. */
void input_block0_toggle_pre_frc(void)
{
    if (sys_frc_get_enable_bit4() && (input_capture_read8(0, 3) & 8)) {
        input_capture_update_bits(0, 3, 8, 0);
        timer_sleep_ticks(0x28);
        input_capture_update_bits(0, 3, 8, 1);
        dbg_printf("\033[1;31mtoggle for preFRC\r\n\033[m");
    }
}
