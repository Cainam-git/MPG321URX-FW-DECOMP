/* leon2m FUN_a012add8 @ 0xa012add8-0xa012af40 (360 bytes), flags -mcpu=v8 -O3 -g.
 * FUN_a012add8(i, n): nibble i of byte +0x2c of DAT_a802e1a0 is replaced by n. In the 22-byte row i of
 * DAT_a802d8ae: byte 2 = n; byte 0 = the 2-bit field at bit n * 2 of byte i of the halfword at +0x2f when n <= 2,
 * else nibble i of byte +0x31; byte 1 = the 2-bit field at bit n * 2 of byte i of the halfword at +0x2d; byte 7 /
 * byte 6 = bit n of nibble i of byte +0x32 / +0x33. The row is copied to a local and FUN_a0137a68(i, copy) is called.
 * Siblings: FUN_a012af40, FUN_a012b078.
 * Source form: byte 0 is one conditional expression; the row bytes are stored in the order 2, 0, 1, 7, 6.
 */
struct __attribute__((packed, aligned(4))) Settings {
    unsigned char p00[0x2c];
    unsigned char b2c;
    unsigned short h2d:16;
    unsigned short h2f:16;
    unsigned char b31, b32, b33;
    unsigned char rest[0x50 - 0x34];
};
struct Row { unsigned char b0, b1, b2, b3, b4, b5, b6, b7; unsigned short h[7]; };
extern struct Settings DAT_a802e1a0;
extern struct Row DAT_a802d8ae[];
extern void FUN_a0137a68(unsigned char, unsigned char *);

void FUN_a012add8(unsigned char i, unsigned int n)
{
    struct Row r;

    DAT_a802e1a0.b2c = (DAT_a802e1a0.b2c & ~(0xf << (i * 4))) | (n << (i * 4));
    DAT_a802d8ae[i].b2 = n;
    DAT_a802d8ae[i].b0 = n <= 2 ? ((unsigned char)(DAT_a802e1a0.h2f >> (i * 8)) >> (n * 2)) & 3
                                : (DAT_a802e1a0.b31 >> (i * 4)) & 0xf;
    DAT_a802d8ae[i].b1 = ((unsigned char)(DAT_a802e1a0.h2d >> (i * 8)) >> (n * 2)) & 3;
    DAT_a802d8ae[i].b7 = (((DAT_a802e1a0.b32 >> (i * 4)) & 0xf) >> n) & 1;
    DAT_a802d8ae[i].b6 = (((DAT_a802e1a0.b33 >> (i * 4)) & 0xf) >> n) & 1;
    r = DAT_a802d8ae[i];
    FUN_a0137a68(i, (unsigned char *)&r);
}
