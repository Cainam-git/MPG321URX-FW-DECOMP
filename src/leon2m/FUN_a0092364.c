/* leon2m FUN_a0092364 @ 0xa0092364-0xa0092444 (56 words), flags -mcpu=v8 -O3 -g.
 * Twin of FUN_a0092444 (only the loop constant differs).
 * Code facts: FUN_a00a8ee8(word 0xa802afec - 0x1e); FUN_a00aa01c(same, 0); loop: t = (lduh 0xa802afee, i.e. the
 * low half of word 0xa802afec) - 0x1a; t = t % 5 (signed, smul by 0x66666667); word 0xa802afec = t + 0x1e; repeat
 * until FUN_a00aa520(t) == 1 (u8 return, 1 arg: the quotient in %o1 is only the remainder temp).
 * FUN_a00a900c(afec - 0x1e, 1); FUN_a00aa01c(afec - 0x1e, 1); u = afec - 0x1e; r = FUN_a01445fc(byte 0xa802d2ae);
 * tail FUN_a0146c40(6, 0, 0) if u == r else FUN_a0146c40(6, 1, 0) (crossjumped: two 'mov 6' in the fw).
 * FUN_a01445fc takes byte 0xa802d2ae; FUN_a00aa520 takes one argument.
 * Source form: an if/else of two tail calls (a '!=' argument gives one call); an 'unsigned int r' local gives the
 * fw 'cmp u, r' operand order. Aids: none.
 */
extern unsigned char DAT_a802d2ae;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a8ee8(unsigned char);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00aa01c(unsigned char, int);
extern unsigned char FUN_a00aa520(unsigned char);
extern unsigned char FUN_a01445fc(unsigned char);
extern void FUN_a0146c40(int, int, int);

void FUN_a0092364(void)
{
  int t;

  FUN_a00a8ee8(_DAT_a802afec - 0x1e);
  FUN_a00aa01c(_DAT_a802afec - 0x1e, 0);
  do {
    t = (unsigned short)_DAT_a802afec - 0x1a;
    t = t % 5;
    _DAT_a802afec = t + 0x1e;
  } while (FUN_a00aa520(t) != 1);
  FUN_a00a900c(_DAT_a802afec - 0x1e, 1);
  FUN_a00aa01c(_DAT_a802afec - 0x1e, 1);
  {
    unsigned int u = _DAT_a802afec - 0x1e;
    unsigned int r = FUN_a01445fc(DAT_a802d2ae);
    if (u == r)
      FUN_a0146c40(6, 0, 0);
    else
      FUN_a0146c40(6, 1, 0);
  }
}
