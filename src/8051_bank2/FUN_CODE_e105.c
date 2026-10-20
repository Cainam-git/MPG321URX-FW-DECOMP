/* 8051_bank2 FUN_CODE_e105 @ 0xe105  update agent: read one scaler register over the service I2C bus
 * (byte-exact with OPTIMIZE(8,SPEED) LARGE).
 * Sends 03 87 <reg hi> <reg lo> (opcode 0x87 = register read) to slave 0x6E via FUN_CODE_bfcf, waits 100 units,
 * reads the reply into the buffer at XDATA 0x0436 with FUN_CODE_bba9(0x6E, buf), waits 5 units (FUN_CODE_e44b) and
 * returns buffer byte 2 (the register value). Used by FUN_CODE_a8a3 to save / restore 0xF1E0 around a partial update.
 */
extern unsigned char xdata DAT_EXTMEM_0436[];
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char FUN_CODE_bba9(unsigned char addr, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e4b9(void);
void FUN_CODE_e4bf(unsigned char *buf);
void FUN_CODE_e44b(unsigned char t);
unsigned char FUN_CODE_da8a(unsigned int reg, unsigned char val);
unsigned char FUN_CODE_e105(unsigned int reg)
{
    DAT_EXTMEM_0436[0] = 3;
    DAT_EXTMEM_0436[1] = 0x87;
    DAT_EXTMEM_0436[2] = reg >> 8;
    DAT_EXTMEM_0436[3] = reg;
    FUN_CODE_bfcf(0x6e, 4, DAT_EXTMEM_0436);
    FUN_CODE_d059(100);
    FUN_CODE_bba9(0x6e, DAT_EXTMEM_0436);
    FUN_CODE_e44b(5);
    return DAT_EXTMEM_0436[2];
}
