/* 8051_bank0 FUN_CODE_0c83 @ 0x0c83  STBC boot loader: choose and verify the SPI flash bus mode (byte-exact
 * with OPTIMIZE(8,SPEED) REGFILE(R.ORC); FUN_CODE_124f is compiled in the same file because Keil's
 * "reuse of common entry code" then emits the two shared parameter set-ups FUN_CODE_123a / FUN_CODE_1249 in front of
 * it, as in the firmware).
 * FUN_CODE_0c83(quad, idx) with quad = DATA 0x2F (chip can do Quad) and idx = DATA 0x30 (chip index from the JEDEC
 * table), called by the flash identification FUN_CODE_111f. Returns the read opcode it settled on (the caller
 * ignores it; the mode stays in register 0xF050).
 * Quad capable: read the QE bit by manufacturer group (idx & 0xF0): 0x30 -> RDSR (0x05) bit 6; 0x40 / 0x80 -> RDSR2
 * (0x35) bit 1; 0x50 -> taken as set. If clear, set it: flags byte DATA 0x14 bit 1 selects the two-register form
 * (WRSR 0x01 / WRSR2 0x31, each after WREN 0x06 with WEL / WIP polling, the SR1 write repeated when SR1 bit 7 was
 * set) or the 16-bit WRSR form (0x01 with SR1 / SR2, groups 0x30 / 0x40 / 0x80; others write zeros). Then pin set-up
 * 0xF134 |= 0xC0, 0xF11D bit 7 set / bit 6 clear, 0xF050 = (0xF050 & ~0x20) | 0x04 (quad), read 10 bytes from flash
 * address 0 with opcode 0x6B (FUN_CODE_1491) and compare them with CODE 0x0000..0x0009 (the copy the mask ROM
 * loaded in single-bit mode): equal -> "Set Flash to Quad mode!!", return 0x6B.
 * Otherwise (or not quad capable): 0xF050 = (0xF050 & ~0x24) | 0x20 (dual), same test with 0x3B: equal -> "Set Flash
 * to Dual mode!!", return 0x3B; else 0xF050 &= ~0x20, "System can not support Dual mode!!", return 0x0B (single-bit
 * fast read): the boot loader continues in single-bit mode, it does not stop.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f134, DAT_EXTMEM_f11c, DAT_EXTMEM_f11d, DAT_EXTMEM_f050;
extern unsigned char data DAT_0014;
extern void FUN_CODE_0989(void *fmt, ...);
void FUN_CODE_17af(unsigned char cmd);
unsigned char FUN_CODE_172d(unsigned char cmd);
void FUN_CODE_1491(unsigned char op, unsigned long addr, unsigned char n, unsigned char *dst);
void FUN_CODE_124f(unsigned int n_out, unsigned char *out, unsigned int n_in, unsigned char *in);

unsigned char FUN_CODE_0c83(unsigned char quad, unsigned char idx)
{
    unsigned char code *p;
    unsigned char s, sr1, sr2;
    unsigned char buf[3];
    unsigned char rd[10];
    bit ok;                 /* "verified" flag, bit 0x20.3 */
    ok = 1;
    if (quad) {
        if ((idx & 0xf0) == 0x30) s = FUN_CODE_172d(0x05) & 0x40;
        else if ((idx & 0xf0) == 0x40 || (idx & 0xf0) == 0x80) s = FUN_CODE_172d(0x35) & 0x02;
        else if ((idx & 0xf0) == 0x50) s = 1;
        if (s == 0) {
            DAT_EXTMEM_f134 |= 0xc0;
            DAT_EXTMEM_f11c |= 0x40;
            DAT_EXTMEM_f11d |= 0x80;
            DAT_EXTMEM_f11d &= ~0x40;
            if (DAT_0014 & 0x02) {
                sr1 = FUN_CODE_172d(0x05);
                sr2 = FUN_CODE_172d(0x35);
                if ((int)(sr1 & 0x80)) {
                    ok = 1;
                    buf[0] = 0x01;
                    buf[1] = sr1 & 0x7f;
                    FUN_CODE_17af(0x06);
                    while (!(FUN_CODE_172d(0x05) & 0x02));
                    FUN_CODE_124f(2, buf, 0, &s);
                    while (FUN_CODE_172d(0x05) & 0x01);
                    while (FUN_CODE_172d(0x05) & 0x02);
                }
                FUN_CODE_17af(0x06);
                while (!(FUN_CODE_172d(0x05) & 0x02));
                buf[0] = 0x31;
                buf[1] = sr2 | 0x02;
                FUN_CODE_124f(2, buf, 0, &s);
                while (FUN_CODE_172d(0x05) & 0x01);
                while (FUN_CODE_172d(0x05) & 0x02);
                if (ok) {
                    buf[0] = 0x01;
                    buf[1] = sr1;
                    FUN_CODE_17af(0x06);
                    while (!(FUN_CODE_172d(0x05) & 0x02));
                    FUN_CODE_124f(2, buf, 0, &s);
                    while (FUN_CODE_172d(0x05) & 0x01);
                    while (FUN_CODE_172d(0x05) & 0x02);
                }
            } else {
                buf[1] = FUN_CODE_172d(0x05);
                if ((int)(buf[1] & 0x80)) {
                    ok = 1;
                    buf[1] &= 0x7f;
                }
                if ((idx & 0xf0) == 0x30) { buf[2] = FUN_CODE_172d(0x15); buf[1] |= 0x40; }
                else if ((idx & 0xf0) == 0x40) { buf[2] = FUN_CODE_172d(0x35); buf[2] |= 0x02; }
                else if ((idx & 0xf0) == 0x80) { buf[2] = FUN_CODE_172d(0x35); buf[2] |= 0x02; }
                else { buf[1] = 0; buf[2] = 0; }
                FUN_CODE_17af(0x06);
                while (!(FUN_CODE_172d(0x05) & 0x02));
                buf[0] = 0x01;
                FUN_CODE_124f(3, buf, 0, &s);
                while (FUN_CODE_172d(0x05) & 0x01);
                while (FUN_CODE_172d(0x05) & 0x02);
                s = FUN_CODE_172d(0x05);
                if (ok) {
                    buf[1] |= 0x80;
                    FUN_CODE_17af(0x06);
                    while (!(FUN_CODE_172d(0x05) & 0x02));
                    FUN_CODE_124f(3, buf, 0, &s);
                    while (FUN_CODE_172d(0x05) & 0x01);
                    while (FUN_CODE_172d(0x05) & 0x02);
                    s = FUN_CODE_172d(0x05);
                }
            }
        }
        DAT_EXTMEM_f134 |= 0xc0;
        DAT_EXTMEM_f11d |= 0x80;
        DAT_EXTMEM_f11d &= ~0x40;
        s = DAT_EXTMEM_f050;
        s &= ~0x20;
        s |= 0x04;
        DAT_EXTMEM_f050 = s;
        p = 0;
        FUN_CODE_1491(0x6b, 0, 10, rd);
        ok = 1;
        for (s = 0; s < 10; s++) if (p[s] != rd[s]) ok = 0;
        if (ok) {
            FUN_CODE_0989((void code *)0x15bb);
            return 0x6b;
        }
        ok = 1;
        DAT_EXTMEM_f050 &= ~0x04;
    }
    s = DAT_EXTMEM_f050;
    s &= ~0x24;
    s |= 0x20;
    DAT_EXTMEM_f050 = s;
    FUN_CODE_1491(0x3b, 0, 10, rd);
    p = 0;
    for (s = 0; s < 10; s++) if (p[s] != rd[s]) ok = 0;
    if (ok) {
        FUN_CODE_0989((void code *)0x15d6);
        return 0x3b;
    }
    DAT_EXTMEM_f050 &= ~0x20;
    FUN_CODE_0989((void code *)0x15f1);
    return 0x0b;
}

extern unsigned char volatile xdata DAT_EXTMEM_f0e6x_unused;
extern unsigned char volatile xdata DAT_EXTMEM_f0e6, DAT_EXTMEM_f0f4, DAT_EXTMEM_f0eb, DAT_EXTMEM_f0ec, DAT_EXTMEM_f0ed, DAT_EXTMEM_f0ee;
extern unsigned char volatile xdata DAT_EXTMEM_f1c0, DAT_EXTMEM_f1c3, DAT_EXTMEM_f1c8, DAT_EXTMEM_f0e5;
void FUN_CODE_124f(unsigned int n_out, unsigned char *out, unsigned int n_in, unsigned char *in)
{
    unsigned char t;        /* mode scratch, later the dropped first FIFO byte */
    unsigned long total;
    unsigned int i;
    t = DAT_EXTMEM_f0e6 & 0x0c;
    t |= 0x41;
    DAT_EXTMEM_f0e6 = t;
    total = n_out + n_in - 1;
    DAT_EXTMEM_f0f4 = ((unsigned char)n_out << 5) | 0x13;
    DAT_EXTMEM_f0eb = total >> 16;
    DAT_EXTMEM_f0ec = total >> 8;
    DAT_EXTMEM_f0ed = (unsigned int)(total & 0xff);
    DAT_EXTMEM_f0ee = out[0];
    DAT_EXTMEM_f1c0 = 0x82;
    for (i = 1; i < n_out; i++) DAT_EXTMEM_f1c3 = out[i];
    DAT_EXTMEM_f1c0 = 0x84;
    DAT_EXTMEM_f1c8 = 0x81;
    DAT_EXTMEM_f0e5 = 1;
    while ((int)(DAT_EXTMEM_f0e5 & 1));
    if (n_in > 0) {
        DAT_EXTMEM_f1c8 = 0x82;
        t = DAT_EXTMEM_f1c8;
        for (i = 0; i < n_in; i++) in[i] = DAT_EXTMEM_f1c8;
    }
    DAT_EXTMEM_f1c0 = 0x80;
    DAT_EXTMEM_f1c8 = 0x80;
}
