/* leon2s FUN_a0092cec @ 0xa0092cec-0xa0092db8 (204 bytes, 51 words)
 * Flags: -mcpu=v8 -Os -g.
 * void (u8 port, u8 *p). It is the page-3 twin of FUN_a0092944: it writes p[0..0xd] into registers
 * 3..0x10 of page 3 through FUN_a00a8054(u8 port, u8 page, u16 reg, u8 val), reg = offset + 3.
 * There are three u8-counter loops of lengths 3, 7 and 4, and one counter variable (%l0) serves all three.
 * The firmware sets no %i0 (void) and masks the port with 'and 0xff' (u8).
 */
extern void FUN_a00a8054(unsigned char, unsigned char, unsigned short, unsigned char);

void FUN_a0092cec(unsigned char port, unsigned char *p)
{
    unsigned char i;

    for (i = 0; i < 3; i++)
        FUN_a00a8054(port, 3, i + 3, p[i]);
    for (i = 0; i < 7; i++)
        FUN_a00a8054(port, 3, i + 6, p[i + 3]);
    for (i = 0; i < 4; i++)
        FUN_a00a8054(port, 3, i + 0xd, p[i + 0xa]);
}
