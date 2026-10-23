/* 8051_bank2 FUN_CODE_35a9 @ 0x35a9..0x3e68 (2239 B), OPTIMIZE(8,SPEED) LARGE. Callers: FUN_CODE_ba96 (n = 0), FUN_CODE_6e16.
 * LARGE parameter n (0x08F2); locals i (unsigned int, 0x08F3), e (0x08F5), k (0x08F6), r (0x08F7, the FUN_CODE_4ffa
 * result, stored and not read again), nm[6] (0x08F8) initialised from the CODE bytes "UPDATE" at 0xE0B3 (?C?COPY).
 * n == 1: nm = XDATA 0xF19A..0xF19F; then 0xF19A..0xF19F = nm. Reads 0x200 bytes at 0 into the XDATA buffer 0x01E6
 * (FUN_CODE_cbd9). When its first 11 bytes differ from the CODE bytes at 0xE0A8 (EB 58 90 "MSDOS5.0"): 0x0105 = the
 * 32-bit value at buffer +0x1C6 (FUN_CODE_bf1b) and the 0x200 bytes at 0x0105 are read, else 0x0105 = 0.
 * Buffer bytes 3..7 == "EXFAT": 0x041C = 1, 0x01DC = 1 << buffer[0x6D], 0x042A = 1 << buffer[0x6C], 0x0418 =
 * value(+0x60) - 2, 0x014B = value(+0x58), 0x0405 = 0x014B + 0x0418 * 0x01DC, 0x0158 = value(+0x50); reads the block at
 * 0x0405 + 0x0105, then walks 32-byte entries: 0 ends the walk; type 0x85 compares the UTF-16 name at +0x42 with nm
 * (each byte + 0x20) and ".bin" -> FUN_CODE_813c(i), e |= 0x0A, or with "config" ".bin" -> FUN_CODE_b84b(i),
 * e |= 0xA0, 0x014A = 1; 0x85 entries advance 0x60, others 0x20; at the end of a block the next one is read
 * (k + 1); e == 0xAA ends the walk; i > 0x2800 returns 0.
 * Otherwise: 0x041C = 0 and the same walk over 8.3 entries: name == nm / "CONFIG", extension "BIN", attribute 0x20,
 * with 0x042A = value(+0x0B, 2), 0x0405 = value(+0x24) * buffer[0x10] + value(+0x0E, 2), 0x0158 = value(+0x0E, 2),
 * 0x0418 = value(+0x2C), 0x01DC = buffer[0x0D]; a walk that ends without bit 0x0A in e returns 0.
 * Found: FUN_CODE_3e68(), then 1 when FUN_CODE_ad56() returns non-zero, else 0.
 * Source forms: the name bytes are compared as '(unsigned int)(nm[j] + 0x20) == buf[...]' (computed first, int
 * compare); the shifts as 'x = 1; x <<= n;'; the first scan is 'for (i = 0; i != 11; i++)'; 'return 0' after the
 * (e & 0x0F) test lets Keil use A (MOV R7,A). 0x042A is the size field of the record at 0x0429 as in FUN_CODE_a17e.c.
 */
struct Geo { unsigned char n; unsigned int size; };
extern struct Geo xdata DAT_EXTMEM_0429;
extern unsigned char xdata DAT_EXTMEM_01e6[];
extern unsigned char code DAT_CODE_e0a8[];
extern unsigned long xdata DAT_EXTMEM_0105;
extern unsigned long xdata DAT_EXTMEM_0405;
extern unsigned long xdata DAT_EXTMEM_0418;
extern unsigned long xdata DAT_EXTMEM_014b;
extern unsigned long xdata DAT_EXTMEM_0158;
extern unsigned int xdata DAT_EXTMEM_01dc;
extern unsigned char xdata DAT_EXTMEM_041c;
extern unsigned char xdata DAT_EXTMEM_014a;
extern unsigned char xdata DAT_EXTMEM_f19a, DAT_EXTMEM_f19b, DAT_EXTMEM_f19c, DAT_EXTMEM_f19d, DAT_EXTMEM_f19e, DAT_EXTMEM_f19f;
extern unsigned char FUN_CODE_4ffa(void);
extern void FUN_CODE_cbd9(unsigned long addr, unsigned char *buf, unsigned long n);
extern unsigned long FUN_CODE_bf1b(unsigned char *p, unsigned char n);
extern void FUN_CODE_813c(unsigned int e);
extern void FUN_CODE_b84b(unsigned int e);
extern void FUN_CODE_3e68(void);
extern unsigned char FUN_CODE_ad56(void);

unsigned char FUN_CODE_35a9(unsigned char n)
{
    unsigned int i;
    unsigned char e;
    unsigned char k;
    unsigned char r;
    unsigned char nm[6] = "UPDATE";
    if (n == 1) {
        nm[0] = DAT_EXTMEM_f19a;
        nm[1] = DAT_EXTMEM_f19b;
        nm[2] = DAT_EXTMEM_f19c;
        nm[3] = DAT_EXTMEM_f19d;
        nm[4] = DAT_EXTMEM_f19e;
        nm[5] = DAT_EXTMEM_f19f;
    }
    DAT_EXTMEM_f19a = nm[0];
    DAT_EXTMEM_f19b = nm[1];
    DAT_EXTMEM_f19c = nm[2];
    DAT_EXTMEM_f19d = nm[3];
    DAT_EXTMEM_f19e = nm[4];
    DAT_EXTMEM_f19f = nm[5];
    r = FUN_CODE_4ffa();
    FUN_CODE_cbd9(0, DAT_EXTMEM_01e6, 0x200);
    e = 0;
    for (i = 0; i != 11; i++) {
        if (DAT_EXTMEM_01e6[i] != DAT_CODE_e0a8[i]) {
            e = 0xff;
            break;
        }
    }
    if (e == 0xff) {
        DAT_EXTMEM_0105 = FUN_CODE_bf1b(&DAT_EXTMEM_01e6[0x1c6], 4);
        FUN_CODE_cbd9(DAT_EXTMEM_0105, DAT_EXTMEM_01e6, 0x200);
    } else {
        DAT_EXTMEM_0105 = 0;
    }
    if (DAT_EXTMEM_01e6[3] == 'E' && DAT_EXTMEM_01e6[4] == 'X' && DAT_EXTMEM_01e6[5] == 'F' && DAT_EXTMEM_01e6[6] == 'A'
        && DAT_EXTMEM_01e6[7] == 'T') {
        DAT_EXTMEM_041c = 1;
        DAT_EXTMEM_01dc = 1;
        DAT_EXTMEM_01dc <<= DAT_EXTMEM_01e6[0x6d];
        DAT_EXTMEM_0429.size = 1;
        DAT_EXTMEM_0429.size <<= DAT_EXTMEM_01e6[0x6c];
        DAT_EXTMEM_0418 = FUN_CODE_bf1b(&DAT_EXTMEM_01e6[0x60], 4) - 2;
        DAT_EXTMEM_014b = FUN_CODE_bf1b(&DAT_EXTMEM_01e6[0x58], 4);
        DAT_EXTMEM_0405 = DAT_EXTMEM_014b + DAT_EXTMEM_0418 * DAT_EXTMEM_01dc;
        DAT_EXTMEM_0158 = FUN_CODE_bf1b(&DAT_EXTMEM_01e6[0x50], 4);
        FUN_CODE_cbd9(DAT_EXTMEM_0405 + DAT_EXTMEM_0105, DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
        i = 0;
        k = 0;
        e = 0;
        DAT_EXTMEM_014a = 0;
        for (;;) {
            if (DAT_EXTMEM_01e6[i] == 0) goto load;
            if (DAT_EXTMEM_01e6[i] == 0x85) {
                if ((unsigned int)(nm[0] + 0x20) == DAT_EXTMEM_01e6[i + 0x42] && (unsigned int)(nm[1] + 0x20) == DAT_EXTMEM_01e6[i + 0x44]
                    && (unsigned int)(nm[2] + 0x20) == DAT_EXTMEM_01e6[i + 0x46] && (unsigned int)(nm[3] + 0x20) == DAT_EXTMEM_01e6[i + 0x48]
                    && (unsigned int)(nm[4] + 0x20) == DAT_EXTMEM_01e6[i + 0x4a] && (unsigned int)(nm[5] + 0x20) == DAT_EXTMEM_01e6[i + 0x4c]
                    && DAT_EXTMEM_01e6[i + 0x50] == 'b' && DAT_EXTMEM_01e6[i + 0x52] == 'i' && DAT_EXTMEM_01e6[i + 0x54] == 'n') {
                    FUN_CODE_813c(i);
                    e |= 0x0a;
                } else if (DAT_EXTMEM_01e6[i + 0x42] == 'c' && DAT_EXTMEM_01e6[i + 0x44] == 'o' && DAT_EXTMEM_01e6[i + 0x46] == 'n'
                    && DAT_EXTMEM_01e6[i + 0x48] == 'f' && DAT_EXTMEM_01e6[i + 0x4a] == 'i' && DAT_EXTMEM_01e6[i + 0x4c] == 'g'
                    && DAT_EXTMEM_01e6[i + 0x50] == 'b' && DAT_EXTMEM_01e6[i + 0x52] == 'i' && DAT_EXTMEM_01e6[i + 0x54] == 'n') {
                    FUN_CODE_b84b(i);
                    e |= 0xa0;
                    DAT_EXTMEM_014a = 1;
                }
                i += 0x60;
            } else {
                i += 0x20;
            }
            if (e == 0xaa) goto load;
            if (i >= DAT_EXTMEM_0429.size) {
                k++;
                i = 0;
                FUN_CODE_cbd9(DAT_EXTMEM_0405 + DAT_EXTMEM_0105 + k, DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
            }
            if (i > 0x2800) return 0;
        }
    } else {
        DAT_EXTMEM_041c = 0;
        DAT_EXTMEM_0429.size = FUN_CODE_bf1b(&DAT_EXTMEM_01e6[0x0b], 2);
        DAT_EXTMEM_0405 = FUN_CODE_bf1b(&DAT_EXTMEM_01e6[0x24], 4) * DAT_EXTMEM_01e6[0x10] + FUN_CODE_bf1b(&DAT_EXTMEM_01e6[0x0e], 2);
        DAT_EXTMEM_0158 = FUN_CODE_bf1b(&DAT_EXTMEM_01e6[0x0e], 2);
        DAT_EXTMEM_0418 = FUN_CODE_bf1b(&DAT_EXTMEM_01e6[0x2c], 4);
        DAT_EXTMEM_01dc = DAT_EXTMEM_01e6[0x0d];
        FUN_CODE_cbd9(DAT_EXTMEM_0405 + DAT_EXTMEM_0105, DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
        i = 0;
        k = 0;
        e = 0;
        DAT_EXTMEM_014a = 0;
        for (;;) {
            if (DAT_EXTMEM_01e6[i] == 0) break;
            if (DAT_EXTMEM_01e6[i] == nm[0] && DAT_EXTMEM_01e6[i + 1] == nm[1] && DAT_EXTMEM_01e6[i + 2] == nm[2]
                && DAT_EXTMEM_01e6[i + 3] == nm[3] && DAT_EXTMEM_01e6[i + 4] == nm[4] && DAT_EXTMEM_01e6[i + 5] == nm[5]
                && DAT_EXTMEM_01e6[i + 8] == 'B' && DAT_EXTMEM_01e6[i + 9] == 'I' && DAT_EXTMEM_01e6[i + 10] == 'N'
                && DAT_EXTMEM_01e6[i + 11] == 0x20) {
                FUN_CODE_813c(i);
                e |= 0x0a;
            } else if (DAT_EXTMEM_01e6[i] == 'C' && DAT_EXTMEM_01e6[i + 1] == 'O' && DAT_EXTMEM_01e6[i + 2] == 'N'
                && DAT_EXTMEM_01e6[i + 3] == 'F' && DAT_EXTMEM_01e6[i + 4] == 'I' && DAT_EXTMEM_01e6[i + 5] == 'G'
                && DAT_EXTMEM_01e6[i + 8] == 'B' && DAT_EXTMEM_01e6[i + 9] == 'I' && DAT_EXTMEM_01e6[i + 10] == 'N'
                && DAT_EXTMEM_01e6[i + 11] == 0x20) {
                FUN_CODE_b84b(i);
                e |= 0xa0;
                DAT_EXTMEM_014a = 1;
            }
            if (e == 0xaa) break;
            i += 0x20;
            if (i >= DAT_EXTMEM_0429.size) {
                k++;
                i = 0;
                FUN_CODE_cbd9(DAT_EXTMEM_0405 + DAT_EXTMEM_0105 + k, DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
            }
            if (i > 0x2800) return 0;
        }
        if (!(e & 0x0f)) return 0;
    }
load:
    FUN_CODE_3e68();
    if (!FUN_CODE_ad56()) return 0;
    return 1;
}
