/* leon2s FUN_a008b8d4 @ 0xa008b8d4 (-mcpu=v8 -Os -g)
 * Finished by hand from mechanical Ghidra C. Returns bit 6 of register 4 of port param_1
 * (read through FUN_a00a6f78), as 0 or 1. Needed the reader's proven unsigned prototype
 * (logical shift).
 * Still needs a real name and proper types.
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
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern unsigned int FUN_a00a6f78(unsigned int, unsigned short);

unsigned char FUN_a008b8d4(uint param_1)

{
  param_1 = param_1 & 0xff;
  return (FUN_a00a6f78(param_1,4) >> 6) & 1;
}