/* FUN_a0083870 (leon2s 0xa0083870-0xa0083e28, 1464 bytes), flags -mcpu=v8 -Os -g.
 * Reads the low byte of the five hardware registers 0xcf018884, 0xcf019484, 0xcf019884, 0xcf019c84 and
 * 0xcf01a084 once at entry. Bit 0 of the argument: for each register whose enable getter (FUN_a0070424,
 * FUN_a006ffb4, FUN_a006ffc4, FUN_a006ffd4, FUN_a006ffe4) returns non-zero, copies its bit 3 into bit 2..6 of
 * the status byte DAT_a80789e0; for the getters FUN_a0070404 / FUN_a0070414, copies bit 1 of
 * FUN_a00a7fd8(0 / 1, 0, 9) into bit 0 / bit 1 of DAT_a80789e0.
 * Bit 1 of the argument: clears the word DAT_a80789e4; for each enabled register with bit 6 set, writes
 * (byte & 0x3f) | 0x40 back and sets one of two bits of DAT_a80789e4 chosen by bit 3; with bit 7 set, writes
 * (byte & 0x3f) | 0x80 back and sets a third bit. For FUN_a0070404 / FUN_a0070414, compares bit 0 / bit 1 of
 * DAT_a80789e0 with the previous value in DAT_a80789e8 / DAT_a80789e9 (0 -> 1 sets 0x200 / 0x800, 1 -> 0
 * sets 0x400 / 0x1000 in DAT_a80789e4) and stores the new bit value.
 * Source form: the five register values are unsigned char locals.
 */
#define R0 (*(volatile unsigned int *)0xcf018884)
#define R1 (*(volatile unsigned int *)0xcf019484)
#define R2 (*(volatile unsigned int *)0xcf019884)
#define R3 (*(volatile unsigned int *)0xcf019c84)
#define R4 (*(volatile unsigned int *)0xcf01a084)

extern unsigned char DAT_a80789e0;
extern unsigned int DAT_a80789e4;
extern unsigned char DAT_a80789e8;
extern unsigned char DAT_a80789e9;

extern unsigned char FUN_a0070424(void);
extern unsigned char FUN_a006ffb4(void);
extern unsigned char FUN_a006ffc4(void);
extern unsigned char FUN_a006ffd4(void);
extern unsigned char FUN_a006ffe4(void);
extern unsigned char FUN_a0070404(void);
extern unsigned char FUN_a0070414(void);
extern short FUN_a00a7fd8(unsigned int param_1, unsigned short param_2, unsigned short param_3);

void FUN_a0083870(unsigned char mode)
{
    unsigned char a = R0;
    unsigned char b = R1;
    unsigned char c = R2;
    unsigned char d = R3;
    unsigned char e = R4;

    if (mode & 1) {
        if (FUN_a0070424()) {
            if (a & 8)
                DAT_a80789e0 |= 4;
            else
                DAT_a80789e0 &= ~4;
        }
        if (FUN_a006ffb4()) {
            if (b & 8)
                DAT_a80789e0 |= 8;
            else
                DAT_a80789e0 &= ~8;
        }
        if (FUN_a006ffc4()) {
            if (c & 8)
                DAT_a80789e0 |= 0x10;
            else
                DAT_a80789e0 &= ~0x10;
        }
        if (FUN_a006ffd4()) {
            if (d & 8)
                DAT_a80789e0 |= 0x20;
            else
                DAT_a80789e0 &= ~0x20;
        }
        if (FUN_a006ffe4()) {
            if (e & 8)
                DAT_a80789e0 |= 0x40;
            else
                DAT_a80789e0 &= ~0x40;
        }
        if (FUN_a0070404()) {
            if (FUN_a00a7fd8(0, 0, 9) & 2)
                DAT_a80789e0 |= 1;
            else
                DAT_a80789e0 &= ~1;
        }
        if (FUN_a0070414()) {
            if (FUN_a00a7fd8(1, 0, 9) & 2)
                DAT_a80789e0 |= 2;
            else
                DAT_a80789e0 &= ~2;
        }
    }
    if (mode & 2) {
        DAT_a80789e4 = 0;
        if (FUN_a0070424()) {
            if (a & 0x40) {
                R0 = (a & 0x3f) | 0x40;
                if (a & 8)
                    DAT_a80789e4 |= 1;
                else
                    DAT_a80789e4 |= 2;
            }
            if (a & 0x80) {
                R0 = (a & 0x3f) | 0x80;
                DAT_a80789e4 |= 4;
            }
        }
        if (FUN_a006ffb4()) {
            if (b & 0x40) {
                R1 = (b & 0x3f) | 0x40;
                if (b & 8)
                    DAT_a80789e4 |= 8;
                else
                    DAT_a80789e4 |= 0x10;
            }
            if (b & 0x80) {
                R1 = (b & 0x3f) | 0x80;
                DAT_a80789e4 |= 0x20;
            }
        }
        if (FUN_a006ffc4()) {
            if (c & 0x40) {
                R2 = (c & 0x3f) | 0x40;
                if (c & 8)
                    DAT_a80789e4 |= 0x40;
                else
                    DAT_a80789e4 |= 0x80;
            }
            if (c & 0x80) {
                R2 = (c & 0x3f) | 0x80;
                DAT_a80789e4 |= 0x100;
            }
        }
        if (FUN_a006ffd4()) {
            if (d & 0x40) {
                R3 = (d & 0x3f) | 0x40;
                if (d & 8)
                    DAT_a80789e4 |= 0x2000;
                else
                    DAT_a80789e4 |= 0x4000;
            }
            if (d & 0x80) {
                R3 = (d & 0x3f) | 0x80;
                DAT_a80789e4 |= 0x8000;
            }
        }
        if (FUN_a006ffe4()) {
            if (e & 0x40) {
                R4 = (e & 0x3f) | 0x40;
                if (e & 8)
                    DAT_a80789e4 |= 0x10000;
                else
                    DAT_a80789e4 |= 0x20000;
            }
            if (e & 0x80) {
                R4 = (e & 0x3f) | 0x80;
                DAT_a80789e4 |= 0x40000;
            }
        }
        if (FUN_a0070404()) {
            if (DAT_a80789e8 == 0 && (DAT_a80789e0 & 1))
                DAT_a80789e4 |= 0x200;
            else if (DAT_a80789e8 == 1 && !(DAT_a80789e0 & 1))
                DAT_a80789e4 |= 0x400;
            DAT_a80789e8 = DAT_a80789e0 & 1;
        }
        if (FUN_a0070414()) {
            if (DAT_a80789e9 == 0 && (DAT_a80789e0 & 2))
                DAT_a80789e4 |= 0x800;
            else if (DAT_a80789e9 == 1 && !(DAT_a80789e0 & 2))
                DAT_a80789e4 |= 0x1000;
            DAT_a80789e9 = (DAT_a80789e0 >> 1) & 1;
        }
    }
}
