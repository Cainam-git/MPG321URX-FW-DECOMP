/* input_is_port_used  (FUN_a0080320)
 *
 * Return 1 when port c (0..3) is in use for the current port layout byte.
 *   port: port number 0..3
 * Returns: 1 = used
 * Note: Port 0 always; 1 when 0xA802D2AF != 0; 2 when it is 4..7; 3 when it is 7.
 * Name basis: derived - same rule is the 'used port' test of the event generator sys_app_generate_events
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0080320 @ 0xa0080320, flags -mcpu=v8 -O3 -g.
 * Source form: an if / else-if chain on the port number with one result variable returned as 'used & 1'.
 */

extern unsigned char user_settings_pip_pbp_mode;

/*
 * Tell whether port 0..3 takes part in the present picture layout. The layout is the PIP/PBP mode byte
 * of the user settings (user_settings_pip_pbp_mode):
 *   port 0  always
 *   port 1  in every mode except 0
 *   port 2  in modes 4 to 7
 *   port 3  in mode 7
 * Any other port number is not used.
 */
unsigned char input_is_port_used(unsigned char port)
{
    unsigned char used = 0;

    if (port == 0)
        used = 1;
    else if (port == 1) {
        if (user_settings_pip_pbp_mode != 0)
            used = 1;
    } else if (port == 2) {
        if ((unsigned char)(user_settings_pip_pbp_mode - 4) <= 3)
            used = 1;
    } else if (port == 3) {
        if (user_settings_pip_pbp_mode == 7)
            used = 1;
    }
    return used & 1;
}
