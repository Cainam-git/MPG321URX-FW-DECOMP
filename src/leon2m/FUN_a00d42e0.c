/* leon2m FUN_a00d42e0 @ 0xa00d42e0 (-mcpu=v8 -O2 -g)
 * k = p1 & 0xff; calls FUN_a0145808(k, 0xb, FUN_a0145660(k, 0xb) & 0xffff, 1).
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
extern int FUN_a0145660();
extern int FUN_a0145808();

void FUN_a00d42e0(uint param_1)

{
  unsigned short uVar1;
  
  param_1 = param_1 & 0xff;
  uVar1 = FUN_a0145660(param_1,0xb);
  FUN_a0145808(param_1,0xb,uVar1 & 0xffff,1);
  return;
}