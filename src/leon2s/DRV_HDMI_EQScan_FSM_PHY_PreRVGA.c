/* DRV_HDMI_EQScan_FSM_PHY_PreRVGA (leon2s 0xa0076180-0xa0076e68, 3304 bytes), flags -mcpu=v8 -Os -g -msoft-float.
 * u8 port; returns 0 or 1. Every print is under bit 1 of _DAT_a8078634. Data: ARR_a807a9f0 = 0x898-byte records
 * (rvga[3] at +9, done flags b2d[3] at +0x2d, counter b30, word table tbl[rvga][pre][ch] at +0x80, the two
 * tables t470 / t668 [6][7][3] and halfwords h860[6][3] read by RCT_Value, bytes b890[3] / b893[3]);
 * ARR_a807ccc4 = 12-byte records {w0, w4, b8}; DAT_a00b3ac8 = RVGA byte table; DAT_a00b3b90 / DAT_a00b3b96 =
 * halfword register numbers per channel. Three local tables [6][3] (lengths, indexes, words) are cleared with
 * FUN_a00b15ac. Prints DAT_a0066df8 (port letter, name, b30), then for ch 0..2:
 * - b2d[ch] == 1: prints "PreRVGA is done" and goes to the next channel.
 * - rvga[ch] < (b8 ? 3 : 1): FUN_a00a7424(1, 0xf, port, DAT_a00b3b96[ch]); FUN_a00a7488(port, DAT_a00b3b90[ch],
 *   0xff0fffff, 0xf00000 when FUN_a0073520(port) is non-zero, else (DAT_a00b3ac8[rvga[ch]] & 0xf) << 20); prints
 *   bits 20..23 of FUN_a00a7314(port, DAT_a00b3b90[ch]) and goes to the next channel.
 * - otherwise, for each RVGA index i < (b8 ? 3 : 1) and pre <= (b8 ? 9 : 13): a tbl[i][pre][ch] value below 0x10
 *   counts len[i][ch] and lo (pre / n == 0, n = b8 ? 5 : 7) or hi; the value is copied to t470[i][pre % n][ch]
 *   (pre / n == 0) or t668[i][pre % n][ch]; then h860[i][ch] = b8 != 0 || hi >= lo, and lo, hi = 0. Prints the
 *   lengths, picks the index bi of the largest len[i][ch] (first one kept on ties, each step printed) and prints
 *   it. With bi == 0 and a zero length: per index i the smallest t470 (b8 == 0) or t668 [i][j][ch], j <= (b8 ?
 *   4 : 6), goes to the word table and its j to the index table, then bi = the index of the smallest of those
 *   words (each step printed with the j and bidx values left by the inner loop). Prints bi, stores b893[ch] =
 *   the largest length and b890[ch] = bi; RCT_Value(port, ch) == 0 sets w0 = 0 and returns 0; else the same two
 *   register writes with DAT_a00b3ac8[bi] and b2d[ch] = 1.
 * After the loop: b30 = 0; w0 = 8 after EQ_handler_2(port) when all three b2d are 1, else 7; returns 1.
 * Source forms: old-style (K&R) definition with an unsigned char parameter (zero-extended at each use); the
 * limits are written '(b8 ? 3u : 1u)', '(b8 ? 9u : 0xdu)', '(b8 ? 4u : 6u)' and the divisor '(b8 ? 5u : 7u)'
 * (re-read at each use); the RVGA register value is an if/else into its own variable; the two zero tests are
 * nested ifs; the first row word is read with j = 0 before the j loop; the index byte is stored before the
 * word; the "u32TotalSCDC" format string is the same literal as in RCT_Value (one copy in the image).
 */
struct EqRec {
    unsigned char _0[9];
    unsigned char rvga[3];
    unsigned char _c[0x2d - 0xc];
    unsigned char b2d[3];
    unsigned char b30;
    unsigned char _31[0x80 - 0x31];
    unsigned int tbl[3][14][3];
    unsigned char _278[0x470 - 0x278];
    unsigned int t470[6][7][3];
    unsigned int t668[6][7][3];
    unsigned short h860[6][3];
    unsigned char _884[0x890 - 0x884];
    unsigned char b890[3];
    unsigned char b893[3];
    unsigned char _896[2];
};
struct Rec12 { unsigned int w0; unsigned int w4; unsigned char b8; unsigned char pad[3]; };
extern struct EqRec ARR_a807a9f0[];
extern struct Rec12 ARR_a807ccc4[];
extern unsigned int _DAT_a8078634;
extern const unsigned char DAT_a00b3ac8[];
extern const unsigned short DAT_a00b3b90[];
extern const unsigned short DAT_a00b3b96[];
extern unsigned char DAT_a0066df8[];
extern int FUN_a0073044(const void *, ...);
extern void *FUN_a00b15ac(unsigned char *dst, unsigned char v, int n);
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);
extern void FUN_a00a7424(int, unsigned int, unsigned char, unsigned short);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);
extern unsigned char FUN_a0073520(unsigned char);
extern unsigned char RCT_Value(int, int);
extern void EQ_handler_2(unsigned int port);

static const char fn_[] = "DRV_HDMI_EQScan_FSM_PHY_PreRVGA";

int DRV_HDMI_EQScan_FSM_PHY_PreRVGA(port)
    unsigned char port;
{
    unsigned char len[6][3];
    unsigned char idx[6][3];
    unsigned int scdc[6][3];
    unsigned char ch = 0;
    unsigned char i;
    unsigned char pre;
    unsigned char j = 0;
    unsigned char bidx = 0;
    unsigned char lo = 0;
    unsigned char hi = 0;
    unsigned char bi;
    unsigned int best;
    unsigned int v;
    unsigned int m;
    unsigned int r;

    FUN_a00b15ac((unsigned char *)len, 0, sizeof(len));
    FUN_a00b15ac((unsigned char *)idx, 0, sizeof(idx));
    FUN_a00b15ac((unsigned char *)scdc, 0, sizeof(scdc));
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0066df8, (char)(port + 'A'), fn_, ARR_a807a9f0[port].b30);
    for (; ch < 3; ch++) {
        if (ARR_a807a9f0[port].b2d[ch] == 1) {
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044("[EQ]: # Port%c, CH%d, -------1 PreRVGA is done, bypass PreAEQ------- \n",
                             (char)(port + 'A'), ch);
            continue;
        }
        if (ARR_a807a9f0[port].rvga[ch] < (ARR_a807ccc4[port].b8 ? 3u : 1u)) {
            if (ch < 3)
                FUN_a00a7424(1, 0xf, port, DAT_a00b3b96[ch]);
            if (FUN_a0073520(port)) {
                if (ch < 3)
                    FUN_a00a7488(port, DAT_a00b3b90[ch], 0xff0fffff, 0xf00000);
            } else {
                if (ch < 3)
                    FUN_a00a7488(port, DAT_a00b3b90[ch], 0xff0fffff,
                                 (DAT_a00b3ac8[ARR_a807a9f0[port].rvga[ch]] & 0xf) << 20);
            }
            if ((_DAT_a8078634 & 2) != 0) {
                if (ch < 3)
                    r = (FUN_a00a7314(port, DAT_a00b3b90[ch]) >> 20) & 0xf;
                else
                    r = 0;
                FUN_a0073044("[EQ]: # Port%c, CH%d,  RVGA Reg value = 0x%02lx\n\n", (char)(port + 'A'), ch, r);
            }
            continue;
        }
        for (i = 0; i < (ARR_a807ccc4[port].b8 ? 3u : 1u); i++) {
            for (pre = 0; pre <= (ARR_a807ccc4[port].b8 ? 9u : 0xdu); pre++) {
                if (ARR_a807a9f0[port].tbl[i][pre][ch] < 0x10) {
                    len[i][ch]++;
                    if (pre / (ARR_a807ccc4[port].b8 ? 5u : 7u) == 0)
                        lo++;
                    else
                        hi++;
                }
                if (pre / (ARR_a807ccc4[port].b8 ? 5u : 7u) == 0)
                    ARR_a807a9f0[port].t470[i][pre % (ARR_a807ccc4[port].b8 ? 5u : 7u)][ch] =
                        ARR_a807a9f0[port].tbl[i][pre][ch];
                else
                    ARR_a807a9f0[port].t668[i][pre % (ARR_a807ccc4[port].b8 ? 5u : 7u)][ch] =
                        ARR_a807a9f0[port].tbl[i][pre][ch];
            }
            ARR_a807a9f0[port].h860[i][ch] = ARR_a807ccc4[port].b8 != 0 || hi >= lo;
            hi = 0;
            lo = 0;
        }
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044("[EQ]: # Port%c : =========================================\n", (char)(port + 'A'));
        for (i = 0; i < (ARR_a807ccc4[port].b8 ? 3u : 1u); i++) {
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044("[EQ]: RVGA : 0x%02x =>\n", i);
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044("[EQ]: Ch%d , length = 0x%d\n", ch, len[i][ch]);
        }
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044("[EQ]: # Port%c, CH%d, u8RVGA_Index = 0  , u32Length = %d  \n", (char)(port + 'A'), ch,
                         len[0][ch]);
        best = len[0][ch];
        bi = 0;
        for (i = 1; i < (ARR_a807ccc4[port].b8 ? 3u : 1u); i++) {
            v = len[i][ch];
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044("[EQ]: # Port%c, CH%d, index = %d  u32Length = %ld  / u8BestRVGAIdx = %d  u32BestLength = %ld  \n",
                             (char)(port + 'A'), ch, i, v, bi, best);
            if (v > best) {
                best = v;
                bi = i;
            }
        }
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044("[EQ]: # Port%c, CH%d, 1-th round, u8BestRVGAIdx = %d  u32BestLength = %ld  \n",
                         (char)(port + 'A'), ch, bi, best);
        if (bi == 0) {
            if (best == 0) {
                for (i = 0; i < (ARR_a807ccc4[port].b8 ? 3u : 1u); i++) {
                    bidx = 0;
                    j = 0;
                    if (ARR_a807ccc4[port].b8 == 0)
                        m = ARR_a807a9f0[port].t470[i][j][ch];
                    else
                        m = ARR_a807a9f0[port].t668[i][j][ch];
                    for (j = 0; j <= (ARR_a807ccc4[port].b8 ? 4u : 6u); j++) {
                        if (ARR_a807ccc4[port].b8 == 0)
                            v = ARR_a807a9f0[port].t470[i][j][ch];
                        else
                            v = ARR_a807a9f0[port].t668[i][j][ch];
                        if ((_DAT_a8078634 & 2) != 0)
                            FUN_a0073044("[EQ]: # Port%c, CH%d, index = %d  u32TotalSCDC = %ld  / u8BestRCTIdx = %d  u32BestSCDC = %ld  \n",
                                     (char)(port + 'A'), ch, j, v, bidx, m);
                        if (v < m) {
                            bidx = j;
                            m = v;
                        }
                    }
                    idx[i][ch] = bidx;
                    scdc[i][ch] = m;
                }
                m = scdc[0][ch];
                bi = 0;
                for (i = 0; i < (ARR_a807ccc4[port].b8 ? 3u : 1u); i++) {
                    v = scdc[i][ch];
                    if ((_DAT_a8078634 & 2) != 0)
                        FUN_a0073044("[EQ]: # Port%c, CH%d, index = %d  u32TotalSCDC = %ld  / u8BestRCTIdx = %d  u32BestSCDC = %ld  \n",
                                 (char)(port + 'A'), ch, j, v, bidx, m);
                    if (v < m) {
                        m = v;
                        bi = i;
                    }
                }
            }
        }
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044("[EQ]: # Port%c, CH%d, 2-th round, u8BestRVGAIdx = %d  u32BestLength = %ld  \n",
                         (char)(port + 'A'), ch, bi, best);
        ARR_a807a9f0[port].b893[ch] = best;
        ARR_a807a9f0[port].b890[ch] = bi;
        if (RCT_Value(port, ch) == 0) {
            ARR_a807ccc4[port].w0 = 0;
            return 0;
        }
        if (ch < 3)
            FUN_a00a7424(1, 0xf, port, DAT_a00b3b96[ch]);
        if (FUN_a0073520(port)) {
            if (ch < 3)
                FUN_a00a7488(port, DAT_a00b3b90[ch], 0xff0fffff, 0xf00000);
        } else {
            if (ch < 3)
                FUN_a00a7488(port, DAT_a00b3b90[ch], 0xff0fffff, (DAT_a00b3ac8[bi] & 0xf) << 20);
        }
        ARR_a807a9f0[port].b2d[ch] = 1;
    }
    ARR_a807a9f0[port].b30 = 0;
    if (ARR_a807a9f0[port].b2d[0] == 1 && ARR_a807a9f0[port].b2d[1] == 1 && ARR_a807a9f0[port].b2d[2] == 1) {
        EQ_handler_2(port);
        ARR_a807ccc4[port].w0 = 8;
    } else {
        ARR_a807ccc4[port].w0 = 7;
    }
    return 1;
}
