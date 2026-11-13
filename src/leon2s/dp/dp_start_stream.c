/* dp_start_stream  (FUN_a00afeb8)
 *
 * Start the reception of a port's stream, optionally from scratch.
 * Name basis: derived - restart flag clears the retry counter; register writes and the clock check
 *
 * Matching notes
 * --------------
 * FUN_a00afeb8 (leon2s, 0xa00afeb8-0xa00b0004, 332 bytes), flags -mcpu=v8 -Os -g.
 * dp_calc_pixel_clock returns unsigned short (its return path shifts left and right by 16), and pixel_clock is
 * unsigned short; the counter is a plain byte. The pixel clock is passed to sys_dsc_dec_set_clock unchanged.
 */
extern unsigned char dp_stream_start_count;
extern unsigned char dp_stream_reg485_values[];
extern unsigned int dp_check_stream_clock(unsigned int, unsigned int);
extern void dp_reg_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned short dp_calc_pixel_clock(unsigned int);
extern void sys_dsc_dec_set_clock(unsigned int, unsigned short);
extern unsigned int dp_reg_read8(unsigned int, unsigned short);
extern void dp_reg_write8(unsigned int, unsigned short, unsigned int);
extern void sys_dsc_dec_set_regb4_bit1(void);
extern void dp_unit_restart(unsigned int, unsigned int);

/* One attempt to start the reception of a DP input's stream.
 *
 * With restart set, the attempt counter dp_stream_start_count is cleared and dp_check_stream_clock(port, 1) is
 * called first. Then: bits 2 and 5 of register 0x483 set, bits 0 and 1 cleared, bit 0 of 0x486 set; the pixel
 * clock is computed (dp_calc_pixel_clock) and passed to sys_dsc_dec_set_clock(0, clock); for a clock of 101 to
 * 149, bit 0 of 0x483 is cleared when register 0x21c reads 6 and set otherwise. Register 0x485 gets entry
 * [counter] of dp_stream_reg485_values, then sys_dsc_dec_set_regb4_bit1(). When dp_check_stream_clock(port, 0)
 * returns 1 the counter is incremented; above 10 it is cleared, dp_unit_restart(port, 0) runs and the result
 * is 1.
 *
 * port: DP input. restart: non-zero = begin with a cleared counter. Returns 1 when the counter ran out and the
 * unit was restarted, else 0. Called by sys_dsc_dec_run_state.
 */
unsigned int dp_start_stream(unsigned int port, unsigned int restart)
{
    unsigned short pixel_clock;

    if ((restart & 0xff) != 0) {
        dp_stream_start_count = 0;
        dp_check_stream_clock(port & 0xff, 1);
    }
    port = port & 0xff;
    dp_reg_update_bits(port, 0x483, 0x24, 1);
    dp_reg_update_bits(port, 0x483, 3, 0);
    dp_reg_update_bits(port, 0x486, 1, 1);
    pixel_clock = dp_calc_pixel_clock(port);
    sys_dsc_dec_set_clock(0, pixel_clock);
    if ((unsigned short)(pixel_clock - 101) <= 0x30) {
        if ((dp_reg_read8(port, 0x21c) & 0xff) == 6)
            dp_reg_update_bits(port, 0x483, 1, 0);
        else
            dp_reg_update_bits(port, 0x483, 1, 1);
    }
    dp_reg_write8(port, 0x485, dp_stream_reg485_values[dp_stream_start_count]);
    sys_dsc_dec_set_regb4_bit1();
    if ((dp_check_stream_clock(port, 0) & 0xff) == 1)
        dp_stream_start_count++;
    if (dp_stream_start_count > 10) {
        dp_stream_start_count = 0;
        dp_unit_restart(port, 0);
        return 1;
    }
    return 0;
}
