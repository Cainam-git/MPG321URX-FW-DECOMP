/* leon2m FUN_a0091668 @ 0xa0091668-0xa0091710 (42 words), flags -mcpu=v8 -O3 -g.
 * afec loop family, test-first variant.
 * Code facts: FUN_a00b4144(word 0xa802afec - 2, 2); word afec = 0xb; loop: break when FUN_a00aa520(afec - 0xb)
 * == 1 (u8, 1 arg), else t = (lduh 0xa802afee) - 10, t %= 3 (smul 0x55555556), afec = t + 0xb. Then
 * FUN_a00a900c(afec - 0xb, 1) and tail FUN_a00aa4c0(afec - 0xb, 1). void(void).
 * FUN_a00aa520 takes afec - 0xb; the tail callee takes 2 arguments.
 * Source form: 'for (;;) { if (call == 1) break; ... }' gives the fw rotated loop ('while (call != 1)' gives other
 * code). Aids: none.
 */
extern unsigned int _DAT_a802afec;
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00aa4c0(unsigned char, int);
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a00b4144(unsigned char, int);

void FUN_a0091668(void)
{
  int t;

  FUN_a00b4144(_DAT_a802afec - 2, 2);
  _DAT_a802afec = 0xb;
  for (;;) {
    if (FUN_a00aa520(_DAT_a802afec - 0xb) == 1)
      break;
    t = (unsigned short)_DAT_a802afec - 10;
    t = t % 3;
    _DAT_a802afec = t + 0xb;
  }
  FUN_a00a900c(_DAT_a802afec - 0xb, 1);
  FUN_a00aa4c0(_DAT_a802afec - 0xb, 1);
}
