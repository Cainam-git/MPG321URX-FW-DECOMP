/* dp_status_reg_update_bits  (FUN_a00a7058)
 *
 * Set or clear masked bits of a byte register of one or both DP receiver status blocks.
 *   port: unit
 *   reg: register
 *   mask: bits
 *   mode: 1 = set
 * Name basis: derived - block table 0xA00B4D90, unit 2 = both; callers dp_init_port
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Same code as hdmi_rx21_reg_update_bits with the table dp_status_reg_bases and a plain else for the single-unit case.
 * Source form: the value read and the result are unsigned char locals.
 */
extern unsigned short dp_status_reg_bases[];

#define REG(a) (*(volatile unsigned int *)(0xcf000000 | ((a) * 4)))

/*
 * Set or clear the bits of mask in a byte register of a DP receiver status block. Unit 2 does both units,
 * values above 2 do nothing. Read-modify-write on the register of dp_status_reg_read8.
 *
 *   port: 0, 1, or 2 = both
 *   reg:  register number
 *   mask: bits to change
 *   mode: 1 = set the bits, any other value = clear them
 */
void dp_status_reg_update_bits(unsigned char port, unsigned short reg, unsigned char mask, unsigned char mode)
{
    unsigned char i;
    unsigned char old_value;
    unsigned char new_value;

    if (port > 2)
        return;
    if (port == 2) {
        i = 0;
        do {
            old_value = REG(dp_status_reg_bases[i] + reg);
            if (mode == 1)
                new_value = old_value | mask;
            else
                new_value = old_value & ~mask;
            REG(dp_status_reg_bases[i] + reg) = new_value;
            i++;
        } while (i <= 1);
    } else {
        old_value = REG(dp_status_reg_bases[port] + reg);
        if (mode == 1)
            new_value = old_value | mask;
        else
            new_value = old_value & ~mask;
        REG(dp_status_reg_bases[port] + reg) = new_value;
    }
}
