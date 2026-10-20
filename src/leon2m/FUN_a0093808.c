/* leon2m FUN_a0093808 @ 0xa0093808-0xa0093884 (31 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 31 words. afec family.
 * Code facts: byte DAT_a802d290 + 0x1a0 = byte 0xa8025c56 (stored in the call delay slot); FUN_a00a93bc(word
 * 0xa802afec - 0x56, u8); FUN_a00a9650(c56 + 1, 0); FUN_a00a813c(1, c56 + 1, 1) (c56 re-read for each call);
 * byte 0xa802afea = d290[0x1a0]; word afec = 0x12; tail FUN_a00a900c(4, 1). void(void).
 * Fix vs the autoc draft: real base DAT_a802d290 (draft DAT_a802d430 word), byte types, the tail takes 2 args
 * (the draft passed four extra params). Aids: none.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802afea;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a0093808(void)
{
  DAT_a802d290[0x1a0] = DAT_a8025c56;
  FUN_a00a93bc(_DAT_a802afec - 0x56);
  FUN_a00a9650(DAT_a8025c56 + 1, 0);
  FUN_a00a813c(1, DAT_a8025c56 + 1, 1);
  DAT_a802afea = DAT_a802d290[0x1a0];
  _DAT_a802afec = 0x12;
  FUN_a00a900c(4, 1);
}
