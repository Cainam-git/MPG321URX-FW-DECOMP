/* leon2s FUN_a009270c @ 0xa009270c-0xa00927a0 (37 words), flags -mcpu=v8 -Os -g.
 * Code facts: base ARR_a807d580 (0x1c-byte records: sll 3, sub, sll 2), u16 at +0x18. If the u8 'on' is set
 * (btst 0xff): FUN_a00a8054(p, 2, 1, low byte of h18 = ldub +0x19), FUN_a00a8054(p, 2, 2, h18 >> 8),
 * FUN_a00a80cc(p, 2, 0xbd, 1, 1). Then tail FUN_a00a80cc(p, 2, 0, 3, 1 or 0): two calls in C, cross-jumped into
 * one sibcall with %i4 = 1 / clr %i4. void (the caller value is the callee's).
 * Fix vs the autoc draft: real base ARR_a807d580 (draft ARR_a807d598 + 24/25), the last arg is a constant in each
 * arm (not 'on != 0'), the record is indexed directly (a local record pointer moves the head schedule). Aids: none.
 */
struct rec { unsigned char pad[0x18]; unsigned short h18; unsigned char pad2[2]; };
extern struct rec ARR_a807d580[];
extern void FUN_a00a8054(unsigned char, unsigned char, unsigned short, unsigned char);
extern void FUN_a00a80cc(unsigned char, unsigned char, unsigned short, unsigned char, unsigned char);
void FUN_a009270c(unsigned char p, unsigned char on)
{

  if (on) {
    FUN_a00a8054(p, 2, 1, ARR_a807d580[p].h18);
    FUN_a00a8054(p, 2, 2, ARR_a807d580[p].h18 >> 8);
    FUN_a00a80cc(p, 2, 0xbd, 1, 1);
    FUN_a00a80cc(p, 2, 0, 3, 1);
  } else
  FUN_a00a80cc(p, 2, 0, 3, 0);
}
