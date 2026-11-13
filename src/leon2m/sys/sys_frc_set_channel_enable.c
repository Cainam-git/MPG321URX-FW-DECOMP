/* sys_frc_set_channel_enable  (FUN_a0109554)
 *
 * Set or clear the enable bit of a converter channel.
 * Name basis: derived - bit n of 0xCF011A00
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0109554 @ 0xa0109554, flags -mcpu=v8 -O3 -g.
 * Source form: one read-modify-write through a volatile register, in either case.
 */
#define REG_CF011A00 (*(volatile unsigned int *)0xcf011a00)

/*
 * Set (on != 0) or clear bit `source_class` of the register 0xCF011A00.
 *
 * Called by GMDHEnableFRC, sys_run_app_timer_task and sys_mode_enter_state_c, in each case with sys_get_channel_source_class(3) and on = 0.
 */
void sys_frc_set_channel_enable(unsigned char source_class, unsigned char on)
{
    if (on)
        REG_CF011A00 |= 1 << source_class;
    else
        REG_CF011A00 &= ~(1 << source_class);
}
