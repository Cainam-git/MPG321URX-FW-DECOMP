/* audio_unit_get_owner_slot_mask  (FUN_a014e974)
 *
 * Return a 9-bit mask of the slots that belong to an owner.
 * Returns: slot mask
 * Name basis: descriptive - compares each of the nine table bytes with the argument; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e974 @ 0xa014e974, flags -mcpu=v8 -O2 -g.
 * Source form the exact build depends on: the table byte is copied into a separate unsigned char local and
 * compared as 'owner == slot_owner'; the direct forms 'audio_slot_owners[i] == owner' and
 * 'owner == audio_slot_owners[i]' give the compare operands in the other order. The counter is an unsigned
 * char (the compiler keeps it with an increment and a mask of 0xff); the result is an unsigned short.
 */
extern unsigned char audio_slot_owners[];

/*
 * Return a mask of the audio output slots that the source "owner" owns: bit n is set when slot n (0..8) is
 * owned by it. Nothing calls it.
 */
unsigned short audio_unit_get_owner_slot_mask(unsigned char owner)
{
    unsigned short slot_mask = 0;
    unsigned char slot;
    for (slot = 0; slot <= 8; slot++) {
        unsigned char slot_owner = audio_slot_owners[slot];
        if (owner == slot_owner)
            slot_mask |= 1 << slot;
    }
    return slot_mask;
}
