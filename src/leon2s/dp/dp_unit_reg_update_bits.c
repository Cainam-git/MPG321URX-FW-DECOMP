/* dp_unit_reg_update_bits  (FUN_a00a8400)
 *
 * Set or clear masked bits of a byte register of one or all eight DP units.
 *   port: unit
 *   reg: register
 *   mask: bits
 *   mode: 1 = set
 * Name basis: derived - block table 0xA00B4D20, unit > 7 = all; callers dp_unit_set_reg1_bit5_and_reg3
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: the value read and the result are unsigned char locals (register choice of the loop).
 */
extern unsigned short dp_unit_reg_bases[];

#define REG(a) (*(volatile unsigned int *)(0xcf000000 | ((a) * 4)))

/*
 * Set or clear the bits of mask in a byte register of one of eight DP units, or of all eight. Read-modify-write
 * on the register of dp_unit_reg_write8 (the write-only counterpart).
 *
 *   port: unit 0..7, above 7 = all eight units
 *   reg:  register number
 *   mask: bits to change
 *   mode: 1 = set the bits, any other value = clear them
 */
void dp_unit_reg_update_bits(unsigned char port, unsigned short reg, unsigned char mask, unsigned char mode)
{
    unsigned char i;
    unsigned char old_value;
    unsigned char new_value;

    if (port > 7) {
        i = 0;
        do {
            old_value = REG(dp_unit_reg_bases[i] + reg);
            if (mode == 1)
                new_value = old_value | mask;
            else
                new_value = old_value & ~mask;
            REG(dp_unit_reg_bases[i] + reg) = new_value;
            i++;
        } while (i <= 7);
    } else {
        old_value = REG(dp_unit_reg_bases[port] + reg);
        if (mode == 1)
            new_value = old_value | mask;
        else
            new_value = old_value & ~mask;
        REG(dp_unit_reg_bases[port] + reg) = new_value;
    }
}
