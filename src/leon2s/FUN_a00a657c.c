/* leon2s FUN_a00a657c @ 0xa00a657c (-mcpu=v8 -Os -g)
 * Finished by hand from mechanical Ghidra C. Register read function for one hardware block:
 * returns the low byte of register param_2 of port param_1 (0 or 1; other ports read 0).
 * Address = 0xcf000000 | ((base[port] + reg) * 4), with the per-port 16-bit base table at
 * 0xa00b4d9c. One of seven identical functions, one per block (tables
 * 0xa00b4d40/4d6c/4d7a/4d90/4d94/4d98/4d9c).
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
extern unsigned short DAT_a00b4d9c;

uint FUN_a00a657c(uint param_1, unsigned short param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((param_1 & 0xff) < 2) {
    uVar1 = *(volatile uint *)(((ushort)(&DAT_a00b4d9c)[param_1 & 0xff] + (param_2 & 0xffff)) * 4 |
                     0xcf000000) & 0xff;
  }
  return uVar1;
}