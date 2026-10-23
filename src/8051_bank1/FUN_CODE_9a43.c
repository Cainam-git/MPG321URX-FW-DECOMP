/* 8051_bank1 FUN_CODE_9a43 @ 0x9A43..0x9B11 (206 bytes), OPTIMIZE(7,SPEED) (the same bytes at OPTIMIZE(8,SPEED) LARGE).
 * FUN_CODE_9a43(sel, a, b): writes a and b to one pair of XDATA registers chosen by sel: 1 0xF0B0/0xF0C7,
 * 2 0xF0B1/0xF0C8, 3 0xF0B2/0xF0C9, 4 0xF0B3/0xF0CA, 5 0xF0B4/0xF0CB, 6 0xF0B5/0xF0CE, 7 0xF0B6/0xF0CF,
 * 8 0xF130/0xF138, 9 0xF131/0xF139, 10 0xF132/0xF13A, 11 0xF133/0xF13B, 12 0xF134/0xF13C, 13 0xF135/0xF13D;
 * other values write nothing. Keil switch with a jump table at 0x9A5B (13 LJMPs); each case ends in its own RET.
 * No LCALL/LJMP to 0x9A43 occurs in the bank-1 image. The registers are hardware registers (volatile). No aids.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f0b0, DAT_EXTMEM_f0b1, DAT_EXTMEM_f0b2, DAT_EXTMEM_f0b3;
extern unsigned char volatile xdata DAT_EXTMEM_f0b4, DAT_EXTMEM_f0b5, DAT_EXTMEM_f0b6;
extern unsigned char volatile xdata DAT_EXTMEM_f0c7, DAT_EXTMEM_f0c8, DAT_EXTMEM_f0c9, DAT_EXTMEM_f0ca;
extern unsigned char volatile xdata DAT_EXTMEM_f0cb, DAT_EXTMEM_f0ce, DAT_EXTMEM_f0cf;
extern unsigned char volatile xdata DAT_EXTMEM_f130, DAT_EXTMEM_f131, DAT_EXTMEM_f132, DAT_EXTMEM_f133;
extern unsigned char volatile xdata DAT_EXTMEM_f134, DAT_EXTMEM_f135;
extern unsigned char volatile xdata DAT_EXTMEM_f138, DAT_EXTMEM_f139, DAT_EXTMEM_f13a, DAT_EXTMEM_f13b;
extern unsigned char volatile xdata DAT_EXTMEM_f13c, DAT_EXTMEM_f13d;

void FUN_CODE_9a43(unsigned char sel, unsigned char a, unsigned char b)
{
    switch (sel) {
    case 1: DAT_EXTMEM_f0b0 = a; DAT_EXTMEM_f0c7 = b; break;
    case 2: DAT_EXTMEM_f0b1 = a; DAT_EXTMEM_f0c8 = b; break;
    case 3: DAT_EXTMEM_f0b2 = a; DAT_EXTMEM_f0c9 = b; break;
    case 4: DAT_EXTMEM_f0b3 = a; DAT_EXTMEM_f0ca = b; break;
    case 5: DAT_EXTMEM_f0b4 = a; DAT_EXTMEM_f0cb = b; break;
    case 6: DAT_EXTMEM_f0b5 = a; DAT_EXTMEM_f0ce = b; break;
    case 7: DAT_EXTMEM_f0b6 = a; DAT_EXTMEM_f0cf = b; break;
    case 8: DAT_EXTMEM_f130 = a; DAT_EXTMEM_f138 = b; break;
    case 9: DAT_EXTMEM_f131 = a; DAT_EXTMEM_f139 = b; break;
    case 10: DAT_EXTMEM_f132 = a; DAT_EXTMEM_f13a = b; break;
    case 11: DAT_EXTMEM_f133 = a; DAT_EXTMEM_f13b = b; break;
    case 12: DAT_EXTMEM_f134 = a; DAT_EXTMEM_f13c = b; break;
    case 13: DAT_EXTMEM_f135 = a; DAT_EXTMEM_f13d = b; break;
    }
}
