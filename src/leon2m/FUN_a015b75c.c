/* leon2m FUN_a015b75c @ 0xa015b75c (-mcpu=v8 -Os -g)
 * When bit 9 (0x200) of the halfword at p1 + 0xC is clear, calls FUN_a015ea68(p1 + 0x58). Returns 0.
 * Source form: Ghidra's type and symbol names are kept.
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
extern int FUN_a015ea68();

unsigned int FUN_a015b75c(int param_1,uint param_2)

{
  if ((*(ushort *)(param_1 + 0xc) & 0x200) == 0) {
    FUN_a015ea68(param_1 + 0x58);
  }
  return (ulonglong)param_2 << 0x20;
}