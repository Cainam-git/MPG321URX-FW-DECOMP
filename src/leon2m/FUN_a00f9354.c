/* leon2m FUN_a00f9354 @ 0xa00f9354  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, permuter)
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
extern int FUN_a00f1a90(int, int);
short FUN_a00f9354(uint param_1)
{
  unsigned char uVar1;
  uint uVar2;
  param_1 = param_1 & 0xff;
  uVar1 = FUN_a00f1a90(param_1 & 0xff, 0x9e);
  ;
  return (uVar1 & 0xff) | ((FUN_a00f1a90(param_1, 0xac) & 0x1f) << 8);
}
