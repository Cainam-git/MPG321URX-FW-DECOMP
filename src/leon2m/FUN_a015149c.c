/* leon2m FUN_a015149c @ 0xa015149c-0xa0151674 (118 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a01241fc(); FUN_a0142418(0, f24) with f24 = bits 24..27 of the word at 0xa802e3d4
 * (fw ldub [rec+4] & 0xf); FUN_a0142418(1, f20) (ld, srl 20, and 0xf); m = top nibble (srl 28,
 * signed char compare: ble). m == 2 / 1 / 3 / other select the (a, b) pattern of four
 * FUN_a0109ad0(i, a) + FUN_a0109b14(i, b) pairs for i = 0..3: (0,1), (1,0), (1,1), (0,0); then
 * FUN_a014e7d0().
 * Source form: the record is DAT_a802e3d0 with the bit-field word at +4, the same union E3D0 as
 * src/leon2m/FUN_a014c7bc.c (f28:4, f24:4, f20:4); not volatile; no read of the word before FUN_a01241fc.
 * FUN_a0142418 declared (u8, u8) void as in FUN_a014c7bc. Aids: none.
 */

extern void FUN_a0109ad0(int, int);
extern void FUN_a0109b14(int, int);
extern unsigned int FUN_a01241fc(void);
extern void FUN_a0142418(unsigned char, unsigned char);
extern void FUN_a014e7d0(void);
struct E3D0bits {
    unsigned int b31:1, b30:1, b29:1, b28:1, b27:1, b26:1, b25:1, b24:1, r0:24;
    unsigned int f28:4, f24:4, f20:4, r1:20;
};
union E3D0 { struct E3D0bits f; unsigned char b[0x30]; };
extern union E3D0 DAT_a802e3d0;
void FUN_a015149c(void)
{
  char uVar1;
  int uVar2;
  FUN_a01241fc();
  FUN_a0142418(0, DAT_a802e3d0.f.f24);
  FUN_a0142418(1, DAT_a802e3d0.f.f20);
  uVar1 = DAT_a802e3d0.f.f28;
  if (uVar1 == 2)
  {
    FUN_a0109ad0(0, 0);
    FUN_a0109b14(0, 1);
    FUN_a0109ad0(1, 0);
    FUN_a0109b14(1, 1);
    FUN_a0109ad0(2, 0);
    uVar2 = 0;
    FUN_a0109b14(2, 1);
    FUN_a0109ad0(3, uVar2);
    FUN_a0109b14(3, 1);
    FUN_a014e7d0();
    return;
  }
  if (uVar1 < 3)
  {
    if (uVar1 == 1)
    {
      FUN_a0109ad0(0, 1);
      FUN_a0109b14(0, 0);
      FUN_a0109ad0(1, 1);
      FUN_a0109b14(1, 0);
      FUN_a0109ad0(2, 1);
      uVar2 = 1;
      FUN_a0109b14(2, 0);
      FUN_a0109ad0(3, uVar2);
      FUN_a0109b14(3, 0);
      FUN_a014e7d0();
      return;
    }
  }
  else
    if (uVar1 == 3)
  {
    FUN_a0109ad0(0, 1);
    FUN_a0109b14(0, 1);
    FUN_a0109ad0(1, 1);
    FUN_a0109b14(1, 1);
    FUN_a0109ad0(2, 1);
    FUN_a0109b14(2, 1);
    uVar2 = 1;
    FUN_a0109ad0(3, uVar2);
    FUN_a0109b14(3, 1);
    FUN_a014e7d0();
    return;
  }
  FUN_a0109ad0(0, 0);
  FUN_a0109b14(0, 0);
  FUN_a0109ad0(1, 0);
  FUN_a0109b14(1, 0);
  FUN_a0109ad0(2, 0);
  FUN_a0109b14(2, 0);
  uVar2 = 0;
  FUN_a0109ad0(3, uVar2);
  FUN_a0109b14(3, 0);
  FUN_a014e7d0();
}
