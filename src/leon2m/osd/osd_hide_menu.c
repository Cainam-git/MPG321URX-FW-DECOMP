/* osd_hide_menu  (FUN_a00b5080)
 *
 * Hide the menu layer, all its windows and layer 1, and clear bit 15 of app state halfword +0x3E.
 * Note: Sets the page byte 0xA802B08F to 0x24.
 * Name basis: proven - osd_api_enable(0, 0) and window enable off; called by osd_close_menu,
 *   OSDCloseWhenSyncDet and others
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b5080 @ 0xa00b5080, flags -mcpu=v8 -O3 -g.
 * Source form: bit 15 of the halfword at +0x3E is a one-bit bit-field (the bit-field named flag_15).
 */
struct flags_0x3e_bits { unsigned short flag_15 : 1, rest : 15; };
struct app_state_record_layout { unsigned char pad[0x3e]; struct flags_0x3e_bits flags_0x3e; };
extern struct app_state_record_layout app_state_record;
extern unsigned char osd_list_id;
extern void osd_api_enable(int on, int layer);
extern void osd_api_set_window_enable(int window, int on, int unused);

#define MENU_LAYER_MAIN   0
#define CROSSHAIR_LAYER   1
#define ALL_WINDOWS       8
#define OSD_LIST_QUICK_MENU 0x24   /* osd_list_id value of the quick menu lists */

/* Hide the menu: switch off the menu layer (layer 0) and all its windows, set osd_list_id to 0x24, switch off
 * layer 1 (the crosshair layer) too, and clear bit 15 of app_state_record halfword +0x3E (the flag that makes
 * osd_dispatch_key_event skip the menu time-out). Called by osd_close_menu, OSDCloseWhenSyncDet and many other
 * routines. */
void osd_hide_menu(void)
{
    osd_api_enable(0, MENU_LAYER_MAIN);
    osd_api_set_window_enable(ALL_WINDOWS, 0, 0);
    osd_list_id = OSD_LIST_QUICK_MENU;
    osd_api_enable(0, CROSSHAIR_LAYER);
    app_state_record.flags_0x3e.flag_15 = 0;
}
