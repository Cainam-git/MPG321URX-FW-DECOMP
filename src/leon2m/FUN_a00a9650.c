/* leon2m FUN_a00a9650 @ 0xa00a9650-0xa00a9abc (283 words), flags -mcpu=v8 -O3 -g. Many callers (FUN_a00918f4,
 * FUN_a00932a8, FUN_a0094438, ...).
 * With y = row * 2 + 5 and f = (mode != 0 && mode != 2):
 *  - mode 0 or 2: FUN_a00a9468(1, 2), FUN_a00b34d4(0, 1). mode 1: k = FUN_a00a8a78(row); k == 1 gives the same two
 *    calls, otherwise k is computed again and k == 0 gives FUN_a00a9468(1, 3), FUN_a00b34d4(0, 4).
 *  - w = 3 when f, else 4; FUN_a0146c40(w, 0, 0); FUN_a014667c(w, 0, 0, 0, 0, 4 when f / 0xc, 0, 0, 0, 0, 0);
 *    FUN_a0146870(w, 0x3a8, (u8)y * 36 + 0x1a / 0x16, 0x4f7, (u8)y * 36 + 0x51 / 0x55, 0).
 *  - f: FUN_a0146c40(w, 1, 0), FUN_a00b3ed0(1, 0x27, (u8)y, 0xe), FUN_a00b32e4(0, 1, 0x589a, 0x27 / 0x34, y, 3,
 *    0xa6 / 0xa9), FUN_a0146c40(1, 1, 0), FUN_a0146c40(2, 1, 0).
 *  - otherwise, FUN_a0090fcc() in 0x58..0x5b: FUN_a00b32e4(1, 0, 0x792, 0x27, y, 0xe, 0), the same with y + 2,
 *    then with y + 1 and length 1 for x 0x27 and 0x34; else FUN_a0146b20(0, 0x27 / 0x34, (u8)y + k, 1, 0, 0) for
 *    k = 0..2. Both end with FUN_a0146c40(w, 1, 0).
 * Source form: the same-file function FUN_a00a8a78 (switch over FUN_a0090fcc(), jump tables 0xa00a3e50 and
 * 0xa00a3b64 in its two inlined copies) is defined here as a static copy; y is an unsigned int and the call
 * arguments narrow it; the f test is written out at each use (if-conversion computes it again each time).
 */
extern unsigned short FUN_a0090fcc(void);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00b34d4(unsigned int, unsigned int);
extern void FUN_a0146c40(int, int, int);
extern void FUN_a014667c(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                         unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a0146870(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00b3ed0(unsigned char, unsigned char, unsigned int, unsigned int);
extern void FUN_a00b32e4(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char,
                         unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

static unsigned char FUN_a00a8a78(unsigned char p)
{
    unsigned char r = 0;

    switch (FUN_a0090fcc()) {
    case 0x3f:
    case 0x40:
    case 0x41:
    case 0x44:
    case 0x45:
    case 0x53:
    case 0x56:
    case 0x58:
    case 0x59:
    case 0x5a:
    case 0x5b:
    case 0x6f:
    case 0x7a:
    case 0x7b:
    case 0x7c:
    case 0x82:
    case 0x83:
    case 0xb3:
    case 0xba:
    case 0xbd:
    case 0xbe:
    case 0xbf:
    case 0xdc:
    case 0xe1:
    case 0xe6:
        r = 1;
        break;
    case 0xc0:
    case 0xc1:
    case 0xc2:
        if (p == 2)
            r = 1;
        break;
    case 0x69:
    case 0x6a:
    case 0x6b:
    case 0xaf:
    case 0xb0:
    case 0xca:
    case 0xcb:
    case 0xcc:
    case 0xf5:
    case 0xf7:
    case 0xf8:
    case 0xf9:
        r = 2;
        break;
    }
    return r & 3;
}

void FUN_a00a9650(unsigned char row, unsigned char mode)
{
    unsigned int y = row * 2 + 5;
    unsigned char w;
    unsigned char k;

    if (mode == 0 || mode == 2) {
        FUN_a00a9468(1, 2);
        FUN_a00b34d4(0, 1);
    } else if (mode == 1) {
        if (FUN_a00a8a78(row) == 1) {
            FUN_a00a9468(1, 2);
            FUN_a00b34d4(0, 1);
        } else if (FUN_a00a8a78(row) == 0) {
            FUN_a00a9468(1, 3);
            FUN_a00b34d4(0, 4);
        }
    }
    w = (mode != 0 && mode != 2) ? 3 : 4;
    FUN_a0146c40(w, 0, 0);
    if (mode != 0 && mode != 2)
        FUN_a014667c(w, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0);
    else
        FUN_a014667c(w, 0, 0, 0, 0, 0xc, 0, 0, 0, 0, 0);
    if (mode != 0 && mode != 2)
        FUN_a0146870(w, 0x3a8, (unsigned char)y * 36 + 0x1a, 0x4f7, (unsigned char)y * 36 + 0x51, 0);
    else
        FUN_a0146870(w, 0x3a8, (unsigned char)y * 36 + 0x16, 0x4f7, (unsigned char)y * 36 + 0x55, 0);
    if (mode != 0 && mode != 2) {
        FUN_a0146c40(w, 1, 0);
        FUN_a00b3ed0(1, 0x27, (unsigned char)y, 0xe);
        FUN_a00b32e4(0, 1, 0x589a, 0x27, y, 3, 0xa6);
        FUN_a00b32e4(0, 1, 0x589a, 0x34, y, 3, 0xa9);
        FUN_a0146c40(1, 1, 0);
        FUN_a0146c40(2, 1, 0);
    } else if (FUN_a0090fcc() > 0x57 && FUN_a0090fcc() <= 0x5b) {
        FUN_a00b32e4(1, 0, 0x792, 0x27, y, 0xe, 0);
        FUN_a00b32e4(1, 0, 0x792, 0x27, y + 2, 0xe, 0);
        FUN_a00b32e4(1, 0, 0x792, 0x27, y + 1, 1, 0);
        FUN_a00b32e4(1, 0, 0x792, 0x34, y + 1, 1, 0);
        FUN_a0146c40(w, 1, 0);
    } else {
        for (k = 0; k <= 2; k++) {
            FUN_a0146b20(0, 0x27, (unsigned char)y + k, 1, 0, 0);
            FUN_a0146b20(0, 0x34, (unsigned char)y + k, 1, 0, 0);
        }
        FUN_a0146c40(w, 1, 0);
    }
}
