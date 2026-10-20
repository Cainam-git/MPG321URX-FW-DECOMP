/* leon2m FUN_a0091f58 @ 0xa0091f58-0xa0092044 (59 words).
 * Calls FUN_a00b4144(afec - 2, 2) with afec = word 0xa802afec, sets afec to 0x1a when FUN_a00d7d48
 * returns non-zero, else to 0x19 when the word 0xa802d3ac (offset 0x11c of the block at 0xa802d290) is negative or
 * when the word 0xa802d340 (offset 0xb0) is non-zero and FUN_a00d8bd8 returns non-zero, else to 0x18, and while
 * FUN_a00aa520(afec - 0x18) does not return 1 steps it forwards through 0x18..0x1d: t = ((low halfword of afec) - 23)
 * % 6, afec = t + 0x18. Then FUN_a00a900c(afec - 0x18, 1). Same loop as FUN_a0091668.
 */
extern unsigned int _DAT_a802afec;
extern void FUN_a00a900c(unsigned char, int);
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a00b4144(unsigned char, int);
extern int FUN_a00d7d48(void);
extern unsigned char FUN_a00d8bd8(void);
struct G290 { unsigned char pad0[0xb0];
unsigned int w0b0;
unsigned char pad1[0x11c - 0xb4];
int w11c;
};
extern struct G290 DAT_a802d290;

void FUN_a0091f58(void)
{
  int t;

  FUN_a00b4144(_DAT_a802afec - 2, 2);
  if (FUN_a00d7d48() != 0)
    _DAT_a802afec = 0x1a;
  else if (DAT_a802d290.w11c < 0)
    _DAT_a802afec = 0x19;
  else if (DAT_a802d290.w0b0 != 0 && FUN_a00d8bd8())
    _DAT_a802afec = 0x19;
  else
    _DAT_a802afec = 0x18;
  for (;;) {
    if (FUN_a00aa520(_DAT_a802afec - 0x18) == 1)
      break;
    t = (unsigned short)_DAT_a802afec - 23;
    t = t % 6;
    _DAT_a802afec = t + 0x18;
  }
  FUN_a00a900c(_DAT_a802afec - 0x18, 1);
}
