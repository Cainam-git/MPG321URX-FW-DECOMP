/* ldc_hw_set_strength  (FUN_a00fbc80)
 *
 * Set the strength values of the grid block for a mode.
 * Name basis: descriptive - per-mode values and bit 31 of 0xD004002C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fbc80 @ 0xa00fbc80, flags -mcpu=v8 -O3 -g. Caller: ldc_hw_command.
 * Source forms the exact build depends on: an if/else chain, not a switch (the firmware compares the level with
 * 0, 1, 2, 3 in a row); each arm has its own local word, so each gets its own stack slot (fp-12, -16, -20, -24,
 * -28 in source order).
 */

#define R(a) (*(volatile unsigned int *)(a))

/* Register of the grid block: bit 31 is set in levels 2 and 3. */
#define LDC_REG_2C        0xd004002c
#define LDC_REG_2C_BIT31  0x80000000

/* Id of ldc_hw_access_register: sets bits 8..12 of the register at 0xD004000C. */
#define LDC_ID_0C_BITS8_12 10

extern int ldc_hw_set_timing(unsigned char, unsigned int);
extern int ldc_hw_access_register(unsigned int, unsigned int *, unsigned int, unsigned int);

/*
 * Put the grid block into one of four levels.
 *
 *   selector  must be 0, otherwise nothing happens
 *   level     0..3; any larger value acts like level 1
 *
 * Always returns 1. For selector 0 each level does three things in this order: sets the block's mode with
 * ldc_hw_set_timing, sets or clears bit 31 of LDC_REG_2C, and writes a value into bits 8..12 of the register at 0xD004000C:
 *
 *   level   mode   bit 31 of LDC_REG_2C   value
 *     0       0       clear                 0x00
 *     1       3       clear                 0x00
 *     2       3       set                   0x03
 *     3       3       set                   0x13
 *   other     3       clear                 0x00
 */
int ldc_hw_set_strength(unsigned char selector, unsigned char level)
{
    if (selector == 0) {
        if (level == 0) {
            unsigned int v;

            ldc_hw_set_timing(0, 0);
            R(LDC_REG_2C) &= ~LDC_REG_2C_BIT31;
            v = 0;
            ldc_hw_access_register(LDC_ID_0C_BITS8_12, &v, 0, 0);
        } else if (level == 1) {
            unsigned int v;

            ldc_hw_set_timing(0, 3);
            R(LDC_REG_2C) &= ~LDC_REG_2C_BIT31;
            v = 0;
            ldc_hw_access_register(LDC_ID_0C_BITS8_12, &v, 0, 0);
        } else if (level == 2) {
            unsigned int v;

            ldc_hw_set_timing(0, 3);
            R(LDC_REG_2C) |= LDC_REG_2C_BIT31;
            v = 3;
            ldc_hw_access_register(LDC_ID_0C_BITS8_12, &v, 0, 0);
        } else if (level == 3) {
            unsigned int v;

            ldc_hw_set_timing(0, 3);
            R(LDC_REG_2C) |= LDC_REG_2C_BIT31;
            v = 0x13;
            ldc_hw_access_register(LDC_ID_0C_BITS8_12, &v, 0, 0);
        } else {
            unsigned int v;

            ldc_hw_set_timing(0, 3);
            R(LDC_REG_2C) &= ~LDC_REG_2C_BIT31;
            v = 0;
            ldc_hw_access_register(LDC_ID_0C_BITS8_12, &v, 0, 0);
        }
    }
    return 1;
}
