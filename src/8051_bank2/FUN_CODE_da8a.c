/* 8051_bank2 FUN_CODE_da8a @ 0xda8a  update agent: write one scaler register over the service I2C bus
 * (byte-exact with OPTIMIZE(8,SPEED) LARGE).
 * Builds the packet 04 78 <reg hi> <reg lo> <val> in the shared buffer XDATA 0x0436 and sends it to I2C slave
 * 0x6E (the scaler's service address) with FUN_CODE_bfcf(addr, len, buf); waits 100 units (FUN_CODE_d059) and calls
 * FUN_CODE_e4b9 (reads the reply status into the same buffer); returns bfcf's status. Opcode 0x78 = register write
 * (matches the public MPG 341CQPX write-up, where this function is FUN_DA8A and 0x78 is the documented service
 * write). The agent writes scaler registers remotely this way, e.g. 0xD7E0 = 0x81 on entering ROM ISP (FUN_CODE_a8a3).
 */
extern unsigned char xdata DAT_EXTMEM_0436[];
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char FUN_CODE_bba9(unsigned char addr, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e4b9(void);
void FUN_CODE_e4bf(unsigned char *buf);
void FUN_CODE_e44b(unsigned char t);
unsigned char FUN_CODE_da8a(unsigned int reg, unsigned char val);
unsigned char FUN_CODE_da8a(unsigned int reg, unsigned char val)
{
    unsigned char r;
    DAT_EXTMEM_0436[0] = 4;
    DAT_EXTMEM_0436[1] = 0x78;
    DAT_EXTMEM_0436[2] = reg >> 8;
    DAT_EXTMEM_0436[3] = reg;
    DAT_EXTMEM_0436[4] = val;
    r = FUN_CODE_bfcf(0x6e, 5, DAT_EXTMEM_0436);
    FUN_CODE_d059(100);
    FUN_CODE_e4b9();
    return r;
}
