/* dp_set_bank_registers  (FUN_a00b12cc)
 *
 * Write a pair of bank registers depending on a per-port test.
 * Name basis: descriptive - register writes chosen by the option stub (never non-zero) and the enable argument
 *
 * Matching notes
 * --------------
 * FUN_a00b12cc (leon2s 0xa00b12cc-0xa00b1350, 132 bytes), flags -mcpu=v8 -Os -g.
 * The last call is a tail call. `enable` is a raw word parameter tested as a byte.
 */
extern unsigned char dp_tx_hpd_option_stub_copy3(unsigned char);
extern void dp_reg_write8(unsigned int, unsigned short, unsigned int);
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned int, unsigned int);

/* Write register 0x46 and bit 0 of register 0xC0 of DisplayPort receiver `port`:
 *   option stub non-zero (never, in this build): reg 0x46 = 0x13, bit set
 *   else `enable` non-zero:                      reg 0x46 = 0x17, bit set
 *   else:                                        reg 0x46 = 0x13, bit cleared */
void dp_set_bank_registers(unsigned char port, unsigned int enable)
{
    if (dp_tx_hpd_option_stub_copy3(port) != 0) {
        dp_reg_write8(port, 0x46, 0x13);
        dp_reg_update_bits(port, 0xc0, 1, 1);
    } else if ((unsigned char)enable != 0) {
        dp_reg_write8(port, 0x46, 0x17);
        dp_reg_update_bits(port, 0xc0, 1, 1);
    } else {
        dp_reg_write8(port, 0x46, 0x13);
        dp_reg_update_bits(port, 0xc0, 1, 0);
    }
}
