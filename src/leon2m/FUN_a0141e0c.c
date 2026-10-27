/* FUN_a0141e0c (leon2m 0xa0141e0c-0xa0141e74, 104 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the halfword at +0xe of 0x12-byte entry 0, 1, 2 or 3 of DAT_a802e116 for c = 0x51, 0x61, 0x71 or 0x81,
 * otherwise 0. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies
 * between FUN_a0141d50 and FUN_a0141e74.
 */
struct E12 { unsigned char p0[0xe]; unsigned short we; unsigned char p10[2]; };
extern struct E12 DAT_a802e116[];

unsigned short FUN_a0141e0c(unsigned char c)
{
    switch (c) {
    case 0x51:
        return DAT_a802e116[0].we;
    case 0x61:
        return DAT_a802e116[1].we;
    case 0x71:
        return DAT_a802e116[2].we;
    case 0x81:
        return DAT_a802e116[3].we;
    default:
        return 0;
    }
}
