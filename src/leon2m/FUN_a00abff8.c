/* leon2m FUN_a00abff8 @ 0xa00abff8..0xa00ac0c4 (204 bytes, 51 words)
 * Flags: -mcpu=v8 -O3 -g.
 * What it does (code facts): step up: v = DAT_a802d290[0x12] + 1; v > 100 stores 100 (clamp), else stores v and
 * redraws through FUN_a00ab5f0(0x2c, 6, v, 7, 1), three FUN_a0146a80(.., 6, .., 0x742, 0) calls,
 * FUN_a0146b50(0xe6, 0), FUN_a00b6ec8(0x29, 6, DAT_a802d290[0x12]) and FUN_a00d45f8(). Always sets bit 1 of
 * DAT_a802b08e.
 * Callers: no direct 'call 0xa00abff8' in asm/leon2m (reached via a pointer/table).
 * Compiler aids: none. Source form, two points:
 *  - Arm order: the clamp arm first ('if (v > 100) clamp; else { calls }'). With the calls arm first it ends in a
 *    jump to the join, the jump depends on the last %o3/%o4 sets, and sched1 ranks the third FUN_a0146a80 call's
 *    argument sets o3, o4 (more dependents) before o2 (fw: o2, o3, o4).
 *  - Callee prototypes from the callees' asm: FUN_a00b6ec8 is void (plain ret/restore after a tail call, %i0 not
 *    set) with three u8 parameters (all and 0xff); an 'int' return moves the 0x29 / 6 argument sets of the last
 *    call. FUN_a00ab5f0 (u8 x5, and 0xff on %i0..%i4), FUN_a0146a80 (u16, u16, u8, u16, u8), FUN_a0146b50 (u16,
 *    u8).
 * Same body as FUN_a00abe94 called with flag 1 (0x742 column), plus the save/clamp.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802b08e;
extern void FUN_a00ab5f0(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a00b6ec8(unsigned char, unsigned char, unsigned char);
extern void FUN_a00d45f8(void);

void FUN_a00abff8(void)
{
  unsigned char v = DAT_a802d290[0x12] + 1;
  
  if (v > 100) {
      DAT_a802d290[0x12] = 100;
  } else {
      DAT_a802d290[0x12] = v;
      FUN_a00ab5f0(0x2c, 6, v, 7, 1);
      FUN_a0146a80(0x28, 6, 3, 0x742, 0);
      FUN_a0146a80(0x2b, 6, 1, 0x742, 0);
      FUN_a0146a80(0x32, 6, 1, 0x742, 0);
      FUN_a0146b50(0xe6, 0);
      FUN_a00b6ec8(0x29, 6, DAT_a802d290[0x12]);
      FUN_a00d45f8();
  }
  
  DAT_a802b08e |= 2;
}
