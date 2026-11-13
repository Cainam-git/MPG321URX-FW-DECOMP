/* osd_draw_hdr_icon  (FUN_a00b8668)
 *
 * Draw the small HDR icon window.
 * Note: Page 0x11 of osd_draw_signal_message (8 x 3 cell layout).
 * Name basis: derived - shown when sys_user_get_picture_state is non-zero (the same test prints 'HDR' in the
 *   info box); caller osd_run_periodic_task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b8668 @ 0xa00b8668 (-mcpu=v8 -O2 -g)
 */
#define SIGNAL_MESSAGE_HDR_ICON 0x11            /* osd_draw_signal_message page: small icon, 8 x 3 glyph block */

extern int osd_draw_signal_message();

/* Draw the small HDR icon window (page 0x11 of osd_draw_signal_message). */
void osd_draw_hdr_icon(void)

{
  osd_draw_signal_message(SIGNAL_MESSAGE_HDR_ICON);
  return;
}
