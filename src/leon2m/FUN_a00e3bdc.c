/* leon2m FUN_a00e3bdc @ 0xa00e3bdc (-mcpu=v8 -O2)
 * Mechanical Ghidra C, finished by hand: error path is an early return -1; FUN_a00df80c takes no args; built -O2 without -g; Ghidra's type names are kept.
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
extern int FUN_a00df170();
extern int FUN_a00df80c();
extern int FUN_a00dfc50();
extern void FUN_a00dffb4();
extern void FUN_a00e05d8();
extern int FUN_a00e0bc0();
extern int FUN_a00e321c();
extern int FUN_a00e3524();
extern int FUN_a00e3880();

int FUN_a00e3bdc(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  
  FUN_a00dffb4(3,param_1,param_4);
  FUN_a00dfc50(param_1,param_2,param_3);
  if (2 < param_4) {
    FUN_a00df80c();
    FUN_a00e0bc0();
    FUN_a00df170(0x1997a8,param_4);
    return -1;
  }
  {
    if (param_4 == 1) {
      FUN_a00e3524(param_1,param_2,param_3);
    }
    else if ((int)param_4 < 2) {
      if (param_4 == 0) {
        FUN_a00e321c(param_1,param_2,param_3);
      }
    }
    else if (param_4 == 2) {
      FUN_a00e3880(param_1,param_2,param_3);
    }
    FUN_a00e05d8(param_1,0x1c0,0xf2,2);
    FUN_a00e05d8(param_1,0x1c0,0xf2,0x82);
    FUN_a00e05d8(param_1,0x1c0,0xf2,0x92);
    FUN_a00e05d8(param_1,0x1c0,0xf2,0x12);
    FUN_a00e05d8(param_1,0x1c0,0xf2,0x52);
    FUN_a00e05d8(param_1,0x1c0,0xf2,0x72);
    FUN_a00e05d8(param_1,0x1c0,0xf2,0x62);
    FUN_a00e05d8(param_1,0x1c0,0xf2,0x42);
    FUN_a00e05d8(param_1,0x1c0,0xf2,2);
    FUN_a00e05d8(param_1,0x1c0,0xf2,0);
    FUN_a00e05d8(param_1,0x1e1,0xf2,2);
    FUN_a00e05d8(param_1,0x1e1,0xf2,0x42);
    FUN_a00e05d8(param_1,0x1e1,0xf2,0x52);
    FUN_a00e05d8(param_1,0x1e1,0xf2,0x72);
    FUN_a00e05d8(param_1,0x1e1,0xf2,0x62);
    FUN_a00e05d8(param_1,0x1e1,0xf2,0x22);
    FUN_a00e05d8(param_1,0x1e1,0xf2,0x32);
    FUN_a00e05d8(param_1,0x1e1,0xf2,0x12);
    FUN_a00e05d8(param_1,0x1e1,0xf2,2);
    FUN_a00e05d8(param_1,0x1e1,0xf2,0x82);
    FUN_a00e05d8(param_1,0x1e1,0xf2,0x92);
    FUN_a00e05d8(param_1,0x1e1,0xf2,2);
    FUN_a00e05d8(param_1,0x1e1,0xf2,0);
    FUN_a00e05d8(param_1,0x215,0xf2,2);
    FUN_a00e05d8(param_1,0x215,0xf2,0x42);
    FUN_a00e05d8(param_1,0x215,0xf2,0x52);
    FUN_a00e05d8(param_1,0x215,0xf2,0x72);
    FUN_a00e05d8(param_1,0x215,0xf2,0x62);
    FUN_a00e05d8(param_1,0x215,0xf2,0x22);
    FUN_a00e05d8(param_1,0x215,0xf2,0x32);
    FUN_a00e05d8(param_1,0x215,0xf2,0x12);
    FUN_a00e05d8(param_1,0x215,0xf2,2);
    FUN_a00e05d8(param_1,0x215,0xf2,0x82);
    FUN_a00e05d8(param_1,0x215,0xf2,0x92);
    FUN_a00e05d8(param_1,0x215,0xf2,2);
    FUN_a00e05d8(param_1,0x215,0xf2,0);
  }
  return 0;
}