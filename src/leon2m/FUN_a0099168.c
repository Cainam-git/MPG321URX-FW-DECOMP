/* leon2m FUN_a0099168 @ 0xa0099168-0xa00991ec (33 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 33 words.
 * Code facts: f = bit 15 of word 0xa802d290+0xa8; FUN_a00a93bc(f); f = byte 0xa8025c56 & 1; FUN_a00a9650(f, 0);
 * FUN_a00a813c(1, f, 1) (f re-read each time); word 0xa802afec = 0x2e; tail FUN_a00a900c(4, 1).
 * Fix vs the autoc draft (75.76): bit 15 as a 1-bit BIT-FIELD (big-endian: hi:16, b15:1, lo:15) of the record word
 * via a struct pointer (fw sethi|or into %l0; the draft used the mid-record name _DAT_a802d338 with masks).
 * Aids: none.
 */
struct R290 { unsigned char pad[0xa8]; struct { unsigned int hi : 16, b15 : 1, lo : 15; } fa8; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);

void FUN_a0099168(void)
{
    struct R290 *p = &DAT_a802d290;

    FUN_a00a93bc(p->fa8.b15);
    p->fa8.b15 = DAT_a8025c56;
    FUN_a00a9650(p->fa8.b15, 0);
    FUN_a00a813c(1, p->fa8.b15, 1);
    _DAT_a802afec = 0x2e;
    FUN_a00a900c(4, 1);
}
