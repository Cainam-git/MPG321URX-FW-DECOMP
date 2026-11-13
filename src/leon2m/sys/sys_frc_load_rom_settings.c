/* sys_frc_load_rom_settings  (FUN_a0112b2c)
 *
 * Load the ROM settings selected by the two stored indexes into the frame-rate converter.
 * Name basis: descriptive - words of the ROM set to sys_frc_write_setting_values
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0112b2c @ 0xa0112b2c-0xa0112db0 (161 words), flags -mcpu=v8 -O3 -g.
 * Source form: the selected set is written out again in every statement (macro ROM_SET), because the firmware
 * reads both index bytes again after each call.
 */
/* One settings set in ROM: 24 words (96 bytes). Two sets per first index. */
struct frc_setting_set { unsigned int w[24]; };
extern const struct frc_setting_set sys_frc_rom_settings[][2];
extern unsigned char sys_frc_config_index, sys_frc_config_index2;
extern unsigned int sys_region_base_first, sys_region_base_second, sys_region_base_third;
extern void sys_frc_write_setting_values(unsigned char, unsigned int, unsigned int, unsigned int);

/* the set selected by the two index bytes; read again after every call */
#define ROM_SET sys_frc_rom_settings[sys_frc_config_index][sys_frc_config_index2]

/*
 * Load the ROM settings set chosen by sys_frc_config_index and sys_frc_config_index2.
 *
 * Words 0..20 of the set go to sys_frc_write_setting_values in nine calls: setting 0 to 4 take three words
 * each (words 0..14), setting 5 takes word 15, setting 0xA takes words 16 and 17, setting 0xB takes words 18 and
 * 19, setting 0x13 takes word 20; unused word slots are passed as 0. Words 21, 22 and 23 are then stored in
 * sys_region_base_second, sys_region_base_third and sys_region_base_first.
 * Called by startup_init_display_clocks and sys_frc_switch_mode.
 */
void sys_frc_load_rom_settings(void)
{
    sys_frc_write_setting_values(0, ROM_SET.w[0], ROM_SET.w[1], ROM_SET.w[2]);
    sys_frc_write_setting_values(1, ROM_SET.w[3], ROM_SET.w[4], ROM_SET.w[5]);
    sys_frc_write_setting_values(2, ROM_SET.w[6], ROM_SET.w[7], ROM_SET.w[8]);
    sys_frc_write_setting_values(3, ROM_SET.w[9], ROM_SET.w[10], ROM_SET.w[11]);
    sys_frc_write_setting_values(4, ROM_SET.w[12], ROM_SET.w[13], ROM_SET.w[14]);
    sys_frc_write_setting_values(5, ROM_SET.w[15], 0, 0);
    sys_frc_write_setting_values(0xa, ROM_SET.w[16], ROM_SET.w[17], 0);
    sys_frc_write_setting_values(0xb, ROM_SET.w[18], ROM_SET.w[19], 0);
    sys_frc_write_setting_values(0x13, ROM_SET.w[20], 0, 0);
    sys_region_base_second = ROM_SET.w[21];
    sys_region_base_third = ROM_SET.w[22];
    sys_region_base_first = ROM_SET.w[23];
}
