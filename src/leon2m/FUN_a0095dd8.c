/* leon2m FUN_a0095dd8 @ 0xa0095dd8-0xa0095e54 (31 words), flags -mcpu=v8 -O3 -g.
 * Code facts: inverts bit 31 of the word at 0xa802d290+0x1f4 (srl 31 / xnor / sll 31 / andn / or = a 1-bit
 * bit-field 'f31 = ~f31'); FUN_a00aa0e8(word 0xa802afec - 0xe, as u8, 1); if byte rec+0x1a4 == 3 and bit 31 is
 * now set (re-read, 'bge' sign test) the byte is cleared; tail FUN_a00d9fdc(2) on every path. void(void).
 * Fix vs the autoc draft (65.62): real base DAT_a802d290 (draft: mid-record words d434/d484); the MSB is a 1-bit
 * bit-field (first field = MSB, big-endian); one tail call after the conditional clear; FUN_a00d9fdc takes 1 arg.
 * Aids: none.
 */
struct R290 { unsigned char pad[0x1a4]; unsigned char b1a4; unsigned char pad2[0x4f]; unsigned int f31 : 1, rest : 31; };
extern struct R290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern void FUN_a00aa0e8(unsigned char, int);
extern void FUN_a00d9fdc(int);

void FUN_a0095dd8(void)
{
  struct R290 *p = &DAT_a802d290;

  p->f31 = ~p->f31;
  FUN_a00aa0e8(_DAT_a802afec - 0xe, 1);
  if (p->b1a4 == 3 && p->f31)
    p->b1a4 = 0;
  FUN_a00d9fdc(2);
}
