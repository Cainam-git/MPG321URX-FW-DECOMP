/* leon2m FUN_a00bd6e4 @ 0xa00bd6e4 (-mcpu=v8 -O2 -g)
 * Two-digit reply of the 11-byte frame at 0xA802D078: byte 7 = '0'; v = byte 0xA802D41D; v > 9 (unsigned) ->
 * bytes 8, 9 = '1', v + 0x26; else '0', v + 0x30. Then FUN_a00bac3c(0x2b), FUN_a00ba950(port) and
 * FUN_a00babe4(port, 0xb), which sends the 11 bytes (the same body as case 0x2b of FUN_a00bfcc4).
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

extern unsigned char DAT_a802d41d;
extern unsigned char DAT_a802d078[];
extern void FUN_a00bac3c();
extern int FUN_a00ba950();
extern void FUN_a00babe4(undefined1 param_1, undefined1 param_2);

void FUN_a00bd6e4(byte param_1)
{
    unsigned char val = DAT_a802d41d;
    
    DAT_a802d078[7] = 0x30;
    if (val > 9) {
        DAT_a802d078[8] = 0x31;
        DAT_a802d078[9] = (val + 0x26);
    } else {
        DAT_a802d078[8] = 0x30;
        DAT_a802d078[9] = (val + 0x30);
    }
    (void)FUN_a00bac3c(0x2b);
    (void)FUN_a00ba950(param_1);
    FUN_a00babe4(param_1, 0xb);
    return;
}
