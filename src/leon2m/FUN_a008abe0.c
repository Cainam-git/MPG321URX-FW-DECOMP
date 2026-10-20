/* leon2m FUN_a008abe0 @ 0xa008abe0-0xa008ac00 (8 words), flags -mcpu=v8 -O3 -g.
 * Code facts: v = FUN_a01266b0() (u16, no argument); tail FUN_a008a568(0x15, v) (u8, u16: sll/srl 16 of the
 * return value). void(void). Fix vs the autoc draft (66.67): FUN_a01266b0 takes no arguments (the draft passed
 * param_1/param_2, which only sat in %o0/%o1); real prototypes from src/. Aids: none.
 */
extern unsigned short FUN_a01266b0(void);
extern void FUN_a008a568(unsigned char, unsigned short);

void FUN_a008abe0(void)
{
  FUN_a008a568(0x15, FUN_a01266b0());
}
