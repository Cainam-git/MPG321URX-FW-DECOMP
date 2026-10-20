/* leon2m FUN_a0093754 @ 0xa0093754-0xa0093808 (45 words), flags -mcpu=v8 -O3 -g.
 * afec family, sibling of FUN_a0093808.
 * Code facts: FUN_a00a93bc(byte 0xa8025c56 + 1); FUN_a00a813c(1, c56 + 1, 0); FUN_a00a9650(word 0xa802afec -
 * 0x56, 0); FUN_a00a813c(1, DAT_a802d290[0x1a0] + 1, 0); byte 0xa802afea = d290[0x1a0]; FUN_a00a813c(1,
 * d290[0x1a0] + 1, 1); word afec = 0x12; FUN_a00a900c(4, 1); byte 0xa802b08e |= 2. Every byte is re-read for
 * each use. void(void). The record base is DAT_a802d290; afea is a byte; void/u8 prototypes. Aids: none.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802afea;
extern unsigned char DAT_a802b08e;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a0093754(void)
{
  FUN_a00a93bc(DAT_a8025c56 + 1);
  FUN_a00a813c(1, DAT_a8025c56 + 1, 0);
  FUN_a00a9650(_DAT_a802afec - 0x56, 0);
  FUN_a00a813c(1, DAT_a802d290[0x1a0] + 1, 0);
  DAT_a802afea = DAT_a802d290[0x1a0];
  FUN_a00a813c(1, DAT_a802d290[0x1a0] + 1, 1);
  _DAT_a802afec = 0x12;
  FUN_a00a900c(4, 1);
  DAT_a802b08e |= 2;
}
