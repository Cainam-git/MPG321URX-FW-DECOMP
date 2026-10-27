/* FUN_a0142110 (leon2m 0xa0142110-0xa0142140, 48 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns 1 when the top four bits (bits 12..15) of the halfword at +0 of 0x12-byte entry i of DAT_a802e116 equal
 * 5, otherwise 0. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies
 * between FUN_a01420e4 and FUN_a0142140.
 */
struct E12 { unsigned short h0; unsigned char p2[0x10]; };
extern struct E12 DAT_a802e116[];

unsigned int FUN_a0142110(unsigned char i)
{
    return (DAT_a802e116[i].h0 >> 12) == 5;
}
