/* oled_is_off_sensing_due  (FUN_a0127a34)
 *
 * Return whether enough use time has passed for the panel's off-state sensing.
 * Returns: 0 or 1
 * Name basis: derived - hours * 60 + minutes above 19, or hours at least 4, from the device settings; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0127a34 @ 0xa0127a34, flags -mcpu=v8 -O3 -msoft-float.
 * Source form: one local result, set in four branches. Nothing calls this copy; the same function is also
 * built into oled_power_task (the OLED power task) and oled_choose_recover_mode.
 */
extern unsigned short nvram_get_device_setting(unsigned int);
#define DEVICE_SETTING_SENSING_TEST 0x10    /* factory switch "Sensing Test" */
#define DEVICE_SETTING_OFFS_COUNT   0xb     /* count 0..59 below an hour (see "OFFS H") */
#define DEVICE_SETTING_OFFS_HOURS   0xd     /* hours counted, printed as "OFFS H" */

/*
 * Tell whether the counted OFFS time has reached the point of off sensing: 4 or more hours in normal use; with
 * the "Sensing Test" switch on, hours * 60 + count above 19. Returns 1 or 0. Nothing calls this copy.
 */
unsigned char oled_is_off_sensing_due(void)
{
    unsigned char due;
    if (nvram_get_device_setting(DEVICE_SETTING_SENSING_TEST) == 0) {
        if (nvram_get_device_setting(DEVICE_SETTING_OFFS_HOURS) >= 4) due = 1; else due = 0;
    } else {
        if (nvram_get_device_setting(DEVICE_SETTING_OFFS_HOURS) * 60 + nvram_get_device_setting(DEVICE_SETTING_OFFS_COUNT) > 19) due = 1; else due = 0;
    }
    return due;
}
