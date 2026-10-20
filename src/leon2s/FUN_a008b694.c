/* leon2s FUN_a008b694 @ 0xa008b694 (-mcpu=v8 -Os -g)
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
extern uint FUN_a00a6bb8(uint param_1, unsigned short param_2);
extern void FUN_a00a6c98(uint param_1, uint param_2, uint param_3, uint param_4);
void FUN_a008b694(uint param_1)
{
  uint uVar1;
  int diff;
  uint abs_diff;
  param_1 = param_1 & 0xff;
  uVar1 = FUN_a00a6bb8(param_1, 0x63);
  diff = ((int) (uVar1 & 0xff)) - 0x80;
  abs_diff = ((diff >> 0x1f) ^ diff) - (diff >> 0x1f);
  abs_diff = abs_diff & 0xff;
  if (abs_diff <= 0xf)
  {
    FUN_a00a6c98(param_1, 0x60, 0x20, 0);
  }
  else
  {
    FUN_a00a6c98(param_1, 0x60, 0x20, 1);
  }
  return;
}
