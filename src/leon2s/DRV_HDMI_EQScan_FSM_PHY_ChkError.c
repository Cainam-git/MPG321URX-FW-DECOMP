/* leon2s DRV_HDMI_EQScan_FSM_PHY_ChkError @ 0xa007d688-0xa007e7c0 (4408 bytes), flags -mcpu=v8 -Os -g.
 * u8 port; returns 0 or 1. Uses the 0x898-byte port record ARR_a807a9f0[port] (rvga[3] at +9, counter at
 * +0x30, ok[3] at +0x31, word table [n][3] at +0x38, byte +0x896) and the 12-byte record ARR_a807ccc4[port]
 * (word 0 written on exit, byte 7 printed as the round, byte 8 selects the RVGA index limit).
 * While the counter is <= 5 it counts up (DRV_HDMI_PHY_Clr_EQ_Err(port) first when it is 0) and returns
 * 0. Otherwise it prints DAT_a0066df8 (port letter, function name, counter) and reads per channel 0..2 the
 * status (FUN_a00a7468(ch, port, 0x1ea0) == 0 ? bits of 0x1e94 / 0x1e98 : 0) and the 16-bit value assembled
 * from bytes of 0x1ea0 / 0x1ea4 into two local word arrays. Value 0x8000 with status bit 5 clear sets ok[ch]
 * (print s_a0067ca8); any other value clears ok[ch] (print s_a0067ce0) and, when the RVGA index of the
 * channel is allowed (rvga_ok), stores value & 0x7fff in the table row of that index.
 * With byte 8 set and a zero low nibble in 0x1178/0x1578/0x1978: print s_a0067d08, word 0 = 4, DAT_a807898c = 1.
 * All three ok: FUN_a007d140(port) == 0 prints s_a0067d48 (99), counts ARR_a8078990[port], clears
 * ARR_a8078998[port], clears ARR_a8076198[port] when a value is below 0x7fff and bits 0x10..0x12 of 0x1e94 are
 * set, calls FUN_a0077e68(port, 0) when FUN_a007517c(port) is non-zero, Deskew_HotPlug(port) after more than 10
 * counts, word 0 = 0, returns 0; else prints the channel registers, sets ARR_a8078998[port] = 1 when DAT_a807619f
 * is set, word 0 = 0x10 and clears byte +0x896. Not all ok: a run of debug prints of the values and registers;
 * then with DAT_a807619f == 1: an allowed RVGA index of a failing channel and byte 8 == 1 advances those
 * indexes (word 0 = 0xd); else DAT_a807cc58[0] == 0 writes the table values DAT_a00b3ad4[DAT_a807cc58[ch]] and
 * DAT_a00b3acc[DAT_a807ccf8[ch]] (both bytes post-incremented) into 0x1178/0x1578/0x1978 around a pulse of bit
 * 0x15 of 0x1100/0x1500/0x1900, clears the counter (word 0 = 0xb); else clears byte +0x896 and checks the three
 * values (0x7fff or bit 15 clear: print s_a0067c58, word 0 = 0, returns 0; otherwise word 0 = 0x10). DAT_a807619f
 * != 1: print s_a0068198, word 0 = 0.
 * Source form: the counter is the 4th argument of the first print and DAT_a807cc58[0] the 3rd argument of the
 * "initial R/C" prints (s_a0068090, s_a0068108), which places them in %o3 / %o2; status assigned with '?:'
 * (the array address is formed before the value); the limit test is the inlined helper rvga_ok (its index
 * argument is read before the byte-8 test); the table bytes are post-incremented inside the value expression;
 * the per-channel loop keeps the firmware's 'ch < 3' test; debug prints are separate ifs (jump threading
 * gives the nested shape).
 */
struct Rec12 { unsigned int w0; unsigned char b4[3]; unsigned char b7; unsigned char b8; unsigned char pad[3]; };
struct EqPort {
    unsigned char _0[9];
    unsigned char rvga[3];
    unsigned char _c[0x24];
    unsigned char cnt;
    unsigned char ok[3];
    unsigned char _34[4];
    unsigned int tbl[178][3];
    unsigned char _890[6];
    unsigned char b896;
    unsigned char _897;
};
extern struct EqPort ARR_a807a9f0[];
extern struct Rec12 ARR_a807ccc4[];
extern unsigned int _DAT_a8078634;
extern unsigned char ARR_a8078990[];
extern unsigned char ARR_a8078998[];
extern unsigned char ARR_a8076198[];
extern unsigned char DAT_a807619f;
extern unsigned char DAT_a807898c;
extern unsigned char DAT_a807cc58[];
extern unsigned char DAT_a807ccf8[];
extern unsigned int DAT_a00b3acc[];
extern unsigned int DAT_a00b3ad4[];
extern unsigned short DAT_a00b3b78[];
extern unsigned char DAT_a00b3ac8[];
extern unsigned char DAT_a0066df8[];
extern char s_a0067ca8[], s_a0067ce0[], s_a0067d08[], s_a0067d48[], s_a0067c18[], s_a00671b8[], s_a00671f0[],
    s_a0067228[], s_a0067d70[], s_a0067d98[], s_a0067de8[], s_a0067e10[], s_a0067e40[], s_a0067e60[],
    s_a0067e88[], s_a0067eb8[], s_a0067ee8[], s_a0067f20[], s_a0067f48[], s_a0067f70[], s_a0067f98[],
    s_a0067fd0[], s_a0068008[], s_a0068040[], s_a0068090[], s_a00680d0[], s_a0067c58[], s_a0068108[],
    s_a0068150[], s_a0068198[];
extern int FUN_a0073044(const void *, ...);
extern void DRV_HDMI_PHY_Clr_EQ_Err(unsigned int);
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);
extern void FUN_a00a7424(int, unsigned int, unsigned char, unsigned short);
extern unsigned int FUN_a00a7468(unsigned int, unsigned char, unsigned short);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);
extern unsigned char FUN_a007d140(unsigned char);
extern unsigned char FUN_a007517c(unsigned int);
extern void FUN_a0077e68(unsigned char, int);
extern void Deskew_HotPlug(unsigned char);

/* 1 when idx is an allowed RVGA index: 0..2 when byte 8 of ARR_a807ccc4[port] is set, else only 0. */
static inline int rvga_ok(unsigned char port, unsigned char idx)
{
    if (ARR_a807ccc4[port].b8 != 0)
        return idx <= 2;
    return idx == 0;
}

int DRV_HDMI_EQScan_FSM_PHY_ChkError(unsigned char port)
{
    unsigned int st[3] = {0};
    unsigned int ced[3] = {0};
    unsigned char ch = 0;
    unsigned int v;

    if (ARR_a807a9f0[port].cnt <= 5) {
        if (ARR_a807a9f0[port].cnt == 0)
            DRV_HDMI_PHY_Clr_EQ_Err(port);
        ARR_a807a9f0[port].cnt++;
        return 0;
    }
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0066df8, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_ChkError",
                     ARR_a807a9f0[port].cnt);
    for (; ch < 3; ch++) {
        if (ch == 0) {
            st[ch] = FUN_a00a7468(0, port, 0x1ea0) == 0 ? FUN_a00a7314(port, 0x1e94) >> 24 : 0;
            ced[ch] = (FUN_a00a7314(port, 0x1ea0) & 0xff00) | ((FUN_a00a7314(port, 0x1ea0) >> 16) & 0xff);
        } else if (ch == 1) {
            st[ch] = FUN_a00a7468(1, port, 0x1ea0) == 0 ? FUN_a00a7314(port, 0x1e98) & 0xff : 0;
            ced[ch] = ((FUN_a00a7314(port, 0x1ea0) & 0xff000000) >> 16) | (FUN_a00a7314(port, 0x1ea4) & 0xff);
        } else {
            st[ch] = FUN_a00a7468(2, port, 0x1ea0) == 0 ? (FUN_a00a7314(port, 0x1e98) >> 8) & 0xff : 0;
            ced[ch] = (FUN_a00a7314(port, 0x1ea4) & 0xff00) | ((FUN_a00a7314(port, 0x1ea4) >> 16) & 0xff);
        }
        if ((st[ch] & 0x20) == 0 && ced[ch] == 0x8000) {
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044(s_a0067ca8, (char)(port + 'A'), ch, ced[ch] & 0x7fff,
                             FUN_a00a7314(port, 0x1ea0) & 0xff);
            ARR_a807a9f0[port].ok[ch] = 1;
        } else if (ced[ch] != 0x8000) {
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044(s_a0067ce0, (char)(port + 'A'), ch, ced[ch] & 0x7fff);
            ARR_a807a9f0[port].ok[ch] = 0;
            if (rvga_ok(port, ARR_a807a9f0[port].rvga[ch]))
                ARR_a807a9f0[port].tbl[ARR_a807a9f0[port].rvga[ch]][ch] = ced[ch] & 0x7fff;
        }
    }
    if (ARR_a807ccc4[port].b8 != 0) {
        if ((FUN_a00a7314(port, 0x1178) & 0xf) == 0 || (FUN_a00a7314(port, 0x1578) & 0xf) == 0
            || (FUN_a00a7314(port, 0x1978) & 0xf) == 0) {
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044(s_a0067d08, (char)(port + 'A'), FUN_a00a7314(port, 0x1178) & 0xf,
                             FUN_a00a7314(port, 0x1578) & 0xf, FUN_a00a7314(port, 0x1978) & 0xf);
            ARR_a807ccc4[port].w0 = 4;
            DAT_a807898c = 1;
            return 1;
        }
    }
    if (ARR_a807a9f0[port].ok[0] == 1 && ARR_a807a9f0[port].ok[1] == 1 && ARR_a807a9f0[port].ok[2] == 1) {
        if (FUN_a007d140(port) == 0) {
            FUN_a0073044(s_a0067d48, 99);
            ARR_a8078990[port]++;
            ARR_a8078998[port] = 0;
            if ((ced[0] & 0x7fff) < 0x7fff || (ced[1] & 0x7fff) < 0x7fff || (ced[2] & 0x7fff) < 0x7fff) {
                if (FUN_a00a7468(0x10, port, 0x1e94) == 1 && FUN_a00a7468(0x11, port, 0x1e94) == 1
                    && FUN_a00a7468(0x12, port, 0x1e94) == 1) {
                    ARR_a8076198[port] = 0;
                    if ((_DAT_a8078634 & 2) != 0)
                        FUN_a0073044(s_a0067c18, (char)(port + 'A'));
                }
            }
            if (FUN_a007517c(port))
                FUN_a0077e68(port, 0);
            if (ARR_a8078990[port] > 10) {
                Deskew_HotPlug(port);
                ARR_a8078990[port] = 0;
            }
            ARR_a807ccc4[port].w0 = 0;
            return 0;
        }
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(s_a00671b8, (char)(port + 'A'), (FUN_a00a7314(port, 0x1178) & 0xffff00) >> 8,
                         FUN_a00a7314(port, 0x1178) & 0xf);
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(s_a00671f0, (char)(port + 'A'), (FUN_a00a7314(port, 0x1578) & 0xffff00) >> 8,
                         FUN_a00a7314(port, 0x1578) & 0xf);
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(s_a0067228, (char)(port + 'A'), (FUN_a00a7314(port, 0x1978) & 0xffff00) >> 8,
                         FUN_a00a7314(port, 0x1978) & 0xf);
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(s_a0067d70, (char)(port + 'A'));
        if (DAT_a807619f != 0)
            ARR_a8078998[port] = 1;
        ARR_a807ccc4[port].w0 = 0x10;
        ARR_a807a9f0[port].b896 = 0;
        return 1;
    }
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(s_a0067d98);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(s_a0067de8, (char)(port + 'A'), ARR_a807ccc4[port].b7);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(s_a0067e10, (char)(port + 'A'), ced[0] & 0x7fff, FUN_a00a7314(port, 0x1ea0) & 0xff);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(s_a0067e40, (char)(port + 'A'), ced[1] & 0x7fff);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(s_a0067e60, (char)(port + 'A'), ced[2] & 0x7fff);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(s_a0067e88, (char)(port + 'A'), (FUN_a00a7314(port, 0x1178) & 0xffff00) >> 8,
                     FUN_a00a7314(port, 0x1178) & 0xf);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(s_a0067eb8, (char)(port + 'A'), (FUN_a00a7314(port, 0x1578) & 0xffff00) >> 8,
                     FUN_a00a7314(port, 0x1578) & 0xf);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(s_a0067ee8, (char)(port + 'A'), (FUN_a00a7314(port, 0x1978) & 0xffff00) >> 8,
                     FUN_a00a7314(port, 0x1978) & 0xf);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(s_a0067f20, (char)(port + 'A'), (FUN_a00a7314(port, 0x103c) >> 16) & 0xff);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(s_a0067f48, (char)(port + 'A'), (FUN_a00a7314(port, 0x143c) >> 16) & 0xff);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(s_a0067f70, (char)(port + 'A'), (FUN_a00a7314(port, 0x183c) >> 16) & 0xff);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(s_a0067f98, (char)(port + 'A'), ARR_a807a9f0[port].rvga[0],
                     DAT_a00b3ac8[ARR_a807a9f0[port].rvga[0]]);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(s_a0067fd0, (char)(port + 'A'), ARR_a807a9f0[port].rvga[1],
                     DAT_a00b3ac8[ARR_a807a9f0[port].rvga[1]]);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(s_a0068008, (char)(port + 'A'), ARR_a807a9f0[port].rvga[2],
                     DAT_a00b3ac8[ARR_a807a9f0[port].rvga[2]]);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(s_a0068040);
    if (DAT_a807619f == 1) {
        if (((rvga_ok(port, ARR_a807a9f0[port].rvga[0]) && ARR_a807a9f0[port].ok[0] == 0)
             || (rvga_ok(port, ARR_a807a9f0[port].rvga[1]) && ARR_a807a9f0[port].ok[1] == 0)
             || (rvga_ok(port, ARR_a807a9f0[port].rvga[2]) && ARR_a807a9f0[port].ok[2] == 0))
            && ARR_a807ccc4[port].b8 == 1) {
            for (ch = 0; ch < 3; ch++) {
                if (rvga_ok(port, ARR_a807a9f0[port].rvga[ch]) && ARR_a807a9f0[port].ok[ch] == 0)
                    ARR_a807a9f0[port].rvga[ch]++;
            }
            ARR_a807ccc4[port].w0 = 0xd;
        } else if (DAT_a807cc58[0] == 0) {
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044(s_a0068090, (char)(port + 'A'), DAT_a807cc58[0]);
            FUN_a00a7424(1, 0x15, port, 0x1100);
            FUN_a00a7424(1, 0x15, port, 0x1500);
            FUN_a00a7424(1, 0x15, port, 0x1900);
            for (ch = 0; ch < 3; ch++) {
                if (ch < 3) {
                    FUN_a00a7488(port, DAT_a00b3b78[ch], 0xff0000f0,
                                 (DAT_a00b3ad4[DAT_a807cc58[ch]++] & 0xf) | ((DAT_a00b3acc[DAT_a807ccf8[ch]++] & 0xffff) << 8));
                }
            }
            FUN_a00a7424(0, 0x15, port, 0x1100);
            FUN_a00a7424(0, 0x15, port, 0x1500);
            FUN_a00a7424(0, 0x15, port, 0x1900);
            ARR_a807a9f0[port].cnt = 0;
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044(s_a00680d0, (char)(port + 'A'));
            ARR_a807ccc4[port].w0 = 0xb;
        } else {
            ARR_a807a9f0[port].b896 = 0;
            if ((ced[0] & 0x7fff) == 0x7fff || (ced[1] & 0x7fff) == 0x7fff || (ced[2] & 0x7fff) == 0x7fff
                || (ced[0] & 0x8000) == 0 || (ced[1] & 0x8000) == 0 || (ced[2] & 0x8000) == 0) {
                if ((_DAT_a8078634 & 2) != 0)
                    FUN_a0073044(s_a0067c58, (char)(port + 'A'));
                ARR_a807ccc4[port].w0 = 0;
                return 0;
            }
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044(s_a0068108, (char)(port + 'A'), DAT_a807cc58[0]);
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044(s_a0068150, (char)(port + 'A'));
            ARR_a807ccc4[port].w0 = 0x10;
        }
    } else {
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(s_a0068198, (char)(port + 'A'));
        ARR_a807ccc4[port].w0 = 0;
    }
    return 1;
}
