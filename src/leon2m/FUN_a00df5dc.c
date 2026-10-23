/* leon2m FUN_a00df5dc @ 0xa00df5dc-0xa00df648 (27 words).
 * Writes 1 (sel == 1) or 2 (any other sel) to the register 0xc00d02f4, then reads the registers
 * 0xcf000000 + 4 * a, 0xcf000004 + 4 * a and 0xcf000008 + 4 * a as the bytes 0, 1 and 2 of a 24-bit value v
 * and returns (v * 12) >> 17. FUN_a00df648 writes the same three registers from (value << 17) / 12.
 * Source form: v is assembled with one |= per byte (one expression gives other register names).
 */
#define SEL (*(volatile unsigned int *)0xc00d02f4)
#define R(a, o) (*(volatile unsigned int *)(((a) << 2) + 0xcf000000 + (o) * 4))

unsigned int FUN_a00df5dc(unsigned int a, unsigned int sel)
{
    unsigned int b0, b1, b2, v;

    if (sel == 1)
        SEL = sel;
    else
        SEL = 2;
    b0 = R(a, 0);
    b1 = R(a, 1);
    b2 = R(a, 2);
    v = b0;
    v |= b1 << 8;
    v |= b2 << 16;
    return (v * 12) >> 17;
}
