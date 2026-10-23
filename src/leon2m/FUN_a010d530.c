/* leon2m FUN_a010d530 @ 0xa010d530-0xa010d838 (776 bytes). Flags -mcpu=v8 -O3 -g.
 *
 * void FUN_a010d530(c, a, b, d): ch = (unsigned char)c selects a channel record (ch == 1 -> 0xA802D7C4, ch == 2 ->
 * 0xA802D784, else 0xA802D744) and stores a, b, d in its bytes +0x3B, +0x3C, +0x3D. For each of a, b, d in turn,
 * word w (block words 0x3D, 0x3E, 0x3F = offsets 0xF4, 0xF8, 0xFC) of T1[ch > 2 ? 0 : ch] is read and written back
 * with bits 16..23 replaced by (x * 255 + 50) / 100 - 0x80 (unsigned), first to T1 = DAT_0019aed8, then to
 * T2 = DAT_0019aecc (entry ch, or entries 0..2 when ch > 2).
 * Same SET form as FUN_a010edbc. No direct callers in asm/leon2m. FUN_a010d244 writes the low 10 bits of the same
 * words from bytes +0x38..+0x3A.
 * Source form: 'unsigned int idx = ch > 2 ? 0 : c;' then '(unsigned char)idx' for each read (selects on the wide
 *   parameter); record bytes stored in ascending order.
 */
struct ChBlk { unsigned char pad[0x3b]; unsigned char b3b, b3c, b3d; };
struct Regs { unsigned int w[0x40]; };
extern struct ChBlk DAT_a802d744, DAT_a802d784, DAT_a802d7c4;
extern volatile struct Regs *const DAT_0019aed8[3];
extern volatile struct Regs *const DAT_0019aecc[3];

#define SET(tab, f, val) do { if (ch > 2) { unsigned int i; for (i = 0; i <= 2; i++) tab[i]->f = val; } else tab[ch]->f = val; } while (0)

void FUN_a010d530(unsigned int c, unsigned char a, unsigned char b, unsigned char d)
{
    unsigned char ch = c;
    struct ChBlk *p;
    unsigned int w;

    p = &DAT_a802d7c4;
    if (ch != 1) {
        p = &DAT_a802d744;
        if (ch == 2) p = &DAT_a802d784;
    }
    p->b3b = a;
    p->b3c = b;
    p->b3d = d;
    {
        unsigned int idx = ch > 2 ? 0 : c;
        w = (DAT_0019aed8[(unsigned char)idx]->w[0x3d] & ~0xff0000) | (((a * 255U + 50) / 100 - 0x80) << 16);
    }
    SET(DAT_0019aed8, w[0x3d], w);
    SET(DAT_0019aecc, w[0x3d], w);
    {
        unsigned int idx = ch > 2 ? 0 : c;
        w = (DAT_0019aed8[(unsigned char)idx]->w[0x3e] & ~0xff0000) | (((b * 255U + 50) / 100 - 0x80) << 16);
    }
    SET(DAT_0019aed8, w[0x3e], w);
    SET(DAT_0019aecc, w[0x3e], w);
    {
        unsigned int idx = ch > 2 ? 0 : c;
        w = (DAT_0019aed8[(unsigned char)idx]->w[0x3f] & ~0xff0000) | (((d * 255U + 50) / 100 - 0x80) << 16);
    }
    SET(DAT_0019aed8, w[0x3f], w);
    SET(DAT_0019aecc, w[0x3f], w);
}
