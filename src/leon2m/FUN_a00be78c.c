/* leon2m FUN_a00be78c @ 0xa00be78c (-mcpu=v8 -O3 -g)
 * Stores '0', '0' and byte 0xA802D47D + 0x2F in bytes 7, 8 and 9 of the byte array 0xA802D078, then calls
 * FUN_a00bac3c(0x81), FUN_a00ba950(p1) and FUN_a00babe4(p1, 0xb). Same code as FUN_a00be66c with other constants.
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

extern unsigned char DAT_a802d47d;
extern unsigned char DAT_a802d078[];
extern void FUN_a00bac3c();
extern int FUN_a00ba950();
extern void FUN_a00babe4(undefined1 param_1, undefined1 param_2);

void FUN_a00be78c(byte param_1)
{
    DAT_a802d078[7] = 0x30;
    DAT_a802d078[8] = 0x30;
    DAT_a802d078[9] = (DAT_a802d47d + 0x2f);
    (void)FUN_a00bac3c(0x81);
    (void)FUN_a00ba950(param_1);
    FUN_a00babe4(param_1, 0xb);
    return;
}
