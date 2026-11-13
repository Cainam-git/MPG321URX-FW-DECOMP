/* audio_unit_assign_unit  (FUN_a014ebf8)
 *
 * Give an id a free unit, or take over the oldest one, and update the order queue.
 * Name basis: derived - fills the unit fields and the queue; prints the IsAnyACRAvailable result
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014ebf8 (leon2m 0xa014ebf8-0xa014f208, 1552 bytes), flags -mcpu=v8 -O3 -g.
 * The helpers are same-file copies of audio_unit_queue_append, audio_unit_queue_rotate, audio_unit_find_unit, IsAnyACRAvailable and audio_unit_send_owner_slots, which
 * GCC inlines at -O3.
 * Source form: the first-free-place insert (queue_append) of the source 4 / source 6 arms is called with the
 * variable source, the rotate (queue_rotate) and the final field store with the constants 4 and 6; the
 * "no free unit" case (unit > 3) is the first arm of each test.
 */
extern unsigned short audio_unit_owners;
extern unsigned short audio_unit_order;
extern unsigned char audio_slot_owners[];
extern int dbg_printf();
extern void ipc_route_audio_source(unsigned char, unsigned char, unsigned char, unsigned char);

#define NO_UNIT         4       /* "no unit": result of find_unit and first_free_acr_unit */
#define SOURCE_UNIT_0   4       /* the source that always sits in unit 0 */
#define SOURCE_UNIT_2   6       /* the source that always sits in unit 2 */

/* Put a source into the first free place of the order queue (audio_unit_order, four 4-bit places). */
static void queue_append(unsigned char source)
{
    unsigned char i;
    for (i = 0; i < 4; i++)
        if (((audio_unit_order >> (i * 4)) & 0xf) == 0) {
            audio_unit_order |= source << (i * 4);
            break;
        }
}

/* Push a source in at the back of the order queue; returns the source that falls out at the front. */
static unsigned char queue_rotate(unsigned char source)
{
    unsigned short old_queue = audio_unit_order;

    audio_unit_order = (old_queue >> 4) | (source << 12);
    return old_queue & 0xf;
}

/* Index (0..3) of the unit that holds the source, or NO_UNIT when none does. */
static unsigned char find_unit(unsigned char source)
{
    unsigned char i;

    for (i = 0; i < 4; i++)
        if (((audio_unit_owners >> (i * 4)) & 0xf) == source)
            break;
    return i;
}

/* First empty unit of 1 and 3 (the firmware's "ACR" units), or NO_UNIT when both are taken. */
static unsigned char first_free_acr_unit(void)
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

static inline unsigned char slot_owner(unsigned char slot) { return audio_slot_owners[slot]; }

/* Tell the input processor to route the source to the unit, for every output slot the source owns. */
static void route_owned_slots(unsigned char source, unsigned char unit)
{
    unsigned char slot;
    for (slot = 0; slot <= 8; slot++)
        if (source == slot_owner(slot))
            ipc_route_audio_source(source, slot, unit, 1);
}

/*
 * Give a source one of the four audio units. audio_unit_owners holds the source of each unit in a 4-bit
 * place (unit n = bits 4n..4n+3, 0 = empty); audio_unit_order lists the sources in the order they were
 * assigned, oldest in the lowest place.
 *
 *   source  the id to place. Sources 4 and 6 always take unit 0 and unit 2; every other source takes
 *           a free one of units 1 and 3, or, when both are taken, the unit of the oldest source.
 *
 * Source 4 or 6: when its unit holds another source, that source is moved first. It goes to a free
 * unit of 1 and 3, or, when neither is free, it takes the unit of the oldest source in the queue (that
 * source falls out of the queue). The moved source's output slots are re-routed to its new unit. In both
 * cases source 4 or 6 is pushed on the queue, then its own unit is set to it.
 * Any other source: it goes into the free unit, or into the unit of the oldest source (that source loses
 * its unit and is not notified).
 *
 * Called by audio_unit_request_unit.
 */
void audio_unit_assign_unit(unsigned char source)
{
    unsigned char displaced, unit;

    if (source == SOURCE_UNIT_0) {
        displaced = audio_unit_owners & 0xf;
        if (displaced != 0) {
            unit = first_free_acr_unit();
            if (unit > 3) {
                unit = find_unit(queue_rotate(SOURCE_UNIT_0));
                audio_unit_owners = (audio_unit_owners & ~(0xf << (unit * 4))) | (displaced << (unit * 4));
                route_owned_slots(displaced, unit);
            } else {
                audio_unit_owners = (audio_unit_owners & ~(0xf << (unit * 4))) | (displaced << (unit * 4));
                route_owned_slots(displaced, unit);
                queue_append(source);
            }
        }
        audio_unit_owners = (audio_unit_owners & ~0xf) | 4;
    } else if (source == SOURCE_UNIT_2) {
        displaced = (audio_unit_owners >> 8) & 0xf;
        if (displaced != 0) {
            unit = first_free_acr_unit();
            if (unit > 3) {
                unit = find_unit(queue_rotate(SOURCE_UNIT_2));
                audio_unit_owners = (audio_unit_owners & ~(0xf << (unit * 4))) | (displaced << (unit * 4));
                route_owned_slots(displaced, unit);
            } else {
                audio_unit_owners = (audio_unit_owners & ~(0xf << (unit * 4))) | (displaced << (unit * 4));
                route_owned_slots(displaced, unit);
                queue_append(source);
            }
        }
        audio_unit_owners = (audio_unit_owners & ~0xf00) | 0x600;
    } else {
        unit = first_free_acr_unit();
        if (unit > 3) {
            unit = find_unit(queue_rotate(source));
            audio_unit_owners = (audio_unit_owners & ~(0xf << (unit * 4))) | (source << (unit * 4));
        } else {
            audio_unit_owners = (audio_unit_owners & ~(0xf << (unit * 4))) | (source << (unit * 4));
            queue_append(source);
        }
    }
}
