/* leon2s FUN_a00ab4f8 @ 0xa00ab4f8 (-mcpu=v8 -Os -g)
 * Finished by hand from mechanical Ghidra C. Twin of FUN_a00ab4a8 (opposite direction). Sets
 * bit param_1 in peripheral register 0xcf013280, sets bits 0 and 3 of 0xcf013290, calls
 * FUN_a00b1794(1), then clears bit 0 of 0xcf013284.
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
#define _DAT_cf013280 (*(volatile unsigned int *)0xcf013280)
#define _DAT_cf013284 (*(volatile unsigned int *)0xcf013284)
#define _DAT_cf013290 (*(volatile unsigned int *)0xcf013290)
extern int FUN_a00b1794();

void FUN_a00ab4f8(uint param_1)

{
  _DAT_cf013280 = _DAT_cf013280 | 1 << param_1;
  _DAT_cf013290 = _DAT_cf013290 | 9;
  FUN_a00b1794(1);
  _DAT_cf013284 = _DAT_cf013284 & 0xfffffffe;
}