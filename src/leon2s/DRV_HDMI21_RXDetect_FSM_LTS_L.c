/* DRV_HDMI21_RXDetect_FSM_LTS_L (leon2s 0xa009bba8-0xa009bef0, 840 bytes), flags -mcpu=v8 -Os -g.
 * int (unsigned int port), returns 0. p = (u8) port; sel = 2 for p 0, 3 for p 1, other ports return at once.
 * When the state DAT_a807d648[p] differs from word +0x30 of the 0xb0-byte record DAT_a807d680[p]: for i = 0..3
 * clears bits 24..27 / 28..31 of register word 0x28 or bits 0..3 / 4..7 of word 0x29 of the block
 * DAT_a807db00[p].regs; prints the function trace (bit 11 of DAT_a8078634); clears DAT_a8079054[p], copies the
 * state into the record, clears its byte 2, FUN_a00a73ac(0x16, regs + 0x28), FUN_a009b5f4(p) and
 * FUN_a00a7424(0, 0 and 1, p, 0x3600). Then, when bits 24..27 of regs[0x24] are not 0: state = 3,
 * DAT_a8079054[p] = 0, return. DAT_a8079054[p] is cleared when byte 1 of the 0x190-byte record DAT_a807d7e0[p]
 * is 1; above 0x2bc it is cleared, FUN_a0098b60(p) is called and "HPD Toggle to recover" printed; otherwise,
 * above 0x64 with bit 0x11 of regs + 0x24 set, FUN_a00a73d4(0x11, regs + 0x24), and the counter is incremented
 * when byte 6 of DAT_a807cc64[sel], bit 0x11 of word 1 of DAT_a807db00[p].regs0 are set and the record byte 1 is
 * 0. Finally state = 7.
 * Source form: 'sel = 2;' assigned before the port test (keeps the port byte in one register for the record
 * address of the loop).
 */
struct Port {
    volatile unsigned int *regs0;
    unsigned char _04[8];
    volatile unsigned int *rc;
    unsigned char _10[8];
    volatile unsigned int *regs;
    unsigned char _1c[0x34 - 0x1c];
};
struct Rec {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char _03[0x30 - 3];
    unsigned int state;
    unsigned char _34[0xb0 - 0x34];
};
struct R190 {
    unsigned char b0;
    unsigned char b1;
    unsigned char _2[0x190 - 2];
};
struct sel_rec {
    unsigned char b0;
    unsigned char b1;
    unsigned char _2[4];
    unsigned char b6;
    unsigned char _7[0x18 - 7];
};

extern struct Port DAT_a807db00[];
extern struct Rec DAT_a807d680[];
extern unsigned long DAT_a807d648[];
extern struct sel_rec DAT_a807cc64[];
extern struct R190 DAT_a807d7e0[];
extern unsigned short DAT_a8079054[];
extern unsigned int DAT_a8078634;
extern const char DAT_a0067868[];

extern int FUN_a0073044(const char *, ...);
extern void FUN_a00a73ac(unsigned int, volatile unsigned int *);
extern void FUN_a00a73d4(unsigned int, volatile unsigned int *);
extern unsigned int FUN_a00a7408(unsigned int, volatile unsigned int *);
extern void FUN_a009b5f4(unsigned char);
extern void FUN_a00a7424(int, unsigned int, unsigned char, unsigned short);
extern void FUN_a0098b60(unsigned char);

static const char fn_[] = "DRV_HDMI21_RXDetect_FSM_LTS_L";

int DRV_HDMI21_RXDetect_FSM_LTS_L(unsigned int port)
{
    unsigned char p = port;
    unsigned char sel;
    unsigned char i;

    sel = 2;
    if (p != 0) {
        if (p == 1)
            sel = 3;
        else
            return 0;
    }
    if (DAT_a807d648[p] != DAT_a807d680[p].state) {
        for (i = 0; i <= 3; i++) {
            if (i == 0)
                DAT_a807db00[p].regs[0x28] &= 0xf0ffffff;
            else if (i == 1)
                DAT_a807db00[p].regs[0x28] &= 0x0fffffff;
            else if (i == 2)
                DAT_a807db00[p].regs[0x29] &= ~0xf;
            else if (i == 3)
                DAT_a807db00[p].regs[0x29] &= ~0xf0;
        }
        if (DAT_a8078634 & 0x800)
            FUN_a0073044(DAT_a0067868, fn_);
        DAT_a8079054[p] = 0;
        DAT_a807d680[p].state = DAT_a807d648[p];
        DAT_a807d680[p].b2 = 0;
        FUN_a00a73ac(0x16, DAT_a807db00[p].regs + 0x28);
        FUN_a009b5f4(p);
        FUN_a00a7424(0, 0, p, 0x3600);
        FUN_a00a7424(0, 1, p, 0x3600);
    }
    if ((DAT_a807db00[p].regs[0x24] >> 24) & 0xf) {
        DAT_a807d648[p] = 3;
        DAT_a8079054[p] = 0;
        return 0;
    }
    if (DAT_a807d7e0[p].b1 == 1)
        DAT_a8079054[p] = 0;
    if (DAT_a8079054[p] > 0x2bc) {
        DAT_a8079054[p] = 0;
        FUN_a0098b60(p);
        if (DAT_a8078634 & 0x800)
            FUN_a0073044("[HDMI21]: Port%d HPD Toggle to recover(%d)\n\n", p, 1);
    } else {
        if (DAT_a8079054[p] > 0x64 && FUN_a00a7408(0x11, DAT_a807db00[p].regs + 0x24))
            FUN_a00a73d4(0x11, DAT_a807db00[p].regs + 0x24);
        if (DAT_a807cc64[sel].b6 != 0 && FUN_a00a7408(0x11, DAT_a807db00[p].regs0 + 1) && DAT_a807d7e0[p].b1 == 0)
            DAT_a8079054[p]++;
    }
    DAT_a807d648[p] = 7;
    return 0;
}
