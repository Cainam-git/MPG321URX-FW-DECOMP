/* leon2m FUN_a00f913c @ 0xa00f913c (-mcpu=v8 -O3 -g)
 * When p3 != 0: prints "ESC[1;35mEnable PrePattern\r\nESC[m" through FUN_a00df170, writes a fixed list of values
 * to registers 0xa4 .. 0x59 of p1 through FUN_a00f1ad4 / FUN_a00f1d48 / FUN_a00f1b5c (0x8c gets p2 | 0x80), sets
 * bit 4 of register 0xCF011400 and calls FUN_a00f1ad4(p1, 0x55, 0xf0). Otherwise calls FUN_a00f1ad4(p1, 0xa4, 0)
 * and FUN_a00f1b5c(p1, 0x94, 0x10, 0), clears bit 4 of register 0xCF011400 and calls FUN_a00f1ad4(p1, 0x55, 0xc0)
 * and FUN_a00f1ad4(p1, 0x8c, 0).
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
#define _DAT_cf011400 (*(volatile unsigned int *)0xcf011400)
extern int FUN_a00df170();
extern void FUN_a00f1ad4();
extern void FUN_a00f1b5c();
extern void FUN_a00f1d48();

void FUN_a00f913c(undefined1 param_1,byte param_2, unsigned char param_3,undefined4 param_4,undefined4 param_5
                 ,undefined4 param_6)

{
  if (param_3 != '\0') {
    FUN_a00df170(0x19a428);
    FUN_a00f1ad4(param_1,0xa4,1);
    FUN_a00f1d48(param_1,0x8d,0xdc);
    FUN_a00f1d48(param_1,0x8f,0x500);
    FUN_a00f1ad4(param_1,0x91,0x14);
    FUN_a00f1ad4(param_1,0x93,0);
    FUN_a00f1ad4(param_1,0x9e,0xd0);
    FUN_a00f1ad4(param_1,0xac,2);
    FUN_a00f1d48(param_1,0x95,0x7bc);
    FUN_a00f1d48(param_1,0x97,0x2ee);
    FUN_a00f1d48(param_1,0xa0,0x2d0);
    FUN_a00f1d48(param_1,0xa2,0x500);
    FUN_a00f1b5c(param_1,0x94,0x10,1);
    FUN_a00f1ad4(param_1,0x8c,param_2 | 0x80);
    FUN_a00f1d48(param_1,0x57,0x13f);
    FUN_a00f1d48(param_1,0x59,0x2ed);
    _DAT_cf011400 = _DAT_cf011400 | 0x10;
    FUN_a00f1ad4(param_1,0x55,0xf0,param_4,param_5,param_6);
    return;
  }
  FUN_a00f1ad4(param_1,0xa4,0);
  FUN_a00f1b5c(param_1,0x94,0x10,0);
  _DAT_cf011400 = _DAT_cf011400 & 0xffffffef;
  FUN_a00f1ad4(param_1,0x55,0xc0);
  FUN_a00f1ad4(param_1,0x8c,0,param_4,param_5,param_6);
  return;
}