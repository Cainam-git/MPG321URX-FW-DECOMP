/* osd_toggle_power_led  (FUN_a00993a8)
 *
 * Switch the Power LED on or off and apply it.
 * Note: Toggles bit 30 of settings word +0x1F4.
 * Name basis: proven - handler table 0xA802422C: OK on state 0x32 = 'Power LED' (Settings texts 0x1874F8)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00993a8 @ 0xa00993a8-0xa0099440 (152 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: a union of the word and a bit-field view; the bit is set to ~(word >> 30) and tested on the
 * word with 0x40000000.
 */
/* Settings word +0x1F4; bit 30 is the Power LED switch. */
union flags_1f4 { unsigned int w; struct { unsigned int b31:1, power_led:1, rest:30; } f; };
struct user_settings_record { unsigned char p0[0x1f4]; union flags_1f4 u; };
extern struct user_settings_record user_settings;
extern unsigned char osd_request_bits;
extern void osd_draw_toggle_switch_selected(unsigned char i0, unsigned char i1);
extern void sys_set_mode_byte_c9f8(unsigned char);
extern void gpio_set_port4_bit7_high_if_allowed(void);
extern void gpio_set_port4_bit7_low_if_allowed(void);
extern void gpio_set_port4_bit4_low_if_allowed(void);
extern void sys_user_apply_mode_byte(void);

#define TOGGLE_ITEM_POWER_LED    1      /* item index of osd_draw_toggle_switch_selected for Power LED */
#define SETTINGS_POWER_LED       0x40000000 /* bit 30 of settings word +0x1F4 */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02 /* osd_request_bits bit 1: a setting was changed */

/*
 * OK on the Power LED item of the Settings page: flip the switch (bit 30 of the settings word at +0x1F4) and
 * draw the new OFF or ON state.
 *
 * Then the mode byte is set to 1 (sys_set_mode_byte_c9f8), pin 7 of GPIO port 4 is driven high when the switch
 * is now on and low when it is off, pin 4 of port 4 is driven low, and sys_user_apply_mode_byte stores the mode
 * byte from the switch. The routine ends by reporting a settings change.
 */
void osd_toggle_power_led(void)
{
    user_settings.u.f.power_led = ~(user_settings.u.w >> 30);
    osd_draw_toggle_switch_selected(TOGGLE_ITEM_POWER_LED, user_settings.u.f.power_led);
    sys_set_mode_byte_c9f8(1);
    if (user_settings.u.w & SETTINGS_POWER_LED)
        gpio_set_port4_bit7_high_if_allowed();
    else
        gpio_set_port4_bit7_low_if_allowed();
    gpio_set_port4_bit4_low_if_allowed();
    sys_user_apply_mode_byte();
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
