/* sys_dsc_dec_calc_pixel_clock  (FUN_a00a535c)
 *
 * Compute and print the pixel clock of the DSC picture and program the clock.
 *   factor
 *   divisor
 *   multiplier: factor
 * Returns: clock in kHz
 * Name basis: proven - prints 'Pexil clock = %ld KHz'; then sys_dsc_dec_set_pll(0, clock)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a535c @ 0xa00a535c (-mcpu=v8 -Os)
 * The first and second parameters are 16-bit; the divisor is masked to 16 bits.
 */
extern int dbg_printf(const char *, ...);
extern int sys_dsc_dec_set_pll(int, int);

/* Compute (multiplier * factor / divisor) * 100, print it as the pixel clock in kHz ("Pexil clock" is the
 * firmware's own spelling), set the decoder's clock with sys_dsc_dec_set_pll(0, clock) and return the value.
 *   factor, divisor: 16-bit values
 *   multiplier: factor of the product
 */
int sys_dsc_dec_calc_pixel_clock(unsigned short factor, unsigned short divisor, int multiplier)
{
    unsigned int product;
    unsigned int divisor_32;
    int clock_khz;

    product = (unsigned int)multiplier * (unsigned int)factor;
    divisor_32 = divisor & 0xffff;
    clock_khz = (int)(product / divisor_32) * 100;
    dbg_printf("\n Pexil clock = %ld KHz\n\n", clock_khz);
    sys_dsc_dec_set_pll(0, clock_khz);
    return clock_khz;
}
