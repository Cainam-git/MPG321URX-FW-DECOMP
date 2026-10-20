/* leon2m FUN_a00b83e4 @ 0xa00b83e4-0xa00b848c (42 words), flags -mcpu=v8 -O3 -g.
 * Code facts: if FUN_a0142e8c(0) != 5 (u8): FUN_a00b7f9c(0x15), FUN_a014771c(0), and if the u16 FUN_a0145660(0,
 * 0x16) != 0: byte 0xa802b08e |= 1. Then FUN_a0146dc0(0, 0), FUN_a0146c40(8, 0, 0), byte 0xa802b08f = 0x24,
 * FUN_a0146dc0(0, 1), u16 0xa802cff4+0x3e &= 0x7fff (fw andn 0xffff8000). The b08f store comes before
 * FUN_a0146dc0(0, 1); FUN_a014771c takes one argument (0, fw clr %o0 in the delay slot).
 * Source form: the u16 is field +0x3e of the record DAT_a802cff4 (fw sethi|or of the base).
 * Compiler aids: none.
 */
struct Scff4 { unsigned char pad[0x3e]; unsigned short h03e; };
extern struct Scff4 DAT_a802cff4;
extern unsigned char DAT_a802b08e;
extern unsigned char DAT_a802b08f;
extern void FUN_a00b7f9c(int);
extern unsigned char FUN_a0142e8c(unsigned int);
extern unsigned short FUN_a0145660(unsigned char, unsigned int);
extern void FUN_a0146c40(int, int, int);
extern void FUN_a0146dc0(int, int);
extern void FUN_a014771c(int);

void FUN_a00b83e4(void)
{
  if (FUN_a0142e8c(0) != 5) {
    FUN_a00b7f9c(0x15);
    FUN_a014771c(0);
    if (FUN_a0145660(0, 0x16) != 0)
      DAT_a802b08e |= 1;
  }
  FUN_a0146dc0(0, 0);
  FUN_a0146c40(8, 0, 0);
  DAT_a802b08f = 0x24;
  FUN_a0146dc0(0, 1);
  DAT_a802cff4.h03e &= 0x7fff;
}
