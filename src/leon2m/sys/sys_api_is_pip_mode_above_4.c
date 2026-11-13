/* sys_api_is_pip_mode_above_4  (FUN_a0148854)
 *
 * Return whether the picture-in-picture mode (device settings byte +7) is above 4.
 * Returns: 0 or 1
 * Name basis: derived - plain test of device_settings_pip_mode; twin of sys_is_pip_mode_above_4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148854 @ 0xa0148854-0xa0148868 (5 words), flags -mcpu=v8 -O2 -g.
 * Source form: the base device_settings (not the mid-record name device_settings_pip_mode) and two early returns
 * 'if (b > 4) return 1; return 0;': ifcvt then emits the fw cmp 5 / subx scc; the expression, ternary and
 * flag-variable forms all keep a branch (cmp 4; bgu).
 * Aids: none.
 */
#define DEVICE_SETTINGS_PIP_MODE 7   /* byte +7 of the device settings (pip_mode) */

extern unsigned char device_settings[];

/* Return 1 when byte +7 of the device settings (the picture-in-picture mode) is above 4, else 0. */
unsigned char sys_api_is_pip_mode_above_4(void)
{
    if (device_settings[DEVICE_SETTINGS_PIP_MODE] > 4)
        return 1;
    return 0;
}
