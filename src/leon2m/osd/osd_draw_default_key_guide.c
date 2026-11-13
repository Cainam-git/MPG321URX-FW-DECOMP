/* osd_draw_default_key_guide  (FUN_a00aa4c0)
 *
 * Draw the default key guide (icons and texts)
 * Note: osd_draw_key_guide(1, 2) then osd_update_key_guide(0, 1).
 * Name basis: derived - called by the G.I. and PIP item handlers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00aa4c0 @ 0xa00aa4c0, flags -mcpu=v8 -O2 -g.
 * Source form: both callees are declared without prototypes; the routine takes six words and hands words 3 to 6
 * on to osd_update_key_guide (the firmware passes them through unchanged).
 */
extern int osd_draw_key_guide();
extern int osd_update_key_guide();

#define KEY_TEXT_MOVE  0       /* key guide texts: Move, Enter, ... */
#define KEY_TEXT_ENTER 1

/* Draw the default key guide: osd_draw_key_guide(1, 2) for the icon cells,
 * then osd_update_key_guide with the texts Move and Enter. The six arguments
 * are not used here; the last four are handed on to osd_update_key_guide
 * unchanged. Called by the G.I. and PIP item handlers. */
void osd_draw_default_key_guide(unsigned int ignored_1,unsigned int ignored_2,unsigned int pass_3,unsigned int pass_4,
                 unsigned int pass_5,unsigned int pass_6)
{
  osd_draw_key_guide(1,2);
  osd_update_key_guide(KEY_TEXT_MOVE,KEY_TEXT_ENTER,pass_3,pass_4,pass_5,pass_6);
  return;
}
