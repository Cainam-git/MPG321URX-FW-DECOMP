/* 8051_bank1 FUN_CODE_71f0 @ 0x71f0..0x7352 (354 bytes), OPTIMIZE(8,SPEED).
 * Register set-up: sets bit 0x0E (BITS_21_6), XDATA 0xF1E0 = 0xC1, then the same 12 values into the two blocks at
 * XDATA 0x5000 and 0x5100 (bytes 0x09, 0x05, 0x0E, 0x08, 0x06, 0x34/0x35, 0x02, 0x00, 0x0C, 0x0B, 0x0A). With
 * XDATA 0xD511 == 0x20 bits 7..6 of 0xE135 are set. Then read-modify-writes on 0xD90B, 0xD904, 0xD905, 0xD90C and
 * 0xD929 = 0x71; with 0xD511 == 0x20 a further group of clears in 0xD904..0xD92D, 0xDA00 and 0xE12B..0xE1EE.
 * Finally 0xD52C |= 0x0C, 0xD52D |= 0x82, FUN_CODE_dc51(), XDATA 0xA6EE = 0, FUN_CODE_daad() unless 0xD511 ==
 * 0x20, and a tail jump to FUN_CODE_a142(1).
 * volatile on 0xD511: the firmware reads it again for each of its three tests.
 * Source form: the last test is '!(d511 == 0x20)' (SETB C / CLR C / JC).
 * Caller: the command switch FUN_CODE_224f (case 0x16, CMD_SYS_POWERSAVING).
 */
extern unsigned char xdata DAT_EXTMEM_f1e0;
extern unsigned char xdata DAT_EXTMEM_5000[];
extern unsigned char xdata DAT_EXTMEM_5100[];
extern unsigned char volatile xdata DAT_EXTMEM_d511;
extern unsigned char xdata DAT_EXTMEM_e135;
extern unsigned char xdata DAT_EXTMEM_d929, DAT_EXTMEM_d90b, DAT_EXTMEM_d904, DAT_EXTMEM_d905, DAT_EXTMEM_d90c;
extern unsigned char xdata DAT_EXTMEM_d910, DAT_EXTMEM_d911, DAT_EXTMEM_d912, DAT_EXTMEM_d90f, DAT_EXTMEM_d92d;
extern unsigned char xdata DAT_EXTMEM_da00;
extern unsigned char xdata DAT_EXTMEM_e1bf, DAT_EXTMEM_e1cf, DAT_EXTMEM_e1d8, DAT_EXTMEM_e1e0, DAT_EXTMEM_e1e2;
extern unsigned char xdata DAT_EXTMEM_e1ec, DAT_EXTMEM_e1ee, DAT_EXTMEM_e19f, DAT_EXTMEM_e1af, DAT_EXTMEM_e12b;
extern unsigned char xdata DAT_EXTMEM_d52c, DAT_EXTMEM_d52d;
extern unsigned char xdata DAT_EXTMEM_a6ee;
extern bit BITS_21_6;
extern void FUN_CODE_dc51(void);
extern void FUN_CODE_daad(void);
extern void FUN_CODE_a142(unsigned char n);

void FUN_CODE_71f0(void)
{
    BITS_21_6 = 1;
    DAT_EXTMEM_f1e0 = 0xc1;
    DAT_EXTMEM_5000[0x09] = 0x93;
    DAT_EXTMEM_5000[0x05] = 0x53;
    DAT_EXTMEM_5000[0x0e] = 0x00;
    DAT_EXTMEM_5000[0x08] = 0x06;
    DAT_EXTMEM_5000[0x06] = 0x1c;
    DAT_EXTMEM_5000[0x34] = 0xff;
    DAT_EXTMEM_5000[0x35] = 0x34;
    DAT_EXTMEM_5000[0x02] = 0x14;
    DAT_EXTMEM_5000[0x00] = 0x88;
    DAT_EXTMEM_5000[0x0c] = 0x35;
    DAT_EXTMEM_5000[0x0b] = 0xff;
    DAT_EXTMEM_5000[0x0a] = 0x20;
    DAT_EXTMEM_5100[0x09] = 0x93;
    DAT_EXTMEM_5100[0x05] = 0x53;
    DAT_EXTMEM_5100[0x0e] = 0x00;
    DAT_EXTMEM_5100[0x08] = 0x06;
    DAT_EXTMEM_5100[0x06] = 0x1c;
    DAT_EXTMEM_5100[0x34] = 0xff;
    DAT_EXTMEM_5100[0x35] = 0x34;
    DAT_EXTMEM_5100[0x02] = 0x14;
    DAT_EXTMEM_5100[0x00] = 0x88;
    DAT_EXTMEM_5100[0x0c] = 0x35;
    DAT_EXTMEM_5100[0x0b] = 0xff;
    DAT_EXTMEM_5100[0x0a] = 0x20;
    if (DAT_EXTMEM_d511 == 0x20)
        DAT_EXTMEM_e135 |= 0xc0;
    DAT_EXTMEM_d929 = 0x71;
    DAT_EXTMEM_d90b &= 0x7f;
    DAT_EXTMEM_d904 &= 0x0f;
    DAT_EXTMEM_d905 &= 0x7f;
    DAT_EXTMEM_d90c |= 0x01;
    if (DAT_EXTMEM_d511 == 0x20) {
        DAT_EXTMEM_d910 = 0x00;
        DAT_EXTMEM_d904 &= 0x01;
        DAT_EXTMEM_d911 = 0x00;
        DAT_EXTMEM_d912 = 0x00;
        DAT_EXTMEM_d90f &= 0x7f;
        DAT_EXTMEM_d92d &= 0x3f;
        DAT_EXTMEM_da00 &= 0xfe;
        DAT_EXTMEM_e1bf &= 0x7f;
        DAT_EXTMEM_e1cf &= 0x7f;
        DAT_EXTMEM_e1d8 = 0x00;
        DAT_EXTMEM_e1e0 &= 0x80;
        DAT_EXTMEM_e1e2 &= 0x8f;
        DAT_EXTMEM_e1ec &= 0x80;
        DAT_EXTMEM_e1ee &= 0x80;
        DAT_EXTMEM_e19f &= 0x7f;
        DAT_EXTMEM_e1af &= 0x7f;
        DAT_EXTMEM_e12b &= 0x7f;
    }
    DAT_EXTMEM_d52c |= 0x0c;
    DAT_EXTMEM_d52d |= 0x82;
    FUN_CODE_dc51();
    DAT_EXTMEM_a6ee = 0;
    if (!(DAT_EXTMEM_d511 == 0x20))
        FUN_CODE_daad();
    FUN_CODE_a142(1);
}
