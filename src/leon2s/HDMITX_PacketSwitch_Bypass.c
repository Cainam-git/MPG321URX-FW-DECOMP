/* HDMITX_PacketSwitch_Bypass (leon2s 0xa00a8cac-0xa00a8ec4, 536 bytes), flags -mcpu=v8 -Os -g.
 * (port, input), void; the range ends with the unreachable ret/restore pair after the final tail call.
 * input 0x31 / 0x41 / 0x51 / 0x61: FUN_a00a89c0(0, input, port, 0, 1, 0), (1, .., 0x27, 0, 1) and
 * (2, .., 0, 0, 0); when any of them returns 0, prints "HDMITX_PacketSwitch_Bypass HDMI RX in Fail !!! %d".
 * input 0x71 / 0x81: k = (input != 0x71) selects the 3-byte record DAT_a8079290[k]; ok = bit 0 of
 * FUN_a00a89c0(0, input, port, 0, 0, 1), then ANDed with FUN_a00a89c0(1, input, port, 0x27, b0, b0) (b0 = byte 0
 * of the record, as 1 / 0) and FUN_a00a89c0(2, input, port, 0, 0, b1 | b2); ok == 0 prints "... DP RX in Fail
 * !!!  %d" (tail call). Other inputs print "... wrong ucInput !  s%d". All prints pass 0.
 * Source forms: input and port are unsigned char copies for the first calls; the last call passes the
 * parameters themselves (the firmware masks them again there); each arm holds its complete call.
 */
struct PktSel { unsigned char b0; unsigned char b1; unsigned char b2; };
extern struct PktSel DAT_a8079290[];
extern int FUN_a0073044(const char *, ...);
extern unsigned char FUN_a00a89c0(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char,
                                  unsigned char);

void HDMITX_PacketSwitch_Bypass(unsigned int port, unsigned int input)
{
    unsigned char in = input;
    unsigned char p;
    unsigned char ok = 1;
    unsigned char k;
    unsigned char r;
    int e;

    switch (in) {
    case 0x31:
    case 0x41:
    case 0x51:
    case 0x61:
        p = port;
        e = FUN_a00a89c0(0, in, p, 0, 1, 0) == 0;
        e |= FUN_a00a89c0(1, in, p, 0x27, 0, 1) == 0;
        e |= FUN_a00a89c0(2, in, p, 0, 0, 0) == 0;
        if (e)
            FUN_a0073044("HDMITX_PacketSwitch_Bypass HDMI RX in Fail !!! %d\r\n", 0);
        break;
    case 0x71:
    case 0x81:
        p = port;
        r = FUN_a00a89c0(0, in, p, 0, 0, 1);
        k = in != 0x71;
        ok = r & 1;
        if (DAT_a8079290[k].b0)
            ok &= FUN_a00a89c0(1, in, p, 0x27, 1, 1);
        else
            ok &= FUN_a00a89c0(1, in, p, 0x27, 0, 0);
        if (DAT_a8079290[k].b2 | DAT_a8079290[k].b1)
            ok = FUN_a00a89c0(2, input, port, 0, 0, 1) & ok;
        else
            ok = FUN_a00a89c0(2, input, port, 0, 0, 0) & ok;
        break;
    default:
        FUN_a0073044("HDMITX_PacketSwitch_Bypass wrong ucInput !  s%d\r\n", 0);
        break;
    }
    if (!ok)
        FUN_a0073044("HDMITX_PacketSwitch_Bypass DP RX in Fail !!!  %d\r\n", 0);
}
