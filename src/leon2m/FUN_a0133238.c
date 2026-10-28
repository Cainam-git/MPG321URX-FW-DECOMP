/* leon2m FUN_a0133238 @ 0xa0133238-0xa0133384 (83 words), -mcpu=v8 -O3 -g.
 * Clears the 12-byte table DAT_a802da60 and writes four byte pairs (code, entry) at positions 0..7:
 * code FUN_a0132d44(5) = 0x15 with entry FUN_a0132dd8(0x10, 1) and FUN_a0132dd8(0x20, 1), then code
 * FUN_a0132d44(6) = 0x16 with FUN_a0132dd8(2, 0) and FUN_a0132dd8(1, 0) (entry = (b & 1) << 4 | index of the
 * bit set in m). FUN_a0132d44 and FUN_a0132dd8 are the same-file functions, inlined here as static copies, as in
 * FUN_a0132e1c. Leaf; called by FUN_a0136600.
 * Source form: four copies of one block 'tab[q++] = FUN_a0132d44(c); tab[q++] = FUN_a0132dd8(m, b); if (q > 0xb)
 * return;' with q set to 0 after the clear loop (GCC folds the positions and tests).
 */
extern unsigned char DAT_a802da60[12];

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

void FUN_a0133238(void)
{
    unsigned char i, q;

    for (i = 0; i < 12; i++)
        DAT_a802da60[i] = 0;
    q = 0;
    DAT_a802da60[q++] = FUN_a0132d44(5);
    DAT_a802da60[q++] = FUN_a0132dd8(0x10, 1);
    if (q > 0xb)
        return;
    DAT_a802da60[q++] = FUN_a0132d44(5);
    DAT_a802da60[q++] = FUN_a0132dd8(0x20, 1);
    if (q > 0xb)
        return;
    DAT_a802da60[q++] = FUN_a0132d44(6);
    DAT_a802da60[q++] = FUN_a0132dd8(0x2, 0);
    if (q > 0xb)
        return;
    DAT_a802da60[q++] = FUN_a0132d44(6);
    DAT_a802da60[q++] = FUN_a0132dd8(0x1, 0);
    if (q > 0xb)
        return;
}
