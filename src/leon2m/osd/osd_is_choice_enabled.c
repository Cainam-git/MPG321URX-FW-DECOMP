/* osd_is_choice_enabled  (FUN_a00aad30)
 *
 * Return 1 when a choice of the open list can be selected.
 *   choice: choice index
 * Returns: 1 enabled, 0 skipped
 * Note: Page from byte 0xA802B08F; depends on HDR, PIP/PBP and other settings.
 * Name basis: derived - the loop test of every osd_select_prev|next_<setting> handler; rejected choices are
 *   greyed (0x296)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00aad30 @ 0xa00aad30, flags -mcpu=v8 -O3 -g.
 * Source form: bit 31 of word +0x1f4 (the DSC switch) is a signed 1-bit bit-field (as in osd_apply_pip_pbp_mode).
 */
/* The fields of the user settings record that this routine reads. */
struct user_settings_head {
    unsigned char pad_0x0[0x1e];
    unsigned char input_source;                 /* +0x1E */
    unsigned char pip_pbp_mode;                 /* +0x1F: 0 = single picture */
    unsigned char second_source;                /* +0x20 */
    unsigned char pad_0x21[0x1a4 - 0x21];
    unsigned char screen_size;                  /* +0x1A4 */
    unsigned char pad_0x1a5[0x1f4 - 0x1a5];
    union {
        unsigned int w;
        struct {
            signed int dsc_switch : 1;          /* bit 31 */
            unsigned int rest : 31;
        } f;
    } word_0x1f4;
};
extern struct user_settings_head user_settings;
extern unsigned char osd_list_id;
extern unsigned char osd_step_pro_mode_index(unsigned char, unsigned char);
extern int sys_user_get_picture_state(void);
extern unsigned short input_api_get_timing_field(unsigned char, unsigned int);
extern unsigned short panel_api_get_active_size(int);

#define LIST_ID_PRO_MODE     0xc
#define LIST_ID_SCREEN_SIZE  0xe
#define LIST_ID_PIP_ITEMS    0xf
#define LIST_ID_PBP_ITEMS    0x10
#define TIMING_WIDTH         7          /* input_api_get_timing_field selectors */
#define TIMING_HEIGHT        8
#define PANEL_SIZE_WIDTH     0          /* panel_api_get_active_size selectors */
#define PANEL_SIZE_LINES     1

/*
 * Tell whether a choice of the open choice list can be selected; 0 means the choice is skipped when the
 * cursor steps through the list (and is drawn greyed out).
 *
 *   choice  choice row in the list
 *
 * By the open list (osd_list_id), every case not named is enabled:
 *   Pro mode list (0xC)    the choices from osd_step_pro_mode_index(4, 0) to osd_step_pro_mode_index(6, 0)
 *                          are disabled when sys_user_get_picture_state() is not 0.
 *   Screen Size list (0xE) choices 3, 5 and 6 are disabled when pip_pbp_mode is not 0; choice 3 also when the
 *                          DSC switch is on. Choice 4 is disabled when pip_pbp_mode is not 0; otherwise,
 *                          when the input's width equals the panel's active width and its height is not
 *                          below the panel's active lines, the answer is whether screen_size is 3 (and
 *                          the later tests are not made).
 *   PIP list (0xF)         choices 3 and 4 are disabled when the two sources are the same.
 *   PBP list (0x10)        choices 5 and 6 are disabled when the two sources are the same.
 *
 * Called in the loop of the previous/next handler of each choice list.
 */
unsigned char osd_is_choice_enabled(unsigned char choice)
{
    if (osd_list_id == LIST_ID_PRO_MODE && osd_step_pro_mode_index(4, 0) <= choice && choice <= osd_step_pro_mode_index(6, 0) && sys_user_get_picture_state() != 0)
        return 0;
    if (osd_list_id == LIST_ID_SCREEN_SIZE) {
        if (choice == 4) {
            if (user_settings.pip_pbp_mode)
                return 0;
            if (input_api_get_timing_field(0, TIMING_WIDTH) == panel_api_get_active_size(PANEL_SIZE_WIDTH) && input_api_get_timing_field(0, TIMING_HEIGHT) >= panel_api_get_active_size(PANEL_SIZE_LINES))
                return user_settings.screen_size == 3;
        } else if (choice == 3) {
            if (user_settings.pip_pbp_mode)
                return 0;
            if (user_settings.word_0x1f4.f.dsc_switch)
                return 0;
        } else if (choice == 5) {
            if (user_settings.pip_pbp_mode)
                return 0;
        } else if (choice == 6) {
            if (user_settings.pip_pbp_mode)
                return 0;
        }
    }
    if (osd_list_id == LIST_ID_PIP_ITEMS && (unsigned char)(choice - 3) <= 1 && user_settings.input_source == user_settings.second_source)
        return 0;
    if (osd_list_id == LIST_ID_PBP_ITEMS && (unsigned char)(choice - 5) <= 1 && user_settings.input_source == user_settings.second_source)
        return 0;
    return 1;
}
