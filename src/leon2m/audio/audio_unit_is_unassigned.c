/* audio_unit_is_unassigned  (FUN_a014f32c)
 *
 * Return whether an id holds no unit.
 * Returns: 1 when unassigned
 * Name basis: derived - 1 when no 4-bit field of the halfword at 0xA802CC80 equals the id; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014f32c, flags -mcpu=v8 -O2 -g.
 * Source form: the limit 4 is kept in a local (limit) for the final compare, so GCC emits 'cmp 4; subx'
 * (unit_index >= limit) instead of folding it to unit_index > 3.
 */
/* The four 4-bit fields of audio_unit_owners (lowest first) hold the sound source assigned to each audio unit. */
#define AUDIO_UNIT_COUNT 4
extern unsigned short audio_unit_owners;

/*
 * Tell whether a sound source holds none of the four audio units.
 *
 *   source  the sound source id to look for
 *
 * Returns 1 when no unit field of audio_unit_owners equals the id, 0 when one does.
 */
int audio_unit_is_unassigned(unsigned char source)
{
    unsigned char unit_index, limit = AUDIO_UNIT_COUNT;
    for (unit_index = 0; unit_index < AUDIO_UNIT_COUNT; unit_index++)
        if (((audio_unit_owners >> (unit_index * 4)) & 0xf) == source)
            break;
    return unit_index >= limit;
}
