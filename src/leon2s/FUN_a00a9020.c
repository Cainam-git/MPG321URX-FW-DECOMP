/* FUN_a00a9020 (leon2s 0xa00a9020-0xa00a9380, 864 bytes), flags -mcpu=v8 -Os -g.
 * Builds the 9-byte packet pkt from the bytes in[0..3]: pkt[0..2] = 0x82, 2, 0x0d; pkt[4] = b4 << 5;
 * pkt[5] = b5 << 6; pkt[6] = b6h << 4 | b6l << 2; pkt[8] = b8h << 6 | b8l (b8l = mode < 0x1a); pkt[3] = minus
 * the 8-bit sum of 0x91 and pkt[4..8]. The six values live in a local struct that is first cleared with
 * FUN_a00b15ac (fill: pointer, value, count).
 * in[1] bit 6 clear: b6l = 2, b8h = 0; unless in[1] bit 7 is set, (in[0] & 0x1e) selects b4, b5, b6h
 * (value 8 also sets b6l = 1). in[1] bit 6 set: the high nibble of in[2] is 0 (b5 = 3, b6h from the low
 * nibble, b6l = 1 or 2 from in[3] bit 7), 0x10..0x30 (b4 = 2, 1, 3; b5 and b6h from the low nibble, b8h =
 * in[3] bit 7 clear, b6l = 0) or larger (b5 = 3, b6h = 4, rest 0).
 * Source forms the exact build depends on: case 0 listed with the default body (jump table from 0), case
 * order 0, 8, 0xa, 0xc, 0x1a, 0x1c, 2, 4, 0x12, 0x14, 0x18 and the store order inside the cases (cross-jumped
 * tails); in[2] read into an unsigned char b, copied to an int v for the high-nibble tests, and the second
 * low-nibble switch on an unsigned char lo = b & 0xf (gives the firmware's separate 'and 0xff' copy); the
 * checksum seed loaded from pkt[3] in the for initialiser. Jump tables at 0xa00a8f8c (8 entries) and
 * 0xa00a8fac (29 entries).
 */
extern void *FUN_a00b15ac(void *, int, unsigned int);

struct fields {
    int b4;
    int b5;
    int b6h;
    int b6l;
    int b8h;
    int b8l;
};

void FUN_a00a9020(unsigned int mode, unsigned char *in, unsigned char *pkt)
{
    struct fields s;
    int v, hi;
    unsigned char i;
    unsigned char sum;
    unsigned char b, lo;

    FUN_a00b15ac(&s, 0, sizeof s);
    if (!(in[1] & 0x40)) {
        s.b6l = 2;
        s.b8h = 0;
        if (!(in[1] & 0x80)) {
            switch (in[0] & 0x1e) {
            case 0:
                s.b5 = 0;
                s.b6h = 0;
                s.b4 = 0;
                break;
            case 8:
                s.b6l = 1;
                s.b5 = 0;
                s.b6h = 0;
                s.b4 = 0;
                break;
            case 0xa:
                s.b5 = 1;
                s.b4 = 1;
                s.b6h = 0;
                break;
            case 0xc:
                s.b5 = 1;
                s.b4 = 2;
                s.b6h = 0;
                break;
            case 0x1a:
                s.b5 = 2;
                s.b4 = 1;
                s.b6h = 0;
                break;
            case 0x1c:
                s.b5 = 2;
                s.b4 = 2;
                s.b6h = 0;
                break;
            case 2:
                s.b5 = 3;
                s.b4 = 1;
                s.b6h = 0;
                break;
            case 4:
                s.b5 = 3;
                s.b4 = 2;
                s.b6h = 0;
                break;
            case 0x12:
                s.b5 = 3;
                s.b6h = 1;
                s.b4 = 1;
                break;
            case 0x14:
                s.b5 = 3;
                s.b6h = 1;
                s.b4 = 2;
                break;
            case 0x18:
                s.b5 = 3;
                s.b6h = 4;
                s.b4 = 0;
                break;
            default:
                s.b5 = 0;
                s.b6h = 0;
                s.b4 = 0;
                break;
            }
        }
    } else {
        b = in[2];
        v = b;
        hi = v & 0xf0;
        if (hi == 0) {
            s.b4 = 0;
            switch (v & 0xf) {
            case 3:
                s.b5 = 3;
                s.b6h = 4;
                break;
            case 4:
                s.b5 = 3;
                s.b6h = 7;
                break;
            case 6:
                s.b5 = 3;
                s.b6h = 6;
                break;
            default:
                s.b5 = 3;
                s.b6h = 4;
                break;
            }
            s.b6l = ((signed char)in[3] >= 0) ? 2 : 1;
            s.b8h = 0;
        } else if (hi >= 0x10 && hi <= 0x30) {
            switch (hi) {
            case 0x10:
                s.b4 = 2;
                break;
            case 0x20:
                s.b4 = 1;
                break;
            case 0x30:
                s.b4 = 3;
                break;
            default:
                s.b4 = 2;
                break;
            }
            lo = b & 0xf;
            switch (lo) {
            case 0:
                s.b5 = 1;
                s.b6h = 0;
                break;
            case 1:
                s.b5 = 2;
                s.b6h = 0;
                break;
            case 2:
                s.b5 = 3;
                s.b6h = 0;
                break;
            case 3:
                s.b5 = 3;
                s.b6h = 1;
                break;
            case 4:
                s.b5 = 3;
                s.b6h = 2;
                break;
            case 5:
                s.b5 = 3;
                s.b6h = 3;
                break;
            case 6:
                s.b5 = 3;
                s.b6h = 5;
                break;
            case 7:
                s.b5 = 3;
                s.b6h = 6;
                break;
            default:
                s.b5 = 1;
                s.b6h = 0;
                break;
            }
            s.b8h = (signed char)in[3] >= 0;
            s.b6l = 0;
        } else {
            s.b5 = 3;
            s.b6h = 4;
            s.b4 = 0;
            s.b6l = 0;
            s.b8h = 0;
        }
    }
    if (mode < 0x1a)
        s.b8l = 1;
    else
        s.b8l = 0;
    pkt[0] = 0x82;
    pkt[1] = 2;
    pkt[2] = 0xd;
    pkt[4] = s.b4 << 5;
    pkt[5] = s.b5 << 6;
    pkt[6] = (s.b6h << 4) | (s.b6l << 2);
    pkt[8] = (s.b8h << 6) | s.b8l;
    pkt[3] = 0x82 + 2 + 0xd;
    for (i = 0, sum = pkt[3]; i < 5; i++)
        sum += pkt[4 + i];
    pkt[3] = -sum;
}
