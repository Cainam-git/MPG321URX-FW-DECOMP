/* reg_write_byte_in_word  (FUN_a002c2a0)
 *
 * Replace byte number (a & 3), counted from the low end, of the aligned word that holds address a.
 *   addr: address; bits 0..1 pick the byte number from the low end of its aligned word
 *   value: new byte value
 * Note: In this big-endian program that is the byte at (a & ~3) + 3 - (a & 3), not the byte at a; nothing
 *   calls it.
 * Name basis: descriptive - code only; no reference in the image
 *
 * Matching notes
 * --------------
 * FUN_a002c2a0 (leon2m 0xa002c2a0-0xa002c2d4, 52 bytes, leaf), flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the word pointer is volatile, so the store stays out of the retl delay slot.
 */

/*
 * Replace byte number (addr & 3), counted from the least significant end, of the aligned word that holds
 * 'addr' with 'value'; the other three bytes are written back unchanged. The counterpart of
 * reg_read_byte_in_word. Nothing in the image refers to it.
 */
void reg_write_byte_in_word(unsigned int addr, unsigned char value)
{
    unsigned int shift = (addr & 3) << 3;
    volatile unsigned int *word = (volatile unsigned int *)(addr & ~3u);

    *word = (*word & ~(0xff << shift)) | (value << shift);
}
