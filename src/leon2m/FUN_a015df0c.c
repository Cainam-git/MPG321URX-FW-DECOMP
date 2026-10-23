/* leon2m FUN_a015df0c @ 0xa015df0c (-mcpu=v8 -O2 -g)
 * Clears word 0xA802E40C and calls r = FUN_a015e880(p2); when r == -1 and word 0xA802E40C is then nonzero, stores
 * that word at *p1. Returns r.
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
extern unsigned int _DAT_a802e40c;
extern int FUN_a015e880(int param_1);

int FUN_a015df0c(int *param_1,int param_2)

{
  int iVar1;
  
  _DAT_a802e40c = 0;
  iVar1 = FUN_a015e880(param_2);
  if ((iVar1 == -1) && (_DAT_a802e40c != 0)) {
    *param_1 = _DAT_a802e40c;
  }
  return CONCAT44(param_2,iVar1);
}