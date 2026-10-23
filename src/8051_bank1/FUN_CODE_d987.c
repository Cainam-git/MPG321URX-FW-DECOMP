/* 8051_bank1 FUN_CODE_d987 @ 0xd987  OPTIMIZE(7,SPEED)
 * Calls FUN_CODE_cd07 and FUN_CODE_ce4b, then sets up the serial port and timers: SCON = 0x52 (mode 1, receiver
 * enabled, TI set), TMOD = 0x21 (Timer 1 mode 2 auto-reload, Timer 0 mode 1), PCON = 0x80 (SMOD, doubled baud
 * rate). Starts Timers 0 and 1, enables external interrupts 0 and 1, the Timer 0 interrupt and the serial
 * interrupt, and gives the serial interrupt high priority (PS). The SFR and bit addresses are the standard 8052
 * ones.
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

void FUN_CODE_cd07(void);
void FUN_CODE_ce4b(void);

void FUN_CODE_d987(void)
{
    FUN_CODE_cd07();
    FUN_CODE_ce4b();
    SCON = 0x52;
    TMOD = 0x21;
    PCON = 0x80;
    TR0 = 1;
    TR1 = 1;
    EX0 = 1;
    EX1 = 1;
    ET0 = 1;
    ES = 1;
    PS = 1;
}
