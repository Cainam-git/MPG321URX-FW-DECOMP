/* FUN_a0142140 (leon2m 0xa0142140-0xa0142168, 40 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns bit 6 of the halfword at +0 of 0x12-byte entry i of the array DAT_a802e116. Nothing in the image refers
 * to it: no call, branch, sethi/or constant or address word. It lies between FUN_a0142110 and FUN_a0142168.
 */
struct E12 { unsigned short h0; unsigned char p2[0x10]; };
extern struct E12 DAT_a802e116[];

unsigned int FUN_a0142140(unsigned char i)
{
    return (DAT_a802e116[i].h0 >> 6) & 1;
}
