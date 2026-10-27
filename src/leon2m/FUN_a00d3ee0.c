/* FUN_a00d3ee0 (leon2m 0xa00d3ee0-0xa00d3f80, 160 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * The FUN_a00d3e28 conversion with the knee value fixed at 879: v = ((c - 70) * 144 + 15) / 30 + 879 for c above
 * 0x45, otherwise (c * 753 + 35) / 70 + 126; returns (v - 126) * 100 / 897 as a byte. Nothing in the image refers
 * to it: no call, branch, sethi/or constant or address word. It lies between FUN_a00d3e28 and FUN_a00d3f80. Source
 * form: the FUN_a00d3e28 expressions with the constant written in (GCC folds them to c * 144 - 10065 and c * 753 +
 * 35).
 */
unsigned char FUN_a00d3ee0(unsigned char c)
{
    unsigned short v;

    if (c > 0x45)
        v = (unsigned int)((c - 70) * (0x3ff - 879) + 15) / 30 + 879;
    else
        v = (unsigned int)(c * (879 - 126) + 35) / 70 + 126;
    return (v - 126) * 100 / 897;
}
