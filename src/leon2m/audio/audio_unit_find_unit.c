/* audio_unit_find_unit  (FUN_a014ead0)
 *
 * Return which of the four units an id holds, or 4 when it holds none.
 * Returns: unit index or 4
 * Name basis: derived - searches the four 4-bit fields of the halfword at 0xA802CC80; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014ead0 @ 0xa014ead0 (68 bytes, leaf), section default flags -mcpu=v8 -O2 -g.
 * Source form the exact build depends on: the search loop breaks out and returns the counter itself.
 */
extern unsigned short audio_unit_owners;

/*
 * Return the number (0..3) of the first audio unit whose owner is "owner", or 4 when no unit has it.
 * audio_unit_owners holds the owner of each unit as a 4-bit field, unit 0 in the lowest bits. Nothing calls it.
 */
unsigned char audio_unit_find_unit(unsigned char owner)
{
    unsigned char unit;

    for (unit = 0; unit < 4; unit++)
        if (((audio_unit_owners >> (unit * 4)) & 0xf) == owner)
            break;
    return unit;
}
