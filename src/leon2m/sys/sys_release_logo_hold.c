/* sys_release_logo_hold  (FUN_a0082acc)
 *
 * Finish the logo phase: restore the picture, unblock all keys, clear the hold flag and flag 25.
 * Note: Clears bit 0 of 0xA802AF41 that osd_show_logo_on_power_on sets.
 * Name basis: derived - sys_end_logo_restore_picture, sys_set_key_blocked(0xFF, 0), app_flags bit 0 cleared,
 *   sys_api_clear_all_channels_flag25
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0082acc @ 0xa0082acc, flags -mcpu=v8 -O3 -g.
 * Calls sys_end_logo_restore_picture() and sys_set_key_blocked(0xff, 0), clears bit 0 of app_flags, then passes its six
 * arguments to sys_api_clear_all_channels_flag25.
 */
extern unsigned char app_flags; /* 0xa802af41 */
extern int sys_set_key_blocked(int a, int b); /* 0xa008ee6c */
extern int sys_end_logo_restore_picture(void); /* 0xa008f354 */
extern void sys_api_clear_all_channels_flag25(int a, int b, int c, int d, int e, int f); /* 0xa0143da8 */

#define APP_FLAG_LOGO_HOLD 0x01         /* app_flags bit 0: set by osd_show_logo_on_power_on while the logo is shown */
#define KEY_ID_ALL         0xff         /* key event code meaning every key */

/*
 * End the logo phase: restore the picture (sys_end_logo_restore_picture), unblock all keys, clear the logo hold
 * flag, then call sys_api_clear_all_channels_flag25.
 *
 * The six arguments are handed to sys_api_clear_all_channels_flag25 unchanged; this routine does not use them.
 * osd_show_logo_on_power_on blocked all keys but 0x40 and set the flag; this undoes both.
 */
void sys_release_logo_hold(int a, int b, int c, int d, int e, int f)
{
    unsigned char flags;
    sys_end_logo_restore_picture();
    sys_set_key_blocked(KEY_ID_ALL, 0);
    flags = app_flags;
    app_flags = flags & ~APP_FLAG_LOGO_HOLD;
    sys_api_clear_all_channels_flag25(a, b, c, d, e, f);
}
