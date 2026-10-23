/* leon2m FUN_a012798c @ 0xa012798c (-mcpu=v8 -O2 -g)
 * Returns func_0x4008d594(halfword 0xA802D89A) as a halfword.
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
extern unsigned short _DAT_a802d89a;
extern int func_0x4008d594();

unsigned short FUN_a012798c(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = (uint)_DAT_a802d89a;
  return func_0x4008d594(uVar1);
}