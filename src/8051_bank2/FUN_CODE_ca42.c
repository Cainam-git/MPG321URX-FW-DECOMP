/* 8051_bank2 FUN_CODE_ca42 @ 0xca42  OPTIMIZE(8,SPEED) LARGE
 *
 * DUALFW tag block: build a 512-byte block in XDATA 0x0440..0x063F and send it.
 * Skipped (returns at once) when FUN_CODE_e4c9() != 0 (a byte of the table at XDATA 0x07D3 indexed by 0x075B).
 * Otherwise: service-bus register 0xF0DE = 0x23 then 0x21 (FUN_CODE_da8a), block filled with 0xFF, "DUALFW" at
 * block offset 0x1F0 (XDATA 0x0630, the same signature the bootloader looks for at flash 0x6FF0, docs/bootloader.md),
 * offset 0x1F6 = (mode bit 2 set) ? 2 * XDATA[0x0644] : 0x78, and with bit 2 clear 8 bytes from XDATA 0x064A..0x0651
 * copied to offsets 0x1F7..0x1FE. A 16-bit byte sum of the whole block is computed into a local (XDATA 0x08EF..0x08F0)
 * and never used (it is in the firmware bytes). Then FUN_CODE_e1c1(0), FUN_CODE_c52f(0x77, block) (c52f calls the service-bus function FUN_CODE_d275 for slave 0x6E),
 * and FUN_CODE_d059(200) wait.
 * mode (R7) is kept in the LARGE-model XDATA block at 0x08EE. The fill loop compiles to Keil's MOVX/INC DPTR/DJNZ
 * R7/DJNZ R6 idiom from a plain index loop (memset gives ?C?MEMSET instead).
 */
extern unsigned char xdata DAT_EXTMEM_0440[0x200];
extern unsigned char xdata DAT_EXTMEM_0644;
extern unsigned char xdata DAT_EXTMEM_064a[8];
extern unsigned char FUN_CODE_e4c9(void);
extern unsigned char FUN_CODE_da8a(unsigned int reg, unsigned char val);
extern void FUN_CODE_e1c1(unsigned char a);
extern void FUN_CODE_c52f(unsigned char dev, unsigned char *buf);
extern void FUN_CODE_d059(unsigned int t);

void FUN_CODE_ca42(unsigned char mode)
{
    unsigned int sum;
    unsigned int i;
    sum = 0;
    if (FUN_CODE_e4c9()) return;
    FUN_CODE_da8a(0xf0de, 0x23);
    FUN_CODE_da8a(0xf0de, 0x21);
    for (i = 0; i < 0x200; i++) DAT_EXTMEM_0440[i] = 0xff;
    DAT_EXTMEM_0440[0x1f0] = 'D';
    DAT_EXTMEM_0440[0x1f1] = 'U';
    DAT_EXTMEM_0440[0x1f2] = 'A';
    DAT_EXTMEM_0440[0x1f3] = 'L';
    DAT_EXTMEM_0440[0x1f4] = 'F';
    DAT_EXTMEM_0440[0x1f5] = 'W';
    if (mode & 4) {
        DAT_EXTMEM_0440[0x1f6] = DAT_EXTMEM_0644 * 2;
    } else {
        DAT_EXTMEM_0440[0x1f6] = 0x78;
        for (i = 0; i < 8; i++) DAT_EXTMEM_0440[0x1f7 + i] = DAT_EXTMEM_064a[i];
    }
    for (i = 0; i < 0x200; i++) sum += DAT_EXTMEM_0440[i];
    FUN_CODE_e1c1(0);
    FUN_CODE_c52f(0x77, DAT_EXTMEM_0440);
    FUN_CODE_d059(200);
}
