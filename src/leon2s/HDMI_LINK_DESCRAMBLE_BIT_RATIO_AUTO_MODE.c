/* leon2s HDMI_LINK_DESCRAMBLE_BIT_RATIO_AUTO_MODE @ 0xa007ed88-0xa007f634 (2220 bytes), flags -mcpu=v8 -Os -g.
 * u8 port; returns 1. Its debug prints carry the name "DRV_HDMI_EQScan_FSM_PHY_Init" (fn_). With bit 1 of
 * _DAT_a8078634 set it prints DAT_a0068250 (port letter, FUN_a00b2064()) and DAT_a0067058 (port letter, fn_).
 * Clears DAT_a807cc58[0..2] and DAT_a807ccf8[0..2]; when FUN_a0073520(port) is non-zero clears bit 3 of
 * 0x2070/0x2470/0x2870/0x3070 and bits 0x18/0x11 of the 0x2028.. registers; then fixed PHY writes (0x1168,
 * 0x1020/0x1420/0x1820, 0x1c00, a pulse of bit 0x15 of 0x1100/0x1500/0x1900 around 0x1168/0x1038 writes, bit
 * 0x17 of 0x1148/0x1548/0x1948 set, FUN_a00b160c(10), cleared) and halfword +0xa of the 24-byte record
 * DAT_a807cc64[port] = FUN_a0074f60(port).
 * FUN_a007517c(port) non-zero: two prints (s_a0068288, s_a00682b0 with ARR_a8078978[port]). Else when
 * FUN_a007af04 and FUN_a007af6c return 0, record byte 7 != 1 and 0x4a < halfword +0xa <= 0x96:
 * ARR_a8078980[port] = 1, FUN_a007ed0c(port, 0), and when bits 0x10..0x12 of 0x1e94 all test 0
 * (FUN_a00a7468) bit 0 of ARR_a8076198[port] is inverted; otherwise ARR_a8078980[port] = 0 and
 * FUN_a007ec30(port, 0, 0) + FUN_a007ed0c(port, 1) (port 2: FUN_a007ed0c(port, 0) only).
 * Then halfword +8 = halfword +0xa (times 4 when FUN_a007b2a0(port) == 1; FUN_a007517c non-zero also calls
 * FUN_a007ed0c(port, 0) and FUN_a007ec30(port, 1, port == 2)), with FUN_a007ec30 calls when
 * ARR_a8078980[port] == 1. FUN_a007d054(port) non-zero sets bits 16..18 of word +0x74 of *_DAT_a807db0c to
 * 5 (port 2) and calls FUN_a007ebd0(port); zero clears them (port 2). When ARR_a8078998[port] == 0 the
 * records ARR_a807ccc4[port] (12 bytes) and ARR_a807a9f0[port] (0x898 bytes) are cleared. Finally word 0 of
 * ARR_a807ccc4[port] = 1, its byte 7 = 0, byte +0x30 of ARR_a807a9f0[port] = 0, DAT_a807898c = 0.
 * Source form: the port == 2 call variants are written as separate calls in if/else arms; ARR_a8078980[port]
 * is read into a local before the halfword store; the six byte clears in array order.
 */
struct Rec24 { unsigned char _0[7]; unsigned char b7; unsigned short h8; unsigned short ha; unsigned char _c[0xc]; };
struct Rec12 { unsigned int w0; unsigned char b4[3]; unsigned char b7; unsigned char b8; unsigned char pad[3]; };
struct EqPort { unsigned char _0[0x30]; unsigned char cnt; unsigned char _31[0x898 - 0x31]; };
extern struct Rec24 DAT_a807cc64[];
extern struct Rec12 ARR_a807ccc4[];
extern struct EqPort ARR_a807a9f0[];
extern unsigned int _DAT_a8078634;
extern unsigned int *_DAT_a807db0c;
extern unsigned char DAT_a807cc58[];
extern unsigned char DAT_a807ccf8[];
extern unsigned char ARR_a8078978[];
extern unsigned char ARR_a8078980[];
extern unsigned char ARR_a8078998[];
extern unsigned char ARR_a8076198[];
extern unsigned char DAT_a807898c;
extern unsigned char DAT_a0068250[], DAT_a0067058[];
extern char s_a0068288[], s_a00682b0[], s_a00682e8[], s_a0068328[], s_a0068358[], s_a0068390[], s_a00683d0[],
    s_a00683f0[], s_a0068420[], s_a0068440[], s_a0068470[], s_a0068498[];
extern int FUN_a0073044(const void *, ...);
extern int FUN_a00734c4(const char *);
extern unsigned int FUN_a00b2064(void);
extern unsigned char FUN_a0073520(unsigned char);
extern void FUN_a00a7424(int, unsigned int, unsigned char, unsigned short);
extern unsigned int FUN_a00a7468(unsigned int, unsigned char, unsigned short);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);
extern void FUN_a00b160c(unsigned int);
extern unsigned short FUN_a0074f60(unsigned char);
extern unsigned char FUN_a007517c(unsigned int);
extern unsigned char FUN_a007af04(unsigned char);
extern unsigned char FUN_a007af6c(unsigned char);
extern unsigned char FUN_a007b2a0(unsigned char);
extern unsigned char FUN_a007d054(unsigned char);
extern void FUN_a007ed0c(unsigned char, unsigned char);
extern void FUN_a007ec30(unsigned char, unsigned char, unsigned char);
extern void FUN_a007ebd0(unsigned char);
extern void *FUN_a00b15ac(void *, int, unsigned int);

static const char fn_[] = "DRV_HDMI_EQScan_FSM_PHY_Init";

int HDMI_LINK_DESCRAMBLE_BIT_RATIO_AUTO_MODE(unsigned char port)
{
    unsigned char m;

    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0068250, (char)(port + 'A'), FUN_a00b2064());
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0067058, (char)(port + 'A'), fn_);
    DAT_a807cc58[0] = 0;
    DAT_a807cc58[1] = 0;
    DAT_a807cc58[2] = 0;
    DAT_a807ccf8[0] = 0;
    DAT_a807ccf8[1] = 0;
    DAT_a807ccf8[2] = 0;
    if (FUN_a0073520(port)) {
        FUN_a00a7424(0, 3, port, 0x2070);
        FUN_a00a7424(0, 3, port, 0x2470);
        FUN_a00a7424(0, 3, port, 0x2870);
        FUN_a00a7424(0, 3, port, 0x3070);
        FUN_a00a7424(0, 0x18, port, 0x2028);
        FUN_a00a7424(0, 0x11, port, 0x2028);
        FUN_a00a7424(0, 0x11, port, 0x2428);
        FUN_a00a7424(0, 0x11, port, 0x2828);
        FUN_a00a7424(0, 0x11, port, 0x3028);
    }
    FUN_a00a7424(0, 0xd, port, 0x1168);
    FUN_a00a7488(port, 0x1020, 0xffcfffff, 0x100000);
    FUN_a00a7488(port, 0x1420, 0xffcfffff, 0x100000);
    FUN_a00a7488(port, 0x1820, 0xffcfffff, 0x100000);
    FUN_a00a7488(port, 0x1c00, 0xffffff00, 2);
    FUN_a00a7424(1, 0x15, port, 0x1100);
    FUN_a00a7424(1, 0x15, port, 0x1500);
    FUN_a00a7424(1, 0x15, port, 0x1900);
    FUN_a00a7488(port, 0x1168, 0xffff00ff, 0);
    FUN_a00a7488(port, 0x1038, 0xffffff00, 0);
    FUN_a00a7424(1, 0x12, port, 0x1f08);
    FUN_a00a7424(1, 0x17, port, 0x1148);
    FUN_a00a7424(1, 0x17, port, 0x1548);
    FUN_a00a7424(1, 0x17, port, 0x1948);
    FUN_a00b160c(10);
    FUN_a00a7424(0, 0x17, port, 0x1948);
    FUN_a00a7424(0, 0x17, port, 0x1548);
    FUN_a00a7424(0, 0x17, port, 0x1148);
    FUN_a00a7424(0, 0x12, port, 0x1f08);
    DAT_a807cc64[port].ha = FUN_a0074f60(port);
    if (FUN_a007517c(port)) {
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(s_a0068288, (char)(port + 'A'));
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(s_a00682b0, (char)(port + 'A'), ARR_a8078978[port]);
    } else if (FUN_a007af04(port) == 0 && FUN_a007af6c(port) == 0 && DAT_a807cc64[port].b7 != 1
               && DAT_a807cc64[port].ha > 0x4a && DAT_a807cc64[port].ha <= 0x96) {
        ARR_a8078980[port] = 1;
        FUN_a007ed0c(port, 0);
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(s_a00682e8, (char)(port + 'A'), ARR_a8076198[port]);
        if (FUN_a00a7468(0x10, port, 0x1e94) == 0 && FUN_a00a7468(0x11, port, 0x1e94) == 0
            && FUN_a00a7468(0x12, port, 0x1e94) == 0) {
            ARR_a8076198[port] = ~ARR_a8076198[port] & 1;
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044(s_a0068328, (char)(port + 'A'));
        }
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(s_a0068358, (char)(port + 'A'), ARR_a8076198[port]);
    } else {
        ARR_a8078980[port] = 0;
        if (port != 2) {
            FUN_a007ec30(port, 0, 0);
            FUN_a007ed0c(port, 1);
        } else {
            FUN_a007ed0c(port, 0);
        }
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(s_a0068390, (char)(port + 'A'));
    }
    if (FUN_a007517c(port)) {
        FUN_a007ed0c(port, 0);
        if (port != 2)
            FUN_a007ec30(port, 1, 0);
        else
            FUN_a007ec30(port, 1, 1);
        DAT_a807cc64[port].h8 = DAT_a807cc64[port].ha;
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(s_a00683d0, (char)(port + 'A'), DAT_a807cc64[port].h8);
    } else if (FUN_a007b2a0(port) == 1) {
        m = ARR_a8078980[port];
        DAT_a807cc64[port].h8 = DAT_a807cc64[port].ha << 2;
        if (m == 1) {
            FUN_a007ec30(port, 1, 1);
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044(s_a00683f0, (char)(port + 'A'));
        }
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(s_a0068420, (char)(port + 'A'), DAT_a807cc64[port].h8);
    } else {
        m = ARR_a8078980[port];
        DAT_a807cc64[port].h8 = DAT_a807cc64[port].ha;
        if (m == 1) {
            FUN_a007ec30(port, 0, 0);
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044(s_a0068440, (char)(port + 'A'));
        }
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(s_a00683d0, (char)(port + 'A'), DAT_a807cc64[port].h8);
    }
    if (FUN_a007d054(port)) {
        if (port == 2)
            _DAT_a807db0c[0x74 / 4] = (_DAT_a807db0c[0x74 / 4] & ~0x70000) | 0x50000;
        FUN_a007ebd0(port);
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(s_a0068470, (char)(port + 'A'), fn_);
    } else if (port == 2) {
        _DAT_a807db0c[0x74 / 4] &= ~0x70000;
    }
    if (ARR_a8078998[port] == 0) {
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a00734c4(s_a0068498);
        FUN_a00b15ac(&ARR_a807ccc4[port], 0, 0xc);
        FUN_a00b15ac(&ARR_a807a9f0[port], 0, 0x898);
    }
    ARR_a807ccc4[port].w0 = 1;
    ARR_a807ccc4[port].b7 = 0;
    ARR_a807a9f0[port].cnt = 0;
    DAT_a807898c = 0;
    return 1;
}
