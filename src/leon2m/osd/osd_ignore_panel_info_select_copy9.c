/* osd_ignore_panel_info_select_copy9  (FUN_a0148374)
 *
 * Do nothing when OK or right is pressed on OLED Panel Info.
 * Note: Empty function in the handler table. Identical copy of osd_ignore_panel_info_select.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x3B = 'OLED Panel Info.' (MSI OLED Care
 *   texts 0x185E78)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148374 @ 0xa0148374, flags -mcpu=v8 -O2 -g.
 * Empty function: returns at once.
 */

/* Handler for OK or right on the OLED Panel Info line: it does nothing. */
void osd_ignore_panel_info_select_copy9(void)

{
  return;
}
