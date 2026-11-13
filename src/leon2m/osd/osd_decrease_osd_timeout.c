/* osd_decrease_osd_timeout  (FUN_a00a454c)
 *
 * Lower OSD Time out by 5 on its slider (left key) and apply it.
 * Note: Settings byte +0xC, range 5..30 s; redraws the slider.
 * Name basis: derived - handler table 0xA802422C: left on state 0xB0 (OSD Time out slider)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a454c, flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is reached through a struct pointer; the clamp arm comes first
 * ('new_value < 5 || new_value > 0x1e' stores 5); with the in-range arm first the registers differ. The
 * compiler folds the range test into one unsigned compare. The slider draw takes one unsigned byte.
 */
/* The field of the user settings record that is used here. */
struct user_settings_record {
    unsigned char pad0[0xc];
    unsigned char osd_timeout;                  /* +0xC: the OSD Time out setting */
};
extern struct user_settings_record user_settings;
extern unsigned char osd_request_bits;
extern void osd_draw_timeout_slider(unsigned char);
extern void osd_user_apply_menu_timeout(void);

#define OSD_TIMEOUT_STEP  5
#define OSD_TIMEOUT_MIN   5
#define OSD_TIMEOUT_MAX   0x1e          /* 30 */
#define SLIDER_BEING_EDITED          1  /* argument of osd_draw_timeout_slider */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit 1 of osd_request_bits */

/*
 * Left key on the OSD Time out slider (menu state 0xB0): lower the time out by 5 down to 5, redraw the slider
 * and apply the value (osd_user_apply_menu_timeout). A result outside 5 to 30 stores 5 without a redraw.
 * The settings-changed request bit is set in every case.
 */
void osd_decrease_osd_timeout(void)
{
  struct user_settings_record *settings = &user_settings;
  unsigned char new_value = settings->osd_timeout - OSD_TIMEOUT_STEP;

  if (new_value < OSD_TIMEOUT_MIN || new_value > OSD_TIMEOUT_MAX)
    settings->osd_timeout = OSD_TIMEOUT_MIN;
  else {
    settings->osd_timeout = new_value;
    osd_draw_timeout_slider(SLIDER_BEING_EDITED);
    osd_user_apply_menu_timeout();
  }
  osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
