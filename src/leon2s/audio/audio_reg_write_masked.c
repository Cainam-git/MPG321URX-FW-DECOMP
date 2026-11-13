/* audio_reg_write_masked  (FUN_a00a71fc)
 *
 * Replace the masked bits of a register of one or all four audio units.
 *   unit: unit 0..3, 4 = all
 *   reg: register
 *   mask
 *   value
 * Name basis: proven - block table 0xA00B4D88, unit 4 = all; (old & ~mask) | (value & mask)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a71fc @ 0xa00a71fc (-mcpu=v8 -Os -g).
 * Source form: the register is written out as one macro expression, used on both sides of the assignment, once
 * in the loop and once for a single unit.
 */
extern unsigned short audio_reg_bases[];

/* Register "reg" of the audio unit with index unit_index. */
#define AUDIO_REG(unit_index) \
    (*(volatile unsigned int *)(0xcf000000 | ((audio_reg_bases[unit_index] + (unsigned short)reg) * 4)))

/*
 * Replace the masked bits of a register of one audio unit, or of all four.
 *   unit:  audio unit 0..3, or 4 for all four units; any other number changes nothing
 *   reg:   register number
 *   mask:  the bits to replace
 *   value: their new value
 * The new register value is ((old & ~mask) | (mask & value)) & 0xff.
 */
void audio_reg_write_masked(unsigned int unit, unsigned short reg, unsigned int mask, unsigned int value)
{
    unsigned char i;
    
    unit &= 0xff;
    if (unit == 4) {
        i = 0;
        do {
            AUDIO_REG(i) = (AUDIO_REG(i) & ~mask | mask & value) & 0xff;
            i++;
        } while (i <= 3);
    } else if (unit < 4) {
        AUDIO_REG(unit) = (AUDIO_REG(unit) & ~mask | mask & value) & 0xff;
    }
}
