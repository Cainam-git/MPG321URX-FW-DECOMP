/* leon2m FUN_a0092b18 @ 0xa0092b18-0xa0092bb4 (39 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 39 words.
 * Code facts (afec % N loop family, src FUN_a0091668 form): FUN_a00b4144((u8)(word 0xa802afec - 2), 2); afec =
 * 0x2a; loop (entered at the test): if FUN_a00aa520((u8)(afec - 0x2a)) == 1 break; t = (lduh 0xa802afee, low
 * half of afec) - 0x29; t = t % 10 (signed, smul 0x66666667, sra 2); afec = t + 0x2a. The test re-loads afec
 * because it has two predecessors. Tail FUN_a00a900c((u8)(afec - 0x2a), 1) (restore %g0,1,%o1). void(void).
 * Fixes vs the autoc draft: loop shape test-first (for(;;) with break), (unsigned short)_DAT_a802afec, 1-arg
 * aa520, real u8/void prototypes. Aids: none.
 */
extern unsigned int _DAT_a802afec;
extern void FUN_a00a900c(unsigned char, int);
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a00b4144(unsigned char, int);

void FUN_a0092b18(void)
{
  int t;

  FUN_a00b4144(_DAT_a802afec - 2, 2);
  _DAT_a802afec = 0x2a;
  for (;;) {
    if (FUN_a00aa520(_DAT_a802afec - 0x2a) == 1)
      break;
    t = (unsigned short)_DAT_a802afec - 0x29;
    t = t % 10;
    _DAT_a802afec = t + 0x2a;
  }
  FUN_a00a900c(_DAT_a802afec - 0x2a, 1);
}
