/* 8051_bank1 FUN_CODE_acf2 @ 0xACF2..0xAD88 (150 bytes; unlisted code found in a gap of the function table).
 * FUN_CODE_acf2(sel, v): writes v to one XDATA register chosen by sel: 1 0xF000, 2 0xF001, 3 0xF002, 4 0xF003,
 * 5 0xF004, 6 0xF010, 7 0xF012, 8 0xF114, 9 0xF116, 10 0xF118, 11 0xF11A, 12 0xF11C, 13 0xF11E; 14 writes
 * v | 0xCC to port P3 (SFR 0xB0); other values write nothing. Keil switch with a jump table at 0xAD0A (14 LJMPs);
 * each case ends in its own RET. Counterpart of FUN_CODE_b33e (the odd registers 0xF005.., 0xF011.., 0xF115..).
 * No LCALL/LJMP to 0xACF2 occurs in the bank-1 image. No aids.
 */
sfr P3 = 0xb0;
extern unsigned char xdata DAT_EXTMEM_f000, DAT_EXTMEM_f001, DAT_EXTMEM_f002, DAT_EXTMEM_f003;
extern unsigned char xdata DAT_EXTMEM_f004, DAT_EXTMEM_f010, DAT_EXTMEM_f012, DAT_EXTMEM_f114;
extern unsigned char xdata DAT_EXTMEM_f116, DAT_EXTMEM_f118, DAT_EXTMEM_f11a, DAT_EXTMEM_f11c;
extern unsigned char xdata DAT_EXTMEM_f11e;

void FUN_CODE_acf2(unsigned char sel, unsigned char v)
{
    switch (sel) {
    case 1: DAT_EXTMEM_f000 = v; break;
    case 2: DAT_EXTMEM_f001 = v; break;
    case 3: DAT_EXTMEM_f002 = v; break;
    case 4: DAT_EXTMEM_f003 = v; break;
    case 5: DAT_EXTMEM_f004 = v; break;
    case 6: DAT_EXTMEM_f010 = v; break;
    case 7: DAT_EXTMEM_f012 = v; break;
    case 8: DAT_EXTMEM_f114 = v; break;
    case 9: DAT_EXTMEM_f116 = v; break;
    case 10: DAT_EXTMEM_f118 = v; break;
    case 11: DAT_EXTMEM_f11a = v; break;
    case 12: DAT_EXTMEM_f11c = v; break;
    case 13: DAT_EXTMEM_f11e = v; break;
    case 14: P3 = v | 0xcc; break;
    }
}
