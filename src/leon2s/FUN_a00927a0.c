/* leon2s FUN_a00927a0 @ 0xa00927a0-0xa0092890 (60 words), flags -mcpu=v8 -Os -g.
 * Code facts: port, on, force (u8). on != 0: tail FUN_a00a80cc(port, 3, 0, 3, 1). force != 0:
 * FUN_a00a8054(port, 3, 0xbe, 0xff); FUN_a00a8054(port, 3, 0xbf, 0xff); tail
 * FUN_a00a80cc(port, 3, 0, 3, 0). Else a = FUN_a00a7fd8(port, 3, 0xbe), b = FUN_a00a7fd8(port,
 * 3, 0xbf); both 0xff: tail FUN_a00a80cc(port, 3, 0, 3, 0); otherwise tail
 * FUN_a00a8054(port, 3, 0, FUN_a00a7fd8(port, 3, 0)). void.
 * Prototypes: FUN_a00a7fd8 takes 3 args (u8 (u8, u8, u16)), FUN_a00a80cc 5. Aids: none.
 */
extern unsigned char FUN_a00a7fd8(unsigned char, unsigned char, unsigned short);
extern void FUN_a00a8054(unsigned char, unsigned char, unsigned short, unsigned char);
extern void FUN_a00a80cc(unsigned char, unsigned char, unsigned short, unsigned char, unsigned char);

void FUN_a00927a0(unsigned char port, unsigned char on, unsigned char force)
{
    unsigned char a, b;

    if (on) {
        FUN_a00a80cc(port, 3, 0, 3, 1);
        return;
    }
    if (force) {
        FUN_a00a8054(port, 3, 0xbe, 0xff);
        FUN_a00a8054(port, 3, 0xbf, 0xff);
        FUN_a00a80cc(port, 3, 0, 3, 0);
        return;
    }
    a = FUN_a00a7fd8(port, 3, 0xbe);
    b = FUN_a00a7fd8(port, 3, 0xbf);
    if (a == 0xff && b == 0xff) {
        FUN_a00a80cc(port, 3, 0, 3, 0);
        return;
    }
    FUN_a00a8054(port, 3, 0, FUN_a00a7fd8(port, 3, 0));
}
