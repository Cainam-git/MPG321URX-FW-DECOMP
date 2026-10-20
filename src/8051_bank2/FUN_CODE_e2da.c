/* 8051_bank2 FUN_CODE_e2da @ 0xe2da  update agent: service command 01 11 (byte-exact with
 * OPTIMIZE(8,SPEED) LARGE). Sends 01 11 to slave 0x6E, keeps the status in a local, waits 100 units (FUN_CODE_d059)
 * and reads the reply (FUN_CODE_e4bf). Used by the flash identification FUN_CODE_0003 after each 0xF068 change.
 */
extern unsigned char xdata DAT_EXTMEM_0436[];
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char FUN_CODE_bba9(unsigned char addr, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e4bf(unsigned char *buf);
void FUN_CODE_e44b(unsigned char n);
void FUN_CODE_e478(void);
void FUN_CODE_e2da(void)
{
    unsigned char r;
    DAT_EXTMEM_0436[0] = 1;
    DAT_EXTMEM_0436[1] = 0x11;
    r = FUN_CODE_bfcf(0x6e, 2, DAT_EXTMEM_0436);
    FUN_CODE_d059(100);
    FUN_CODE_e4bf(DAT_EXTMEM_0436);
}
