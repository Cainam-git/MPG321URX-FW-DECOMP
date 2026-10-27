/* FUN_a012f3b4 (leon2m 0xa012f3b4-0xa012f3ec, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns bits 12..15 of the first word of 0x78-byte entry c of DAT_a802df30 when c is at most 3, otherwise 0xff.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a012f31c and FUN_a012f3ec. Source form: an int result set to -1 and returned as unsigned char.
 */
struct Chan { unsigned int state:4, f24:4, step:4, f16:4, port:4, f8:4, f4:4, f1:3, b0:1; unsigned char p04[0x74]; };
extern struct Chan DAT_a802df30[4];
unsigned char FUN_a012f3b4(unsigned char c)
{
    unsigned char r = 0xff;
    if (c <= 3)
        r = DAT_a802df30[c].port;
    return r;
}
