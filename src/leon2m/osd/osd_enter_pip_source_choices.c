/* osd_enter_pip_source_choices  (FUN_a0097b7c)
 *
 * Open the PIP Source list on the current sub-window input.
 * Note: States 0xD0..0xD3; input = settings byte +0x20.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x7A = 'Source'; texts 0x1828C0: Source,
 *   PIP Size, Location, Display Switch, Audio Switch
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0097b7c @ 0xa0097b7c-0xa0097bec (112 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is a byte array; the second input byte (+0x20) is read again for every use.
 * Same form as osd_enter_pbp_source2_choices.
 */
extern unsigned char osd_list_id, osd_edit_value;
extern unsigned int osd_menu_state;
extern unsigned char user_settings[];
extern unsigned char input_api_source_id_to_menu_index(unsigned char x);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_input_choices(void);

#define USER_SETTINGS_SECOND_SOURCE  0x20       /* offset of the source of the second picture */
#define MENU_STATE_INPUT_CHOICES     0xd0       /* + input: the PIP Source list (states 0xD0..0xD3) */
#define LIST_ID_PIP_PBP_ITEMS        5          /* osd_list_id value set when an input list opens */
#define CHOICE_ROW_PLAIN             0          /* highlight style of a choice row while the list is left */
#define CHOICE_ROW_EDGED             1          /* highlight style of a choice row in the open list */

/*
 * OK or right on the Source item of the PIP list: open the list of inputs for the PIP window.
 *
 * osd_list_id becomes 5 and the four input names are drawn. The present source of the second picture is saved in
 * osd_edit_value. The menu state becomes 0xD0 plus the translation of that source
 * (input_api_source_id_to_menu_index), and the translated row is highlighted, first in the plain and then in the
 * edged style.
 */
void osd_enter_pip_source_choices(void)
{
    osd_list_id = LIST_ID_PIP_PBP_ITEMS;
    osd_draw_input_choices();
    osd_edit_value = user_settings[USER_SETTINGS_SECOND_SOURCE];
    osd_menu_state = input_api_source_id_to_menu_index(user_settings[USER_SETTINGS_SECOND_SOURCE]) + MENU_STATE_INPUT_CHOICES;
    osd_highlight_choice_row(input_api_source_id_to_menu_index(user_settings[USER_SETTINGS_SECOND_SOURCE]), CHOICE_ROW_PLAIN);
    osd_highlight_choice_row(input_api_source_id_to_menu_index(user_settings[USER_SETTINGS_SECOND_SOURCE]), CHOICE_ROW_EDGED);
}
