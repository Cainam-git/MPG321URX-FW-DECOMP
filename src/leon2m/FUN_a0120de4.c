/* leon2m FUN_a0120de4 @ 0xa0120de4-0xa01211ac (242 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Returns a byte code for mode 'mode' of block blk from register 0x11 of the block (FUN_a00f1f9c(blk, 0x11) = s):
 *   0x11: (s & 0xf8) == 0x18 -> 2, == 0x38 -> 3;  0x12: (s & 0xf8) == 0x28 -> 3;
 *   0x13, 0x21: (s & 0xe0) == 0x20 -> 4 when check_regs(blk) passes, else 1;
 *   0x31, 0x41, 0x51, 0x61: 5 when DAT_a8027aac[blk].a == 1 and (s & 0xc0) == 0, or .a != 1 and (s & 0x18) == 0x18;
 *   0x71, 0x81: (s & 0xc0) == 0 -> 5;  0x91, 0xa1 -> 5;  0xb1, 0xe1, 0xe2: (s & 0xd8) == 0x18 -> 5;  0xe8 -> 2;
 *   0xc1 and all other values -> 1.
 * check_regs: register 0x23 in 1..15; register 0x22 <= (16-bit pair 0x12 & 0x1fff) / 48; pair 0x12 & 0x1fff not
 * below 0x280 and not 0x1fff; pair 0x14 & 0x1fff not below 0x200 and not 0x1fff; n = pair 0x26 + 1 >= 0xc8; then
 * register 0x22 (as a double, __floatsidf FUN_a0156840) must not be greater (__gtdf2 FUN_a0156778) than
 * 602.6 * 0.1 for n <= 0x17b, 503 * 0.1 for n <= 0x2d9, else 303.8 * 0.1 (16-bit pairs read with FUN_a00f21f0).
 * Called by FUN_a01211ac and FUN_a01213a4.
 * Source form: a switch with an explicit 'default: r = 1' (case 0xc1 keeps its own compare node) and 0xe1/0xe2 on
 * one label (a range node), which gives the firmware's compare tree; check_regs is a static helper returning
 * unsigned char with early returns and unsigned short locals; the record test is one '||' condition; the limits
 * are written as 602.6 * 0.1, 503 * 0.1 and 303.8 * 0.1, whose folded products are the firmware's constants at
 * 0x1a2fe0/0x1a2fe8/0x1a2ff0 (the literals 60.26, 50.3 and 30.38 round one unit lower).
 * Compiler aid (no instructions): 'goto g2; g2:' at the start of the 0x13/0x21 case changes the predicted branch
 * probabilities so that block reordering places the 0x51 compare block before the 0xa1 compare block.
 */
struct VMode { unsigned int a; unsigned int div32; unsigned int c; };
extern struct VMode DAT_a8027aac[];
extern unsigned char FUN_a00f1f9c(unsigned char blk, unsigned char reg);
extern unsigned short FUN_a00f21f0(unsigned char, unsigned char);

static unsigned char check_regs(unsigned char blk)
{
    unsigned short v, w;
    unsigned short c;
    unsigned short h;

    v = FUN_a00f1f9c(blk, 0x23);
    if (v < 1 || v > 15)
        return 0;
    c = FUN_a00f1f9c(blk, 0x22);
    h = FUN_a00f21f0(blk, 0x12) & 0x1fff;
    if (c > (unsigned short)(h / 48))
        return 0;
    h = FUN_a00f21f0(blk, 0x12) & 0x1fff;
    if (h < 0x280 || h == 0x1fff)
        return 0;
    h = FUN_a00f21f0(blk, 0x14) & 0x1fff;
    if (h < 0x200 || h == 0x1fff)
        return 0;
    c = FUN_a00f1f9c(blk, 0x22);
    w = FUN_a00f21f0(blk, 0x26) + 1;
    if (w < 0xc8)
        return 0;
    if (w <= 0x17b) {
        if (c > 602.6 * 0.1)
            return 0;
    } else if (w <= 0x2d9) {
        if (c > 503 * 0.1)
            return 0;
    } else {
        if (c > 303.8 * 0.1)
            return 0;
    }
    return 1;
}

unsigned char FUN_a0120de4(unsigned char mode, unsigned char blk)
{
    int r = 1;

    switch (mode) {
    case 0x11:
        if ((FUN_a00f1f9c(blk, 0x11) & 0xf8) == 0x18)
            r = 2;
        else if ((FUN_a00f1f9c(blk, 0x11) & 0xf8) == 0x38)
            r = 3;
        break;
    case 0x12:
        if ((FUN_a00f1f9c(blk, 0x11) & 0xf8) == 0x28)
            r = 3;
        break;
    case 0x13:
    case 0x21:
        goto g2;
    g2:
        if ((FUN_a00f1f9c(blk, 0x11) & 0xe0) == 0x20)
            r = check_regs(blk) ? 4 : 1;
        break;
    case 0x31:
    case 0x41:
    case 0x51:
    case 0x61:
        if ((DAT_a8027aac[blk].a == 1 && (FUN_a00f1f9c(blk, 0x11) & 0xc0) == 0)
            || (DAT_a8027aac[blk].a != 1 && (FUN_a00f1f9c(blk, 0x11) & 0x18) == 0x18))
            r = 5;
        break;
    case 0x71:
    case 0x81:
        if ((FUN_a00f1f9c(blk, 0x11) & 0xc0) == 0)
            r = 5;
        break;
    case 0x91:
    case 0xa1:
        r = 5;
        break;
    case 0xb1:
    case 0xe1:
    case 0xe2:
        if ((FUN_a00f1f9c(blk, 0x11) & 0xd8) == 0x18)
            r = 5;
        break;
    case 0xc1:
        break;
    case 0xe8:
        r = 2;
        break;
    default:
        r = 1;
        break;
    }
    return r;
}
