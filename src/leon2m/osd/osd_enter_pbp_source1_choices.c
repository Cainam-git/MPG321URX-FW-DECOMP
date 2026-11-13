/* osd_enter_pbp_source1_choices  (FUN_a0098280)
 *
 * Open the input list for PBP Source 1 on the current main input.
 * Note: States 0xD4..0xD7; input = settings byte +0x1E.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x82 = 'Source 1' (texts 0x182534)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0098280 @ 0xa0098280 (-mcpu=v8 -O3 -g)
 * Source form: the main input byte (+0x1E) is read again for the second and third translation call; the
 * translation result is kept in an unsigned char. The settings record is a byte array.
 */
extern unsigned char osd_edit_value;
extern unsigned char osd_list_id;
extern unsigned char user_settings[];
extern unsigned int osd_menu_state;

extern void osd_draw_input_choices(void);
extern int input_api_source_id_to_menu_index(unsigned char);
extern void osd_highlight_choice_row(int, int);

#define USER_SETTINGS_INPUT_SOURCE   0x1e       /* offset of the Input Source byte (the main input) */
#define USER_SETTINGS_PBP_SOURCE_SLOT 0x1a3     /* offset of the byte that says which PBP source the list edits */
#define PBP_SOURCE_SLOT_1            0          /* Source 1 (Source 2 is 1) */
#define MENU_STATE_INPUT_CHOICES     0xd4       /* + input: the PBP source input list (states 0xD4..0xD7) */
#define LIST_ID_PIP_PBP_ITEMS        5          /* osd_list_id value set when an input list opens */
#define CHOICE_ROW_PLAIN             0          /* highlight style of a choice row while the list is left */
#define CHOICE_ROW_EDGED             1          /* highlight style of a choice row in the open list */

/*
 * OK or right on the Source 1 item of the PBP list (menu state 0x82): open the list of inputs for PBP source 1.
 *
 * osd_list_id becomes 5 and the settings byte +0x1A3 (the PBP source being edited) is set to 0. The four input
 * names are drawn. The main input is saved in osd_edit_value. The menu state becomes 0xD4 plus the translation of
 * that input (input_api_source_id_to_menu_index), and the translated row is highlighted, first in the plain and then
 * in the edged style.
 */
void osd_enter_pbp_source1_choices(void)
{
    unsigned char input;

    osd_list_id = LIST_ID_PIP_PBP_ITEMS;
    user_settings[USER_SETTINGS_PBP_SOURCE_SLOT] = PBP_SOURCE_SLOT_1;
    osd_draw_input_choices();
    input = user_settings[USER_SETTINGS_INPUT_SOURCE];
    osd_edit_value = input;
    input = input_api_source_id_to_menu_index(input);
    osd_menu_state = (input & 0xff) + MENU_STATE_INPUT_CHOICES;
    input = input_api_source_id_to_menu_index(user_settings[USER_SETTINGS_INPUT_SOURCE]);
    osd_highlight_choice_row(input & 0xff, CHOICE_ROW_PLAIN);
    input = input_api_source_id_to_menu_index(user_settings[USER_SETTINGS_INPUT_SOURCE]);
    osd_highlight_choice_row(input & 0xff, CHOICE_ROW_EDGED);
}
