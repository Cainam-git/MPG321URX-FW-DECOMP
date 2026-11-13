/* oled_request_sensing_in_factory_burn_in  (FUN_a0127ab8)
 *
 * In factory mode with Burn In on and device setting 17 at 1: request a sensing run and return 1.
 * Returns: 1 when requested, else 0
 * Note: Nothing calls this copy; the same steps are built into oled_is_off_sensing_due and oled_power_task.
 * Name basis: derived - tests the factory-mode marker 0x55AA (settings +0x1F6), the burn-in flag (+0x1D5) and
 *   device setting 17; then sets field +9 and clears +0xF of the OLED power state
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0127ab8 @ 0xa0127ab8, flags -mcpu=v8 -O3 -msoft-float.
 * Source form: one local result set in the two branches. Nothing calls this copy; the same function is also built
 * into oled_choose_recover_mode and oled_power_task.
 */
struct oled_power_state_record {
    unsigned char state, sub;
    unsigned short t2, t4, cnt;
    unsigned char byte_0x8, byte_0x9, byte_0xa, byte_0xb;
    union { unsigned char b; unsigned short h; } c;
    unsigned char be, target;
    unsigned char b10, b11, b12, b13;
    unsigned short h14;
    unsigned char b16;
};
struct user_settings_record {
    unsigned char p000[0x1d5];
    unsigned char burn_in_flag;
    unsigned char p1d6[0x1e2 - 0x1d6];
    unsigned char b1e2, b1e3, b1e4, b1e5, b1e6, b1e7;
    unsigned char p1e8[0x1f4 - 0x1e8];
    union { unsigned int w; struct { unsigned short hi, lo; } h; } u1f4;
};
extern struct oled_power_state_record oled_power_state;
extern struct user_settings_record user_settings;
#define S oled_power_state
#define G user_settings
extern unsigned short nvram_get_device_setting(unsigned int);

#define USAGE_MARKER                0x55aa  /* the factory-mode marker (written by ddc_tool_set_factory_mode) that
                                               the settings halfword at +0x1F6 (u1f4.h.lo) must hold */
#define DEVICE_SETTING_USAGE_RECORD 0x11    /* device setting 17 */

/*
 * Tell whether a sensing run is wanted in factory burn-in: settings halfword +0x1F6 holds the factory-mode marker
 * 0x55AA (the constant's name USAGE_MARKER is historical; no usage record is checked), the burn-in flag
 * (+0x1D5) is set and device setting 17 is 1. In that case field +0x09 of the OLED power state record is set
 * to 1 and field +0x0F ("target") cleared. Returns 1 in that case, else 0.
 */
unsigned char oled_request_sensing_in_factory_burn_in(void)
{
    unsigned char valid;
    if (G.u1f4.h.lo == USAGE_MARKER && G.burn_in_flag != 0 && nvram_get_device_setting(DEVICE_SETTING_USAGE_RECORD) == 1) {
        S.byte_0x9 = 1;
        S.target = 0;
        valid = 1;
    } else
        valid = 0;
    return valid;
}
