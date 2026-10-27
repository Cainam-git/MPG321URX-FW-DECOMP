/* FUN_a013ffb0 (leon2m 0xa013ffb0-0xa0140034, 132 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the index of the first 0x24-byte entry of DAT_001a5a16 whose halfword +0x22 equals k, scanning until an
 * entry whose halfword +2 is 0xffff (that index when none matches). Nothing in the image refers to it: no call,
 * branch, sethi/or constant or address word. It lies between FUN_a013fe2c and FUN_a0140034.
 */
struct Mode { unsigned char p0[2]; unsigned short w2; unsigned char p4[0x22 - 4]; unsigned short w22; };
extern const struct Mode DAT_001a5a16[];

unsigned char FUN_a013ffb0(unsigned short k)
{
    unsigned char i;

    for (i = 0; DAT_001a5a16[i].w2 != 0xffff; i++)
        if (DAT_001a5a16[i].w22 == k)
            break;
    return i;
}
