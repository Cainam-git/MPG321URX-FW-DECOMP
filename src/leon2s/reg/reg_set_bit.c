/* reg_set_bit  (FUN_a00a73ac)
 *
 * Set bit n of a word array (register block).
 *   bit: bit number
 *   words: word array
 * Name basis: proven - word n >> 5, bit n & 31; used on every receiver register block
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a73ac @ 0xa00a73ac (-mcpu=v8 -Os -g).
 * Source form: the word is read and written through volatile accesses; the shift count is cast to a byte.
 */
/*
 * Set bit "bit" of an array of 32-bit words: word bit / 32, bit position bit % 32.
 *   bit:   bit number
 *   words: address of the word array (a register block)
 * The clear and test twins are reg_clear_bit and reg_test_bit.
 */
void reg_set_bit(unsigned int bit, int words)

{
  int byte_offset;
  
  byte_offset = (bit >> 5) * 4;
  *(volatile unsigned int *)(words + byte_offset) = *(volatile unsigned int *)(words + byte_offset) | 1 << ((unsigned char)bit & 0x1f);
  return;
}
