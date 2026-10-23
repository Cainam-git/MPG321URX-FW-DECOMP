/* DRV_HDMI_EQScan_FSM_PHY_PreAEQ (leon2s 0xa0076e68-0xa007731c, 1204 bytes), flags -mcpu=v8 -Os -g.
 * u8 port; returns 0. Prints DAT_a0067058 with (char)(port + 'A') and the function name when bit 1 of
 * _DAT_a8078634 is set (every print below is under the same bit). Data: ARR_a807a9f0 = 0x898-byte records
 * (bytes b3[3] at 3, idx[3] at 9, words w10[3] at 0x10, bytes b2a[3], b2d[3], b30); ARR_a807ccc4 = 12-byte
 * records {w0, w4, b8}; the 4-byte tables {rct, -, u16 cft} DAT_a00b3c0c (b8 != 0), DAT_a00b3bd4 (b8 == 0)
 * and DAT_a00b3b9c (b8 == 0, FUN_a0073520(port) != 0 and DAT_a8078988[port] == 1); halfword register numbers
 * per channel DAT_a00b3b04 (0x1170..), DAT_a00b3b0a (0x117c..), DAT_a00b3b78 (0x1178..).
 * For each channel ch 0..2: b2d[ch] == 1 prints "PreRVGA is done, bypass PreAEQ". Else, while b3[ch] is
 * below 10 (b8 != 0) or 14: b3[ch] == 0 clears w10[ch]; FUN_a00a7488(port, reg, mask, value) writes
 * 0x2f0000 / 0x4f0000 into bits 16..23 of DAT_a00b3b04[ch] / DAT_a00b3b0a[ch] and, from entry b3[ch] of the
 * table, (rct & 0xf) | (cft << 8) into DAT_a00b3b78[ch] (mask 0xff0000f0), then prints the entry. Otherwise
 * prints "preAEQ done for RVGAidx"; while idx[ch] < 3 (b8 != 0) or 1 it increments idx[ch], prints it and
 * clears b3[ch]; b2a[ch] = 1.
 * All three b2a == 1: b30 = 0, b2a[ch] = 0 for each channel whose idx[ch] is below the limit, w0 = 6.
 * Otherwise: w0 = 0xc, DAT_a80761a0[port] = 1, b30 = 0 and DRV_HDMI_PHY_Clr_EQ_Err(port).
 * Source forms: the limits are '(b8 ? 10u : 14u)' / '(b8 ? 3u : 1u)' (unsigned compares, b8 reread at
 * each test); the function name is a separate static string.
 */
struct EqRec {
    unsigned char vga[3];
    unsigned char b3[3];
    unsigned char _6[3];
    unsigned char idx[3];
    unsigned char _c[4];
    unsigned int w10[3];
    unsigned char _1c[0x28 - 0x1c];
    unsigned char b28;
    unsigned char _29;
    unsigned char b2a[3];
    unsigned char b2d[3];
    unsigned char b30;
    unsigned char done[3];
    unsigned char b34[3];
    unsigned char _37;
    unsigned int scdc[178][3];
    unsigned char _890[8];
};
struct Rec12 { unsigned int w0; unsigned int w4; unsigned char b8; unsigned char pad[3]; };
struct AeqEnt { unsigned char rct; unsigned char _1; unsigned short cft; };
extern struct EqRec ARR_a807a9f0[];
extern struct Rec12 ARR_a807ccc4[];
extern unsigned char DAT_a80761a0[];
extern unsigned char DAT_a8078988[];
extern unsigned int _DAT_a8078634;
extern const struct AeqEnt DAT_a00b3b9c[];
extern const struct AeqEnt DAT_a00b3bd4[];
extern const struct AeqEnt DAT_a00b3c0c[];
extern const unsigned short DAT_a00b3b04[];
extern const unsigned short DAT_a00b3b0a[];
extern const unsigned short DAT_a00b3b78[];
extern unsigned char DAT_a0067058[];
extern int FUN_a0073044(const void *, ...);
extern unsigned char FUN_a0073520(unsigned char);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);
extern void DRV_HDMI_PHY_Clr_EQ_Err(unsigned int);

static const char fn_[] = "DRV_HDMI_EQScan_FSM_PHY_PreAEQ";

int DRV_HDMI_EQScan_FSM_PHY_PreAEQ(unsigned char port)
{
    const struct AeqEnt *tbl;
    unsigned char ch;
    unsigned short cft;
    unsigned char rct;

    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0067058, (char)(port + 'A'), fn_);
    tbl = ARR_a807ccc4[port].b8 ? DAT_a00b3c0c : DAT_a00b3bd4;
    if (FUN_a0073520(port)) {
        if (ARR_a807ccc4[port].b8 == 0 && DAT_a8078988[port] == 1)
            tbl = DAT_a00b3b9c;
    }
    for (ch = 0; ch <= 2; ch++) {
        if (ARR_a807a9f0[port].b2d[ch] == 1) {
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044("[EQ]: # Port%c, CH%d, -------2 PreRVGA is done, bypass PreAEQ------- \n\n",
                             (char)(port + 'A'), ch);
            continue;
        }
        if (ARR_a807a9f0[port].b3[ch] < (ARR_a807ccc4[port].b8 ? 10u : 14u)) {
            if (ARR_a807a9f0[port].b3[ch] == 0)
                ARR_a807a9f0[port].w10[ch] = 0;
            if (ch < 3) {
                FUN_a00a7488(port, DAT_a00b3b04[ch], 0xff00ffff, 0x2f0000);
                FUN_a00a7488(port, DAT_a00b3b0a[ch], 0xff00ffff, 0x4f0000);
            }
            cft = tbl[ARR_a807a9f0[port].b3[ch]].cft;
            rct = tbl[ARR_a807a9f0[port].b3[ch]].rct;
            if (ch < 3)
                FUN_a00a7488(port, DAT_a00b3b78[ch], 0xff0000f0, (rct & 0xf) | (cft << 8));
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044("[EQ]: # Port%c, CH%d, preAEQIdx = %d, RCT = 0x%02x , CFT = 0x%04x\n",
                             (char)(port + 'A'), ch, ARR_a807a9f0[port].b3[ch], rct, cft);
        } else {
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044("[EQ]: # Port%c, CH%d, preAEQ done for RVGAidx (%d) !!!\n",
                             (char)(port + 'A'), ch, ARR_a807a9f0[port].idx[ch]);
            if (ARR_a807a9f0[port].idx[ch] < (ARR_a807ccc4[port].b8 ? 3u : 1u)) {
                ARR_a807a9f0[port].idx[ch]++;
                if ((_DAT_a8078634 & 2) != 0)
                    FUN_a0073044("[EQ]: # Port%c, CH%d, next preRVGAIdx = %d\n",
                                 (char)(port + 'A'), ch, ARR_a807a9f0[port].idx[ch]);
                ARR_a807a9f0[port].b3[ch] = 0;
            }
            ARR_a807a9f0[port].b2a[ch] = 1;
        }
    }
    if (ARR_a807a9f0[port].b2a[0] == 1 && ARR_a807a9f0[port].b2a[1] == 1 && ARR_a807a9f0[port].b2a[2] == 1) {
        ARR_a807a9f0[port].b30 = 0;
        for (ch = 0; ch <= 2; ch++) {
            if (ARR_a807a9f0[port].idx[ch] < (ARR_a807ccc4[port].b8 ? 3u : 1u))
                ARR_a807a9f0[port].b2a[ch] = 0;
        }
        ARR_a807ccc4[port].w0 = 6;
    } else {
        ARR_a807ccc4[port].w0 = 0xc;
        DAT_a80761a0[port] = 1;
        ARR_a807a9f0[port].b30 = 0;
        DRV_HDMI_PHY_Clr_EQ_Err(port);
    }
    return 0;
}
