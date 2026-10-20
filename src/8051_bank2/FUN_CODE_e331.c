/* 8051_bank2 FUN_CODE_e331 @ 0xe331
 * Service command 02 99 <a> to slave 0x6E (FUN_CODE_bfcf, status not kept), wait 4000 (FUN_CODE_d059), reply read
 * FUN_CODE_e4bf(buf) as tail LJMP; same form as FUN_CODE_e24d (02 A3 <a>, wait 100).
 * Callers 0xc1f7, 0xdd29 (FUN_CODE_dd1a), 0xe4a6. Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 */
extern unsigned char xdata DAT_EXTMEM_0436[];
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e4bf(unsigned char *buf);
void FUN_CODE_e331(unsigned char a)
{
    DAT_EXTMEM_0436[0] = 2;
    DAT_EXTMEM_0436[1] = 0x99;
    DAT_EXTMEM_0436[2] = a;
    FUN_CODE_bfcf(0x6e, 3, DAT_EXTMEM_0436);
    FUN_CODE_d059(4000);
    FUN_CODE_e4bf(DAT_EXTMEM_0436);
}
