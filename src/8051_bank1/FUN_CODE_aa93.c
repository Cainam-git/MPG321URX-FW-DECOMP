/* 8051_bank1 FUN_CODE_aa93 @ 0xAA93..0xAB2C (153 bytes), OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC).
 * Writes 0x82 to XDATA 0xF1C0, sets the XDATA byte pointer at 0xA74A to 0xF800 and sends the 0x200 bytes
 * 0xF800..0xF9FF to XDATA 0xF1C3 through it (?C?ILDIX). Then 0xF1C0 = 0x82 again and, twice: FUN_CODE_d5f3(6);
 * wait until bit 1 of FUN_CODE_cf73(5) is set; XDATA 0xF0F0..0xF0F2 = bytes 1..3 of the unsigned long at 0xA75F;
 * FUN_CODE_c5f0(); that long += 0x100; wait while bit 0 of FUN_CODE_cf73(5) is set. The counter i stays in
 * R2:R3 across the calls (whole-program register file). Same register sequence as FUN_CODE_6f26.
 * The 0xF0xx / 0xF1xx locations are hardware registers (volatile). No aids.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f1c0, DAT_EXTMEM_f1c3;
extern unsigned char volatile xdata DAT_EXTMEM_f0f0, DAT_EXTMEM_f0f1, DAT_EXTMEM_f0f2;
extern unsigned char xdata * xdata DAT_EXTMEM_a74a;
extern union { unsigned long l; unsigned char b[4]; } xdata DAT_EXTMEM_a75f;
void FUN_CODE_d5f3(unsigned char cmd);
unsigned char FUN_CODE_cf73(unsigned char cmd);
extern void FUN_CODE_c5f0(void);

void FUN_CODE_aa93(void)
{
    unsigned int i;

    DAT_EXTMEM_f1c0 = 0x82;
    DAT_EXTMEM_a74a = (unsigned char xdata *)0xf800;
    for (i = 0; i < 0x200; i++) DAT_EXTMEM_f1c3 = *DAT_EXTMEM_a74a++;
    DAT_EXTMEM_f1c0 = 0x82;
    for (i = 0; i < 2; i++) {
        FUN_CODE_d5f3(6);
        while (!(FUN_CODE_cf73(5) & 2)) ;
        DAT_EXTMEM_f0f0 = DAT_EXTMEM_a75f.b[1];
        DAT_EXTMEM_f0f1 = DAT_EXTMEM_a75f.b[2];
        DAT_EXTMEM_f0f2 = DAT_EXTMEM_a75f.b[3];
        FUN_CODE_c5f0();
        DAT_EXTMEM_a75f.l += 0x100;
        while (FUN_CODE_cf73(5) & 1) ;
    }
}
