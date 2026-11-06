/* leon2s FUN_a0090dec @ 0xa0090dec (-mcpu=v8 -Os -g)
 * v = FUN_a00a657c(p1, 0x45) & 7. Returns 10 for v = 5, 0xC for v = 6, 0x10 for v = 7 and 8 for v = 0..4
 * (jump table switchdataD_a0090dcc: entries 0..4 = the 8 arm).
 * Source form: Ghidra's type and symbol names are kept. Cases 0..4 set 8 and fall through into the default arm,
 * which sets 8 again: the case labels 0..4 stay in the switch (table from 0, cmp 7), the first store is dead and
 * the arms share one block; a 'case 0..4: default:' label list is merged into the default (table from 5), and
 * a separate 'case 0..4: ... break;' arm leaves the default arm with one predecessor (if-conversion moves its
 * store in front of the range test, bgu instead of bgu,a).
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
extern int FUN_a00a657c();
int FUN_a0090dec(unsigned char param_1)

{
  unsigned char uVar1;
  
  param_1 = FUN_a00a657c(param_1,0x45) & 0xff;
  switch(param_1 & 7) {
  case 5:
    uVar1 = 10;
    break;
  case 6:
    uVar1 = 0xc;
    break;
  case 7:
    uVar1 = 0x10;
    break;
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
    uVar1 = 8;
  default:
    uVar1 = 8;
  }
  return uVar1;
}
