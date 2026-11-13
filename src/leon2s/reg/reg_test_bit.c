/* reg_test_bit  (FUN_a00a7408)
 *
 * Return bit n of a word array (register block).
 *   bit: bit number
 *   words: word array
 * Returns: bit value (masked)
 * Name basis: proven - word n >> 5, bit n & 31
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a7408 @ 0xa00a7408 (-mcpu=v8 -Os -g).
 * Source form: the shift count is cast to a byte.
 */
/*
 * Return bit "bit" (0 or 1) of an array of 32-bit words: word bit / 32, bit position bit % 32.
 * Test twin of reg_set_bit and reg_clear_bit.
 *   bit:   bit number
 *   words: address of the word array (a register block)
 */
unsigned int reg_test_bit(unsigned int bit, int words)

{
  return *(unsigned int *)(words + (bit >> 5) * 4) >> ((unsigned char)bit & 0x1f) & 1;
}
