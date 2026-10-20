/* leon2m FUN_a0086ac8 @ 0xa0086ac8-0xa0086ae8 (8 words), flags -mcpu=v8 -O3 -g.
 * Code facts: returns (u16)(FUN_a0147724() - t0): elapsed ticks since t0 (FUN_a0147724 returns a u16, its asm
 * ends in srl 16). One parameter.
 * Fix vs the autoc draft (75.00): BEHAVIOUR - the draft returned FUN_a0147724() unchanged (the 'sub %o0, %i0'
 * of the parameter was dropped). Aids: none.
 */
extern unsigned short FUN_a0147724(void);

unsigned short FUN_a0086ac8(unsigned int t0)
{
    return FUN_a0147724() - t0;
}
