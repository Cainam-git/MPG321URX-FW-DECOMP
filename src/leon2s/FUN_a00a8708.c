/* leon2s FUN_a00a8708 @ 0xa00a8708-0xa00a8844, -mcpu=v8 -Os -g.
 * (u8 port, u8 sel, const u8 *d). Writes d[0..3] through SC_MaskSetByte(0, port, off, mask, d[k]) to four
 * consecutive registers with masks 0xe0, 0xff, 0xff, 0x3f: offsets 0xab..0xae for sel 0, 0xe8..0xeb for
 * sel 1, 0xec..0xef for sel 2. Any other sel tail-calls FUN_a0073044 with s_a006c200
 * ("HDMI20RX2PacketSwitch WRONG selection!!!...").
 * Source form: a switch with the four calls written out in each case; GCC shares the last two calls.
 */
extern void SC_MaskSetByte(unsigned char id, unsigned char n, unsigned short off, unsigned int mask, unsigned int val);
extern char s_a006c200[];
extern int FUN_a0073044(const char *, ...);

void FUN_a00a8708(unsigned char port, unsigned char sel, unsigned char *d)
{
    switch (sel) {
    case 0:
        SC_MaskSetByte(0, port, 0xab, 0xe0, d[0]);
        SC_MaskSetByte(0, port, 0xac, 0xff, d[1]);
        SC_MaskSetByte(0, port, 0xad, 0xff, d[2]);
        SC_MaskSetByte(0, port, 0xae, 0x3f, d[3]);
        break;
    case 1:
        SC_MaskSetByte(0, port, 0xe8, 0xe0, d[0]);
        SC_MaskSetByte(0, port, 0xe9, 0xff, d[1]);
        SC_MaskSetByte(0, port, 0xea, 0xff, d[2]);
        SC_MaskSetByte(0, port, 0xeb, 0x3f, d[3]);
        break;
    case 2:
        SC_MaskSetByte(0, port, 0xec, 0xe0, d[0]);
        SC_MaskSetByte(0, port, 0xed, 0xff, d[1]);
        SC_MaskSetByte(0, port, 0xee, 0xff, d[2]);
        SC_MaskSetByte(0, port, 0xef, 0x3f, d[3]);
        break;
    default:
        FUN_a0073044(s_a006c200);
        break;
    }
}
