/* ldc_hw_set_timing  (FUN_a00fbaf8)
 *
 * Store a mode and write the timing values of the grid block.
 * Name basis: descriptive - 1000 - t and an optional second value
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fbaf8 @ 0xa00fbaf8, flags -mcpu=v8 -O3 -g. Called from ldc_hw_set_strength and ldc_hw_command.
 * Source forms the exact build depends on:
 *  - the ldc_timing_scale store is one '?:' assignment (the store goes through the full address register);
 *  - value and value_e4 are stack words whose addresses are passed;
 *  - the register words are read-modify-written, bit 31 with a mask local.
 * Names: the match depends on the names DAT_a802d678_vsize and DAT_a802d67a_hsize (gcse orders the two hoisted
 *   %hi parts by a hash of the names: firmware 0xa00fbb8c %l1 for 0xa802d67a, 0xa00fbb90 %l0 for 0xa802d678).
 */

#define REG(a) (*(volatile unsigned int *)(a))

/* Registers of the grid block. */
#define LDC_REG_CTRL 0xd0040000         /* bit 31 enable */
#define LDC_REG_MODE 0xd00400d8         /* bits 0..3 mode */

/* Ids of ldc_hw_access_register used here. */
enum {
    LDC_ID_NONE         = 8,            /* writes nothing */
    LDC_ID_E4_BITS24_31 = 11
};

#define LDC_MODE_MAX 4                  /* modes 0..4 are accepted */

extern unsigned char ldc_timing_mode;
extern unsigned short ldc_timing_value;
extern unsigned short DAT_a8026a86;
extern unsigned short ldc_reg8_value;
extern unsigned short ldc_timing_scale;
extern unsigned short DAT_a802d678_vsize;
extern unsigned short DAT_a802d67a_hsize;
extern int ldc_hw_access_register(unsigned int, unsigned int *, unsigned int, unsigned int);

/*
 * Set the mode of the grid block and write the values that go with it.
 *
 *   selector  0 or 1; a larger value is rejected. Only 0 writes the second value (step 4).
 *   mode      0..4; a larger value is rejected. Stored in ldc_timing_mode.
 *
 * Returns 0 when a parameter is rejected (nothing is changed), otherwise 1.
 *
 *  1. ldc_timing_scale = 0x100 for modes 0 and 1, 0x80 for modes 2..4.
 *  2. value = ldc_timing_value * ldc_timing_scale / 256, then 1000 - value (0 when value is above 1000). It is
 *     kept in ldc_reg8_value and passed to ldc_hw_access_register as id 8, which writes no register.
 *  3. Mode 4 with selector 0 only: DAT_a8026a86 above 0xBB7 gives 0x80, up to 0x1F3 gives 0, between
 *     them (DAT_a8026a86 * 0x34 - 0x6590) / 1024; written as id 11, which sets bits 24..31 of the register at 0xD00400E4.
 *  4. Bit 31 of LDC_REG_CTRL = (mode != 0); bits 0..3 of LDC_REG_MODE = mode.
 */
int ldc_hw_set_timing(unsigned char selector, unsigned int mode)
{
    unsigned int value = 0, value_e4 = 0;
    unsigned char enable;
    unsigned int mask;

    if (selector > 1 || mode > LDC_MODE_MAX)
        return 0;
    ldc_timing_mode = mode;
    ldc_timing_scale = (mode <= 1) ? 0x100 : 0x80;
    value = (int)(ldc_timing_value * ldc_timing_scale) >> 8;
    value = (value > 1000) ? 0 : 1000 - value;
    ldc_reg8_value = value;
    ldc_hw_access_register(LDC_ID_NONE, &value, DAT_a802d67a_hsize, DAT_a802d678_vsize);
    if (mode == LDC_MODE_MAX) {
        if (selector == 0) {
            value = DAT_a8026a86;
            if (value > 0xbb7)
                value_e4 = 0x80;
            else if (value <= 0x1f3)
                value_e4 = 0;
            else
                value_e4 = (value * 0x34 - 0x6590) >> 10;
            ldc_hw_access_register(LDC_ID_E4_BITS24_31, &value_e4, DAT_a802d67a_hsize, DAT_a802d678_vsize);
        }
    }
    enable = ldc_timing_mode != 0;
    mask = 0x80000000;
    REG(LDC_REG_CTRL) = (REG(LDC_REG_CTRL) & ~mask) | ((enable << 31) & mask);
    REG(LDC_REG_MODE) = (REG(LDC_REG_MODE) & ~0xf) | (ldc_timing_mode & 0xf);
    return 1;
}
