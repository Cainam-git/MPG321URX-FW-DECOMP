/* leon2m FUN_a002d148 @ 0xa002d148 (-mcpu=v8 -Os -g)
 * When the function pointer in word 0xA802B0DC is not null, calls it with 3. Returns p1.
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
extern code *_DAT_a802b0dc;

int FUN_a002d148(undefined4 param_1,undefined4 param_2)

{
  if (_DAT_a802b0dc != (code *)0x0) {
    (*_DAT_a802b0dc)(3);
  }
  return CONCAT44(param_2,param_1);
}