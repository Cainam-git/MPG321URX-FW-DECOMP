/* 8051_bank2 FUN_CODE_d1bb @ 0xd1bb  update agent: hand the scaler over for an update (m = 1) or give it back (m = 0)
 * (OPTIMIZE(8,SPEED) LARGE).
 * FUN_CODE_e53b(0x14), P1.4 = 1, wait 2, FUN_CODE_de50(m). Only for m == 1, over the service bus (FUN_CODE_da8a /
 * FUN_CODE_e105, slave 0x6E):
 *   wait 5, read the pending reply (FUN_CODE_e4b9 = FUN_CODE_e4bf(XDATA 0x0436) through Keil's common entry) and keep
 *   its bytes 1 / 2 in XDATA 0x0648 / 0x0649;
 *   scaler 0xF04C = 0x60, 0xD929 = 0x06, 0xF1A8 = 0x02;
 *   if scaler 0xF050 bit 2 (the boot loader's "quad mode verified" latch, see 8051_bank0 FUN_CODE_0c83) is set:
 *     0xF11C |= 0x40 and 0xF11D &= ~0x40 (the same pin set-up the boot loader does for quad mode);
 *   0xF0E0 = 0xAA (the register the boot loader writes 0xAA to at start: the public MPG 341CQPX write-up measured it as
 *     the watchdog, 0xAA = off);
 *   0xF0FF |= 0x40.
 * Ends with FUN_CODE_e53b(1) (tail call). Called with 1 at the start of FUN_CODE_a8a3 (enter ISP) and with 0 at its end.
 * The boot loader stores its FUN_CODE_17e2 result + 1 in 0xD929.
 */
sfr P1 = 0x90;
sbit P1_4 = P1 ^ 4;
extern unsigned char xdata DAT_EXTMEM_0436[];
extern unsigned char xdata DAT_EXTMEM_0648, DAT_EXTMEM_0649;
void FUN_CODE_e53b(unsigned char a);
void FUN_CODE_e44b(unsigned char n);
void FUN_CODE_de50(unsigned char m);
void FUN_CODE_e4b9(void);
unsigned char FUN_CODE_e105(unsigned int reg);
unsigned char FUN_CODE_da8a(unsigned int reg, unsigned char val);

void FUN_CODE_d1bb(unsigned char m)
{
    FUN_CODE_e53b(0x14);
    P1_4 = 1;
    FUN_CODE_e44b(2);
    FUN_CODE_de50(m);
    if (m == 1) {
        FUN_CODE_e44b(5);
        FUN_CODE_e4b9();
        DAT_EXTMEM_0648 = DAT_EXTMEM_0436[1];
        DAT_EXTMEM_0649 = DAT_EXTMEM_0436[2];
        FUN_CODE_da8a(0xf04c, 0x60);
        FUN_CODE_da8a(0xd929, 0x06);
        FUN_CODE_da8a(0xf1a8, 0x02);
        if (FUN_CODE_e105(0xf050) & 0x04) {
            FUN_CODE_da8a(0xf11c, FUN_CODE_e105(0xf11c) | 0x40);
            FUN_CODE_da8a(0xf11d, FUN_CODE_e105(0xf11d) & ~0x40);
        }
        FUN_CODE_da8a(0xf0e0, 0xaa);
        FUN_CODE_da8a(0xf0ff, FUN_CODE_e105(0xf0ff) | 0x40);
    }
    FUN_CODE_e53b(1);
}
