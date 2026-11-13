/* audio_unit_release_unused_units  (FUN_a014f208)
 *
 * Free every unit whose id no longer appears in the slot table.
 * Name basis: derived - clears unit fields without a matching table byte and removes them from the queue
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014f208 @ 0xa014f208, flags -mcpu=v8 -O3 -g -msoft-float (the flag keeps the 0xf mask constant out
 * of the loop preheader, as in the firmware).
 * Source form the exact build depends on: the owner search and the order-list removal are static helpers,
 * inlined; the removal works on audio_unit_order itself (GCC keeps it in a register and stores it at both loop
 * exits; the first term keeps the whole halfword); the table byte is copied into a local before the compare
 * 'owner == slot_owner' (operand order of the compare).
 */
extern unsigned short audio_unit_owners;
extern unsigned short audio_unit_order;
extern unsigned char audio_slot_owners[9];

/* Mask of the audio output slots (0..8) whose owner is "owner"; bit n is slot n. */
static unsigned short slots_owned_by(unsigned char owner)
{
    unsigned char slot, slot_owner;
    unsigned short slot_mask = 0;

    for (slot = 0; slot < 9; slot++) {
        slot_owner = audio_slot_owners[slot];
        if (owner == slot_owner)
            slot_mask |= 1 << slot;
    }
    return slot_mask;
}

/* Take "owner" out of the order list audio_unit_order (four 4-bit ids): the first field that holds it goes. */
static void remove_from_order(unsigned char owner)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        if (((audio_unit_order >> (i * 4)) & 0xf) == owner) {
            audio_unit_order = ((int)((unsigned int)audio_unit_order << (16 - i * 4)) >> (16 - i * 4)) |
                           ((audio_unit_order >> (i * 4 + 4)) << (i * 4));
            break;
        }
    }
}

/*
 * Free every audio unit whose owner no longer owns an audio output slot: the unit's 4-bit field in
 * audio_unit_owners is cleared and the owner is taken out of the order list audio_unit_order.
 * No call to this address was found in the image.
 */
void audio_unit_release_unused_units(void)
{
    unsigned char unit;
    unsigned char owner;

    for (unit = 0; unit < 4; unit++) {
        owner = (audio_unit_owners >> (unit * 4)) & 0xf;
        if (slots_owned_by(owner) == 0) {
            audio_unit_owners &= ~(0xf << (unit * 4));
            remove_from_order(owner);
        }
    }
}
