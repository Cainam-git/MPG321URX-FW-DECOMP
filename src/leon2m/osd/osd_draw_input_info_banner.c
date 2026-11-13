/* osd_draw_input_info_banner  (FUN_a00b848c)
 *
 * Draw the input info banner, or the HDR icon, after a new input is found.
 * Note: Re-maps the input byte +0x1E; uses bits 9/10 of 0xA802CFF4.
 * Name basis: derived - only caller osd_show_input_info_message; pages 0x1e / 0x11 of osd_draw_signal_message
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b848c @ 0xa00b848c-0xa00b8668 (119 words), flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: the halfword at 0xa802cff4 is a union of the plain halfword (the
 * updates) and a bit-field view (the bit 10 test); a mask test lets GCC reuse the loaded value where the
 * firmware reloads it.
 */
/* Messages of osd_draw_signal_message used here. */
#define SIGNAL_MESSAGE_HDR_ICON     0x11
#define SIGNAL_MESSAGE_EMPTY        0x15
#define SIGNAL_MESSAGE_INPUT_BANNER 0x1e

#define PORT_TYPE_5            5        /* port type for which the empty window is not drawn */
#define TIMING_FIELD_0x16      0x16     /* measured timing field of channel 0, read as non-zero or zero */
#define FACTORY_MARKER         0x55aa   /* value of user_settings factory marker (+0x1F6) that suppresses the messages */
#define APP_STATE_BIT9         0x200    /* app_state_record flag bits */
#define APP_STATE_BIT10        0x400    /* set by osd_apply_input_change */
#define APP_STATE_FLAG_15      0x8000   /* app_state_record +0x3E bit 15 */
#define OSD_REQUEST_SETTINGS_CHANGED 2
#define OSD_REQUEST_BIT0       1
#define OSD_LIST_QUICK_MENU    0x24

/* The user settings fields used here. */
struct user_settings_record {
    unsigned char pad0[0x1e];
    unsigned char input_source;                 /* +0x1E: the selected Input Source (menu index) */
    unsigned char pad1f[0x1d5 - 0x1f];
    unsigned char burn_in_flag;                 /* +0x1D5: burn-in mode on (1) or off (0) */
    unsigned char pad1d6[0x1f6 - 0x1d6];
    unsigned short factory_marker;              /* +0x1F6 */
};
/* The application state fields used here. */
struct app_state_record_layout {
    union {
        unsigned short h;
        struct {
            unsigned short low_bits : 5, bit10 : 1, bit9 : 1, high_bits : 9;
        } f;
    } flags;                                    /* +0x00: bit 9, bit 10 (APP_STATE_BIT10) */
    unsigned char pad2[0x3e - 2];
    unsigned short flags_0x3e;                  /* +0x3E: bit 15 is cleared when the menu is hidden */
};
extern struct user_settings_record user_settings;
extern struct app_state_record_layout app_state_record;
extern unsigned char osd_request_bits, osd_list_id;
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern unsigned char input_api_menu_index_to_source_id(unsigned char);
extern unsigned char input_get_port_sync_mode(unsigned int);
extern unsigned short input_api_get_timing_field(unsigned char, unsigned int);
extern void osd_draw_signal_message(int);
extern void sys_poll_events_stub_copy20(int);
extern void osd_api_enable(int, int);
extern void osd_api_set_window_enable(int, int, int);
extern int sys_user_get_picture_state(void);

/*
 * Fix up the stored Input Source, then draw what the main picture shows next to a new input: the empty
 * message window, the input name banner or the HDR icon. Called by osd_show_input_info_message.
 *
 * In this order:
 *   1. The stored Input Source is translated to a source id and back; when that gives another menu index, the
 *      index is replaced and "settings changed" is requested.
 *   2. Unless port 0 has type 5 or the burn-in flag is set, and while timing field 0x16 of channel 0 is zero,
 *      the empty message window is drawn and the menu layers are switched off again (as the first steps of
 *      osd_draw_signal_message do). If field 0x16 is then non-zero, request bit 0 is set.
 *   3. If app_state_record bit 10 (set by osd_apply_input_change) is set: the input name banner is drawn
 *      unless the factory marker holds 0x55aa; bit 10 is cleared; bit 9 is set when the picture state is
 *      non-zero and the marker is not 0x55aa, else cleared.
 *      If bit 10 is clear: bit 9 is cleared and the HDR icon is drawn when the picture state is non-zero and the
 *      marker is not 0x55aa.
 */
void osd_draw_input_info_banner(void)
{
    /* Menu index -> source id -> menu index; store the result when it differs. */
    if (user_settings.input_source != input_api_menu_index_to_source_id(input_api_source_id_to_menu_index(user_settings.input_source))) {
        user_settings.input_source = input_api_menu_index_to_source_id(input_api_source_id_to_menu_index(user_settings.input_source));
        osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
    }
    if (input_get_port_sync_mode(0) != PORT_TYPE_5 && input_api_get_timing_field(0, TIMING_FIELD_0x16) == 0 && user_settings.burn_in_flag == 0) {
        osd_draw_signal_message(SIGNAL_MESSAGE_EMPTY);
        sys_poll_events_stub_copy20(0);
        /* Switch both menu layers off and close all windows, as osd_draw_signal_message does at its start. */
        osd_api_enable(0, 0);
        osd_api_set_window_enable(8, 0, 0);
        osd_list_id = OSD_LIST_QUICK_MENU;
        osd_api_enable(0, 1);
        app_state_record.flags_0x3e &= ~APP_STATE_FLAG_15;
        if (input_api_get_timing_field(0, TIMING_FIELD_0x16) != 0)
            osd_request_bits |= OSD_REQUEST_BIT0;
    }
    if (app_state_record.flags.f.bit10) {
        if (user_settings.factory_marker != FACTORY_MARKER)
            osd_draw_signal_message(SIGNAL_MESSAGE_INPUT_BANNER);
        app_state_record.flags.h &= ~APP_STATE_BIT10;
        if (sys_user_get_picture_state() != 0 && user_settings.factory_marker != FACTORY_MARKER)
            app_state_record.flags.h |= APP_STATE_BIT9;
        else
            app_state_record.flags.h &= ~APP_STATE_BIT9;
    } else {
        app_state_record.flags.h &= ~APP_STATE_BIT9;
        if (sys_user_get_picture_state() != 0 && user_settings.factory_marker != FACTORY_MARKER)
            osd_draw_signal_message(SIGNAL_MESSAGE_HDR_ICON);
    }
}
