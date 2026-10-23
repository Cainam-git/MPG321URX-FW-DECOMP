/* leon2m FUN_a012b078 @ 0xa012b078-0xa012b164 (59 words).
 * Takes index i and a byte v. n = nibble i of byte +0x2c of the settings record at 0xA802E1A0; in the 16-bit
 * field at +0x2d..+0x2e the two bits at position i * 8 + n * 2 are cleared and v shifted to that position is
 * ORed in (v is not masked). Then byte 1 of the 22-byte row
 * i of DAT_a802d8ae is set to v and a copy of that row is passed to FUN_a0137a68(i, &copy).
 * Called by FUN_a014a4d8.
 * Source form: the record is the packed, 4-byte aligned layout used by FUN_a0145c5c (16-bit fields as
 * 'unsigned short x:16' bit-fields); the row copy is a plain structure assignment (halfword alignment).
 */
struct __attribute__((packed, aligned(4))) Settings {
    unsigned char p00[0x2c];
    unsigned char b2c;
    unsigned short h2d:16;
    unsigned char rest[0x50 - 0x2f];
};
struct Row { unsigned char b0, b1; unsigned short h[10]; };
extern struct Settings DAT_a802e1a0;
extern struct Row DAT_a802d8ae[];
extern void FUN_a0137a68(unsigned char, unsigned char *);

void FUN_a012b078(unsigned char i, unsigned char v)
{
    struct Row r;
    unsigned char n = (DAT_a802e1a0.b2c >> (i * 4)) & 0xf;

    DAT_a802e1a0.h2d = (DAT_a802e1a0.h2d & ~((3 << (i * 8)) << (n * 2))) | ((v << (i * 8)) << (n * 2));
    DAT_a802d8ae[i].b1 = v;
    r = DAT_a802d8ae[i];
    FUN_a0137a68(i, (unsigned char *)&r);
}
