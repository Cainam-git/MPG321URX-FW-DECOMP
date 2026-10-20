/* FUN_a008faa0 (leon2s, 0xa008faa0-0xa008facc, 44 bytes, 11 words, leaf).
 * Flags: -mcpu=v8 -Os -g.
 * Code facts: rec = ARR_a807d3e4 + (u8)param_1 * 0xb0; clears the bytes +0x57, +0x68, +0x1f, +0x41, +0x8a.
 * Fix vs draft: source store order 0x57, 0x68, 0x1f, 0x41, 0x8a (1 of 120 orders gives the fw
 * 8a, 57, 68, 1f, 41). Twin of FUN_a008fa78 (same record, neighbouring bytes).
 * Store order: in this -Os block of independent byte clears the fw emits the LAST source store first,
 * then the others in source order (the last of those in the retl delay slot).
 * Aids: none.
 */
extern unsigned char ARR_a807d3e4[];

void FUN_a008faa0(unsigned int param_1)
{
    unsigned char *p = ARR_a807d3e4 + (param_1 & 0xff) * 176;
    p[0x57] = 0;
    p[0x68] = 0;
    p[0x1f] = 0;
    p[0x41] = 0;
    p[0x8a] = 0;
}
