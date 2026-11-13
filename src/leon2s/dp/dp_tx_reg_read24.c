/* dp_tx_reg_read24  (FUN_a00a79c4)
 *
 * Read a 24-bit value from three byte registers of a DP / eDP transmitter.
 *   port: output
 *   reg: first register
 * Returns: 24-bit value
 * Name basis: proven - register 0x50 order: third | first << 16 | second << 8
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g. A leaf routine.
 * Source form: the first two values are unsigned char locals (the byte mask comes from the conversion), and
 * the else arm shifts the result in place (result <<= 8; result |= second; ...); a shift into a new value lets
 * the scheduler move it above the reg == 0x50 branch.
 */
extern unsigned char dp_tx_reg_bases;

static __inline__ unsigned int rd(unsigned int a)
{
    return *(volatile unsigned int *)((a * 4) | 0xcf000000);
}

#define TX_REG_0x50 0x50    /* the one register triple that is stored high byte first */

/*
 * Read a 24-bit value from three byte registers of a DP transmitter output (0 = DPTX, 1..4 = eDP): reg,
 * reg + 1 and reg + 2. Returns 0 for an output above 4.
 *
 *   port: 0..4
 *   reg:  first register
 *
 * For registers other than 0x50 the first register is the low byte. For register 0x50 the first register is
 * the high byte, the second the middle byte and the third the low byte.
 */
unsigned int dp_tx_reg_read24(unsigned int port, unsigned short reg)
{
    unsigned int result = 0;
    unsigned int first_index;
    unsigned char first, second;

    if ((port & 0xff) < 5) {
        first_index = *(unsigned short *)(&dp_tx_reg_bases + (port & 0xff) * 2) + reg;
        first = rd(first_index);
        second = rd(first_index + 1);
        result = rd(first_index + 2);
        if (reg == TX_REG_0x50) {
            result |= first << 16 | second << 8;
        } else {
            result <<= 8;
            result |= second;
            result <<= 8;
            result |= first;
        }
    }
    return result;
}
