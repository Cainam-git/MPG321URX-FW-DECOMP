/* 8051_bank0 FUN_CODE_1616 @ 0x1616  STBC boot loader: UART set-up, 4800 baud 8N1 (built
 * with OPTIMIZE(7,SPEED)).
 * Clock = 48 MHz when FUN_CODE_18bb() reports XDATA 0xD511 == 0x20, else 96 MHz; timer 1 in 8-bit
 * auto-reload mode (TMOD 0x21) with SMOD = 1 (PCON 0x80): TH1 = -(clock * 2 / 384 / 4800) (52 -> 0xCC, or 104 ->
 * 0x98), SCON = 0x52 (mode 1, receiver on, TI set), TR1 = 1. The long arithmetic runs through the Keil library
 * (?C?LMUL FUN_CODE_0fb9, ?C?ULDIV FUN_CODE_1044); clock and baud are this function's DATA locals 0x22..0x27.
 */
sfr TH1 = 0x8D; sfr SCON = 0x98; sfr TMOD = 0x89; sfr PCON = 0x87; sfr TCON = 0x88;
sbit TR1 = TCON ^ 6;
bit FUN_CODE_18bb(void);
void FUN_CODE_1616(void)
{
    unsigned long clk;
    unsigned int baud;
    if (FUN_CODE_18bb()) clk = 48000000; else clk = 96000000;
    baud = 4800;
    TH1 = -(unsigned char)(clk * 2 / 384 / baud);
    SCON = 0x52;
    TMOD = 0x21;
    PCON = 0x80;
    TR1 = 1;
}
