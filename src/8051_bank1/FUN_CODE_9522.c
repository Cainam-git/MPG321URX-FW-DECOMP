/* 8051_bank1 FUN_CODE_9522 @ 0x9522..0x960f (237 bytes), OPTIMIZE(8,SPEED).
 * Clears XDATA 0xA782 and passes the string at CODE 0xDD1C ("Initial CC PHY!!\r\n") to FUN_CODE_2820. Then it
 * writes one of two byte sets into the register block that the generic pointer at XDATA 0xA76D points to: with
 * XDATA 0xD511 == 0x20 bytes 1..8, 0x0A, 0x0B = 01 0D F6 F6 F3 B0 00 88, 1C D1; otherwise bytes 0..6, 8, 0x0A,
 * 0x0B = 43 7D 0F C5 C5 03 80, 66, 1D A0. With XDATA 0xA6A6 == 1 it sets bit 0x16, XDATA 0xA780 = 2 and jumps to
 * FUN_CODE_a959; otherwise bit 0x17, XDATA 0xA781 = 2 and FUN_CODE_a9f6.
 * The pointee is volatile as in FUN_CODE_a959 (register block); the stores go through ?C?CSTOPTR / ?C?CSTPTR and
 * both branches share the final 'LCALL ?C?CSTOPTR' for byte 0x0B.
 * Caller: FUN_CODE_dc92.
 */
extern unsigned char volatile * xdata DAT_EXTMEM_a76d;
extern unsigned char xdata DAT_EXTMEM_d511;
extern unsigned char xdata DAT_EXTMEM_a6a6;
extern unsigned char xdata DAT_EXTMEM_a780;
extern unsigned char xdata DAT_EXTMEM_a781;
extern unsigned char xdata DAT_EXTMEM_a782;
extern bit BITS_22_6;
extern bit BITS_22_7;
extern void FUN_CODE_2820(void *fmt, ...) large;
extern void FUN_CODE_a959(void);
extern void FUN_CODE_a9f6(void);

void FUN_CODE_9522(void)
{
    DAT_EXTMEM_a782 = 0;
    FUN_CODE_2820((void code *)0xdd1c);
    if (DAT_EXTMEM_d511 == 0x20) {
        DAT_EXTMEM_a76d[1] = 0x01;
        DAT_EXTMEM_a76d[2] = 0x0d;
        DAT_EXTMEM_a76d[3] = 0xf6;
        DAT_EXTMEM_a76d[4] = 0xf6;
        DAT_EXTMEM_a76d[5] = 0xf3;
        DAT_EXTMEM_a76d[6] = 0xb0;
        DAT_EXTMEM_a76d[7] = 0x00;
        DAT_EXTMEM_a76d[8] = 0x88;
        DAT_EXTMEM_a76d[0x0a] = 0x1c;
        DAT_EXTMEM_a76d[0x0b] = 0xd1;
    } else {
        DAT_EXTMEM_a76d[0] = 0x43;
        DAT_EXTMEM_a76d[1] = 0x7d;
        DAT_EXTMEM_a76d[2] = 0x0f;
        DAT_EXTMEM_a76d[3] = 0xc5;
        DAT_EXTMEM_a76d[4] = 0xc5;
        DAT_EXTMEM_a76d[5] = 0x03;
        DAT_EXTMEM_a76d[6] = 0x80;
        DAT_EXTMEM_a76d[8] = 0x66;
        DAT_EXTMEM_a76d[0x0a] = 0x1d;
        DAT_EXTMEM_a76d[0x0b] = 0xa0;
    }
    if (DAT_EXTMEM_a6a6 == 1) {
        BITS_22_6 = 1;
        DAT_EXTMEM_a780 = 2;
        FUN_CODE_a959();
    } else {
        BITS_22_7 = 1;
        DAT_EXTMEM_a781 = 2;
        FUN_CODE_a9f6();
    }
}
