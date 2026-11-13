/* osd_close_pip_custom_position  (FUN_a0093b74)
 *
 * Leave the free PIP positioning and return to the location list (OK key)
 * Note: Shows the menu layer again; state 0xDC.
 * Name basis: derived - OK on state 0x107 (handler table)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0093b74, flags -mcpu=v8 -O2 -g.
 * Source form: the routine takes six unsigned int parameters; the last four are passed on to osd_api_enable,
 * which is declared without a prototype, as in the firmware.
 */
#define MENU_STATE_PIP_LOCATION_CUSTOMIZE 0xdc  /* PIP Location choices, on the Customize row (choice row 4) */
#define CHOICE_ROW_CUSTOMIZE   4
#define CHOICE_ROW_PLAIN       0        /* osd_highlight_choice_row styles */
#define CHOICE_ROW_EDGED       1

extern unsigned int osd_menu_state;
extern void osd_highlight_choice_row();
extern int osd_api_enable();

/*
 * Leave the free positioning of the PIP window (OK key in menu state 0x107): the menu state goes back to the
 * Customize row of the PIP Location choices, which is highlighted in both styles, and menu layer 0 is switched
 * on again (osd_api_enable: first argument 1 = on, second = layer).
 * Parameters 3 to 6 are passed on to osd_api_enable; parameters 1 and 2 are not used.
 */
void osd_close_pip_custom_position(unsigned int unused_1, unsigned int unused_2, unsigned int arg3, unsigned int arg4,
                 unsigned int arg5, unsigned int arg6)

{
  osd_menu_state = MENU_STATE_PIP_LOCATION_CUSTOMIZE;
  osd_highlight_choice_row(CHOICE_ROW_CUSTOMIZE,2);
  osd_highlight_choice_row(CHOICE_ROW_CUSTOMIZE,CHOICE_ROW_EDGED);
  osd_api_enable(1,0,arg3,arg4,arg5,arg6);
  return;
}
