/* leon2s FUN_a00db784 @ 0xa00db784-0xa00db9d4, -mcpu=v8 -Os -g.
 * void (void). Code linked 0xF10000 above its load address (func_0xa0f8.... calls, s_9f1c.... strings).
 * i = DAT_a80787fd, row = the 48-byte row DAT_a8079c98[i], f = a local flag byte. Bit 4 of DAT_a8078841:
 * DAT_a8079c50[i] = 0 and three 16-byte reads func_0xa0f96400(0, 0x90, 0x1400 / 0x1410 / 0x1420, 0xf, row +
 * 0 / 0x10 / 0x20); bit 5 instead: DAT_a8079c50[i] = 1 and the reads from 0x1600 / 0x1610 / 0x1620. A failed
 * read passes s_9f1ccb58 / s_9f1ccb78 / s_9f1ccb98 to func_0xa0f834c4 and returns; neither bit: return.
 * After the reads the bit is cleared and set in f; v = (row[0] >> 4) - 1, n = v / 2 rounded up for odd v;
 * a non-zero low nibble of row[0] steps DAT_a80787fd modulo 16; func_0xa0f963d4(0, 0x80, 0x2003, 0, &f)
 * (0 result: s_9f1ccbb8). When row[n + 3] is 0x11 and row[n + 6], row[n + 7] are 0: FUN_a00dae90(row[n + 5],
 * 1, 0) and FUN_a00d64ec(). Same module as FUN_a00db53c.
 */
extern unsigned char DAT_a80787fd;
extern unsigned char DAT_a8078841;
extern unsigned char DAT_a8079c50[];
extern unsigned char DAT_a8079c98[][48];
extern const char s_9f1ccb58[], s_9f1ccb78[], s_9f1ccb98[], s_9f1ccbb8[];
extern int func_0xa0f834c4(const char *);
extern unsigned char func_0xa0f96400(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);
extern unsigned char func_0xa0f963d4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);
extern int FUN_a00dae90(unsigned char, unsigned char, unsigned char);
extern void FUN_a00d64ec(void);

void FUN_a00db784(void)
{
    unsigned char *row;
    unsigned char f;
    int v;
    unsigned char n;

    row = DAT_a8079c98[DAT_a80787fd];
    f = 0;
    if (DAT_a8078841 & 0x10) {
        DAT_a8079c50[DAT_a80787fd] = 0;
        if (!func_0xa0f96400(0, 0x90, 0x1400, 0xf, row)) {
            func_0xa0f834c4(s_9f1ccb58);
            return;
        }
        if (!func_0xa0f96400(0, 0x90, 0x1410, 0xf, row + 0x10)) {
            func_0xa0f834c4(s_9f1ccb78);
            return;
        }
        if (!func_0xa0f96400(0, 0x90, 0x1420, 0xf, row + 0x20)) {
            func_0xa0f834c4(s_9f1ccb98);
            return;
        }
        f |= 0x10;
        DAT_a8078841 &= ~0x10;
    } else if (DAT_a8078841 & 0x20) {
        DAT_a8079c50[DAT_a80787fd] = 1;
        if (!func_0xa0f96400(0, 0x90, 0x1600, 0xf, row)) {
            func_0xa0f834c4(s_9f1ccb58);
            return;
        }
        if (!func_0xa0f96400(0, 0x90, 0x1610, 0xf, row + 0x10)) {
            func_0xa0f834c4(s_9f1ccb78);
            return;
        }
        if (!func_0xa0f96400(0, 0x90, 0x1620, 0xf, row + 0x20)) {
            func_0xa0f834c4(s_9f1ccb98);
            return;
        }
        f |= 0x20;
        DAT_a8078841 &= ~0x20;
    } else
        return;
    v = (row[0] >> 4) - 1;
    n = v / 2;
    if (v & 1)
        n = v / 2 + 1;
    if (row[0] & 0xf)
        DAT_a80787fd = (DAT_a80787fd + 1) & 0xf;
    if (!func_0xa0f963d4(0, 0x80, 0x2003, 0, &f))
        func_0xa0f834c4(s_9f1ccbb8);
    if (row[n + 3] == 0x11 && row[n + 6] == 0 && row[n + 7] == 0) {
        FUN_a00dae90(row[n + 5], 1, 0);
        FUN_a00d64ec();
    }
}
