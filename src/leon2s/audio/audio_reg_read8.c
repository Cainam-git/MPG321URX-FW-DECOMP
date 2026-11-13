/* audio_reg_read8  (FUN_a00a71b4)
 *
 * Read a byte register of an audio unit.
 *   unit
 *   reg: register
 * Returns: low byte of the register; a unit above 3 reads unit 0
 * Name basis: proven - audio unit block table 0xA00B4D88; invalid units read unit 0
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a71b4 @ 0xa00a71b4 (-mcpu=v8 -Os -g).
 * Source form: the clamp is branch-free. 'cmp %g1, 4; subx %g0, 0, %g1' gives the mask -1 for unit < 4 and 0 for
 * unit >= 4, written as "(unit >= 4) - 1". Same form as audio_reg_write8.
 */
extern unsigned short audio_reg_bases[];

/*
 * Read a byte register of an audio unit.
 *   unit: audio unit 0..3 (a larger number reads unit 0)
 *   reg:  register number
 * The register is the word at 0xCF000000 | ((audio_reg_bases[unit] + reg) << 2); its low byte is returned.
 */
unsigned int audio_reg_read8(unsigned int unit, unsigned int reg)
{
    unsigned int unit_byte = unit & 0xff;
    unsigned int valid_mask = (unit_byte >= 4) - 1;
    unsigned int unit_index = (unit & valid_mask) & 0xff;
    unsigned int base = audio_reg_bases[unit_index];
    return (*(volatile unsigned int *)(0xcf000000 | ((base + (unsigned short)reg) << 2))) & 0xff;
}
