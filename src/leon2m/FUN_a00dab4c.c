/* leon2m FUN_a00dab4c @ 0xa00dab4c  MATCH (-mcpu=v8 -O2 -g, gcc 3.4.4, autoc)
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
extern void FUN_a01278e4(undefined1 param_1);
extern void FUN_a01278fc(undefined1 param_1);
extern void FUN_a0127914(undefined1 param_1);
extern void FUN_a01279e8(undefined1 param_1);
extern void FUN_a0143d98(void);

void FUN_a00dab4c(uint param_1,undefined4 param_2)

{
  if ((param_1 & 0xff) != 0) {
    return CONCAT44(param_2,param_1);
  }
  FUN_a01278e4(1);
  FUN_a0127914(0);
  FUN_a01278fc(1);
  FUN_a01279e8(1);
  return FUN_a0143d98();
}