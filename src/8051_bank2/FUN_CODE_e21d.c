/* 8051_bank2 FUN_CODE_e21d @ 0xe21d  update agent: set scaler registers 0xF1EB / 0xF1E0 for a mode
 * (OPTIMIZE(8,SPEED) LARGE).
 * Waits 50 units (FUN_CODE_e44b(0x32)), then over the service bus (FUN_CODE_da8a): mode 0 -> 0xF1EB = 0x82,
 * 0xF1E0 = 0x0A; otherwise -> 0xF1EB = 0x8A, 0xF1E0 = 0x02. Called with 1 from FUN_CODE_a8a3 on the way into ROM ISP
 * (the reference write-up lists the same two writes for FUN_E21D(1)).
 */
extern unsigned char xdata DAT_EXTMEM_0436[];
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char FUN_CODE_bba9(unsigned char addr, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e4b9(void);
void FUN_CODE_e4bf(unsigned char *buf);
void FUN_CODE_e44b(unsigned char t);
unsigned char FUN_CODE_da8a(unsigned int reg, unsigned char val);
void FUN_CODE_e21d(unsigned char a)
{
    FUN_CODE_e44b(0x32);
    if (a == 0) {
        FUN_CODE_da8a(0xf1eb, 0x82);
        FUN_CODE_da8a(0xf1e0, 0x0a);
    } else {
        FUN_CODE_da8a(0xf1eb, 0x8a);
        FUN_CODE_da8a(0xf1e0, 0x02);
    }
}
