/* audio_unit_queue_append  (FUN_a014ea54)
 *
 * Put an id into the first free place of the order queue.
 * Name basis: derived - first zero 4-bit field of the halfword at 0xA802CC82; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014ea54 @ 0xa014ea54 (84 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: the global is read and updated inside the loop; GCC hoists the load
 * and sinks the store (written back on both exits).
 */
extern unsigned short audio_unit_order;

/*
 * Put an id into the first empty field (value 0) of the order list. audio_unit_order holds four 4-bit ids,
 * the first one in the lowest bits. Nothing is stored when no field is 0. Nothing calls it.
 */
void audio_unit_queue_append(unsigned char id)
{
    unsigned char i;
    for (i = 0; i < 4; i++)
        if (((audio_unit_order >> (i * 4)) & 0xf) == 0) {
            audio_unit_order |= id << (i * 4);
            break;
        }
}
