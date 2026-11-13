/* sys_user_restart_channel3_by_table  (FUN_a00d5c2c)
 *
 * Copy a table record chosen by a settings byte and restart channel 3 if its enable value is 1.
 * Note: The copied record is passed on but never used; nothing calls this routine.
 * Name basis: descriptive - twin for channel 3; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5c2c @ 0xa00d5c2c-0xa00d5ca0 (29 words), flags -mcpu=v8 -O3 -g.
 * Source form: the record is copied with a plain structure assignment, halfword by halfword (2-byte alignment).
 * The callee is declared with two parameters although its definition takes one.
 */
/* One 16-byte record of the table at 0x1984C8 (eight halfwords, no field is named). */
struct channel_record_16 {
    unsigned short h[8];
};
extern const struct channel_record_16 sys_user_channel_records[];
extern unsigned char user_settings_byte_0x48;
extern void sys_api_restart_secondary_channel(int which, struct channel_record_16 *record);

/*
 * Copy the record that settings byte +0x48 selects from the table at 0x1984C8 and pass it, with which = 1
 * (channel 3), to sys_api_restart_secondary_channel. That routine reads only its first argument: it restarts
 * channel 3 when the system configuration enable value of channel 3 is 1. The record is not used. Nothing
 * calls this routine.
 */
void sys_user_restart_channel3_by_table(void)
{
    struct channel_record_16 r = sys_user_channel_records[user_settings_byte_0x48];

    sys_api_restart_secondary_channel(1, &r);
}
