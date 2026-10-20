/* 8051_bank1 FUN_CODE_cc7d @ 0xcc7d  (from a mechanical draft with the
 * loop bound fixed: the firmware compares i with 0x00F0 = MOV A,R7 / XRL A,#0F0H / ORL A,R6 / JNZ)
 * Register bank 3 (PUSH PSW, PSW = 0x18). XDATA 0xCC8B &= 0xF7; writes 55 55 to 0xD909 / 0xD90A, 04 / 03 / FE to
 * 0xD906 / 0xD905 / 0xD904, 84 / 30 to 0xD90B / 0xD90C, then 0xF0 x NOP.
 * Byte-exact with OPTIMIZE(8,SPEED) (MATCH exact None 69/69; also level 7 and LARGE: i lives in R6:R7). Only caller 0xd220.
 */
#include <intrins.h>

extern unsigned char xdata DAT_EXTMEM_cc8b;
extern unsigned char xdata DAT_EXTMEM_d904;
extern unsigned char xdata DAT_EXTMEM_d905;
extern unsigned char xdata DAT_EXTMEM_d906;
extern unsigned char xdata DAT_EXTMEM_d909;
extern unsigned char xdata DAT_EXTMEM_d90a;
extern unsigned char xdata DAT_EXTMEM_d90b;
extern unsigned char xdata DAT_EXTMEM_d90c;

void FUN_CODE_cc7d(void) using 3
{
    unsigned int i;

    DAT_EXTMEM_cc8b &= 0xf7;
    DAT_EXTMEM_d909 = 0x55;
    DAT_EXTMEM_d90a = 0x55;
    DAT_EXTMEM_d906 = 0x04;
    DAT_EXTMEM_d905 = 0x03;
    DAT_EXTMEM_d904 = 0xfe;
    DAT_EXTMEM_d90b = 0x84;
    DAT_EXTMEM_d90c = 0x30;

    for (i = 0; i != 0xf0; i++) {
        _nop_();
    }
}
