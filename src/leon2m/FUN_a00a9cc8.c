/* leon2m FUN_a00a9cc8 @ 0xa00a9cc8 (-mcpu=v8 -O3 -g)
 * v = (2 * p + 5) & 0xff; func_0x4008e2a4(); for i = 0..2: FUN_a0146b20(0, 0x27, v + i, 1, 0, 0) and
 * FUN_a0146b20(0, 0x34, v + i, 1, 0, 0); then FUN_a00b32e4(0, 0, 0x796, 0x27, v, 3, 0), FUN_a00b32e4(0, 0, 0x796, 0x34,
 * v, 3, 0), FUN_a0146c40(3, 0, 0) and FUN_a00b3ed0(0, 0, 0, 0).
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
extern void FUN_a00b32e4();
extern int FUN_a00b3ed0();
extern void FUN_a0146b20(undefined1 param_1, undefined2 param_2, undefined2 param_3, undefined1 param_4, undefined1 param_5, undefined1 param_6);
extern int FUN_a0146c40();
extern int func_0x4008e2a4();
void FUN_a00a9cc8(unsigned char param_1)
{
  byte bVar2;
  byte bVar3;
  bVar2 = (param_1 * '\x02') + 5;
  func_0x4008e2a4();
  bVar3 = 0;
  bVar3 = 0;
  do
  {
    FUN_a0146b20(0, 0x27, bVar2 + bVar3, 1, 0, 0);
    FUN_a0146b20(0, 0x34, bVar2 + bVar3, 1, 0, 0);
    bVar3 = bVar3 + 1;
    bVar3 = (uint) bVar3;
  }
  while (bVar3 < 3);
  FUN_a00b32e4(0, 0, 0x796, 0x27, bVar2, 3, 0);
  FUN_a00b32e4(0, 0, 0x796, 0x34, bVar2, 3, 0);
  FUN_a0146c40(3, 0, 0);
  FUN_a00b3ed0(0, 0, 0, 0);
  return;
}
