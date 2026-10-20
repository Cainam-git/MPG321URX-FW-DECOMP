/* leon2m FUN_a013dbcc @ 0xa013dbcc  (hand; same compile unit as FUN_a013dc6c, which calls it)
 * Looks up the port class code of a port (FUN_a00fd820) and, for the four known codes 0x51 / 0x61 / 0x71 / 0x81,
 * fetches the 16-byte record of class 0..3 with FUN_a0139040 into a stack buffer and copies it to *out (8 halfwords).
 * Any other code: nothing is written. param_2 is not used (dc6c passes its buffer pointer there).
 * Form: every case has its OWN call + copy; gcc's cross-jumping merges the four copies
 * into one call block before block reordering, and the merged block's summed frequency gives the fw case-tree layout
 * (> 0x61 subtree inline, 0x51 leaf out of line). The one-call form 'v = k; break; ... call(v)' gives the
 * other layout. Flags -mcpu=v8 -O3 -g (-msoft-float: same object). jf 100 match=True, rawcmp 0 / 40 words.
 */
struct S16 { unsigned short h[8]; };
extern unsigned char FUN_a00fd820(unsigned char);
extern void FUN_a0139040(int, struct S16 *);

void FUN_a013dbcc(unsigned char param_1, unsigned int param_2, struct S16 *param_3)
{
  struct S16 buf;

  switch (FUN_a00fd820(param_1)) {
  case 0x51:
    FUN_a0139040(0, &buf);
    *param_3 = buf;
    break;
  case 0x61:
    FUN_a0139040(1, &buf);
    *param_3 = buf;
    break;
  case 0x71:
    FUN_a0139040(2, &buf);
    *param_3 = buf;
    break;
  case 0x81:
    FUN_a0139040(3, &buf);
    *param_3 = buf;
    break;
  }
}
