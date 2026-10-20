/* leon2m FUN_a010edbc @ 0xa010edbc-0xa010ef64 (424 bytes)  program half the transformed row's +0x08 value into the
 * output channel register blocks (hand; BYTE-EXACT at -mcpu=v8 -O3 -g, also -O3 -g -msoft-float and
 * -O3; jf.py 100 %, rawcmp mismatches 0). Twin of the byte-exact FUN_a010f7a4.
 *
 * void FUN_a010edbc(c): ch = (unsigned char)c selects a channel record: ch == 1 -> 0xA802D7C4, ch == 2 -> 0xA802D784,
 *   else 0xA802D744; sets bit 0 of its byte +0x3E.
 *   v = (transformed row *DAT_a802d6a4 halfword +0x08 >> 1) << 16.
 *   Two pointer tables of 3 register blocks {w0, w4, w8, wc}: T1 = 0x19AED8, T2 = 0x19AECC.
 *   wc = v in T1[ch] then T2[ch]; ch > 2 means "all three blocks" (loop i = 0..2) for every write.
 *   w = T1[ch > 2 ? 0 : ch]->w4 | 0x4000 (bit 14), then w4 = w in T1 and T2 the same way.
 * Globals: DAT_a802d744/784/7c4 (+0x3E byte), DAT_a802d6a4 (pointer to the transformed panel row, reads +0x08 only),
 *   DAT_0019aed8[3], DAT_0019aecc[3] (pointers to register blocks; writes +0x0C and +0x04, reads +0x04 of T1).
 * Callers: no direct call in asm/leon2m; Ghidra marks the entry unreachable.
 * Panel row fields read: transformed row +0x08 only.
 * BYTE-EXACT key: the index select is 'unsigned int idx = ch > 2 ? 0 : c;' used as (unsigned char)idx (selects on the
 *   wide parameter, then truncates: bgu,a / clr %i0 / and 0xff). 'if (ch > 2) c = 0;' is if-converted to subx/and.
 */
struct ChBlk { unsigned char pad[0x3e]; unsigned char b3e; };
struct Regs { unsigned int w0, w4, w8, wc; };
struct PanelParam { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08; };
extern struct ChBlk DAT_a802d744, DAT_a802d784, DAT_a802d7c4;
extern struct PanelParam *DAT_a802d6a4;
extern volatile struct Regs *const DAT_0019aed8[3];
extern volatile struct Regs *const DAT_0019aecc[3];

#define SET(tab, f, val) do { if (ch > 2) { unsigned int i; for (i = 0; i <= 2; i++) tab[i]->f = val; } else tab[ch]->f = val; } while (0)

void FUN_a010edbc(unsigned int c)
{
    unsigned char ch = c;
    struct ChBlk *p;
    unsigned int v, w;

    p = &DAT_a802d7c4;
    if (ch != 1) {
        p = &DAT_a802d744;
        if (ch == 2) p = &DAT_a802d784;
    }
    p->b3e |= 1;
    v = (DAT_a802d6a4->h08 >> 1) << 16;
    SET(DAT_0019aed8, wc, v);
    SET(DAT_0019aecc, wc, v);
    {
        unsigned int idx = ch > 2 ? 0 : c;
        w = DAT_0019aed8[(unsigned char)idx]->w4 | 0x4000;
    }
    SET(DAT_0019aed8, w4, w);
    SET(DAT_0019aecc, w4, w);
}
