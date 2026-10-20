/* leon2m FUN_a0148f4c @ 0xa0148f4c-0xa0148fc0 (29 words), flags -mcpu=v8 -O3 -g.
 * Code facts: cur = byte DAT_a802e3d0 + 3. When cur != the u8 mode: if both are non-zero (two cmp %g0 / addx
 * flags and btst) FUN_a012f1ec(0, 4), else FUN_a0107e44(0, 0x960, 1) and FUN_a012f1ec(0, 2); then the byte =
 * mode. void.
 * Fix vs the autoc draft: real base DAT_a802e3d0 + 3 (draft DAT_a802e3d3), u8 param, void; the both-non-zero
 * arm comes first in the source. Aids: none.
 */
extern unsigned char DAT_a802e3d0[];
extern void FUN_a0107e44(int, int, int);
extern void FUN_a012f1ec(int, int);

void FUN_a0148f4c(unsigned char mode)
{
  unsigned char cur = DAT_a802e3d0[3];

  if (cur != mode) {
    if (cur != 0 && mode != 0)
      FUN_a012f1ec(0, 4);
    else {
      FUN_a0107e44(0, 0x960, 1);
      FUN_a012f1ec(0, 2);
    }
    DAT_a802e3d0[3] = mode;
  }
}
