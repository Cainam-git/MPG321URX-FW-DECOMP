/* input_find_slot_by_port_code  (FUN_a014e478)
 *
 * Return the index 0..7 of the input slot whose port code matches, or 8.
 * Returns: slot index, 8 when not found
 * Name basis: descriptive - compares the first byte of each slot's 0x16-byte record
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e478 @ 0xa014e478, flags -mcpu=v8 -O2 -g (the section default; no cflags entry).
 * Source form the exact build depends on: a do/while with an unsigned char counter and a separate int copy of it
 * that is used for the call and returned.
 */

extern int input_slot_get_port_code(int slot);

#define INPUT_SLOT_COUNT 8

/*
 * Return the number of the first input slot (0 to 7) whose port code is port_code, or 8 when no slot has it.
 *
 *   port_code  the port code to look for (compared as a byte)
 *
 * The port code of a slot is the first byte of its 0x16-byte port table row (input_slot_get_port_code).
 */
int input_find_slot_by_port_code(unsigned int port_code)
{
    unsigned char wanted;
    unsigned char counter;
    int slot;

    wanted = port_code & 0xff;
    counter = 0;
    slot = 0;
    do {
        if ((input_slot_get_port_code(slot) & 0xff) == wanted)
            break;
        counter++;
        slot = counter;
    } while (counter < INPUT_SLOT_COUNT);
    return slot;
}
