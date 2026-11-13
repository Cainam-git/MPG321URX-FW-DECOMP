/* sys_user_apply_output_mode  (FUN_a00d5da4)
 *
 * Apply the output mode setting.
 * Name basis: descriptive - sys_api_set_output_mode(1, 2 or 0 by settings byte +5); unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5da4 @ 0xa00d5da4-0xa00d5e0c (26 words), flags -mcpu=v8 -O3 -g.
 * Source form: the mode is chosen in a switch into a byte and masked with 3 at the call; the call to
 * sys_api_set_output_mode is a tail call.
 */
extern unsigned char sys_is_logo_hold(void);
extern void gpio_set_aux_bit0_low(void);
extern void sys_api_set_output_mode(unsigned char mode);
extern unsigned char user_settings_output_mode;

/*
 * Pass the output mode setting (settings byte +5) to sys_api_set_output_mode: 1 and 2 are passed on, any
 * other value becomes 0. When sys_is_logo_hold() returns 0, gpio_set_aux_bit0_low() is called first.
 * Nothing calls this routine.
 */
void sys_user_apply_output_mode(void)
{
    unsigned char mode;

    if (!sys_is_logo_hold())
        gpio_set_aux_bit0_low();
    switch (user_settings_output_mode) {
    case 1: mode = 1; break;
    case 2: mode = 2; break;
    default: mode = 0; break;
    }
    sys_api_set_output_mode(mode & 3);
}
