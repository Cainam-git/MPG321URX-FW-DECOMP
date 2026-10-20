/* FUN_a007aac4 (leon2s 0xa007aac4-0xa007ab94, 208 bytes), flags -mcpu=v8 -Os -g.
 * Copies the bytes a, b, c, d into a 4-byte stack buffer. For idx > 3 calls FUN_a00a7488(port, n, 0xffff00ff,
 * x << 8) four times with (n, x) = (0x2064, a), (0x2464, b), (0x2864, c), (0x3064, d); for idx 0..3 once with
 * n from the halfword table DAT_a00b3afc and x from the buffer, both at index idx.
 * Source form: the idx > 3 arm is written first.
 */
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);
extern const unsigned short DAT_a00b3afc[];

void FUN_a007aac4(unsigned char port, unsigned char idx, unsigned char a, unsigned char b, unsigned char c,
                  unsigned char d)
{
    unsigned char buf[4];

    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    if (idx > 3) {
        FUN_a00a7488(port, 0x2064, 0xffff00ff, a << 8);
        FUN_a00a7488(port, 0x2464, 0xffff00ff, b << 8);
        FUN_a00a7488(port, 0x2864, 0xffff00ff, c << 8);
        FUN_a00a7488(port, 0x3064, 0xffff00ff, d << 8);
    } else {
        FUN_a00a7488(port, DAT_a00b3afc[idx], 0xffff00ff, buf[idx] << 8);
    }
}
