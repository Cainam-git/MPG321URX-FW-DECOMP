/* leon2m FUN_a0091de8 @ 0xa0091de8-0xa0091ea0 (46 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 46 words. Twin of FUN_a0091ea0 (only the loop constant differs);
 * same shape as FUN_a0092444 / FUN_a009bf48.
 * Code facts: FUN_a00a8ee8(word 0xa802afec - 0x15, as u8); FUN_a00aa258(same, 0); loop: t = (lduh 0xa802afee =
 * low half of word 0xa802afec) - 0x13; t = t % 3 (signed, smul by 0x55555556); word 0xa802afec = t + 0x15;
 * repeat until FUN_a00aa520(t) == 1 (u8, 1 arg). FUN_a00a900c(afec - 0x15, 1); FUN_a00aa258(afec - 0x15, 1);
 * tail FUN_a00af44c(0x15, afec - 0x15). void(void).
 * Fix vs the autoc draft: FUN_a00aa520 takes 1 arg (the draft passed the quotient, which is only the remainder
 * temp); the half-word read is (unsigned short)_DAT_a802afec; u8/void prototypes. Aids: none.
 */
extern unsigned int _DAT_a802afec;
extern void FUN_a00a8ee8(unsigned char);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00aa258(unsigned char, int);
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a00af44c(unsigned char, unsigned char);

void FUN_a0091de8(void)
{
  int t;

  FUN_a00a8ee8(_DAT_a802afec - 0x15);
  FUN_a00aa258(_DAT_a802afec - 0x15, 0);
  do {
    t = (unsigned short)_DAT_a802afec - 0x13;
    t = t % 3;
    _DAT_a802afec = t + 0x15;
  } while (FUN_a00aa520(t) != 1);
  FUN_a00a900c(_DAT_a802afec - 0x15, 1);
  FUN_a00aa258(_DAT_a802afec - 0x15, 1);
  FUN_a00af44c(0x15, _DAT_a802afec - 0x15);
}
