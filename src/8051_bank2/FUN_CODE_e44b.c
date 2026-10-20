/* 8051_bank2 FUN_CODE_e44b @ 0xe44b  update agent: delay (byte-exact with OPTIMIZE(8,SPEED) LARGE
 * REGFILE(R.ORC)). Calls the base delay FUN_CODE_e478 four times per unit, n units (n in R7, counted in R5).
 */
extern unsigned char xdata DAT_EXTMEM_0436[];
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char FUN_CODE_bba9(unsigned char addr, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e4bf(unsigned char *buf);
void FUN_CODE_e44b(unsigned char n);
void FUN_CODE_e478(void);
void FUN_CODE_e44b(unsigned char n)
{
    while (n--) {
        FUN_CODE_e478();
        FUN_CODE_e478();
        FUN_CODE_e478();
        FUN_CODE_e478();
    }
}
