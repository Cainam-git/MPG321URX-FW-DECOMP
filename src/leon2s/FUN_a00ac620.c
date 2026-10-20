/* leon2s FUN_a00ac620 @ 0xa00ac620-0xa00ac66c (19 words), flags -mcpu=v8 -Os -g.
 * Returns the 24-bit value (r(0x3d2) << 16) + (r(0x3d1) << 8) + r(0x3d0) with r(x) = FUN_a00a6bb8(ch, x)
 * & 0xff (three byte registers, high byte first). The bytes are joined with + (firmware add), as in
 * FUN_a00af320.
 */
extern unsigned int FUN_a00a6bb8(unsigned char, unsigned short);

unsigned int FUN_a00ac620(unsigned char ch)
{
    unsigned int r;

    r = (FUN_a00a6bb8(ch, 0x3d2) & 0xff) << 16;
    r += (FUN_a00a6bb8(ch, 0x3d1) & 0xff) << 8;
    return r + (FUN_a00a6bb8(ch, 0x3d0) & 0xff);
}
