/* 8051_bank2 FUN_CODE_abce @ 0xabce (392 B), SMALL-model function (parameter block ?_FUN_CODE_abce?BYTE at DATA 0x08:
 * buf 0x08..0x0A generic pointer, addr 0x0B..0x0E, n 0x0F, f 0x10; locals j 0x11, i 0x12).
 * Callers: FUN_CODE_a547 (x2), FUN_CODE_d866, FUN_CODE_db76, FUN_CODE_e04a; tail LJMP from FUN_CODE_defd and FUN_CODE_e373. For i = 0 .. n - 1: addr += i; the four
 * bytes of addr go to XDATA 0xCD35..0xCD38 (low byte first, ?C?ULSHR by 8 / 16 / 24); 0x80 is written to 0xCD30 and
 * 0xCD32; then up to 250 reads of 0xCD33 until it reads 0x80. Then 32 bytes are read from 0xCD34 into
 * buf[i * 32 .. i * 32 + 31] in groups of four (j steps by 4 while j < i * 32 + 32, a signed int compare): with
 * f == 1 in the order +0, +1, +2, +3, otherwise +3, +2, +1, +0 (?C?CSTOPTR stores). After each block, when n > 1,
 * FUN_CODE_e44b(2).
 * 0xCD34 is declared volatile: the code reads the same address once for every byte it stores (a data port), so the
 * reads must not be merged. Byte-exact with OPTIMIZE(7,SPEED), (8,SPEED) and (8,SPEED) LARGE. No aids.
 */
extern unsigned char xdata DAT_EXTMEM_cd30;
extern unsigned char xdata DAT_EXTMEM_cd32;
extern unsigned char xdata DAT_EXTMEM_cd33;
extern volatile unsigned char xdata DAT_EXTMEM_cd34;
extern unsigned char xdata DAT_EXTMEM_cd35;
extern unsigned char xdata DAT_EXTMEM_cd36;
extern unsigned char xdata DAT_EXTMEM_cd37;
extern unsigned char xdata DAT_EXTMEM_cd38;
void FUN_CODE_e44b(unsigned char n);
void FUN_CODE_abce(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char f) small
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
        DAT_EXTMEM_cd32 = 0x80;
        j = 0xfa;
        do {
            if (DAT_EXTMEM_cd33 == 0x80) break;
        } while (--j);
        if (f == 1) {
            for (j = i << 5; j < i * 32 + 32; j += 4) {
                buf[j] = DAT_EXTMEM_cd34;
                buf[j + 1] = DAT_EXTMEM_cd34;
                buf[j + 2] = DAT_EXTMEM_cd34;
                buf[j + 3] = DAT_EXTMEM_cd34;
            }
        } else {
            for (j = i << 5; j < i * 32 + 32; j += 4) {
                buf[j + 3] = DAT_EXTMEM_cd34;
                buf[j + 2] = DAT_EXTMEM_cd34;
                buf[j + 1] = DAT_EXTMEM_cd34;
                buf[j] = DAT_EXTMEM_cd34;
            }
        }
        if (n > 1) FUN_CODE_e44b(2);
    }
}
