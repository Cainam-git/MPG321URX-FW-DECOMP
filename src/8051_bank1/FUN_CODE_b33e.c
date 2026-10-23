/* 8051_bank1 FUN_CODE_b33e @ 0xB33E..0xB3CB (141 bytes), OPTIMIZE(7,SPEED) (the same bytes at OPTIMIZE(8,SPEED) LARGE).
 * FUN_CODE_b33e(sel, v): writes v to one XDATA register chosen by sel: 1 0xF005, 2 0xF006, 3 0xF007, 4 0xF008,
 * 5 0xF009, 6 0xF011, 7 0xF013, 8 0xF115, 9 0xF117, 10 0xF119, 11 0xF11B, 12 0xF11D, 13 0xF11F; other values
 * write nothing. Keil switch with a jump table at 0xB356 (13 LJMPs); each case ends in its own RET.
 * No LCALL/LJMP to 0xB33E occurs in the bank-1 image. The registers are hardware registers (volatile). No aids.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f005, DAT_EXTMEM_f006, DAT_EXTMEM_f007, DAT_EXTMEM_f008;
extern unsigned char volatile xdata DAT_EXTMEM_f009, DAT_EXTMEM_f011, DAT_EXTMEM_f013, DAT_EXTMEM_f115;
extern unsigned char volatile xdata DAT_EXTMEM_f117, DAT_EXTMEM_f119, DAT_EXTMEM_f11b, DAT_EXTMEM_f11d;
extern unsigned char volatile xdata DAT_EXTMEM_f11f;

void FUN_CODE_b33e(unsigned char sel, unsigned char v)
{
    switch (sel) {
    case 1: DAT_EXTMEM_f005 = v; break;
    case 2: DAT_EXTMEM_f006 = v; break;
    case 3: DAT_EXTMEM_f007 = v; break;
    case 4: DAT_EXTMEM_f008 = v; break;
    case 5: DAT_EXTMEM_f009 = v; break;
    case 6: DAT_EXTMEM_f011 = v; break;
    case 7: DAT_EXTMEM_f013 = v; break;
    case 8: DAT_EXTMEM_f115 = v; break;
    case 9: DAT_EXTMEM_f117 = v; break;
    case 10: DAT_EXTMEM_f119 = v; break;
    case 11: DAT_EXTMEM_f11b = v; break;
    case 12: DAT_EXTMEM_f11d = v; break;
    case 13: DAT_EXTMEM_f11f = v; break;
    }
}
