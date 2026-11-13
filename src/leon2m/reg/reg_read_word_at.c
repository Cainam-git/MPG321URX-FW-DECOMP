/* reg_read_word_at  (FUN_a00f9988)
 *
 * Return the word at an address.
 * Returns: word
 * Name basis: derived - plain load; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f9988 @ 0xa00f9988, -mcpu=v8 -O2 -g.
 * Source form: the pointer is to volatile data (with a plain pointer the load moves into the delay slot).
 */

/* Return the word at 'address'. Nothing calls it. */
unsigned int reg_read_word_at(volatile unsigned int *address)
{
    return *address;
}
