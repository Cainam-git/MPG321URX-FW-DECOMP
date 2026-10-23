/* 8051_bank2 FUN_CODE_b1a9 @ 0xb1a9 (351 B), SMALL-model function (parameter block ?_FUN_CODE_b1a9?BYTE at DATA 0x08:
 * buf 0x08..0x0A generic pointer, addr 0x0B..0x0E, n 0x0F, f 0x10; locals j 0x11, i 0x12). Counterpart of
 * FUN_CODE_abce in the other direction.
 * Callers (all tail LJMPs): FUN_CODE_de20, FUN_CODE_e04a, FUN_CODE_e1a4, FUN_CODE_e306. For i = 0 .. n - 1: addr += i; the four bytes of addr
 * go to XDATA 0xCD35..0xCD38 (low byte first, ?C?ULSHR by 8 / 16 / 24); 0x80 is written to 0xCD30. Then 32 bytes of
 * buf[i * 32 .. i * 32 + 31] are written to 0xCD31 in groups of four (j steps by 4 while j < i * 32 + 32, a signed
 * int compare; ?C?CLDOPTR loads): with f == 1 in the order +0, +1, +2, +3, otherwise +3, +2, +1, +0. After each block,
 * when n > 1, FUN_CODE_e44b(1).
 * Byte-exact with OPTIMIZE(7,SPEED), (8,SPEED) and (8,SPEED) LARGE. No aids.
 */
extern unsigned char xdata DAT_EXTMEM_cd30;
extern unsigned char xdata DAT_EXTMEM_cd31;
extern unsigned char xdata DAT_EXTMEM_cd35;
extern unsigned char xdata DAT_EXTMEM_cd36;
extern unsigned char xdata DAT_EXTMEM_cd37;
extern unsigned char xdata DAT_EXTMEM_cd38;
void FUN_CODE_e44b(unsigned char n);
void FUN_CODE_b1a9(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char f) small
{
    unsigned char j;
    unsigned char i;
    for (i = 0; i < n; i++) {
        addr += i;
        DAT_EXTMEM_cd35 = addr;
        DAT_EXTMEM_cd36 = addr >> 8;
        DAT_EXTMEM_cd37 = addr >> 16;
        DAT_EXTMEM_cd38 = addr >> 24;
        DAT_EXTMEM_cd30 = 0x80;
        if (f == 1) {
            for (j = i << 5; j < i * 32 + 32; j += 4) {
                DAT_EXTMEM_cd31 = buf[j];
                DAT_EXTMEM_cd31 = buf[j + 1];
                DAT_EXTMEM_cd31 = buf[j + 2];
                DAT_EXTMEM_cd31 = buf[j + 3];
            }
        } else {
            for (j = i << 5; j < i * 32 + 32; j += 4) {
                DAT_EXTMEM_cd31 = buf[j + 3];
                DAT_EXTMEM_cd31 = buf[j + 2];
                DAT_EXTMEM_cd31 = buf[j + 1];
                DAT_EXTMEM_cd31 = buf[j];
            }
        }
        if (n > 1) FUN_CODE_e44b(1);
    }
}
