/* RCT_Value (leon2s 0xa0075858-0xa0075ffc, 1956 bytes), flags -mcpu=v8 -Os -g.
 * u8 port, u8 ch; returns (u8) 0 or 1; called by DRV_HDMI_EQScan_FSM_PHY_PreRVGA. Every print is under bit 1 of
 * _DAT_a8078634. Data: ARR_a807a9f0 = 0x898-byte records (b34[3] at 0x34, two u32 tables [6][7][3] at 0x470
 * and 0x668, halfwords h860[6][3], per-channel {rct byte, halfword v} at 0x884, index bytes b890[3]);
 * ARR_a807ccc4 = 12-byte records {w0, w4, b8}; DAT_a8078988[port] byte flags; DAT_a00b3b80 / DAT_a00b3b88 =
 * byte tables {6, 8, 0xa, 0xc, 0xf} / {1, 3, 5, 7, 9, 0xc, 0xf}. n = b8 ? 4 : 6 (re-read at each test).
 * k = b890[ch]. h860[k][ch] == 0: v = 0 when b8 == 0 and the flag is 1, else 0xff; table base = t470[k],
 * byte table DAT_a00b3b88. Else v = 0xff / 0xfff the same way, base = t668[k], byte table DAT_a00b3b80 when
 * b8 != 0, else DAT_a00b3b88. Over i = 0..n it notes whether every base[i][ch] is 0, every one non-zero, and
 * the count of zeros. With b8 == 0 and the flag 0: the flag is set when all are non-zero, or when fewer
 * than 3 are zero and every t668[k][i][ch] (i = 0..n) is non-zero; a set flag prints "Go Into Error
 * Handing" and returns 0. Otherwise it picks the RCT byte: all zero: ("all port error free")
 * (tbl[0] + tbl[n]) >> 1; all non-zero: tbl[index of the smallest base[i][ch]] (first one kept on ties,
 * each step printed); else the first i from 0 up and the first i from n down to 1 with base[i][ch] < 0x10
 * (0 when none; t668 values printed) give (tbl[u8Left] + tbl[u8Right]) >> 1. Stores the RCT byte and v to
 * the channel's entry at 0x884, sets b34[ch] = 1, returns 1.
 * Source forms: old-style (K&R) definition with unsigned char parameters (the arguments arrive as int and
 * are zero-extended at each use, port copied out of %i0); the RCT byte is computed into a local before the
 * two stores, written rct first, then v; the t668 base for the second scan is a separate pointer taken
 * before the first scan.
 * Compiler aid: __builtin_expect(all_err == 1, 1) emits no instructions; it places the flag store of that
 * arm at the shared store after the second scan, as in the firmware.
 */
struct RctRes { unsigned char rct; unsigned char _1; unsigned short v; };
struct EqRec {
    unsigned char _0[0x34];
    unsigned char b34[3];
    unsigned char _37[0x470 - 0x37];
    unsigned int t470[6][7][3];
    unsigned int t668[6][7][3];
    unsigned short h860[6][3];
    struct RctRes res[3];
    unsigned char b890[3];
    unsigned char _893[0x898 - 0x893];
};
struct Rec12 { unsigned int w0; unsigned int w4; unsigned char b8; unsigned char pad[3]; };
extern struct EqRec ARR_a807a9f0[];
extern struct Rec12 ARR_a807ccc4[];
extern unsigned char DAT_a8078988[];
extern unsigned int _DAT_a8078634;
extern const unsigned char DAT_a00b3b80[];
extern const unsigned char DAT_a00b3b88[];
extern int FUN_a0073044(const char *, ...);

unsigned char RCT_Value(port, ch)
    unsigned char port, ch;
{
    unsigned int (*base)[3];
    unsigned int (*alt)[3];
    const unsigned char *tbl;
    unsigned short val;
    unsigned char all_zero, all_err, ok, cnt, i;
    unsigned char u8Left, u8Right, j, rct;
    unsigned int u32BestSCDC, u32TotalSCDC;

    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044("[EQ]: # Port%c, Ch%d, ------- find best R/C value ------- , (%d)\n", (char)(port + 'A'), ch,
                     ARR_a807a9f0[port].h860[ARR_a807a9f0[port].b890[ch]][ch]);
    if (ARR_a807a9f0[port].h860[ARR_a807a9f0[port].b890[ch]][ch] == 0) {
        if (ARR_a807ccc4[port].b8 == 0 && DAT_a8078988[port] == 1)
            val = 0;
        else
            val = 0xff;
        base = ARR_a807a9f0[port].t470[ARR_a807a9f0[port].b890[ch]];
        tbl = DAT_a00b3b88;
    } else {
        if (ARR_a807ccc4[port].b8 == 0 && DAT_a8078988[port] == 1)
            val = 0xff;
        else
            val = 0xfff;
        base = ARR_a807a9f0[port].t668[ARR_a807a9f0[port].b890[ch]];
        if (ARR_a807ccc4[port].b8 != 0)
            tbl = DAT_a00b3b80;
        else
            tbl = DAT_a00b3b88;
    }
    alt = ARR_a807a9f0[port].t668[ARR_a807a9f0[port].b890[ch]];
    all_zero = 1;
    all_err = 1;
    cnt = 0;
    for (i = 0; i <= (ARR_a807ccc4[port].b8 ? 4u : 6u); i++) {
        if (base[i][ch] == 0) {
            all_err = 0;
            cnt++;
        } else {
            all_zero = 0;
        }
    }
    if (ARR_a807ccc4[port].b8 == 0 && DAT_a8078988[port] == 0) {
        ok = 1;
        if (__builtin_expect(all_err == 1, 1)) {
            DAT_a8078988[port] = 1;
        } else {
            for (i = 0; i <= (ARR_a807ccc4[port].b8 ? 4u : 6u); i++)
                if (alt[i][ch] == 0)
                    ok = 0;
            if (ok == 1 && cnt < 3)
                DAT_a8078988[port] = 1;
        }
        if (DAT_a8078988[port] == 1) {
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044("[EQ]: # Port%c, Ch%d , ------- Go Into Error Handing ------- \n", (char)(port + 'A'), ch);
            return 0;
        }
    }
    if (all_zero) {
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044("[EQ]: # Port%c, Ch%d , ------- all port error free ------- \n", (char)(port + 'A'), ch);
        rct = (tbl[0] + tbl[ARR_a807ccc4[port].b8 ? 4u : 6u]) >> 1;
        ARR_a807a9f0[port].res[ch].rct = rct;
        ARR_a807a9f0[port].res[ch].v = val;
        ARR_a807a9f0[port].b34[ch] = 1;
        return 1;
    }
    u8Left = 0;
    u8Right = 0;
    if (all_err) {
        u32BestSCDC = base[0][ch];
        for (j = 1; j <= (ARR_a807ccc4[port].b8 ? 4u : 6u); j++) {
            u32TotalSCDC = base[j][ch];
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044("[EQ]: # Port%c, CH%d, index = %d  u32TotalSCDC = %ld  / u8BestRCTIdx = %d  u32BestSCDC = %ld  \n",
                             (char)(port + 'A'), ch, j, u32TotalSCDC, u8Left, u32BestSCDC);
            if (u32TotalSCDC < u32BestSCDC) {
                u32BestSCDC = u32TotalSCDC;
                u8Left = j;
            }
        }
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044("[EQ]: # Port%c, CH%d, Best RCT idx = %d, RCT_Value = 0x%02x\n\n", (char)(port + 'A'), ch, u8Left,
                         tbl[u8Left]);
        rct = tbl[u8Left];
        ARR_a807a9f0[port].res[ch].rct = rct;
        ARR_a807a9f0[port].res[ch].v = val;
        ARR_a807a9f0[port].b34[ch] = 1;
        return 1;
    }
    for (i = 0; i <= (ARR_a807ccc4[port].b8 ? 4u : 6u); i++) {
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044("[EQ]: # Port%c, CH%d, L RCTidx = %d, SDCD = 0x%04lx \n\n", (char)(port + 'A'), ch, i,
                         ARR_a807a9f0[port].t668[ARR_a807a9f0[port].b890[ch]][i][ch]);
        if (base[i][ch] < 0x10) {
            u8Left = i;
            break;
        }
    }
    for (i = ARR_a807ccc4[port].b8 ? 4u : 6u; i != 0; i--) {
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044("[EQ]: # Port%c, CH%d, R RCTidx = %d, SDCD = 0x%04lx \n\n", (char)(port + 'A'), ch, i,
                         ARR_a807a9f0[port].t668[ARR_a807a9f0[port].b890[ch]][i][ch]);
        if (base[i][ch] < 0x10) {
            u8Right = i;
            break;
        }
    }
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044("[EQ]: # Port%c, CH%d, u8Left = %d, u8Right = %d\n\n", (char)(port + 'A'), ch, u8Left, u8Right);
    rct = (tbl[u8Left] + tbl[u8Right]) >> 1;
    ARR_a807a9f0[port].res[ch].rct = rct;
    ARR_a807a9f0[port].res[ch].v = val;
    ARR_a807a9f0[port].b34[ch] = 1;
    return 1;
}
