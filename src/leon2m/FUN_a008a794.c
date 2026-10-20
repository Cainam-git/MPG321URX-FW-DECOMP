/* leon2m FUN_a008a794 @ 0xa008a794-0xa008a878 (57 words incl. the merged unreachable ret/restore FUN_a008a870), flags -mcpu=v8 -O3 -g.
 * Twin of FUN_a008a878.
 * Code facts: ROM table DAT_00100242 of 3-byte records {x, y, w} indexed by byte 0xa802afbd (add/add = *3,
 * [base + off] and +1/+2). FUN_a0146a80(x, y, w, 0x790, 0) for the old index; index = afbd - 1, when <= 0xc it wraps to 0x1a;
 * FUN_a0146a80(x, y, w, 0x90, 0) for the new index. Then the index maps to byte 0xa802d2a1 (3 -> 2, 9 -> 3, 0xc / 0x14 -> 1, 6 -> 0) followed by the
 * tail call FUN_a00d9764() (void(void)); the 0-store path has its own clrb + tail call. Any other index ends in a
 * real 'nop' before ret/restore. void(void).
 * Fix vs the autoc draft: one 3-byte record table symbol, void prototypes (d9764 takes no args). A switch gives a
 * jump table (54.10); the if-chain with the nested '!= 0xc { == 6 ... != 0x14 }' block gives the fw compare
 * order and the shared 'mov 1' block. Aids: one asm nop on the fall-out path (fw real nop, not a delay slot).
 */
struct pos { unsigned char x, y, w; };
extern struct pos DAT_00100242[];
extern unsigned char DAT_a802afbd;
extern unsigned char DAT_a802d2a1;
extern void FUN_a00d9764(void);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);

void FUN_a008a794(void)
{
  unsigned char v;

  FUN_a0146a80(DAT_00100242[DAT_a802afbd].x, DAT_00100242[DAT_a802afbd].y, DAT_00100242[DAT_a802afbd].w, 0x790, 0);
  DAT_a802afbd--;
  if (DAT_a802afbd < 0xd)
    DAT_a802afbd = 0x1a;
  FUN_a0146a80(DAT_00100242[DAT_a802afbd].x, DAT_00100242[DAT_a802afbd].y, DAT_00100242[DAT_a802afbd].w, 0x90, 0);
  if (DAT_a802afbd == 3)
    v = 2;
  else if (DAT_a802afbd == 9)
    v = 3;
  else {
    if (DAT_a802afbd != 0xc) {
      if (DAT_a802afbd == 6) {
        DAT_a802d2a1 = 0;
        FUN_a00d9764();
        return;
      }
      if (DAT_a802afbd != 0x14) {
        __asm__ volatile ("nop");
        return;
      }
    }
    v = 1;
  }
  DAT_a802d2a1 = v;
  FUN_a00d9764();
}
