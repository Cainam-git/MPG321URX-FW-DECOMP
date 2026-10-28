/* leon2m FUN_a010f50c @ 0xa010f50c-0xa010f65c (336 bytes). Flags -mcpu=v8 -O3 -g.
 *
 * void FUN_a010f50c(c, on): clears one flag bit in word w0 of the register blocks of the channel tables
 * T1 = DAT_0019aef0 and T2 = DAT_0019aee4 (3 pointers each to blocks {w0, w4, ..., w18}).
 *   w = T1[ch > 2 ? 0 : ch]->w0 (read once before any write), ch = (unsigned char)c.
 *   on == 0: v = w & ~1; on != 0: v = w & ~0x10. v is written to w0 of T1 then T2; a channel > 2 writes
 *   blocks 0..2. Same SET form as FUN_a010f064.
 * Source form: both writes are in a static helper set2(ch, k, v) with unsigned char channel parameters,
 *   called once per arm with (ch, c, w & mask); the T2 channel is the narrowed parameter c, which the
 *   firmware masks again from %o0 ('and %o0, 0xff') for the T2 test.
 */
struct Regs { unsigned int w0, w4, w8, wc, w10, w14, w18; };
extern volatile struct Regs *const DAT_0019aef0[3];
extern volatile struct Regs *const DAT_0019aee4[3];

/* Field f of block n of table tab, or of blocks 0..2 when n > 2. */
#define SET(tab, n, f, val) do { if ((n) > 2) { unsigned int i; for (i = 0; i <= 2; i++) tab[i]->f = val; } \
                                 else tab[n]->f = val; } while (0)

static void set2(unsigned char ch, unsigned char k, unsigned int v)
{
    SET(DAT_0019aef0, ch, w0, v);
    SET(DAT_0019aee4, k, w0, v);
}

void FUN_a010f50c(unsigned short c, unsigned char on)
{
    unsigned char ch = c;
    unsigned int w;

    {
        unsigned char idx = ch > 2 ? 0 : c;
        w = DAT_0019aef0[idx]->w0;
    }
    if (on == 0)
        set2(ch, c, w & ~1);
    else
        set2(ch, c, w & ~0x10);
}
