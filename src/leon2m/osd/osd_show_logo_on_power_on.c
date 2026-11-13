/* osd_show_logo_on_power_on  (FUN_a0081e0c)
 *
 * Show the start-up logo when armed, block all keys except 0x40 and start a 3-second timer.
 * Note: Condition: settings word bit 12 set, bit 14 (factory mode) clear and halfword +0x1F6 not 0x55AA; sets
 *   the logo hold flag.
 * Name basis: derived - text 'show logo %d'; calls ShowLogo ShowLogo
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0081e0c, flags -mcpu=v8 -O3 -g.
 * (includes the merged ret/restore tail FUN_a0081ea0). The same block is inlined in
 * src/leon2m/power/power_enter_app_state.c.
 * Source form: user_settings is a local struct declaration; the format string is the symbol s_000fedc8.
 */

/* The two fields of the user settings record used here. */
struct user_settings_record {
    unsigned int word_0x0;                      /* +0x00 */
    unsigned char pad4[0x1f6 - 4];
    unsigned short factory_marker;              /* +0x1F6 */
};

#define SETTINGS_WORD0_BIT12   0x1000           /* bits of word_0x0 */
#define SETTINGS_FACTORY_MODE  0x4000           /* bit 14 */
#define FACTORY_MODE_MARKER    0x55aa           /* value of factory_marker */

#define KEY_ID_ALL             0xff             /* sys_set_key_blocked: all keys */
#define KEY_POWER              0x40             /* the one key left unblocked while the logo shows */
#define APP_FLAG_LOGO_HOLD     0x01             /* bit 0 of app_flags */
#define APP_TIMER_LOGO_HOLD    3
#define LOGO_HOLD_MS           3000

extern struct user_settings_record user_settings;
extern unsigned char app_flags;
extern int dbg_printf(const char *fmt, ...);
extern void ShowLogo(void);
extern void sys_set_key_blocked(int, int);
extern void sys_api_set_all_channels_flag25(void);
extern void sys_app_timer_start(int, int);

/*
 * Show the power-on logo when settings word bit 12 is set and bit 14 (factory mode) is clear and the factory
 * marker is not 0x55AA. Then all keys except 0x40 are blocked, app_flags bit 0 (logo hold) is set, and
 * timer 3 is started for 3000 ms. Otherwise nothing happens.
 */
void osd_show_logo_on_power_on(void)
{
  if ((user_settings.word_0x0 & (SETTINGS_WORD0_BIT12 | SETTINGS_FACTORY_MODE)) == SETTINGS_WORD0_BIT12 &&
      user_settings.factory_marker != FACTORY_MODE_MARKER) {
    dbg_printf("\nshow logo %d\r\n", 1);
    ShowLogo();
    sys_set_key_blocked(KEY_ID_ALL, 1);
    sys_set_key_blocked(KEY_POWER, 0);
    app_flags |= APP_FLAG_LOGO_HOLD;
    sys_api_set_all_channels_flag25();
    sys_app_timer_start(APP_TIMER_LOGO_HOLD, LOGO_HOLD_MS);
  }
}
