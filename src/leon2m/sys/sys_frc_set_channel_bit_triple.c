/* sys_frc_set_channel_bit_triple  (FUN_a01084a8)
 *
 * Set or clear a converter channel's bit in three registers.
 * Name basis: descriptive - used when the FRC mode changes
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01084a8 @ 0xa01084a8, flags -mcpu=v8 -O3 -g.
 * Source form: constant-address register macros in every statement and the mask written inline as
 * (1 << source_class) in each statement (no mask variable): the compiler hoists the per-arm address computations
 * above the branch, which gives the firmware's extra register copies; a 'mask' local changes the register choice.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern int dbg_printf();

/*
 * Set (on != 0) or clear bit `source_class` in each of the three registers 0xCF011800, 0xCF011A00 and
 * 0xCF011BF8, and print "SetFRCCHRW(bit) on" first.
 * Setting goes in the order 0xCF011800, 0xCF011A00, 0xCF011BF8; clearing goes in the reverse order.
 *
 * Called by SYSAPI_ConfigSystemPIPMode, the OLED frame-rate-converter handler (oled_frc_task), GMDHEnableFRC and two
 * more routines, mostly with sys_get_channel_source_class(channel) as the bit number.
 */
void sys_frc_set_channel_bit_triple(unsigned char source_class, unsigned char on)
{
    dbg_printf("\033[1;31m---->SetFRCCHRW(%d) %d\r\n\033[m", source_class, on);
    if (on) {
        R(0xcf011800) |= (1 << source_class);
        R(0xcf011a00) |= (1 << source_class);
        R(0xcf011bf8) |= (1 << source_class);
    } else {
        R(0xcf011bf8) &= ~(1 << source_class);
        R(0xcf011a00) &= ~(1 << source_class);
        R(0xcf011800) &= ~(1 << source_class);
    }
}
