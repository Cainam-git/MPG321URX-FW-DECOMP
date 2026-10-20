/* leon2s FUN_a00943d0 @ 0xa00943d0-0xa00944e0 (68 words), flags -mcpu=v8 -Os -g.
 * Code facts: save/restore around a reset pulse. save[5] bytes at %fp-16: save[0] =
 * FUN_a00a82e4(port, 0x80); save[1..4] = FUN_a00a7fd8(port, 0, 0x13e), (port, 0, 0x13f),
 * (port, 2, 0xbd), (port, 2, 0). FUN_a00a80cc(port, 0, 5, 1, 1); FUN_a00b1794(1) (delay);
 * FUN_a00a80cc(port, 0, 5, 1, 0); then write back: FUN_a00a8210(port, 0x80, 0, save[0]);
 * FUN_a00a8054(port, 0, 0x13e, save[1]), (port, 0, 0x13f, save[2]), (port, 2, 0xbd, save[3]),
 * (port, 2, 0, save[4]). void.
 * Fix vs the autoc draft (83.82): BEHAVIOUR: the saved values are the READ results (the draft
 * wrote the port number back five times); a byte array on the stack holds them. Aids: none.
 */
extern unsigned char FUN_a00a7fd8(unsigned char, unsigned char, unsigned short);
extern void FUN_a00a8054(unsigned char, unsigned char, unsigned short, unsigned char);
extern void FUN_a00a80cc(unsigned char, unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a00a8210(unsigned char, unsigned short, unsigned char, unsigned char);
extern unsigned char FUN_a00a82e4(unsigned char, unsigned short);
extern void FUN_a00b1794(unsigned int);

void FUN_a00943d0(unsigned char port)
{
    unsigned char save[5];

    save[0] = FUN_a00a82e4(port, 0x80);
    save[1] = FUN_a00a7fd8(port, 0, 0x13e);
    save[2] = FUN_a00a7fd8(port, 0, 0x13f);
    save[3] = FUN_a00a7fd8(port, 2, 0xbd);
    save[4] = FUN_a00a7fd8(port, 2, 0);
    FUN_a00a80cc(port, 0, 5, 1, 1);
    FUN_a00b1794(1);
    FUN_a00a80cc(port, 0, 5, 1, 0);
    FUN_a00a8210(port, 0x80, 0, save[0]);
    FUN_a00a8054(port, 0, 0x13e, save[1]);
    FUN_a00a8054(port, 0, 0x13f, save[2]);
    FUN_a00a8054(port, 2, 0xbd, save[3]);
    FUN_a00a8054(port, 2, 0, save[4]);
}
