/* FUN_a006d31c (leon2s, 0xa006d31c-0xa006d39c, 128 bytes, 32 words).
 * Flags: -mcpu=v8 -Os -g. Judge: jf 100.00 match=True, rawcmp_l2s 0/32 mismatches.
 * Code facts: init sequence: FUN_a008d690, FUN_a008d70c, FUN_a006d30c, FUN_9f1b1c18,
 * DRV_HDMIRx_Phy_Init (0xa0074bf8), FUN_a008f54c, DRV_HDMI21_RX_Init (0xa00a1cdc), FUN_a00ab8b8(0),
 * FUN_a00ab8b8(1), FUN_a00b1028(0, 1), FUN_a00b1028(1, 1), FUN_a00a47b0(), FUN_a0085ea8(), then a
 * tail call FUN_a0095c30() (restore in the delay slot).
 * Fixes vs draft: FUN_a00a47b0 and FUN_a0095c30 take NO args (fw sets no %o regs before them; the
 * draft passed (1,1) and six pass-through params), so the function has no params. Aids: none.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0
extern void FUN_a008d690(void);
extern void FUN_a008d70c(void);
extern void FUN_a006d30c(void);
extern void FUN_9f1b1c18(void);
extern void DRV_HDMIRx_Phy_Init(void);
extern void FUN_a008f54c(void);
extern void DRV_HDMI21_RX_Init(void);
extern void FUN_a00ab8b8(uint param_1);
extern void FUN_a00b1028(uint param_1, uint param_2);
extern void FUN_a00a47b0(void);
extern void FUN_a0085ea8(void);
extern void FUN_a0095c30(void);

void FUN_a006d31c(void)
{
    uint uVar1;
    uint uVar2;
    FUN_a008d690();
    FUN_a008d70c();
    FUN_a006d30c();
    FUN_9f1b1c18();
    DRV_HDMIRx_Phy_Init();
    FUN_a008f54c();
    DRV_HDMI21_RX_Init();
    FUN_a00ab8b8(0);
    FUN_a00ab8b8(1);
    uVar1 = 0;
    uVar2 = 1;
    FUN_a00b1028(uVar1, uVar2);
    uVar1 = 1;
    FUN_a00b1028(uVar1, uVar2);
    FUN_a00a47b0();
    FUN_a0085ea8();
    FUN_a0095c30();
}
