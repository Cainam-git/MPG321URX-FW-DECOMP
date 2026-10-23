/* 8051_bank1 FUN_CODE_af47 @ 0xaf47 .. 0xafdb (written from the firmware)
 * bit: (register n & mask) != 0. n = 1..13 selects XDATA 0xF000, F001, F002, F003, F004, F010, F012, F114, F116, F118,
 * F11A, F11C, F11E; n = 14 reads SFR P3 (MOV A,0B0H); any other n gives 0. Keil switch: DEC A / CJNE A,#0EH / JC,
 * 3-byte LJMP table at 0xaf5f; the shared tail MOVX A,@DPTR / ANL A,R5 / MOV R6,A is cross-jumped (0xafc8).
 * functions.json size 33 is the code before the table; the judged span is 0xaf47..0xafdc (149 B). No volatile needed
 * (each register is read once). 'return r != 0;' also matches; 'return r;' does not.
 * Callers 0x5a85 (FUN_CODE_5a39), 0xa0f2 (FUN_CODE_a085), 0xae3d, 0xae4e (FUN_CODE_ae1d).
 * Options: OPTIMIZE(8,SPEED) (also with REGFILE(R.ORC)).
 */
#include <reg51.h>
extern unsigned char xdata DAT_EXTMEM_f000;
extern unsigned char xdata DAT_EXTMEM_f001;
extern unsigned char xdata DAT_EXTMEM_f002;
extern unsigned char xdata DAT_EXTMEM_f003;
extern unsigned char xdata DAT_EXTMEM_f004;
extern unsigned char xdata DAT_EXTMEM_f010;
extern unsigned char xdata DAT_EXTMEM_f012;
extern unsigned char xdata DAT_EXTMEM_f114;
extern unsigned char xdata DAT_EXTMEM_f116;
extern unsigned char xdata DAT_EXTMEM_f118;
extern unsigned char xdata DAT_EXTMEM_f11a;
extern unsigned char xdata DAT_EXTMEM_f11c;
extern unsigned char xdata DAT_EXTMEM_f11e;
bit FUN_CODE_af47(unsigned char n, unsigned char mask)
{
    unsigned char r;
    switch (n) {
    case 1: r = DAT_EXTMEM_f000 & mask; break;
    case 2: r = DAT_EXTMEM_f001 & mask; break;
    case 3: r = DAT_EXTMEM_f002 & mask; break;
    case 4: r = DAT_EXTMEM_f003 & mask; break;
    case 5: r = DAT_EXTMEM_f004 & mask; break;
    case 6: r = DAT_EXTMEM_f010 & mask; break;
    case 7: r = DAT_EXTMEM_f012 & mask; break;
    case 8: r = DAT_EXTMEM_f114 & mask; break;
    case 9: r = DAT_EXTMEM_f116 & mask; break;
    case 10: r = DAT_EXTMEM_f118 & mask; break;
    case 11: r = DAT_EXTMEM_f11a & mask; break;
    case 12: r = DAT_EXTMEM_f11c & mask; break;
    case 13: r = DAT_EXTMEM_f11e & mask; break;
    case 14: r = P3 & mask; break;
    default: r = 0; break;
    }
    if (r) return 1;
    return 0;
}
