/* FUN_a00d3f80 (leon2m 0xa00d3f80-0xa00d4084, 260 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * The FUN_a00d3e28 conversion with the knee fixed at 272 when bit 11 of the word at DAT_a802d290 + 0xa8 is set and
 * the byte at DAT_a802d290 + 0x181 is 7, otherwise at 879 (the FUN_a00d3ee0 conversion). Nothing in the image
 * refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a00d3ee0 and FUN_a00d4084.
 * Source form: two static conversion helpers with the constants written in (conv879 is the FUN_a00d3ee0 body), each
 * inlined.
 */
struct R290 { unsigned char p0[0xa8]; unsigned int wa8; unsigned char pac[0x181 - 0xac]; unsigned char b181; };
extern struct R290 DAT_a802d290;
static unsigned char conv879(unsigned char c)
{
    unsigned short v;
    if (c > 0x45)
        v = (unsigned int)((c - 70) * (0x3ff - 879) + 15) / 30 + 879;
    else
        v = (unsigned int)(c * (879 - 126) + 35) / 70 + 126;
    return (v - 126) * 100 / 897;
}
static unsigned char conv272(unsigned char c)
{
    unsigned short v;
    if (c > 0x45)
        v = (unsigned int)((c - 70) * (0x3ff - 272) + 15) / 30 + 272;
    else
        v = (unsigned int)(c * (272 - 126) + 35) / 70 + 126;
    return (v - 126) * 100 / 897;
}
unsigned char FUN_a00d3f80(unsigned char c)
{
    if ((DAT_a802d290.wa8 & 0x800) && DAT_a802d290.b181 == 7)
        return conv272(c);
    return conv879(c);
}
