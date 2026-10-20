/* leon2s FUN_a00b18d0 @ 0xa00b18d0 (-mcpu=v8 -Os -g)
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
#define _DAT_cf0114fc (*(volatile unsigned int *)0xcf0114fc)
extern int FUN_a0072b7c();
extern int FUN_a0073044();
extern int FUN_a0096204();
extern int FUN_a00b17e8();
extern int FUN_a00b18ac();
extern int FUN_a00b1e70();

int FUN_a00b18d0(undefined4 param_1,undefined4 param_2)

{
  FUN_a0096204();
  FUN_a00b17e8();
  FUN_a0072b7c();
  FUN_a00b1e70();
  FUN_a00b18ac();
  FUN_a0073044("\012\015NT68500 Leon2S system compiled under Linux\012\015%s\012\015","SWVERSION");
  _DAT_cf0114fc = _DAT_cf0114fc | 0x80;
  return CONCAT44(param_2,param_1);
}