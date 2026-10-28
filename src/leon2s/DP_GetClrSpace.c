/* DP_GetClrSpace (leon2s 0xa006ed54-0xa006fa28, 3284 bytes), flags -mcpu=v8 -Os -g.
 * Link state step for port (0 or 1 accepted, other values return at once) and stream of the port record rec.
 * Saves the record's link status (+0), PHY status (+0xd) and byte +0xe, calls FUN_a00b0454(port, bit 7 of
 * halfword +0x12) for port 1 or for port 0 with stream 0, runs func_0x9f1cc264/func_0x9f1cc0a8 and the
 * FUN_a00b1418 / FUN_a00b14b0 / FUN_a00b1434 group, and compares func_0x9f1c6694(port) with DAT_a80788b8[port]:
 * on a change it prints SST2MST or MST2SST, calls FUN_a00b12cc / FUN_a00ac41c, sets status 2 through
 * FUN_a006d53c and stores the new value. For stream 1, 2 or 3 a zero result of func_0x9f1cc084 / 090 / 09c
 * returns when the status is 2 or less and otherwise sets status 2. Then by status (strings name 2 PHY_POWERON,
 * 3 LINK_STANDBY, 4 LINK_STABLE, 5 LINK_READY):
 * 1: FUN_a00afdf4(port, 1), FUN_a00b0568(port). 2: register calls, FUN_a006e820; bit 0 of +0xd moves to status 3.
 * 3: when FUN_a00ad27c(port) == 1, bit 6 of FUN_a00a6bb8(port, 0xf2) is set and FUN_a00acc54(port) is in
 * 0x15..0xd47: status 4, DAT_a807889c[stream] = FUN_a00b2064(), the five halfwords +2..+0xa are read again,
 * bit 4 of +0x12 is cleared and the values are printed; a lost FUN_a00ad27c result moves to status 2.
 * 4: lost training / SCDT / FIFO mode change move to status 2 / 3 / 2; else by byte +0x11: 0 waits
 * (bit 1 of +0xd ? 700 : 100) ticks of FUN_a00b2064 with FUN_a006e990, then reads the color space
 * (FUN_a00ada24) and depth (FUN_a00acb94), programs FUN_a00ae0dc / FUN_a00b0004 / FUN_a00b00e0 / FUN_a00add8c
 * by the Clk halfword (above 0x3a2, above 0x1c2, else; streams 0 and 4 use other values) and the following
 * register calls, and increments +0x11; 1 checks again within 0x95 ticks, prints a FIFO error from
 * FUN_a00ad644, or moves to status 5 (byte +0xf = 1, DAT_a80788b0[stream] = 0, FUN_a00abb20(port)).
 * 5: lost training / SCDT move to status 2 / 3; a color space change or a FUN_a006e990 change or a FIFO error
 * moves to status 4; otherwise FUN_a00b06e0 and FUN_a00ae378 / FUN_a00ad684 every 300 ticks. Leaving status 5
 * runs FUN_a00aba14, FUN_a00ab964(port, 0..9) and FUN_a006d568(rec, port, stream).
 * Finally a change from status 5 sets byte +0x10 and prints the new status, and a changed PHY status or byte
 * +0xe sets +0xf (and +0x10 when bits 0x48 differ) and prints both.
 * Source form: old-style parameter declarations (unsigned char port, stream); the status print passes the
 * status as its second value; the FIFO error print takes FUN_a00ad644(port) and FUN_a00a6bb8(port, 0x44) as
 * direct call arguments; the result of FUN_a00ad27c is kept in an unsigned int and stored to DAT_a80788c8.
 */
struct PortRec {
    unsigned char link_status, b1;
    unsigned short htotal, vtotal, hrtlde, vrtlde, clk;
    unsigned char clrspace, phy_status, be, bf, b10, b11;
    union {
        unsigned short h;
        unsigned char depth;
        struct { unsigned short hi : 11; unsigned short force_mode_change : 1; unsigned short lo : 4; } f;
    } u12;
};

extern unsigned char DAT_a80788c0[];
extern unsigned char DAT_a80788b8[];
extern unsigned int DAT_a807889c[];
extern unsigned char DAT_a80788c8[];
extern unsigned char ARR_a8079310[];
extern unsigned char DAT_a80788b0[];
extern char s_a00661d0[], s_a0066208[], s_a0066240[], s_a0066270[], s_a0066138[], s_a0066158[], s_a0066178[],
    s_a0066198[], s_a0066290[], s_a00662a8[], s_a00662c8[], s_a00662f8[], s_a0066320[], s_a0066350[],
    s_a0066370[], s_a0066388[], s_a00663b0[], s_a00663e8[], s_a0066400[], s_a0066410[], s_a0066430[],
    s_a0066448[], s_a0066468[];

extern int FUN_a0073044(char *, ...);
extern void FUN_a00b0454(unsigned char, unsigned char);
extern unsigned char FUN_a00b0470(unsigned char);
extern void func_0x9f1cc264(unsigned char);
extern void func_0x9f1cc0a8(void);
extern unsigned char FUN_a00b1418(unsigned char);
extern unsigned char FUN_a00b14b0(unsigned char);
extern unsigned char FUN_a00b1434(unsigned char);
extern void FUN_a00ad6cc(unsigned char, unsigned char);
extern void FUN_a00b1470(unsigned char);
extern void FUN_a00b1964(void);
extern void FUN_a00b1450(unsigned char);
extern unsigned char func_0x9f1c6694(unsigned char);
extern void FUN_a00b12cc(unsigned char, unsigned char);
extern void FUN_a00ac41c(unsigned char, unsigned char, unsigned char);
extern void FUN_a006d53c(struct PortRec *, unsigned char);
extern unsigned char func_0x9f1cc084(void);
extern unsigned char func_0x9f1cc090(void);
extern unsigned char func_0x9f1cc09c(void);
extern void FUN_a00afdf4(unsigned char, unsigned char);
extern void FUN_a00b0568(unsigned char);
extern void FUN_a00b05e8(unsigned char, unsigned char);
extern void FUN_a00af858(unsigned char, unsigned char);
extern void FUN_a00add0c(unsigned char, unsigned char);
extern void FUN_a006e820(struct PortRec *, unsigned char);
extern void FUN_a00b1350(unsigned char);
extern void FUN_a0088f90(unsigned char, unsigned short);
extern unsigned char FUN_a00ad27c(unsigned char);
extern unsigned char FUN_a00a6bb8(unsigned char, unsigned short);
extern unsigned short FUN_a00acc54(unsigned char);
extern void FUN_a00ad734(unsigned char);
extern unsigned int FUN_a00b2064(void);
extern unsigned short FUN_a00acb40(unsigned char);
extern unsigned short FUN_a00acb60(unsigned char);
extern unsigned short FUN_a00acac0(unsigned char);
extern unsigned short FUN_a00acb00(unsigned char);
extern void FUN_a00b0078(unsigned char, unsigned char);
extern void FUN_a00af764(unsigned char);
extern unsigned char FUN_a00b0138(unsigned char);
extern unsigned char FUN_a006e990(struct PortRec *, unsigned char);
extern unsigned char FUN_a00af320(unsigned char);
extern unsigned char FUN_a00ada24(unsigned char, unsigned char);
extern unsigned int FUN_a00acb94(unsigned char);
extern void FUN_a00ae0dc(unsigned char, unsigned char, unsigned char);
extern void FUN_a00b0004(unsigned char, unsigned char);
extern void FUN_a00b00e0(unsigned char, unsigned char);
extern unsigned char FUN_a00ad828(unsigned char);
extern void FUN_a00add8c(unsigned char, unsigned char);
extern void FUN_a00af168(unsigned char, unsigned char);
extern void FUN_a00af464(unsigned char, unsigned char);
extern void FUN_a00ae254(unsigned char, unsigned char);
extern void FUN_a00b04a8(unsigned char);
extern void FUN_a00ad0c4(unsigned char);
extern void FUN_a008b914(unsigned char);
extern void FUN_a00ad09c(unsigned char);
extern unsigned char FUN_a00ad644(unsigned char);
extern void FUN_a00abb20(unsigned char);
extern void FUN_a00b06e0(unsigned char);
extern void FUN_a00ae378(unsigned char);
extern void FUN_a00ad684(unsigned char);
extern void FUN_a00aba14(unsigned char);
extern void FUN_a00ab964(unsigned char, unsigned char);
extern void FUN_a006d568(struct PortRec *, unsigned char, unsigned char);

void DP_GetClrSpace(rec, port, stream)
    struct PortRec *rec;
    unsigned char port, stream;
{
    unsigned char old_status = rec->link_status;
    unsigned char old_phy = rec->phy_status;
    unsigned char old_be = rec->be;
    unsigned char mst[2];
    unsigned char i, d;
    unsigned int r;

    if (port > 1)
        return;
    if ((port == 0 && stream == 0) || port == 1)
        FUN_a00b0454(port, (rec->u12.h >> 7) & 1);
    if (FUN_a00b0470(port) == 0 && DAT_a80788c0[port] == 1 && DAT_a80788b8[port] != 0) {
        func_0x9f1cc264(port);
        func_0x9f1cc0a8();
    }
    if (FUN_a00b1418(port) && FUN_a00b14b0(port)) {
        if (FUN_a00b1434(port))
            FUN_a00ad6cc(port, 1);
        FUN_a00b1470(port);
        FUN_a00b1964();
        FUN_a00b1450(port);
    }
    mst[port] = func_0x9f1c6694(port);
    if (DAT_a80788b8[port] != mst[port]) {
        if (mst[port]) {
            FUN_a0073044(s_a0066208, port);
            FUN_a00b12cc(port, 1);
            FUN_a00ac41c(0, 1, 0);
        } else {
            FUN_a0073044(s_a00661d0, port);
            FUN_a00b12cc(port, 0);
            FUN_a00ac41c(port, 0, 0);
        }
        FUN_a006d53c(rec, 2);
        DAT_a80788b8[port] = mst[port];
    }
    if ((stream == 1 && func_0x9f1cc084() == 0) || (stream == 2 && func_0x9f1cc090() == 0) ||
        (stream == 3 && func_0x9f1cc09c() == 0)) {
        if (rec->link_status <= 2)
            return;
        FUN_a006d53c(rec, 2);
    }
    switch (rec->link_status) {
    case 1:
        FUN_a00afdf4(port, 1);
        FUN_a00b0568(port);
        break;
    case 2:
        FUN_a00b05e8(port, 0);
        FUN_a00af858(port, 0);
        FUN_a00afdf4(port, 1);
        FUN_a00add0c(port, 1);
        FUN_a006e820(rec, port);
        if (rec->phy_status & 1) {
            FUN_a00b1350(port);
            FUN_a0088f90(0, 8);
            FUN_a006d53c(rec, 3);
            FUN_a0073044(s_a0066240, port, stream);
        }
        break;
    case 3:
        if (FUN_a00ad27c(port) != 1) {
            FUN_a006d53c(rec, 2);
            FUN_a0073044(s_a0066270, port);
            break;
        }
        if (!(FUN_a00a6bb8(port, 0xf2) & 0x40))
            break;
        if (FUN_a00acc54(port) <= 0x14)
            break;
        if (FUN_a00acc54(port) > 0xd47)
            break;
        FUN_a00ad734(port);
        FUN_a006d53c(rec, 4);
        DAT_a807889c[stream] = FUN_a00b2064();
        rec->htotal = FUN_a00acb40(port);
        rec->vtotal = FUN_a00acb60(port);
        rec->hrtlde = FUN_a00acac0(port);
        rec->vrtlde = FUN_a00acb00(port);
        rec->clk = FUN_a00acc54(port);
        rec->u12.f.force_mode_change = 0;
        FUN_a006e820(rec, port);
        FUN_a00af858(port, 0);
        FUN_a00afdf4(port, 1);
        FUN_a00b0078(port, 1);
        FUN_a00af764(port);
        FUN_a0073044(s_a0066138, port, rec->htotal);
        FUN_a0073044(s_a0066158, port, rec->vtotal);
        FUN_a0073044(s_a0066178, port, rec->hrtlde);
        FUN_a0073044(s_a0066198, port, rec->vrtlde);
        FUN_a0073044(s_a0066290, port, rec->clk);
        FUN_a0073044(s_a00662a8, port);
        ARR_a8079310[port] = 0;
        break;
    case 4:
        r = FUN_a00ad27c(port);
        if (r != 1) {
            FUN_a006d53c(rec, 2);
            FUN_a0073044(s_a00662c8, port);
            break;
        }
        if (!(FUN_a00a6bb8(port, 0xf2) & 0x40)) {
            FUN_a006d53c(rec, 3);
            FUN_a0073044(s_a00662f8, port);
            break;
        }
        if (FUN_a00b0138(port)) {
            FUN_a006d53c(rec, 2);
            FUN_a0073044(s_a0066320, port);
            break;
        }
        switch (rec->b11) {
        case 0:
            if (FUN_a00b2064() - DAT_a807889c[stream] < (rec->phy_status & 2) * 300 + 100) {
                if (FUN_a006e990(rec, port) == 1)
                    DAT_a807889c[stream] = FUN_a00b2064();
                if (FUN_a00af320(port))
                    DAT_a80788c8[port] = r;
                break;
            }
            rec->clrspace = FUN_a00ada24(port, (rec->phy_status >> 1) & 1);
            FUN_a0073044(s_a0066350, port, rec->clrspace);
            rec->u12.depth = FUN_a00acb94(port);
            FUN_a0073044(s_a0066370, rec->u12.depth);
            if (stream == 0 || stream == 4) {
                if (rec->clk > 0x3a2) {
                    FUN_a00ae0dc(port, 4, rec->clrspace);
                    FUN_a00b0004(port, 0);
                    FUN_a00b00e0(port, 0);
                    FUN_a00add8c(port, 1);
                } else if (rec->clk > 0x1c2) {
                    FUN_a00ae0dc(port, 1, rec->clrspace);
                    FUN_a00b0004(port, 0);
                    FUN_a00b00e0(port, 0);
                    FUN_a00add8c(port, 2);
                } else {
                    FUN_a00ae0dc(port, 1, rec->clrspace);
                    FUN_a00b0004(port, 1);
                    FUN_a00b00e0(port, 0);
                    if (FUN_a00ad828(rec->clrspace))
                        FUN_a00add8c(port, 4);
                    else
                        FUN_a00add8c(port, 2);
                }
            } else {
                if (rec->clk > 0x3a2) {
                    FUN_a00ae0dc(port, 4, rec->clrspace);
                    FUN_a00b0004(port, 0);
                    FUN_a00b00e0(port, 0);
                    FUN_a00add8c(port, 1);
                } else if (rec->clk > 0x1c2) {
                    FUN_a00ae0dc(port, 1, rec->clrspace);
                    FUN_a00b0004(port, 1);
                    FUN_a00b00e0(port, 1);
                    FUN_a00add8c(port, 2);
                } else {
                    FUN_a00ae0dc(port, 1, rec->clrspace);
                    FUN_a00b0004(port, 0);
                    FUN_a00b00e0(port, 0);
                    if (FUN_a00ad828(rec->clrspace))
                        FUN_a00add8c(port, 4);
                    else
                        FUN_a00add8c(port, 2);
                }
            }
            FUN_a006e820(rec, port);
            if (FUN_a00af320(port))
                DAT_a80788c8[port] = 2;
            if ((rec->phy_status & 2) || DAT_a80788c8[port] == 2) {
                FUN_a00af168(port, 1);
                FUN_a00af464(port, 1);
                ARR_a8079310[port] = 0;
            } else {
                FUN_a00af168(port, 0);
                FUN_a00af464(port, 0);
                DAT_a80788c8[port] = 0;
            }
            FUN_a00ae254(port, 0xb0);
            FUN_a00add0c(port, 0);
            FUN_a00af858(port, 1);
            FUN_a00afdf4(port, 0);
            FUN_a00b0078(port, 0);
            FUN_a00b04a8(port);
            FUN_a00ad0c4(port);
            FUN_a008b914(port);
            DAT_a807889c[stream] = FUN_a00b2064();
            FUN_a00ad09c(port);
            rec->b11++;
            break;
        case 1:
            if ((rec->phy_status & 2) == 0 && FUN_a00b2064() - DAT_a807889c[stream] <= 0x95) {
                if (FUN_a006e990(rec, port) == 1) {
                    FUN_a006d53c(rec, 4);
                    DAT_a807889c[stream] = FUN_a00b2064();
                    break;
                }
                if (FUN_a00ad644(port) == 1)
                    FUN_a00ad09c(port);
                break;
            }
            if ((rec->phy_status & 2) == 0 && FUN_a00ad644(port) == 1) {
                FUN_a0073044(s_a0066388, port, FUN_a00ad644(port), FUN_a00a6bb8(port, 0x44));
                FUN_a006d53c(rec, 4);
                DAT_a807889c[stream] = FUN_a00b2064();
                break;
            }
            FUN_a006d53c(rec, 5);
            FUN_a0073044(s_a00663b0, port, stream, rec->clk);
            rec->bf = 1;
            DAT_a807889c[stream] = FUN_a00b2064();
            DAT_a80788b0[stream] = 0;
            FUN_a00abb20(port);
            break;
        }
        break;
    case 5:
        if (FUN_a00ad27c(port) != 1) {
            FUN_a0073044(s_a00663e8, port);
            FUN_a006d53c(rec, 2);
        } else if (!(FUN_a00a6bb8(port, 0xf2) & 0x40)) {
            FUN_a0073044(s_a0066400, port);
            FUN_a006d53c(rec, 3);
        } else if (FUN_a00ada24(port, (rec->phy_status >> 1) & 1) != rec->clrspace) {
            FUN_a0073044(s_a0066410, port);
            rec->clrspace = FUN_a00ada24(port, (rec->phy_status >> 1) & 1);
            FUN_a006d53c(rec, 4);
            DAT_a807889c[stream] = FUN_a00b2064();
        } else if (FUN_a006e990(rec, port) == 1) {
            FUN_a006d53c(rec, 4);
            DAT_a807889c[stream] = FUN_a00b2064();
            FUN_a0073044(s_a0066430, DAT_a807889c[stream]);
        } else if (!(rec->phy_status & 2) && FUN_a00ad644(port) == 1) {
            FUN_a0073044(s_a0066388, port, FUN_a00ad644(port), FUN_a00a6bb8(port, 0x44));
            FUN_a006d53c(rec, 4);
            DAT_a807889c[stream] = FUN_a00b2064();
        } else {
            FUN_a00b06e0(port);
            if (FUN_a00b2064() - DAT_a807889c[stream] > 300) {
                DAT_a807889c[stream] = FUN_a00b2064();
                FUN_a00ae378(port);
                DAT_a80788b0[stream] = 1;
            }
            if (DAT_a80788b0[stream] == 1)
                FUN_a00ad684(port);
        }
        if (rec->link_status != 5) {
            FUN_a00aba14(port);
            for (i = 0; i < 10; i++)
                FUN_a00ab964(port, i);
            FUN_a006d568(rec, port, stream);
        }
        break;
    }
    d = rec->link_status;
    if (d != 5 && old_status == 5) {
        rec->b10 = 1;
        FUN_a0073044(s_a0066448, port, d);
        DAT_a80788c8[port] = 0;
    }
    d = rec->phy_status;
    if (d != old_phy || rec->be != old_be) {
        rec->bf = 1;
        if ((d & 0x48) != (old_phy & 0x48))
            rec->b10 = 1;
        FUN_a0073044(s_a0066468, port, d, rec->be);
    }
}
