/* 8051_bank1 FUN_CODE_da57 @ 0xda57
 * Twin of FUN_CODE_da3a for bit 4: b = (XDATA 0xA6FD & 0x10) == 0x10; when set printf "mrx1 wake up\r\n" (0x6ab4);
 * returns b (local bit = BIT 0x01). Callers 0x53f5, 0x5407, 0x547f, 0x549c. Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 */
extern unsigned char xdata DAT_EXTMEM_a6fd;
extern void FUN_CODE_2820(void *fmt, ...) large;
bit FUN_CODE_da57(void)
{
    bit b;
    unsigned char v;
    b = 0;
    v = DAT_EXTMEM_a6fd & 0x10;
    if (v == 0x10) b = 1;
    if (b) FUN_CODE_2820((void code *)0x6ab4);
    return b;
}
