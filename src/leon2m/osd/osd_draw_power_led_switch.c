/* osd_draw_power_led_switch  (FUN_a00b7a08)
 *
 * Draw the Power LED switch of the Settings page.
 * Note: Value = bit 30 of settings word +0x1F4.
 * Name basis: proven - row 8 of the Settings items (second page); osd_toggle_power_led toggles the same bit
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b7a08 @ 0xa00b7a08 (-mcpu=v8 -O3 -g)
 * Source form: two separate calls, each followed by a return.
 */
#define POWER_LED_BIT 0x40000000                /* bit 30 of settings word +0x1F4 */

extern unsigned int user_settings_word_0x1f4;   /* settings word +0x1F4 */
extern int osd_draw_toggle_switch();

/* Draw the Power LED switch, on when bit 30 of settings word +0x1F4 is set. The item number given is 1, which
   puts the switch on row 8 (osd_draw_toggle_switch). */
void osd_draw_power_led_switch(void)

{
  if ((user_settings_word_0x1f4 & POWER_LED_BIT) != 0) {
    osd_draw_toggle_switch(1,1);
    return;
  }
  osd_draw_toggle_switch(1,0);
  return;
}
