/* osd_draw_auto_scan_switch  (FUN_a00b3b5c)
 *
 * Draw the Input Source auto scan switch and its key guide.
 *   on: selected
 * Note: Value = bit 9 of settings word 0.
 * Name basis: derived - called by osd_toggle_auto_scan
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b3b5c @ 0xa00b3b5c, flags -mcpu=v8 -O3 -g.
 * Source form: the second call is written as two calls in an if/else (the '== 1' value form gives one shared
 * call); it is a tail call.
 */
extern unsigned int user_settings;      /* word at +0 */
extern void osd_draw_toggle_switch(unsigned char item, unsigned char on);
extern void osd_draw_input_item_state(unsigned char item, int style);

#define INPUT_ITEM_AUTO_SCAN 4       /* item row of the Input Source page that has a switch */
#define AUTO_SCAN_BIT        9       /* bit of settings word 0 shown by the switch */

/* Redraw the Auto Scan switch of the Input Source page: the OFF/ON switch of item row 4 is drawn in normal
 * colours from bit 9 of the first settings word, then osd_draw_input_item_state redraws the item's state with
 * highlight style 1 when 'on' is 1 and style 0 otherwise. Called by osd_toggle_auto_scan. */
void osd_draw_auto_scan_switch(unsigned char on)
{
    osd_draw_toggle_switch(INPUT_ITEM_AUTO_SCAN, user_settings >> AUTO_SCAN_BIT & 1);
    if (on == 1)
        osd_draw_input_item_state(INPUT_ITEM_AUTO_SCAN, 1);
    else
        osd_draw_input_item_state(INPUT_ITEM_AUTO_SCAN, 0);
}
