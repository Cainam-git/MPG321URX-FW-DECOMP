/* leon2s FUN_a00c7d5c @ 0xa00c7d5c  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern void func_0xa0fb8054();

void FUN_a00c7d5c(undefined1 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  ushort uVar1;
  
  func_0xa0fb8054(param_1,0,0xfe,0x19);
  func_0xa0fb8054(param_1,0,0xfe,0xa2);
  uVar1 = 0;
  func_0xa0fb8054(param_1,0,0xfe,0xc4);
  func_0xa0fb8054(param_1,0,0xfc,0);
  do {
    func_0xa0fb8054(param_1,0,0xfc,*(undefined1 *)(param_2 + (uint)uVar1));
    uVar1 = uVar1 + 1;
  } while (uVar1 < 5);
  func_0xa0fb8054(param_1,0,0xfc,0);
  func_0xa0fb8054(param_1,0,0xfc,0);
  func_0xa0fb8054(param_1,0,0xfc,0xa8);
  uVar1 = 0;
  do {
    func_0xa0fb8054(param_1,0,0xfc,*(undefined1 *)(param_3 + (uint)uVar1));
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x118);
  uVar1 = 0;
  do {
    func_0xa0fb8054(param_1,0,0xfc,0);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 5);
  uVar1 = 0;
  do {
    func_0xa0fb8054(param_1,0,0xfc,0);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 2);
  uVar1 = 0;
  do {
    func_0xa0fb8054(param_1,0,0xfc,0);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 8);
  uVar1 = 0;
  do {
    func_0xa0fb8054(param_1,0,0xfc,0);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 2);
  uVar1 = 0;
  do {
    func_0xa0fb8054(param_1,0,0xfc,0);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 8);
  uVar1 = 0;
  do {
    func_0xa0fb8054(param_1,0,0xfc,0);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 2);
  uVar1 = 0;
  do {
    func_0xa0fb8054(param_1,0,0xfc,0);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 4);
  func_0xa0fb8054(param_1,0,0xfe,0x19);
  func_0xa0fb8054(param_1,0,0xfe,0x4c);
  func_0xa0fb8054(param_1,0,0xfe,0x2a,param_5,param_6);
  return;
}