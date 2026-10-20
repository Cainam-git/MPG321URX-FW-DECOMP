/* leon2m FUN_a015e408 @ 0xa015e408  MATCH (-mcpu=v8 -O2 -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
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
extern unsigned int _DAT_a802e40c;
extern undefined4 FUN_a015e7e0(undefined4 param_1,int param_2);

int FUN_a015e408(int *param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  _DAT_a802e40c = 0;
  uVar1 = FUN_a015e7e0(param_2,param_3);
  if ((uVar1 == 0xffffffff) && (_DAT_a802e40c != 0)) {
    *param_1 = _DAT_a802e40c;
  }
  return CONCAT44(param_2,uVar1);
}