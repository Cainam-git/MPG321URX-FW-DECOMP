/* osd_ignore_panel_info_select_copy5  (FUN_a00bdeb8)
 *
 * Do nothing when OK or right is pressed on OLED Panel Info.
 * Note: Empty function in the handler table. Identical copy of osd_ignore_panel_info_select.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x3B = 'OLED Panel Info.' (MSI OLED Care
 *   texts 0x185E78)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bdeb8 @ 0xa00bdeb8 (-mcpu=v8 -O2 -g)
 * Empty function: returns at once.
 */

/* Handler for OK / right on the OLED Panel Info item: nothing to do. */
void osd_ignore_panel_info_select_copy5(void)

{
  return;
}
