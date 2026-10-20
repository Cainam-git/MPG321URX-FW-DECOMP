/* leon2m FUN_a0115644 @ 0xa0115644-0xa0115684 (16 words).
 * Sets bit 7 of hardware register 0xcf011f80, then sets bit 0 of the same register when on is non-zero and clears
 * it when on is zero (two separate read-modify-writes of the volatile register). The zero case is written
 * first; with the arms swapped GCC inverts the branch and the block order.
 * Callers: FUN_a0147d70 (twice) and FUN_a0150df8.
 */
#define REG_cf011f80 (*(volatile unsigned int *)0xcf011f80)

void FUN_a0115644(unsigned char on)
{
    REG_cf011f80 |= 0x80;
    if (on == 0)
        REG_cf011f80 &= ~1;
    else
        REG_cf011f80 |= 1;
}
