/* ldc_hw_load_curve_second  (FUN_a00f9bbc)
 *
 * Copy the second 17-point curve into its 12-bit register fields.
 * Name basis: descriptive - halfwords at 0xA8027A30 to 0xD0040140..0xD0040160
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f9bbc @ 0xa00f9bbc, flags -mcpu=v8 -O3 -g.
 * Source form: same as ldc_hw_load_curve_first (set_field helper inlined, one expression per register), with
 * another table and register block.
 */

#define CURVE_POINTS    17
#define CURVE_LOW_MASK  0xfff           /* even point: bits 0..11 of the register */
#define CURVE_HIGH_MASK 0xfff0000       /* odd point: bits 16..27 of the register */
#define CURVE_HIGH_SHIFT 16
#define REG(a) (*(volatile unsigned int *)(a))

extern unsigned short ldc_second_curve[CURVE_POINTS];

/* Return (v | bits) & ~clear. */
static unsigned int set_field(unsigned int v, unsigned int bits, unsigned int clear)
{
    return (v | bits) & ~clear;
}

/*
 * Copy the 17 halfwords of ldc_second_curve into 12-bit fields of nine grid block registers from 0xd0040140 in steps of 4:
 * register k (k = 0..7) takes point 2k in bits 0..11 and point 2k + 1 in bits 16..27, register 8 takes point
 * 16 in bits 0..11. The other bits keep their value; each register is read once and written once. Called by ldc_hw_init and
 * ldc_hw_command.
 */
void ldc_hw_load_curve_second(void)
{
    REG(0xd0040140) = set_field(REG(0xd0040140) & ~CURVE_LOW_MASK, ldc_second_curve[0] & CURVE_LOW_MASK, CURVE_HIGH_MASK) | ((ldc_second_curve[1] << CURVE_HIGH_SHIFT) & CURVE_HIGH_MASK);
    REG(0xd0040144) = set_field(REG(0xd0040144) & ~CURVE_LOW_MASK, ldc_second_curve[2] & CURVE_LOW_MASK, CURVE_HIGH_MASK) | ((ldc_second_curve[3] << CURVE_HIGH_SHIFT) & CURVE_HIGH_MASK);
    REG(0xd0040148) = set_field(REG(0xd0040148) & ~CURVE_LOW_MASK, ldc_second_curve[4] & CURVE_LOW_MASK, CURVE_HIGH_MASK) | ((ldc_second_curve[5] << CURVE_HIGH_SHIFT) & CURVE_HIGH_MASK);
    REG(0xd004014c) = set_field(REG(0xd004014c) & ~CURVE_LOW_MASK, ldc_second_curve[6] & CURVE_LOW_MASK, CURVE_HIGH_MASK) | ((ldc_second_curve[7] << CURVE_HIGH_SHIFT) & CURVE_HIGH_MASK);
    REG(0xd0040150) = set_field(REG(0xd0040150) & ~CURVE_LOW_MASK, ldc_second_curve[8] & CURVE_LOW_MASK, CURVE_HIGH_MASK) | ((ldc_second_curve[9] << CURVE_HIGH_SHIFT) & CURVE_HIGH_MASK);
    REG(0xd0040154) = set_field(REG(0xd0040154) & ~CURVE_LOW_MASK, ldc_second_curve[10] & CURVE_LOW_MASK, CURVE_HIGH_MASK) | ((ldc_second_curve[11] << CURVE_HIGH_SHIFT) & CURVE_HIGH_MASK);
    REG(0xd0040158) = set_field(REG(0xd0040158) & ~CURVE_LOW_MASK, ldc_second_curve[12] & CURVE_LOW_MASK, CURVE_HIGH_MASK) | ((ldc_second_curve[13] << CURVE_HIGH_SHIFT) & CURVE_HIGH_MASK);
    REG(0xd004015c) = set_field(REG(0xd004015c) & ~CURVE_LOW_MASK, ldc_second_curve[14] & CURVE_LOW_MASK, CURVE_HIGH_MASK) | ((ldc_second_curve[15] << CURVE_HIGH_SHIFT) & CURVE_HIGH_MASK);
    REG(0xd0040160) = (REG(0xd0040160) & ~CURVE_LOW_MASK) | (ldc_second_curve[16] & CURVE_LOW_MASK);
}
