/* ldc_hw_load_curve_first  (FUN_a00f9a00)
 *
 * Copy the first 17-point curve into its 12-bit register fields.
 * Name basis: descriptive - halfwords at 0xA8027A52 to 0xD0040110..0xD0040130
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f9a00 @ 0xa00f9a00, flags -mcpu=v8 -O3 -g.
 * Source form: the first field is set through a small static helper, set_field(v, bits, clear) =
 * (v | bits) & ~clear, which the compiler inlines; written as one expression per register. Written any other
 * way, the registers are assigned differently.
 */

#define CURVE_POINTS    17
#define CURVE_LOW_MASK  0xfff           /* even point: bits 0..11 of the register */
#define CURVE_HIGH_MASK 0xfff0000       /* odd point: bits 16..27 of the register */
#define CURVE_HIGH_SHIFT 16
#define REG(a) (*(volatile unsigned int *)(a))

extern unsigned short ldc_first_curve[CURVE_POINTS];

/* Return (v | bits) & ~clear. */
static unsigned int set_field(unsigned int v, unsigned int bits, unsigned int clear)
{
    return (v | bits) & ~clear;
}

/*
 * Copy the 17 halfwords of ldc_first_curve into 12-bit fields of nine grid block registers from 0xd0040110 in steps of 4:
 * register k (k = 0..7) takes point 2k in bits 0..11 and point 2k + 1 in bits 16..27, register 8 takes point
 * 16 in bits 0..11. The other bits keep their value; each register is read once and written once. Called by ldc_hw_init and
 * ldc_hw_command.
 */
void ldc_hw_load_curve_first(void)
{
    REG(0xd0040110) = set_field(REG(0xd0040110) & ~CURVE_LOW_MASK, ldc_first_curve[0] & CURVE_LOW_MASK, CURVE_HIGH_MASK) | ((ldc_first_curve[1] << CURVE_HIGH_SHIFT) & CURVE_HIGH_MASK);
    REG(0xd0040114) = set_field(REG(0xd0040114) & ~CURVE_LOW_MASK, ldc_first_curve[2] & CURVE_LOW_MASK, CURVE_HIGH_MASK) | ((ldc_first_curve[3] << CURVE_HIGH_SHIFT) & CURVE_HIGH_MASK);
    REG(0xd0040118) = set_field(REG(0xd0040118) & ~CURVE_LOW_MASK, ldc_first_curve[4] & CURVE_LOW_MASK, CURVE_HIGH_MASK) | ((ldc_first_curve[5] << CURVE_HIGH_SHIFT) & CURVE_HIGH_MASK);
    REG(0xd004011c) = set_field(REG(0xd004011c) & ~CURVE_LOW_MASK, ldc_first_curve[6] & CURVE_LOW_MASK, CURVE_HIGH_MASK) | ((ldc_first_curve[7] << CURVE_HIGH_SHIFT) & CURVE_HIGH_MASK);
    REG(0xd0040120) = set_field(REG(0xd0040120) & ~CURVE_LOW_MASK, ldc_first_curve[8] & CURVE_LOW_MASK, CURVE_HIGH_MASK) | ((ldc_first_curve[9] << CURVE_HIGH_SHIFT) & CURVE_HIGH_MASK);
    REG(0xd0040124) = set_field(REG(0xd0040124) & ~CURVE_LOW_MASK, ldc_first_curve[10] & CURVE_LOW_MASK, CURVE_HIGH_MASK) | ((ldc_first_curve[11] << CURVE_HIGH_SHIFT) & CURVE_HIGH_MASK);
    REG(0xd0040128) = set_field(REG(0xd0040128) & ~CURVE_LOW_MASK, ldc_first_curve[12] & CURVE_LOW_MASK, CURVE_HIGH_MASK) | ((ldc_first_curve[13] << CURVE_HIGH_SHIFT) & CURVE_HIGH_MASK);
    REG(0xd004012c) = set_field(REG(0xd004012c) & ~CURVE_LOW_MASK, ldc_first_curve[14] & CURVE_LOW_MASK, CURVE_HIGH_MASK) | ((ldc_first_curve[15] << CURVE_HIGH_SHIFT) & CURVE_HIGH_MASK);
    REG(0xd0040130) = (REG(0xd0040130) & ~CURVE_LOW_MASK) | (ldc_first_curve[16] & CURVE_LOW_MASK);
}
