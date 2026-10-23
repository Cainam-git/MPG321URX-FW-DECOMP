/* leon2s DRV_HDMI_EQScan_FSM_PHY_EQ @ 0xa007b394-0xa007c4b8 (-mcpu=v8 -Os -g)
 * EQ step of the HDMI EQ-scan state machine for port p. v = halfword +8 of record p of DAT_a807cc64. Writes the
 * per-lane PHY fields at 0x1128/0x1528/0x1928, 0x1134/0x1534/0x1934 and 0x11b0/0x15b0/0x19b0 with values chosen by
 * FUN_a0073520(p), then either loads the EQ table values (DAT_a00b3ad4/DAT_a00b3acc indexed by DAT_a807cc58 and
 * DAT_a807ccf8, or DAT_a807619e/DAT_a807619c) into 0x1178/0x1578/0x1978, or writes the three bytes of row p of
 * ARR_a807a9f0 with FUN_a0074ef4. Selects the 0x101c/0x141c/0x181c and 0x3614 settings by the ranges of v (below
 * 100, 160, 300, up to 600 with FUN_a007b2a0(p), above 600), and with r = FUN_a0073520(p) writes the 0x3614/0x360c
 * group. Byte 8 of the 12-byte record ARR_a807ccc4[p] = (v > 300); bch_en_flag(p, 5) when ARR_a8078998[p] is 0;
 * byte 8 is cleared together with DAT_a807898c when that flag is set. When byte 8 is 1, writes the 0x1170/0x117c
 * group, 0x1020 and 0x23c0..0x33c0. Ends with FUN_a00a7424 on 0x1004/0x1404/0x1804, hdmi_PHY_Set_CTLE(p),
 * FUN_a0075360(p) when r is set, a 10-tick delay, FUN_a00a7424 on 0x1900/0x1500/0x1100,
 * DRV_HDMI_PHY_Clr_EQ_Err(p) and word 0 of ARR_a807ccc4[p] = 10. Returns 0.
 * Source form: the final store is written in both arms of 'if (ARR_a807ccc4[port].b8 == 1) ... else ...' with the
 * same value, as other branches of this function also are. The two identical arms are merged only after register
 * allocation, so the index computation is allocated as a value shared by both arms; this gives the firmware's
 * register choice (%o0) and order for the last store.
 */
struct Rec24 { unsigned char _0[8]; unsigned short h8; unsigned char _a[0xe]; };
struct Rec12 { unsigned int w0; unsigned int w4; unsigned char b8; unsigned char pad[3]; };
extern struct Rec24 DAT_a807cc64[];
extern struct Rec12 ARR_a807ccc4[];
extern unsigned int _DAT_a8078634;
extern unsigned char ARR_a8078998[];
extern unsigned char DAT_a807898c;
extern unsigned char ARR_a807a9f0[][0x898];
extern unsigned char DAT_a807619e;
extern unsigned short DAT_a807619c;
extern unsigned char DAT_a807cc58[];
extern unsigned char DAT_a807ccf8[];
extern unsigned int DAT_a00b3ad4[];
extern unsigned int DAT_a00b3acc[];
extern unsigned char DAT_a0067058[], DAT_a0067988[];
extern char s_a00679b8[], s_a00679e0[], s_a0067a18[], s_a0067a50[], s_a0067a78[], s_a0067a98[];
extern int FUN_a0073044(const void *, ...);
extern int FUN_a00734c4(const char *);
extern unsigned char FUN_a0073520(unsigned char);
extern unsigned char FUN_a007b2a0(unsigned char);
extern void FUN_a0074ef4(unsigned char, unsigned char, unsigned char);
extern void FUN_a00a7424(int, unsigned int, unsigned char, unsigned short);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);
extern void FUN_a00b1794(unsigned short);
extern void bch_en_flag(unsigned int, int);
extern void hdmi_PHY_Set_CTLE(unsigned char);
extern void FUN_a0075360(unsigned char);
extern void DRV_HDMI_PHY_Clr_EQ_Err(unsigned int);

int DRV_HDMI_EQScan_FSM_PHY_EQ(unsigned char port)
{
    unsigned short v = DAT_a807cc64[port].h8;
    unsigned char r;

    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0067058, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_EQ");
    FUN_a00a7424(1, 0xf, port, 0x1134);
    FUN_a00a7424(1, 0xf, port, 0x1534);
    FUN_a00a7424(1, 0xf, port, 0x1934);
    if (FUN_a0073520(port)) {
        FUN_a00a7488(port, 0x1128, 0xff0fffff, 0xf00000);
        FUN_a00a7488(port, 0x1528, 0xff0fffff, 0xf00000);
        FUN_a00a7488(port, 0x1928, 0xff0fffff, 0xf00000);
    } else {
        FUN_a00a7488(port, 0x1128, 0xff0fffff, 0x300000);
        FUN_a00a7488(port, 0x1528, 0xff0fffff, 0x300000);
        FUN_a00a7488(port, 0x1928, 0xff0fffff, 0x300000);
    }
    FUN_a00a7488(port, 0x11b0, 0xffffff00, 0xf8);
    FUN_a00a7488(port, 0x15b0, 0xffffff00, 0xf8);
    FUN_a00a7488(port, 0x19b0, 0xffffff00, 0xf8);
    if (FUN_a0073520(port)) {
        FUN_a00a7488(port, 0x101c, 0xffffff, 0xbb000000);
        FUN_a00a7424(1, 0xf, port, 0x1134);
        FUN_a00a7488(port, 0x1128, 0xff0fffff, 0xf00000);
        FUN_a00a7424(1, 0xf, port, 0x1534);
        FUN_a00a7488(port, 0x1528, 0xff0fffff, 0xf00000);
        FUN_a00a7424(1, 0xf, port, 0x1934);
        FUN_a00a7488(port, 0x1928, 0xff0fffff, 0xf00000);
    } else {
        FUN_a00a7488(port, 0x101c, 0xffffff, 0xbb000000);
        FUN_a00a7424(1, 0xf, port, 0x1134);
        FUN_a00a7488(port, 0x1128, 0xff0fffff, 0x300000);
        FUN_a00a7424(1, 0xf, port, 0x1534);
        FUN_a00a7488(port, 0x1528, 0xff0fffff, 0x300000);
        FUN_a00a7424(1, 0xf, port, 0x1934);
        FUN_a00a7488(port, 0x1928, 0xff0fffff, 0x300000);
    }
    if (v > 300)
        ARR_a807ccc4[port].b8 = 1;
    else
        ARR_a807ccc4[port].b8 = 0;
    if (ARR_a8078998[port] == 0)
        bch_en_flag(port, 5);
    if (DAT_a807898c != 0) {
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(DAT_a0067988, (char)(port + 'A'));
        ARR_a807ccc4[port].b8 = 0;
        DAT_a807898c = 0;
    }
    if (ARR_a807ccc4[port].b8 == 1) {
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(s_a00679b8, (char)(port + 'A'));
        FUN_a00a7488(port, 0x1170, 0xff00ffff, 0x2c0000);
        FUN_a00a7488(port, 0x1570, 0xff00ffff, 0x2c0000);
        FUN_a00a7488(port, 0x1970, 0xff00ffff, 0x2c0000);
        FUN_a00a7488(port, 0x117c, 0xff00ffff, 0xff0000);
        FUN_a00a7488(port, 0x157c, 0xff00ffff, 0xff0000);
        FUN_a00a7488(port, 0x197c, 0xff00ffff, 0xff0000);
        if (FUN_a0073520(port)) {
            FUN_a00a7488(port, 0x1178, 0xff0000f0,
                         (DAT_a00b3ad4[DAT_a807cc58[0]] & 0xf) | ((DAT_a00b3acc[DAT_a807ccf8[0]] & 0xffff) << 8));
            FUN_a00a7488(port, 0x1578, 0xff0000f0,
                         (DAT_a00b3ad4[DAT_a807cc58[1]] & 0xf) | ((DAT_a00b3acc[DAT_a807ccf8[1]] & 0xffff) << 8));
            FUN_a00a7488(port, 0x1978, 0xff0000f0,
                         (DAT_a00b3ad4[DAT_a807cc58[2]] & 0xf) | ((DAT_a00b3acc[DAT_a807ccf8[2]] & 0xffff) << 8));
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044(s_a00679e0, DAT_a00b3ad4[DAT_a807cc58[0]], DAT_a00b3acc[DAT_a807ccf8[0]]);
        } else {
            FUN_a00a7488(port, 0x1178, 0xff0000f0, (DAT_a807619e & 0xf) | (DAT_a807619c << 8));
            FUN_a00a7488(port, 0x1578, 0xff0000f0, (DAT_a807619e & 0xf) | (DAT_a807619c << 8));
            FUN_a00a7488(port, 0x1978, 0xff0000f0, (DAT_a807619e & 0xf) | (DAT_a807619c << 8));
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044(s_a0067a18, DAT_a807619e, DAT_a807619c);
        }
    } else {
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(s_a0067a50, (char)(port + 'A'));
        FUN_a00a7488(port, 0x1170, 0xff00ffff, 0x2f0000);
        FUN_a00a7488(port, 0x1570, 0xff00ffff, 0x2f0000);
        FUN_a00a7488(port, 0x1970, 0xff00ffff, 0x2f0000);
        FUN_a00a7488(port, 0x117c, 0xff00ffff, 0x4f0000);
        FUN_a00a7488(port, 0x157c, 0xff00ffff, 0x4f0000);
        FUN_a00a7488(port, 0x197c, 0xff00ffff, 0x4f0000);
        FUN_a0074ef4(port, 0, ARR_a807a9f0[port][0]);
        FUN_a0074ef4(port, 1, ARR_a807a9f0[port][1]);
        FUN_a0074ef4(port, 2, ARR_a807a9f0[port][2]);
    }
    if (v < 100) {
        if (!FUN_a0073520(port)) {
            FUN_a00a7424(1, 7, port, 0x101c);
            FUN_a00a7424(1, 7, port, 0x141c);
            FUN_a00a7424(1, 7, port, 0x181c);
            FUN_a00a7488(port, 0x101c, 0xfffffff9, 2);
            FUN_a00a7488(port, 0x141c, 0xfffffff9, 2);
            FUN_a00a7488(port, 0x181c, 0xfffffff9, 2);
            FUN_a00a7488(port, 0x1178, 0xff0000f0, 0xff08);
            FUN_a00a7488(port, 0x1578, 0xff0000f0, 0xff08);
            FUN_a00a7488(port, 0x1978, 0xff0000f0, 0xff08);
            FUN_a00a7488(port, 0x1020, 0xffcfffff, 0x100000);
            FUN_a00a7488(port, 0x1420, 0xffcfffff, 0x100000);
            FUN_a00a7488(port, 0x1820, 0xffcfffff, 0x100000);
        } else {
            FUN_a00a7488(port, 0x1178, 0xff0000f0, 0xff08);
            FUN_a00a7488(port, 0x1578, 0xff0000f0, 0xff08);
            FUN_a00a7488(port, 0x1978, 0xff0000f0, 0xff08);
            FUN_a00a7424(1, 7, port, 0x101c);
            FUN_a00a7424(1, 7, port, 0x141c);
            FUN_a00a7424(1, 7, port, 0x181c);
            FUN_a00a7488(port, 0x101c, 0xfffffff9, 2);
            FUN_a00a7488(port, 0x141c, 0xfffffff9, 2);
            FUN_a00a7488(port, 0x181c, 0xfffffff9, 2);
            FUN_a00a7488(port, 0x1020, 0xffcfffff, 0x100000);
            FUN_a00a7488(port, 0x1420, 0xffcfffff, 0x100000);
            FUN_a00a7488(port, 0x1820, 0xffcfffff, 0x100000);
            FUN_a00a7488(port, 0x3614, 0xffff0000, 0x160);
        }
    } else if (v < 160) {
        if (FUN_a0073520(port)) {
            FUN_a00a7488(port, 0x1178, 0xff0000f0, 0xff08);
            FUN_a00a7488(port, 0x1578, 0xff0000f0, 0xff08);
            FUN_a00a7488(port, 0x1978, 0xff0000f0, 0xff08);
            FUN_a00a7424(1, 7, port, 0x101c);
            FUN_a00a7424(1, 7, port, 0x141c);
            FUN_a00a7424(1, 7, port, 0x181c);
            FUN_a00a7488(port, 0x101c, 0xfffffff9, 4);
            FUN_a00a7488(port, 0x141c, 0xfffffff9, 4);
            FUN_a00a7488(port, 0x181c, 0xfffffff9, 4);
            FUN_a00a7488(port, 0x1020, 0xffcfffff, 0x100000);
            FUN_a00a7488(port, 0x1420, 0xffcfffff, 0x100000);
            FUN_a00a7488(port, 0x1820, 0xffcfffff, 0x100000);
            FUN_a00a7488(port, 0x3614, 0xffff0000, 0x4444);
        } else {
            FUN_a00a7424(1, 7, port, 0x101c);
            FUN_a00a7424(1, 7, port, 0x141c);
            FUN_a00a7424(1, 7, port, 0x181c);
            FUN_a00a7488(port, 0x101c, 0xfffffff9, 6);
            FUN_a00a7488(port, 0x141c, 0xfffffff9, 6);
            FUN_a00a7488(port, 0x181c, 0xfffffff9, 6);
            FUN_a00a7488(port, 0x1178, 0xff0000f0, 0xff08);
            FUN_a00a7488(port, 0x1578, 0xff0000f0, 0xff08);
            FUN_a00a7488(port, 0x1978, 0xff0000f0, 0xff08);
            FUN_a00a7488(port, 0x1020, 0xffcfffff, 0x100000);
            FUN_a00a7488(port, 0x1420, 0xffcfffff, 0x100000);
            FUN_a00a7488(port, 0x1820, 0xffcfffff, 0x100000);
        }
    } else if (v < 300) {
l300:
        if (!FUN_a0073520(port)) {
            FUN_a00a7424(1, 7, port, 0x101c);
            FUN_a00a7424(1, 7, port, 0x141c);
            FUN_a00a7424(1, 7, port, 0x181c);
            FUN_a00a7488(port, 0x101c, 0xfffffff9, 6);
            FUN_a00a7488(port, 0x141c, 0xfffffff9, 6);
            FUN_a00a7488(port, 0x181c, 0xfffffff9, 6);
            FUN_a00a7488(port, 0x1178, 0xff0000f0, 0xff08);
            FUN_a00a7488(port, 0x1578, 0xff0000f0, 0xff08);
            FUN_a00a7488(port, 0x1978, 0xff0000f0, 0xff08);
            FUN_a00a7488(port, 0x1020, 0xffcfffff, 0x100000);
            FUN_a00a7488(port, 0x1420, 0xffcfffff, 0x100000);
            FUN_a00a7488(port, 0x1820, 0xffcfffff, 0x100000);
        } else {
            FUN_a00a7488(port, 0x1178, 0xff0000f0, 0xff08);
            FUN_a00a7488(port, 0x1578, 0xff0000f0, 0xff08);
            FUN_a00a7488(port, 0x1978, 0xff0000f0, 0xff08);
            FUN_a00a7424(1, 7, port, 0x101c);
            FUN_a00a7424(1, 7, port, 0x141c);
            FUN_a00a7424(1, 7, port, 0x181c);
            FUN_a00a7488(port, 0x101c, 0xfffffff9, 4);
            FUN_a00a7488(port, 0x141c, 0xfffffff9, 4);
            FUN_a00a7488(port, 0x181c, 0xfffffff9, 4);
            FUN_a00a7488(port, 0x1020, 0xffcfffff, 0x100000);
            FUN_a00a7488(port, 0x1420, 0xffcfffff, 0x100000);
            FUN_a00a7488(port, 0x1820, 0xffcfffff, 0x100000);
            FUN_a00a7488(port, 0x3614, 0xffff0000, 0x60);
        }
    } else if (v <= 600) {
        if (!FUN_a007b2a0(port)) {
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a00734c4(s_a0067a78);
            goto l300;
        } else {
            if (!FUN_a0073520(port)) {
                FUN_a00a7424(1, 7, port, 0x101c);
                FUN_a00a7424(1, 7, port, 0x141c);
                FUN_a00a7424(1, 7, port, 0x181c);
                FUN_a00a7488(port, 0x101c, 0xfffffff9, 6);
                FUN_a00a7488(port, 0x141c, 0xfffffff9, 6);
                FUN_a00a7488(port, 0x181c, 0xfffffff9, 6);
                FUN_a00a7488(port, 0x1178, 0xff0000f0, 0xfff08);
                FUN_a00a7488(port, 0x1578, 0xff0000f0, 0xfff08);
                FUN_a00a7488(port, 0x1978, 0xff0000f0, 0xfff08);
                FUN_a00a7488(port, 0x1020, 0xffcfffff, 0x300000);
                FUN_a00a7488(port, 0x1420, 0xffcfffff, 0x300000);
                FUN_a00a7488(port, 0x1820, 0xffcfffff, 0x300000);
            } else {
                FUN_a00a7488(port, 0x1178, 0xff0000f0, 0x303);
                FUN_a00a7488(port, 0x1578, 0xff0000f0, 0x303);
                FUN_a00a7488(port, 0x1978, 0xff0000f0, 0x303);
                FUN_a00a7424(1, 7, port, 0x101c);
                FUN_a00a7424(1, 7, port, 0x141c);
                FUN_a00a7424(1, 7, port, 0x181c);
                FUN_a00a7488(port, 0x101c, 0xfffffff9, 4);
                FUN_a00a7488(port, 0x141c, 0xfffffff9, 4);
                FUN_a00a7488(port, 0x181c, 0xfffffff9, 4);
                FUN_a00a7488(port, 0x1020, 0xffcfffff, 0x100000);
                FUN_a00a7488(port, 0x1420, 0xffcfffff, 0x100000);
                FUN_a00a7488(port, 0x1820, 0xffcfffff, 0x100000);
            }
        }
    } else {
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a00734c4(s_a0067a98);
    }
    r = FUN_a0073520(port);
    if (r) {
        FUN_a00a7488(port, 0x3614, 0xffffff00, 0);
        FUN_a00a7488(port, 0x3614, 0xffff00ff, 0);
        FUN_a00a7488(port, 0x360c, 0xffff0000, 0x83d0);
        FUN_a00a7488(port, 0x360c, 0xffff, 0x83d00000);
        FUN_a00a7488(port, 0x3610, 0xffff0000, 0x83d0);
        FUN_a00a7488(port, 0x3610, 0xffff, 0x83d00000);
        FUN_a00a7488(port, 0x3614, 0xff00ffff, 0x7c0000);
        FUN_a00a7488(port, 0x3614, 0xffffff, 0xff000000);
        FUN_a00a7488(port, 0x3618, 0xffffff00, 0xff);
        FUN_a00a7488(port, 0x3620, 0xffffff00, 0);
        FUN_a00a7488(port, 0x3620, 0xffff00ff, 0x100);
        FUN_a00a7424(0, 0x1b, port, 0x3604);
        FUN_a00a7488(port, 0x1020, 0xffffff, 0xa2000000);
        FUN_a00a7488(port, 0x23c0, 0xffff00ff, 0x5000);
        FUN_a00a7488(port, 0x27c0, 0xffff00ff, 0x1000);
        FUN_a00a7488(port, 0x2bc0, 0xffff00ff, 0x1000);
        FUN_a00a7488(port, 0x33c0, 0xffff00ff, 0x1000);
    }
    FUN_a00a7424(1, 0x10, port, 0x1004);
    FUN_a00a7424(1, 0x10, port, 0x1404);
    FUN_a00a7424(1, 0x10, port, 0x1804);
    hdmi_PHY_Set_CTLE(port);
    if (r)
        FUN_a0075360(port);
    FUN_a00b1794(10);
    FUN_a00a7424(0, 0x15, port, 0x1900);
    FUN_a00a7424(0, 0x15, port, 0x1500);
    FUN_a00a7424(0, 0x15, port, 0x1100);
    DRV_HDMI_PHY_Clr_EQ_Err(port);
    if (ARR_a807ccc4[port].b8 == 1)
        ARR_a807ccc4[port].w0 = 10;
    else
        ARR_a807ccc4[port].w0 = 10;
    return 0;
}
