/* 8051_bank1 FUN_CODE_ad88 @ 0xad88 (149 B)
 * FUN_CODE_ad88(ch): LARGE parameter ch at XDATA 0xA475. When XDATA 0xD511 is 0x20: 0xDCAC = 2 << ch and the
 * ten bytes 0xDCA1..0xDCAA = 87 99 C0 17 00 BD 87 44 44 00. Otherwise FUN_CODE_9e3f(ch, 0x0490, 1, 1),
 * (ch, 0x0434, 1, 0), (ch, 0x0433, 0x10, 0), (ch, 0x0490, 2, 0) (fourth parameter in 9e3f's slot 0xA47A).
 * Options: OPTIMIZE(8,SPEED) LARGE.
 * Source form: ch is copied to a local first.
 */
extern unsigned char xdata DAT_EXTMEM_d511;
extern unsigned char xdata DAT_EXTMEM_dcac;
extern unsigned char xdata DAT_EXTMEM_dca1[10];
void FUN_CODE_9e3f(unsigned char ch, unsigned int reg, unsigned char v, unsigned char f);

void FUN_CODE_ad88(unsigned char ch)
{
    unsigned char n;

    if (DAT_EXTMEM_d511 == 0x20) {
        n = ch;
        DAT_EXTMEM_dcac = 2 << n;
        DAT_EXTMEM_dca1[0] = 0x87;
        DAT_EXTMEM_dca1[1] = 0x99;
        DAT_EXTMEM_dca1[2] = 0xc0;
        DAT_EXTMEM_dca1[3] = 0x17;
        DAT_EXTMEM_dca1[4] = 0;
        DAT_EXTMEM_dca1[5] = 0xbd;
        DAT_EXTMEM_dca1[6] = 0x87;
        DAT_EXTMEM_dca1[7] = 0x44;
        DAT_EXTMEM_dca1[8] = 0x44;
        DAT_EXTMEM_dca1[9] = 0;
    } else {
        FUN_CODE_9e3f(ch, 0x0490, 1, 1);
        FUN_CODE_9e3f(ch, 0x0434, 1, 0);
        FUN_CODE_9e3f(ch, 0x0433, 0x10, 0);
        FUN_CODE_9e3f(ch, 0x0490, 2, 0);
    }
}
