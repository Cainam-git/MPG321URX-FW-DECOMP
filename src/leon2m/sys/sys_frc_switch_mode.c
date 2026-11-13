/* sys_frc_switch_mode  (FUN_a01131d4)
 *
 * Switch the frame-rate converter to another mode and reload its settings.
 * Name basis: derived - masks the enabled channels, reloads, restores; called from GMDHEnableFRC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01131d4, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - FRC_CTRL is read twice, into two separate variables, before the mode is stored;
 *  - the two loops over the five channel bits are written as (x >> i) & 1 tests with the register updated
 *    in place (R(reg) &= / |=); R is volatile.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define FRC_CTRL        0xcf011a00      /* bits 0..4: the five channels are on; bit 5 is read back and restored */
#define FRC_CHANNEL_ON  0xcf011800      /* bits 0..4 are cleared and set together with those of FRC_CTRL */
#define FRC_REG_1D8C    0xcf011d8c      /* cleared while the settings are reloaded */
#define FRC_CHANNELS    5               /* channel bits 0..4 */
#define FRC_SETTLE_TICKS 0x32           /* wait after the channels are off */

struct Row6 { unsigned char b[0x16]; };
extern const struct Row6 sys_frc_bit_group_table[][2];
extern unsigned char sys_frc_mode;
extern unsigned char sys_frc_config_index, sys_frc_config_index2;
extern void pq_block8_stop(void);
extern void sys_frc_apply_bit_groups(unsigned char, unsigned char);
extern void sys_frc_load_rom_settings(void);
extern void pq_block8_start(void);
extern void reg_set_channel_ctrl_bit(unsigned int, unsigned int);
extern void timer_sleep_ticks(int ms);

/*
 * Change the frame-rate converter to mode `mode` and reload its settings from the ROM.
 *
 *   mode  the new mode; stored in sys_frc_mode and as the second ROM index (sys_frc_config_index2)
 *
 * Nothing happens when the converter is already in that mode. Otherwise: remember which channels are on,
 * stop picture block 8, switch the channels off, wait, clear FRC_REG_1D8C, apply the six byte values of the
 * ROM row [sys_frc_config_index][mode] as bit groups (index = group number), load the ROM settings, then switch
 * the remembered channels on again and restart picture block 8 if bit 5 of FRC_CTRL had been set.
 * Called from GMDHEnableFRC with the result of sys_api_is_pip_mode_above_4.
 */
void sys_frc_switch_mode(unsigned char mode)
{
    unsigned char was_on, now_on, i;

    if (sys_frc_mode == mode)
        return;
    was_on = R(FRC_CTRL);
    now_on = R(FRC_CTRL);
    sys_frc_mode = mode;
    sys_frc_config_index2 = mode;
    pq_block8_stop();
    /* Switch off the channels that are on. */
    for (i = 0; i <= FRC_CHANNELS - 1; i++) {
        if ((now_on >> i) & 1) {
            reg_set_channel_ctrl_bit(i, 1);
            R(FRC_CHANNEL_ON) &= ~(1 << i);
            R(FRC_CTRL) &= ~(1 << i);
        }
    }
    timer_sleep_ticks(FRC_SETTLE_TICKS);
    R(FRC_REG_1D8C) = 0;
    for (i = 0; i <= 5; i++)
        sys_frc_apply_bit_groups(i, sys_frc_bit_group_table[sys_frc_config_index][sys_frc_config_index2].b[i]);
    sys_frc_load_rom_settings();
    /* Switch the channels back on that were on before. */
    for (i = 0; i <= FRC_CHANNELS - 1; i++) {
        if ((was_on >> i) & 1) {
            reg_set_channel_ctrl_bit(i, 0);
            R(FRC_CHANNEL_ON) |= 1 << i;
            R(FRC_CTRL) |= 1 << i;
        }
    }
    if (was_on & 0x20)
        pq_block8_start();
}
