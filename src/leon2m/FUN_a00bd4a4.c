/* leon2m FUN_a00bd4a4 @ 0xa00bd4a4  MATCH (-mcpu=v8 -O3 -g, twin)
 * Twin of FUN_a00bd6e4: same code, constants swapped; byte-exact.
 * See FUN_a00bd6e4 for the explanation; this copy's constants differ, so its comments were removed.
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

extern unsigned char DAT_a802d41a;
extern unsigned char DAT_a802d078[];
extern void FUN_a00bac3c();
extern int FUN_a00ba950();
extern void FUN_a00babe4(undefined1 param_1, undefined1 param_2);

void FUN_a00bd4a4(byte param_1)
{
    unsigned char val = DAT_a802d41a;
    
    DAT_a802d078[7] = 0x30;
    if (val > 9) {
        DAT_a802d078[8] = 0x31;
        DAT_a802d078[9] = (val + 0x26);
    } else {
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (val + 0x30);
    }
    (void)FUN_a00bac3c(0x28);
    (void)FUN_a00ba950(param_1);
    FUN_a00babe4(param_1, 0xb);
    return;
}
