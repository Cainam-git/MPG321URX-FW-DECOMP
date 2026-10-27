/* FUN_a0121388 (leon2m 0xa0121388-0xa01213a4, 28 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Clears bit 'bit' of the word DAT_a802c9e4. Nothing in the image refers to it: no call, branch, sethi/or constant
 * or address word. It lies between FUN_a0121374 and FUN_a01213a4.
 */
extern unsigned int DAT_a802c9e4;

void FUN_a0121388(unsigned int bit)
{
    DAT_a802c9e4 &= ~(1 << bit);
}
