/* FUN_a006e820 (leon2s 0xa006e820-0xa006e990, 368 bytes), flags -mcpu=v8 -Os -g.
 * Updates the flag byte +0xd of the status record st for port. st[0] <= 2: for st[0] == 2 bit 0 = (low byte of
 * FUN_a00ad27c(port) == 1); then all bits but bit 0 are cleared. st[0] > 2: bit 0 set; bit 1 = FUN_a00ad784(port)
 * != 0; bit 2 = FUN_a00ad320(port) != 0; bits 3 and 4 = bits 0 and 1 of FUN_a00af524(port); bit 6 of the
 * halfword +0x12 = FUN_a00af690(st, port) != 0; bit 6 = bit (port + 4) of DAT_a8078c35; bit 5 = bit (port + 4)
 * of DAT_a8078c5b. Each bit is written with its own if/else (or / and-not).
 */
extern unsigned char DAT_a8078c35;
extern unsigned char DAT_a8078c5b;
extern unsigned char FUN_a00ad27c(unsigned char port);
extern unsigned char FUN_a00ad784(unsigned int param_1);
extern unsigned char FUN_a00ad320(unsigned char param_1);
extern unsigned char FUN_a00af524(unsigned char port);
extern unsigned char FUN_a00af690(unsigned char *st, unsigned int port);

void FUN_a006e820(unsigned char *st, unsigned char port)
{
    unsigned char v;

    if (st[0] <= 2) {
        if (st[0] == 2) {
            if (FUN_a00ad27c(port) == 1)
                st[0xd] |= 1;
            else
                st[0xd] &= ~1;
        }
        st[0xd] &= 1;
    } else {
        st[0xd] |= 1;
        if (FUN_a00ad784(port))
            st[0xd] |= 2;
        else
            st[0xd] &= ~2;
        if (FUN_a00ad320(port))
            st[0xd] |= 4;
        else
            st[0xd] &= ~4;
        v = FUN_a00af524(port);
        if (v & 1)
            st[0xd] |= 8;
        else
            st[0xd] &= ~8;
        if (v & 2)
            st[0xd] |= 0x10;
        else
            st[0xd] &= ~0x10;
        if (FUN_a00af690(st, port))
            *(unsigned short *)(st + 0x12) |= 0x40;
        else
            *(unsigned short *)(st + 0x12) &= ~0x40;
        if ((DAT_a8078c35 >> (port + 4)) & 1)
            st[0xd] |= 0x40;
        else
            st[0xd] &= ~0x40;
        if ((DAT_a8078c5b >> (port + 4)) & 1)
            st[0xd] |= 0x20;
        else
            st[0xd] &= ~0x20;
    }
}
