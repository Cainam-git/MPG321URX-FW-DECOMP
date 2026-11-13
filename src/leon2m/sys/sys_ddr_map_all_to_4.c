/* sys_ddr_map_all_to_4  (FUN_a00e0e28)
 *
 * Return 4 for the value 0xFF, other values unchanged.
 * Returns: mapped value
 * Name basis: descriptive - 0xFF means 'all'; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0e28 @ 0xa00e0e28-0xa00e0e44 (7 words, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: one compare and a return of the argument.
 */
#define ALL_UNITS 0xff          /* the script's "every unit" selector */
#define ALL_UNITS_ENTRY 4       /* its entry in sys_ddr_script_unit_ranges */

/*
 * Turn the selector 0xff into 4 and leave any other value unchanged. The script interpreter
 * (sys_ddr_run_script) uses the same rule inline: for the commands that loop over units, 0xff selects entry 4
 * of sys_ddr_script_unit_ranges. Nothing in the image calls this routine.
 */
unsigned int sys_ddr_map_all_to_4(unsigned int unit)
{
    if (unit == ALL_UNITS)
        return ALL_UNITS_ENTRY;
    return unit;
}
