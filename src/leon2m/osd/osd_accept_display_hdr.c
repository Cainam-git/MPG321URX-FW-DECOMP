/* osd_accept_display_hdr  (FUN_a0096ce4)
 *
 * Keep the highlighted DisplayHDR mode and apply it if it changed (OK)
 * Note: A change closes the menu and applies the mode (sys_user_apply_startup_settings).
 * Name basis: derived - handler table 0xA802422C: OK on states 0x77..0x79; texts 0x190CEC: True Black 400,
 *   Peak 1000 nits, EOTF Boost
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0096ce4 @ 0xa0096ce4-0xa0096e14 (76 words), flags -mcpu=v8 -O3 -g.
 * Source form: the app_state_record flags are unsigned short bit-fields (bit 15 tested, bit 10 set); the
 * DisplayHDR mode is read from settings word +0xAC as (word >> 18) & 3 at each use.
 */
struct app_state_record {
    unsigned char pad[4];
    unsigned short bit15 : 1, bits11_14 : 4, bit10 : 1, rest : 10;     /* halfword +4: bit 15 = SLEEP_WORD_BIT15, bit 10 = SLEEP_WORD_BIT10 */
    unsigned char pad6[4];
    unsigned short half_0xa;
};
struct user_settings_record {
    unsigned char pad[0xac];
    unsigned int settings_page_flags;           /* +0xAC: bits 18..19 = DisplayHDR mode, bit 20 = SETTINGS_PAGE_FLAG_BIT20 */
};
extern struct app_state_record app_state_record;
extern struct user_settings_record user_settings;
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern unsigned char osd_request_bits;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void input_rearm_port_event(unsigned char, unsigned char);
extern void osd_hide_menu(void);
extern void sys_user_apply_startup_settings(void);
extern unsigned char input_api_get_channel_port_code(unsigned char);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern void sys_app_timer_start(int, int);

#define MENU_STATE_DISPLAY_HDR_LIST   0x77      /* + mode: the DisplayHDR list (states 0x77..0x79) */
#define MENU_STATE_DISPLAY_HDR_ITEM   0x1d      /* DisplayHDR item of the page, item row 5 */
#define SETTINGS_PAGE_FLAG_BIT20      0x100000  /* bit 20 of the settings page flags */
#define APP_STATE_CEC_SOURCE_HOLD     0x40      /* bit 6 of app_state_record halfword +0xA */
#define APP_TIMER_CEC_SOURCE_HOLD     0x14      /* started with 5000 ms together with APP_STATE_CEC_SOURCE_HOLD */

/*
 * OK in the DisplayHDR list (menu states 0x77..0x79: True Black 400, Peak 1000 nits, EOTF Boost; reached
 * through the handler table). The stored mode is bits 18..19 of settings word +0xAC; osd_choice_row is the
 * row the code compares it with.
 *
 * The list is left: the old row is unhighlighted and unmarked, the row of the present state is highlighted, the
 * stored mode is marked, the menu state becomes 0x1D and item row 5 is highlighted.
 * When the stored mode differs from osd_choice_row it is applied: bit 10 of halfword +4 is set and the port
 * events are re-armed when bit 15 of it is set, the menu is closed and the start-up settings are applied
 * (sys_user_apply_startup_settings). Then, if channel 0 has a source and settings flag bit 20 is set, the CEC
 * source hold is started for 5000 ms.
 * At the end bits 0x02 (OSD_REQUEST_SETTINGS_CHANGED) and 0x04 (OSD_REQUEST_EVENT_83) of osd_request_bits are set.
 */
void osd_accept_display_hdr(void)
{
    osd_clear_choice_highlight(osd_choice_row);
    osd_draw_choice_mark(1, osd_choice_row, 0);
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_DISPLAY_HDR_LIST, 0);
    osd_draw_choice_mark(1, (user_settings.settings_page_flags >> 18) & 3, 1);
    osd_menu_state = MENU_STATE_DISPLAY_HDR_ITEM;
    osd_highlight_item_row(5, 1);
    if (osd_choice_row != ((user_settings.settings_page_flags >> 18) & 3)) {
        if (app_state_record.bit15) {
            app_state_record.bit10 = 1;
            input_rearm_port_event(4, 0);
        }
        osd_menu_state = 0;
        osd_hide_menu();
        sys_user_apply_startup_settings();
        if (input_api_source_id_to_menu_index(input_api_get_channel_port_code(0)) && (user_settings.settings_page_flags & SETTINGS_PAGE_FLAG_BIT20)) {
            app_state_record.half_0xa |= APP_STATE_CEC_SOURCE_HOLD;
            sys_app_timer_start(APP_TIMER_CEC_SOURCE_HOLD, 5000);
        }
    }
    osd_request_bits |= 6;
}
