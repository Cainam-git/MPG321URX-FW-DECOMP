/* 8051_bank1 FUN_CODE_d92a @ 0xd92a
 * bit: XDATA 0xD511 == 0x20 and bit 6 of FUN_CODE_d53f(page, 0x041A). The parameter page stays in R7 for d53f
 * (d92a never writes R7 before the call; the only caller 0xb2c1 in FUN_CODE_b2b0 loads R7 from XDATA 0xA476).
 * d53f(uchar page, uint v): R7 = page, R4:R5 = v (it uses R4 as data and R5 as offset, so v is one uint).
 * The nested ?: gives the firmware's three MOV R7,#k and MOV A,R7 / ADD A,#0FFH; the if/else form puts r in DATA.
 * Options: OPTIMIZE(8,SPEED).
 */
extern unsigned char volatile xdata DAT_EXTMEM_d511;   /* volatile: FUN_CODE_afdc re-reads it 4x */
unsigned char FUN_CODE_d53f(unsigned char page, unsigned int v);
bit FUN_CODE_d92a(unsigned char page)
{
    return (DAT_EXTMEM_d511 == 0x20) ? ((FUN_CODE_d53f(page, 0x41a) & 0x40) ? 1 : 0) : 0;
}
