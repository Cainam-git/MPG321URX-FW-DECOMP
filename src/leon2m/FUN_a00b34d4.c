/* leon2m FUN_a00b34d4 @ 0xa00b34d4  (-mcpu=v8 -O3 -g)
 * Byte DAT_a802d290 +0x189 holds two nibbles. Calls FUN_a0146b50(0x1EE, 0) and FUN_a0146b6c(2, 0); if hi differs from
 * the stored high nibble: FUN_a0146a80(0x37, 0xE, 4, 0x596, 0) and FUN_a00a31a4(0, 0x37, 0xE, 4, FUN_a00a3844(table
 * 0x1928B0, hi * 29 + byte +8), 0). The same with FUN_a0146b50(0x1F7, 0), lo, the low nibble and second argument
 * 0x13. Finally byte +0x189 = (hi << 4) + lo.
 * Callers: FUN_a0091710, FUN_a00919b4, FUN_a0091d74, FUN_a009221c and others; FUN_a00b7474 tail-calls it.
 * Source form: the two-call step is a static helper inlined twice (written in place, the register names
 * differ); the same step appears alone in FUN_a00b344c.
 */
struct R290 { unsigned char pad[8]; unsigned char b08; unsigned char pad2[0x189 - 9]; unsigned char b189; };
extern struct R290 DAT_a802d290;
extern void FUN_a0146b50(int, int);
extern void FUN_a0146b6c(int, int);
extern void FUN_a0146a80(int, int, int, int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);

static void row(unsigned int y, unsigned int v)
{
    FUN_a0146a80(0x37, y, 4, 0x596, 0);
    FUN_a00a31a4(0, 0x37, y, 4, FUN_a00a3844((unsigned int *)0x1928b0, v * 29 + DAT_a802d290.b08), 0);
}

void FUN_a00b34d4(unsigned char hi, unsigned char lo)
{
    FUN_a0146b50(0x1ee, 0);
    FUN_a0146b6c(2, 0);
    if (hi != DAT_a802d290.b189 >> 4)
        row(0xe, hi);
    FUN_a0146b50(0x1f7, 0);
    FUN_a0146b6c(2, 0);
    if (lo != (DAT_a802d290.b189 & 0xf))
        row(0x13, lo);
    DAT_a802d290.b189 = (hi << 4) + lo;
}
