/* leon2m FUN_a00be66c @ 0xa00be66c (-mcpu=v8 -O2 -g)
 * Writes '0' (0x30) to DAT_a802d078[7] and [8] and DAT_a802d479 + 0x2F ('0' - 1) to DAT_a802d078[9], then calls
 * FUN_a00bac3c(0x7D), FUN_a00ba950(param_1) and FUN_a00babe4(param_1, 0xB). Same shape as FUN_a00be5e8. Returns
 * nothing.
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

extern unsigned char DAT_a802d479;
extern unsigned char DAT_a802d078[];
extern void FUN_a00bac3c();
extern int FUN_a00ba950();
extern void FUN_a00babe4(undefined1 param_1, undefined1 param_2);

void FUN_a00be66c(byte param_1)
{
    DAT_a802d078[7] = 0x30;
    DAT_a802d078[8] = 0x30;
    DAT_a802d078[9] = (DAT_a802d479 + 0x2f);
    (void)FUN_a00bac3c(0x7d);
    (void)FUN_a00ba950(param_1);
    FUN_a00babe4(param_1, 0xb);
    return;
}
