/* uart_init  (FUN_CODE_1616)
 *
 * Set the serial port up for 4800 baud, 8 data bits, no parity.
 * Name basis: proven - timer 1 reload chosen by the clock (48 or 96 MHz)
 *
 * Matching notes
 * --------------
 * Built with the section default OPTIMIZE(7,SPEED).
 * Source form: clock and baud rate are locals (DATA 0x22..0x27) and the reload value is computed at run time in
 * unsigned long arithmetic, through the compiler library's ?C?LMUL and ?C?ULDIV; the exact build depends on it.
 */
sfr TH1 = 0x8D; sfr SCON = 0x98; sfr TMOD = 0x89; sfr PCON = 0x87; sfr TCON = 0x88;
sbit TR1 = TCON ^ 6;

#define CLOCK_HZ_VARIANT_20 48000000UL  /* clock used when reg_sys_clock_variant reads 0x20 */
#define CLOCK_HZ_OTHER      96000000UL  /* clock used otherwise */
#define UART_BAUD           4800
#define SCON_VALUE          0x52
#define TMOD_VALUE          0x21
#define PCON_VALUE          0x80

bit startup_is_slow_clock(void);

/* uart_init
 *
 * Sets the serial port up for the boot loader's printed messages: 4800 baud, 8 data bits, no parity, with
 * timer 1 as the baud rate clock.  The timer reload is -(clock * 2 / 384 / 4800): 0xCC for 48 MHz, 0x98 for
 * 96 MHz.  Called once by startup_boot_main, before the banner is printed.
 */
void uart_init(void)
{
    unsigned long clock_hz;
    unsigned int baud;
    if (startup_is_slow_clock()) clock_hz = CLOCK_HZ_VARIANT_20; else clock_hz = CLOCK_HZ_OTHER;
    baud = UART_BAUD;
    TH1 = -(unsigned char)(clock_hz * 2 / 384 / baud);
    SCON = SCON_VALUE;
    TMOD = TMOD_VALUE;
    PCON = PCON_VALUE;
    TR1 = 1;
}
