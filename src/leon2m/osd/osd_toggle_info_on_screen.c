/* osd_toggle_info_on_screen  (FUN_a00991ec)
 *
 * Switch Info. On Screen on or off and redraw the item.
 * Note: Toggles bit 22 of settings word +0xAC.
 * Name basis: proven - handler table 0xA802422C: OK on state 0x2F = 'Info. On Screen' (Settings texts
 *   0x1874F8)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00991ec @ 0xa00991ec-0xa0099244 (22 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table). Source form: bit 22 of word +0xAC is a 1-bit bit-field, toggled as 'f = 1 - f' (the same
 * form as osd_toggle_type_c_pd_charge).
 */
/* Settings word +0xAC; bit 22 is Info. On Screen. */
struct user_settings_record { unsigned char pad[0xac]; unsigned int hi : 9, info_on_screen : 1, lo : 22; };
extern struct user_settings_record user_settings;
extern unsigned char osd_request_bits;
extern void osd_draw_toggle_switch_selected(int, unsigned char);

#define TOGGLE_ITEM_INFO_ON_SCREEN 5    /* item index of osd_draw_toggle_switch_selected for Info. On Screen */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02 /* osd_request_bits bit 1: a setting was changed */

/*
 * OK on the Info. On Screen item of the Settings page: flip the switch (bit 22 of settings word +0xAC), draw the
 * new OFF or ON state and report a settings change.
 */
void osd_toggle_info_on_screen(void)
{
    struct user_settings_record *p = &user_settings;

    p->info_on_screen = 1 - p->info_on_screen;
    osd_draw_toggle_switch_selected(TOGGLE_ITEM_INFO_ON_SCREEN, p->info_on_screen);
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
