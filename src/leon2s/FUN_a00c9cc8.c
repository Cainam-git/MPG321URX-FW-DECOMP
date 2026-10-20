/* leon2s FUN_a00c9cc8 @ 0xa00c9cc8  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern unsigned int DAT_a807cdb8;
extern void FUN_a00c99a4();
extern int func_0xa0fb7ee0();

void FUN_a00c9cc8(undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_a00c99a4(param_1,0xa807ce48,5,3,0x400);
  FUN_a00c99a4(param_1,&DAT_a807cdb8,0,0,0x400);
  func_0xa0fb7ee0(param_1,0,0);
  func_0xa0fb7ee0(param_1,3,1,param_4,param_5,param_6);
  return;
}