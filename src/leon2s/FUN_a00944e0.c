/* leon2s FUN_a00944e0 @ 0xa00944e0  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern void FUN_a00a8054();
extern void FUN_a00a80cc();

void FUN_a00944e0(undefined1 param_1)

{
  
  FUN_a00a80cc(param_1,0,0x86,0x80,1);
  FUN_a00a8054(param_1,0,0x88,0xd6);
  FUN_a00a8054(param_1,0,0x56,0x2e);
  FUN_a00a8054(param_1,0,8,0x30);
  FUN_a00a80cc(param_1,0,0x12f,0x80,1);
  FUN_a00a8054(param_1,3,0xbe,0xff);
  FUN_a00a8054(param_1,3,0xbf,0xff);
  FUN_a00a80cc(param_1,0,0x49,0x20,1);
  return;
}