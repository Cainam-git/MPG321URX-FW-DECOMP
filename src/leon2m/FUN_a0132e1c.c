/* leon2m FUN_a0132e1c @ 0xa0132e1c-0xa0133238 (230 words), -mcpu=v8 -O3 -g.
 * Clears the 12-byte table DAT_a802d9b8 and fills it with byte pairs (code, entry), at most six pairs.
 * When bit 31 of the word DAT_a802e3d0 is set it writes four fixed pairs for (c, m) = (3, 4), (3, 8), (11, 2),
 * (2, 0x10) and returns. Otherwise n is taken from the byte DAT_a802e1a7 (0 -> 1, 1/2/5 -> 2, 3/6 -> 3, 4/7 -> 4,
 * other values keep 1; jump table 0xa0132b0c) and for k = 0..n-1: a = FUN_a0142168(FUN_a012fc70(k)) (0 when a >= 7),
 * c = FUN_a01252e0(DAT_a802e116[a].b10), m = FUN_a01252fc(DAT_a802e116[a].b10) (18-byte records); the pair is
 * code = FUN_a0132d44(c) and entry = FUN_a0132dd8(m, ~func_0x4008cd38(c, m)); a pair already in the table (even
 * positions 0..10) is skipped, otherwise it is appended, and the function returns once the position passes 0xb.
 * FUN_a0132d44 (jump table 0xa0132ac0) and FUN_a0132dd8 are the same-file functions, inlined here as static copies.
 * Called by FUN_a0136600.
 * Source form: the four fixed pairs are four copies of one block (code from FUN_a0132d44(c), entry, position test)
 * with their own position variable q, initialised in its declaration; GCC folds the first two position tests and
 * keeps the third (constant 6 in a register), as in the firmware. The main path uses pos, set to 0 before the
 * bit-31 test. FUN_a012fc70 is called with the loop counter k. n is a switch with grouped case labels.
 */
struct E116 {
    unsigned char pad[0x10];
    unsigned char b10;
    unsigned char pad11;
};
extern unsigned char DAT_a802d9b8[12];
extern unsigned int DAT_a802e3d0;
extern unsigned char DAT_a802e1a7;
extern struct E116 DAT_a802e116[];
extern int func_0x4008cd38(int, int);
extern unsigned char FUN_a012fc70(unsigned char);
extern unsigned char FUN_a0142168(unsigned char);
extern unsigned char FUN_a01252e0(unsigned int);
extern unsigned char FUN_a01252fc(unsigned int);

static unsigned char FUN_a0132d44(unsigned char c)
{
    unsigned char r = 0;
    switch (c) {
    case 1:
        r = 0x11;
        break;
    case 2:
        r = 0x12;
        break;
    case 3:
        r = 0x13;
        break;
    case 4:
        r = 0x14;
        break;
    case 5:
        r = 0x15;
        break;
    case 6:
        r = 0x16;
        break;
    case 7:
        r = 0x17;
        break;
    case 8:
        r = 0x18;
        break;
    case 9:
        r = 0x19;
        break;
    case 10:
        r = 0x1a;
        break;
    case 11:
        r = 0x1b;
        break;
    case 12:
        r = 0x1c;
        break;
    case 13:
        r = 0x1d;
        break;
    case 18:
        r = 0x11;
        break;
    }
    return r & 0x1f;
}

static unsigned char FUN_a0132dd8(unsigned char c, unsigned char b)
{
    unsigned char r;
    unsigned char i;
    for (i = 0; i < 8; i++)
        if ((c >> i) == 1)
            break;
    r = ((b & 1) << 4) | i;
    return r;
}

void FUN_a0132e1c(void)
{
    unsigned char k, a, c, m, code, e, j, found, pos;
    unsigned char q = 0;
    unsigned char i = 0;
    unsigned char n = 1;

    for (; i < 12; i++)
        DAT_a802d9b8[i] = 0;
    pos = 0;
    if (DAT_a802e3d0 >> 31) {
        DAT_a802d9b8[q++] = FUN_a0132d44(3);
        DAT_a802d9b8[q++] = FUN_a0132dd8(0x4, ~func_0x4008cd38(3, 0x4));
        if (q > 0xb)
            return;
        DAT_a802d9b8[q++] = FUN_a0132d44(3);
        DAT_a802d9b8[q++] = FUN_a0132dd8(0x8, ~func_0x4008cd38(3, 0x8));
        if (q > 0xb)
            return;
        DAT_a802d9b8[q++] = FUN_a0132d44(11);
        DAT_a802d9b8[q++] = FUN_a0132dd8(0x2, ~func_0x4008cd38(11, 0x2));
        if (q > 0xb)
            return;
        DAT_a802d9b8[q++] = FUN_a0132d44(2);
        DAT_a802d9b8[q++] = FUN_a0132dd8(0x10, ~func_0x4008cd38(2, 0x10));
        if (q > 0xb)
            return;
        return;
    }
    switch (DAT_a802e1a7) {
    case 0:
        n = 1;
        break;
    case 1:
    case 2:
    case 5:
        n = 2;
        break;
    case 3:
    case 6:
        n = 3;
        break;
    case 4:
    case 7:
        n = 4;
        break;
    }
    for (k = 0; k < n; k++) {
        a = FUN_a0142168(FUN_a012fc70(k));
        if (a >= 7)
            a = 0;
        c = FUN_a01252e0(DAT_a802e116[a].b10);
        m = FUN_a01252fc(DAT_a802e116[a].b10);
        code = FUN_a0132d44(c);
        e = FUN_a0132dd8(m, ~func_0x4008cd38(c, m));
        found = 0;
        for (j = 0; j < 12; j += 2) {
            if (DAT_a802d9b8[j] == code && DAT_a802d9b8[j + 1] == e) {
                found = 1;
                break;
            }
        }
        if (!found) {
            DAT_a802d9b8[pos++] = code;
            DAT_a802d9b8[pos++] = e;
            if (pos > 0xb)
                return;
        }
    }
}
