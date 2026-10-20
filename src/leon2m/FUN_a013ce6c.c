/* leon2m FUN_a013ce6c @ 0xa013ce6c  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, permuter)
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
extern unsigned char DAT_a802df30;
inline uint *inline_fn(uint arg0)
{
  return (uint *) ((&DAT_a802df30) + ((arg0 & 0xff) * 0x78));
}

uint FUN_a013ce6c(uint param_1)
{
  uint uVar1;
  uVar1 = 0xd;
  if ((param_1 & 0xff) < 4)
  {
    uVar1 = (*inline_fn(param_1)) >> 0x1c;
  }
  return uVar1;
}
