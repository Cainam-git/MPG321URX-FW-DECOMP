/* FUN_a006e0e4 (leon2s 0xa006e0e4-0xa006e2c4, 480 bytes), flags -mcpu=v8 -Os -g.
 * Called by FUN_a006e2c4 with the status record st, the port and the 400-byte port record rec. Updates the flag
 * byte st[0xd]: bit 1 = rec[0x2d] != 0; bit 2 = bit 0 or bit 2 of rec[6]; bit 3 = bit 1, bit 4 = bit 4 and bit 7 =
 * bit 3 of rec[6]; bit 6 = bit (p + 2) of DAT_a8078c35; bit 5 = bit (p + 2) of DAT_a8078c5b (p = (u8)port).
 * Halfword +0xe: bit 14 = FUN_a00a2978(p) != 0, bit 15 = FUN_a00a2994(p) != 0, bit 13 = FUN_a00a29b0(port) != 0.
 * Halfword +0x12 bit 6: when st[0] is 5, the low byte of FUN_a00a2230(0, p) != 0; otherwise FUN_a00a2230(1, p)
 * is called and the bit is cleared. Each bit is written with its own if/else (or / and-not).
 * Source form: p is assigned just before the bit-7 test; the last call takes 'port & 0xff' (a fresh mask).
 */
extern unsigned char DAT_a8078c35;
extern unsigned char DAT_a8078c5b;
extern unsigned char FUN_a00a2978(unsigned int);
extern unsigned char FUN_a00a2994(unsigned int);
extern unsigned char FUN_a00a29b0(unsigned char port);
extern unsigned int FUN_a00a2230(unsigned char reset, unsigned int param_2);

void FUN_a006e0e4(unsigned char *st, unsigned int port, unsigned char *rec)
{
    unsigned char p;

    if (rec[0x2d])
        st[0xd] |= 2;
    else
        st[0xd] &= ~2;
    if ((rec[6] & 1) || (rec[6] & 4))
        st[0xd] |= 4;
    else
        st[0xd] &= ~4;
    if (rec[6] & 2)
        st[0xd] |= 8;
    else
        st[0xd] &= ~8;
    if (rec[6] & 0x10)
        st[0xd] |= 0x10;
    else
        st[0xd] &= ~0x10;
    p = port;
    if (rec[6] & 8)
        st[0xd] |= 0x80;
    else
        st[0xd] &= 0x7f;
    if ((DAT_a8078c35 >> (p + 2)) & 1)
        st[0xd] |= 0x40;
    else
        st[0xd] &= ~0x40;
    if ((DAT_a8078c5b >> (p + 2)) & 1)
        st[0xd] |= 0x20;
    else
        st[0xd] &= ~0x20;
    if (FUN_a00a2978(p))
        *(unsigned short *)(st + 0xe) |= 0x4000;
    else
        *(unsigned short *)(st + 0xe) &= ~0x4000;
    if (FUN_a00a2994(p))
        *(unsigned short *)(st + 0xe) |= 0x8000;
    else
        *(unsigned short *)(st + 0xe) &= ~0x8000;
    if (st[0] != 5) {
        FUN_a00a2230(1, p);
        *(unsigned short *)(st + 0x12) &= ~0x40;
    } else if ((unsigned char)FUN_a00a2230(0, p))
        *(unsigned short *)(st + 0x12) |= 0x40;
    else
        *(unsigned short *)(st + 0x12) &= ~0x40;
    if (FUN_a00a29b0(port & 0xff))
        *(unsigned short *)(st + 0xe) |= 0x2000;
    else
        *(unsigned short *)(st + 0xe) &= ~0x2000;
}
