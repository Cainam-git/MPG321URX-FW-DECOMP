/* pq_is_fga_bit4_set  (FUN_a012f134)
 *
 * Return bit 4 of a value as 0 or 1.
 * Returns: 0 or 1
 * Name basis: descriptive - tested on a system configuration byte before FGA data is used
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012f134 @ 0xa012f134, flags -mcpu=v8 -O2 -g.
 * Source form: an unsigned char result set to 0, then to 1 by an if, and returned as result & 1 (the firmware
 * keeps the and 1 in the return delay slot).
 */

#define FGA_IN_USE_BIT 0x10     /* bit 4 of sys_config gamma_selection: FGA data in use */

/*
 * Return 1 when bit 4 of 'gamma_selection' is set, else 0.
 * Callers: pq_apply_picture_mode and pq_load_fga_color_entries, each with sys_config gamma_selection
 * (stSysConfig +0x18), before they use stored FGA data.
 */
unsigned char pq_is_fga_bit4_set(unsigned int gamma_selection)
{
    unsigned char result;

    result = 0;
    if (gamma_selection & FGA_IN_USE_BIT)
        result = 1;
    return result & 1;
}
