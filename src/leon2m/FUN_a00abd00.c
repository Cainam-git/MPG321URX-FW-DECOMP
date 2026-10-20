/* leon2m FUN_a00abd00 @ 0xa00abd00..0xa00abdc8 (200 bytes, 50 words)
 * Flags: -mcpu=v8 -O3 -g.
 * What it does (code facts): step DOWN twin of FUN_a00abff8 on byte 0x13: v = DAT_a802d290[0x13] - 1;
 * v > 100 (wrapped below 0) stores 0, else stores v and redraws with row 8 and FUN_a0146b50(0xe8, 0),
 * then FUN_a00d462c(). Always sets bit 1 of DAT_a802b08e.
 * Callers: no direct 'call 0xa00abd00' in asm/leon2m (reached via a pointer/table).
 * Aids: none. Two code facts make it exact:
 *  - ARM ORDER: the clamp arm first ('if (v > 100) clamp; else { calls }', exact negation of
 *    the draft's 'v <= 100'). With the calls arm first it ends in a jump to the join, the
 *    jump depends on the last %o3/%o4 sets, and sched1 ranks the third FUN_a0146a80 call's
 *    argument sets o3, o4 (more dependents) before o2 (fw: o2, o3, o4): 98.04.
 *  - REAL PROTOTYPES from the callees' asm: FUN_a00b6ec8 is void (plain ret/restore after
 *    a tail call, %i0 not set) with three u8 parameters (all and 0xff); an 'int' return moves
 *    the 0x29 / 6 argument sets of the last call (96.08). FUN_a00ab5f0 (u8 x5, and 0xff on
 *    %i0..%i4), FUN_a0146a80 (u16, u16, u8, u16, u8), FUN_a0146b50 (u16, u8).
 * Same body as FUN_a00abe94 called with flag 1 (0x742 column), plus the save/clamp.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802b08e;
extern void FUN_a00ab5f0(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a00b6ec8(unsigned char, unsigned char, unsigned char);
extern void FUN_a00d462c(void);

void FUN_a00abd00(void)
{
  unsigned char v = DAT_a802d290[0x13] - 1;

  if (v > 100) {
    DAT_a802d290[0x13] = 0;
  } else {
    DAT_a802d290[0x13] = v;
    FUN_a00ab5f0(0x2c, 8, v, 7, 1);
    FUN_a0146a80(0x28, 8, 3, 0x742, 0);
    FUN_a0146a80(0x2b, 8, 1, 0x742, 0);
    FUN_a0146a80(0x32, 8, 1, 0x742, 0);
    FUN_a0146b50(0xe8, 0);
    FUN_a00b6ec8(0x29, 8, DAT_a802d290[0x13]);
    FUN_a00d462c();
  }
  DAT_a802b08e |= 2;
}
