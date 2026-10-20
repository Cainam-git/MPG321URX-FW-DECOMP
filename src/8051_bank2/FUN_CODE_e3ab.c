/* 8051_bank2 FUN_CODE_e3ab @ 0xe3ab  update agent: service command 01 25 (byte-exact with
 * OPTIMIZE(8,SPEED) LARGE). Sends 01 25 to slave 0x6E (FUN_CODE_bfcf), waits with timeout 0x0FA0 (FUN_CODE_d059) and
 * reads the reply (FUN_CODE_e4bf). Called by the SPI engine FUN_CODE_c0be right after the transfer set-up: it is the
 * "run the queued SPI transaction" command.
 */
extern unsigned char xdata DAT_EXTMEM_0436[];
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char FUN_CODE_bba9(unsigned char addr, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e4bf(unsigned char *buf);
void FUN_CODE_e44b(unsigned char n);
void FUN_CODE_e478(void);
void FUN_CODE_e3ab(void)
{
    DAT_EXTMEM_0436[0] = 1;
    DAT_EXTMEM_0436[1] = 0x25;
    FUN_CODE_bfcf(0x6e, 2, DAT_EXTMEM_0436);
    FUN_CODE_d059(0x0fa0);
    FUN_CODE_e4bf(DAT_EXTMEM_0436);
}
