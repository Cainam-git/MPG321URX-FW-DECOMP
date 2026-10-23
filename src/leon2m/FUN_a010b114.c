/* leon2m FUN_a010b114 @ 0xa010b114 (-mcpu=v8 -O2 -g)
 * Copies 0x40 bytes from 0x19ADDC into a local buffer (FUN_a013c910, byte copy), then calls FUN_a00f2e98(0x76, 0,
 * 0x40, p1), or with the local buffer instead of p1 when p1 is null.
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
extern int FUN_a00f2e98();
extern int FUN_a013c910();

void FUN_a010b114(undefined1 *param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  undefined1 auStack_48 [64];
  
  FUN_a013c910(auStack_48,0x19addc,0x40);
  puVar1 = param_1;
  if (param_1 == (undefined1 *)0x0) {
    puVar1 = auStack_48;
  }
  FUN_a00f2e98(0x76,0,0x40,puVar1);
  return CONCAT44(param_2,param_1);
}