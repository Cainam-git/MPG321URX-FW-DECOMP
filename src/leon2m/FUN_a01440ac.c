/* leon2m FUN_a01440ac @ 0xa01440ac  MATCH (-mcpu=v8 -O2 -g, gcc 3.4.4, permuter)
 * reached byte-exact by tools/permuter.py: decomp-permuter (AST mutations), judged by exact bytes
 */

typedef unsigned char undefined;
typedef unsigned char undefined1;
typedef unsigned char byte;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned short undefined2;
typedef unsigned short ushort;
typedef unsigned short word;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned int ulong;
typedef unsigned int dword;
typedef unsigned int undefined3;
typedef unsigned long long undefined8;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern int FUN_a0129a10();
unsigned char FUN_a01440ac(byte param_1, undefined4 param_2)
{
  int new_var;
  uint uVar1;
  uVar1 = 0xffffffff;
  if (param_1 == 0x61)
  {
    uVar1 = 1;
  }
  else
  {
    new_var = 0x62;
    if (param_1 <= (new_var - 1))
    {
      if (param_1 == 0x51)
      {
        uVar1 = 0;
      }
    }
    else
      if (param_1 == 0x71)
    {
      uVar1 = 2;
    }
    else
      if (param_1 == 0x81)
    {
      uVar1 = 3;
    }
  }
  uVar1 = uVar1 & 0xff;
  return FUN_a0129a10(uVar1);
}
