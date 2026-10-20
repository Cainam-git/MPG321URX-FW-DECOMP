/* leon2s FUN_a00ab4a8 @ 0xa00ab4a8 (-mcpu=v8 -Os -g)
 * Finished by hand from mechanical Ghidra C. Twin of FUN_a00ab4f8 (opposite direction). Sets
 * bit param_1 in peripheral register 0xcf013280, clears bits 0 and 3 of 0xcf013290, calls
 * FUN_a00b1794(1) (busy-wait delay: 50 000 nop iterations per unit), then sets bit 0 of 0xcf013284.
 * FUN_a00ab4f8 sets bits 0 and 3 of 0xcf013290 and clears bit 0 of 0xcf013284 instead. The shift
 * count is used unmasked and the function returns nothing (the Ghidra output had a '& 0x1f' and a
 * return value that are not in the code).
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

void FUN_a00ab4a8(uint param_1)

{
  _DAT_cf013280 = _DAT_cf013280 | 1 << param_1;
  _DAT_cf013290 = _DAT_cf013290 & 0xfffffff6;
  FUN_a00b1794(1);
  _DAT_cf013284 = _DAT_cf013284 | 1;
}