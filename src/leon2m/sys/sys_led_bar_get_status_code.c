/* sys_led_bar_get_status_code  (FUN_a00da870)
 *
 * Work out the status code 1..10 that the LED light bar shows.
 * Name basis: derived - from the settings and state records; stored at 0xA802D00D
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00da870 @ 0xa00da870, flags -mcpu=v8 -O3 -g.
 * Source form: v is read before the +0x1E4 / +0x1E5 test; the 'v <= 2' tests come first (the smaller code is
 * the fall-through); v is decremented only when non-zero. The firmware has the 'ldub v' in the branch delay
 * slot, before 'sethi &app_state_record', the same pattern as in panel_output_setup_clock / panel_output_setup_path.
 */
/* The bytes of the user settings record used here (no name is documented for them). */
struct user_settings_record {
    unsigned char pad0[0x1e2];
    unsigned char byte_0x1e2;   /* compared with app_state_record halfword +0x10, and tested against 2 */
    unsigned char byte_0x1e3;   /* the same for halfword +0x12 */
    unsigned char byte_0x1e4;   /* non-zero: code 5 */
    unsigned char byte_0x1e5;   /* non-zero: code 6 */
    unsigned char byte_0x1e6;   /* must be 1 for codes 7 and 9 */
    unsigned char byte_0x1e7;   /* must be 1 for codes 8 and 10 */
};
/* The fields of the application state record used here. */
struct app_state_record_fields {
    unsigned char pad00[0x10];
    unsigned short halfword_0x10;
    unsigned short halfword_0x12;
    unsigned char pad14[5];
    unsigned char status_code;      /* +0x19: the result, stored here */
};
extern struct user_settings_record user_settings;
extern struct app_state_record_fields app_state_record;

/*
 * Work out the status code 1..10 for the LED light bar, store it in app_state_record +0x19 and return it.
 * port is 0 for the first set of settings bytes (+0x1E2, +0x1E4, +0x1E6) and not 0 for the second set
 * (+0x1E3, +0x1E5, +0x1E7). Calls: osd_check_panel_protect_prompt.
 *   port 0:     byte +0x1E4 set -> 5;
 *               else v = byte +0x1E2; if v equals halfword +0x10 of the state record and byte +0x1E6 is 1:
 *               7 when (v - 1, or 0 when v is 0) <= 2, else 9;
 *               otherwise 1 when v <= 2, else 3.
 *   port not 0: byte +0x1E5 set -> 6;
 *               else v = byte +0x1E3; if v equals halfword +0x12 and byte +0x1E7 is 1: 8 when v <= 2, else 10;
 *               otherwise 2 when v <= 2, else 4.
 */
unsigned char sys_led_bar_get_status_code(unsigned char port)
{
    unsigned char v;
    if (port == 0) {
        v = user_settings.byte_0x1e2;
        if (user_settings.byte_0x1e4 != 0) { app_state_record.status_code = 5; return 5; }
        if (v == app_state_record.halfword_0x10 && user_settings.byte_0x1e6 == 1) {
            if (v != 0) v--;
            if (v <= 2) { app_state_record.status_code = 7; return 7; }
            app_state_record.status_code = 9; return 9;
        }
        if (v <= 2) { app_state_record.status_code = 1; return 1; }
        app_state_record.status_code = 3; return 3;
    }
    v = user_settings.byte_0x1e3;
    if (user_settings.byte_0x1e5 != 0) { app_state_record.status_code = 6; return 6; }
    if (v == app_state_record.halfword_0x12 && user_settings.byte_0x1e7 == 1) {
        if (v <= 2) { app_state_record.status_code = 8; return 8; }
        app_state_record.status_code = 10; return 10;
    }
    if (v <= 2) { app_state_record.status_code = 2; return 2; }
    app_state_record.status_code = 4; return 4;
}
