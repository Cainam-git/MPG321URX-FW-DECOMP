/* leon2m FUN_a00b3c80 @ 0xa00b3c80..0xa00b3d14 (148 bytes, 37 words)
 * Flags: -mcpu=v8 -O3 -g.
 * What it does (code facts): FUN_a0146b50(0x92, 0) and FUN_a0146b6c(0, 0) first, then for i = 0, 1, 2: v =
 * FUN_a00a3844(DAT_00196678, i * 29 + DAT_a802d290.b08) (FUN_a00a3844 returns word [n] of the ROM word table at
 * 0x196678, n as unsigned short) and FUN_a00a31a4(0, 0x16, i * 2 + 6, 1, v, 0). The table address is 0x196678 (fw
 * sethi %hi(0x196400) | 0x278).
 * Callers: FUN_a00b0034.
 * Source form: the loop is a label + 'if (i <= 2) goto top;' (a bottom-tested loop without loop notes): every
 * do/while/for form lets loop.c hoist the full &DAT_a802d290 (sethi + or) out of the loop; the fw hoists only the
 * sethi parts.
 * Compiler aids: none.
 */
struct St { unsigned char pad[8]; unsigned char b08; };
extern struct St DAT_a802d290;
extern unsigned int DAT_00196678[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);

void FUN_a00b3c80(void)
{
  unsigned char i;

  FUN_a0146b50(0x92, 0);
  FUN_a0146b6c(0, 0);
  i = 0;
top:
  FUN_a00a31a4(0, 0x16, i * 2 + 6, 1, FUN_a00a3844(DAT_00196678, i * 29 + DAT_a802d290.b08), 0);
  i++;
  if (i <= 2)
    goto top;
}
