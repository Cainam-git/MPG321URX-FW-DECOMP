/* 8051_bank1 FUN_CODE_c1c1 @ 0xc1c1 (92 B)  Byte-exact with OPTIMIZE(7,SPEED).
 * Runs in register bank 3 ('using 3': PUSH PSW, PSW = 0x18). Two identical event checks: when bit 0 of XDATA 0xDCDF
 * and bit 3 of 0xDCDE are set, it calls FUN_CODE_9339 (bit 0x15 = BITS_22_5 set) or FUN_CODE_b979 (clear) and then
 * sets bit 3 of 0xDCDE again; the same with 0xDCCF / 0xDCCE and FUN_CODE_914b / FUN_CODE_b8fd. Finally it calls
 * FUN_CODE_d214 when the chip ID XDATA 0xD511 is not 0x20. Only caller FUN_CODE_3091 (0x3107).
 * The bit tests are int-typed ('ANL A,#n / JZ'). The chip-ID test goes through a bit value (CJNE, SETB C / CLR C,
 * JC): written as a '(bit)' conversion of the comparison.
 */
extern unsigned char xdata DAT_EXTMEM_dcdf, DAT_EXTMEM_dcde, DAT_EXTMEM_dccf, DAT_EXTMEM_dcce, DAT_EXTMEM_d511;
extern bit BITS_22_5;
void FUN_CODE_9339(void);
void FUN_CODE_b979(void);
void FUN_CODE_914b(void);
void FUN_CODE_b8fd(void);
void FUN_CODE_d214(void);

void FUN_CODE_c1c1(void) using 3
{
    if ((unsigned int)(DAT_EXTMEM_dcdf & 0x01) && (unsigned int)(DAT_EXTMEM_dcde & 0x08)) {
        if (BITS_22_5) FUN_CODE_9339(); else FUN_CODE_b979();
        DAT_EXTMEM_dcde |= 0x08;
    }
    if ((unsigned int)(DAT_EXTMEM_dccf & 0x01) && (unsigned int)(DAT_EXTMEM_dcce & 0x08)) {
        if (BITS_22_5) FUN_CODE_914b(); else FUN_CODE_b8fd();
        DAT_EXTMEM_dcce |= 0x08;
    }
    if (!(bit)(DAT_EXTMEM_d511 == 0x20)) FUN_CODE_d214();
}
