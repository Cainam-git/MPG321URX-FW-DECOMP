/* leon2s FUN_a0085b14 @ 0xa0085b14 (-mcpu=v8 -Os -g)
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
extern void FUN_a00a78fc();
extern void FUN_a00a7940();

void FUN_a0085b14(undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_a00a7940(param_1,0x28,8,0);
  FUN_a00a78fc(param_1,0x21,0x31);
  FUN_a00a78fc(param_1,7,0x30);
  FUN_a00a78fc(param_1,0x22,4);
  FUN_a00a78fc(param_1,0x23,0x32);
  FUN_a00a78fc(param_1,0x24,0x96,param_4,param_5,param_6);
  return;
}