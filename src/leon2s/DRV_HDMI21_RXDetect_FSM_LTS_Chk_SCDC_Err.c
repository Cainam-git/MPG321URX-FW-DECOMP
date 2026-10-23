/* DRV_HDMI21_RXDetect_FSM_LTS_Chk_SCDC_Err (leon2s 0xa0098e88-0xa0099560, 1752 bytes), flags -mcpu=v8 -Os -g.
 * Ports 0 and 1 only (p = (u8)port, phy = 2 for port 0, 3 for port 1); returns 0. Data: state words
 * DAT_a807d648[p]; the 0xb0-byte record DAT_a807d680[p] (byte 0 = 3 or 4 lane mode, byte 2 = rate, u16
 * rc[4][2] at +0x1a, fail counter byte +0x2b, word +0x30 = last state); regs = word +0x18 of the 0x34-byte
 * record DAT_a807db00[p] (register block); the per-lane bytes DAT_a807cc50[4] / DAT_a807cc60[4]; debug flags
 * DAT_a8078634 (bit 11: "[HDMI21]" lines, bit 1: "[EQ]" lines).
 * - When the state differs from word +0x30: prints "=%s=" with the function name and copies it.
 * - FUN_a008d800() > 0x82 and bits 15..8 of regs word 0xb0 not 0xff: prints DAT_a0069dc8, sets those bits
 *   to 0xff, state 3, return.
 * - Bits 27..24 of regs word 0x90 != byte 2: prints DAT_a0069e08, state 3, and when FUN_a008d800() > 0x82
 *   sets bits 15..8 of regs word 0xb0 to 0xff; return.
 * - Clears rc[i][0..1] for i below byte 0. Then repeatedly: in 3 / 4 lane mode, when bits 27..24 of
 *   FUN_a00a7314(phy, 0x2e60) are not 7 / 0xf, the fail counter is incremented and printed; at 3 it is
 *   cleared, DRV_HDMI21_PHY_PICDR_Reset(phy) runs and the function returns; otherwise the counter is cleared.
 *   err = DRV_HDMI21_RX_SCDC_Chk_Err(p) is printed ("CED_ALL"); rate 6 prints "CED Compare bypass" and ends
 *   the loop; err == 0 ends it; else ok = 1 and for each lane i < 4 while ok: when bit i of err is set both
 *   cc50[i] and cc60[i] are incremented; either above 1 clears ok. ok still set: FUN_a007ab94(phy),
 *   DRV_HDMI21_Set_PHY_PreAEQ(phy, 1) and the next pass; else the loop ends.
 * - After a cleared ok: rate 1 prints "SCDC Compare bypass"; otherwise the local u16BestSCDCErrCnt[i] =
 *   rc[i][0], u8BestRCIdx[i] = 0; for index 1 of each lane: cc50[i] == 0 prints the bypass line, else
 *   u16SCDCErrCnt[i] = rc[i][1] is printed with the best values and a smaller count selects index 1; cc50[i]
 *   and cc60[i] = u8BestRCIdx[i]; the rc values of both indices are printed per lane; FUN_a007ab94(phy),
 *   DRV_HDMI21_Set_PHY_PreAEQ(phy, 1).
 * - Ending with err == 0 or ok cleared: state 9 and word 0 of the 0x18-byte record DAT_a807d650[p] = 0.
 * The local array names are the ones in the firmware's format string DAT_a0069f78.
 * Source forms: the loops over the four lanes test the inlined helper lane_ok(i) (the inlined call keeps the
 * exit test at the loop bottom with the address arithmetic of the body in it); the lane loop of the error
 * count tests 'i < 4 && ok'; the 3 / 4 lane blocks have the counting arm first; p is assigned from port again
 * after the first state test and at the top of each pass; the register block pointer is volatile unsigned
 * long (its alias set lets the state store move between the register read and write in the first branch).
 */
struct Port {
    unsigned char _00[0x18];
    volatile unsigned long *regs;
    unsigned char _1c[0x34 - 0x1c];
};
struct Rec {
    unsigned char n;
    unsigned char _01;
    unsigned char mode;
    unsigned char _03[0x1a - 3];
    unsigned short rc[4][2];
    unsigned char _2a;
    unsigned char fail;
    unsigned char _2c[0x30 - 0x2c];
    unsigned int state;
    unsigned char _34[0xb0 - 0x34];
};
struct eq_state {
    unsigned int st;
    unsigned char _04[0x18 - 4];
};

extern struct Port DAT_a807db00[];
extern struct Rec DAT_a807d680[];
extern unsigned int DAT_a807d648[];
extern struct eq_state DAT_a807d650[];
extern unsigned int DAT_a8078634;
extern unsigned char DAT_a807cc50[];
extern unsigned char DAT_a807cc60[];
extern const char DAT_a0067868[], s_a00b4338[], s_a0069dc8[], s_a0069e08[], s_a0069e38[], s_a0069e78[],
    s_a0069eb8[], s_a0069ef0[], s_a0069f18[], s_a0069f38[], s_a0069f78[], s_a0069ff0[];

extern unsigned char FUN_a008d800(void);
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);
extern int FUN_a0073044(const char *, ...);
extern int FUN_a00734c4(const char *);
extern void DRV_HDMI21_PHY_PICDR_Reset(unsigned char);
extern int DRV_HDMI21_RX_SCDC_Chk_Err(unsigned int);
extern void FUN_a007ab94(unsigned char);
extern void DRV_HDMI21_Set_PHY_PreAEQ(unsigned char, unsigned char);

static inline int lane_ok(unsigned char lane)
{
    return lane < 4;
}

int DRV_HDMI21_RXDetect_FSM_LTS_Chk_SCDC_Err(unsigned int port)
{
    unsigned char p = port;
    unsigned char ok = 0;
    unsigned char phy;
    unsigned char err;
    unsigned char i;
    unsigned char j;

    if (p == 0)
        phy = 2;
    else if (p == 1)
        phy = 3;
    else
        return 0;

    if (DAT_a807d648[p] != DAT_a807d680[p].state) {
        if (DAT_a8078634 & 0x800)
            FUN_a0073044(DAT_a0067868, s_a00b4338);
        DAT_a807d680[p].state = DAT_a807d648[p];
    }
    if (FUN_a008d800() > 0x82 && ((DAT_a807db00[p].regs[0xb0 / 4] >> 8) & 0xff) != 0xff) {
        if (DAT_a8078634 & 0x800)
            FUN_a00734c4(s_a0069dc8);
        DAT_a807d648[p] = 3;
        DAT_a807db00[p].regs[0xb0 / 4] = (DAT_a807db00[p].regs[0xb0 / 4] & 0xffff00ff) | 0xff00;
        return 0;
    }
    p = port;
    if (((DAT_a807db00[p].regs[0x90 / 4] >> 24) & 0xf) != DAT_a807d680[p].mode) {
        if (DAT_a8078634 & 0x800)
            FUN_a00734c4(s_a0069e08);
        DAT_a807d648[p] = 3;
        if (FUN_a008d800() > 0x82)
            DAT_a807db00[p].regs[0xb0 / 4] = (DAT_a807db00[p].regs[0xb0 / 4] & 0xffff00ff) | 0xff00;
        return 0;
    }
    for (i = 0; i < DAT_a807d680[p].n; i++) {
        DAT_a807d680[p].rc[i][0] = 0;
        DAT_a807d680[p].rc[i][1] = 0;
    }
    for (;;) {
        p = port;
        if (DAT_a807d680[p].n == 3) {
            if (((FUN_a00a7314(phy, 0x2e60) >> 24) & 0xf) != 7) {
                DAT_a807d680[p].fail++;
                if (DAT_a8078634 & 0x800)
                    FUN_a0073044(s_a0069e38, DAT_a807d680[p].fail);
                if (DAT_a807d680[p].fail == 3) {
                    DAT_a807d680[p].fail = 0;
                    DRV_HDMI21_PHY_PICDR_Reset(phy);
                    return 0;
                }
            } else {
                DAT_a807d680[p].fail = 0;
            }
        } else if (DAT_a807d680[p].n == 4) {
            if (((FUN_a00a7314(phy, 0x2e60) >> 24) & 0xf) != 0xf) {
                DAT_a807d680[p].fail++;
                if (DAT_a8078634 & 0x800)
                    FUN_a0073044(s_a0069e78, DAT_a807d680[p].fail);
                if (DAT_a807d680[p].fail == 3) {
                    DAT_a807d680[p].fail = 0;
                    DRV_HDMI21_PHY_PICDR_Reset(phy);
                    return 0;
                }
            } else {
                DAT_a807d680[p].fail = 0;
            }
        }
        err = DRV_HDMI21_RX_SCDC_Chk_Err(p);
        if (DAT_a8078634 & 0x800)
            FUN_a0073044(s_a0069eb8, err);
        if (DAT_a807d680[p].mode == 6) {
            if (DAT_a8078634 & 0x800)
                FUN_a00734c4(s_a0069ef0);
            goto done;
        }
        if (err == 0)
            goto done;
        ok = 1;
        for (i = 0; i < 4 && ok; i++) {
            if ((err >> i) & 1) {
                DAT_a807cc50[i]++;
                DAT_a807cc60[i]++;
            }
            if (DAT_a807cc50[i] > 1 || DAT_a807cc60[i] > 1)
                ok = 0;
        }
        if (!ok)
            break;
        FUN_a007ab94(phy);
        DRV_HDMI21_Set_PHY_PreAEQ(phy, 1);
    }
    if (DAT_a807d680[p].mode == 1) {
        if (DAT_a8078634 & 2)
            FUN_a00734c4(s_a0069f18);
    } else {
        unsigned char u8BestRCIdx[4] = { 0 };
        unsigned short u16BestSCDCErrCnt[4] = { 0 };
        unsigned short u16SCDCErrCnt[4] = { 0 };

        for (i = 0; lane_ok(i); i++) {
            u16BestSCDCErrCnt[i] = DAT_a807d680[p].rc[i][0];
            u8BestRCIdx[i] = 0;
        }
        for (i = 0; lane_ok(i); i++) {
            for (j = 1; j < 2; j++) {
                if (DAT_a807cc50[i] == 0) {
                    if (DAT_a8078634 & 2)
                        FUN_a0073044(s_a0069f38, (char)(port + 'A'), i, 0);
                } else {
                    u16SCDCErrCnt[i] = DAT_a807d680[port & 0xff].rc[i][j];
                    if (DAT_a8078634 & 2)
                        FUN_a0073044(s_a0069f78, (char)(port + 'A'), i, j, i, u16SCDCErrCnt[i], i,
                                     u8BestRCIdx[i], i, u16BestSCDCErrCnt[i]);
                    if (u16SCDCErrCnt[i] < u16BestSCDCErrCnt[i])
                        u8BestRCIdx[i] = j;
                }
            }
            DAT_a807cc50[i] = u8BestRCIdx[i];
            DAT_a807cc60[i] = u8BestRCIdx[i];
        }
        for (i = 0; lane_ok(i); i++) {
            for (j = 0; j < 2; j++) {
                if (DAT_a8078634 & 2)
                    FUN_a0073044(s_a0069ff0, (char)(port + 'A'), i, DAT_a807cc50[i], j,
                                 DAT_a807d680[port & 0xff].rc[i][j]);
            }
        }
        FUN_a007ab94(phy);
        DRV_HDMI21_Set_PHY_PreAEQ(phy, 1);
    }
done:
    if (err == 0)
        goto fail;
    if (ok)
        return 0;
fail:
    DAT_a807d648[port & 0xff] = 9;
    DAT_a807d650[port & 0xff].st = 0;
    return 0;
}
