/* leon2m FUN_a012af40 @ 0xa012af40-0xa012b078 (-mcpu=v8 -O3 -g).
 * n = nibble i of byte +0x2c of DAT_a802e1a0. When n <= 2, the 2-bit field at bit i * 8 + n * 2 of the halfword at
 * +0x2f is replaced by v; otherwise nibble i of byte +0x31 is replaced by v. Then byte 0 of the 22-byte row i of
 * DAT_a802d8ae is set to v, the row is copied to a local and FUN_a0137a68(i, copy) is called.
 * Source form: the row copy is a memcpy (GCC expands it inline), which places the row address computation
 * after the first halfword load as in the firmware.
 */
struct __attribute__((packed, aligned(4))) Settings {
    unsigned char p00[0x2c];
    unsigned char b2c;
    unsigned short h2d:16;
    unsigned short h2f:16;
    unsigned char b31;
    unsigned char rest[0x50 - 0x32];
};
struct Row { unsigned char b0, b1; unsigned short h[10]; };
extern struct Settings DAT_a802e1a0;
extern struct Row DAT_a802d8ae[];
extern void *memcpy(void *, const void *, unsigned int);
extern void FUN_a0137a68(unsigned char, unsigned char *);

void FUN_a012af40(unsigned char i, unsigned char v)
{
    struct Row r;
    unsigned char n = (DAT_a802e1a0.b2c >> (i * 4)) & 0xf;

    if (n <= 2)
        DAT_a802e1a0.h2f = (DAT_a802e1a0.h2f & ~((3 << (i * 8)) << (n * 2))) | ((v << (i * 8)) << (n * 2));
    else
        DAT_a802e1a0.b31 = (DAT_a802e1a0.b31 & ~(0xf << (i * 4))) | (v << (i * 4));
    DAT_a802d8ae[i].b0 = v;
    memcpy(&r, &DAT_a802d8ae[i], sizeof r);
    FUN_a0137a68(i, (unsigned char *)&r);
}
