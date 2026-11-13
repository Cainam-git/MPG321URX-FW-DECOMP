/* sys_frc_set_source_class_enable  (FUN_a0109474)
 *
 * Set or clear the enable bit of source class 1, 2 or 3.
 * Name basis: derived - bit 7 of 0xCF011AA4 / 0xCF011AA8 / 0xCF011AAC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0109474 @ 0xa0109474, flags -mcpu=v8 -O3 -g.
 * Source form: a switch over three cases (compiled as a compare chain).
 */
#define REG_cf011aa4 (*(volatile unsigned int *)0xcf011aa4)
#define REG_cf011aa8 (*(volatile unsigned int *)0xcf011aa8)
#define REG_cf011aac (*(volatile unsigned int *)0xcf011aac)

/*
 * Set (on != 0) or clear bit 7 of the register chosen by `source_class`: 1 = 0xCF011AA4, 2 = 0xCF011AA8,
 * 3 = 0xCF011AAC. Other values do nothing.
 *
 * Called by osd_apply_screen_size, GMDHEnableFRC, sys_set_channel_enable, sys_apply_pip_layout,
 * sys_api_rebuild_channel_window, sys_api_stop_channel and sys_api_set_channel_source_enable.
 */
void sys_frc_set_source_class_enable(unsigned char source_class, unsigned char on)
{
    switch (source_class) {
    case 1:
        if (on)
            REG_cf011aa4 |= 0x80;
        else
            REG_cf011aa4 &= ~0x80;
        break;
    case 2:
        if (on)
            REG_cf011aa8 |= 0x80;
        else
            REG_cf011aa8 &= ~0x80;
        break;
    case 3:
        if (on)
            REG_cf011aac |= 0x80;
        else
            REG_cf011aac &= ~0x80;
        break;
    }
}
