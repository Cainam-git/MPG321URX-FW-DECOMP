/* leon2m FUN_a00a8230 @ 0xa00a8230-0xa00a82c4 (37 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Code facts: twin of FUN_a00b3c80: FUN_a0146b50(0x92, 0); FUN_a0146b6c(0, 0); for i = 0..3: FUN_a00a31a4(0, 0x14,
 * i*2 + 6, 1, FUN_a00a3844(ROM word table 0x19158c, (u16)(i*29 + byte 0xa802d290+8)), 0).
 * Source form: built with -msoft-float; at plain -O3 -g this loop form lets loop.c hoist the full &DAT_a802d290.
 * The same code results at plain -O3 -g with the FUN_a00b3c80 'top: ... if (i < n) goto top;' form. The table is
 * the symbol DAT_0019158c, the record a struct, the callee prototypes as in FUN_a00b3c80. The loop bound is a
 * variable 'n = 4' (fw 'cmp %l0, 4; bcs' = LTU 4; a literal 4 is canonicalised to 'cmp 3; bleu' before the
 * constant is known; same form as src/leon2m/FUN_a01387a4.c 'i < n', n = 7).
 * Compiler aids: none.
 */
struct St { unsigned char pad[8]; unsigned char b08; };
extern struct St DAT_a802d290;
extern unsigned int DAT_0019158c[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);

void FUN_a00a8230(void)
{
  unsigned char i;
  unsigned char n = 4;

  FUN_a0146b50(0x92, 0);
  FUN_a0146b6c(0, 0);
  for (i = 0; i < n; i++)
    FUN_a00a31a4(0, 0x14, i * 2 + 6, 1, FUN_a00a3844(DAT_0019158c, i * 29 + DAT_a802d290.b08), 0);
}
