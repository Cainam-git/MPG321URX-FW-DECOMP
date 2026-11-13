/* HDMI20RX2PacketSwitch  (FUN_a00a8708)
 *
 * Write one packet-forwarding selection of an HDMI 2.0 receiver.
 *   port: HDMI 2.0 receiver
 *   sel: selection 0..2
 *   data: 4 bytes
 * Name basis: proven - original name printed ('HDMI20RX2PacketSwitch WRONG selection!!!'); writes through
 *   SC_MaskSetByte
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a8708, flags -mcpu=v8 -Os -g.
 * Source form: a switch with the four calls written out in each case; GCC shares the last two calls.
 */
extern void SC_MaskSetByte(unsigned char id, unsigned char n, unsigned short off, unsigned int mask, unsigned int val);
extern int dbg_printf(const char *, ...);

/*
 * Write one packet-forwarding selection of an HDMI 2.0 receiver. The four bytes in `data` go through
 * SC_MaskSetByte (register list 0, block `port`) to four consecutive registers with the masks 0xE0, 0xFF,
 * 0xFF, 0x3F:
 *   selection 0: registers 0xAB..0xAE
 *   selection 1: registers 0xE8..0xEB
 *   selection 2: registers 0xEC..0xEF
 * Any other selection only prints the "WRONG selection" text.
 *   port: HDMI 2.0 receiver
 *   sel:  selection 0..2
 *   data: 4 bytes
 */
void HDMI20RX2PacketSwitch(unsigned char port, unsigned char sel, unsigned char *data)
{
    switch (sel) {
    case 0:
        SC_MaskSetByte(0, port, 0xab, 0xe0, data[0]);
        SC_MaskSetByte(0, port, 0xac, 0xff, data[1]);
        SC_MaskSetByte(0, port, 0xad, 0xff, data[2]);
        SC_MaskSetByte(0, port, 0xae, 0x3f, data[3]);
        break;
    case 1:
        SC_MaskSetByte(0, port, 0xe8, 0xe0, data[0]);
        SC_MaskSetByte(0, port, 0xe9, 0xff, data[1]);
        SC_MaskSetByte(0, port, 0xea, 0xff, data[2]);
        SC_MaskSetByte(0, port, 0xeb, 0x3f, data[3]);
        break;
    case 2:
        SC_MaskSetByte(0, port, 0xec, 0xe0, data[0]);
        SC_MaskSetByte(0, port, 0xed, 0xff, data[1]);
        SC_MaskSetByte(0, port, 0xee, 0xff, data[2]);
        SC_MaskSetByte(0, port, 0xef, 0x3f, data[3]);
        break;
    default:
        dbg_printf("HDMI20RX2PacketSwitch WRONG selection!!!");
        break;
    }
}
