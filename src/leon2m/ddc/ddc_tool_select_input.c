/* ddc_tool_select_input  (FUN_a00d1d34)
 *
 * Switch to the input the factory tool names.
 *   p: request
 * Returns: 0xE0
 * Note: Codes 8, 9, 0x0D, 0x0F select inputs 0..3.
 * Name basis: derived - settings byte +0x1E, osd_apply_input_change; caller ddc_tool_dispatch_command
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d1d34 @ 0xa00d1d34-0xa00d1e08 (53 words), flags -mcpu=v8 -O3 (no -g: with -g a nop follows the
 * final call).
 * Source form: an if/else chain with the test written in each arm (a switch gives a compare tree).
 */

/* The one field of the user settings record used here (docs/RECORDS.md). */
struct user_settings_record {
    unsigned char pad000[0x1e];
    unsigned char input_source;                 /* +0x1E: the Input Source menu index */
};
extern struct user_settings_record user_settings;
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern unsigned char input_api_menu_index_to_source_id(unsigned char);
extern void osd_apply_input_change(void);
extern void ddc_raise_event0(void);

#define TOOL_RESULT_DONE 0xe0                   /* the command was carried out */

/* Request byte 7 values: the tool's numbers of the inputs 0..3. */
#define TOOL_INPUT_0     8
#define TOOL_INPUT_1     9
#define TOOL_INPUT_2     0x0d
#define TOOL_INPUT_3     0x0f

/*
 * Factory tool command 0x0A (TOOL_CMD_SELECT_INPUT): switch to the input named by request byte 7 (TOOL_INPUT_0
 * .. TOOL_INPUT_3 for inputs 0..3). Nothing happens when that input is already the one the menu index stands
 * for; any other byte value changes nothing. A change stores the new menu index in the Input Source setting and
 * calls osd_apply_input_change. DDC/CI event 0 is raised in every case.
 *
 *   p  the request; byte 7 is the value
 *
 * Returns TOOL_RESULT_DONE. Called by ddc_tool_dispatch_command.
 */
int ddc_tool_select_input(unsigned char *p)
{
    if (p[7] == TOOL_INPUT_0) {
        if (input_api_source_id_to_menu_index(user_settings.input_source) != 0) {
            user_settings.input_source = input_api_menu_index_to_source_id(0);
            osd_apply_input_change();
        }
    } else if (p[7] == TOOL_INPUT_1) {
        if (input_api_source_id_to_menu_index(user_settings.input_source) != 1) {
            user_settings.input_source = input_api_menu_index_to_source_id(1);
            osd_apply_input_change();
        }
    } else if (p[7] == TOOL_INPUT_2) {
        if (input_api_source_id_to_menu_index(user_settings.input_source) != 2) {
            user_settings.input_source = input_api_menu_index_to_source_id(2);
            osd_apply_input_change();
        }
    } else if (p[7] == TOOL_INPUT_3) {
        if (input_api_source_id_to_menu_index(user_settings.input_source) != 3) {
            user_settings.input_source = input_api_menu_index_to_source_id(3);
            osd_apply_input_change();
        }
    }
    ddc_raise_event0();
    return TOOL_RESULT_DONE;
}
