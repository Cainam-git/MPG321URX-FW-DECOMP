/* leon2m FUN_a00be5e8 @ 0xa00be5e8  MATCH (-mcpu=v8 -O2 -g)
 * Writes '0' (0x30) to DAT_a802d078[7], [8] and [9], then calls FUN_a00bac3c(0x77), FUN_a00ba950(param_1) and
 * FUN_a00babe4(param_1, 0xB). The result of FUN_a00ba950 is not used.
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

extern unsigned char DAT_a802d078[];
extern void FUN_a00bac3c();
extern int FUN_a00ba950();
extern void FUN_a00babe4(undefined1 param_1, undefined1 param_2);

void FUN_a00be5e8(byte param_1)
{
    DAT_a802d078[7] = 0x30;
    DAT_a802d078[8] = 0x30;
    DAT_a802d078[9] = 0x30;
    (void)FUN_a00bac3c(0x77);
    (void)FUN_a00ba950(param_1);
    FUN_a00babe4(param_1, 0xb);
    return;
}
