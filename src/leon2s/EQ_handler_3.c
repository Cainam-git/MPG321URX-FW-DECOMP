/* EQ_handler_3 (leon2s 0xa007afdc-0xa007b2a0, 708 bytes), flags -mcpu=v8 -Os -g.
 * unsigned int port. r = ARR_a807cc64[port] (0x18-byte records). When r.b3 differs from
 * (FUN_a00a7468(0x1c, port, 0x1c04) != 0): sets DAT_a8076198[port] = 1 if r.b3 is set, stores the new value
 * (read again) in r.b3, clears word 0 of the 12-byte record ARR_a807ccc4[port], sets byte 0x37 of the
 * 0x898-byte record ARR_a807a9f0[port] and clears r.b1; when the new value is set and
 * FUN_a00a7468(0, port, 0x3600) is not 0 it calls FUN_a009ec20(ch, byte 1 of the 0xb0-byte record
 * ARR_a807d680[ch]) with ch = (port != 2); prints "CDKT Chg State To %d" (under bit 1 of _DAT_a8078634) and,
 * when r.b3 is set and the low byte of FUN_a0074fc4(port) is not 0, clears DAT_a8078998[port] and prints
 * "CLK unstable1" with 0x2b1. Otherwise, when r.b3 is set and that low byte is not 0, prints "CLK unstable2"
 * if r.b1 == 1 and does the same three clears/sets. Finally, when DAT_a80789c8[port] differs from
 * FUN_a007af6c(port) and r.b7 != 1, stores a new FUN_a007af6c(port) there and clears the ARR_a807ccc4 word
 * and r.b1.
 * Source form: port is an unsigned int parameter (raw %i0 in index arithmetic, masked per call);
 * ARR_a807ccc4 is an array of {w0, w4, b8} records as in DRV_HDMI_EQScan_FSM_PHY_PreAEQ; the independent
 * stores are written in the firmware's order.
 */
struct sel_rec {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4[3];
    unsigned char b7;
    unsigned char _8[0x18 - 8];
};
struct rec_b0 {
    unsigned char b0;
    unsigned char b1;
    unsigned char _2[0xb0 - 2];
};
extern struct sel_rec ARR_a807cc64[];
struct Rec12 { unsigned int w0; unsigned int w4; unsigned char b8; unsigned char pad[3]; };
extern struct Rec12 ARR_a807ccc4[];
extern unsigned char ARR_a807a9f0[][0x898];
extern struct rec_b0 ARR_a807d680[];
extern unsigned char DAT_a8076198[];
extern unsigned char DAT_a8078998[];
extern unsigned char DAT_a80789c8[];
extern unsigned int _DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern int FUN_a0074fc4(unsigned char);
extern unsigned int FUN_a00a7468(unsigned int, unsigned char, unsigned short);
extern void FUN_a009ec20(unsigned char, unsigned char);
extern unsigned char FUN_a007af6c(unsigned char);

void EQ_handler_3(unsigned int port)
{
    unsigned char ch = port != 2;
    unsigned char v;

    if (ARR_a807cc64[port].b3 != (FUN_a00a7468(0x1c, port, 0x1c04) != 0)) {
        if (ARR_a807cc64[port].b3)
            DAT_a8076198[port] = 1;
        v = FUN_a00a7468(0x1c, port, 0x1c04) != 0;
        ARR_a807cc64[port].b3 = v;
        ARR_a807ccc4[port].w0 = 0;
        ARR_a807a9f0[port][0x37] = 1;
        ARR_a807cc64[port].b1 = 0;
        if (v) {
            if (FUN_a00a7468(0, port, 0x3600))
                FUN_a009ec20(ch, ARR_a807d680[ch].b1);
        }
        if (_DAT_a8078634 & 2)
            FUN_a0073044("[EQ]: \x1b[36;1m# Port%c CDKT Chg State To %d. Restart EQ Flow\n\x1b[m", (char)(port + 'A'),
                         FUN_a00a7468(0x1c, port, 0x1c04) != 0);
        if (ARR_a807cc64[port].b3 && (unsigned char)FUN_a0074fc4(port)) {
            DAT_a8078998[port] = 0;
            if (_DAT_a8078634 & 2)
                FUN_a0073044("[EQ]: # Port%c CLK unstable1. Clean u8EQDone (%d)\n\n", (char)(port + 'A'), 0x2b1);
        }
    } else if (ARR_a807cc64[port].b3 && (unsigned char)FUN_a0074fc4(port)) {
        if (ARR_a807cc64[port].b1 == 1) {
            if (_DAT_a8078634 & 2)
                FUN_a0073044("[EQ]: # Port%c CLK unstable2. Restart EQ Flow\n", (char)(port + 'A'));
        }
        ARR_a807cc64[port].b1 = 0;
        ARR_a807ccc4[port].w0 = 0;
        ARR_a807a9f0[port][0x37] = 1;
    }
    if (DAT_a80789c8[port] != FUN_a007af6c(port) && ARR_a807cc64[port].b7 != 1) {
        DAT_a80789c8[port] = FUN_a007af6c(port);
        ARR_a807ccc4[port].w0 = 0;
        ARR_a807cc64[port].b1 = 0;
    }
}
