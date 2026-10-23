/* FUN_a00974ec (leon2s 0xa00974ec-0xa0097680, 404 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Computes a byte r (initially 0) from two register blocks of the 0x34-byte port record ARR_a807db00[port]
 * (pointers at +4 and +0x14) and stores it in byte +6 of the 400-byte port record ARR_a807d7e0[port].
 * Block +4: when the low byte of register +0x60 is 0x83 and the low 24 bits of +0x64 are 0x1a: r = 1 when byte 1
 * of +0x60 is 1 and bit 8 of +0x68 is set; for byte 1 of +0x60 equal to 2 or 3: r = 1 when bit 8 of +0x68 is
 * set, then r |= 0x10 when bit 5 of +0x6c is clear, otherwise r |= 2 and bit 4 of r = !(bit 13 of +0x68).
 * Block +0x14: when the low byte of +0x50 is 0x7f, bits 24..29 are 4 and register +0x54 reads 0x01000100,
 * r = 4 for bits 16..17 of +0x58 equal to 1 and r = 8 for 3. The register blocks are volatile (hardware).
 * Source form: the bit-5 test of +0x6c with the set arm first; bit 13 tested as a byte of (+0x68 >> 8).
 */
struct Port34 {
    unsigned int w0;
    volatile unsigned int *r4;
    unsigned char pad8[0xc];
    volatile unsigned int *r14;
    unsigned char rest[0x34 - 0x18];
};
extern struct Port34 ARR_a807db00[];
extern unsigned char ARR_a807d7e0[];

void FUN_a00974ec(unsigned char port)
{
    unsigned char r = 0;
    unsigned int w;
    unsigned int b;
    unsigned int x;

    w = ARR_a807db00[port].r4[0x60 / 4];
    if ((w & 0xff) == 0x83 && (ARR_a807db00[port].r4[0x64 / 4] & 0xffffff) == 0x1a) {
        b = w >> 8;
        if ((b & 0xff) == 1 && (ARR_a807db00[port].r4[0x68 / 4] & 0x100))
            r = 1;
        if ((unsigned char)(b - 2) <= 1) {
            if (ARR_a807db00[port].r4[0x68 / 4] & 0x100)
                r = 1;
            if (ARR_a807db00[port].r4[0x6c / 4] & 0x20) {
                r |= 2;
                if ((unsigned char)(ARR_a807db00[port].r4[0x68 / 4] >> 8) & 0x20)
                    r &= ~0x10;
                else
                    r |= 0x10;
            } else
                r |= 0x10;
        }
    }
    w = ARR_a807db00[port].r14[0x50 / 4];
    if ((w & 0xff) == 0x7f && ((w >> 24) & 0x3f) == 4) {
        w = ARR_a807db00[port].r14[0x54 / 4];
        if ((w & 0xff) == 0 && ((w >> 8) & 0xff) == 1 && ((w >> 16) & 0xff) == 0 && (w >> 24) == 1) {
            w = ARR_a807db00[port].r14[0x58 / 4];
            x = (w >> 16) & 3;
            if (x == 1)
                r = 4;
            else if (x == 3)
                r = 8;
        }
    }
    ARR_a807d7e0[port * 400 + 6] = r;
}
