/* leon2m FUN_a00a49b8 @ 0xa00a49b8-0xa00a4a30 (30 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/30 mismatches.
 * Code facts: b = (u8)(byte DAT_a802d290[9] - 1); if b > 100 (also the wrap from 0): byte
 * DAT_a802d290[9] = 0; else store b, FUN_a00a45c0(5, 8, b, 0xc), FUN_a00b3708(10, 6,
 * DAT_a802d290[9]) (reloaded after the call), FUN_a00d8cd4(). Then FUN_a00d4998(); bit 1 of
 * byte DAT_a802b08e set. void, no params.
 * Required form: the reset arm FIRST ('if (b > 100)',
 * exact negation; the abff8 lever). With the calls arm first, local-alloc gives the loaded
 * byte %g1 and the masked b %o5 (fw: load/sub in %o5, b in %g1). Prototypes: a45c0 and b3708
 * re-mask their first args (u8). Aids: none.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802b08e;
extern void FUN_a00a45c0(unsigned char, unsigned char, unsigned char, unsigned int);
extern void FUN_a00b3708(unsigned char, unsigned char, unsigned int);
extern void FUN_a00d8cd4(void);
extern void FUN_a00d4998(void);

void FUN_a00a49b8(void)
{
    unsigned char b = DAT_a802d290[9] - 1;
    if (b > 100) {
        DAT_a802d290[9] = 0;
    } else {
        DAT_a802d290[9] = b;
        FUN_a00a45c0(5, 8, b, 0xc);
        FUN_a00b3708(10, 6, DAT_a802d290[9]);
        FUN_a00d8cd4();
    }
    FUN_a00d4998();
    DAT_a802b08e |= 2;
}
