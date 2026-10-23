/* leon2s FUN_a0078fe8 @ 0xa0078fe8 (-mcpu=v8 -Os -g)
 * Returns 1 when FUN_a00a7468(0x1c, p1 & 0xff, 0x1c04) is non-zero and the u16 FUN_a0074f60(p1) is in 11..0x257 (two
 * calls), else 0. p2 is not used.
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

extern uint FUN_a0074f60(undefined1 param_1);
extern uint FUN_a00a7468(uint param_1, unsigned char param_2, unsigned short param_3);

uint FUN_a0078fe8(uint param_1, uint param_2)
{
    uint uVar1;
    uint uVar2;

    uVar2 = param_1 & 0xff;
    uVar1 = FUN_a00a7468(0x1c, (unsigned char)uVar2, 0x1c04);
    if (uVar1 != 0) {
        if ((unsigned short)FUN_a0074f60((undefined1)param_1) > 10) {
            if ((unsigned short)FUN_a0074f60((undefined1)param_1) <= 0x257) {
                return 1;
            }
        }
    }
    return 0;
}
