/* reg_write_word_at_alt  (FUN_a00e2248)
 *
 * Store a word at an address.
 * Name basis: derived - tail call to the plain store; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e2248 @ 0xa00e2248, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the call is the last statement, so the compiler makes it a tail call.
 */
extern void reg_write32_copy(unsigned int, unsigned int);

/* Store 'value' at 'address' by calling reg_write32_copy. Nothing calls it. */
void reg_write_word_at_alt(unsigned int address, unsigned int value)
{
    reg_write32_copy(address, value);
}
