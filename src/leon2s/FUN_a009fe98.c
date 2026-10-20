/* leon2s FUN_a009fe98 @ 0xa009fe98  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
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
extern unsigned char DAT_a807db00;
extern int FUN_a009fe2c();

void FUN_a009fe98(uint param_1)

{
  *(uint *)(*(int *)(&DAT_a807db00 + (param_1 & 0xff) * 0x34) + 0x84) =
       *(uint *)(*(int *)(&DAT_a807db00 + (param_1 & 0xff) * 0x34) + 0x84) | 0x71;
  FUN_a009fe2c(param_1 & 0xff,0xea8a);
  return;
}