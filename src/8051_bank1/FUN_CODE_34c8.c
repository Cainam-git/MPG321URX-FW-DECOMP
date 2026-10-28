/* 8051_bank1 FUN_CODE_34c8 @ 0x34c8..0x38a7 (991 B)  OPTIMIZE(8,SPEED) LARGE; register bank 3 ('using 3').
 * Parameters type (R7), p (generic pointer) and sel in the LARGE block at XDATA 0xA55A..0xA55D; locals base 0xA55E
 * and q 0xA55F..0xA561. Callers: FUN_CODE_b8fd (0xB973), FUN_CODE_b979 (0xB9EE).
 * sel == 0 selects count n = XDATA 0xDCDB, base 0xDD and the 7-byte table q = XDATA 0xA6EF; otherwise n = 0xDCCB,
 * base 0xCD, q = 0xA6F6 (base is stored and not read). IDATA 0x5B / 0x5C hold the loop index i and n; bit 0x21.4
 * is cleared. FUN_CODE_d737(sel, idx) reads and FUN_CODE_d884(sel, idx, v) writes a byte of set sel.
 * type 0, p[1] == 6: writes 2 to index 0xA8 when bit 4*sel + 1 of XDATA 0xA6FD is clear, else 1.
 * type 1, p[1] == 1: for i < n: at position p[2] + i == 2, q[2] = p[i + 4]; then if d737(0x8F) is 0, writes 0 to
 *   0x97, 0x98, 0x99; else if q[2] & 0x0F > 1: by d737(0x8D) & 0x0F (1, 2, 4) writes (7, 0), (0x77, 0), (0x77, 0x77)
 *   to 0x97 / 0x98, then sets bit 0 of 0x99 and writes 7 to 0xA8; else if q[2] is 0, sets bit 4*sel of 0xA6FD.
 *   At position 3, q[3] = p[i + 4]; if q[3] > 0 and d737(0x8E) & 0x0F is 1: by d737(0x8D) & 0x0F (1, 2, 4) writes
 *   (1, 0), (0x11, 0), (0x11, 0x11) to 0x97 / 0x98.
 * type 1, p[1] == 6, p[2] == 0, p[3] == 0: p[4] == 2 clears bit 4*sel + 1 of 0xA6FD, p[4] == 1 sets it.
 * Source form: the position tests are written 'p[2] + i == k', the first store index 'i + p[2]', the second
 *   'p[2] + i'.
 */
extern unsigned char xdata DAT_EXTMEM_dcdb, DAT_EXTMEM_dccb;
extern unsigned char xdata DAT_EXTMEM_a6ef[], DAT_EXTMEM_a6f6[];
extern unsigned char xdata DAT_EXTMEM_a6fd;
struct cnt_5b { unsigned char i; unsigned char n; };
extern struct cnt_5b idata DAT_INTMEM_5b;
extern bit BITS_21_4;
extern void FUN_CODE_d884(unsigned char sel, unsigned char idx, unsigned char v);
extern unsigned char FUN_CODE_d737(unsigned char sel, unsigned char idx);

void FUN_CODE_34c8(unsigned char type, unsigned char *p, unsigned char sel) using 3
{
    unsigned char base;
    unsigned char *q;
    unsigned char c, e1, e4, e5;

    BITS_21_4 = 0;
    if (sel == 0) {
        DAT_INTMEM_5b.n = DAT_EXTMEM_dcdb;
        base = 0xdd;
        q = DAT_EXTMEM_a6ef;
    } else {
        DAT_INTMEM_5b.n = DAT_EXTMEM_dccb;
        base = 0xcd;
        q = DAT_EXTMEM_a6f6;
    }
    switch (type) {
    case 0:
        if (p[1] == 6) {
            c = sel * 4;
            if (!(DAT_EXTMEM_a6fd & (2 << c))) FUN_CODE_d884(sel, 0xa8, 2);
            else FUN_CODE_d884(sel, 0xa8, 1);
        }
        break;
    case 1:
        if (p[1] == 1) {
            for (DAT_INTMEM_5b.i = 0; DAT_INTMEM_5b.i < DAT_INTMEM_5b.n; DAT_INTMEM_5b.i++) {
                if (p[2] + DAT_INTMEM_5b.i == 2) {
                    q[DAT_INTMEM_5b.i + p[2]] = p[DAT_INTMEM_5b.i + 4];
                    if (FUN_CODE_d737(sel, 0x8f) == 0) {
                        FUN_CODE_d884(sel, 0x97, 0);
                        FUN_CODE_d884(sel, 0x98, 0);
                        FUN_CODE_d884(sel, 0x99, 0);
                    } else if ((q[DAT_INTMEM_5b.i + p[2]] & 0x0f) > 1) {
                        if ((FUN_CODE_d737(sel, 0x8d) & 0x0f) == 1) {
                            FUN_CODE_d884(sel, 0x97, 7);
                            FUN_CODE_d884(sel, 0x98, 0);
                        } else if ((FUN_CODE_d737(sel, 0x8d) & 0x0f) == 2) {
                            FUN_CODE_d884(sel, 0x97, 0x77);
                            FUN_CODE_d884(sel, 0x98, 0);
                        } else if ((FUN_CODE_d737(sel, 0x8d) & 0x0f) == 4) {
                            FUN_CODE_d884(sel, 0x97, 0x77);
                            FUN_CODE_d884(sel, 0x98, 0x77);
                        }
                        FUN_CODE_d884(sel, 0x99, FUN_CODE_d737(sel, 0x99) | 1);
                        FUN_CODE_d884(sel, 0xa8, 7);
                    } else if (q[DAT_INTMEM_5b.i + p[2]] == 0) {
                        DAT_EXTMEM_a6fd |= (1 << (sel * 4));
                    }
                }
                if (p[2] + DAT_INTMEM_5b.i == 3) {
                                        q[p[2] + DAT_INTMEM_5b.i] = p[DAT_INTMEM_5b.i + 4];
                    if (q[DAT_INTMEM_5b.i + p[2]] > 0 && (FUN_CODE_d737(sel, 0x8e) & 0x0f) == 1) {
                        if ((FUN_CODE_d737(sel, 0x8d) & 0x0f) == 1) {
                            FUN_CODE_d884(sel, 0x97, 1);
                            FUN_CODE_d884(sel, 0x98, 0);
                        } else if ((FUN_CODE_d737(sel, 0x8d) & 0x0f) == 2) {
                            FUN_CODE_d884(sel, 0x97, 0x11);
                            FUN_CODE_d884(sel, 0x98, 0);
                        } else if ((FUN_CODE_d737(sel, 0x8d) & 0x0f) == 4) {
                            FUN_CODE_d884(sel, 0x97, 0x11);
                            FUN_CODE_d884(sel, 0x98, 0x11);
                        }
                    }
                }
            }
        } else if (p[1] == 6 && p[2] == 0) {
            if (p[3] == 0 && p[4] == 2) {
                DAT_EXTMEM_a6fd &= ~(2 << (sel * 4));
            } else if (p[3] == 0 && p[4] == 1) {
                DAT_EXTMEM_a6fd |= (2 << (sel * 4));
            }
        }
        break;
    }
}
