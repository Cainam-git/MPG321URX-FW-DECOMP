/* leon2m FUN_a012b260 @ 0xa012b260-0xa012b328 (50 words), flags -mcpu=v8 -O3 -g.
 * Called by FUN_a014a768. n = nibble i of the settings byte 0xa802e1a0+0x2c; the field of bit (4 i + n) of byte
 * +0x33 is set to v ((b & ~(1 << 4i << n)) | (v << 4i << n)). Byte +6 of the 22-byte row DAT_a802d8ae[i] = v, then
 * the row is copied to a local (halfword copy) and passed with i to FUN_a013797c.
 * Source form: as FUN_a012b078 (same row copy); the settings are accessed through a struct pointer s.
 */
struct Settings {
    unsigned char p00[0x2c];
    unsigned char b2c;
    unsigned char p2d[5];
    unsigned char b32;
    unsigned char b33;
    unsigned char rest[0x50 - 0x34];
};
struct Row { unsigned short h0, h2, h4; unsigned char b6, b7; unsigned short h8[7]; };
extern struct Settings DAT_a802e1a0;
extern struct Row DAT_a802d8ae[];
extern void FUN_a013797c(unsigned char, unsigned char *);

void FUN_a012b260(unsigned char i, unsigned char v)
{
    struct Row r;
    struct Settings *s = &DAT_a802e1a0;
    unsigned char n = (s->b2c >> (i * 4)) & 0xf;

    s->b33 = (s->b33 & ~((1 << (i * 4)) << n)) | ((v << (i * 4)) << n);
    DAT_a802d8ae[i].b6 = v;
    r = DAT_a802d8ae[i];
    FUN_a013797c(i, (unsigned char *)&r);
}
