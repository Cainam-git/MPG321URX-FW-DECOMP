/* DRV_HDMI_EQDetect_Timer (leon2s 0xa0083324-0xa0083618, 756 bytes), flags -mcpu=v8 -Os -g.
 * void. Unless FUN_a00a7468(0x12, 0, 0x1f0c) is non-zero, for port 0..3 with r = ARR_a807cc64[port]
 * (0x18-byte records): when r.b2 == 1 prints "EQ reset" (under bit 1 of _DAT_a8078634) and clears word 0 of
 * ARR_a807ccc4[port], DAT_a8078998[port], r.b1, r.b2 and the halfword r.h8. Ports with r.b0 == 0 are skipped.
 * Then FUN_a0073be8(port); when FUN_a0073520(port) is set, ch becomes 0 for port 2 and 1 for port 3 (else keeps
 * its value) and, if FUN_a00a7468(0x1f, ch, 0x1f0c) is non-zero, a new byte 1 of the 0xb0-byte record
 * ARR_a807d680[ch] is stored in DAT_a80789d0[ch] and, when non-zero, passed to FUN_a009ec20(ch, ...),
 * FUN_a0080494(port, ...) and printed; then word +4 of DAT_a80789d4 = _DAT_a8076190, FUN_a00b2194(&DAT_a80789d4)
 * and the next port. Otherwise, when bits 0..2 of the register 0xcf0124a4 are 4, calls
 * FUN_a00a7488(n, 0x1f04, 0xffffff00, 0x2f) for n = 0..3 and returns. Else EQ_handler_3(port); when r.b3 is
 * set: EQ_handler(port) if r.b1 == 1, otherwise clears the ARR_a807ccc4 word (printing "Restart EQ Flow" with
 * 0x237 when it was 0x10) and calls FUN_a0079460(port). After the loop the same DAT_a80789d4 update and call.
 * Source form: port initialised at its declaration; the reset clears in the firmware's store order.
 */
struct sel_rec {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char _4[4];
    unsigned short h8;
    unsigned char _a[0x18 - 0xa];
};
struct Rec12 { unsigned int w0; unsigned int w4; unsigned char b8; unsigned char pad[3]; };
struct rec_b0 {
    unsigned char b0;
    unsigned char b1;
    unsigned char _2[0xb0 - 2];
};
struct R { unsigned int w0; unsigned int w4; };
extern struct sel_rec ARR_a807cc64[];
extern struct Rec12 ARR_a807ccc4[];
extern struct rec_b0 ARR_a807d680[];
extern unsigned char DAT_a8078998[];
extern unsigned char DAT_a80789d0[];
extern struct R DAT_a80789d4;
extern unsigned int _DAT_a8076190;
extern unsigned int _DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern unsigned int FUN_a00a7468(unsigned int, unsigned char, unsigned short);
extern void FUN_a0073be8(unsigned char);
extern unsigned char FUN_a0073520(unsigned char);
extern void FUN_a009ec20(unsigned char, unsigned char);
extern void FUN_a0080494(unsigned char, unsigned char);
extern void FUN_a00b2194(struct R *);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);
extern void EQ_handler_3(unsigned int);
extern void EQ_handler(unsigned char);
extern void FUN_a0079460(unsigned char);

#define REG_CF0124A4 (*(volatile unsigned int *)0xcf0124a4)

static const char fn_[] = "DRV_HDMI_EQDetect_Timer";

void DRV_HDMI_EQDetect_Timer(void)
{
    unsigned char port = 0;
    unsigned char ch = 0;

    if (FUN_a00a7468(0x12, 0, 0x1f0c) == 0) {
        for (; port <= 3; port++) {
            if (ARR_a807cc64[port].b2 == 1) {
                if (_DAT_a8078634 & 2)
                    FUN_a0073044("[EQ]: Port%c EQ reset, set state to INIT state\n\n", (char)(port + 'A'));
                ARR_a807cc64[port].h8 = 0;
                ARR_a807ccc4[port].w0 = 0;
                DAT_a8078998[port] = 0;
                ARR_a807cc64[port].b1 = 0;
                ARR_a807cc64[port].b2 = 0;
            }
            if (ARR_a807cc64[port].b0 == 0)
                continue;
            FUN_a0073be8(port);
            if (FUN_a0073520(port)) {
                if (port == 2)
                    ch = 0;
                else if (port == 3)
                    ch = 1;
                if (FUN_a00a7468(0x1f, ch, 0x1f0c)) {
                    if (ARR_a807d680[ch].b1 != DAT_a80789d0[ch]) {
                        DAT_a80789d0[ch] = ARR_a807d680[ch].b1;
                        if (ARR_a807d680[ch].b1 != 0) {
                            FUN_a009ec20(ch, ARR_a807d680[ch].b1);
                            FUN_a0080494(port, DAT_a80789d0[ch]);
                            if (_DAT_a8078634 & 2)
                                FUN_a0073044("[EQ]: %s EQDetect Timer u8FRL_Rate = %d\n", fn_, DAT_a80789d0[ch]);
                        }
                    }
                    DAT_a80789d4.w4 = _DAT_a8076190;
                    FUN_a00b2194(&DAT_a80789d4);
                    continue;
                }
            }
            if ((REG_CF0124A4 & 7) == 4) {
                FUN_a00a7488(0, 0x1f04, 0xffffff00, 0x2f);
                FUN_a00a7488(1, 0x1f04, 0xffffff00, 0x2f);
                FUN_a00a7488(2, 0x1f04, 0xffffff00, 0x2f);
                FUN_a00a7488(3, 0x1f04, 0xffffff00, 0x2f);
                return;
            }
            EQ_handler_3(port);
            if (ARR_a807cc64[port].b3 == 0)
                continue;
            if (ARR_a807cc64[port].b1 == 1) {
                EQ_handler(port);
                continue;
            }
            if (ARR_a807ccc4[port].w0 == 0x10) {
                if (_DAT_a8078634 & 2)
                    FUN_a0073044("[EQ]: # Port%c Restart EQ Flow, %d\n", (char)(port + 'A'), 0x237);
                ARR_a807ccc4[port].w0 = 0;
            }
            FUN_a0079460(port);
        }
    }
    DAT_a80789d4.w4 = _DAT_a8076190;
    FUN_a00b2194(&DAT_a80789d4);
}
