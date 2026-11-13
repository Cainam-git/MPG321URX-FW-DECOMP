/* sys_ddr_measure_pll  (FUN_a00df5dc)
 *
 * Select a measurement and return the clock value of a memory interface.
 * Returns: value
 * Name basis: descriptive - 24-bit value times 12, shifted right by 17; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00df5dc @ 0xa00df5dc-0xa00df648 (27 words), flags -mcpu=v8 -O3 -g.
 * Source form: the value is assembled with one |= per byte (a single expression gives other register names).
 * The register macros are volatile accesses.
 */
#define CLOCK_SELECT_REG (*(volatile unsigned int *)0xc00d02f4)
/* Register o (0..2) of the triple that starts at 0xCF000000 + 4 * a. */
#define R(a, o) (*(volatile unsigned int *)(((a) << 2) + 0xcf000000 + (o) * 4))

/*
 * Write 1 (sel == 1) or 2 (any other sel) to the register 0xC00D02F4. Then read the registers
 * 0xCF000000 + 4 * a, +4 and +8 as bytes 0, 1 and 2 of a 24-bit value v and return (v * 12) >> 17.
 * sys_ddr_set_pll_value writes the same three registers from a value (value << 17) / 12.
 */
unsigned int sys_ddr_measure_pll(unsigned int a, unsigned int sel)
{
    unsigned int b0, b1, b2, v;

    if (sel == 1)
        CLOCK_SELECT_REG = sel;
    else
        CLOCK_SELECT_REG = 2;
    b0 = R(a, 0);
    b1 = R(a, 1);
    b2 = R(a, 2);
    v = b0;
    v |= b1 << 8;
    v |= b2 << 16;
    return (v * 12) >> 17;
}
