/* 8051_bank2 FUN_CODE_8cdc @ 0x8cdc..0x8f95 (caller: LCALL at 0x6f4e). Compiled OPTIMIZE(8,SPEED) LARGE.
 * buf = the 512-byte block at XDATA 0x01E6; FUN_CODE_cbd9(addr, buf, n) reads n bytes from addr into buf (n goes to
 * its parameter block at XDATA 0x0927 through ?C?LSTKXDATA); FUN_CODE_bf1b(p, n) returns the n-byte little-endian
 * value at p as unsigned long.
 * 1. cbd9(0, buf, 0x200). If bytes buf[3..10] differ at some index from both 8-byte CODE tables 0xE0B9 ("MSDOS5.0")
 *    and 0xE0C1 ("NTFS    "): ulong 0x0105 = bf1b(buf + 0x1C6, 4) and cbd9(that value, buf, 0x200); else 0x0105 = 0.
 * 2. buf[3..7] = "EXFAT": byte 0x041C = 1, word 0x01DC = 1 << buf[0x6D], word 0x042A = 1 << buf[0x6C] (each set to 1
 *    and then shifted), ulongs 0x0418 / 0x0405 / 0x0158 = bf1b(buf + 0x60 / 0x58 / 0x50, 4).
 *    buf[3..6] = "NTFS": 0x041C = 2, 0x042A = bf1b(buf + 0x0B, 2), 0x01DC = buf[0x0D], ulong 0x01E2 =
 *    bf1b(buf + 0x30, 4) * word 0x01DC, FUN_CODE_aa43(), then step 4 only.
 *    otherwise: 0x041C = 0, 0x042A = bf1b(buf + 0x0B, 2), 0x0405 = bf1b(buf + 0x24, 4) * buf[0x10] +
 *    bf1b(buf + 0x0E, 2), 0x0158 = bf1b(buf + 0x0E, 2), 0x0418 = bf1b(buf + 0x2C, 4), 0x01DC = buf[0x0D].
 * 3. (EXFAT and the last case) ulong 0x0414 = 0x0418, ulong 0x0410 = 0x0418 * 4, ulong 0x01DE = 0x0418 * 4 / 0x042A.
 * 4. FUN_CODE_d5c5(), then FUN_CODE_e532(0) as a tail jump.
 * Source form the bytes depend on: the table test compares '(char)buf[3 + i]' with the char tables (Keil loads the
 * buffer byte into R5, the table byte into R4 and XORs the two registers); r = 0xFF marks a mismatch and ends the loop.
 */
extern unsigned char xdata DAT_EXTMEM_01e6[];
extern char code DAT_CODE_e0b9[];
extern char code DAT_CODE_e0c1[];
extern unsigned long xdata DAT_EXTMEM_0105;
extern unsigned char xdata DAT_EXTMEM_041c;
extern unsigned int xdata DAT_EXTMEM_01dc;
extern unsigned int xdata DAT_EXTMEM_042a;
extern unsigned long xdata DAT_EXTMEM_0418;
extern unsigned long xdata DAT_EXTMEM_0405;
extern unsigned long xdata DAT_EXTMEM_0158;
extern unsigned long xdata DAT_EXTMEM_01e2;
extern unsigned long xdata DAT_EXTMEM_0414;
extern unsigned long xdata DAT_EXTMEM_0410;
extern unsigned long xdata DAT_EXTMEM_01de;
void FUN_CODE_cbd9(unsigned long addr, unsigned char *buf, unsigned long n);
unsigned long FUN_CODE_bf1b(unsigned char *p, unsigned char n);
void FUN_CODE_aa43(void);
void FUN_CODE_d5c5(void);
void FUN_CODE_e532(unsigned int v);

void FUN_CODE_8cdc(void)
{
    unsigned char i;
    unsigned char r;
    FUN_CODE_cbd9(0, DAT_EXTMEM_01e6, 0x200);
    r = 0;
    for (i = 0; i < 8; i++) {
        if ((char)DAT_EXTMEM_01e6[3 + i] != DAT_CODE_e0b9[i] && (char)DAT_EXTMEM_01e6[3 + i] != DAT_CODE_e0c1[i]) {
            r = 0xff;
            break;
        }
    }
    if (r == 0xff) {
        DAT_EXTMEM_0105 = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + 0x1c6, 4);
        FUN_CODE_cbd9(DAT_EXTMEM_0105, DAT_EXTMEM_01e6, 0x200);
    } else DAT_EXTMEM_0105 = 0;
    if (DAT_EXTMEM_01e6[3] == 'E' && DAT_EXTMEM_01e6[4] == 'X' && DAT_EXTMEM_01e6[5] == 'F' && DAT_EXTMEM_01e6[6] == 'A'
        && DAT_EXTMEM_01e6[7] == 'T') {
        DAT_EXTMEM_041c = 1;
        DAT_EXTMEM_01dc = 1;
        DAT_EXTMEM_01dc <<= DAT_EXTMEM_01e6[0x6d];
        DAT_EXTMEM_042a = 1;
        DAT_EXTMEM_042a <<= DAT_EXTMEM_01e6[0x6c];
        DAT_EXTMEM_0418 = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + 0x60, 4);
        DAT_EXTMEM_0405 = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + 0x58, 4);
        DAT_EXTMEM_0158 = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + 0x50, 4);
    } else if (DAT_EXTMEM_01e6[3] == 'N' && DAT_EXTMEM_01e6[4] == 'T' && DAT_EXTMEM_01e6[5] == 'F'
        && DAT_EXTMEM_01e6[6] == 'S') {
        DAT_EXTMEM_041c = 2;
        DAT_EXTMEM_042a = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + 0x0b, 2);
        DAT_EXTMEM_01dc = DAT_EXTMEM_01e6[0x0d];
        DAT_EXTMEM_01e2 = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + 0x30, 4) * DAT_EXTMEM_01dc;
        FUN_CODE_aa43();
        goto done;
    } else {
        DAT_EXTMEM_041c = 0;
        DAT_EXTMEM_042a = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + 0x0b, 2);
        DAT_EXTMEM_0405 = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + 0x24, 4) * DAT_EXTMEM_01e6[0x10]
            + FUN_CODE_bf1b(DAT_EXTMEM_01e6 + 0x0e, 2);
        DAT_EXTMEM_0158 = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + 0x0e, 2);
        DAT_EXTMEM_0418 = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + 0x2c, 4);
        DAT_EXTMEM_01dc = DAT_EXTMEM_01e6[0x0d];
    }
    DAT_EXTMEM_0414 = DAT_EXTMEM_0418;
    DAT_EXTMEM_0410 = DAT_EXTMEM_0418 * 4;
    DAT_EXTMEM_01de = DAT_EXTMEM_0418 * 4 / DAT_EXTMEM_042a;
done:
    FUN_CODE_d5c5();
    FUN_CODE_e532(0);
}
