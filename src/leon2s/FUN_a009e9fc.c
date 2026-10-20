/* leon2s FUN_a009e9fc @ 0xa009e9fc (-mcpu=v8 -Os -g)
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
extern byte ARR_a807d650[];

void FUN_a009e9fc(uint param_1)

{
  *(undefined4 *)((param_1 & 0xff) * 0x18 + (int)ARR_a807d650) = 0;
  return;
}