/* 8051_bank2 FUN_CODE_e2ab @ 0xe2ab
 * Service command 02 36 <a> to slave 0x6E (FUN_CODE_bfcf, status not kept), wait 4000, reply read through the entry
 * block FUN_CODE_e4b9 (declared void(void) as in FUN_CODE_e24d), returns the reply bytes
 * buf[2]:buf[3] as unsigned int (R6:R7). Only caller 0xa169 (FUN_CODE_9f8f). Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 */
extern unsigned char xdata DAT_EXTMEM_0436[];
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e4b9(void);
unsigned int FUN_CODE_e2ab(unsigned char a)
{
    DAT_EXTMEM_0436[0] = 2;
    DAT_EXTMEM_0436[1] = 0x36;
    DAT_EXTMEM_0436[2] = a;
    FUN_CODE_bfcf(0x6e, 3, DAT_EXTMEM_0436);
    FUN_CODE_d059(4000);
    FUN_CODE_e4b9();
    return ((unsigned int)DAT_EXTMEM_0436[2] << 8) | DAT_EXTMEM_0436[3];
}
