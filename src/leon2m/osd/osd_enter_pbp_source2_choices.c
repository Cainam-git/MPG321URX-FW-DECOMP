/* osd_enter_pbp_source2_choices  (FUN_a00982f0)
 *
 * Open the input list for PBP Source 2 on the current second input.
 * Note: States 0xD4..0xD7; input = settings byte +0x20.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x83 = 'Source 2' (texts 0x182534)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00982f0 @ 0xa00982f0-0xa0098364 (116 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the form of osd_enter_pip_source_choices. The settings record is a byte array; the second input
 * byte (+0x20) is read again for every use.
 */
extern unsigned char osd_list_id, osd_edit_value;
extern unsigned int osd_menu_state;
extern unsigned char user_settings[];
extern unsigned char input_api_source_id_to_menu_index(unsigned char x);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_input_choices(void);

#define USER_SETTINGS_SECOND_SOURCE  0x20       /* offset of the source of the second picture */
#define USER_SETTINGS_PBP_SOURCE_SLOT 0x1a3     /* offset of the byte that says which PBP source the list edits */
#define PBP_SOURCE_SLOT_2            1          /* Source 2 (Source 1 is 0) */
#define MENU_STATE_INPUT_CHOICES     0xd4       /* + input: the PBP source input list (states 0xD4..0xD7) */
#define LIST_ID_PIP_PBP_ITEMS        5          /* osd_list_id value set when an input list opens */
#define CHOICE_ROW_PLAIN             0          /* highlight style of a choice row while the list is left */
#define CHOICE_ROW_EDGED             1          /* highlight style of a choice row in the open list */

/*
 * OK or right on the Source 2 item of the PBP list (menu state 0x83): open the list of inputs for PBP source 2.
 *
 * osd_list_id becomes 5 and the settings byte +0x1A3 (the PBP source being edited) is set to 1. The four input
 * names are drawn. The source of the second picture is saved in osd_edit_value. The menu state becomes 0xD4 plus
 * the translation of that source (input_api_source_id_to_menu_index), and the translated row is highlighted, first in
 * the plain and then in the edged style.
 */
void osd_enter_pbp_source2_choices(void)
{
    osd_list_id = LIST_ID_PIP_PBP_ITEMS;
    user_settings[USER_SETTINGS_PBP_SOURCE_SLOT] = PBP_SOURCE_SLOT_2;
    osd_draw_input_choices();
    osd_edit_value = user_settings[USER_SETTINGS_SECOND_SOURCE];
    osd_menu_state = input_api_source_id_to_menu_index(user_settings[USER_SETTINGS_SECOND_SOURCE]) + MENU_STATE_INPUT_CHOICES;
    osd_highlight_choice_row(input_api_source_id_to_menu_index(user_settings[USER_SETTINGS_SECOND_SOURCE]), CHOICE_ROW_PLAIN);
    osd_highlight_choice_row(input_api_source_id_to_menu_index(user_settings[USER_SETTINGS_SECOND_SOURCE]), CHOICE_ROW_EDGED);
}
