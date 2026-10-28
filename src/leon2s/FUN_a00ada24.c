/* leon2s FUN_a00ada24 @ 0xa00ada24-0xa00add0c, flags -mcpu=v8 -Os -g.
 * Returns a code byte for port 'port' from two register readings (FUN_a00a6f78 / FUN_a00a6bb8 take
 * (port, register number), FUN_a00a6c98(port, reg, mask, value) writes a masked field).
 *   When bit 2 of register 5 (FUN_a00a6f78) and bit 6 of register 0x8e are set: bit 7 of register 0xbe = 0,
 *   v = register 0xbd; bit 7 of 0xbe = 1, w = register 0xbd; bit 7 of 0xbe = 0. r = table code of v
 *   (6 -> 0x1b, 0x10 -> 3, 0x11 -> 9, 0x13 -> 0x15, 0x12/0x14/0x15 -> 0xf, 0x16 -> 0x1d, 0x17 -> 0x23, the 0x2x
 *   and 0x3x rows likewise, other values -> 1); for v in 0x20..0x27 r -= 2 when FUN_a00ad7c8(port) != 0;
 *   r -= 1 when bit 7 of w is set; return r.
 *   Otherwise v = register 0x8d & 0x1e; bit 7 of register 0x8e set: r = 1; else by v: 0xa -> 2 or 4 and
 *   0x1a -> 8 or 10 (FUN_a00ad7c8(port) != 0 or 0), 0xc -> 2, 0x1c -> 8, 2 -> 0x10, 0x12 -> 0x16, 4 -> 0xe,
 *   0x14 -> 0x14; 8 -> 8 when FUN_a00ad6ec(port) != 0, flag != 0 and byte +0x11f of the 0x12c-byte entry
 *   ARR_a807dc18[port] != 0, else 0; other values -> 1, or 8 under the same three conditions.
 * Source form: r is one unsigned int variable for the whole function (the 0xa / 0x1a ?: results go straight
 *   into the return register); grouped case labels for the shared codes.
 * Compiler aid: 'v = 0;' after 'r -= 1;' in the bit-7 arm is a dead store (v is not read again) and emits
 *   no instructions; with two statements in the arm the decrement is not if-converted into a sign-shift
 *   subtraction, so it stays the firmware's 'btst 0x80; bne,a; add -1' branch.
 */
struct Rec12c {
    unsigned char _0[0x11f];
    unsigned char b11f;
    unsigned char _120[0x12c - 0x120];
};
extern struct Rec12c ARR_a807dc18[];
extern unsigned int FUN_a00a6f78(unsigned char, unsigned short);
extern unsigned int FUN_a00a6bb8(unsigned char, unsigned short);
extern void FUN_a00a6c98(unsigned char, unsigned short, unsigned char, unsigned char);
extern unsigned char FUN_a00ad7c8(unsigned char);
extern unsigned char FUN_a00ad6ec(unsigned char);

unsigned char FUN_a00ada24(unsigned char port, unsigned char flag)
{
    unsigned int r;
    unsigned char v;
    unsigned char w;

    if ((FUN_a00a6f78(port, 5) & 4) && (FUN_a00a6bb8(port, 0x8e) & 0x40)) {
        FUN_a00a6c98(port, 0xbe, 0x80, 0);
        v = FUN_a00a6bb8(port, 0xbd);
        FUN_a00a6c98(port, 0xbe, 0x80, 1);
        w = FUN_a00a6bb8(port, 0xbd);
        FUN_a00a6c98(port, 0xbe, 0x80, 0);
        switch (v) {
        case 6:
            r = 0x1b;
            break;
        case 0x10:
            r = 3;
            break;
        case 0x11:
            r = 9;
            break;
        case 0x13:
            r = 0x15;
            break;
        case 0x12:
        case 0x14:
        case 0x15:
            r = 0xf;
            break;
        case 0x16:
            r = 0x1d;
            break;
        case 0x17:
            r = 0x23;
            break;
        case 0x20:
            r = 5;
            break;
        case 0x21:
            r = 0xb;
            break;
        case 0x23:
            r = 0x17;
            break;
        case 0x22:
        case 0x24:
        case 0x25:
            r = 0x11;
            break;
        case 0x26:
            r = 0x1f;
            break;
        case 0x27:
            r = 0x25;
            break;
        case 0x30:
            r = 7;
            break;
        case 0x31:
            r = 0xd;
            break;
        case 0x33:
            r = 0x19;
            break;
        case 0x32:
        case 0x34:
        case 0x35:
            r = 0x13;
            break;
        case 0x36:
            r = 0x21;
            break;
        case 0x37:
            r = 0x27;
            break;
        default:
            r = 1;
            break;
        }
        if (v >= 0x20 && v <= 0x27) {
            if (FUN_a00ad7c8(port))
                r -= 2;
        }
        if (w & 0x80) {
            r -= 1;
            v = 0;
        }
        return r;
    }
    v = FUN_a00a6bb8(port, 0x8d) & 0x1e;
    if (FUN_a00a6bb8(port, 0x8e) & 0x80)
        r = 1;
    else switch (v) {
    case 0xa:
        r = FUN_a00ad7c8(port) ? 2 : 4;
        break;
    case 0x1a:
        r = FUN_a00ad7c8(port) ? 8 : 10;
        break;
    case 0xc:
        r = 2;
        break;
    case 0x1c:
        r = 8;
        break;
    case 2:
        r = 0x10;
        break;
    case 0x12:
        r = 0x16;
        break;
    case 4:
        r = 0xe;
        break;
    case 0x14:
        r = 0x14;
        break;
    case 8:
        if (FUN_a00ad6ec(port) && flag) {
            r = 8;
            if (!ARR_a807dc18[port].b11f)
                r = 0;
        } else
            r = 0;
        break;
    default:
        r = 1;
        if (FUN_a00ad6ec(port) && flag) {
            r = 8;
            if (!ARR_a807dc18[port].b11f)
                r = 1;
        }
        break;
    }
    return r;
}
