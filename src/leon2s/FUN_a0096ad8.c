/* FUN_a0096ad8 (leon2s, 0xa0096ad8-0xa0096b08, 48 bytes, 12 words, leaf).
 * Flags: -mcpu=v8 -Os -g.
 * rec = ARR_a807d7e0 + (u8)param_1 * 400 (smul 0x190); clears the bytes +0xa2, +0xe7, +0x10d, +0xb9,
 * +0x182, +0x187.
 * The base is ARR_a807d7e0 (firmware sethi 0xa807d400 | 0x3e0). The source store order follows the rule
 * below, as in the twins FUN_a008fa78 / FUN_a008faa0.
 * Store order: in this -Os block of independent byte clears the firmware emits the last source store first,
 * then the others in source order (the last of those in the retl delay slot).
 */
extern unsigned char ARR_a807d7e0[];

void FUN_a0096ad8(unsigned int param_1)
{
    unsigned char *p = &ARR_a807d7e0[(param_1 & 0xff) * 400];
    p[0xa2] = 0;
    p[0xe7] = 0;
    p[0x10d] = 0;
    p[0xb9] = 0;
    p[0x182] = 0;
    p[0x187] = 0;
}
