/* leon2m FUN_a0099e44 @ 0xa0099e44-0xa0099f20 (55 words), flags -mcpu=v8 -O3 -g.
 * Code facts: word 0xa802afec == 0xb8 -> clear bit 29 of the word at 0xa802d290+0x1dc; == 0xb9 -> set it (both
 * arms out of line). FUN_a00a93bc(byte 0xa8025c56 + 0x48, as u8); FUN_a00a813c(1, byte 0xa8025c56, 0);
 * word 0xa802afec = 0x34; FUN_a00a9650(bit 29 of rec+0x1dc, 0); FUN_a00a813c(1, bit 29 re-read, 1);
 * FUN_a00a900c(afec - 0x34, 1); FUN_a00a9468(1, 2); FUN_a00b34d4(0, 1); tail FUN_a00daae8() (no args).
 * The record base is DAT_a802d290; the tail call takes no arguments; u8/void prototypes. Aids: none.
 */
struct R290 { unsigned char pad[0x1dc]; unsigned int w1dc; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00b34d4(unsigned int, unsigned int);
extern void FUN_a00daae8(void);

void FUN_a0099e44(void)
{
  if (_DAT_a802afec == 0xb8)
    DAT_a802d290.w1dc &= ~0x20000000;
  else if (_DAT_a802afec == 0xb9)
    DAT_a802d290.w1dc |= 0x20000000;
  FUN_a00a93bc(DAT_a8025c56 + 0x48);
  FUN_a00a813c(1, DAT_a8025c56, 0);
  _DAT_a802afec = 0x34;
  FUN_a00a9650(DAT_a802d290.w1dc >> 29 & 1, 0);
  FUN_a00a813c(1, DAT_a802d290.w1dc >> 29 & 1, 1);
  FUN_a00a900c(_DAT_a802afec - 0x34, 1);
  FUN_a00a9468(1, 2);
  FUN_a00b34d4(0, 1);
  FUN_a00daae8();
}
