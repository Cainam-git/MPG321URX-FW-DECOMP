/* leon2s FUN_a0085dcc @ 0xa0085dcc (-mcpu=v8 -Os -g)
 * Sets bits 0-4 of register 0xCF013280 and writes 0x86, 0x95 and 0x55 to registers 0xCF013284, 0xCF013288 and
 * 0xCF01328C. With k = p1 & 0xff calls FUN_a00ab584(), FUN_a00ab4a8(k) and FUN_a00a78fc(k, r, v) for (r, v) =
 * (0x32, 0), (0x31, 0xd1), (0x35, 0x13), (0x35, 0x91), (0x33, 8); for k == 0 also FUN_a00a7940(0, 0x21, 6, 1) and
 * FUN_a00a78fc(0, 0x31, 0xb). Clears byte 0xA8078A0D.
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
extern unsigned char DAT_a8078a0d;
#define _DAT_cf013280 (*(volatile unsigned int *)0xcf013280)
#define _DAT_cf013284 (*(volatile unsigned int *)0xcf013284)
#define _DAT_cf013288 (*(volatile unsigned int *)0xcf013288)
#define _DAT_cf01328c (*(volatile unsigned int *)0xcf01328c)
extern void FUN_a00a78fc(uint param_1, unsigned short param_2,uint param_3);
extern void FUN_a00a7940();
extern int FUN_a00ab4a8();
extern int FUN_a00ab584();

void FUN_a0085dcc(uint param_1,undefined4 param_2)

{
  uint uVar1;
  
  _DAT_cf013280 = _DAT_cf013280 | 0x1f;
  _DAT_cf013284 = 0x86;
  _DAT_cf013288 = 0x95;
  _DAT_cf01328c = 0x55;
  uVar1 = param_1 & 0xff;
  FUN_a00ab584();
  FUN_a00ab4a8(uVar1);
  FUN_a00a78fc(uVar1,0x32,0);
  FUN_a00a78fc(uVar1,0x31,0xd1);
  FUN_a00a78fc(uVar1,0x35,0x13);
  FUN_a00a78fc(uVar1,0x35,0x91);
  FUN_a00a78fc(uVar1,0x33,8);
  if (uVar1 == 0) {
    FUN_a00a7940(0,0x21,6,1);
    FUN_a00a78fc(0,0x31,0xb);
  }
  DAT_a8078a0d = 0;
  return CONCAT44(param_2,param_1) & 0xffffffff000000ff;
}