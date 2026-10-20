/* leon2m FUN_a00a493c @ 0xa00a493c-0xa00a49b8 (31 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 31 words.
 * Code facts: v = (u8)(byte DAT_a802d290 + 9 + 1). If v > 100: the byte = 100. Else the byte = byte + 1 (stored in
 * the call delay slot), FUN_a00a45c0(5, 8, v, 0xc), FUN_a00b3708(10, 6, re-read byte), FUN_a00d8cd4(). Then
 * FUN_a00d4998() and byte 0xa802b08e |= 2. void(void).
 * Fix vs the autoc draft: real base DAT_a802d290 (draft DAT_a802d299 as u16), void prototypes; the clamp arm
 * comes first in the source (FUN_a00abff8 lever; the increment arm first swaps %o5/%g1, 80.65). Aids: none.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802b08e;
extern void FUN_a00a45c0(int, int, unsigned char, int);
extern void FUN_a00b3708(int, int, unsigned char);
extern void FUN_a00d4998(void);
extern void FUN_a00d8cd4(void);

void FUN_a00a493c(void)
{
  unsigned char v = DAT_a802d290[9] + 1;

  if (v > 100)
    DAT_a802d290[9] = 100;
  else {
    DAT_a802d290[9] = DAT_a802d290[9] + 1;
    FUN_a00a45c0(5, 8, v, 0xc);
    FUN_a00b3708(10, 6, DAT_a802d290[9]);
    FUN_a00d8cd4();
  }
  FUN_a00d4998();
  DAT_a802b08e |= 2;
}
