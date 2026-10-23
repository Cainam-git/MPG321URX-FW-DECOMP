/* 8051_bank2 FUN_CODE_e4c9 @ 0xe4c9  update agent: read one entry of the table at XDATA 0x07D3 indexed by XDATA
 * 0x075B (OPTIMIZE(8,SPEED) LARGE).
 */
extern unsigned char xdata DAT_EXTMEM_0436[];
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char FUN_CODE_bba9(unsigned char addr, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e4bf(unsigned char *buf);
void FUN_CODE_e44b(unsigned char n);
void FUN_CODE_e478(void);
extern unsigned char xdata DAT_EXTMEM_07d3[];
extern unsigned char xdata DAT_EXTMEM_075b;
unsigned char FUN_CODE_e4c9(void)
{
    return DAT_EXTMEM_07d3[DAT_EXTMEM_075b];
}
