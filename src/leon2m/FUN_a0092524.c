/* leon2m FUN_a0092524 @ 0xa0092524-0xa0092648 (73 words), flags -mcpu=v8 -O3 -g.
 * Code facts: byte 0xa8025c55 = d290[0x1a4]; byte 0xa8025c56 = d290[0x1f] (base DAT_a802d290); if d290[0x1f]
 * == 0: d290[0x8f] = d290[0x19]. FUN_a00b4144((u8)(afec - 2), 2); word 0xa802afec = d290[0x1f] + 0x23; loop
 * (src FUN_a0091668 form, test first): if FUN_a00aa520((u8)(afec - 0x23)) == 1 break; t = (lduh 0xa802afee) -
 * 0x22; t = t % 3; afec = t + 0x23. FUN_a00a813c(0, d290[0x1f], 0); FUN_a00a900c((u8)(afec - 0x23), 1);
 * FUN_a0146c40(6, 0, 0); if afec == 0x23: FUN_a00a9468(1, 3), tail FUN_a00b34d4(0, 4); else FUN_a00a9468(1,
 * 2), tail FUN_a00b34d4(0, 1). void(void). All record bytes are read through the base DAT_a802d290;
 * FUN_a00aa520 takes one argument. Source form: test-first loop. Aids: none.
 */
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a8025c56;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a00b34d4(unsigned int, unsigned int);
extern void FUN_a00b4144(unsigned char, int);
extern void FUN_a0146c40(int, int, int);

void FUN_a0092524(void)
{
  int t;

  DAT_a8025c55 = DAT_a802d290[0x1a4];
  DAT_a8025c56 = DAT_a802d290[0x1f];
  if (DAT_a802d290[0x1f] == 0)
    DAT_a802d290[0x8f] = DAT_a802d290[0x19];
  FUN_a00b4144(_DAT_a802afec - 2, 2);
  _DAT_a802afec = DAT_a802d290[0x1f] + 0x23;
  for (;;) {
    if (FUN_a00aa520(_DAT_a802afec - 0x23) == 1)
      break;
    t = (unsigned short)_DAT_a802afec - 0x22;
    t = t % 3;
    _DAT_a802afec = t + 0x23;
  }
  FUN_a00a813c(0, DAT_a802d290[0x1f], 0);
  FUN_a00a900c(_DAT_a802afec - 0x23, 1);
  FUN_a0146c40(6, 0, 0);
  if (_DAT_a802afec == 0x23) {
    FUN_a00a9468(1, 3);
    FUN_a00b34d4(0, 4);
  } else {
    FUN_a00a9468(1, 2);
    FUN_a00b34d4(0, 1);
  }
}
