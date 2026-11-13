/* sys_is_pip_mode_active  (FUN_a013d670)
 *
 * Return whether a picture-in-picture mode is set.
 * Returns: 0 or 1
 * Name basis: derived - PIP mode byte at 0xA802E1A7 (set by SYSAPI_ConfigSystemPIPMode) is not 0; unused
 *
 * Matching notes
 * --------------
 * FUN_a013d670 (leon2m 0xa013d670-0xa013d684, 20 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Nothing in the image refers to this routine. Source form: 'return device_settings_pip_mode != 0;'.
 */
extern unsigned char device_settings_pip_mode;

/* Return 1 when the picture-in-picture mode is not 0, else 0. Nothing calls this routine. */
int sys_is_pip_mode_active(void)
{
    return device_settings_pip_mode != 0;
}
