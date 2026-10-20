/* leon2s FUN_a007381c @ 0xa007381c  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern void FUN_a0073638();
extern int FUN_a0073680();
extern int FUN_a0073704();
extern int FUN_a0073738();
extern void FUN_a00a7424();
extern void FUN_a00a7488();

void FUN_a007381c(undefined1 param_1, unsigned char param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  if (param_2 == '\x01') {
    FUN_a00a7424(1,0xd,param_1,0x1f0c);
    FUN_a00a7424(1,0xe,param_1,0x1f0c);
    FUN_a00a7424(1,0x10,param_1,0x1c04);
    FUN_a00a7424(0,0xf,param_1,0x1c04);
    FUN_a00a7424(1,2,param_1,0x1c04);
    FUN_a00a7424(1,7,param_1,0x1c04);
    FUN_a00a7424(0,0x1f,param_1,0x2e5c);
    FUN_a00a7424(1,0x11,param_1,0x1c04);
    FUN_a00a7424(1,0x15,param_1,0x1c00);
    FUN_a00a7424(1,0x1b,param_1,0x1c00);
    FUN_a00a7424(1,0x18,param_1,8000);
    FUN_a00a7424(1,8,param_1,0x3608);
    FUN_a00a7424(1,9,param_1,0x3608);
    FUN_a0073738(param_1);
    FUN_a00a7424(1,0x10,param_1,0x361c);
    FUN_a00a7488(param_1,0x2c34,0xfffff3ff,0x400);
    FUN_a00a7424(1,0x10,param_1,0x2c34);
    FUN_a00a7424(1,0x11,param_1,0x2c34);
    FUN_a00a7424(1,0x12,param_1,0x2c34);
    FUN_a00a7424(1,0x13,param_1,0x2c34);
    FUN_a00a7424(0,0x19,param_1,0x2c34);
    FUN_a00a7424(1,0x12,param_1,0x361c);
    FUN_a0073638(param_1,1,param_3,param_4,param_5,param_6);
    return;
  }
  FUN_a0073680(param_1);
  FUN_a0073704(param_1);
  FUN_a00a7424(0,0xe,param_1,0x1f0c);
  FUN_a00a7424(0,0x10,param_1,0x1c04);
  FUN_a00a7424(0,0xf,param_1,0x1c04);
  FUN_a00a7424(0,2,param_1,0x1c04);
  FUN_a00a7424(0,0x15,param_1,0x1c00);
  FUN_a00a7424(0,0x1b,param_1,0x1c00);
  FUN_a00a7424(1,0x1f,param_1,0x2e5c);
  FUN_a00a7424(0,8,param_1,0x3608);
  FUN_a00a7424(0,9,param_1,0x3608);
  FUN_a00a7424(0,0,param_1,0x361c);
  FUN_a00a7424(0,0x10,param_1,0x361c);
  FUN_a00a7424(0,0x1d,param_1,0x3618);
  FUN_a00a7488(param_1,0x2c34,0xfffff3ff,0);
  FUN_a00a7424(0,0x10,param_1,0x2c34);
  FUN_a00a7424(0,0x11,param_1,0x2c34);
  FUN_a00a7424(0,0x12,param_1,0x2c34);
  FUN_a00a7424(0,0x13,param_1,0x2c34);
  FUN_a00a7424(0,0x14,param_1,0x2c34);
  FUN_a00a7424(1,0x19,param_1,0x2c34);
  FUN_a00a7424(0,0x12,param_1,0x361c);
  FUN_a00a7424(1,0x15,param_1,0x1100);
  FUN_a00a7424(1,0x15,param_1,0x1500);
  FUN_a00a7424(1,0x15,param_1,0x1900,param_5,param_6);
  return;
}