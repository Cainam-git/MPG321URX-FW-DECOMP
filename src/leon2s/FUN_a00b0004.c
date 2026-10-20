/* leon2s FUN_a00b0004 @ 0xa00b0004-0xa00b0078 (29 words), flags -mcpu=v8 -Os -g.
 * Code facts: q = (u8)FUN_a00add48(port, (u8)func_0x9f1c6624(port)) (ROM call); when the u8 'on' is set:
 * FUN_a00a8400(q, 0, 0x10, 1) then tail FUN_a00a8400(q, 0, 0x80, 0); else FUN_a00a8400(q, 0, 0x10, 0) then
 * tail FUN_a00a8400(q, 0, 0x80, 1) (the two tails share one 'call; restore' after per-arm %i1..%i3 set-up).
 * void. Fix vs the autoc draft: void, the 0x80 write takes the inverse constant per arm, u8 prototypes.
 * Aids: none.
 */
extern void FUN_a00a8400(unsigned char, unsigned char, unsigned short, unsigned char);
extern unsigned char FUN_a00add48(unsigned char, unsigned char);
extern unsigned char func_0x9f1c6624(unsigned char);

void FUN_a00b0004(unsigned char port, unsigned char on)
{
  unsigned char q = FUN_a00add48(port, func_0x9f1c6624(port));

  if (on) {
    FUN_a00a8400(q, 0, 0x10, 1);
    FUN_a00a8400(q, 0, 0x80, 0);
  } else {
    FUN_a00a8400(q, 0, 0x10, 0);
    FUN_a00a8400(q, 0, 0x80, 1);
  }
}
