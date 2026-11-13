/* oled_choose_recover_mode  (FUN_a0127b24)
 *
 * Decide whether an off sensing run must start while the OLED power machine idles: 2 or 0.
 * Returns: 2 (off sensing) or 0
 * Note: Nothing calls this copy; oled_power_task has the same decision built in. Its third test ends in 'hours
 *   * 60 + count >= 0', which is always true.
 * Name basis: derived - forced-sensing byte, oled_is_off_sensing_due and the factory burn-in test; the same
 *   code sits in oled_power_task under the 'RecoverOFF' print
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0127b24 @ 0xa0127b24, flags -mcpu=v8 -O3 -g.
 * Source form: the two helpers (oled_request_sensing_in_factory_burn_in, oled_is_off_sensing_due) are written out before the
 * routine in this file, with one result local each; the routine is a chain of if / else if setting one mode
 * local. The firmware also has stand-alone copies of the helpers (oled_request_sensing_in_factory_burn_in, oled_is_off_sensing_due). The comparison
 * "hours * 60 + count >= 0" is kept: it is always true.
 */
/* Device settings (nvram_get_device_setting) read here; the factory menu prints the counts as "OFFS H" etc. */
#define DEVICE_SETTING_OFFS_COUNT   0xb     /* use time since the last off sensing run: count 0..59 below an hour */
#define DEVICE_SETTING_OFFS_HOURS   0xd     /* hours since the last off sensing run, printed as "OFFS H" */
#define DEVICE_SETTING_SENSING_TEST 0x10    /* factory menu switch "Sensing Test" */
#define DEVICE_SETTING_USAGE_RECORD 0x11    /* device setting 17 */

#define OFFS_HOURS_DUE          4           /* off sensing is due after this many hours of use */
#define OFFS_TEST_MINUTES_DUE   19          /* with "Sensing Test": due above hours * 60 + count = 19 */
#define FACTORY_MODE_MARKER     0x55aa      /* settings halfword +0x1F6 while the factory tool's factory mode is on */

#define RECOVER_MODE_NONE        0          /* no run */
#define RECOVER_MODE_OFF_SENSING 2          /* start the off sensing run */
#define AFTER_SENSING_DISPLAY    0          /* after the run go back to the picture ("Goto Display") */

/* The state record of the OLED power machine (oled_power_state) up to the fields used here. */
struct oled_power_record {
    unsigned char state, step;
    unsigned short second_ticks, ticks, seconds;
    unsigned char blink_phase;
    unsigned char sensing_requested;    /* +0x09 a run is wanted */
    unsigned char forced_sensing;       /* +0x0A start off sensing without checking the use time */
    unsigned char byte_0xb;
    union { unsigned char b; unsigned short h; } power_down;
    unsigned char byte_0xe;
    unsigned char after_sensing;        /* +0x0F what follows a run (0 = back to the picture) */
    unsigned char qsm_done, byte_0x11, fake_sleep, sensing_active;
    unsigned short run_seconds;
    unsigned char blink_count;
};
/* The fields of the user settings record that are read here. */
struct user_settings_record {
    unsigned char p000[0x1d5];
    unsigned char burn_in_flag;                 /* +0x1D5 */
    unsigned char p1d6[0x1e2 - 0x1d6];
    unsigned char b1e2, b1e3, b1e4, b1e5, b1e6, b1e7;
    unsigned char p1e8[0x1f4 - 0x1e8];
    union { unsigned int w; struct { unsigned short hi, factory_mode_marker; } h; } word_0x1f4;
};
extern struct oled_power_record oled_power_state;
extern struct user_settings_record user_settings;
#define power    oled_power_state
#define settings user_settings
extern unsigned short nvram_get_device_setting(unsigned int);

/* 1 when the factory mode marker, the burn-in flag and device setting 17 are all set; then a run is requested
   and the run is to end back at the picture. */
unsigned char oled_request_sensing_in_factory_burn_in(void)
{
    unsigned char valid;
    if (settings.word_0x1f4.h.factory_mode_marker == FACTORY_MODE_MARKER && settings.burn_in_flag != 0 && nvram_get_device_setting(DEVICE_SETTING_USAGE_RECORD) == 1) {
        power.sensing_requested = 1;
        power.after_sensing = AFTER_SENSING_DISPLAY;
        valid = 1;
    } else
        valid = 0;
    return valid;
}

/* 1 when the use time since the last off sensing run has reached the point where the next run is due: 4 hours,
   or with the factory switch "Sensing Test" on, hours * 60 + count above 19. */
unsigned char oled_is_off_sensing_due(void)
{
    unsigned char due;
    if (nvram_get_device_setting(DEVICE_SETTING_SENSING_TEST) == 0) {
        if (nvram_get_device_setting(DEVICE_SETTING_OFFS_HOURS) >= OFFS_HOURS_DUE) due = 1; else due = 0;
    } else {
        if (nvram_get_device_setting(DEVICE_SETTING_OFFS_HOURS) * 60 + nvram_get_device_setting(DEVICE_SETTING_OFFS_COUNT) > OFFS_TEST_MINUTES_DUE) due = 1; else due = 0;
    }
    return due;
}

/*
 * Decide whether an off sensing run must start while the OLED power machine is in its idle state (RecoverOFF).
 * Returns 2 (RECOVER_MODE_OFF_SENSING) or 0. Nothing calls this copy; the power machine (oled_power_task) has
 * the same decision built in.
 *
 * Mode 2 when, tested in this order:
 *   1. the "forced sensing" byte of the power record is 1 (set by the panel refresh request);
 *   2. the use time says a run is due (oled_is_off_sensing_due);
 *   3. oled_request_sensing_in_factory_burn_in gives 1 (despite its name it tests factory mode with Burn In on and device
 *      setting 17 = 1, no usage record; it also marks a run as wanted and sets "back to the picture" as its
 *      end) and "hours * 60 + count >= 0", which is always true.
 * Otherwise mode 0.
 */
unsigned char oled_choose_recover_mode(void)
{
    unsigned char mode;
    if (power.forced_sensing == 1) mode = RECOVER_MODE_OFF_SENSING;
    else if (oled_is_off_sensing_due()) mode = RECOVER_MODE_OFF_SENSING;
    else if (oled_request_sensing_in_factory_burn_in() == 1 && nvram_get_device_setting(DEVICE_SETTING_OFFS_HOURS) * 60 + nvram_get_device_setting(DEVICE_SETTING_OFFS_COUNT) >= 0) mode = RECOVER_MODE_OFF_SENSING;
    else mode = RECOVER_MODE_NONE;
    return mode;
}
