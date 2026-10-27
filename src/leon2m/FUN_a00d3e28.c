/* FUN_a00d3e28 (leon2m 0xa00d3e28-0xa00d3ee0, 184 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Converts c with d = the halfword DAT_a802d46a: v = (c - 70) * (0x3ff - d) + 15) / 30 + d for c above 0x45,
 * otherwise (c * (d - 126) + 35) / 70 + 126 (unsigned divisions, v a halfword); returns (v - 126) * 100 / 897
 * (signed) as a byte. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It
 * lies between FUN_a00d3dbc and FUN_a00d3ee0.
 */
extern unsigned short DAT_a802d46a;

unsigned char FUN_a00d3e28(unsigned char c)
{
    unsigned short v;

    if (c > 0x45)
        v = (unsigned int)((c - 70) * (0x3ff - DAT_a802d46a) + 15) / 30 + DAT_a802d46a;
    else
        v = (unsigned int)(c * (DAT_a802d46a - 126) + 35) / 70 + 126;
    return (v - 126) * 100 / 897;
}
