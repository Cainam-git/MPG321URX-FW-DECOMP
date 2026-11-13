/* reg_write_word_at  (FUN_a00f9994)
 *
 * Store a word at an address.
 * Name basis: derived - plain store; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f9994 @ 0xa00f9994, -mcpu=v8 -O2 -g.
 * Source form: the pointer is to volatile data (with a plain pointer the store moves into the delay slot).
 */

/* Store 'value' at 'address'. Nothing calls it. */
void reg_write_word_at(volatile unsigned int *address, unsigned int value)
{
    *address = value;
}
