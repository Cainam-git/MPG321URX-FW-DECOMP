/* FUN_a008fa78 (leon2s, 0xa008fa78-0xa008faa0, 40 bytes, 10 words, leaf).
 * Flags: -mcpu=v8 -Os -g.
 * Code facts: rec = ARR_a807d3e4 + (u8)param_1 * 0xb0; clears the bytes +0x58, +0x69, +0x42, +0x8b.
 * Fixes vs draft: the record base is the SYMBOL ARR_a807d3e4 (draft: a constant pointer) and the
 * source store order is 0x58, 0x69, 0x42, 0x8b (1 of 24 orders gives the fw 8b, 58, 69, 42).
 * Store order: in this -Os block of independent byte clears the fw emits the LAST source store first,
 * then the others in source order (the last of those in the retl delay slot).
 * Aids: none.
 */
extern unsigned char ARR_a807d3e4[];

void FUN_a008fa78(unsigned int param_1)
{
    unsigned char *p = ARR_a807d3e4 + (param_1 & 0xff) * 176;
    p[0x58] = 0;
    p[0x69] = 0;
    p[0x42] = 0;
    p[0x8b] = 0;
}
