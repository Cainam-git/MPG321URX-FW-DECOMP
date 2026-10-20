/* FUN_a00afeb8 (leon2s, 0xa00afeb8-0xa00b0004, 83 words). Flags -mcpu=v8 -Os -g. jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 Code facts: (port, restart). restart: counter DAT_a807933a = 0, aec50(port, 1). Three a6c98 writes (0x483/0x24/1, 0x483/3/0, 0x486/1/1); r = (u16)FUN_a00acc54(port);
 a4ec4(0, r); if (u16)(r - 101) <= 0x30: 6c98(port, 0x483, 1, (u8)6bb8(port, 0x21c) == 6 ? 0 : 1). 6c00(port, 0x485, DAT_a00b4df8[counter]); aec10();
 (u8)aec50(port, 0) == 1 -> counter++; counter > 10 -> counter = 0, afdf4(port, 0), return 1; else return 0.
 Fixes vs draft: BEHAVIOUR a4ec4's 2nd arg is r itself (the draft passed r >> 16); FUN_a00acc54 returns unsigned short (its retl path does
 sll/srl 16) and r is u16; the counter is a plain byte (the draft used a volatile 0xa8079000 base and a bogus store). Aids: none.
 */
extern unsigned char DAT_a807933a;
extern unsigned char DAT_a00b4df8[];
extern unsigned int FUN_a00aec50(unsigned int, unsigned int);
extern void FUN_a00a6c98(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned short FUN_a00acc54(unsigned int);
extern void FUN_a00a4ec4(unsigned int, unsigned short);
extern unsigned int FUN_a00a6bb8(unsigned int, unsigned short);
extern void FUN_a00a6c00(unsigned int, unsigned short, unsigned int);
extern void FUN_a00aec10(void);
extern void FUN_a00afdf4(unsigned int, unsigned int);

unsigned int FUN_a00afeb8(unsigned int param_1, unsigned int param_2)
{
    unsigned short r;

    if ((param_2 & 0xff) != 0) {
        DAT_a807933a = 0;
        FUN_a00aec50(param_1 & 0xff, 1);
    }
    param_1 = param_1 & 0xff;
    FUN_a00a6c98(param_1, 0x483, 0x24, 1);
    FUN_a00a6c98(param_1, 0x483, 3, 0);
    FUN_a00a6c98(param_1, 0x486, 1, 1);
    r = FUN_a00acc54(param_1);
    FUN_a00a4ec4(0, r);
    if ((unsigned short)(r - 101) <= 0x30) {
        if ((FUN_a00a6bb8(param_1, 0x21c) & 0xff) == 6)
            FUN_a00a6c98(param_1, 0x483, 1, 0);
        else
            FUN_a00a6c98(param_1, 0x483, 1, 1);
    }
    FUN_a00a6c00(param_1, 0x485, DAT_a00b4df8[DAT_a807933a]);
    FUN_a00aec10();
    if ((FUN_a00aec50(param_1, 0) & 0xff) == 1)
        DAT_a807933a++;
    if (DAT_a807933a > 10) {
        DAT_a807933a = 0;
        FUN_a00afdf4(param_1, 0);
        return 1;
    }
    return 0;
}
