/* osd_is_third_level_state  (FUN_a00a8ae0)
 *
 * Return 1 when a menu state is one of the states with a third-level list.
 *   state: menu state
 * Returns: 1 or 0
 * Note: Same state sets as the test at the end of osd_clear_choice_column.
 * Name basis: descriptive - value sets 0x3F..0x40, 0x43, 0xED..0xEF, 0x44..0x45, 0xE7..0xEC, ...
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a8ae0 @ 0xa00a8ae0, flags -mcpu=v8 -O3 -g. No direct callers (reached through a table).
 * Source form: one if statement per test, each returning 1, in the order of the code below; 67 / 237-239 and
 * 111 / 204 share one if (the compiler evaluates each pair without a branch between them); the ranges are written
 * "state >= a && state <= b".
 */
/* Return 1 when the menu state is one of the values listed below, else 0
 * (the tests run in this order). In hex the values are 0x3F-0x40, 0x43,
 * 0xED-0xEF, 0x44-0x45, 0xE7-0xEC, 0x6F, 0xCC, 0x7A-0x7C, 0xCD-0xCF, 0xD0-0xD3,
 * 0xD8-0xDC, 0x82-0x83 and 0xD4-0xD7. They belong to the Smart Crosshair
 * Icon / Color rows and lists (0x3F, 0x40, 0x43, 0xED..), the Optix Scope Size
 * and Ratio rows and lists (0x44, 0x45, 0xE7..0xEC), the last entry of the
 * Color Temperature list (0x6C + 3), the blue gain editor (0xCC), the first
 * three PIP list rows (0x7A..0x7C), the PIP size, source and location lists
 * (0xCD.., 0xD0.., 0xD8..), the two PBP source rows (0x82, 0x83) and the PBP
 * source list (0xD4..). */
unsigned char osd_is_third_level_state(int state)
{
    if (state >= 63 && state <= 64)
        return 1;
    if (state == 67 || (state >= 237 && state <= 239))
        return 1;
    if (state >= 68 && state <= 69)
        return 1;
    if (state >= 231 && state <= 236)
        return 1;
    if (state == 111 || state == 204)
        return 1;
    if (state >= 122 && state <= 124)
        return 1;
    if (state >= 205 && state <= 207)
        return 1;
    if (state >= 208 && state <= 211)
        return 1;
    if (state >= 216 && state <= 220)
        return 1;
    if (state >= 130 && state <= 131)
        return 1;
    if (state >= 212 && state <= 215)
        return 1;
    return 0;
}
