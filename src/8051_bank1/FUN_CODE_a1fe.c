/* 8051_bank1 FUN_CODE_a1fe @ 0xa1fe..0xa2b8 (186 bytes), OPTIMIZE(8,SPEED) LARGE.
 * Nothing happens while XDATA 0xA6EE is 0. When FUN_CODE_db7d(0) or FUN_CODE_db7d(1) is set and the flag XDATA
 * 0xA6A9 is 0, the flag is set, bit 1 of XDATA 0xDCB0 is pulsed (set, then cleared) and the 16-bit count from
 * FUN_CODE_d94a is stored to XDATA 0xA6A7/0xA6A8. While the flag is set and more than 5000 counts have passed since
 * then, r = FUN_CODE_db7d(0) | FUN_CODE_db7d(1), the count is stored again and bit 1 of 0xDCB0 is pulsed; otherwise
 * r = 1. When r is 0, 0xA6EE and 0xA6A9 are cleared and FUN_CODE_d5c8 and FUN_CODE_de7c are called.
 * LARGE local: r at XDATA 0xA473 (cleared first, collected with |= from the bit results).
 * volatile on 0xDCB0: the firmware reads it again between the set and the clear of bit 1 (hardware register).
 * Caller: FUN_CODE_3fe7 (LCALL at 0x40FC).
 */
extern unsigned char volatile xdata DAT_EXTMEM_dcb0;
extern unsigned char xdata DAT_EXTMEM_a6ee;
extern unsigned char xdata DAT_EXTMEM_a6a9;
extern unsigned int xdata DAT_EXTMEM_a6a7;
extern bit FUN_CODE_db7d(unsigned char n);
extern unsigned int FUN_CODE_d94a(void);
extern void FUN_CODE_d5c8(void);
extern void FUN_CODE_de7c(void);

void FUN_CODE_a1fe(void)
{
    unsigned char r;

    r = 0;
    if (DAT_EXTMEM_a6ee > 0) {
        if (FUN_CODE_db7d(0) || FUN_CODE_db7d(1)) {
            if (DAT_EXTMEM_a6a9 == 0) {
                DAT_EXTMEM_a6a9 = 1;
                DAT_EXTMEM_dcb0 |= 0x02;
                DAT_EXTMEM_dcb0 &= ~0x02;
                DAT_EXTMEM_a6a7 = FUN_CODE_d94a();
            }
        }
        if (DAT_EXTMEM_a6a9 != 0 && FUN_CODE_d94a() - DAT_EXTMEM_a6a7 > 5000) {
            r |= FUN_CODE_db7d(0);
            r |= FUN_CODE_db7d(1);
            DAT_EXTMEM_a6a7 = FUN_CODE_d94a();
            DAT_EXTMEM_dcb0 |= 0x02;
            DAT_EXTMEM_dcb0 &= ~0x02;
        } else
            r = 1;
        if (r == 0) {
            DAT_EXTMEM_a6ee = 0;
            DAT_EXTMEM_a6a9 = 0;
            FUN_CODE_d5c8();
            FUN_CODE_de7c();
        }
    }
}
