/* 8051_bank1 FUN_CODE_afdc @ 0xafdc (written from the firmware)
 * Register set-up by XDATA 0xD511 (0x20 / 0x1A / other): F160..F165 = FF 1F F3 (FF or 3F) 00 FF;
 * F3E9 = 0x0F for 0x1A; then for 0x1A: F024 |= 1C, F02C |= 03, F02D |= BF, F030 |= 04; else F024 |= DC, F02C |= 3F,
 * F02D |= FF, F030 |= BF (0x20) or BB; finally F0A6 |= 3E.
 * volatile is real: 0xD511 is re-read for every test (4 reads), and 'F02D |= 0xFF' keeps its read (MOVX A,@DPTR then
 * MOV A,#0FFH); without volatile on F02D 81.6 %, without it on D511 57.8 %.
 * The second 0x1A test is XRL A,#1AH / JNZ in the firmware: '!(d511 ^ 0x1a)' gives it, '== 0x1a' gives CJNE (147 vs
 * 146 B) and a one-case switch gives 98.6 %.
 * Only caller 0x4087 (FUN_CODE_3fe7).
 * Options: OPTIMIZE(8,SPEED).
 */
extern unsigned char xdata DAT_EXTMEM_f160, DAT_EXTMEM_f161, DAT_EXTMEM_f162, DAT_EXTMEM_f163, DAT_EXTMEM_f164, DAT_EXTMEM_f165;
extern unsigned char volatile xdata DAT_EXTMEM_d511;
extern unsigned char xdata DAT_EXTMEM_f3e9;
extern unsigned char xdata DAT_EXTMEM_f024, DAT_EXTMEM_f02c, DAT_EXTMEM_f030, DAT_EXTMEM_f0a6;
extern unsigned char volatile xdata DAT_EXTMEM_f02d;
void FUN_CODE_afdc(void)
{
    DAT_EXTMEM_f160 = 0xff;
    DAT_EXTMEM_f161 = 0x1f;
    DAT_EXTMEM_f162 = 0xf3;
    if (DAT_EXTMEM_d511 == 0x20) DAT_EXTMEM_f163 = 0xff;
    else DAT_EXTMEM_f163 = 0x3f;
    DAT_EXTMEM_f164 = 0;
    DAT_EXTMEM_f165 = 0xff;
    if (DAT_EXTMEM_d511 == 0x1a) DAT_EXTMEM_f3e9 = 0x0f;
    if (!(DAT_EXTMEM_d511 ^ 0x1a)) {
        DAT_EXTMEM_f024 |= 0x1c;
        DAT_EXTMEM_f02c |= 0x03;
        DAT_EXTMEM_f02d |= 0xbf;
        DAT_EXTMEM_f030 |= 0x04;
    } else {
        DAT_EXTMEM_f024 |= 0xdc;
        DAT_EXTMEM_f02c |= 0x3f;
        DAT_EXTMEM_f02d |= 0xff;
        if (DAT_EXTMEM_d511 == 0x20) DAT_EXTMEM_f030 |= 0xbf;
        else DAT_EXTMEM_f030 |= 0xbb;
    }
    DAT_EXTMEM_f0a6 |= 0x3e;
}
