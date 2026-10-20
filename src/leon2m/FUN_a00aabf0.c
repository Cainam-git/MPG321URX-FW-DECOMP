/* leon2m FUN_a00aabf0 @ 0xa00aabf0-0xa00aacb4 (49 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a0146b50(0x92, 0); FUN_a0146b6c(0, 0); for i = 0..5 (u8): if FUN_a00aa520(i) == 0:
 * FUN_a0146a80(0x14, i*2 + 6, 0xd, 0x292, 0) (fw 'btst 0xff; bne' skips it); then FUN_a00a31a4(0, 0x14, (u16)(i*2
 * + 6), 1, FUN_a00a3844(ROM word table 0x18ca88, (u16)(i*29 + byte 0xa802d290+8)), 0). Same family as
 * FUN_a00b3c80.
 * Source form: the table is the symbol DAT_0018ca88; the loop is the FUN_a00b3c80 label + 'if (i <= 5) goto top;'
 * (bottom-tested loop without loop notes). A for loop gives the same code only with -O3 -g -msoft-float; at plain
 * -O3 -g loop.c hoists the full &DAT_a802d290, while the fw hoists only the sethi.
 * Compiler aids: none.
 */
struct St { unsigned char pad[8]; unsigned char b08; };
extern struct St DAT_a802d290;
extern unsigned int DAT_0018ca88[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a0146a80(unsigned int, unsigned int, unsigned char, unsigned int, unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);

void FUN_a00aabf0(void)
{
  unsigned char i;

  FUN_a0146b50(0x92, 0);
  FUN_a0146b6c(0, 0);
  i = 0;
top:
    if (FUN_a00aa520(i) == 0)
      FUN_a0146a80(0x14, i * 2 + 6, 0xd, 0x292, 0);
    FUN_a00a31a4(0, 0x14, i * 2 + 6, 1, FUN_a00a3844(DAT_0018ca88, i * 29 + DAT_a802d290.b08), 0);
  i++;
  if (i <= 5)
    goto top;
}
