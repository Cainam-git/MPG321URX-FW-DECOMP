/* leon2s FUN_a0086400 @ 0xa0086400  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern int FUN_a00862e4();

unsigned char FUN_a0086400(uint param_1,uint param_2,undefined4 param_3,char param_4,undefined4 param_5)

{
  param_1 = param_1 & 0xff;
  return FUN_a00862e4(param_1,param_2 & 0xff,param_3,(int)param_4,param_5);
}