/* FUN_a0141e74 (leon2m 0xa0141e74-0xa0141edc, 104 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns byte +5 of 0x12-byte entry 0, 1, 2 or 3 of DAT_a802e116 for c = 0x51, 0x61, 0x71 or 0x81, otherwise 8.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a0141e0c and FUN_a0141edc.
 */
struct E12 { unsigned char p0[5]; unsigned char b5; unsigned char p6[0xc]; };
extern struct E12 DAT_a802e116[];

unsigned char FUN_a0141e74(unsigned char c)
{
    switch (c) {
    case 0x51:
        return DAT_a802e116[0].b5;
    case 0x61:
        return DAT_a802e116[1].b5;
    case 0x71:
        return DAT_a802e116[2].b5;
    case 0x81:
        return DAT_a802e116[3].b5;
    default:
        return 8;
    }
}
