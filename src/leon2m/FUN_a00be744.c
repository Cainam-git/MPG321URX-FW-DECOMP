/* leon2m FUN_a00be744 @ 0xa00be744 (-mcpu=v8 -O3 -g)
 * Stores '0', '0' and byte 0xA802D47C + '0' in bytes 7, 8 and 9 of the byte array 0xA802D078, then calls
 * FUN_a00bac3c(0x80), FUN_a00ba950(p1) and FUN_a00babe4(p1, 0xb). Same code as FUN_a00bdcb0 with other constants.
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

extern unsigned char DAT_a802d47c;
extern unsigned char DAT_a802d078[];
extern void FUN_a00bac3c();
extern int FUN_a00ba950();
extern void FUN_a00babe4(undefined1 param_1, undefined1 param_2);

unsigned short FUN_a00be744(byte param_1)
{
    char uVar1;
    DAT_a802d078[7] = 0x30;
    DAT_a802d078[8] = 0x30;
    DAT_a802d078[9] = (DAT_a802d47c + 0x30);
    (void)FUN_a00bac3c(0x80);
    (void)FUN_a00ba950(param_1);
    FUN_a00babe4(param_1, 0xb);
    return;
}
