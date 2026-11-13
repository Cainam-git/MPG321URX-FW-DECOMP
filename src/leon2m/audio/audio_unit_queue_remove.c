/* audio_unit_queue_remove  (FUN_a014e9d8)
 *
 * Remove an id from the four-entry order queue and close the gap.
 * Name basis: derived - queue of four 4-bit ids in the halfword at 0xA802CC82; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e9d8 @ 0xa014e9d8, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: every access goes to audio_unit_order itself inside the loop; the loop
 * optimiser keeps it in a register (loaded before the loop, stored on both exits). The shifts are int
 * arithmetic with arithmetic right shifts.
 */
extern unsigned short audio_unit_order;

/*
 * Take an id out of the order list and close the gap. audio_unit_order holds four 4-bit ids, the first one in
 * the lowest bits. The first field equal to "id" is removed: the fields above it move down by 4 bits and the
 * fields below it stay. The list is unchanged when no field equals "id". Nothing calls it.
 */
void audio_unit_queue_remove(unsigned char id)
{
    unsigned char i;
    int shift;

    for (i = 0; i < 4; i++) {
        shift = i * 4;
        if (((audio_unit_order >> shift) & 0xf) == id) {
            audio_unit_order = ((audio_unit_order << (16 - shift)) >> (16 - shift)) | ((audio_unit_order >> (shift + 4)) << shift);
            break;
        }
    }
}
