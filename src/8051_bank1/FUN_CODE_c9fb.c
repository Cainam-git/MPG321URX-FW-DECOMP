/* 8051_bank1 FUN_CODE_c9fb @ 0xc9fb
 * Same register writes as FUN_CODE_cc7d (XDATA 0xCC8B &= 0xF7; 0xD909 / 0xD90A = 0x55; 0xD906 / 0xD905 / 0xD904 =
 * 04 / 03 / FE; 0xD90B / 0xD90C = 84 / 30), then 0x3840 x NOP (fw CJNE R6,#38H / CJNE R7,#40H), then
 * XDATA 0xD929 = (FUN_CODE_d6bf() + 1) | 0x40 (the same statement as the accepted FUN_CODE_d24a). Callers 0x3fe9, 0x4287.
 * Byte-exact with OPTIMIZE(8,SPEED) and OPTIMIZE(7,SPEED) (i lives in R6:R7, no tail).
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
extern unsigned char xdata DAT_EXTMEM_d929;
unsigned char FUN_CODE_d6bf(void);

void FUN_CODE_c9fb(void)
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

    for (i = 0; i != 0x3840; i++) {
        _nop_();
    }
    DAT_EXTMEM_d929 = (FUN_CODE_d6bf() + 1) | 0x40;
}
