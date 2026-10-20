/* FUN_a0091f14 (leon2s, 0xa0091f14-0xa0092064, 336 bytes, 84 words).
 * Flags: -mcpu=v8 -Os -g.
 * Colour depth set-up. port = (u8)param_1; FUN_a0091ef0(port, 0); r12f = reg 0x12f & ~0x78, r4a = reg 0x4a
 * & 0x1f (FUN_a00a7fd8(port, 0, reg)). By (u8)param_2: 8 -> print "- 8bit_Depth", 0x12f = (r12f | 0x20) &
 * 0xa7, 0x4a = r4a, FUN_a0091ef0(port, 0); 10 -> "- 10bit_Depth", 0x28 / 0xaf, r4a | 0x40,
 * FUN_a0091ef0(port, 1); 12 -> "- 12bit_Depth", 0x30 / 0xb7, r4a | 0x80, FUN_a0091ef0(port, 1); other ->
 * "- 8bit_Depth default" with the 8-bit values. Writes via FUN_a00a8054(port, 0, reg, v).
 * The print FUN_a00734c4 takes one argument (the strings have no format; the firmware sets only %o0); the
 * strings are the symbols DAT_a0068e90/ea8/ec0/ed8.
 */
typedef unsigned char undefined, undefined1, byte, uchar;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern unsigned int FUN_a00734c4(const char *param_1);
extern const char DAT_a0068e90[], DAT_a0068ea8[], DAT_a0068ec0[], DAT_a0068ed8[];
extern void FUN_a0091ef0(undefined1 param_1,undefined1 param_2);
extern int FUN_a00a7fd8();
extern void FUN_a00a8054();

void FUN_a0091f14(uint param_1, int param_2)

{
  uint uVar1;
  unsigned char uVar2;
  undefined1 uVar3;
  
  uVar3 = (undefined1)param_1;
  FUN_a0091ef0(uVar3,0);
  uVar1 = FUN_a00a7fd8(uVar3,0,0x12f) & 0xffffff87;
  uVar2 = FUN_a00a7fd8(uVar3,0,0x4a) & 0x1f;
  
  if ((param_2 & 0xff) == 8) {
    FUN_a00734c4(DAT_a0068e90);
    FUN_a00a8054(uVar3,0,0x12f,(uVar1 | 0x20) & 0xa7);
    FUN_a00a8054(uVar3,0,0x4a,uVar2);
    FUN_a0091ef0(uVar3,0);
  }
  else if ((param_2 & 0xff) == 10) {
    FUN_a00734c4(DAT_a0068ea8);
    FUN_a00a8054(uVar3,0,0x12f,(uVar1 | 0x28) & 0xaf);
    FUN_a00a8054(uVar3,0,0x4a,uVar2 | 0x40);
    FUN_a0091ef0(uVar3,1);
  }
  else if ((param_2 & 0xff) == 12) {
    FUN_a00734c4(DAT_a0068ec0);
    FUN_a00a8054(uVar3,0,0x12f,(uVar1 | 0x30) & 0xb7);
    FUN_a00a8054(uVar3,0,0x4a,uVar2 | 0x80);
    FUN_a0091ef0(uVar3,1);
  }
  else {
    FUN_a00734c4(DAT_a0068ed8);
    FUN_a00a8054(uVar3,0,0x12f,(uVar1 | 0x20) & 0xa7);
    FUN_a00a8054(uVar3,0,0x4a,uVar2);
    FUN_a0091ef0(uVar3,0);
  }
  return;
}
