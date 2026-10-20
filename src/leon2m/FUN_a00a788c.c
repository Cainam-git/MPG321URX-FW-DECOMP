/* leon2m FUN_a00a788c @ 0xa00a788c-0xa00a7adc (148 words), flags -mcpu=v8 -O3 -g.
 * Called by FUN_a00b5d10 and FUN_a00b8e7c.
 * Mode 1, 7, 8, 10: x = 0x399a; two columns a/b (7/0xe, or 3/0x12 for mode 1) get FUN_a0146a80(col, 8, 1,
 * 0x792, 0) and FUN_a0146b20(0, col, 8, 1, 0x1a/0x1b, 0). Other modes: x = 0x3e9a, and modes 2..4 and 9 also
 * call FUN_a00b32e4(1, 1, 0x792, 10, 3/0xd, 2, 0x16/0x18). Then six FUN_a00b32e4 calls with x or 0x489a
 * for the rows 0xe, 0xf and 0x10.
 * Source form: x is assigned at the top of each outer arm (the fw computes it before the inner tests),
 * and the mode 2..4 / 9 test is nested inside the outer else.
 */
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a00b32e4(unsigned char, unsigned char, unsigned short, unsigned char, unsigned char, unsigned char, unsigned char);

void FUN_a00a788c(unsigned char param_1)
{
  unsigned short x;
  unsigned char a, b;

  if (param_1 == 1 || param_1 == 7 || param_1 == 8 || param_1 == 10) {
    x = 0x399a;
    a = 7;
    b = 0xe;
    if (param_1 == 1) {
      a = 3;
      b = 0x12;
    }
    FUN_a0146a80(a, 8, 1, 0x792, 0);
    FUN_a0146a80(b, 8, 1, 0x792, 0);
    FUN_a0146b20(0, a, 8, 1, 0x1a, 0);
    FUN_a0146b20(0, b, 8, 1, 0x1b, 0);
  } else {
    x = 0x3e9a;
    if ((unsigned char)(param_1 - 2) < 3 || param_1 == 9) {
      FUN_a00b32e4(1, 1, 0x792, 10, 3, 2, 0x16);
      FUN_a00b32e4(1, 1, 0x792, 10, 0xd, 2, 0x18);
    }
  }
  FUN_a00b32e4(1, 0, x, 4, 0xe, 1, 0x75);
  FUN_a00b32e4(1, 0, 0x489a, 0xd, 0xe, 1, 0x75);
  FUN_a00b32e4(1, 1, x, 3, 0xf, 3, 0x76);
  FUN_a00b32e4(1, 1, 0x489a, 0xc, 0xf, 3, 0x76);
  FUN_a00b32e4(1, 0, x, 4, 0x10, 1, 0x79);
  FUN_a00b32e4(1, 0, 0x489a, 0xd, 0x10, 1, 0x7a);
}
