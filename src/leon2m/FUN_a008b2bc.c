/* leon2m FUN_a008b2bc @ 0xa008b2bc-0xa008b330 (29 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a0146b50(0xdc, 0); then three FUN_a00a31a4(0, x, 10, n, str, 0) draws with
 * (x, n, str) = (1, 3, 0x100320), (3, 3, 0x100318), (6, 4, 0x100310); the last one is a tail call.
 * Fix vs the autoc draft (79.31): 0x100320/0x100318/0x100310 are SYMBOL addresses (ROM data, each
 * with its own sethi + %lo reloc in the fw; plain constants share one HIGH), named s_00100320 etc.;
 * callee prototypes from src/leon2m/FUN_a008b83c.c. Aids: none.
 */
extern const char s_00100320[], s_00100318[], s_00100310[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, const char *, unsigned char);

void FUN_a008b2bc(void)
{
  FUN_a0146b50(0xdc, 0);
  FUN_a00a31a4(0, 1, 10, 3, s_00100320, 0);
  FUN_a00a31a4(0, 3, 10, 3, s_00100318, 0);
  FUN_a00a31a4(0, 6, 10, 4, s_00100310, 0);
}
