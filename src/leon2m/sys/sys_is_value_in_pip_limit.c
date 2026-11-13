/* sys_is_value_in_pip_limit  (FUN_a013cecc)
 *
 * Return whether a value is inside the limit for the current picture-in-picture mode.
 * Returns: 0 or 1
 * Name basis: descriptive - limit chosen by the PIP mode byte; value 3 also passes with configuration bit 21
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013cecc @ 0xa013cecc-0xa013cf84 (46 words), flags -mcpu=v8 -O3 -g. Caller: sys_channel_apply_output_timing.
 * The limits are a switch with a jump table (0xdc89c).
 */
#define SYS_CONFIG_BIT21 0x200000   /* bit 21 of sys_config: lets the value 3 pass in every mode */

extern unsigned char device_settings_pip_mode;
extern unsigned int sys_config;

/* Return 1 when v is within the limit of the current picture-in-picture mode:
 *   mode 0: v == 0;  modes 1, 2, 5: v <= 1;  modes 3, 6: v <= 2;  modes 4, 7: v <= 3;
 *   any other mode: nothing passes.
 * The value 3 also passes whenever sys_config bit 21 is set. Otherwise returns 0. */
unsigned char sys_is_value_in_pip_limit(unsigned char v)
{
    unsigned char result = 0;

    switch (device_settings_pip_mode) {
    case 0:
        if (v == 0)
            result = 1;
        break;
    case 1:
    case 2:
    case 5:
        if (v <= 1)
            result = 1;
        break;
    case 3:
    case 6:
        if (v <= 2)
            result = 1;
        break;
    case 4:
    case 7:
        if (v <= 3)
            result = 1;
        break;
    }
    if (v == 3 && (sys_config & SYS_CONFIG_BIT21))
        result = 1;
    return result & 1;
}
