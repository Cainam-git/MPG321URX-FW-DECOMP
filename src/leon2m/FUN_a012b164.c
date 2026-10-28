/* leon2m FUN_a012b164 @ 0xa012b164-0xa012b22c (50 words), flags -mcpu=v8 -O3 -g.
 * Called by FUN_a014a654. n = nibble i of the settings byte 0xa802e1a0+0x2c; the field of bit (4 i + n) of byte
 * +0x32 is set to v ((b & ~(1 << 4i << n)) | (v << 4i << n)). Byte +7 of the 22-byte row DAT_a802d8ae[i] = v, then
 * the row is copied to a local (halfword copy) and passed with i to FUN_a0137a68.
 * Source form: as FUN_a012b078 (same row copy); the settings are accessed through a struct pointer s.
 */
struct Settings {
    unsigned char p00[0x2c];
    unsigned char b2c;
    unsigned char p2d[5];
    unsigned char b32;
    unsigned char rest[0x50 - 0x33];
};
struct Row { unsigned short h0, h2, h4; unsigned char b6, b7; unsigned short h8[7]; };
extern struct Settings DAT_a802e1a0;
extern struct Row DAT_a802d8ae[];
extern void FUN_a0137a68(unsigned char, unsigned char *);

void FUN_a012b164(unsigned char i, unsigned char v)
{
    struct Row r;
    struct Settings *s = &DAT_a802e1a0;
    unsigned char n = (s->b2c >> (i * 4)) & 0xf;

    s->b32 = (s->b32 & ~((1 << (i * 4)) << n)) | ((v << (i * 4)) << n);
    DAT_a802d8ae[i].b7 = v;
    r = DAT_a802d8ae[i];
    FUN_a0137a68(i, (unsigned char *)&r);
}
