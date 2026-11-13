/* sys_user_restart_channel2_by_table  (FUN_a00d5bb8)
 *
 * Copy a table record chosen by settings byte +0x46 and restart channel 2 if its enable value is 1.
 * Note: The copied record is passed on but never used; nothing calls this routine.
 * Name basis: descriptive - 16-byte record from the table at 0x1984C8; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5bb8 @ 0xa00d5bb8-0xa00d5c2c (29 words), flags -mcpu=v8 -O3 -g.
 * Source form: the record is copied with a plain structure assignment, halfword by halfword (2-byte alignment).
 * The callee is declared with two parameters although its definition takes one.
 */
/* One 16-byte record of the table at 0x1984C8 (eight halfwords, no field is named). */
struct channel_record_16 {
    unsigned short h[8];
};
extern const struct channel_record_16 sys_user_channel_records[];
extern unsigned char user_settings_byte_0x46;
extern void sys_api_restart_secondary_channel(int which, struct channel_record_16 *record);

/*
 * Copy the record that settings byte +0x46 selects from the table at 0x1984C8 and pass it, with which = 0
 * (channel 2), to sys_api_restart_secondary_channel. That routine reads only its first argument: it restarts
 * channel 2 when the system configuration enable value of channel 2 is 1. The record is not used. Nothing
 * calls this routine.
 */
void sys_user_restart_channel2_by_table(void)
{
    struct channel_record_16 r = sys_user_channel_records[user_settings_byte_0x46];

    sys_api_restart_secondary_channel(0, &r);
}
