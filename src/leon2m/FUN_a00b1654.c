/* leon2m FUN_a00b1654 @ 0xa00b1654-0xa00b1700 (172 bytes), flags -mcpu=v8 -O3 -g. Called by FUN_a009f42c (three
 * calls).
 * When FUN_a0145af8(0x10) returns 0: returns b when a equals FUN_a0127a08(0xff) - 1 and b is 0x1e, 0x32 or 0x37,
 * else 0. Otherwise: returns 0x1e, 0x32 or 0x37 for a == 1 and b 0x11, 0x12 or 0x13, else 0.
 * Source form: the zero-result branch is written first. Register renaming then visits its blocks before the
 * a == 1 test, which gives the a and b values of the other branch %o7 and %g1.
 */
extern unsigned short FUN_a0145af8(unsigned int id);
extern int FUN_a0127a08(unsigned char i);

unsigned char FUN_a00b1654(unsigned char a, unsigned char b)
{
    if (FUN_a0145af8(0x10) == 0) {
        if (a == FUN_a0127a08(0xff) - 1 && (b == 0x1e || b == 0x32 || b == 0x37))
            return b;
        return 0;
    } else {
        if (a == 1) {
            if (b == 0x11)
                return 0x1e;
            if (b == 0x12)
                return 0x32;
            if (b == 0x13)
                return 0x37;
        }
        return 0;
    }
}
