/* sys_api_set_config_bit31  (FUN_a0148d98)
 *
 * Store configuration bit 31 (0 if device settings bit 27 is set), mirror it inverted to channel 0.
 * Name basis: descriptive - stSysConfig bit 31; channel record 0 bit 23 = its inverse; same as command 0 of
 *   sys_api_config
 *
 * Matching notes
 * --------------
 * FUN_a0148d98: callers include App_Initialize, osd_toggle_auto_scan, uart_cmd_set_setting_bit9. Exact form: bit 31 of sys_config
 * is a 1-bit bit-field (first field, big-endian).
 */
#define DEVICE_SETTINGS_BIT27 0x8000000    /* bit 27 of the first word of the device settings */
#define CHANNEL_FLAG_23       0x800000     /* bit 23 of the flags word (+0x70) of a channel record */

struct sys_config_word { unsigned int bit31 : 1, rest : 31; };
/* Channel record (0x78 bytes); only the flags word at +0x70 is used here. */
struct channel_record { unsigned int status_word; unsigned char pad[0x6c]; unsigned int flags; unsigned char pad2[0x4]; };
extern unsigned int device_settings;
extern struct sys_config_word sys_config;
extern struct channel_record channel_records[4];

/* Set bit 31 of sys_config to on; it is forced to 0 when bit 27 of the device settings is set. Then bit 23
 * of the flags word of channel 0 is set to the opposite of the stored bit 31. */
void sys_api_set_config_bit31(int on)
{
    if (device_settings & DEVICE_SETTINGS_BIT27)
        sys_config.bit31 = 0;
    else
        sys_config.bit31 = on;
    if (sys_config.bit31)
        channel_records[0].flags &= ~CHANNEL_FLAG_23;
    else
        channel_records[0].flags |= CHANNEL_FLAG_23;
}
