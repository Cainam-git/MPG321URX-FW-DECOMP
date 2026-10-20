/* leon2s FUN_a006d050 @ 0xa006d050-0xa006d0fc (43 words incl. the merged unreachable ret/restore
 * tail FUN_a006d0f4), flags -mcpu=v8 -Os -g. jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 * Code facts: init sequence of calls: FUN_a00ad5cc(), FUN_a00b0738(0), FUN_a00b0738(1), FUN_a0089d38(),
 * FUN_a0095ea4(), func_0x9f1cc264(0), func_0x9f1cc214(), func_0x9f1cc264(1), func_0x9f1cc214(),
 * func_0x9f1b6730(), FUN_a0083870(3), FUN_a00a4880(0), FUN_a008fa78(0/1), FUN_a0096ad8(0/1); then
 * FUN_a00b3530(9) == -1 -> tail call FUN_a00734c4(0xa0065c00 = "Reliable Check Error!!\r").
 * Fix vs the autoc draft: the print takes ONE argument (fw sets only %i0 before call+restore; the
 * draft passed a 2nd 0 -> 'clr %i1'); prototype as in the other src/leon2s callers. Aids: none.
 */
typedef unsigned int uint;
typedef unsigned long long undefined8;
typedef unsigned int undefined4;

extern void FUN_a00ad5cc(void);
extern int FUN_a00b0738(int);
extern int FUN_a0089d38(void);
extern void FUN_a0095ea4(void);
extern void func_0x9f1cc264(int);
extern void func_0x9f1cc214(void);
extern void func_0x9f1b6730(void);
extern void FUN_a0083870(int);
extern void FUN_a00a4880(int);
extern void FUN_a008fa78(int);
extern void FUN_a0096ad8(int);
extern int FUN_a00b3530(int);
extern void FUN_a00734c4(unsigned int *);
extern unsigned int DAT_a0065c00; /* "Reliable Check Error!!\r" */

void FUN_a006d050(void)
{
    int iVar1;
    
    FUN_a00ad5cc();
    FUN_a00b0738(0);
    FUN_a00b0738(1);
    FUN_a0089d38();
    FUN_a0095ea4();
    func_0x9f1cc264(0);
    func_0x9f1cc214();
    func_0x9f1cc264(1);
    func_0x9f1cc214();
    func_0x9f1b6730();
    FUN_a0083870(3);
    FUN_a00a4880(0);
    FUN_a008fa78(0);
    FUN_a008fa78(1);
    FUN_a0096ad8(0);
    FUN_a0096ad8(1);
    iVar1 = FUN_a00b3530(9);
    if (iVar1 != -1) {
        return;
    }
    FUN_a00734c4(&DAT_a0065c00);
}
