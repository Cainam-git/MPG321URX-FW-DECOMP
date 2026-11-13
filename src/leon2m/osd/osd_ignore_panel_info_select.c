/* osd_ignore_panel_info_select  (FUN_a0099d6c)
 *
 * Do nothing when OK or right is pressed on OLED Panel Info.
 * Note: Empty function in the handler table.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x3B = 'OLED Panel Info.' (MSI OLED Care
 *   texts 0x185E78)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099d6c @ 0xa0099d6c, flags -mcpu=v8 -O2 -g (the default of the section). Empty routine.
 */

/*
 * OK or right on the OLED Panel Info. item of the MSI OLED Care page: nothing happens. The routine is an
 * entry of the key handler table and returns at once.
 */
void osd_ignore_panel_info_select(void)

{
  return;
}
