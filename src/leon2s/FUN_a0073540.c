/* leon2s FUN_a0073540 @ 0xa0073540-0xa0073578 (14 words), flags -mcpu=v8 -Os -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp_l2s.py 0 mismatches / 14 words. Twin of FUN_a00a45d8.
 * Code facts: leaf. When mode == 0: word +4 of the record DAT_a80789d4 = word 0xa8076190, then sibcall
 * FUN_a00b2194(&DAT_a80789d4) ('mov %o7,%g1; call; mov %g1,%o7'). Other modes return through a real 'nop' (the bne
 * target) before retl. void.
 * Fix vs the autoc draft: the record is one {w0, w4} struct (the draft used a separate +4 symbol), the callee
 * is named by its address FUN_a00b2194 (no symbol entry yet). Aids: one asm nop on the mode != 0 path (fw real
 * nop, not a delay slot).
 */
struct R { unsigned int w0; unsigned int w4; };
extern struct R DAT_a80789d4;
extern unsigned int _DAT_a8076190;
extern void FUN_a00b2194(struct R *);

void FUN_a0073540(int mode)
{
  if (mode == 0) {
    DAT_a80789d4.w4 = _DAT_a8076190;
    FUN_a00b2194(&DAT_a80789d4);
    return;
  }
  __asm__ volatile ("nop");
}
