/* 8051_bank1 FUN_CODE_aeb2 @ 0xaeb2 .. 0xaf47 (written from the firmware)
 * Returns one XDATA byte selected by n: n = 1..12 reads 0xF3C5, F3C6, F3C7, F3C8, F3C9, F3CA, F3CB, F3CC, F3D5,
 * F3D6, F5D5, F5D6; any other n returns 0xFF. Keil switch: DEC A / CJNE A,#0CH / JC, 3-byte LJMP table at 0xaeca,
 * case bodies 0xaeee..0xaf41, default 0xaf42 (MOV R6,#0FFH), shared tail MOV R7,AR6 / RET.
 */
extern unsigned char xdata DAT_EXTMEM_f3c5;
extern unsigned char xdata DAT_EXTMEM_f3c6;
extern unsigned char xdata DAT_EXTMEM_f3c7;
extern unsigned char xdata DAT_EXTMEM_f3c8;
extern unsigned char xdata DAT_EXTMEM_f3c9;
extern unsigned char xdata DAT_EXTMEM_f3ca;
extern unsigned char xdata DAT_EXTMEM_f3cb;
extern unsigned char xdata DAT_EXTMEM_f3cc;
extern unsigned char xdata DAT_EXTMEM_f3d5;
extern unsigned char xdata DAT_EXTMEM_f3d6;
extern unsigned char xdata DAT_EXTMEM_f5d5;
extern unsigned char xdata DAT_EXTMEM_f5d6;
unsigned char FUN_CODE_aeb2(unsigned char n)
{
    unsigned char r;
    switch (n) {
    case 1: r = DAT_EXTMEM_f3c5; break;
    case 2: r = DAT_EXTMEM_f3c6; break;
    case 3: r = DAT_EXTMEM_f3c7; break;
    case 4: r = DAT_EXTMEM_f3c8; break;
    case 5: r = DAT_EXTMEM_f3c9; break;
    case 6: r = DAT_EXTMEM_f3ca; break;
    case 7: r = DAT_EXTMEM_f3cb; break;
    case 8: r = DAT_EXTMEM_f3cc; break;
    case 9: r = DAT_EXTMEM_f3d5; break;
    case 10: r = DAT_EXTMEM_f3d6; break;
    case 11: r = DAT_EXTMEM_f5d5; break;
    case 12: r = DAT_EXTMEM_f5d6; break;
    default: r = 0xff; break;
    }
    return r;
}
