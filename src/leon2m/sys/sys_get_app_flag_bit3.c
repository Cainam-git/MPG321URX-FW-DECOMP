/* sys_get_app_flag_bit3  (FUN_a0080bc0)
 *
 * Return bit 3 of the application flag byte 0xA802AF41.
 * Returns: 0 or 1
 * Note: Nothing calls it directly.
 * Name basis: descriptive - code only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0080bc0 @ 0xa0080bc0-0xa0080bd8 (6 words).
 * Returns 1 when bit 3 of byte 0xa802af41 is set and 0 otherwise (the comparison result is formed with
 * cmp/addx, without a branch). A leaf routine without a register window.
 */
extern unsigned char app_flags;

#define APP_FLAG_MUTE_ALL_SENT 8        /* app_flags bit 3; the event generator sys_app_generate_events sets and clears it */

/* Return bit 3 of app_flags (1 or 0). */
int sys_get_app_flag_bit3(void)
{
    if (app_flags & APP_FLAG_MUTE_ALL_SENT)
        return 1;
    return 0;
}
