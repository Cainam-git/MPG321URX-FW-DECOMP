/* osd_api_is_enabled  (FUN_a0146dfc)
 *
 * Return whether a menu layer is switched on.
 * Returns: 0 or 1
 * Name basis: derived - forwards to osd_is_enabled
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146dfc @ 0xa0146dfc-0xa0146e24 (10 words), flags -mcpu=v8 -O2 -g.
 * Source form: the result is a 0/1 flag, not the callee's value. The firmware sets 0 or 1 on each path and masks
 * with 'and 1' at the join, so the flag is an unsigned char and the routine returns 'flag & 1' (same form as
 * input_user_is_active_port_in_range). A _Bool gives other code.
 */
extern unsigned char osd_is_enabled(unsigned char layer);

/* Return 1 when the menu layer (0 or 1) is switched on, otherwise 0. */
unsigned char osd_api_is_enabled(unsigned char layer)
{
    unsigned char enabled = 0;

    if (osd_is_enabled(layer) != 0)
        enabled = 1;
    return enabled & 1;
}
