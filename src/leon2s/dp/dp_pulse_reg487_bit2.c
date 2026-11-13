/* dp_pulse_reg487_bit2  (FUN_a00b1350)
 *
 * Pulse bit 2 of register 0x487 of a port.
 * Name basis: descriptive - values 0, 1, 0
 *
 * Matching notes
 * --------------
 * FUN_a00b1350 (leon2s 0xa00b1350-0xa00b1394, 68 bytes), flags -mcpu=v8 -Os -g.
 * The last call is a tail call. dp_reg_update_bits takes the port as a byte and the register as a halfword.
 */
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned int, unsigned int);

/* Drive bit 2 of register 0x487 of DisplayPort receiver `port` low, high, low. */
void dp_pulse_reg487_bit2(unsigned char port)
{
    dp_reg_update_bits(port, 0x487, 4, 0);
    dp_reg_update_bits(port, 0x487, 4, 1);
    dp_reg_update_bits(port, 0x487, 4, 0);
}
