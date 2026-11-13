/* ipc_pack_bytes_to_words  (FUN_a0132c54)
 *
 * Pack a byte buffer into big-endian words.
 * Name basis: derived - groups of four bytes; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0132c54 @ 0xa0132c54, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the word is stored after each of its four bytes (four stores to the
 * same place); the group counter is a full word with an 8-bit copy for the loop test; the buffers are passed as
 * ints.
 */

/*
 * Pack byte_count bytes from src into big-endian words at dst: dst word i = src bytes 4i..4i+3, first byte in the
 * top bits. The number of words is (byte_count + 3) / 4 taken as 8 bits, so a last partial group still reads four
 * bytes.
 *
 *   src         byte buffer (address)
 *   dst         word buffer (address)
 *   byte_count  number of bytes
 * Returns src.
 *
 * No direct call to this routine was found in FW.021.
 */
unsigned int ipc_pack_bytes_to_words(int src,int dst, unsigned short byte_count)

{
  unsigned char first_byte;
  int word_value;
  unsigned char word_count;
  unsigned int words_done;
  int offset;
  int group;
  unsigned char word_index;

  word_count = (byte_count & 0xffff) + 3 >> 2 & 0xff;
  words_done = 0;
  if (word_count != 0) {
    word_index = 0;
    do {
      offset = word_index * 4;
      first_byte = *(unsigned char *)(src + offset);
      *(unsigned int *)(dst + offset) = (unsigned int)first_byte;
      group = offset + src;
      word_value = (unsigned int)first_byte * 0x100 + (unsigned int)*(unsigned char *)(group + 1);
      *(int *)(dst + offset) = word_value;
      word_value = word_value * 0x100 + (unsigned int)*(unsigned char *)(group + 2);
      *(int *)(dst + offset) = word_value;
      words_done = words_done + 1;
      word_index = words_done & 0xff;
      *(unsigned int *)(dst + offset) = word_value * 0x100 + (unsigned int)*(unsigned char *)(group + 3);
    } while (word_index < word_count);
  }
  return src;
}
