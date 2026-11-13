/* sys_clear_three_clock_bits  (FUN_a01183c0)
 *
 * Clear bit 0 of three block registers.
 * Name basis: descriptive - 0xCF0129D0, 0xCF012B10 and 0xCF014090; unused
 *
 * Matching notes
 * --------------
 * FUN_a01183c0 (leon2m 0xa01183c0-0xa0118400, 64 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: three read-modify-writes of volatile register macros.
 */
#define REGA (*(volatile unsigned int *)0xcf0129d0)
#define REGB (*(volatile unsigned int *)0xcf012b10)
#define REGC (*(volatile unsigned int *)0xcf014090)

/*
 * Clear bit 0 of the three registers 0xCF0129D0, 0xCF012B10 and 0xCF014090 (read-modify-write each).
 * sys_set_three_clock_bits sets the same bits. Nothing calls this routine.
 */
void sys_clear_three_clock_bits(void)
{
    REGA &= ~1u;
    REGB &= ~1u;
    REGC &= ~1u;
}
