/* audio_unit_get_slot_owner  (FUN_a014e960)
 *
 * Return the owner stored in one of the nine slots.
 * Returns: owner id
 * Name basis: descriptive - getter for the 9-byte table at 0xA802A480; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e960 @ 0xa014e960 (20 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form the exact build depends on: an unsigned char index into an extern byte array.
 */
extern unsigned char audio_slot_owners[];

/*
 * Return the source that owns audio output slot "slot" (0..8; the index is not checked).
 * Nothing calls it.
 */
unsigned char audio_unit_get_slot_owner(unsigned char slot)
{
    return audio_slot_owners[slot];
}
