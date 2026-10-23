/* 8051_bank1 FUN_CODE_da3a @ 0xda3a
 * bit = (XDATA 0xA6FD & 1) == 1; when set, printf "mrx wake up\r\n" (code string 0x6aa6, FUN_CODE_2820); returns the
 * bit (MOV C,b / RET). The local bit b is BIT 0x01. Callers 0x53d1, 0x53e3, 0x5445, 0x5462.
 * OPTIMIZE(8,SPEED) LARGE (SMALL gives other code).
 */
extern unsigned char xdata DAT_EXTMEM_a6fd;
extern void FUN_CODE_2820(void *fmt, ...) large;
bit FUN_CODE_da3a(void)
{
    bit b;
    unsigned char v;
    b = 0;
    v = DAT_EXTMEM_a6fd & 0x01;
    if (v == 1) b = 1;
    if (b) FUN_CODE_2820((void code *)0x6aa6);
    return b;
}
