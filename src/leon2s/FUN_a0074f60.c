/* leon2s FUN_a0074f60 @ 0xa0074f60  MATCH (-mcpu=v8 -Os -g)
 * For the port byte p: FUN_a00a7488(p, 0x1f00, 0xfff0ffff, 0x40000) and FUN_a00a7488(p, 0x1f00, 0x00ffffff,
 * 0x1000000) (results discarded), the delay FUN_a00b160c(5), then returns (FUN_a00a7314(p, 0x1f04) >> 8) & 0x1fff.
 * p = param_1 & 0xff is computed once and kept in %l0 across the calls.
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

extern void FUN_a00a7488(uint param_1, undefined2 param_2, uint param_3, uint param_4);
extern void FUN_a00b160c(unsigned int param_1);
extern uint FUN_a00a7314(uint param_1, uint param_2);

uint FUN_a0074f60(undefined1 param_1)
{
  uchar local = param_1 & 0xff;
  FUN_a00a7488(local, 0x1f00, 0xfff0ffff, 0x40000);
  FUN_a00a7488(local, 0x1f00, 0xffffff, 0x1000000);
  FUN_a00b160c(5);
  return (FUN_a00a7314(local, 0x1f04) >> 8) & 0x1fff;
}
