/* leon2m FUN_a014fe78 @ 0xa014fe78 (-mcpu=v8 -O3 -g)
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
extern unsigned char DAT_a802a49a;
extern unsigned char DAT_a802cc84;
extern unsigned char DAT_a802cc87;
extern unsigned short _DAT_a802a49c;
extern unsigned short _DAT_a802a4b0;
extern unsigned short _DAT_a802a4b2;
extern int FUN_a00df170();
extern int FUN_a011d748();
extern int FUN_a011dd9c();
extern int FUN_a011e6dc();
extern int FUN_a014fbf0();
extern int FUN_a014fd34();

void FUN_a014fe78(unsigned char param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined2 uVar1;
  
  FUN_a011e6dc(DAT_a802a49a);
  if (param_1 == '\x01') {
    FUN_a00df170(0x1a7368);
    FUN_a011d748(0x10,0xff,_DAT_a802a49c,0);
    uVar1 = _DAT_a802a4b2;
    if ((DAT_a802cc87 & 1) != 0) {
      FUN_a011dd9c(0x10,_DAT_a802a4b2);
    }
    if ((DAT_a802cc87 & 2) != 0) {
      FUN_a011dd9c(0x11,uVar1);
    }
    if ((DAT_a802cc87 & 4) != 0) {
      FUN_a011dd9c(0x12,uVar1);
    }
    if ((DAT_a802cc87 & 8) != 0) {
      FUN_a011dd9c(0x13,uVar1);
    }
    if ((DAT_a802cc87 & 0x10) != 0) {
      FUN_a011dd9c(0x14,uVar1);
    }
    if ((DAT_a802cc87 & 0x20) != 0) {
      FUN_a011dd9c(0x15,uVar1);
    }
    if ((DAT_a802cc87 & 0x40) != 0) {
      FUN_a011dd9c(0x16,uVar1);
    }
    FUN_a011dd9c(0x18,_DAT_a802a4b0);
    FUN_a014fbf0(1);
    FUN_a014fd34(DAT_a802cc84,param_2,param_3,param_4,param_5,param_6);
    return;
  }
  FUN_a00df170(0x1a7350);
  uVar1 = _DAT_a802a4b2;
  if ((DAT_a802cc87 & 1) != 0) {
    FUN_a011dd9c(0x10,_DAT_a802a4b2);
  }
  if ((DAT_a802cc87 & 2) != 0) {
    FUN_a011dd9c(0x11,uVar1);
  }
  if ((DAT_a802cc87 & 4) != 0) {
    FUN_a011dd9c(0x12,uVar1);
  }
  if ((DAT_a802cc87 & 8) != 0) {
    FUN_a011dd9c(0x13,uVar1);
  }
  if ((DAT_a802cc87 & 0x10) != 0) {
    FUN_a011dd9c(0x14,uVar1);
  }
  if ((DAT_a802cc87 & 0x20) != 0) {
    FUN_a011dd9c(0x15,uVar1);
  }
  if ((DAT_a802cc87 & 0x40) != 0) {
    FUN_a011dd9c(0x16,uVar1);
  }
  FUN_a014fbf0(0);
  FUN_a014fd34(0,param_2,param_3,param_4,param_5,param_6);
  return;
}