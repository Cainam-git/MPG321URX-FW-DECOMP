/* osd_ignore_panel_info_select_copy  (FUN_a0099e3c)
 *
 * Do nothing when OK or right is pressed on OLED Panel Info.
 * Note: Empty function in the handler table. Identical copy of osd_ignore_panel_info_select.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x3B = 'OLED Panel Info.' (MSI OLED Care
 *   texts 0x185E78)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099e3c @ 0xa0099e3c, flags -mcpu=v8 -O2 -g (the default of the section). Empty routine.
 */

/*
 * Same as osd_ignore_panel_info_select: nothing happens, the routine returns at once.
 */
void osd_ignore_panel_info_select_copy(void)

{
  return;
}
