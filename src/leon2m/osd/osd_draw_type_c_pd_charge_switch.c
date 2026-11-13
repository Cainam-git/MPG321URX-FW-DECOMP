/* osd_draw_type_c_pd_charge_switch  (FUN_a00b79d0)
 *
 * Draw the Type C PD Charge switch of the Settings page.
 * Note: Value = bit 7 of settings word +0x1EC.
 * Name basis: proven - row 7 of the Settings items (second page)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b79d0 @ 0xa00b79d0 (-mcpu=v8 -O2 -g)
 * Source form: two separate calls, each followed by a return.
 */
#define TYPE_C_PD_CHARGE_BIT 0x80               /* bit 7 of the word at settings +0x1EC */

extern unsigned int user_settings_boundary_detection;   /* settings word +0x1EC (its first byte is Boundary Detection) */
extern int osd_draw_toggle_switch();

/* Draw the Type C PD Charge switch, on when bit 7 of settings word +0x1EC is set. The item number given is 0,
   which puts the switch on row 6 (osd_draw_toggle_switch). */
void osd_draw_type_c_pd_charge_switch(void)

{
  if ((user_settings_boundary_detection & TYPE_C_PD_CHARGE_BIT) != 0) {
    osd_draw_toggle_switch(0,1);
    return;
  }
  osd_draw_toggle_switch(0,0);
  return;
}
