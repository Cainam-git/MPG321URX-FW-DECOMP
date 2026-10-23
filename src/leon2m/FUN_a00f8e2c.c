/* leon2m FUN_a00f8e2c @ 0xa00f8e2c (-mcpu=v8 -Os -g)
 * Code: halfword array 0xA802B7D8[(p1 & 0xff)] = p2.
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
extern undefined2 ARR_a802b7d8[];

void FUN_a00f8e2c(uint param_1,undefined2 param_2)

{
  ARR_a802b7d8[(param_1 & 0xff)] = param_2;
  return;
}