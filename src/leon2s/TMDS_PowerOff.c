/* leon2s TMDS_PowerOff @ 0xa0074cf8 (-mcpu=v8 -Os -g)
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
extern int FUN_a0073044();
extern void FUN_a007381c();
extern void FUN_a0073c24();
extern void FUN_a00a7424();
extern void FUN_a00a7488();

void TMDS_PowerOff(unsigned char param_1, unsigned char param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 param_6)

{
  FUN_a0073c24(param_1,0);
  FUN_a0073044("TMDS_PowerOff  %d  \015\012",param_1);
  FUN_a007381c(param_1,0);
  if (param_2 == '\x01') {
    FUN_a00a7424(1,7,param_1,0x1c04);
    if ((byte)(param_1 - 2U) < 2) {
      FUN_a00a7424(1,7,param_1,0x2c04);
    }
    FUN_a00a7488(param_1,0x1000,0xffffff00,0xf9);
    FUN_a00a7424(1,2,param_1,0x1c04);
    FUN_a00a7424(1,0x10,param_1,0x1c04);
    FUN_a00a7424(1,0x11,param_1,0x1c04);
    FUN_a00a7424(1,0x18,param_1,8000,param_5,param_6);
    return;
  }
  FUN_a00a7424(0,7,param_1,0x1c04);
  if ((byte)(param_1 - 2U) < 2) {
    FUN_a00a7424(0,7,param_1,0x2c04);
  }
  FUN_a00a7488(param_1,0x1000,0xfffffffe,0,param_5,param_6);
  return;
}