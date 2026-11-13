/* osd_open_dialog_layer  (FUN_a00b0ef8)
 *
 * Set up the overlay layer as a 40 x 11 dialog and draw its frame.
 * Note: No reference to it was found.
 * Name basis: descriptive - layout 3, osd_setup_layer_window(0x28, 0xB, 0x792), osd_draw_dialog_frame
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b0ef8 @ 0xa00b0ef8, flags -mcpu=v8 -O2 -g (section default).
 * Source form: the callees are declared int-returning without prototypes (as the decompiler wrote them) and
 * the routine ends with a plain 'return;'.
 */
extern int osd_draw_dialog_frame();
extern int osd_set_layout();
extern void osd_setup_layer_window();
extern int osd_api_set_position();
extern int panel_wait_sync_pulse();

#define DIALOG_LAYOUT        3       /* osd_set_layout mode used for dialogs and messages */
#define DIALOG_COLUMNS       0x28    /* 40 cells wide */
#define DIALOG_ROWS          0xb     /* 11 cells high */
#define CELL_BLANK           0x792   /* background attribute of the layer */
#define DIALOG_POSITION      0x32    /* both position numbers: 50 (the menu position settings are percentages) */

/* Set up the menu layer as a 40 x 11 dialog box and draw the dialog frame. It waits for four sync pulses
 * first, switches the layer to layout 3, resets it to the dialog size with a blank background and puts it at
 * position 50, 50. Nothing in the image calls it; osd_show_change_notice does the same steps and then draws
 * the notice. */
void osd_open_dialog_layer(void)

{
  
  panel_wait_sync_pulse();
  panel_wait_sync_pulse();
  panel_wait_sync_pulse();
  panel_wait_sync_pulse();
  osd_set_layout(DIALOG_LAYOUT);
  osd_setup_layer_window(DIALOG_COLUMNS, DIALOG_ROWS, CELL_BLANK);
  osd_draw_dialog_frame();
  osd_api_set_position(DIALOG_POSITION, DIALOG_POSITION, 0);
  return;
}
