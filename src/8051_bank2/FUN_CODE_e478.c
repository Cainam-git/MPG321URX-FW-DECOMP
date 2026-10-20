/* 8051_bank2 FUN_CODE_e478 @ 0xe478  update agent: base delay (byte-exact with OPTIMIZE(8,SPEED)
 * LARGE). Spins over a NOP as many times as the 16-bit calibration value in XDATA 0x09D0 says.
 */
extern unsigned char xdata DAT_EXTMEM_0436[];
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char FUN_CODE_bba9(unsigned char addr, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e4bf(unsigned char *buf);
void FUN_CODE_e44b(unsigned char n);
void FUN_CODE_e478(void);
#include <intrins.h>
extern unsigned int xdata DAT_EXTMEM_09d0;
void FUN_CODE_e478(void)
{
    unsigned int n;
    n = DAT_EXTMEM_09d0;
    while (n--) _nop_();
}
