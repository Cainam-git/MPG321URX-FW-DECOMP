/* dp_unit_reg_write8  (FUN_a00a8370)
 *
 * Write a byte register of one or all eight DP units.
 *   unit: unit 0..7, > 7 = all
 *   reg: register
 *   value
 * Name basis: derived - block table 0xA00B4D20 (0x4930..0x49A0), unit > 7 = all; callers
 *   dp_unit_write_two_24bit_values
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: the loop counter is an unsigned char and the table index is a separate unsigned short copy.
 */
extern unsigned short dp_unit_reg_bases[];

/*
 * Write a byte register of one of eight DP units, or of all eight.
 *
 *   unit:  0..7 = that unit, above 7 = all eight units
 *   reg:   register number
 *   value: only the low byte is written
 *
 * The register is the word at 0xCF000000 | ((dp_unit_reg_bases[unit] + reg) * 4); the table is at
 * 0xA00B4D20.
 */
void dp_unit_reg_write8(unsigned int unit, unsigned short reg, unsigned int value)
{
    unsigned char i;
    unsigned short index;

    unit &= 0xff;
    if (unit > 7) {
        i = 0;
        do {
            index = (unsigned short)i;
            *(volatile unsigned int *)(0xcf000000 | 
                ((dp_unit_reg_bases[index] + reg) * 4)) = value & 0xff;
            i++;
        } while ((unsigned char)i <= 7);
    } else {
        *(volatile unsigned int *)(0xcf000000 | 
            ((dp_unit_reg_bases[unit] + reg) * 4)) = value & 0xff;
    }
}
