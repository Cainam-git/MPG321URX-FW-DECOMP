/* sys_set_app_flag_bit3  (FUN_a0080bd8)
 *
 * Set bit 3 of the application flag byte 0xA802AF41 when v is 1, else clear it.
 *   value: 1 = set
 * Name basis: descriptive - code only; counterpart of sys_get_app_flag_bit3
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0080bd8 @ 0xa0080bd8 (-mcpu=v8 -O3 -g)
 * Sets bit 3 (0x08) of the byte at 0xA802AF41 if the low byte of the parameter equals 1, otherwise clears it. The
 * parameter is declared unsigned int and masked with 0xff in the compare; both arms use compound assignment.
 */
extern unsigned char app_flags; /* 0xa802af41 */

#define APP_FLAG_MUTE_ALL_SENT 8        /* app_flags bit 3; the event generator sys_app_generate_events sets and clears it */

/*
 * Set bit 3 of app_flags when the low byte of value is 1, otherwise clear it. The callers pass 1 or 0.
 * value is compared as (value & 0xff) == 1; both arms use compound assignment.
 */
void sys_set_app_flag_bit3(unsigned int value)
{
    if ((value & 0xff) == 1)
        app_flags |= APP_FLAG_MUTE_ALL_SENT;
    else
        app_flags &= ~APP_FLAG_MUTE_ALL_SENT;
}
