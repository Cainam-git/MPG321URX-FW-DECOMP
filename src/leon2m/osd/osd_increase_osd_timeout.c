/* osd_increase_osd_timeout  (FUN_a00a44f4)
 *
 * Raise OSD Time out by 5 on its slider (right key) and apply it.
 * Note: Settings byte +0xC, range 5..30 s; redraws the slider.
 * Name basis: derived - handler table 0xA802422C: right on state 0xB0 (OSD Time out slider)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a44f4, flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is reached through a struct pointer; the sum is an unsigned byte local; the
 * test is 'new_value < 0x1f'. The slider draw takes one unsigned byte.
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
#define OSD_TIMEOUT_MAX   0x1e          /* 30 */
#define SLIDER_BEING_EDITED          1  /* argument of osd_draw_timeout_slider */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit 1 of osd_request_bits */

/*
 * Right key on the OSD Time out slider (menu state 0xB0): raise the time out by 5 up to 30, redraw the slider
 * and apply the value (osd_user_apply_menu_timeout). A sum above 30 stores 30 without a redraw.
 * The settings-changed request bit is set in every case.
 */
void osd_increase_osd_timeout(void)
{
  struct user_settings_record *settings = &user_settings;
  unsigned char new_value = settings->osd_timeout + OSD_TIMEOUT_STEP;

  if (new_value < OSD_TIMEOUT_MAX + 1) {
    settings->osd_timeout = new_value;
    osd_draw_timeout_slider(SLIDER_BEING_EDITED);
    osd_user_apply_menu_timeout();
  } else
    settings->osd_timeout = OSD_TIMEOUT_MAX;
  osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
