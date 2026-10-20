/* leon2s FUN_a00a146c @ 0xa00a146c-0xa00a14c4 (22 words), flags -mcpu=v8 -Os -g.
 * Code facts: 400-byte records DAT_a807d7e0[port] (smul 0x190): bytes +0xe6 and +0xe7 = 1; when byte +0xe8 == 0:
 * FUN_a009faf0(port, &record[0xbc]); tail FUN_a00a0b98(port, 0x12, 0). void.
 * Fix vs the autoc draft: the stores are in ascending source order e6, e7 (the fw emits e7 first and e6 in the
 * bne delay slot; 1 of 6 orders is exact), flat-array integer index (a struct record gives the other add operand
 * order, 50.00), the tail takes 3 args. Aids: none.
 */
extern unsigned char DAT_a807d7e0[];
extern void FUN_a009faf0(unsigned char, unsigned char *);
extern void FUN_a00a0b98(unsigned char, int, int);

void FUN_a00a146c(unsigned char port)
{
  unsigned int idx = port * 400;
  unsigned char c;

  DAT_a807d7e0[idx + 0xe6] = 1;
  DAT_a807d7e0[idx + 0xe7] = 1;
  c = DAT_a807d7e0[idx + 0xe8];
  if (c == 0)
    FUN_a009faf0(port, &DAT_a807d7e0[idx + 0xbc]);
  FUN_a00a0b98(port, 0x12, 0);
}
