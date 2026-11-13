/* osd_toggle_type_c_pd_charge  (FUN_a009934c)
 *
 * Switch Type C PD Charge on or off and apply it.
 * Note: Toggles bit 7 of settings word +0x1EC, then gpio_user_set_port7_bit1(0).
 * Name basis: proven - handler table 0xA802422C: OK on state 0x31 = 'Type C PD Charge' (Settings texts
 *   0x1874F8)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009934c @ 0xa009934c-0xa00993a8 (23 words), flags -mcpu=v8 -O3 -g.
 * Source form: bit 7 of the word at +0x1EC is a 1-bit bit-field, toggled as 'f = 1 - f' (the same form as
 * osd_toggle_info_on_screen). gpio_user_set_port7_bit1 is called with the argument 0.
 */
/* Settings word +0x1EC; bit 7 is Type C PD Charge. */
struct user_settings_record { unsigned char pad[0x1ec]; unsigned int hi : 24, type_c_pd_charge : 1, lo : 7; };
extern struct user_settings_record user_settings;
extern unsigned char osd_request_bits;
extern void osd_draw_toggle_switch_selected(int, unsigned char);
extern void gpio_user_set_port7_bit1(int);

#define TOGGLE_ITEM_TYPE_C_PD_CHARGE 0  /* item index of osd_draw_toggle_switch_selected for Type C PD Charge */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02 /* osd_request_bits bit 1: a setting was changed */

/*
 * OK on the Type C PD Charge item of the Settings page: flip the switch (bit 7 of the settings word at +0x1EC),
 * draw the new OFF or ON state, apply it to GPIO port 7 pin 1 (gpio_user_set_port7_bit1) and report a settings
 * change.
 */
void osd_toggle_type_c_pd_charge(void)
{
  struct user_settings_record *p = &user_settings;

  p->type_c_pd_charge = 1 - p->type_c_pd_charge;
  osd_draw_toggle_switch_selected(TOGGLE_ITEM_TYPE_C_PD_CHARGE, p->type_c_pd_charge);
  gpio_user_set_port7_bit1(0);
  osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
