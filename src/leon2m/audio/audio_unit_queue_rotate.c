/* audio_unit_queue_rotate  (FUN_a014eaa8)
 *
 * Push an id at the back of the order queue and return the id that drops out at the front.
 * Returns: oldest id
 * Name basis: derived - shifts the queue by one 4-bit field; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014eaa8 @ 0xa014eaa8 (40 bytes, leaf), section default flags -mcpu=v8 -O2 -g.
 * Source form the exact build depends on: the old value is read once into a local unsigned short.
 */
extern unsigned short audio_unit_order;

/*
 * Shift the order list by one field: the first id (lowest 4 bits of audio_unit_order) drops out and is
 * returned, the other ids move down, and "id" becomes the last field (the top 4 bits). Nothing calls it.
 */
unsigned char audio_unit_queue_rotate(unsigned char id)
{
    unsigned short old_order = audio_unit_order;

    audio_unit_order = (old_order >> 4) | (id << 12);
    return old_order & 0xf;
}
