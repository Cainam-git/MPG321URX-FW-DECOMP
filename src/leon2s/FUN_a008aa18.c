/* FUN_a008aa18 (leon2s 0xa008aa18-0xa008aab0, 152 bytes), flags -mcpu=v8 -Os -g.
 * Calls FUN_a008a974(0x44) and reads the byte m = FUN_a0089f84(0). For m = 4, 5, 6 or 7: FUN_a008a924(0x8000),
 * then FUN_a008a9ec(0, v) and FUN_a008a9ec(1, v). For m = 1: FUN_a008a924(0x8000) and FUN_a008a95c with the
 * high byte of v. Otherwise FUN_a008a924(v).
 * Source form: the 4..7 test is a static helper with one early return per value; GCC inlines it and keeps the
 * four compares (an || chain or a switch is folded into one range test).
 */
extern void FUN_a008a974(unsigned char v);
extern unsigned char FUN_a0089f84(unsigned char p);
extern void FUN_a008a924(unsigned int v);
extern void FUN_a008a95c(unsigned char v);
extern void FUN_a008a9ec(unsigned char port, unsigned short v);

static int sel(unsigned char m)
{
    if (m == 4)
        return 1;
    if (m == 5)
        return 1;
    if (m == 6)
        return 1;
    if (m == 7)
        return 1;
    return 0;
}

void FUN_a008aa18(unsigned short v)
{
    unsigned char m;

    FUN_a008a974(0x44);
    m = FUN_a0089f84(0);
    if (sel(m)) {
        FUN_a008a924(0x8000);
        FUN_a008a9ec(0, v);
        FUN_a008a9ec(1, v);
    } else if (m == 1) {
        FUN_a008a924(0x8000);
        FUN_a008a95c(v >> 8);
    } else {
        FUN_a008a924(v);
    }
}
