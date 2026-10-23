/* leon2m FUN_a010d244 @ 0xa010d244-0xa010d530 (748 bytes). Flags -mcpu=v8 -O3 -g.
 *
 * void FUN_a010d244(c, a, b, d): ch = (unsigned char)c selects a channel record (ch == 1 -> 0xA802D7C4, ch == 2 ->
 * 0xA802D784, else 0xA802D744) and stores a, b, d in its bytes +0x38, +0x39, +0x3A. For each of a, b, d in turn,
 * word w (block words 0x3D, 0x3E, 0x3F = offsets 0xF4, 0xF8, 0xFC) of T1[ch > 2 ? 0 : ch] is read and written back
 * with bits 0..9 replaced by (x * 1023 + 50) / 100 (unsigned), first to T1 = DAT_0019aed8, then to
 * T2 = DAT_0019aecc (entry ch, or entries 0..2 when ch > 2).
 * Same SET form as FUN_a010edbc; FUN_a010d530 writes bits 16..23 of the same words. No direct callers in asm/leon2m.
 * Source form: c is an unsigned short parameter and each read index is 'unsigned short idx = ch > 2 ? 0 : c;'
 *   (with unsigned int types the incoming c is moved out of %i0); record bytes stored in ascending order.
 */
struct ChBlk { unsigned char pad[0x38]; unsigned char b38, b39, b3a; };
struct Regs { unsigned int w[0x40]; };
extern struct ChBlk DAT_a802d744, DAT_a802d784, DAT_a802d7c4;
extern volatile struct Regs *const DAT_0019aed8[3];
extern volatile struct Regs *const DAT_0019aecc[3];

#define SET(tab, f, val) do { if (ch > 2) { unsigned int i; for (i = 0; i <= 2; i++) tab[i]->f = val; } else tab[ch]->f = val; } while (0)

void FUN_a010d244(unsigned short c, unsigned char a, unsigned char b, unsigned char d)
{
    unsigned char ch = c;
    struct ChBlk *p;
    unsigned int w;

    p = &DAT_a802d7c4;
    if (ch != 1) {
        p = &DAT_a802d744;
        if (ch == 2) p = &DAT_a802d784;
    }
    p->b38 = a;
    p->b39 = b;
    p->b3a = d;
    {
        unsigned short idx = ch > 2 ? 0 : c;
        w = (DAT_0019aed8[(unsigned char)idx]->w[0x3d] & ~0x3ff) | (a * 1023U + 50) / 100;
    }
    SET(DAT_0019aed8, w[0x3d], w);
    SET(DAT_0019aecc, w[0x3d], w);
    {
        unsigned short idx = ch > 2 ? 0 : c;
        w = (DAT_0019aed8[(unsigned char)idx]->w[0x3e] & ~0x3ff) | (b * 1023U + 50) / 100;
    }
    SET(DAT_0019aed8, w[0x3e], w);
    SET(DAT_0019aecc, w[0x3e], w);
    {
        unsigned short idx = ch > 2 ? 0 : c;
        w = (DAT_0019aed8[(unsigned char)idx]->w[0x3f] & ~0x3ff) | (d * 1023U + 50) / 100;
    }
    SET(DAT_0019aed8, w[0x3f], w);
    SET(DAT_0019aecc, w[0x3f], w);
}
