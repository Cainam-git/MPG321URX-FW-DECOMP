/* leon2m FUN_a00a8230 @ 0xa00a8230-0xa00a82c4 (37 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Code facts: twin of FUN_a00b3c80: FUN_a0146b50(0x92, 0); FUN_a0146b6c(0, 0); for i = 0..3: FUN_a00a31a4(0, 0x14,
 * i*2 + 6, 1, FUN_a00a3844(ROM word table 0x19158c, (u16)(i*29 + byte 0xa802d290+8)), 0).
 * Source form: the row loop is a static helper load_rows(tab, reg, n) inlined with (DAT_0019158c, 0x14, 4); the
 * row count is its parameter (fw 'cmp %l0, 4; bcs' at 0xa00a82b0), the table a const pointer parameter. The id-6 arm
 * of FUN_a00b0034 has the same loop with the same compare. Built with -msoft-float as FUN_a00b3c80. The record is a
 * struct, the callee prototypes as in FUN_a00b3c80.
 */
struct St { unsigned char pad[8]; unsigned char b08; };
extern struct St DAT_a802d290;
extern unsigned int DAT_0019158c[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);

static void load_rows(unsigned int *const tab, int reg, unsigned char n)
{
  unsigned char i;

  for (i = 0; i < n; i++)
    FUN_a00a31a4(0, reg, i * 2 + 6, 1, FUN_a00a3844(tab, i * 29 + DAT_a802d290.b08), 0);
}

void FUN_a00a8230(void)
{
  FUN_a0146b50(0x92, 0);
  FUN_a0146b6c(0, 0);
  load_rows(DAT_0019158c, 0x14, 4);
}
