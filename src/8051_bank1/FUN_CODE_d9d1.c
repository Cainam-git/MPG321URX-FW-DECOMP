/* 8051_bank1 FUN_CODE_d9d1 @ 0xd9d1
 * Register write on the 0x9A00 block: 0x9A00[reg] = val (twin of FUN_CODE_dcd3 for 0x9AB0). The base must be the
 * array symbol: with the constant (xdata *)0x9a00 Keil knows R1 = 0 and emits MOV A,R1 / ADD A,R7 (87.5 %).
 * Byte-exact with OPTIMIZE(8,SPEED).
 */
extern unsigned char xdata DAT_EXTMEM_9a00[];
void FUN_CODE_d9d1(unsigned char reg, unsigned char val)
{
    unsigned char *p;
    p = DAT_EXTMEM_9a00;
    p += reg;
    *p = val;
}
