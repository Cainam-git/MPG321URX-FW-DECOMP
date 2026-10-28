/* 8051_bank1 FUN_CODE_ae1d @ 0xae1d .. 0xaeb2 (149 B), OPTIMIZE(8,SPEED) LARGE.
 * Reads the bit-field record XDATA 0xA69C..0xA6A1 and updates bits 4..5 of one of two XDATA bytes:
 *  - a69c[0] bits 2..3 select the byte: non-zero = 0xDCCF, zero = 0xDCDF; its value is copied into v (XDATA 0xA474).
 *  - m = (FUN_CODE_af47(a69c[4], a69c[5]) << 1) | FUN_CODE_af47(a69c[2], a69c[3]) (two register bit tests, 0..3).
 *  - if a69c[1] bits 2..3 or bits 4..5 equal m: bit 0 of a69c[1] set -> v |= 0x30, clear -> v &= 0xCF;
 *    else if a69c[1] bits 6..7 equal m: the opposite (bit 0 set -> v &= 0xCF, clear -> v |= 0x30).
 *  - v is written back to the selected byte (a69c[0] bits 2..3 read again).
 * Bit-fields are allocated from bit 0 (Keil C51): b0 = bit 0, f2 = bits 2..3, f4 = bits 4..5, f6 = bits 6..7.
 * Called from FUN_CODE_3fe7 (0x40ff).
 * Source form: m is declared with the initialiser 0, which is never read (m is assigned before its first use). With
 * it, the firmware's 'MOV R6,A' after the first read of a69c[0] (0xAE21, a copy that nothing reads) is reproduced;
 * without it the copy is absent.
 */
struct cbits { unsigned char b0 : 1; unsigned char b1 : 1; unsigned char f2 : 2; unsigned char f4 : 2; unsigned char f6 : 2; };
union cb { unsigned char v; struct cbits f; };
extern union cb xdata DAT_EXTMEM_a69c[6];
extern unsigned char xdata DAT_EXTMEM_dccf, DAT_EXTMEM_dcdf;
extern bit FUN_CODE_af47(unsigned char n, unsigned char mask);

void FUN_CODE_ae1d(void)
{
    unsigned char x, v, m = 0;

    if (DAT_EXTMEM_a69c[0].f.f2) v = DAT_EXTMEM_dccf; else v = DAT_EXTMEM_dcdf;
    x = FUN_CODE_af47(DAT_EXTMEM_a69c[2].v, DAT_EXTMEM_a69c[3].v);
    m = ((unsigned char)FUN_CODE_af47(DAT_EXTMEM_a69c[4].v, DAT_EXTMEM_a69c[5].v) << 1) | x;
    if (DAT_EXTMEM_a69c[1].f.f2 == m || DAT_EXTMEM_a69c[1].f.f4 == m) {
        if (DAT_EXTMEM_a69c[1].f.b0) v |= 0x30; else v &= 0xcf;
    } else if (DAT_EXTMEM_a69c[1].f.f6 == m) {
        if (DAT_EXTMEM_a69c[1].f.b0) v &= 0xcf; else v |= 0x30;
    }
    if (DAT_EXTMEM_a69c[0].f.f2) DAT_EXTMEM_dccf = v; else DAT_EXTMEM_dcdf = v;
}
