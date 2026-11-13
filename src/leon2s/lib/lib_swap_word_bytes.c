/* lib_swap_word_bytes  (FUN_a0061864)
 *
 * Reverse the byte order of each 32-bit word in a buffer.
 *   words: buffer
 *   length: length in bytes
 * Returns: pointer past the last word
 * Name basis: proven - in-place 32-bit byte swap of n / 4 words
 *
 * Matching notes
 * --------------
 * FUN_a0061864 (leon2s 0xa0061864), flags -mcpu=v8 -Os -g.
 * The temporaries keep the firmware's order of the mask and shift operations; the variables are declared and
 * reused as written.
 */
/*
 * Reverse the byte order of every 32-bit word of a buffer, in place.
 *
 *   words   first word of the buffer
 *   length  buffer length in bytes; only length / 4 whole words are swapped
 *
 * Returns the address after the last swapped word.
 */
unsigned int *lib_swap_word_bytes(unsigned int *words, unsigned int length)
{
    unsigned int count = length >> 2;
    unsigned int word, tmp1, tmp2, tmp3, tmp4, tmp5;

    while (count != 0) {
        word = *words;
        tmp1 = word & 0xff0000;         /* byte 2 */
        tmp2 = word >> 24;              /* byte 3 goes to the bottom */
        tmp3 = word & 0xff00;           /* byte 1 */
        tmp1 = tmp1 >> 8;               /* byte 2 moves to byte 1 */
        tmp3 = tmp3 << 8;               /* byte 1 moves to byte 2 */
        tmp4 = tmp2 | tmp1;
        tmp4 = tmp4 | tmp3;
        tmp5 = word << 24;              /* byte 0 goes to the top */
        word = tmp4 | tmp5;
        *words = word;
        words++;
        count--;
    }

    return words;
}
