/* 8051_bank1 FUN_CODE_8a51 @ 0x8a51..0x8b58 (263 bytes), OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_8a51(m): passes the format at CODE 0x6AC3 ("DP_EnableMRX (%bx)\r\n") with m to FUN_CODE_2820. For m == 0
 * XDATA 0xDCDE = 0x95 and 0xDCDF = 5, then bit 3 cleared, then 1, and XDATA 0xA6F2 = 0; otherwise the same on
 * 0xDCCE/0xDCCF with 9 and bit 2, and XDATA 0xA6F9 = 0. Then bit 1 of 0xDCDF and 0xDCCF is cleared, 0xDCDF gets
 * bit 2 set and bit 3 cleared, 0xDCCF bit 3 set and bit 2 cleared, the low two bits of 0xF161 are cleared and
 * XDATA 0xA6FD = 0x22. Seven bytes are copied to XDATA 0xE140.. from the CODE table chosen by XDATA 0xD511 (0x1A:
 * 0x6BFE, 0x20: 0x6C05, 0x16/0x1E/0x1F/0x17: 0x6BF7, else none), and 0xCC87 gets 0x18 (0xD511 == 0x1A) or 0x08
 * ORed in. With 0xD511 == 0x20: bit 0x00 = bit 0x15, FUN_CODE_b56a, then FUN_CODE_45aa and FUN_CODE_942e for ch 0
 * and 1; otherwise bit 0x15 is set.
 * volatile on 0xD511 (read again for every compare of the chain) and on the two-byte groups 0xDCDE and 0xDCCE (the
 * firmware reads 0xDCDF / 0xDCCF back after each store; INC DPTR from the first byte = one object each).
 * Source form: the last test is '!(d511 == 0x20)', which Keil turns into the firmware's SETB C / CLR C / JC.
 * Callers: FUN_CODE_883d (0x8901, 0x893C) and FUN_CODE_dd09 (0xDD14, tail jump at 0xDD19).
 */
extern unsigned char volatile xdata DAT_EXTMEM_dcde[2];
extern unsigned char volatile xdata DAT_EXTMEM_dcce[2];
extern unsigned char xdata DAT_EXTMEM_f161;
extern unsigned char xdata DAT_EXTMEM_cc87;
extern unsigned char volatile xdata DAT_EXTMEM_d511;
extern unsigned char xdata DAT_EXTMEM_e140[7];
extern unsigned char xdata DAT_EXTMEM_a6f2;
extern unsigned char xdata DAT_EXTMEM_a6f9;
extern unsigned char xdata DAT_EXTMEM_a6fd;
extern unsigned char code DAT_CODE_6bf7[7];
extern unsigned char code DAT_CODE_6bfe[7];
extern unsigned char code DAT_CODE_6c05[7];
extern bit BITS_20_0;
extern bit BITS_22_5;
extern void FUN_CODE_2820(void *fmt, ...) large;
extern void FUN_CODE_b56a(void);
extern void FUN_CODE_45aa(unsigned char ch);
extern void FUN_CODE_942e(unsigned char ch);

void FUN_CODE_8a51(unsigned char m)
{
    unsigned char i;

    FUN_CODE_2820((void code *)0x6ac3, m);
    if (m == 0) {
        DAT_EXTMEM_dcde[0] = 0x95;
        DAT_EXTMEM_dcde[1] = 0x05;
        DAT_EXTMEM_dcde[1] &= ~0x08;
        DAT_EXTMEM_dcde[1] = 0x01;
        DAT_EXTMEM_a6f2 = 0;
    } else {
        DAT_EXTMEM_dcce[0] = 0x95;
        DAT_EXTMEM_dcce[1] = 0x09;
        DAT_EXTMEM_dcce[1] &= ~0x04;
        DAT_EXTMEM_dcce[1] = 0x01;
        DAT_EXTMEM_a6f9 = 0;
    }
    DAT_EXTMEM_dcde[1] &= ~0x02;
    DAT_EXTMEM_dcce[1] &= ~0x02;
    DAT_EXTMEM_dcde[1] |= 0x04;
    DAT_EXTMEM_dcde[1] &= ~0x08;
    DAT_EXTMEM_dcce[1] |= 0x08;
    DAT_EXTMEM_dcce[1] &= ~0x04;
    DAT_EXTMEM_f161 &= 0xfc;
    DAT_EXTMEM_a6fd = 0x22;
    for (i = 0; i < 7; i++) {
        if (DAT_EXTMEM_d511 == 0x1a)
            DAT_EXTMEM_e140[i] = DAT_CODE_6bfe[i];
        else if (DAT_EXTMEM_d511 == 0x20)
            DAT_EXTMEM_e140[i] = DAT_CODE_6c05[i];
        else if (DAT_EXTMEM_d511 == 0x16 || DAT_EXTMEM_d511 == 0x1e || DAT_EXTMEM_d511 == 0x1f || DAT_EXTMEM_d511 == 0x17)
            DAT_EXTMEM_e140[i] = DAT_CODE_6bf7[i];
    }
    if (DAT_EXTMEM_d511 == 0x1a)
        DAT_EXTMEM_cc87 |= 0x18;
    else
        DAT_EXTMEM_cc87 |= 0x08;
    if (DAT_EXTMEM_d511 == 0x20) {
        BITS_20_0 = BITS_22_5;
        FUN_CODE_b56a();
        FUN_CODE_45aa(0);
        FUN_CODE_942e(0);
        FUN_CODE_45aa(1);
        FUN_CODE_942e(1);
    }
    if (!(DAT_EXTMEM_d511 == 0x20))
        BITS_22_5 = 1;
}
