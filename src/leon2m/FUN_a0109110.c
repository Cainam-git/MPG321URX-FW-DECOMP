/* leon2m FUN_a0109110 @ 0xa0109110  MATCH (-mcpu=v8 -O2 -g)
 * This function tests a flag byte and sets or clears bit 7 of a control register at 0xcf011aa0. The uncertainty is whether the compiler will generate the exact same branch structure and register usage, particularly the `mov %o4, %o5` in the delay slot and the store through `%o5` in the clear path. The key fix is inverting the if/else order so the `be` branches to the clear case (matching the target's branch to 0xa0109134), and putting the set case as the fall-through.
 */
#define _DAT_cf011aa0 (*(volatile unsigned int *)0xcf011aa0)

void FUN_a0109110(unsigned char param_1)
{
    if (param_1 != 0) {
        _DAT_cf011aa0 = _DAT_cf011aa0 | 0x80;
    } else {
        _DAT_cf011aa0 = _DAT_cf011aa0 & 0xffffff7f;
    }
}
