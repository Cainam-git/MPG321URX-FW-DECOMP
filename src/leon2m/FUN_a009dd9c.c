/* leon2m FUN_a009dd9c @ 0xa009dd9c-0xa009de04 (26 words), flags -mcpu=v8 -O3 -g.
 * Byte-identical twin of FUN_a009dd34.
 * Code facts: the afec % N loop family (FUN_a0091de8 form): FUN_a00a93bc((u8)(afec + 0x4a));
 * then repeat { t = (low halfword of _DAT_a802afec, lduh +2) - 0xb5; t = t % 2 (signed); afec =
 * t + 0xb6 } until FUN_a00aad30((u8)t) returns 1; sibcall FUN_a00a9650((u8)(afec + 0x4a), 1).
 * Fixes vs the autoc draft (53.85): the loop test is on aad30's RETURN (the draft dropped it and
 * re-tested t), aad30 takes t, a9650 takes 2 args, (unsigned short)_DAT_a802afec instead of a
 * separate volatile afee symbol. void(void). Aids: none.
 */
extern unsigned int _DAT_a802afec;
extern void FUN_a00a93bc(unsigned char);
extern unsigned char FUN_a00aad30(unsigned char);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a009dd9c(void)
{
  int t;

  FUN_a00a93bc(_DAT_a802afec + 0x4a);
  do {
    t = (unsigned short)_DAT_a802afec - 0xb5;
    t = t % 2;
    _DAT_a802afec = t + 0xb6;
  } while (FUN_a00aad30(t) != 1);
  FUN_a00a9650(_DAT_a802afec + 0x4a, 1);
}
