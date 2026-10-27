/* LINK_STANDBY_2 (leon2s 0xa006e444-0xa006e820, 988 bytes), flags -mcpu=v8 -Os -g.
 * void (port record rec, u8 port); the same state structure as LINK_STANDBY with other callees and records.
 * f = FUN_a00961e8(port) indexes the 24-byte link table DAT_a807cc64; ports > 1: nothing. On the first pass
 * (DAT_a8078892 == 0) the power flags DAT_a8078890[0..1] are set to 1. Link-table byte +6 = bit 7 of rec
 * halfword +0x12. rec[0] = state, port record ARR_a807d7e0[port] (400 bytes):
 *   1: power flag 1 -> TMDS_PowerOff(f, 0), flag 0, FUN_a00a1638(port).
 *   2: power flag 0 -> TMDS_PowerOn(f), flag 1, FUN_a00a15c8(port); then state 3 (FUN_a006d53c(rec, 3)).
 *   3: record byte +4 == 1 -> rec +2/+6/+0xa = record +0x1a, +0x1e and +0x32 / 10 (all doubled when record byte
 *      +0x2d != 1 and FUN_a00a2080(port) is nonzero), rec +4/+8 = record +0x1c/+0x20, time stamp
 *      DAT_a8078884[port] = FUN_a00b2064(), state 4.
 *   4: record byte +4 == 1 -> rec[0xc] = FUN_a00a1e28(port), FUN_a006e2c4(rec, port), state 5, print
 *      s_a0065f30 ("HDMI21 RX(%d) go to LINK_READY"), rec[0xf] = 1, FUN_a00a2a04(port); otherwise state 3.
 *   5: record byte +4 != 1 -> print s_a0065f58 ("go to LINK_STANDBY"), state 3; FUN_a00a1e28(port) != rec[0xc] ->
 *      the same print, rec[0xc] = FUN_a00a1e28(port), state 3, stamp = FUN_a00b2064() - 200; otherwise
 *      FUN_a006e0e4(rec, port, record).
 * End of the pass: left state 5 -> rec[0x10] = 1 and print s_a0065f70 (port, state). rec[0xd] or rec[0xe]
 * changed -> FUN_a006e2c4(rec, port), rec[0x10] = 1 when bits 0x48 of rec[0xd] changed, print s_a0065f90.
 * Source forms the exact build depends on: state 3 written with ARR_a807d7e0[port] at every use and the
 * b2d == 1 arm as its own copy of the undoubled stores (cross-jumped); state 5 with the failing tests first;
 * FUN_a00a2080 declared with an unsigned char result.
 */
struct PortRec {
    unsigned char b0, b1;
    unsigned short h2, h4, h6, h8, ha;
    unsigned char bc, bd, be, bf, b10, b11;
    union { unsigned short h; unsigned char b; } u12;
};
struct LinkInfo { unsigned char b0, b1, b2, b3, b4, b5, b6, b7, b8[16]; };   /* 24-byte rows */
struct Rec400 {
    unsigned char b0[4];
    unsigned char b4;
    unsigned char b5[0x1a - 5];
    unsigned short h1a, h1c, h1e, h20;
    unsigned char b22[0x2d - 0x22];
    unsigned char b2d;
    unsigned char b2e[4];
    unsigned short h32;
    unsigned char rest[400 - 0x34];
};

extern struct LinkInfo DAT_a807cc64[];
extern struct Rec400 ARR_a807d7e0[];
extern unsigned char DAT_a8078890[];
extern unsigned char DAT_a8078892;
extern unsigned int DAT_a8078884[];
extern char s_a0065f30[], s_a0065f58[], s_a0065f70[], s_a0065f90[];

extern unsigned char FUN_a00961e8(unsigned char);
extern void TMDS_PowerOff(unsigned char, unsigned char);
extern void TMDS_PowerOn(unsigned char);
extern unsigned int FUN_a00a1638(unsigned int);
extern int FUN_a00a15c8(int);
extern unsigned char FUN_a00a2080(unsigned int);
extern unsigned int FUN_a00b2064(void);
extern unsigned char FUN_a00a1e28(unsigned char);
extern void FUN_a006e2c4(struct PortRec *, unsigned char);
extern void FUN_a006d53c(struct PortRec *, unsigned char);
extern void FUN_a00a2a04(unsigned char);
extern void FUN_a006e0e4(struct PortRec *, unsigned int, struct Rec400 *);
extern int FUN_a0073044(char *, ...);

void LINK_STANDBY_2(struct PortRec *rec, unsigned char port)
{
    unsigned char f = FUN_a00961e8(port);
    unsigned char os = rec->b0, od = rec->bd, oe = rec->be;
    unsigned char i;
    struct Rec400 *r;

    if (port > 1)
        return;
    if (DAT_a8078892 == 0) {
        for (i = 0; i < 2; i++)
            DAT_a8078890[i] = 1;
        DAT_a8078892 = 1;
    }
    DAT_a807cc64[f].b6 = (rec->u12.h >> 7) & 1;
    switch (rec->b0) {
    case 1:
        if (DAT_a8078890[port] == 1) {
            TMDS_PowerOff(f, 0);
            DAT_a8078890[port] = 0;
            FUN_a00a1638(port);
        }
        break;
    case 2:
        if (DAT_a8078890[port] == 0) {
            TMDS_PowerOn(f);
            DAT_a8078890[port] = 1;
            FUN_a00a15c8(port);
        }
        FUN_a006d53c(rec, 3);
        break;
    case 3:
        if (ARR_a807d7e0[port].b4 == 1) {
            if (ARR_a807d7e0[port].b2d == 1) {
                rec->h2 = ARR_a807d7e0[port].h1a;
                rec->h6 = ARR_a807d7e0[port].h1e;
                rec->ha = ARR_a807d7e0[port].h32 / 10;
            } else if (FUN_a00a2080(port)) {
                rec->h2 = ARR_a807d7e0[port].h1a * 2;
                rec->h6 = ARR_a807d7e0[port].h1e * 2;
                rec->ha = ARR_a807d7e0[port].h32 / 10 * 2;
            } else {
                rec->h2 = ARR_a807d7e0[port].h1a;
                rec->h6 = ARR_a807d7e0[port].h1e;
                rec->ha = ARR_a807d7e0[port].h32 / 10;
            }
            rec->h4 = ARR_a807d7e0[port].h1c;
            rec->h8 = ARR_a807d7e0[port].h20;
            DAT_a8078884[port] = FUN_a00b2064();
            FUN_a006d53c(rec, 4);
        }
        break;
    case 4:
        if (ARR_a807d7e0[port].b4 == 1) {
            rec->bc = FUN_a00a1e28(port);
            FUN_a006e2c4(rec, port);
            FUN_a006d53c(rec, 5);
            FUN_a0073044(s_a0065f30, port);
            rec->bf = 1;
            FUN_a00a2a04(port);
        } else
            FUN_a006d53c(rec, 3);
        break;
    case 5:
        r = &ARR_a807d7e0[port];
        if (r->b4 != 1) {
            FUN_a0073044(s_a0065f58);
            FUN_a006d53c(rec, 3);
        } else if (FUN_a00a1e28(port) != rec->bc) {
            FUN_a0073044(s_a0065f58);
            rec->bc = FUN_a00a1e28(port);
            FUN_a006d53c(rec, 3);
            DAT_a8078884[port] = FUN_a00b2064() - 200;
        } else
            FUN_a006e0e4(rec, port, r);
        break;
    }
    if (rec->b0 != 5 && os == 5) {
        rec->b10 = 1;
        FUN_a0073044(s_a0065f70, port, rec->b0);
    }
    if (rec->bd != od || rec->be != oe) {
        FUN_a006e2c4(rec, port);
        if ((rec->bd & 0x48) != (od & 0x48))
            rec->b10 = 1;
        FUN_a0073044(s_a0065f90, port, rec->bd, rec->be);
    }
}
