/* DRV_HDMI21_RXDetect_FSM_LTS_3 (leon2s 0xa009860c-0xa0098b60, 1364 bytes), flags -mcpu=v8 -Os -g -msoft-float.
 * Ports 0 and 1 only (p = (u8)port); returns 0. When FUN_a008d800() <= 0x82, clears DAT_a80790d8[p]. When the
 * state word DAT_a807d648[p] differs from word +0x30 of the 0xb0-byte record DAT_a807d680[p], prints
 * "[HDMI21]: =%s=" with "DRV_HDMI21_RXDetect_FSM_LTS_3" (bit 11 of DAT_a8078634), copies the state there and
 * clears the u16 counter DAT_a8079086[p]. Then FUN_a00a73d4(4, regs + 0x80) with regs = word +0x18 of the
 * 0x34-byte record DAT_a807db00[p] (register-block pointer).
 * FUN_a0098300(p) non-zero: clears bits 27..24 and 31..28 of regs word 0xa0 and bits 3..0 and 7..4 of word 0xa4
 * (one read-modify-write per step of a 4-step loop) and sets the state to 7.
 * Otherwise, when bit 5 of regs + 0x80 is set (FUN_a00a7408): prints "LTS_3 <W>" when the counter is 0,
 * increments the counter and at 300 clears it and prints "no_retrain\n" when bit 17 of regs + 0x90 is set,
 * else "Maybe need HPD Toggle(%d, %d)" with p and the counter. When it is clear: clears byte +0x14 of the
 * record; FUN_a0098300(p) non-zero repeats the clearing above and sets state 7; else, when bits 27..24 of
 * regs word 0x90 are not 0: FUN_a00a73ac(0xb, word 0 of DAT_a807db00[p] + 8 bytes), TxFFE_Max_L(p), the
 * clearing loop, then for i < byte 0 of the record writes field i: 5 to bits 27..24 and 6 to bits
 * 31..28 of word 0xa0, 7 to bits 3..0 and 8 to bits 7..4 of word 0xa4; FUN_a00a73ac(5, regs + 0x80), state 4,
 * clears the u16 DAT_a807908a[port & 0xff].
 * Source forms: the clearing loop is a static inline helper taking the raw port (the first two uses); the
 * third copy is written in place with the function's own loop counter; record accesses name
 * DAT_a807db00[port & 0xff] directly; the port test is two nested ifs (|| folds into a range test).
 * The file is compiled with -msoft-float: it changes the loop-invariant threshold, so the 0x60000000
 * constant of step 1 stays inside the last loop as in the firmware.
 */
struct Port {
    volatile unsigned int *regs0;
    unsigned char _04[0x18 - 4];
    volatile unsigned int *regs;
    unsigned char _1c[0x34 - 0x1c];
};
struct Rec {
    unsigned char n;
    unsigned char _01[0x13];
    unsigned char b14;
    unsigned char _15[0x30 - 0x15];
    unsigned int state;
    unsigned char _34[0xb0 - 0x34];
};

extern struct Port DAT_a807db00[];
extern struct Rec DAT_a807d680[];
extern unsigned int DAT_a807d648[];
extern unsigned char DAT_a80790d8[];
extern unsigned short DAT_a8079086[];
extern unsigned short DAT_a807908a[];
extern unsigned int DAT_a8078634;
extern const char DAT_a0067868[], s_a00b42f8[], s_a0069c90[], s_a0069ca8[], s_a0069cb8[];

extern unsigned char FUN_a008d800(void);
extern int FUN_a0098300(unsigned int);
extern void FUN_a00a73d4(unsigned int, volatile unsigned int *);
extern void FUN_a00a73ac(unsigned int, volatile unsigned int *);
extern unsigned int FUN_a00a7408(unsigned int, volatile unsigned int *);
extern int FUN_a0073044(const char *, ...);
extern int FUN_a00734c4(const char *);
extern void TxFFE_Max_L(unsigned int);

static inline void clear_fields(unsigned int port)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        if (i == 0)
            DAT_a807db00[port & 0xff].regs[0xa0 / 4] &= 0xf0ffffff;
        else if (i == 1)
            DAT_a807db00[port & 0xff].regs[0xa0 / 4] &= 0x0fffffff;
        else if (i == 2)
            DAT_a807db00[port & 0xff].regs[0xa4 / 4] &= ~0xf;
        else if (i == 3)
            DAT_a807db00[port & 0xff].regs[0xa4 / 4] &= ~0xf0;
    }
}

int DRV_HDMI21_RXDetect_FSM_LTS_3(unsigned int port)
{
    unsigned char p = port;
    unsigned char i;

    if (p != 0) {
        if (p != 1)
            return 0;
    }
    if (FUN_a008d800() <= 0x82)
        DAT_a80790d8[p] = 0;
    if (DAT_a807d648[p] != DAT_a807d680[p].state) {
        if (DAT_a8078634 & 0x800)
            FUN_a0073044(DAT_a0067868, s_a00b42f8);
        DAT_a807d680[p].state = DAT_a807d648[p];
        DAT_a8079086[p] = 0;
    }
    FUN_a00a73d4(4, DAT_a807db00[p].regs + 0x80 / 4);
    if (FUN_a0098300(p) & 0xff) {
        clear_fields(port);
        DAT_a807d648[port & 0xff] = 7;
    } else if (FUN_a00a7408(5, DAT_a807db00[p].regs + 0x80 / 4)) {
        if (DAT_a8079086[p] == 0 && (DAT_a8078634 & 0x800))
            FUN_a00734c4(s_a0069c90);
        if (++DAT_a8079086[p] >= 300) {
            DAT_a8079086[p] = 0;
            if (FUN_a00a7408(0x11, DAT_a807db00[p].regs + 0x90 / 4))
                FUN_a00734c4(s_a0069ca8);
            else if (DAT_a8078634 & 0x800)
                FUN_a0073044(s_a0069cb8, p, DAT_a8079086[p]);
        }
    } else {
        DAT_a807d680[p].b14 = 0;
        if (FUN_a0098300(p) & 0xff) {
            clear_fields(port);
            DAT_a807d648[port & 0xff] = 7;
        } else if (((DAT_a807db00[p].regs[0x90 / 4] >> 24) & 0xf) != 0) {
            FUN_a00a73ac(0xb, DAT_a807db00[p].regs0 + 8 / 4);
            TxFFE_Max_L(p);
            for (i = 0; i < 4; i++) {
                if (i == 0)
                    DAT_a807db00[port & 0xff].regs[0xa0 / 4] &= 0xf0ffffff;
                else if (i == 1)
                    DAT_a807db00[port & 0xff].regs[0xa0 / 4] &= 0x0fffffff;
                else if (i == 2)
                    DAT_a807db00[port & 0xff].regs[0xa4 / 4] &= ~0xf;
                else if (i == 3)
                    DAT_a807db00[port & 0xff].regs[0xa4 / 4] &= ~0xf0;
            }
            for (i = 0; i < DAT_a807d680[port & 0xff].n; i++) {
                if (i == 0)
                    DAT_a807db00[port & 0xff].regs[0xa0 / 4] = (DAT_a807db00[port & 0xff].regs[0xa0 / 4] & 0xf0ffffff) | 0x5000000;
                else if (i == 1)
                    DAT_a807db00[port & 0xff].regs[0xa0 / 4] = (DAT_a807db00[port & 0xff].regs[0xa0 / 4] & 0x0fffffff) | 0x60000000;
                else if (i == 2)
                    DAT_a807db00[port & 0xff].regs[0xa4 / 4] = (DAT_a807db00[port & 0xff].regs[0xa4 / 4] & ~0xf) | 7;
                else if (i == 3)
                    DAT_a807db00[port & 0xff].regs[0xa4 / 4] = (DAT_a807db00[port & 0xff].regs[0xa4 / 4] & ~0xf0) | 0x80;
            }
            FUN_a00a73ac(5, DAT_a807db00[port & 0xff].regs + 0x80 / 4);
            DAT_a807d648[port & 0xff] = 4;
            DAT_a807908a[port & 0xff] = 0;
        }
    }
    return 0;
}
