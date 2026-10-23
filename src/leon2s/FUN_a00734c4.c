/* leon2s FUN_a00734c4 @ 0xa00734c4 (-mcpu=v8 -Os -g)
 * Code: FUN_a0061280(p1); returns (ulonglong)p2 << 0x20.
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
extern int FUN_a0061280();

unsigned int FUN_a00734c4(undefined4 param_1,uint param_2)

{
  FUN_a0061280(param_1);
  return (ulonglong)param_2 << 0x20;
}