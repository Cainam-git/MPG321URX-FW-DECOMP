/* 8051_bank1 FUN_CODE_147a @ 0x147a..0x1c3c (1986 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE; register bank 3
 * ('using 3'). Parameters type, p (generic pointer), sel in the LARGE block at XDATA 0xA55B.
 * sel == 0 selects count n = XDATA 0xDCDB, output byte port XDATA 0xDCDD and the 7-byte table q = XDATA 0xA6EF;
 * otherwise n = 0xDCCB, port 0xDCCD, q = 0xA6F6. IDATA 0x5B / 0x5C hold the loop index i and n; IDATA 0x64 / 0x65 are
 * the read offsets of the two sets into the CODE table 0x6AF7; bit 0x21.4 is a flag that ends the function with n
 * zero bytes written to the port. The bit 4*sel + 1 of XDATA 0xA6FD is tested, set or cleared per set.
 * type 0 (flag when p[0] & 0x0F is 0x0F or no case applies), by p[1]: 6: one byte 2 (bit clear) or 1 (bit set),
 *   then n - 1 zeros; 0: CODE 0x6C14[i + p[2]] (p[2] < 0x0C, zero past 12 entries) or 0x80 then zeros
 *   (p[2] == 0x0E); 1: q[i + p[2]] (p[2] < 5, zero past 7 entries); 2: for p[2] < 9 the positions i + p[2] == 2 and
 *   == 3 get 0, 1, 7, 0x11 or 0x77 from the low nibbles of q[1..3] (7 and 0x77 also set the bit), the others CODE
 *   0x6C0C[i + p[2]]; 0x20: CODE 0x6C0C[p[2] + i] (p[2] == 0x0C); 0x22: CODE 0x6C20 (16 entries); 4: CODE 0x6C30
 *   (4 entries); p[0] & 0x0F == 6, p[1] == 0x80, p[2] == 0x28: n bytes 1.
 * type 1: clears the count byte; unless p[0] & 0x0F is 0x0F: p[1] == 1 copies p[4 + i] to q[i + p[2]] while
 *   i + p[2] < 7; p[1] == 6, p[2] == 0, p[3] == 0: p[4] == 2 clears the bit, p[4] == 1 sets it and sets XDATA
 *   0xA6EE to 1 when it is 0.
 * type 2: when n > 0: p[2] == 0x50 writes CODE 0x6AF7[offset + i] for i < n and adds n to the offset; else flag.
 * type 3: clears the count byte; offset = p[4] (p[2] == 0x50 and n > 0) or 0 (p[2] != 0x50).
 * Callers: FUN_CODE_914b (0x9216), FUN_CODE_9339 (0x9401).
 * volatile on 0xDC00..: every loop writes the same port address n times; each store is kept only for volatile.
 * Source forms: shifts by sel * 4 read the accumulator after a constant store ('c = sel * 4; ACC = 2; ... 2 << c',
 *   'x |= (e = sel * 4, ACC = 1, ACC << e)', ACC from reg51.h, one count local per site), which loads A before the
 *   count; type 1 tests 'p[2] + i < 7' and reads 'p[(int)i + 4]' (the int value of i stays in R7 for the index);
 *   the type-2 read is written in both arms of 'if (sel == 0)' as 'T[I64 + i]' / 'T[I65 + i]' (Keil merges the
 *   tails).
 */
#include <reg51.h>
extern unsigned char volatile xdata DAT_EXTMEM_dc00[];
extern unsigned char xdata DAT_EXTMEM_dcdb, DAT_EXTMEM_dccb;
extern unsigned char xdata DAT_EXTMEM_a6ef[], DAT_EXTMEM_a6f6[];
extern unsigned char xdata DAT_EXTMEM_a6fd, DAT_EXTMEM_a6ee;
struct cnt_5b { unsigned char i; unsigned char n; };
extern struct cnt_5b idata DAT_INTMEM_5b;
extern unsigned char idata DAT_INTMEM_64, DAT_INTMEM_65;
extern bit BITS_21_4;
extern unsigned char code DAT_CODE_6af7[0x10], DAT_CODE_6c0c[8], DAT_CODE_6c14[12], DAT_CODE_6c20[16], DAT_CODE_6c30[4];

void FUN_CODE_147a(unsigned char type, unsigned char *p, unsigned char sel) using 3
{
    unsigned char base;
    unsigned char *q;
    int k;
    unsigned char c, e1, e2, e3, e4, e5;

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
        if ((p[0] & 0x0f) == 0x0f) {
            BITS_21_4 = 1;
            break;
        }
        if (p[1] == 6) {
            c = sel * 4;
            ACC = 2;
            if (!(DAT_EXTMEM_a6fd & (2 << c))) DAT_EXTMEM_dc00[base] = 2;
            else DAT_EXTMEM_dc00[base] = 1;
            for (DAT_INTMEM_5b.i = 0; DAT_INTMEM_5b.i < DAT_INTMEM_5b.n - 1; DAT_INTMEM_5b.i++)
                DAT_EXTMEM_dc00[base] = 0;
        } else if (p[1] == 0) {
            if (p[2] < 0x0c) {
                for (DAT_INTMEM_5b.i = 0; DAT_INTMEM_5b.i < DAT_INTMEM_5b.n; DAT_INTMEM_5b.i++) {
                    if (DAT_INTMEM_5b.i + p[2] < 0x0c) DAT_EXTMEM_dc00[base] = DAT_CODE_6c14[DAT_INTMEM_5b.i + p[2]];
                    else DAT_EXTMEM_dc00[base] = 0;
                }
            } else if (p[2] == 0x0e) {
                for (DAT_INTMEM_5b.i = 0; DAT_INTMEM_5b.i < DAT_INTMEM_5b.n; DAT_INTMEM_5b.i++) {
                    if (DAT_INTMEM_5b.i == 0) DAT_EXTMEM_dc00[base] = 0x80;
                    else DAT_EXTMEM_dc00[base] = 0;
                }
            } else {
                BITS_21_4 = 1;
            }
        } else if (p[1] == 1) {
            if (p[2] < 5) {
                for (DAT_INTMEM_5b.i = 0; DAT_INTMEM_5b.i < DAT_INTMEM_5b.n; DAT_INTMEM_5b.i++) {
                    k = DAT_INTMEM_5b.i + p[2];
                    if (k < 7) DAT_EXTMEM_dc00[base] = q[k];
                    else DAT_EXTMEM_dc00[base] = 0;
                }
            }
        } else if (p[1] == 2) {
            if (p[2] < 9) {
                for (DAT_INTMEM_5b.i = 0; DAT_INTMEM_5b.i < DAT_INTMEM_5b.n; DAT_INTMEM_5b.i++) {
                    if (DAT_INTMEM_5b.i + p[2] == 2) {
                        if (q[3] == 0) DAT_EXTMEM_dc00[base] = 0;
                        else if ((q[2] & 0x0f) == 1) {
                            if ((q[1] & 0x0f) == 1) DAT_EXTMEM_dc00[base] = 1;
                            else DAT_EXTMEM_dc00[base] = 0x11;
                        } else if ((q[1] & 0x0f) == 1) {
                            DAT_EXTMEM_dc00[base] = 7;
                            DAT_EXTMEM_a6fd |= (e1 = sel * 4, ACC = 1, ACC << e1);
                        } else {
                            DAT_EXTMEM_dc00[base] = 0x77;
                            DAT_EXTMEM_a6fd |= (e2 = sel * 4, ACC = 1, ACC << e2);
                        }
                    } else if (DAT_INTMEM_5b.i + p[2] == 3) {
                        if (q[3] == 0) DAT_EXTMEM_dc00[base] = 0;
                        else if ((q[2] & 0x0f) == 1) {
                            if ((q[1] & 0x0f) == 4) DAT_EXTMEM_dc00[base] = 0x11;
                            else DAT_EXTMEM_dc00[base] = 0;
                        } else if ((q[1] & 0x0f) == 4) {
                            DAT_EXTMEM_dc00[base] = 0x77;
                            DAT_EXTMEM_a6fd |= (e3 = sel * 4, ACC = 1, ACC << e3);
                        } else {
                            DAT_EXTMEM_dc00[base] = 0;
                        }
                    } else {
                        DAT_EXTMEM_dc00[base] = DAT_CODE_6c0c[DAT_INTMEM_5b.i + p[2]];
                    }
                }
            } else {
                BITS_21_4 = 1;
            }
        } else if (p[1] == 0x20) {
            if (p[2] == 0x0c) {
                for (DAT_INTMEM_5b.i = 0; DAT_INTMEM_5b.i < DAT_INTMEM_5b.n; DAT_INTMEM_5b.i++)
                    DAT_EXTMEM_dc00[base] = DAT_CODE_6c0c[p[2] + DAT_INTMEM_5b.i];
            } else {
                BITS_21_4 = 1;
            }
        } else if (p[1] == 0x22) {
            for (DAT_INTMEM_5b.i = 0; DAT_INTMEM_5b.i < DAT_INTMEM_5b.n; DAT_INTMEM_5b.i++) {
                if (DAT_INTMEM_5b.i + p[2] < 0x10) DAT_EXTMEM_dc00[base] = DAT_CODE_6c20[DAT_INTMEM_5b.i + p[2]];
                else DAT_EXTMEM_dc00[base] = 0;
            }
        } else if (p[1] == 4) {
            for (DAT_INTMEM_5b.i = 0; DAT_INTMEM_5b.i < DAT_INTMEM_5b.n; DAT_INTMEM_5b.i++) {
                if (DAT_INTMEM_5b.i + p[2] < 4) DAT_EXTMEM_dc00[base] = DAT_CODE_6c30[DAT_INTMEM_5b.i + p[2]];
                else DAT_EXTMEM_dc00[base] = 0;
            }
        } else if ((p[0] & 0x0f) == 6 && p[1] == 0x80 && p[2] == 0x28) {
            for (DAT_INTMEM_5b.i = 0; DAT_INTMEM_5b.i < DAT_INTMEM_5b.n; DAT_INTMEM_5b.i++)
                DAT_EXTMEM_dc00[base] = 1;
        } else {
            BITS_21_4 = 1;
        }
        break;
    case 1:
        if (sel == 0) DAT_EXTMEM_dcdb = 0;
        else DAT_EXTMEM_dccb = 0;
        if ((p[0] & 0x0f) == 0x0f) break;
        if (p[1] == 1) {
            for (DAT_INTMEM_5b.i = 0; DAT_INTMEM_5b.i < DAT_INTMEM_5b.n; DAT_INTMEM_5b.i++) {
                if (p[2] + DAT_INTMEM_5b.i < 7) q[DAT_INTMEM_5b.i + p[2]] = p[(int)DAT_INTMEM_5b.i + 4];
            }
        } else if (p[1] == 6 && p[2] == 0) {
            if (p[3] == 0 && p[4] == 2) {
                DAT_EXTMEM_a6fd &= ~(e4 = sel * 4, ACC = 2, ACC << e4);
            } else if (p[3] == 0 && p[4] == 1) {
                DAT_EXTMEM_a6fd |= (e5 = sel * 4, ACC = 2, ACC << e5);
                if (DAT_EXTMEM_a6ee == 0) DAT_EXTMEM_a6ee = 1;
            }
        }
        break;
    case 2:
        if (DAT_INTMEM_5b.n > 0) {
            if (p[2] == 0x50) {
                for (DAT_INTMEM_5b.i = 0; DAT_INTMEM_5b.i < DAT_INTMEM_5b.n; DAT_INTMEM_5b.i++)
{ if (sel == 0) DAT_EXTMEM_dc00[base] = DAT_CODE_6af7[DAT_INTMEM_64 + DAT_INTMEM_5b.i]; else DAT_EXTMEM_dc00[base] = DAT_CODE_6af7[DAT_INTMEM_65 + DAT_INTMEM_5b.i]; }
                if (sel == 0) DAT_INTMEM_64 += DAT_INTMEM_5b.n;
                else DAT_INTMEM_65 += DAT_INTMEM_5b.n;
            } else {
                BITS_21_4 = 1;
            }
        }
        break;
    case 3:
        if (sel == 0) DAT_EXTMEM_dcdb = 0;
        else DAT_EXTMEM_dccb = 0;
        if (p[2] == 0x50) {
            if (DAT_INTMEM_5b.n > 0) {
                if (sel == 0) DAT_INTMEM_64 = p[4];
                else DAT_INTMEM_65 = p[4];
            }
        } else {
            if (sel == 0) DAT_INTMEM_64 = 0;
            else DAT_INTMEM_65 = 0;
        }
        break;
    }
    if (BITS_21_4) {
        for (DAT_INTMEM_5b.i = 0; DAT_INTMEM_5b.i < DAT_INTMEM_5b.n; DAT_INTMEM_5b.i++)
            DAT_EXTMEM_dc00[base] = 0;
    }
}
