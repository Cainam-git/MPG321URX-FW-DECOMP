/* FUN_a00978c8 (leon2m, 0xa00978c8-0xa0097988, 48 words). Flags -mcpu=v8 -O3 -g. jf 100.00 match=True, rawcmp 0 mismatches.
 Code facts: void(void). a8ee8(DAT_a8025c56); a813c(0, DAT_a8025c56, 0); a813c(0, DAT_a802d290[0x1f], 0); a900c((u8)(_DAT_a802afec - 35), 2);
 FUN_a0097508(); FUN_a00976f8(); _DAT_a802afec = 0x7a; a9650(0, 3); v = DAT_a802d290[0x1f]; if v != DAT_a8025c56 { FUN_a00acef4(); v = re-read };
 DAT_a8025c56 = v; DAT_a8025c55 = DAT_a802d290[0x1a4]; DAT_a802b08f = 0xf; tail call FUN_a00d4998().
 Fixes vs draft: one variable v with TWO sets (before the test and after acef4): the second set is why the fw keeps 'and %o3,0xff' after the
 ldub (regmove cannot fold it); plain (non-volatile) DAT_a802d290 byte array; void. Aids: none.
 */
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802b08f;
extern unsigned char DAT_a802d290[];
extern void FUN_a0097508(void);
extern void FUN_a00976f8(void);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a8ee8(unsigned char);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9650(int, int);
extern void FUN_a00acef4(void);
extern void FUN_a00d4998(void);

void FUN_a00978c8(void)
{
    unsigned char v;

    FUN_a00a8ee8(DAT_a8025c56);
    FUN_a00a813c(0, DAT_a8025c56, 0);
    FUN_a00a813c(0, DAT_a802d290[0x1f], 0);
    FUN_a00a900c(_DAT_a802afec - 35, 2);
    FUN_a0097508();
    FUN_a00976f8();
    _DAT_a802afec = 0x7a;
    FUN_a00a9650(0, 3);
    v = DAT_a802d290[0x1f];
    if (v != DAT_a8025c56) {
        FUN_a00acef4();
        v = DAT_a802d290[0x1f];
    }
    DAT_a8025c56 = v;
    DAT_a8025c55 = DAT_a802d290[0x1a4];
    DAT_a802b08f = 0xf;
    FUN_a00d4998();
}
