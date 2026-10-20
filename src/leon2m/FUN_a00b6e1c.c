/* leon2m FUN_a00b6e1c @ 0xa00b6e1c-0xa00b6ec0 (41 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a0146b50(0x111, 0); FUN_a0146b6c(0, 0); for i = 0..4 (u8): FUN_a00a31a4(0, 0x2a, i*2 + 6, 1,
 * FUN_a00a3844(ROM word table 0x194b34, (u16)(i*29 + byte 0xa802d290+8)), 0); then tail FUN_a00a813c(1, low 4 bits
 * of u16 0xa802d290+0x34, 1). Family of FUN_a00b3c80 / FUN_a00aabf0.
 * Source form: the low nibble is a 4-bit bit-field of the u16 at +0x34 (fw lduh + and 0xf; the mask form '& 0xf'
 * into the u8 parameter lets combine narrow the load to ldub +0x35); one record DAT_a802d290 (the fw hoists the
 * full address into %l0, which a plain for loop gives); table DAT_00194b34.
 * Compiler aids: none.
 */
struct St { unsigned char pad[8]; unsigned char b08; unsigned char pad2[0x2b]; struct { unsigned short hi : 12, lo : 4; } h34; };
extern struct St DAT_a802d290;
extern unsigned int DAT_00194b34[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);
extern void FUN_a00a813c(int, unsigned char, int);

void FUN_a00b6e1c(void)
{
  unsigned char i;

  FUN_a0146b50(0x111, 0);
  FUN_a0146b6c(0, 0);
  for (i = 0; i <= 4; i++)
    FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_00194b34, i * 29 + DAT_a802d290.b08), 0);
  FUN_a00a813c(1, DAT_a802d290.h34.lo, 1);
}
