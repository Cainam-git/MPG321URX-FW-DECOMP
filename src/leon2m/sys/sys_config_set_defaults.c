/* sys_config_set_defaults  (FUN_a0151358)
 *
 * Set every field of the system configuration record (stSysConfig) to its default.
 * Name basis: derived - writes all fields of the record at 0xA802E3D0, which the firmware's texts call
 *   stSysConfig; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0151358 @ 0xa0151358, flags -mcpu=v8 -O3 -g.
 * Source form: one assignment per field. The order of the assignments decides the store order and the register
 * choice, so the statements stand in the order that gives the firmware bytes. The bit order of word +0 and the
 * order of the 4-bit fields of word +4 (28, 20, 24) are fixed by the masks in the code.
 */
/* The system configuration record (stSysConfig, docs/RECORDS.md). Only the part that is reset here is declared.
   Word +0 is a row of one-bit flags, word +4 holds three 4-bit fields. */
struct sys_config_record {
    unsigned int bit31:1, bit30:1, bit29:1, bit28:1, frc_lock_mode:1, main_bypass:1, bit25:1, bit24:1, bit23:1, bit22:1, bit21:1, bit20:1, bit19:1, bit18:1,
        reserved_0:10;
    unsigned char byte_3;
    unsigned int converter_mode:4, path_mode_ch0:4, path_mode_ch1:4, field_16:4;
    unsigned char byte_0x06, auto_level_mode;
    unsigned char brightness, color_gain, color_matrix_param, picture_mode, red_gain, green_gain, blue_gain, red_offset, green_offset, blue_offset, red_offset_first, green_offset_first, blue_offset_first, red_offset_second, green_offset_second, blue_offset_second, gamma_selection;
    unsigned char pad_0x19[3];
    unsigned char byte_0x1c, preset_index;
    unsigned char pad_0x1e[4];
    unsigned char byte_0x22, byte_0x23;
    unsigned char pad_0x24[10];
    unsigned char byte_0x2e, byte_0x2f, byte_0x30, byte_0x31, byte_0x32, byte_0x33, byte_0x34;
    unsigned char pad_0x35;
    unsigned short half_0x36;
};
extern struct sys_config_record sys_config;

/*
 * Reset the system configuration record to its starting values; the record is the one the sys_api_config
 * commands change. Nothing in the firmware calls this routine.
 *
 * Defaults: word +0 flags 31, 30, 29, 28, 26 (main bypass), 24, 23, 22, 19 and 18 cleared; flags 27 (post-FRC lock
 * mode), 25 and 21 set. The three 4-bit fields of word +4 (converter mode, path modes of channels 0 and 1) are
 * 0. Brightness 100; colour gain, the red/green/blue gains and the red/green/blue offsets 50; colour matrix
 * parameter and the six signed first/second offsets 0x80; bytes 0x2e, 0x2f and 0x33 set to 1; every other
 * byte written (+3, +6, +7, +0x0b, +0x18, +0x1c, +0x1d, +0x22, +0x23, +0x30 to +0x32, +0x34) and the halfword at
 * +0x36 set to 0.
 * The order of the assignments is not the order of the offsets; it is the order the firmware stores them.
 */
void sys_config_set_defaults(void)
{
    sys_config.bit31 = 0;
    sys_config.bit29 = 0;
    sys_config.bit25 = 1;
    sys_config.color_gain = 0x32;
    sys_config.bit24 = 0;
    sys_config.bit23 = 0;
    sys_config.auto_level_mode = 0;
    sys_config.bit28 = 0;
    sys_config.frc_lock_mode = 1;
    sys_config.byte_0x2e = 1;
    sys_config.byte_0x2f = 1;
    sys_config.brightness = 0x64;
    sys_config.main_bypass = 0;
    sys_config.picture_mode = 0;
    sys_config.bit22 = 0;
    sys_config.converter_mode = 0;
    sys_config.bit30 = 0;
    sys_config.gamma_selection = 0;
    sys_config.color_matrix_param = 0x80;
    sys_config.bit21 = 1;
    sys_config.byte_0x1c = 0;
    sys_config.bit19 = 0;
    sys_config.blue_gain = 0x32;
    sys_config.blue_offset = 0x32;
    sys_config.byte_0x06 = 0;
    sys_config.path_mode_ch1 = 0;
    sys_config.green_gain = 0x32;
    sys_config.preset_index = 0;
    sys_config.green_offset = 0x32;
    sys_config.byte_3 = 0;
    sys_config.red_gain = 0x32;
    sys_config.red_offset_first = 0x80;
    sys_config.green_offset_first = 0x80;
    sys_config.blue_offset_first = 0x80;
    sys_config.red_offset_second = 0x80;
    sys_config.green_offset_second = 0x80;
    sys_config.byte_0x22 = 0;
    sys_config.byte_0x23 = 0;
    sys_config.path_mode_ch0 = 0;
    sys_config.red_offset = 0x32;
    sys_config.blue_offset_second = 0x80;
    sys_config.byte_0x30 = 0;
    sys_config.byte_0x31 = 0;
    sys_config.byte_0x32 = 0;
    sys_config.byte_0x33 = 1;
    sys_config.bit18 = 0;
    sys_config.byte_0x34 = 0;
    sys_config.half_0x36 = 0;
}
