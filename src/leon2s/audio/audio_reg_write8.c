/* audio_reg_write8  (FUN_a00a7168)
 *
 * Write a byte register of an audio unit.
 *   unit
 *   reg: register
 *   value
 * Name basis: proven - audio unit block table 0xA00B4D88 (units 0..3); callers audio_configure and the audio
 *   routing code
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a7168 @ 0xa00a7168-0xa00a71b4 (76 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the clamp is branch-free. 'cmp %g1, 4; subx %g0, 0, %g1' gives the mask -1 for unit < 4 and 0 for
 * unit >= 4, written as "(unit >= 4) - 1". Same form as audio_reg_read8.
 */
extern unsigned short audio_reg_bases[];

/*
 * Write a byte register of an audio unit.
 *   unit:  audio unit 0..3 (a larger number is treated as unit 0)
 *   reg:   register number
 *   value: only the low byte is written
 * The register is the word at 0xCF000000 | ((audio_reg_bases[unit] + reg) << 2).
 */
void audio_reg_write8(unsigned int unit, unsigned int reg, unsigned int value)
{
    unsigned int unit_byte = unit & 0xff;
    unsigned int valid_mask = (unit_byte >= 4) - 1;
    unsigned int unit_index = (unit & valid_mask) & 0xff;
    unsigned int base = audio_reg_bases[unit_index];
    *(volatile unsigned int *)(0xcf000000 | ((base + (unsigned short)reg) << 2)) = value & 0xff;
}
