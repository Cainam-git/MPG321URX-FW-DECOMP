/* leon2m FUN_a0148aa8 @ 0xa0148aa8 (-mcpu=v8 -O2 -g)
 * This function masks the input parameter to a byte, logs it via a trace function, sets bit 31 of a global based on the LSB of the parameter, then calls another function with the global's address and constant 1. The main uncertainty is whether the final call's second parameter should be `1` (from `restore %g0, 1, %o1`) or something else - the assembly clearly shows the constant 1 being loaded into the delay slot.
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
extern unsigned int _DAT_a802e1a0;
extern int FUN_a00df170();
extern void FUN_a0153970();

void FUN_a0148aa8(unsigned char param_1,undefined4 param_2)

{
  FUN_a00df170(0x1a6f28,param_1 & 0xff);
  _DAT_a802e1a0 = _DAT_a802e1a0 & 0x7fffffff | param_1 << 0x1f;
  FUN_a0153970(&_DAT_a802e1a0,1);
  return;
}
