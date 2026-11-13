/* uart_init_8051_serial  (FUN_CODE_d987)
 *
 * Set up the 8051 serial port, both timers and their interrupts.
 * Name basis: proven - standard 8051 SFRs: SCON = 0x52, TMOD = 0x21, PCON.SMOD, TR0/TR1, EX0/EX1/ET0/ES, PS
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d987 @ 0xd987  OPTIMIZE(7,SPEED)
 * The SFR and bit addresses are the standard 8052 ones.
 */
sfr SCON = 0x98;
sfr TMOD = 0x89;
sfr PCON = 0x87;
sbit TR0 = 0x8C;
sbit TR1 = 0x8E;
sbit EX0 = 0xA8;
sbit EX1 = 0xAA;
sbit ET0 = 0xA9;
sbit ES = 0xAC;
sbit PS = 0xBC;

#define SCON_MODE1_REN_TI 0x52  /* serial mode 1, receiver enabled, TI set */
#define TMOD_T1_AUTO_T0_16BIT 0x21  /* timer 1 mode 2 (auto-reload), timer 0 mode 1 */
#define PCON_SMOD 0x80  /* doubled baud rate */

void timer_set_clock_rates(void);
void timer_apply_clock_rates(void);

/*
 * Set up the timer reload and serial rates for the current clock (timer_set_clock_rates, then
 * timer_apply_clock_rates), configure the serial port and both timers, start them, enable external interrupts 0
 * and 1, the timer 0 interrupt and the serial interrupt, and give the serial interrupt high priority.
 */
void uart_init_8051_serial(void)
{
    timer_set_clock_rates();
    timer_apply_clock_rates();
    SCON = SCON_MODE1_REN_TI;
    TMOD = TMOD_T1_AUTO_T0_16BIT;
    PCON = PCON_SMOD;
    TR0 = 1;
    TR1 = 1;
    EX0 = 1;
    EX1 = 1;
    ET0 = 1;
    ES = 1;
    PS = 1;
}
