/* leon2s FUN_a00ac4ec @ 0xa00ac4ec-0xa00ac550 (25 words incl. the merged unreachable ret/restore
 * tail FUN_a00ac548), flags -mcpu=v8 -Os -g. jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 * Code facts: port = arg & 0xff, reg = (u16) arg2, val = arg3 & 0xff; reg < 0x200 -> return; else
 * FUN_a00a6c98(port, 0x30, 0x80, 1) (page bit on), FUN_a00a6c00(port, reg, val), tail call
 * FUN_a00a6c98(port, 0x30, 0x80, 0) (page bit off).
 * Fix vs the autoc draft (96.00): void with three parameters (the draft returned the callee's value
 * and declared K&R callees); real prototypes of FUN_a00a6c00 / FUN_a00a6c98 (u16 reg) as used in
 * FUN_a00ac66c. Aids: none.
 */
extern void FUN_a00a6c00(unsigned int, unsigned short, unsigned int);
extern void FUN_a00a6c98(unsigned int, unsigned short, unsigned int, unsigned int);

void FUN_a00ac4ec(unsigned char port, unsigned short reg, unsigned char val)
{
  if (reg < 0x200)
    return;
  FUN_a00a6c98(port, 0x30, 0x80, 1);
  FUN_a00a6c00(port, reg, val);
  FUN_a00a6c98(port, 0x30, 0x80, 0);
}
