/* sys_get_logo_hold  (FUN_a008453c)
 *
 * Return bit 0 of 0xA802AF41 (logo shown, events held)
 * Returns: 0 or 1
 * Note: Same as sys_is_logo_hold; nothing calls this copy.
 * Name basis: derived - same flag as sys_is_logo_hold
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008453c @ 0xa008453c, flags -mcpu=v8 -O2 -g (section default). Leaf.
 * Returns app_flags & 1 as an unsigned char (ldub; and 1 in the retl delay slot). Nothing in the image refers to it: no
 * call, branch, sethi/or constant or address word.
 */
extern unsigned char app_flags;

#define APP_FLAG_LOGO_HOLD 0x01         /* app_flags bit 0 */

/* Return bit 0 of app_flags (logo shown, events held). Same as sys_is_logo_hold; nothing calls this copy. */
unsigned char sys_get_logo_hold(void)
{
    return app_flags & APP_FLAG_LOGO_HOLD;
}
