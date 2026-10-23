/* leon2s FUN_a008b53c @ 0xa008b53c (-mcpu=v8 -Os -g)
 * v = ((p2 << 17) / 0xC) << 9. Calls FUN_a00a7168(p1, 4, (v / 10000) & 0xff), FUN_a00a7168(p1, 5, (v / 0x271000) &
 * 0xff) and FUN_a00a7168(p1, 6, v / 0x27100000) (bytes 0, 1 and 2 of v / 10000), then FUN_a00a71fc(p1, 2, 4, 0)
 * and FUN_a00a71fc(p1, 7, 0x10, 0).
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
extern void FUN_a00a7168();
extern int FUN_a00a71fc();

void FUN_a008b53c(undefined1 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  uint uVar1;
  
  uVar1 = (uint)(param_2 << 0x11) / 0xc << 9;
  FUN_a00a7168(param_1,4,uVar1 / 10000 & 0xff);
  FUN_a00a7168(param_1,5,uVar1 / 0x271000 & 0xff);
  FUN_a00a7168(param_1,6,uVar1 / 0x27100000);
  FUN_a00a71fc(param_1,2,4,0);
  FUN_a00a71fc(param_1,7,0x10,0,param_5,param_6);
  return;
}