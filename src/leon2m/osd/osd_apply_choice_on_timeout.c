/* osd_apply_choice_on_timeout  (FUN_a00db1ac)
 *
 * Apply the choice of the open menu screen when the menu time-out ends, as OK would on that screen.
 * Note: Covers the Smart Crosshair, Screen Size, DisplayHDR, PIP/PBP, Optix Scope, Static Screen Detection and
 *   Protect Notice screens; other states change nothing.
 * Name basis: derived - called by osd_run_periodic_task when the menu countdown reaches 0; reads the menu
 *   state and calls the accept routine of that screen
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00db1ac @ 0xa00db1ac-0xa00db678 (307 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - osd_get_menu_state() is called again for every test, as in the firmware;
 *  - sys_user_swap_pip_sources (sys_user_swap_pip_sources) is defined in this file as a static copy and inlined;
 *  - the two source bytes are read into locals first, then bit 17 of +0xac is set, then the bytes are written.
 */

/* Fields of the user settings record that this file uses (names as in docs/RECORDS.md). */
struct user_settings_record {
    unsigned char pad0[0x1e];
    unsigned char input_source;                 /* +0x1E: source of the main picture */
    unsigned char pad1f;
    unsigned char second_source;                /* +0x20: source of the second picture */
    unsigned char pad21[0xa8 - 0x21];
    unsigned int gaming_flags;                  /* +0xA8: bit 14 is toggled by audio_user_toggle_source */
    unsigned int settings_page_flags;           /* +0xAC: bits 19..18 DisplayHDR choice, bit 17 reported to the PC tool */
    unsigned char padb0[0x1a4 - 0xb0];
    unsigned char screen_size;                  /* +0x1A4 */
    unsigned char pad1a5[0x1ac - 0x1a5];
    unsigned short halfword_0x1ac;
    unsigned short halfword_0x1ae;
    unsigned char pad1b0[0x1dc - 0x1b0];
    unsigned int oled_care_flags;               /* +0x1DC: bit 15 Static Screen Detection on */
};
extern struct user_settings_record user_settings;
extern unsigned char user_settings_crosshair_icon;
extern unsigned char osd_choice_row;
extern unsigned char osd_request_bits;
extern unsigned short osd_get_menu_state(void);
extern void osd_apply_screen_size(void);
extern void sys_user_apply_startup_settings(void);
extern void osd_accept_pip_pbp_quick_menu(void);
extern void osd_apply_pip_pbp_mode(void);
extern void osd_commit_pip_pbp_layout(void);
extern void osd_set_pbp_mode_from_state(void);
extern void audio_user_update_routing(void);
extern void sys_user_reset_display_path(void);
extern void audio_api_set_mute(unsigned char);
extern void sys_api_select_channel_source(int, unsigned char);
extern void audio_user_toggle_source(void);
extern void osd_accept_pbp_custom_split(void);
extern void osd_apply_optix_scope(void);
extern void oled_set_screen_saver_range(void);
extern void osd_accept_protect_notice(void);

/* Menu states (the screen the menu is on; osd_get_menu_state). Ranges are tested with their numbers, see the
 * block comment below. */
enum {
    STATE_CROSSHAIR_ICON       = 0x3f,  /* first item of the Smart Crosshair settings */
    STATE_CROSSHAIR_RESET      = 0x42,  /* 'Reset' of the Smart Crosshair settings */
    STATE_OPTIX_SCOPE_OFF      = 0x46,
    STATE_OPTIX_SCOPE_ON       = 0x47,
    STATE_SCREEN_SIZE_FIRST    = 0x70,  /* 0x70..0x76: Screen Size choices, size = state - 0x70 */
    STATE_PIP_SETTINGS_SWAP    = 0x7d,  /* the item that runs sys_user_swap_pip_sources in the PIP settings list */
    STATE_PIP_SETTINGS_AUDIO   = 0x7e,  /* the item that runs audio_user_toggle_source in the PIP settings list */
    STATE_PBP_SETTINGS_SWAP    = 0x84,  /* same two items in the PBP settings list */
    STATE_PBP_SETTINGS_AUDIO   = 0x85,
    STATE_STATIC_SCREEN_OFF    = 0xbb,  /* 0xBB..0xBF: Static Screen Detection choices; 0xBB off, 0xBC on */
    STATE_STATIC_SCREEN_ON     = 0xbc,
    STATE_PBP_CUSTOM_SPLIT     = 0x109, /* PBP custom split editor */
    STATE_PIP_PBP_QUICK_MENU   = 0xff   /* quick menu for the PIP/PBP layout */
};

/* Swap the sources of the main and the second picture and re-select them.
 * Nothing but bit 17 of +0xAC is changed when the two sources are equal. */
static void sys_user_swap_pip_sources(void)
{
  struct user_settings_record *settings = &user_settings;
  unsigned char old_main = settings->input_source;
  unsigned char old_second = settings->second_source;

  settings->settings_page_flags |= 0x20000;
  settings->input_source = old_second;
  settings->second_source = old_main;
  if (old_second == old_main)
    return;
  sys_user_reset_display_path();
  /* Bit 14 of +0xA8 is the sound-source bit that audio_user_toggle_source toggles; when it is set the sound is
     muted before the second picture changes source. */
  if (settings->gaming_flags & 0x4000)
    audio_api_set_mute(1);
  sys_api_select_channel_source(1, settings->second_source);
  audio_user_update_routing();
}

/*
 * Apply the choice of the menu screen that is open, as if OK had been pressed on it.
 *
 * Called by osd_run_periodic_task when its one-second countdown (osd_seconds_countdown) reaches 0 in a menu
 * state other than 0x106, 0xE1, 0xE6, 0x41 and 0x81, just before the menu state is set to 0 and the menu is
 * hidden. The routine reads the menu state and, for each group of states, calls the
 * routine that OK calls on that screen (or does the same small update itself). States outside the groups below
 * change nothing. In order:
 *   0x3F          Smart Crosshair settings: the crosshair icon is set to 0.
 *   0x42          Smart Crosshair 'Reset': halfwords +0x1AC and +0x1AE get 0x750 and 0x402.
 *   0x70..0x76    Screen Size choices: screen size = state - 0x70, then osd_apply_screen_size.
 *   0x77..0x79    DisplayHDR choices: only when the DisplayHDR value (settings +0xAC, bits 19..18) differs from
 *                 the value saved in osd_choice_row when the list was opened: sys_user_apply_startup_settings
 *                 and bit 2 of osd_request_bits.
 *   0x23..0x25    PIP/PBP layout items: osd_apply_pip_pbp_mode and osd_commit_pip_pbp_layout.
 *   0xFF          PIP/PBP quick menu: osd_accept_pip_pbp_quick_menu.
 *   0x7F..0x81    PBP settings: osd_set_pbp_mode_from_state.
 *   0x7D, 0x84    swap the sources of the main and the second picture.
 *   0x7E, 0x85    toggle which picture's sound is played.
 *   0x109         PBP custom split editor: osd_accept_pbp_custom_split.
 *   0x46, 0x47    Optix Scope OFF / ON: osd_apply_optix_scope.
 *   0xBB..0xBF    Static Screen Detection choices: 0xBB clears and 0xBC sets bit 15 of settings +0x1DC (the
 *                 other states leave it), then the screen saver range is written to the panel controller.
 *   0xC3, 0xC4    Protect Notice choices: osd_accept_protect_notice.
 * The tests are independent ifs, but each state falls in one group only.
 */
void osd_apply_choice_on_timeout(void)
{
    if (osd_get_menu_state() == STATE_CROSSHAIR_ICON)
        user_settings_crosshair_icon = 0;
    if (osd_get_menu_state() == STATE_CROSSHAIR_RESET) {
        user_settings.halfword_0x1ac = 0x750;
        user_settings.halfword_0x1ae = 0x402;
    }
    if (osd_get_menu_state() > STATE_SCREEN_SIZE_FIRST - 1 && osd_get_menu_state() <= 0x76) {
        user_settings.screen_size = osd_get_menu_state() - STATE_SCREEN_SIZE_FIRST;
        osd_apply_screen_size();
    }
    if (osd_get_menu_state() > 0x76 && osd_get_menu_state() <= 0x79 && osd_choice_row != ((user_settings.settings_page_flags >> 18) & 3)) {
        sys_user_apply_startup_settings();
        osd_request_bits |= 4;
    }
    if ((osd_get_menu_state() > 0x22 && osd_get_menu_state() <= 0x25) || osd_get_menu_state() == STATE_PIP_PBP_QUICK_MENU) {
        if (osd_get_menu_state() == STATE_PIP_PBP_QUICK_MENU)
            osd_accept_pip_pbp_quick_menu();
        else {
            osd_apply_pip_pbp_mode();
            osd_commit_pip_pbp_layout();
        }
    }
    if (osd_get_menu_state() > 0x7e && osd_get_menu_state() <= 0x81)
        osd_set_pbp_mode_from_state();
    if (osd_get_menu_state() == STATE_PBP_SETTINGS_SWAP || osd_get_menu_state() == STATE_PIP_SETTINGS_SWAP)
        sys_user_swap_pip_sources();
    if (osd_get_menu_state() == STATE_PBP_SETTINGS_AUDIO || osd_get_menu_state() == STATE_PIP_SETTINGS_AUDIO)
        audio_user_toggle_source();
    if (osd_get_menu_state() == STATE_PBP_CUSTOM_SPLIT)
        osd_accept_pbp_custom_split();
    if (osd_get_menu_state() == STATE_OPTIX_SCOPE_OFF || osd_get_menu_state() == STATE_OPTIX_SCOPE_ON)
        osd_apply_optix_scope();
    if (osd_get_menu_state() > 0xba && osd_get_menu_state() <= 0xbf) {
        if (osd_get_menu_state() == STATE_STATIC_SCREEN_OFF)
            user_settings.oled_care_flags &= ~0x8000;
        else if (osd_get_menu_state() == STATE_STATIC_SCREEN_ON)
            user_settings.oled_care_flags |= 0x8000;
        oled_set_screen_saver_range();
    }
    if (osd_get_menu_state() > 0xc2 && osd_get_menu_state() <= 0xc4)
        osd_accept_protect_notice();
}
