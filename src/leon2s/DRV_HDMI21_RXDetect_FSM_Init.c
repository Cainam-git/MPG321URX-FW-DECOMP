/* DRV_HDMI21_RXDetect_FSM_Init (leon2s 0xa009bef0-0xa009c09c, 428 bytes), flags -mcpu=v8 -Os -g.
 * p = (u8)port, j = FUN_a00961e8(p). Under bit 11 of DAT_a8078634 prints "[HDMI21]: \x1b[1m%s, PortID = %d\n\x1b[m"
 * with the function name and p. Copies the state word DAT_a807d648[p] to word +0x30 of the 0xb0-byte record
 * DAT_a807d680[p], calls FUN_a009b5f4(p) and clears bits 27..24 and 31..28 of register word 0xa0 and bits 3..0
 * and 7..4 of word 0xa4 of the register block (word +0x18 of the 0x34-byte record DAT_a807db00[p]) in a 4-step
 * loop. Then FUN_a00a73d4(0x16, regs + 0xa0), FUN_a00a73d4(4, regs + 0x80), clears bits 27..24 of word 0x90,
 * FUN_a00a73d4(5, regs + 0x80), FUN_a00a7424(1, 0x14, j, 0x2f08), FUN_a00a7424(0, 0x14, j, 0x2f08), sets the
 * state word to 1 and returns 0. The register block is volatile (hardware).
 * Source form: the clearing loop is the static inline helper of DRV_HDMI21_RXDetect_FSM_LTS_3, called with p;
 * the later accesses index DAT_a807db00[port & 0xff] directly.
 */
struct Port {
    volatile unsigned int *regs0;
    unsigned char _04[0x18 - 4];
    volatile unsigned int *regs;
    unsigned char _1c[0x34 - 0x1c];
};
struct Rec {
    unsigned char n;
    unsigned char _01[0x2f];
    unsigned int state;
    unsigned char _34[0xb0 - 0x34];
};

extern struct Port DAT_a807db00[];
extern struct Rec DAT_a807d680[];
extern unsigned int DAT_a807d648[];
extern unsigned int DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern unsigned char FUN_a00961e8(unsigned char);
extern void FUN_a009b5f4(unsigned char);
extern void FUN_a00a73d4(unsigned int, volatile unsigned int *);
extern void FUN_a00a7424(int mode, unsigned int bit, unsigned char reg, unsigned short val);
static const char fn_[] = "DRV_HDMI21_RXDetect_FSM_Init";

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

int DRV_HDMI21_RXDetect_FSM_Init(unsigned int port)
{
    unsigned char p = port;
    unsigned char j;

    j = FUN_a00961e8(p);
    if (DAT_a8078634 & 0x800)
        FUN_a0073044("[HDMI21]: \x1b[1m%s, PortID = %d\n\x1b[m", fn_, p);
    DAT_a807d680[p].state = DAT_a807d648[p];
    FUN_a009b5f4(p);
    clear_fields(p);
    FUN_a00a73d4(0x16, DAT_a807db00[port & 0xff].regs + 0xa0 / 4);
    FUN_a00a73d4(4, DAT_a807db00[port & 0xff].regs + 0x80 / 4);
    DAT_a807db00[port & 0xff].regs[0x90 / 4] &= ~0x0f000000;
    FUN_a00a73d4(5, DAT_a807db00[port & 0xff].regs + 0x80 / 4);
    FUN_a00a7424(1, 0x14, j, 0x2f08);
    FUN_a00a7424(0, 0x14, j, 0x2f08);
    DAT_a807d648[port & 0xff] = 1;
    return 0;
}
