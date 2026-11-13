/* sys_is_pip_mode_above_4  (FUN_a013d178)
 *
 * Return whether the picture-in-picture mode byte is above 4.
 * Returns: 0 or 1
 * Name basis: descriptive - byte at 0xA802E1A7
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013d178 @ 0xa013d178 (-mcpu=v8 -O2 -g)
 * Source form: compare with <= 4, return 0, else return 1 (int result).
 */
extern unsigned char device_settings_pip_mode;

/* Return 1 when the picture-in-picture mode is above 4, else 0. */
int sys_is_pip_mode_above_4(void)
{
    if (device_settings_pip_mode <= 4)
        return 0;
    return 1;
}
