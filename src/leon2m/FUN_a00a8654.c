/* FUN_a00a8654 (leon2m, 0xa00a8654-0xa00a86e8, 148 bytes, 37 words).
 * Flags: -mcpu=v8 -O3 -g. Judge: jf 100.00 match=True, rawcmp 0/37 mismatches.
 * Code facts: FUN_a0146b50(0x111, 0); FUN_a0146b6c(0, 0); for i = 0..2 (u8):
 * FUN_a00a31a4(0, 0x2a, i*2 + 6, 1, FUN_a00a3844(DAT_00190cec, (u16)(i*29 + byte +8 of the record
 * DAT_a802d290)), 0). Twin of FUN_a00b3c80, same source shape.
 * Fixes vs draft: BEHAVIOUR: the record field is the BYTE at +8 (fw ldub [base+8]; the draft read the
 * u16 DAT_a802d290[4]); FUN_a0146b50 is (u16, u8) void; the loop is a label + 'if (i <= 2) goto top'
 * (a do/while lets loop.c hoist the full record address; fw keeps only the HIGH part outside).
 * Aids: none.
 */
struct St { unsigned char pad[8]; unsigned char b08; };
extern struct St DAT_a802d290;
extern unsigned int DAT_00190cec[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);

void FUN_a00a8654(void)
{
  unsigned char i;

  FUN_a0146b50(0x111, 0);
  FUN_a0146b6c(0, 0);
  i = 0;
top:
  FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_00190cec, i * 29 + DAT_a802d290.b08), 0);
  i++;
  if (i <= 2)
    goto top;
}
