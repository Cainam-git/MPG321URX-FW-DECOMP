/* reg_read_byte_in_word  (FUN_a002c284)
 *
 * Return byte number (a & 3), counted from the low end, of the aligned word that holds address a.
 *   addr: address; bits 0..1 pick the byte number from the low end of its aligned word
 * Returns: (word at a & ~3) >> ((a & 3) * 8), low byte
 * Note: In this big-endian program that is the byte at (a & ~3) + 3 - (a & 3), not the byte at a; nothing
 *   calls it.
 * Name basis: descriptive - code only; no reference in the image
 *
 * Matching notes
 * --------------
 * FUN_a002c284 (leon2m 0xa002c284-0xa002c2a0, 28 bytes, leaf), flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the word is read into a local before the shift.
 */

/*
 * Read the aligned word that holds 'addr' and return its byte number (addr & 3), counted from the least
 * significant end: bits (addr & 3) * 8 upwards. Nothing in the image refers to it (no call, branch, sethi/or
 * constant or address word).
 */
unsigned char reg_read_byte_in_word(unsigned int addr)
{
    unsigned int word = *(unsigned int *)(addr & ~3u);

    return word >> ((addr & 3) * 8);
}
