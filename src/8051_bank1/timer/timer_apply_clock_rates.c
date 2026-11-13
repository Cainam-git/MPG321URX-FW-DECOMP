/* timer_apply_clock_rates  (FUN_CODE_ce4b)
 *
 * Reload the tick timer and the serial port rates after a clock change.
 * Name basis: derived - timer_set_clock_rates, TL0/TH0 from 0xA772/0xA773, uart_set_baud_rate(0x1D, 4800),
 *   0xDD09 bit 3, pulse 0xF3D1 bit 2
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_ce4b @ 0xce4b (60 B)  Byte-exact with OPTIMIZE(7,SPEED).
 * Source form: uart_set_baud_rate is a LARGE function: its first parameter arrives in R7 (stored at XDATA 0xA4B9),
 * the 32-bit second parameter in its XDATA block at 0xA4BA. The register at 0xF3D1 is volatile: the clear re-reads
 * it after the NOPs.
 */
#include <intrins.h>
sfr TL0 = 0x8A;
sfr TH0 = 0x8C;
extern unsigned char xdata timer_reload_low, timer_reload_high, DAT_EXTMEM_dd09, DAT_EXTMEM_f3db;
extern unsigned char volatile xdata DAT_EXTMEM_f3d1;
extern void timer_set_clock_rates(void);
extern void uart_set_baud_rate(unsigned char port, unsigned long baud) large;

/*
 * Recompute the Timer 0 reload (timer_set_clock_rates), load it into
 * TL0 / TH0, set the rate 4800 with selector 0x1D, set bit 3 of 0xDD09,
 * pulse bit 2 of 0xF3D1 (set, five NOPs, clear) and write 0x0F to 0xF3DB.
 * Callers: the code at 0x4284 and 0xD98A.
 */
void timer_apply_clock_rates(void)
{
    timer_set_clock_rates();
    TL0 = timer_reload_low;
    TH0 = timer_reload_high;
    uart_set_baud_rate(0x1d, 4800);
    DAT_EXTMEM_dd09 |= 0x08;
    DAT_EXTMEM_f3d1 |= 0x04;
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    DAT_EXTMEM_f3d1 &= ~0x04;
    DAT_EXTMEM_f3db = 0x0f;
}
