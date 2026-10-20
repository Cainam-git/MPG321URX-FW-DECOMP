/* 8051_bank2 FUN_CODE_e4bf @ 0xe4bf  update agent: read the reply of the last service-bus command (byte-exact
 * with OPTIMIZE(8,SPEED) LARGE).
 * FUN_CODE_bba9(0x6E, buf) reads the slave's answer into buf, then waits 2 units (FUN_CODE_e44b). Most callers use
 * the shared buffer XDATA 0x0436 through the 6-byte entry block FUN_CODE_e4b9 in front of this function (Keil common
 * entry code: R3/R2/R1 = 0x01:0x0436); FUN_CODE_e24d, e3ab and e2da jump here directly with the same buffer.
 */
extern unsigned char xdata DAT_EXTMEM_0436[];
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char FUN_CODE_bba9(unsigned char addr, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e4bf(unsigned char *buf);
void FUN_CODE_e44b(unsigned char n);
void FUN_CODE_e478(void);
void FUN_CODE_e4bf(unsigned char *buf)
{
    FUN_CODE_bba9(0x6e, buf);
    FUN_CODE_e44b(2);
}
