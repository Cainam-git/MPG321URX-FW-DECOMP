/* dp_reg_update_bits  (FUN_a00a6c98)
 *
 * Set or clear masked bits of a byte register of one or both DP receivers.
 *   port: receiver, 2 = both
 *   reg: register
 *   mask: bits
 *   mode: 1 = set
 * Name basis: proven - read-modify-write; mode 1 sets, else clears; port 2 = both
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Same code as hdmi_rx21_reg_update_bits with the table dp_reg_bases and a plain else for the single-receiver case.
 * Source form: the value read and the result are unsigned char locals.
 */
extern unsigned short dp_reg_bases[];

#define REG(a) (*(volatile unsigned int *)(0xcf000000 | ((a) * 4)))

/*
 * Set or clear the bits of mask in a byte register of a DP receiver. Receiver 2 does both receivers (0 and 1),
 * values above 2 do nothing. Read-modify-write on the register of dp_reg_read8.
 *
 *   port: 0, 1, or 2 = both
 *   reg:  register number
 *   mask: bits to change
 *   mode: 1 = set the bits, any other value = clear them
 */
void dp_reg_update_bits(unsigned char port, unsigned short reg, unsigned char mask, unsigned char mode)
{
    unsigned char i;
    unsigned char old_value;
    unsigned char new_value;

    if (port > 2)
        return;
    if (port == 2) {
        i = 0;
        do {
            old_value = REG(dp_reg_bases[i] + reg);
            if (mode == 1)
                new_value = old_value | mask;
            else
                new_value = old_value & ~mask;
            REG(dp_reg_bases[i] + reg) = new_value;
            i++;
        } while (i <= 1);
    } else {
        old_value = REG(dp_reg_bases[port] + reg);
        if (mode == 1)
            new_value = old_value | mask;
        else
            new_value = old_value & ~mask;
        REG(dp_reg_bases[port] + reg) = new_value;
    }
}
