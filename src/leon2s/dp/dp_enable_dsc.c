/* dp_enable_dsc  (FUN_a00af168)
 *
 * Switch the DSC reception of a DP port on or off and print the choice.
 * Name basis: proven - prints 'DP DSC en= %d'; register 0x480 and following; dp_calc_stream_clock when
 *   switching on
 *
 * Matching notes
 * --------------
 * FUN_a00af168 (leon2s, 0xa00af168-0xa00af1e8, 128 bytes), flags -mcpu=v8 -Os -g.
 * Source form: each arm has its own call sequence; -Os then pre-sets (port, 0x480, 1, 1) above the test and
 * crossjumps the final dp_reg_update_bits call. The print is a tail call that passes 'enable' on.
 */
extern void dp_reg_write8(unsigned int, unsigned short, unsigned int);
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void dp_calc_stream_clock(unsigned int);
extern int dbg_printf(const char *, ...);

/*
 * Switch on: set bit 0 of register 0x480, write 0xC0 to register 0x482, run dp_calc_stream_clock, write 2 to
 * register 0x484 and set bit 1 of register 0x486. Switch off: clear bit 0 of register 0x480. Then print the
 * choice with the text "DP DSC en= %d".
 *   port: DP receiver (0 or 1)
 *   enable: non-zero switches on
 * Called from dp_run_link_state.
 */
void dp_enable_dsc(unsigned char port, unsigned char enable)
{
    if (enable != 0) {
        dp_reg_update_bits(port, 0x480, 1, 1);
        dp_reg_write8(port, 0x482, 0xc0);
        dp_calc_stream_clock(port);
        dp_reg_write8(port, 0x484, 2);
        dp_reg_update_bits(port, 0x486, 2, 1);
    } else {
        dp_reg_update_bits(port, 0x480, 1, 0);
    }
    dbg_printf("DP DSC en= %d\r\n", enable);
}
