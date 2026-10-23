/* 8051_bank2 FUN_CODE_a36c @ 0xa36c (475 B, 0xA36C..0xA547), OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_a36c(cmd): ?C?CCASE switch on cmd (LARGE parameter at 0x08E5) over the XDATA bytes 0xF199..0xF19F:
 *   0x11: FUN_CODE_d393(XDATA[0xF19E], XDATA[0xF19F]) (tail jump).
 *   0x21 / 0x22: XDATA[0xCD0A] |= 0x20 / &= 0xDF.
 *   0x31: FUN_CODE_cfa5(XDATA[0xF19C], [0xF19D], [0xF19E], [0xF19F]); then XDATA[0x09CC] = XDATA[0xF199].
 *   0x41 / 0x42: FUN_CODE_e0c9(0, 0xF19B, 5) / FUN_CODE_e0c9(5, 0xF19B, 3) (generic pointer 01 F1 9B, tail jump).
 *   0x52..0x58: cmd -= 0x52; XDATA[0xF19A..0xF19F] = the 6-byte record cmd of the table at XDATA 0x011D.
 *   0x59: FUN_CODE_e532((XDATA[0xF19A] << 8) | XDATA[0xF19B]) (tail jump).
 *   0x60: a = FUN_CODE_e507(); XDATA[0xF19B..0xF19D] = bytes 0..2 of a (local at 0x08E6).
 *   0x5A: b = FUN_CODE_e516(); XDATA[0xF19B..0xF19E] = bytes 0..3 of b (local at 0x08EA).
 *   0x5B: FUN_CODE_dbd0() (tail jump).   0x70: XDATA[0x09C6] = XDATA[0xF19A].   Other values: return.
 * Callers: LCALL at 0xB5F9 and 0xB657. The ?C?CCASE case table at 0xA374..0xA3AD is data inside the function.
 * Source forms: 0xF199..0xF19F are accessed through Keil's absacc.h XBYTE form (volatile xdata pointer at 0); with
 * plain extern bytes Keil keeps cmd in R7 across the record copy and the code is 2 bytes shorter. The table is
 * declared with a fixed size (7 records of 6 bytes, under 256 bytes), so Keil computes the record offset in 8 bits
 * (MUL AB, CLR A / ADDC); with an open size it adds B as the high byte. Case 0x60 is written before case 0x5A (body
 * order and local order in the firmware).
 */
#define XBYTE ((unsigned char volatile xdata *)0)
extern unsigned char xdata DAT_EXTMEM_cd0a;
extern unsigned char xdata DAT_EXTMEM_09cc;
extern unsigned char xdata DAT_EXTMEM_09c6;
extern unsigned char xdata DAT_EXTMEM_011d[7][6];
extern void FUN_CODE_d393(unsigned char a, unsigned int b);
extern void FUN_CODE_cfa5(unsigned char a, unsigned char b, unsigned char c, unsigned char d);
extern void FUN_CODE_e0c9(unsigned char off, unsigned char *src, unsigned char n);
extern void FUN_CODE_e532(unsigned int v);
extern unsigned long FUN_CODE_e507(void);
extern unsigned long FUN_CODE_e516(void);
extern void FUN_CODE_dbd0(void);

void FUN_CODE_a36c(unsigned char cmd)
{
    unsigned long a, b;
    switch (cmd) {
    case 0x11:
        FUN_CODE_d393(XBYTE[0xF19E], XBYTE[0xF19F]);
        break;
    case 0x21:
        DAT_EXTMEM_cd0a |= 0x20;
        break;
    case 0x22:
        DAT_EXTMEM_cd0a &= 0xdf;
        break;
    case 0x31:
        FUN_CODE_cfa5(XBYTE[0xF19C], XBYTE[0xF19D], XBYTE[0xF19E], XBYTE[0xF19F]);
        DAT_EXTMEM_09cc = XBYTE[0xF199];
        break;
    case 0x41:
        FUN_CODE_e0c9(0, &XBYTE[0xF19B], 5);
        break;
    case 0x42:
        FUN_CODE_e0c9(5, &XBYTE[0xF19B], 3);
        break;
    case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: case 0x58:
        cmd -= 0x52;
        XBYTE[0xF19A] = DAT_EXTMEM_011d[cmd][0];
        XBYTE[0xF19B] = DAT_EXTMEM_011d[cmd][1];
        XBYTE[0xF19C] = DAT_EXTMEM_011d[cmd][2];
        XBYTE[0xF19D] = DAT_EXTMEM_011d[cmd][3];
        XBYTE[0xF19E] = DAT_EXTMEM_011d[cmd][4];
        XBYTE[0xF19F] = DAT_EXTMEM_011d[cmd][5];
        break;
    case 0x59:
        FUN_CODE_e532(((unsigned int)XBYTE[0xF19A] << 8) | XBYTE[0xF19B]);
        break;
    case 0x60:
        a = FUN_CODE_e507();
        XBYTE[0xF19B] = a;
        XBYTE[0xF19C] = a >> 8;
        XBYTE[0xF19D] = a >> 16;
        break;
    case 0x5a:
        b = FUN_CODE_e516();
        XBYTE[0xF19B] = b;
        XBYTE[0xF19C] = b >> 8;
        XBYTE[0xF19D] = b >> 16;
        XBYTE[0xF19E] = b >> 24;
        break;
    case 0x5b:
        FUN_CODE_dbd0();
        break;
    case 0x70:
        DAT_EXTMEM_09c6 = XBYTE[0xF19A];
        break;
    }
}
