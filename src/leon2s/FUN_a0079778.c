/* FUN_a0079778 (leon2s 0xa0079778-0xa00798fc, 388 bytes), flags -mcpu=v8 -Os -g.
 * Calls FUN_a00a7424(on == 1, 0x15, port, reg) for a list of registers: mode 1 uses 0x2100, 0x2500, 0x2900,
 * 0x3100 in that order when on is 1 and in reverse order otherwise; other modes use 0x1100, 0x1500, 0x1900
 * (on 1) or 0x1900, 0x1500, 0x1100.
 * Source form: the mode 1 calls pass 'on == 1' directly; the other calls go through a macro that tests on and
 * passes the literal 1 or 0, so each call repeats the test with its own constants.
 */
extern void FUN_a00a7424(int mode, unsigned int bit, unsigned char reg, unsigned short val);

#define WR(port, on, reg) \
    if ((on) == 1) \
        FUN_a00a7424(1, 0x15, port, reg); \
    else \
        FUN_a00a7424(0, 0x15, port, reg)

void FUN_a0079778(unsigned char port, unsigned char on, unsigned char mode)
{
    if (mode == 1) {
        if (on == 1) {
            FUN_a00a7424(on == 1, 0x15, port, 0x2100);
            FUN_a00a7424(on == 1, 0x15, port, 0x2500);
            FUN_a00a7424(on == 1, 0x15, port, 0x2900);
            FUN_a00a7424(on == 1, 0x15, port, 0x3100);
        } else {
            FUN_a00a7424(on == 1, 0x15, port, 0x3100);
            FUN_a00a7424(on == 1, 0x15, port, 0x2900);
            FUN_a00a7424(on == 1, 0x15, port, 0x2500);
            FUN_a00a7424(on == 1, 0x15, port, 0x2100);
        }
    } else {
        if (on == 1) {
            WR(port, on, 0x1100);
            WR(port, on, 0x1500);
            WR(port, on, 0x1900);
        } else {
            WR(port, on, 0x1900);
            WR(port, on, 0x1500);
            WR(port, on, 0x1100);
        }
    }
}
