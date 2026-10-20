/* leon2m FUN_a00d1a34 @ 0xa00d1a34-0xa00d1ad4 (40 words), flags -mcpu=v8 -O3 -g.
 * Code facts: c = byte msg[7] (plain ldub, no volatile). c == 1: FUN_a0081ea8(2) when FUN_a0143c14(0) returns 0;
 * c == 0: FUN_a0081ea8(1) when FUN_a0143c14(0) returns non-zero; c == 2: FUN_a0081ea8(3) when FUN_a013ce6c(0)
 * != 1 (the clr %o0 in the first be delay slot is the 0 argument of all three calls; both callees read their
 * u8 %o0). Then FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc) and return 0xe0.
 * Fix vs the autoc draft: BEHAVIOUR: the tests use the callees' RETURN values (the draft tested a constant 0
 * temp), the callees take the 0 arg; u8 message pointer param, no volatile. Aids: none.
 */
extern unsigned char DAT_a802d290[];
extern void FUN_a0081ea8(int);
extern unsigned char FUN_a013ce6c(unsigned char);
extern unsigned char FUN_a0143c14(unsigned char);
extern int FUN_a014aed0(unsigned char, void *, unsigned short, unsigned short);

int FUN_a00d1a34(unsigned char *msg)
{
  unsigned char c = msg[7];

  if (c == 1) {
    if (FUN_a0143c14(0) == 0)
      FUN_a0081ea8(2);
  } else if (c == 0) {
    if (FUN_a0143c14(0) != 0)
      FUN_a0081ea8(1);
  } else if (c == 2) {
    if (FUN_a013ce6c(0) != 1)
      FUN_a0081ea8(3);
  }
  FUN_a014aed0(0x30, DAT_a802d290, 0, 0x1fc);
  return 0xe0;
}
