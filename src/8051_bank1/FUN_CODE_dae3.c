/* 8051_bank1 FUN_CODE_dae3 @ 0xdae3..0xdafe (27 B)
 * FUN_CODE_dae3(i, v): writes the 16-bit v low byte first to XDATA 0x9A00 + i and 0x9A00 + i + 1 through a generic
 * pointer (?C?CSTPTR twice, the second as a tail jump).
 * No LCALL or LJMP to 0xDAE3 occurs in the bank-1 image. Options: OPTIMIZE(8,SPEED).
 * Source form: 'p += i & 0xff' loads i into A first (MOV A,R7 / ADD A,R1); 'p += i' gives MOV A,R1 / ADD A,R7.
 */
void FUN_CODE_dae3(unsigned char i, unsigned int v)
{
    unsigned char *p;

    p = (unsigned char xdata *)0x9a00;
    p += i & 0xff;
    *p = v;
    p++;
    *p = v >> 8;
}
