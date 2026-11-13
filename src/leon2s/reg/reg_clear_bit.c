/* reg_clear_bit  (FUN_a00a73d4)
 *
 * Clear bit n of a word array (register block).
 *   bit: bit number
 *   words: word array
 * Name basis: proven - word n >> 5, bit n & 31
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a73d4 @ 0xa00a73d4-0xa00a7408 (13 words), flags -mcpu=v8 -Os -g.
 * Source form: the mask goes through a stack slot (st/ld in a 112-byte leaf frame), so the mask local is
 * volatile.
 */
/*
 * Clear bit "bit" of an array of 32-bit words: word bit / 32, bit position bit % 32. Twin of reg_set_bit.
 *   bit:   bit number
 *   words: the word array (a register block)
 */
void reg_clear_bit(unsigned int bit, volatile unsigned int *words)
{
    volatile unsigned int mask = 1 << (bit & 0x1f);

    words[bit >> 5] &= ~mask;
}
