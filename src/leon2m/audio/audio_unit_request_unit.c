/* audio_unit_request_unit  (FUN_a014f3d8)
 *
 * Make sure an id has a unit, assigning one if needed, and announce the assignment.
 * Name basis: derived - releases unused units when none is free, assigns, then sends command 0x92
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014f3d8 @ 0xa014f3d8-0xa014f620 (146 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: IsAnyACRAvailable and audio_unit_release_unused_units are the matched same-file functions, defined
 * here and inlined by GCC (the latter with its two static helpers, the first one named slots_owned_by here because
 * this file also has the unit-search helper find_unit of audio_unit_assign_unit); flags as
 * audio_unit_release_unused_units (-msoft-float).
 */
extern unsigned short audio_unit_owners;
extern unsigned short audio_unit_order;
extern unsigned char audio_slot_owners[9];
extern int dbg_printf();
extern void audio_unit_assign_unit(unsigned char c);
extern void ipc_route_audio_source(unsigned char, unsigned char, unsigned char, unsigned char);

#define NO_UNIT 4       /* "no unit": result of find_unit and IsAnyACRAvailable */

/* Index (0..3) of the unit that holds the source, or NO_UNIT when none does. */
static unsigned char find_unit(unsigned char source)
{
    unsigned char i;

    for (i = 0; i < 4; i++)
        if (((audio_unit_owners >> (i * 4)) & 0xf) == source)
            break;
    return i;
}

/* Bit mask of the output slots (bit n = slot n, slots 0..8) whose owner is the source. */
static unsigned short slots_owned_by(unsigned char source)
{
    unsigned char slot, owner;
    unsigned short mask = 0;

    for (slot = 0; slot < 9; slot++) {
        owner = audio_slot_owners[slot];
        if (source == owner)
            mask |= 1 << slot;
    }
    return mask;
}

/* Take the source out of the order queue; the places behind it move forward. */
static void queue_remove(unsigned char source)
{
    unsigned char place;

    for (place = 0; place < 4; place++) {
        if (((audio_unit_order >> (place * 4)) & 0xf) == source) {
            audio_unit_order = ((int)((unsigned int)audio_unit_order << (16 - place * 4)) >> (16 - place * 4)) |
                           ((audio_unit_order >> (place * 4 + 4)) << (place * 4));
            break;
        }
    }
}

/*
 * Empty every unit whose source no longer owns any of the nine output slots, and remove that source
 * from the order queue.
 */
void audio_unit_release_unused_units(void)
{
    unsigned char unit;
    unsigned char source;

    for (unit = 0; unit < 4; unit++) {
        source = (audio_unit_owners >> (unit * 4)) & 0xf;
        if (slots_owned_by(source) == 0) {
            audio_unit_owners &= ~(0xf << (unit * 4));
            queue_remove(source);
        }
    }
}

/* First empty unit of 1 and 3 (the firmware's "ACR" units), or NO_UNIT when both are taken. */
unsigned char IsAnyACRAvailable(void)
{
    unsigned char acr_units[2] = {1, 3};
    unsigned char i, unit = NO_UNIT;

    for (i = 0; i < 2; i++)
        if (((audio_unit_owners >> (acr_units[i] * 4)) & 0xf) == 0)
            break;
    if (i < 2)
        unit = acr_units[i];
    dbg_printf("\033[0;33mIsAnyACRAvailable %d\r\n\033[m", unit);
    return unit;
}

/*
 * Route a source to an output slot through an audio unit, giving the source a unit first when it has none.
 *
 *   source  the id of the audio source
 *   slot    the output slot, passed on as the output of the routing command
 *
 * When no unit holds the source: if units 1 and 3 are both taken, the units whose source owns no output
 * slot are emptied first; then audio_unit_assign_unit places the source. In every case the routing
 * command (mailbox command 0x92) is sent with the unit that now holds the source and enable 1.
 * Called by audio_api_route_source.
 */
void audio_unit_request_unit(unsigned char source, unsigned char slot)
{
    if (find_unit(source) >= 4) {
        if (IsAnyACRAvailable() > 3)
            audio_unit_release_unused_units();
        audio_unit_assign_unit(source);
    }
    ipc_route_audio_source(source, slot, find_unit(source), 1);
}
