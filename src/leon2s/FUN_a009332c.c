/* leon2s FUN_a009332c @ 0xa009332c-0xa00934c0 (-mcpu=v8 -Os -g).
 * Parameters (src, dst). Through FUN_a00a8054(dst, 0, reg, value): 0x84, 1 and 10 to 0x180..0x182; the bytes read
 * by FUN_a00a6bb8(src, 0x6b..0x6e) to 0x11e..0x121; from v = FUN_a00a6bb8(src, 0x6f) the byte
 * (v << 4) | ((v >> 3) & 0xe) | (v >> 7) to 0x122. Then FUN_a00a80cc(dst, 0, 0x13e, 0x30, 0); with
 * v = FUN_a00a6bb8(src, 0x60) & 0xe0, for i = 0..8: FUN_a00a6c00(src, 0x60, v + i), r = FUN_a00a6bb8(src, 0x62)
 * written to 0x184 + i and added to a byte sum that starts at 0x8f; the negated sum goes to 0x183; ends with
 * FUN_a00a80cc(dst, 0, 0x13e, 0x30, 1).
 * Source form: FUN_a00a6bb8 returns a value masked with 0xff (unsigned char, as in its other matched users);
 * the packed byte is built in three statements on the u8 variable i.
 */
extern unsigned char FUN_a00a6bb8(unsigned char, unsigned short);
extern void FUN_a00a6c00(unsigned char, unsigned short, unsigned char);
extern void FUN_a00a8054(unsigned int, unsigned int, unsigned short, unsigned char);
extern void FUN_a00a80cc(unsigned int, unsigned int, unsigned short, unsigned int, unsigned int);

void FUN_a009332c(unsigned int src, unsigned char dst)
{
    unsigned char i;
    unsigned char v;
    unsigned char r;
    unsigned char sum;

    FUN_a00a8054(dst, 0, 0x180, 0x84);
    FUN_a00a8054(dst, 0, 0x181, 1);
    FUN_a00a8054(dst, 0, 0x182, 10);
    sum = 0x8f;
    for (i = 0; i < 4; i++)
        FUN_a00a8054(dst, 0, i + 0x11e, FUN_a00a6bb8(src, i + 0x6b));
    r = FUN_a00a6bb8(src, 0x6f);
    v = r;
    i = r << 4;
    i |= (v >> 3) & 0xe;
    i |= v >> 7;
    FUN_a00a8054(dst, 0, 0x122, i);
    FUN_a00a80cc(dst, 0, 0x13e, 0x30, 0);
    v = FUN_a00a6bb8(src, 0x60) & 0xe0;
    for (i = 0; i <= 8; i++) {
        FUN_a00a6c00(src, 0x60, v + i);
        r = FUN_a00a6bb8(src, 0x62);
        FUN_a00a8054(dst, 0, i + 0x184, r);
        sum += r;
    }
    sum = -sum;
    FUN_a00a8054(dst, 0, 0x183, sum);
    FUN_a00a80cc(dst, 0, 0x13e, 0x30, 1);
}
