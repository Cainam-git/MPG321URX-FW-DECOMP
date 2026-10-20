/* 8051_bank2 FUN_CODE_e24d @ 0xe24d  update agent: send service command 02 A3 <a> (byte-exact with
 * OPTIMIZE(8,SPEED) LARGE).
 * Sends 02 A3 <a> to slave 0x6E (FUN_CODE_bfcf), keeps the status in its own local, waits 100 units and finishes with
 * the reply read FUN_CODE_e4bf(buf) (tail call). FUN_CODE_a8a3 calls it with 0xF3 as the last step before handing the
 * chip to ROM ISP.
 */
extern unsigned char xdata DAT_EXTMEM_0436[];
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char FUN_CODE_bba9(unsigned char addr, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e4b9(void);
void FUN_CODE_e4bf(unsigned char *buf);
void FUN_CODE_e44b(unsigned char t);
unsigned char FUN_CODE_da8a(unsigned int reg, unsigned char val);
void FUN_CODE_e24d(unsigned char a)
{
    unsigned char r;
    DAT_EXTMEM_0436[0] = 2;
    DAT_EXTMEM_0436[1] = 0xa3;
    DAT_EXTMEM_0436[2] = a;
    r = FUN_CODE_bfcf(0x6e, 3, DAT_EXTMEM_0436);
    FUN_CODE_d059(100);
    FUN_CODE_e4bf(DAT_EXTMEM_0436);
}
