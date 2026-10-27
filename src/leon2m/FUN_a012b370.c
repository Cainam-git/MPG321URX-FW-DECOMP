/* FUN_a012b370 (leon2m 0xa012b370-0xa012b394, 36 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the halfword at +0xe of 0x12-byte entry i of the array DAT_a802e116. Nothing in the image refers to it:
 * no call, branch, sethi/or constant or address word. It lies between FUN_a012b354 and FUN_a012b394.
 */
struct E12 { unsigned char p0[0xe]; unsigned short we; unsigned char p10[2]; };
extern struct E12 DAT_a802e116[];

unsigned short FUN_a012b370(unsigned char i)
{
    return DAT_a802e116[i].we;
}
