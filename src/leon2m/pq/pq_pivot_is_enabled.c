/* pq_pivot_is_enabled  (FUN_a010a2b0)
 *
 * Return whether picture rotation is switched on.
 * Returns: 0 or 1
 * Name basis: derived - bit 7 of 0xCF01EA40; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010a2b0 @ 0xa010a2b0-0xa010a2cc (28 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the masked value is kept in its own unsigned int local, which keeps the and/cmp/addx sequence.
 */
#define PIVOT_REGISTER (*(volatile unsigned int *)0xcf01ea40)
#define PIVOT_ENABLED_BIT 0x80   /* bit 7: set by pq_pivot_enable for modes 1 and 2, cleared otherwise */

/*
 * Return whether picture rotation is switched on: 1 when bit 7 of 0xCF01EA40 is set, else 0.
 *
 * Nothing calls this routine. The register is also written by pq_pivot_enable (bits 6..7 and 0) and
 * sys_frc_apply_bit_groups (bit 5).
 */
unsigned int pq_pivot_is_enabled(void)
{
    unsigned int pivot_enabled_mask = PIVOT_REGISTER & PIVOT_ENABLED_BIT;
    return pivot_enabled_mask != 0;
}
