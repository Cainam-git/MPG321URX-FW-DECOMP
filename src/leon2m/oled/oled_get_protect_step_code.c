/* oled_get_protect_step_code  (FUN_a00b1654)
 *
 * Return the panel protect step code (0x1E, 0x32, 0x37) that applies now.
 *   offs_hours: hours of OFFS time (device setting 13, low byte)
 *   offs_count: count below an hour (device setting 11, 0..59)
 * Returns: step code or 0
 * Note: Depends on the Sensing Test switch (nvram_get_device_setting(0x10)) and the last entry of the care
 *   table (oled_get_care_table_byte)
 * Name basis: descriptive - called three times by osd_run_periodic_task before the panel protect prompt
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b1654 @ 0xa00b1654-0xa00b1700 (172 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the zero-result branch (Sensing Test off) is written first. Register renaming then visits its
 * blocks before the offs_hours == 1 test, so the masked offs_hours of that test is renamed to %o7, the one
 * call-clobbered register they leave unused.
 */
extern unsigned short nvram_get_device_setting(unsigned int id);
extern int oled_get_care_table_byte(unsigned char i);

#define DEVICE_SETTING_SENSING_TEST 0x10    /* factory menu switch "Sensing Test" */
#define CARE_TABLE_LAST             0xff    /* oled_get_care_table_byte: index of the last entry */

/* The three prompt steps, named by the count at which they are shown. */
#define PROTECT_STEP_30             0x1e
#define PROTECT_STEP_50             0x32
#define PROTECT_STEP_55             0x37

/*
 * Tell whether the OLED panel protect prompt is due now, and which of its three steps.
 *
 *   offs_hours  device setting 13, the hour count printed as "OFFS H" (only its low byte is passed)
 *   offs_count  device setting 11, the count below an hour (0..59) that advances the OFFS hours at 60
 *
 * Returns 0x1E, 0x32 or 0x37 when a prompt step is due, else 0. In normal use the steps fall at counts 30, 50 and
 * 55 of the last OFFS hour before the hour value in the last entry of the OLED care table. With the factory
 * switch "Sensing Test" on, the same three steps come early, at counts 17, 18 and 19 of OFFS hour 1, for testing.
 *
 * Called three times in a row by osd_run_periodic_task, which shows the prompt when the step differs from the one
 * shown last.
 */
unsigned char oled_get_protect_step_code(unsigned char offs_hours, unsigned char offs_count)
{
    if (nvram_get_device_setting(DEVICE_SETTING_SENSING_TEST) == 0) {
        if (offs_hours == oled_get_care_table_byte(CARE_TABLE_LAST) - 1
            && (offs_count == PROTECT_STEP_30 || offs_count == PROTECT_STEP_50 || offs_count == PROTECT_STEP_55))
            return offs_count;
        return 0;
    } else {
        if (offs_hours == 1) {
            if (offs_count == 0x11)
                return PROTECT_STEP_30;
            if (offs_count == 0x12)
                return PROTECT_STEP_50;
            if (offs_count == 0x13)
                return PROTECT_STEP_55;
        }
        return 0;
    }
}
