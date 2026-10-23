/* leon2m FUN_a010e624 @ 0xa010e624-0xa010e8ec (712 bytes). Flags -mcpu=v8 -O3 -g.
 *
 * void FUN_a010e624(c, a, b, d): ch = (unsigned char)c selects a record (ch == 1 -> 0xA802D804, else 0xA802D704,
 * ctx() as in FUN_a010d914) and stores a, b, d in its bytes +0x38, +0x39, +0x3A. For each of a, b, d in turn,
 * word w (block words 9, 10, 11 = offsets 0x24, 0x28, 0x2C) of T1[ch > 1 ? 0 : ch] is read and written back with
 * bits 0..9 replaced by (x * 1023 + 50) / 100 (unsigned), first to T1 = DAT_0019aec4, then to T2 = DAT_0019aebc
 * (entry ch, or entries 0..1 when ch > 1).
 * Two-record counterpart of FUN_a010d244. No direct callers in asm/leon2m.
 * Source form: SET macro of FUN_a010d914 (else arm 'i = ch; tab[i]'); c is an unsigned short parameter and each
 *   read index is 'unsigned short idx = ch > 1 ? 0 : c;'; record bytes stored in ascending order.
 */
struct ChBlk { unsigned char pad[0x38]; unsigned char b38, b39, b3a; };
struct Regs { unsigned int w[0x40]; };
extern struct ChBlk DAT_a802d704, DAT_a802d804;
extern volatile struct Regs *const DAT_0019aec4[2];
extern volatile struct Regs *const DAT_0019aebc[2];

#define SET(tab, f, val) do { unsigned int i; if (ch > 1) { for (i = 0; i <= 1; i++) tab[i]->f = val; } else { i = ch; tab[i]->f = val; } } while (0)

static struct ChBlk *ctx(unsigned char ch)
{
    if (ch != 1) return &DAT_a802d704;
    return &DAT_a802d804;
}

void FUN_a010e624(unsigned short c, unsigned char a, unsigned char b, unsigned char d)
{
    unsigned char ch = c;
    struct ChBlk *p;
    unsigned int w;

    p = ctx(ch);
    p->b38 = a;
    p->b39 = b;
    p->b3a = d;
    {
        unsigned short idx = ch > 1 ? 0 : c;
        w = (DAT_0019aec4[(unsigned char)idx]->w[9] & ~0x3ff) | (a * 1023U + 50) / 100;
    }
    SET(DAT_0019aec4, w[9], w);
    SET(DAT_0019aebc, w[9], w);
    {
        unsigned short idx = ch > 1 ? 0 : c;
        w = (DAT_0019aec4[(unsigned char)idx]->w[10] & ~0x3ff) | (b * 1023U + 50) / 100;
    }
    SET(DAT_0019aec4, w[10], w);
    SET(DAT_0019aebc, w[10], w);
    {
        unsigned short idx = ch > 1 ? 0 : c;
        w = (DAT_0019aec4[(unsigned char)idx]->w[11] & ~0x3ff) | (d * 1023U + 50) / 100;
    }
    SET(DAT_0019aec4, w[11], w);
    SET(DAT_0019aebc, w[11], w);
}
