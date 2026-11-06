/* leon2m FUN_a010f064 @ 0xa010f064-0xa010f50c (1192 bytes). Flags -mcpu=v8 -O3 -g.
 *
 * void FUN_a010f064(c, sel, a, b, e, d): writes two packed values into the register blocks of the
 * channel tables T1 = DAT_0019aef0 and T2 = DAT_0019aee4 (3 pointers each to blocks {w0, w4, ..., w18}).
 *   v1 = ((a >> 1) << 16) | b, v2 = ((e >> 1) << 16) | d.
 *   w = T1[ch > 2 ? 0 : ch]->w0 (read once before any write).
 *   sel == 0: w8 = v1, wc = v2, w0 = w | 1;  sel != 0: w10 = v1, w14 = v2, w0 = w | 0x10.
 *   Then w18 = 0x50005. Each value goes to T1 then T2; ch = (unsigned char)c > 2 writes blocks 0..2.
 * Same SET form as FUN_a010edbc (0x19aed8/0x19aecc tables). No direct callers in asm/leon2m.
 * Source form: the v1 pair of each arm is written by a static helper (set2_8 / set2_10, like set2 in
 *   FUN_a010f50c) called with ch and the raw parameter c as its two channels; the firmware recomputes
 *   'and %i0, 0xff' for the T2 write of v1 while every other write uses ch.
 */
struct Regs { unsigned int w0, w4, w8, wc, w10, w14, w18; };
extern volatile struct Regs *const DAT_0019aef0[3];
extern volatile struct Regs *const DAT_0019aee4[3];

/* Field f of block n of table tab, or of blocks 0..2 when n > 2. */
#define SET(tab, n, f, val) { if ((n) > 2) { unsigned int i; for (i = 0; i <= 2; i++) tab[i]->f = val; } \
                              else tab[n]->f = val; }

static void set2_8(unsigned char ch, unsigned char k, unsigned int v)
{
    SET(DAT_0019aef0, ch, w8, v);
    SET(DAT_0019aee4, k, w8, v);
}

static void set2_10(unsigned char ch, unsigned char k, unsigned int v)
{
    SET(DAT_0019aef0, ch, w10, v);
    SET(DAT_0019aee4, k, w10, v);
}

void FUN_a010f064(unsigned short c, unsigned char sel, unsigned short a, unsigned short b, unsigned short e,
                  unsigned short d)
{
    unsigned char ch = c;
    unsigned int v1, v2, w;

    v1 = ((a >> 1) << 16) | b;
    v2 = ((e >> 1) << 16) | d;
    {
        unsigned char idx = ch > 2 ? 0 : c;
        w = DAT_0019aef0[idx]->w0;
    }
    if (sel == 0) {
        set2_8(ch, c, v1);
        SET(DAT_0019aef0, ch, wc, v2);
        SET(DAT_0019aee4, ch, wc, v2);
        w |= 1;
        SET(DAT_0019aef0, ch, w0, w);
        SET(DAT_0019aee4, ch, w0, w);
    } else {
        set2_10(ch, c, v1);
        SET(DAT_0019aef0, ch, w14, v2);
        SET(DAT_0019aee4, ch, w14, v2);
        w |= 0x10;
        SET(DAT_0019aef0, ch, w0, w);
        SET(DAT_0019aee4, ch, w0, w);
    }
    w = 0x50005;
    SET(DAT_0019aef0, ch, w18, w);
    SET(DAT_0019aee4, ch, w18, w);
}
