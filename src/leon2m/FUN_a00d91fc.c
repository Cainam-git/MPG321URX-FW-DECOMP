/* leon2m FUN_a00d91fc @ 0xa00d91fc (-mcpu=v8 -O2 -g)
 * When p1 == 1 calls FUN_a01249ec(0, 0, p3, p4, p5, p6); otherwise FUN_a0124a08(), FUN_a01248ac() and
 * FUN_a014512c(0, 0, p3, p4, p5, p6).
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
extern void FUN_a01248ac(void);
extern void FUN_a01249ec();
extern void FUN_a0124a08(void);
extern int FUN_a014512c();

void FUN_a00d91fc(unsigned char param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  if (param_1 == '\x01') {
    FUN_a01249ec(0,0,param_3,param_4,param_5,param_6);
    return;
  }
  FUN_a0124a08();
  FUN_a01248ac();
  FUN_a014512c(0,0,param_3,param_4,param_5,param_6);
  return;
}