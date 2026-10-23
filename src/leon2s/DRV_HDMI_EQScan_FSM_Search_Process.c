/* DRV_HDMI_EQScan_FSM_Search_Process (leon2s 0xa007890c-0xa0078dc8, 1212 bytes), flags -mcpu=v8 -Os -g.
 * u8 port; returns 1. Prints DAT_a0067058 with (char)(port + 'A') and the function name when bit 1 of
 * _DAT_a8078634 is set (every print below is under the same bit). Data: ARR_a807a9f0 = 0x898-byte records
 * (bytes vga[3] at 0, b3[3] at 3, idx[3] at 9, b28, b2a[3], b30, done[3] at 0x31, b34[3], u32 scdc[][3] at
 * 0x38, b896); ARR_a807ccc4 = 12-byte records {w0, w4, b8}; DAT_a00b3ac8 = byte table HDMI_RVGA_TABLE;
 * DAT_a00b3b90 / DAT_a00b3b96 = halfword register numbers per channel (0x1128.., 0x1134..).
 * b8 != 1: w0 = 0xe (with "Goto FSM_EQSCAN_SEARCH_EQTABLE") when any vga byte is <= 0x17, else w0 = 0x10 and
 * b896 = 0.
 * b8 == 1: for each channel ch 0..2 not done: n = 3 when b8 is nonzero, else 1 (b8 reread at each test);
 * idx[ch] < n: FUN_a00a7424(1, 0xf, port, DAT_a00b3b96[ch]) and FUN_a00a7488(port, DAT_a00b3b90[ch],
 * 0xff0fffff, (RVGA[idx[ch]] & 0xf) << 20), print "apply HDMI_RVGA_TABLE"; idx[ch] == n: the index bi of
 * the smallest scdc[i][ch], i < n (first one kept on ties, each step printed), then "RVGA is all fail" and
 * "Best RVGA idx" prints and the same FUN_a00a7488 write with RVGA[bi]. Then FUN_a00787f4(port),
 * DAT_a80761a0[port] = 6, b28 = 1, b30 = 0, b3/b2a/b34 of each channel not done = 0, w0 = 0xb, b30 = 0.
 * Source forms: the limit is '(b8 ? 3u : 1u)' (unsigned compares); the two calls of the apply step each have
 * their own 'if (ch < 3)' (one shared if keeps the masked port across the first call); the function name is
 * a separate static string; the clears are written b3, b2a, b34.
 */
struct EqRec {
    unsigned char vga[3];
    unsigned char b3[3];
    unsigned char _6[3];
    unsigned char idx[3];
    unsigned char _c[0x28 - 0xc];
    unsigned char b28;
    unsigned char _29;
    unsigned char b2a[3];
    unsigned char _2d[3];
    unsigned char b30;
    unsigned char done[3];
    unsigned char b34[3];
    unsigned char _37;
    unsigned int scdc[178][3];
    unsigned char _890[6];
    unsigned char b896;
    unsigned char _897;
};
struct Rec12 { unsigned int w0; unsigned int w4; unsigned char b8; unsigned char pad[3]; };
extern struct EqRec ARR_a807a9f0[];
extern struct Rec12 ARR_a807ccc4[];
extern unsigned char DAT_a80761a0[];
extern unsigned int _DAT_a8078634;
extern const unsigned char DAT_a00b3ac8[];
extern const unsigned short DAT_a00b3b90[];
extern const unsigned short DAT_a00b3b96[];
extern unsigned char DAT_a0067058[];
extern int FUN_a0073044(const void *, ...);
extern void FUN_a00a7424(int, unsigned int, unsigned char, unsigned short);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);
extern void FUN_a00787f4(unsigned char);

static const char fn_[] = "DRV_HDMI_EQScan_FSM_Search_Process";

int DRV_HDMI_EQScan_FSM_Search_Process(unsigned char port)
{
    unsigned char ch = 0;
    unsigned char i;
    unsigned char bi;
    unsigned int best;
    unsigned int v;

    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0067058, (char)(port + 'A'), fn_);
    if (ARR_a807ccc4[port].b8 == 1) {
        for (ch = 0; ch <= 2; ch++) {
            if (ARR_a807a9f0[port].done[ch] == 1)
                continue;
            if (ARR_a807a9f0[port].idx[ch] > (ARR_a807ccc4[port].b8 ? 3u : 1u))
                continue;
            if (ARR_a807a9f0[port].idx[ch] < (ARR_a807ccc4[port].b8 ? 3u : 1u)) {
                if (ch < 3)
                    FUN_a00a7424(1, 0xf, port, DAT_a00b3b96[ch]);
                if (ch < 3)
                    FUN_a00a7488(port, DAT_a00b3b90[ch], 0xff0fffff,
                                 (DAT_a00b3ac8[ARR_a807a9f0[port].idx[ch]] & 0xf) << 20);
                if ((_DAT_a8078634 & 2) != 0)
                    FUN_a0073044("[EQ]: # Port%c, CH%d, apply HDMI_RVGA_TABLE[%d] = 0x%02x\n\n", (char)(port + 'A'),
                                 ch, ARR_a807a9f0[port].idx[ch], DAT_a00b3ac8[ARR_a807a9f0[port].idx[ch]]);
            } else {
                best = ARR_a807a9f0[port].scdc[0][ch];
                bi = 0;
                for (i = 1; i < (ARR_a807ccc4[port].b8 ? 3u : 1u); i++) {
                    v = ARR_a807a9f0[port].scdc[i][ch];
                    if ((_DAT_a8078634 & 2) != 0)
                        FUN_a0073044("[EQ]: # Port%c, CH%d, index = %d  u32TotalSCDC = %ld  vs u8BestVGAIdx = %d  u32BestSCDC = %ld  \n",
                                     (char)(port + 'A'), ch, i, v, bi, best);
                    if (v < best) {
                        best = v;
                        bi = i;
                    }
                }
                if ((_DAT_a8078634 & 2) != 0)
                    FUN_a0073044("[EQ]: # Port%c, CH%d, RVGA is all fail, find Best RVGA !!!!\n", (char)(port + 'A'), ch);
                if ((_DAT_a8078634 & 2) != 0)
                    FUN_a0073044("[EQ]: # Port%c, CH%d, Best RVGA idx = %d, RVGA_Value = 0x%02x\n\n", (char)(port + 'A'),
                                 ch, bi, DAT_a00b3ac8[bi]);
                if (ch < 3)
                    FUN_a00a7488(port, DAT_a00b3b90[ch], 0xff0fffff, (DAT_a00b3ac8[bi] & 0xf) << 20);
            }
        }
        FUN_a00787f4(port);
        DAT_a80761a0[port] = 6;
        ARR_a807a9f0[port].b28 = 1;
        ARR_a807a9f0[port].b30 = 0;
        for (ch = 0; ch <= 2; ch++) {
            if (ARR_a807a9f0[port].done[ch] != 1) {
                ARR_a807a9f0[port].b3[ch] = 0;
                ARR_a807a9f0[port].b2a[ch] = 0;
                ARR_a807a9f0[port].b34[ch] = 0;
            }
        }
        ARR_a807ccc4[port].w0 = 0xb;
        ARR_a807a9f0[port].b30 = 0;
        return 1;
    }
    if (ARR_a807a9f0[port].vga[0] <= 0x17 || ARR_a807a9f0[port].vga[1] <= 0x17 ||
        ARR_a807a9f0[port].vga[2] <= 0x17) {
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044("[EQ]: # Port%c,Goto FSM_EQSCAN_SEARCH_EQTABLE\n", (char)(port + 'A'));
        ARR_a807ccc4[port].w0 = 0xe;
    } else {
        ARR_a807ccc4[port].w0 = 0x10;
        ARR_a807a9f0[port].b896 = 0;
    }
    return 1;
}
