/* 8051_bank2 FUN_CODE_e27c @ 0xe27c  OPTIMIZE(8,SPEED) LARGE, twin of 8051_bank2/FUN_CODE_e24d
 * Same instruction shape as FUN_CODE_e24d (src/8051_bank2/FUN_CODE_e24d.c); the addresses and constants are the ones in the code below.
 */
extern unsigned char xdata DAT_EXTMEM_0436[];
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char FUN_CODE_bba9(unsigned char addr, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e4b9(void);
void FUN_CODE_e4bf(unsigned char *buf);
void FUN_CODE_e44b(unsigned char t);
unsigned char FUN_CODE_da8a(unsigned int reg, unsigned char val);
void FUN_CODE_e27c(unsigned char a)
{
    unsigned char r;
    DAT_EXTMEM_0436[0] = 2;
    DAT_EXTMEM_0436[1] = 0x000f;
    DAT_EXTMEM_0436[2] = a;
    r = FUN_CODE_bfcf(0x6e, 3, DAT_EXTMEM_0436);
    FUN_CODE_d059(100);
    FUN_CODE_e4bf(DAT_EXTMEM_0436);
}
