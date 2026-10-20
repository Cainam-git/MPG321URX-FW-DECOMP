/* FUN_a00dc0a8 (leon2s, 0xa00dc0a8-0xa00dc214, 364 bytes, 91 words).
 * Flags: -mcpu=v8 -Os -g.
 * Code facts: prints DAT_9f1ccc30 with DAT_a8078832 (the current index). If the byte DAT_a8078840 == 1:
 * x = DAT_a8078832 (u16): clears the bytes DAT_a8078830/828/808/800[x] and the u16 ARR_a807880a/
 * 880e[x]; clears DAT_a80787fc..ff; for i = 0..3 clears ARR_a8079c3d[2i] and [2i+1]; x reloaded:
 * clears DAT_a8078850/848[x] and bits 4..5 of the word at ARR_a80760a4[x] + 0xccc; x reloaded:
 * DAT_a80760b0[x] = 1, clears the u16 _DAT_a80787fa/_DAT_a80787f8 and the byte at 0xa8078838 + x,
 * clears DAT_a8078847; FUN_a00d9a78() when (u8)func_0xa0f966a4() != 0; FUN_a00d6560(DAT_a8078832).
 * Always clears DAT_a8078840 at the end (fw: in the bne,a delay slot and before ret).
 * Fixes vs draft: the draft's first store used an uninitialised index (removed); x is u16 (fw doubles
 * it with add for the u16 arrays); string symbol DAT_9f1ccc30; void. Source order of the first six
 * clears is 830, 828, 80e, 80a, 808, 800 (2 of 720 orders give the fw order; perm.py).
 * AID: the 0xa8078838 byte is written through a local constant pointer
 * 'p = (u8 *)0xa8078838; p[x] = 0' (same instruction bytes as the symbol DAT_a8078838: sethi/or).
 * With the symbol, alias analysis lets sched move that store before the 7fa/7f8 clears (96.70 for
 * all 24 orders of that block); the constant base keeps the fw order and the [%g1+%o4] operands.
 */
extern unsigned char DAT_a80787fc;
extern unsigned char DAT_a80787fd;
extern unsigned char DAT_a80787fe;
extern unsigned char DAT_a80787ff;
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8078840;
extern unsigned char DAT_a8078847;
extern unsigned short _DAT_a80787f8;
extern unsigned short _DAT_a80787fa;
extern void FUN_a00d6560(unsigned char param_1);
extern void FUN_a00d9a78(void);
extern int func_0xa0f83044();
extern int func_0xa0f966a4();
extern unsigned int ARR_a80760a4[];
extern unsigned short ARR_a807880a[];
extern unsigned short ARR_a807880e[];
extern unsigned char ARR_a8079c3d[];
extern unsigned char DAT_a80760b0[];
extern unsigned char DAT_a8078800[];
extern unsigned char DAT_a8078808[];
extern unsigned char DAT_a8078828[];
extern unsigned char DAT_a8078830[];
extern unsigned char DAT_a8078838[];
extern unsigned char DAT_a8078848[];
extern unsigned char DAT_a8078850[];
extern const char DAT_9f1ccc30[];

void FUN_a00dc0a8(void)
{
    unsigned short x;
    unsigned char i;

    func_0xa0f83044(DAT_9f1ccc30, DAT_a8078832);
    if (DAT_a8078840 == 1) {
        x = DAT_a8078832;
        DAT_a8078830[x] = 0;
        DAT_a8078828[x] = 0;
        ARR_a807880e[x] = 0;
        ARR_a807880a[x] = 0;
        DAT_a8078808[x] = 0;
        DAT_a8078800[x] = 0;
        DAT_a80787ff = 0;
        DAT_a80787fe = 0;
        DAT_a80787fd = 0;
        DAT_a80787fc = 0;
        i = 0;
        do {
            ARR_a8079c3d[i * 2] = 0;
            ARR_a8079c3d[i * 2 + 1] = 0;
            i++;
        } while (i < 4);
        x = DAT_a8078832;
        DAT_a8078850[x] = 0;
        DAT_a8078848[x] = 0;
        *(unsigned int *)(ARR_a80760a4[x] + 0xccc) &= ~0x30;
        x = DAT_a8078832;
        DAT_a80760b0[x] = 1;
        _DAT_a80787fa = 0;
        _DAT_a80787f8 = 0;
        { unsigned char *p = (unsigned char *)0xa8078838; p[x] = 0; }
        DAT_a8078847 = 0;
        if (func_0xa0f966a4() & 0xff)
            FUN_a00d9a78();
        FUN_a00d6560(DAT_a8078832);
    }
    DAT_a8078840 = 0;
}
