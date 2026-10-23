/* leon2s FUN_a00aba4c @ 0xa00aba4c (-mcpu=v8 -Os)
 * Returns bit 0 of the hardware register 0xCF034400 (as 0 or 1).
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
#define _DAT_cf034400 (*(volatile unsigned int *)0xcf034400)

uint FUN_a00aba4c(void)

{
  return _DAT_cf034400 & 1;
}