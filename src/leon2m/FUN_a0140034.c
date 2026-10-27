/* FUN_a0140034 (leon2m 0xa0140034-0xa0140058, 36 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the halfword at +0xa of 0x24-byte entry i of the table DAT_001a5a16. Nothing in the image refers to it:
 * no call, branch, sethi/or constant or address word. It lies between FUN_a013ffb0 and FUN_a0140058.
 */
struct Mode { unsigned char p0[0xa]; unsigned short wa; unsigned char pc[0x24 - 0xc]; };
extern const struct Mode DAT_001a5a16[];

unsigned short FUN_a0140034(unsigned char i)
{
    return DAT_001a5a16[i].wa;
}
