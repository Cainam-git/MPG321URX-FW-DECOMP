/* leon2m FUN_a00abe94 @ 0xa00abe94  MATCH (-mcpu=v8 -O2 -g)
 * Computes off = 0x742 when the low byte b of param_1 is non-zero and 0x792 when it is zero, and reads the byte s
 * at 0xA802D2A2 (pointer 0xA802D290 + 0x12). Calls FUN_a00ab5f0(0x2C, 6, s, 7, b), FUN_a0146a80(0x28, 6, 3, off, 0),
 * FUN_a0146a80(0x2B, 6, 1, off, 0), FUN_a0146a80(0x32, 6, 1, off, 0) and FUN_a0146b50(0xE6, 0), and returns
 * FUN_a00b6ec8(0x29, 6, s) as a tail call (restore %g0, 6, %o1 in the delay slot). FUN_a00ab5f0 is declared
 * without a prototype and called with 5 arguments.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();

extern void FUN_a00ab5f0();
extern void FUN_a0146a80(undefined2 param_1, undefined2 param_2, undefined1 param_3, undefined2 param_4, undefined1 param_5);
extern void FUN_a0146b50(undefined2 param_1, undefined1 param_2);
extern int FUN_a00b6ec8(uint param_1, uint param_2, undefined1 param_3);

int FUN_a00abe94(int param_1)
{
    unsigned char b;
    unsigned short uVar1;
    unsigned char *p;
    
    b = (unsigned char)param_1;
    uVar1 = ((b != '\0') - 1 & 0x50) + 0x742;
    p = (unsigned char *)0xa802d290;
    FUN_a00ab5f0(0x2c, 6, p[0x12], 7, b);
    FUN_a0146a80(0x28, 6, 3, uVar1, 0);
    FUN_a0146a80(0x2b, 6, 1, uVar1, 0);
    FUN_a0146a80(0x32, 6, 1, uVar1, 0);
    FUN_a0146b50(0xe6, 0);
    return FUN_a00b6ec8(0x29, 6, p[0x12]);
}
