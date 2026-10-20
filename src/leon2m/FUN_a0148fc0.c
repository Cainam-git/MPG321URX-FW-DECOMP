/* leon2m FUN_a0148fc0 @ 0xa0148fc0 (-mcpu=v8 -O2 -g)
 * Sets bits 28..31 of the word at 0xa802e3d4 to param_1, then calls FUN_a012f1ec(n, 2) for n = 0..3. The word is
 * accessed as member +4 of a struct at 0xa802e3d0, which gives the target's base + 4 addressing.
 */
struct regs {
  unsigned int pad0;
  unsigned int value;
};
extern struct regs _DAT_a802e3d0;
extern void FUN_a012f1ec();

void FUN_a0148fc0(int param_1)
{
  _DAT_a802e3d0.value = (_DAT_a802e3d0.value & 0x0fffffff) | (param_1 << 28);
  FUN_a012f1ec(0, 2);
  FUN_a012f1ec(1, 2);
  FUN_a012f1ec(2, 2);
  FUN_a012f1ec(3, 2);
}
