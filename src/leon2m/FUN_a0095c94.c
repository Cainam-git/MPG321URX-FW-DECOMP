/* leon2m FUN_a0095c94 @ 0xa0095c94-0xa0095d5c (50 words), flags -mcpu=v8 -O3 -g.
 * Code facts (afec % 5 loop family): FUN_a00a93bc((u8)(word 0xa802afec - 0x4e)); loop t = (lduh 0xa802afee,
 * low half of afec) - 0x4d; t = t % 5 (signed, smul 0x66666667); afec = t + 0x4e; until FUN_a00aad30((u8)(t -
 * 5)) == 1 (BEHAVIOUR: the argument is t - 5, the fw 'add %o4,-5'). Then byte DAT_a802d290[0x15b] (0xa802d3eb)
 * = afec - 0x4e (stb in the call delay slot), FUN_a00d9120(void), FUN_a00a9650((u8)(afec - 0x4e), 1); v = byte
 * 0xa8025c56; tail FUN_a00a813c(1, v, afec - 0x4e != v) as two calls. void(void). Twins: FUN_a0095bcc (-0x4a)
 * / FUN_a0095c94 (-0x4d). Fixes vs the autoc draft: aad30 takes 1 arg, (unsigned short)_DAT_a802afec, real
 * base DAT_a802d290. Aids: none.
 */
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d290[];
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);
extern void FUN_a00d9120(void);

void FUN_a0095c94(void)
{
  int t;

  FUN_a00a93bc(_DAT_a802afec - 0x4e);
  do {
    t = (unsigned short)_DAT_a802afec - 0x4d;
    t = t % 5;
    _DAT_a802afec = t + 0x4e;
  } while (FUN_a00aad30(t - 5) != 1);
  DAT_a802d290[0x15b] = _DAT_a802afec - 0x4e;
  FUN_a00d9120();
  FUN_a00a9650(_DAT_a802afec - 0x4e, 1);
  {
    unsigned char v = DAT_a8025c56;
    if (_DAT_a802afec - 0x4e == v)
      FUN_a00a813c(1, v, 0);
    else
      FUN_a00a813c(1, v, 1);
  }
}
