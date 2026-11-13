/* osd_open_crosshair_position  (FUN_a0094368)
 *
 * Open the free position editor for the Smart Crosshair.
 * Note: Hides the menu and sets state 0x108 with editor target 2.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x41 = 'Position' (texts 0x18F984)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0094368, flags -mcpu=v8 -O3 -g.
 * Source form: the target byte is declared char; the preview routine is declared without a prototype and its
 * result is dropped.
 */
#define OVERLAY_CROSSHAIR        2      /* position editor target: the Smart Crosshair */
#define MENU_STATE_POSITION_EDITOR 0x108

extern char user_settings_byte_0x1a3;
extern unsigned int osd_menu_state;
extern unsigned short osd_draw_overlay_position_preview();
extern void osd_hide_menu();
extern void panel_wait_sync_pulse();

/*
 * Open the free position editor for the Smart Crosshair: settings byte +0x1A3 (the editor target) is set to 2,
 * the menu state becomes 0x108, the menu layer and its windows are hidden, two sync pulses of the panel are
 * waited for, and the crosshair is drawn for positioning with osd_draw_overlay_position_preview(2, 1, 0).
 */
void osd_open_crosshair_position(void)

{
  
  user_settings_byte_0x1a3 = OVERLAY_CROSSHAIR;
  osd_menu_state = MENU_STATE_POSITION_EDITOR;
  osd_hide_menu();
  panel_wait_sync_pulse();
  panel_wait_sync_pulse();
  osd_draw_overlay_position_preview(OVERLAY_CROSSHAIR,1,0);
  return;
}
