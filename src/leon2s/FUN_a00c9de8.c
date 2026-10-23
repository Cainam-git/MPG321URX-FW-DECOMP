/* leon2s FUN_a00c9de8 @ 0xa00c9de8 (-mcpu=v8 -Os -g)
 * Calls func_0xa0fc15ac(buf, 0, 0x180) on a 384-byte local buffer, then FUN_a00c9d28(p1 & 0xff, buf, 6, p2) and
 * FUN_a00c99a4(p1 & 0xff, buf, 4, 0, p2).
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
extern int FUN_a00c99a4();
extern void FUN_a00c9d28();
extern int func_0xa0fc15ac();

void FUN_a00c9de8(uint param_1, unsigned short param_2)

{
  undefined1 auStack_188 [384];
  
  func_0xa0fc15ac(auStack_188,0,0x180);
  FUN_a00c9d28(param_1 & 0xff,auStack_188,6,param_2 & 0xffff);
  FUN_a00c99a4(param_1 & 0xff,auStack_188,4,0,param_2 & 0xffff);
  return CONCAT44(param_2,param_1) & 0xffff000000ff;
}