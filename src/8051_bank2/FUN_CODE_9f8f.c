/* 8051_bank2 FUN_CODE_9f8f @ 0x9f8f  OPTIMIZE(8,SPEED) LARGE
 * Real span 0x9f8f..0xa17e (495 bytes, includes the inline ?C?LSTKXDATA constant 00 00 00 B7 at 0xa01f).
 *
 * Page loop of the update agent: one 512-byte block per step, with a progress value.
 *   blk = FUN_CODE_e4f8() / 512 (e4f8 returns the 32-bit value at XDATA 0x0109); n = XDATA[0x0644] << 8 (0x0644 =
 *   byte 4 of the flash-chip record at 0x0640, see FUN_CODE_0003); first = n / 2 when mode bit 2 is set, else 0.
 *   For i = first .. n-1:
 *     mode bit 1 set and (i & 0x7F) >= 0x78 -> skip this i (the last 8 of every 128);
 *     pct = (i - first) * 0xB7 / (n - first) + 0x47 (32-bit; runs 0x47..0xFE); when its low byte differs from
 *       XDATA 0x042D: service-bus writes 0xF0DE = 0x23, 0xBF04 = pct, 0xF0DE = 0x21 (FUN_CODE_da8a), 0x042D = pct;
 *     FUN_CODE_d99e((i >> 5) & 1);
 *     every 128th i ((i & 0x7F) == 0): FUN_CODE_e1c1(i >> 8) and base = i / blk * blk;
 *     FUN_CODE_e54b(i - base, XDATA 0x0440) (e54b = zero-extend to 32 bits and LJMP FUN_CODE_cca2);
 *     a 16-bit byte sum of the 512 bytes at 0x0440 is computed into registers and never used (it is in the bytes);
 *     FUN_CODE_c52f(i, 0x0440); FUN_CODE_d059(4000); FUN_CODE_e2ab(i).
 *   mode (R7) and the locals live in the LARGE-model XDATA block 0x08EE (blk 0x08EF, n 0x08F1, base 0x08F3, i 0x08F5,
 *   first 0x08F7, pct 0x08F9); j / sum are register variables.
 * Keil idioms: n goes through a register temporary t (Keil then reuses R6:R7 for first = t >> 1; computing n
 * straight into memory reloads it); pct is first set to the constant 0xFE - 0x47 and then used (gives the
 * ?C?LSTKXDATA constant store and the reload); (i & 0x7F) >= 0x78 compares as unsigned int (CLR A / SUBB A,#0).
 */
extern unsigned char xdata DAT_EXTMEM_0440[0x200];
extern unsigned char xdata DAT_EXTMEM_0644;
extern unsigned char xdata DAT_EXTMEM_042d;
extern unsigned long FUN_CODE_e4f8(void);
extern unsigned char FUN_CODE_da8a(unsigned int reg, unsigned char val);
extern void FUN_CODE_d99e(unsigned char a);
extern void FUN_CODE_e1c1(unsigned char a);
extern void FUN_CODE_e54b(unsigned int off, unsigned char *buf);
extern void FUN_CODE_c52f(unsigned char dev, unsigned char *buf);
extern void FUN_CODE_d059(unsigned int t);
extern void FUN_CODE_e2ab(unsigned char a);

void FUN_CODE_9f8f(unsigned char mode)
{
    unsigned int blk;
    unsigned int n;
    unsigned int t;
    unsigned int base;
    unsigned int i;
    unsigned int first;
    unsigned long pct;
    unsigned int j;
    unsigned int sum;
    blk = FUN_CODE_e4f8() / 0x200;
    t = DAT_EXTMEM_0644 << 8;
    n = t;
    if (mode & 4) first = t >> 1; else first = 0;
    base = 0;
    for (i = first; i < n; i++) {
        if ((mode & 2) && (i & 0x7f) >= 0x78) continue;
        pct = 0xfe - 0x47;
        pct = (unsigned long)(i - first) * pct / (n - first) + 0x47;
        if ((unsigned char)pct != DAT_EXTMEM_042d) {
            FUN_CODE_da8a(0xf0de, 0x23);
            FUN_CODE_da8a(0xbf04, (unsigned char)pct);
            FUN_CODE_da8a(0xf0de, 0x21);
            DAT_EXTMEM_042d = (unsigned char)pct;
        }
        FUN_CODE_d99e((i >> 5) & 1);
        if ((i & 0x7f) == 0) {
            FUN_CODE_e1c1(i >> 8);
            base = i / blk * blk;
        }
        FUN_CODE_e54b(i - base, DAT_EXTMEM_0440);
        sum = 0;
        for (j = 0; j < 0x200; j++) sum += DAT_EXTMEM_0440[j];
        FUN_CODE_c52f(i, DAT_EXTMEM_0440);
        FUN_CODE_d059(4000);
        FUN_CODE_e2ab(i);
    }
}
