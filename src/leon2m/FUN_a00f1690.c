/* FUN_a00f1690 (leon2m, 0xa00f1690-0xa00f16d8, 72 bytes, 18 words, leaf).
 * Flags: -mcpu=v8 -O3 -g.
 * Code facts: blk (u8) is clamped to 0 when blk >= 2 (fw: cmp %o5,2 + addx/neg/and mask form), then the u16 table
 * DAT_a8026a7a[blk] (firmware base 0xa8026a7a via sethi/or) plus reg (u16) is the register index; the function reads
 * the word at 0xcf000000 | (index << 2) and returns its low byte.
 * The clamp limit is 2. Table declared with 2 entries.
 * Compiler aids: none.
 */
extern unsigned short DAT_a8026a7a[2];     /* block bases */

unsigned char FUN_a00f1690(unsigned char blk, unsigned short reg)
{
    if (blk >= 2) blk = 0;
    return *(volatile unsigned int *)(0xcf000000 | ((DAT_a8026a7a[blk] + reg) << 2));
}
