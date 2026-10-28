/* FUN_a00d7bf8 (leon2s 0xa00d7bf8-0xa00d7ca4, 172 bytes, leaf), flags -mcpu=v8 -Os -g.
 * With the register block p = DAT_a80760a4[DAT_a8078832] (index byte re-read at every access): while bit 3 of
 * word 0xf7 is set, sets it again (read-modify-write), at most 1000 times (unsigned short counter); then sets
 * bit 7 of word 0x30.
 * Source form: one for loop whose condition tests the bit before the counter.
 */
extern unsigned char DAT_a8078832;
extern volatile unsigned int *DAT_a80760a4[];

void FUN_a00d7bf8(void)
{
    unsigned short n;

    for (n = 0; (DAT_a80760a4[DAT_a8078832][0xf7] & 8) && n < 1000; n++)
        DAT_a80760a4[DAT_a8078832][0xf7] |= 8;
    DAT_a80760a4[DAT_a8078832][0x30] |= 0x80;
}
