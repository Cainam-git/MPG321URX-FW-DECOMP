/* leon2s FUN_a0074c48 @ 0xa0074c48 (-mcpu=v8 -Os -g)
 * Returns 1 when byte 1 of the 24-byte record (param_1 & 0xFF) of the table at 0xa807cc64 equals 1, else 0. The +1
 * in the index gives the target's ldub [%g1+1].
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

extern unsigned char ARR_a807cc64[];

bool FUN_a0074c48(uint param_1)
{
    return (ARR_a807cc64[(param_1 & 0xff) * 0x18 + 1] ^ 1) == 0;
}
