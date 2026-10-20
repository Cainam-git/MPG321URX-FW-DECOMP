/* leon2m FUN_a009dc84 @ 0xa009dc84-0xa009dd34 (44 words), flags -mcpu=v8 -O3 -g.
 * Same loop shape as FUN_a009bf48.
 * Code facts: FUN_a00a93bc(word 0xa802afec - 0x44, as u8); loop: t = (lduh 0xa802afee = low half of word
 * 0xa802afec) - 0x43; t = t % 4 (signed); word 0xa802afec = t + 0x44; repeat until FUN_a00aad30(t) == 1.
 * FUN_a00a9650(afec - 0x44, 1); v = byte 0xa8025c56; tail FUN_a00a813c(1, (u8)(v + 2), 0) when
 * afec - 0x46 == v, else FUN_a00a813c(1, (u8)(v + 2), 1) (two tail calls). void(void).
 * Fix vs the autoc draft (67.86): BEHAVIOUR: the 3rd arg is 0 when equal and 1 otherwise (the draft had them
 * swapped); (unsigned short)_DAT_a802afec for the half-word; u8/void prototypes; 'afec - 0x46 == v' with a u8
 * local v (an unsigned int temp for the left side swaps %g1/%i2). Aids: none.
 */
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);

void FUN_a009dc84(void)
{
  int t;

  FUN_a00a93bc(_DAT_a802afec - 0x44);
  do {
    t = (unsigned short)_DAT_a802afec - 0x43;
    t = t % 4;
    _DAT_a802afec = t + 0x44;
  } while (FUN_a00aad30(t) != 1);
  FUN_a00a9650(_DAT_a802afec - 0x44, 1);
  {
    unsigned char v = DAT_a8025c56;
    if (_DAT_a802afec - 0x46 == v)
      FUN_a00a813c(1, v + 2, 0);
    else
      FUN_a00a813c(1, v + 2, 1);
  }
}
