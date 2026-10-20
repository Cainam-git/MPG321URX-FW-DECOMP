/* leon2m FUN_a0092188 @ 0xa0092188-0xa009221c (37 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 37 words. The afec % N loop family (FUN_a0091de8,
 * FUN_a0092444), here with % 6 and without the FUN_a00aa258 calls.
 * Code facts: FUN_a00a8ee8(word 0xa802afec - 0x18, as u8); loop: t = (lduh 0xa802afee = low half of word
 * 0xa802afec) - 0x17; t = t % 6 (signed, smul by 0x2aaaaaab); word 0xa802afec = t + 0x18; repeat until
 * FUN_a00aa520(t) == 1 (u8 return, 1 arg). FUN_a00a900c(afec - 0x18, 1); tail FUN_a00af44c(0x18, afec - 0x18).
 * void(void). Fix vs the autoc draft: FUN_a00aa520 takes 1 arg (the draft passed the quotient * 2), the half-word
 * read is (unsigned short)_DAT_a802afec, u8/void prototypes. Aids: none.
 */
extern unsigned int _DAT_a802afec;
extern void FUN_a00a8ee8(unsigned char);
extern void FUN_a00a900c(unsigned char, int);
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a00af44c(unsigned char, unsigned char);

void FUN_a0092188(void)
{
  int t;

  FUN_a00a8ee8(_DAT_a802afec - 0x18);
  do {
    t = (unsigned short)_DAT_a802afec - 0x17;
    t = t % 6;
    _DAT_a802afec = t + 0x18;
  } while (FUN_a00aa520(t) != 1);
  FUN_a00a900c(_DAT_a802afec - 0x18, 1);
  FUN_a00af44c(0x18, _DAT_a802afec - 0x18);
}
