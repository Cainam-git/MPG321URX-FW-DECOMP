/*
 * DRV_HDMI21_Set_PHY (leon2s 0xa0080494-0xa0083324, 11920 bytes), flags -mcpu=v8 -Os -g.
 * void (port, rate), K&R unsigned char parameters (the firmware masks %i0 / %i1 at each use). Ports 2 and 3
 * select the 0xb0-byte record ARR_a807d680[k] (k = 0 / 1), other ports return. Prints
 * "[HDMI21]: Port%c  %s u8FRL_Rate %d" under bit 11 of DAT_a8078634, then writes the PHY registers of the port with
 * FUN_a00a7424(on, bit, port, reg) and FUN_a00a7488(port, reg, keep-mask, value) in rate-dependent blocks and per
 * lane i = 0..3 from the halfword tables DAT_a00b3b10..DAT_a00b3b70, stores RCT/CFT start values per lane, reads
 * them back with FUN_a00a7314 ("1st_AEQ CH%d RCT=0x%02X, CFT=0x%04X"). When byte +0x34 of the record is set: with
 * every lane at RCT 0xf and CFT <= 7 it prints "Run optical flow"; else for rates 5 and 6 it prints "Run Triangle
 * search flow" and searches per lane over four rows (FUN_a00802cc / FUN_a007a9c0 writes, FUN_a0079b84 values,
 * FUN_a00a7314(port, 0x2e64 / 0x2e68) halves), steps RCT by 2 until all lanes reach 0xf, and writes the chosen
 * values; other rates only write 0x83d0 to 0x360c / 0x3610. Prints the final R/C of the four lanes.
 * Lane counts: E[] is filled for j below record byte 0 and the four-row init reads E[0..3]; record byte 0 is
 * written by TxFFE_Max_L (0, 3 or 4 from record byte 1), and both callers (DRV_HDMI21_RXDetect_FSM_LTS_Chk_Err,
 * DRV_HDMI_EQDetect_Timer) pass a rate equal to record byte 1, so byte 0 is 4 on the rate 5 / 6 path. rct[] and
 * cft[] are set only for rates 1..6 before the lane write loop reads them; DRV_HDMI_EQDetect_Timer passes
 * record byte 1, which TxFFE_Max_L stores from bits 27..24 of register word 0x90 (any value 1..15 when called
 * from DRV_HDMI21_RXDetect_FSM_LTS_3); for 7..15 the firmware writes the unset stack bytes.
 * Source form: every per-lane call has its own lane-index guard ('if (j < 4)') and the lane tables are const;
 * arms that the firmware shares only from a call onward are written out in full in each arm (also the 0x3140
 * call after the 0x2140 / 0x2540 / 0x2940 arms, the 0x2020..0x3020 calls after the 0x360c / 0x3610 arms and
 * the FUN_a007a630 / FUN_a007a6f0 calls of the optical and the default arm); the two 0x21f4 writes are two if
 * statements on the same rate test (the compiler threads the second test); the lane loops before the AEQ
 * search use the AEQ loop variable j; one byte variable c holds the 0x2068..0x3068 field value and the later
 * RCT step; z0[j] is assigned the && expression; the rate 1 arm writes record bytes 0x15..0x18 through a
 * block-scope pointer rec; the independent stores of the rate arms are listed in the order that gives the
 * firmware's store sequence; the local arrays are declared in the order of their frame offsets (fp-16 ..
 * fp-208); the 0xffff initializer of c0 is copied by GCC's implicit memcpy, declared with the link name
 * FUN_a00b15d8.
 */

extern unsigned char ARR_a807d680[][0xb0];
extern unsigned char DAT_a807cc50[4];
extern unsigned char DAT_a807cc60[4];
extern const unsigned int DAT_a00b3adc[];
extern unsigned int DAT_a00b3ae0;
extern const unsigned int DAT_a00b3ae4[];
extern const unsigned short DAT_a00b3b10[4], DAT_a00b3b18[4], DAT_a00b3b28[4], DAT_a00b3b30[4];
extern const unsigned short DAT_a00b3b48[4], DAT_a00b3b50[4], DAT_a00b3b70[4];
extern unsigned int DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern int FUN_a00734c4(const char *);
extern void FUN_a0073704(unsigned char);
extern void FUN_a0075360(unsigned char);
extern void FUN_a0079778(unsigned char, unsigned char, unsigned char);
extern void FUN_a0079a20(unsigned int, unsigned char);
extern void FUN_a0079aac(unsigned char);
extern unsigned char FUN_a0079ac4(unsigned char, unsigned char, unsigned char);
extern unsigned short FUN_a0079b84(unsigned char, unsigned char, unsigned char, unsigned char);
extern void FUN_a007a630(unsigned char);
extern void FUN_a007a6f0(unsigned char);
extern void FUN_a007a79c(unsigned int, int);
extern void FUN_a007a9c0(unsigned int, unsigned char, unsigned char *, unsigned short *);
extern void FUN_a007ab94(unsigned char);
extern void FUN_a007ac7c(unsigned char);
extern void FUN_a00802cc(unsigned int, unsigned char, unsigned char *, unsigned short *);
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);
extern void FUN_a00a7424(int, unsigned int, unsigned char, unsigned short);
extern void FUN_a00a7488(unsigned char, unsigned short, unsigned int, unsigned int);
extern void FUN_a00b1794(int);
extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a00b15d8");
static const char fn_[] = "DRV_HDMI21_Set_PHY";

void DRV_HDMI21_Set_PHY(port, rate)
    unsigned char port, rate;
{
    unsigned short t, d2;
    unsigned int w;
    unsigned char k, i, j, sel, v8, ok, mask, c, d9;
    unsigned short v;
    unsigned char z0[4] = {0};
    unsigned char E[4];
    unsigned char R[4][4];
    unsigned char s30[4] = {0};
    unsigned char s38[4] = {0};
    unsigned char s40[4] = {0};
    unsigned short M[4][4];
    unsigned short m0[4] = {0};
    unsigned short N[4][4];
    unsigned short n1[4] = {0};
    unsigned short n0[4] = {0};
    unsigned short P[4][4];
    unsigned short c0[4] = {0xffff, 0xffff, 0xffff, 0xffff};
    unsigned char rct[4];
    unsigned short cft[4];

    d2 = 0;
    v = 0;
    d9 = 0;
    if (port == 2)
        k = 0;
    else if (port == 3)
        k = 1;
    else
        return;
    if (DAT_a8078634 & 0x800)
        FUN_a0073044("[HDMI21]: \x1b[35;1mPort%c  %s u8FRL_Rate %d\n\x1b[m", (char)(port + 0x41), fn_, rate);
    FUN_a0073704(port);
    FUN_a00b1794(1);
    FUN_a007ab94(port);
    FUN_a007ac7c(port);
    if ((unsigned char)(rate - 1) < 3) {
        FUN_a00a7424(1, 0x1b, port, 0x2e5c);
        FUN_a00a7424(1, 0x1b, port, 0x2e38);
        FUN_a00a7488(port, 0x2e00, 0xfffffff0, 7);
        FUN_a00a7424(0, 0x1d, port, 0x3618);
        FUN_a00a7424(1, 0x1c, port, 0x3618);
        FUN_a00a7488(port, 0x3618, 0xf8ffffff, 0x3000000);
    } else {
        FUN_a00a7424(0, 0x1b, port, 0x2e5c);
        FUN_a00a7424(0, 0x1b, port, 0x2e38);
        FUN_a00a7488(port, 0x2e00, 0xfffffff0, 0xf);
        FUN_a00a7424(1, 0x1d, port, 0x3618);
        FUN_a00a7424(1, 0x1c, port, 0x3618);
        FUN_a00a7488(port, 0x3618, 0xf8ffffff, 0x4000000);
    }
    FUN_a0079778(port, 1, 1);
    FUN_a00a7424(1, 0x14, port, 0x2f08);
    FUN_a00a7424(0, 0x14, port, 0x2f08);
    FUN_a00a7488(port, 0x2000, 0xffffff00, 0xf9);
    if ((unsigned char)(rate - 4) < 3) {
        FUN_a00a7424(1, 4, port, 0x3608);
        FUN_a00a7424(1, 5, port, 0x3608);
        FUN_a00a7424(1, 0, port, 0x1140);
    } else {
        FUN_a00a7424(0, 4, port, 0x3608);
        FUN_a00a7424(0, 0, port, 0x1140);
    }
    FUN_a00a7424(1, 0x10, port, 0x2c04);
    FUN_a00a7424(1, 0x13, port, 0x2c04);
    FUN_a00a7488(port, 0x2000, 0xff00ffff, 0x6e0000);
    FUN_a00a7424(1, 8, port, 0x3608);
    FUN_a00a7424(1, 9, port, 0x3608);
    if ((unsigned char)(rate - 2) < 5)
        FUN_a00a7488(port, 0x3608, 0xff00ffff, 0xc0000);
    else
        FUN_a00a7488(port, 0x3608, 0xff00ffff, 0x50000);
    FUN_a00a7424(1, 0x18, port, 0x2f40);
    v8 = rate == 6 ? 0 : 0xf0;
    for (j = 0; j < 4; j++) {
        if (j < 4)
            FUN_a00a7488(port, DAT_a00b3b50[j], 0xffff00ff, 0x8800);
        if (j < 4)
            FUN_a00a7488(port, DAT_a00b3b30[j], 0xff00ffff, v8 << 16);
        if (j < 4)
            FUN_a00a7488(port, DAT_a00b3b48[j], 0xffff00ff, 0x8800);
        if (j < 4)
            FUN_a00a7488(port, DAT_a00b3b28[j], 0xff00ffff, 0x300000);
    }
    FUN_a00a7488(port, 0x201c, 0xffffff, 0x88000000);
    for (j = 0; j < 4; j++) {
        if (j < 4)
            FUN_a00a7488(port, DAT_a00b3b10[j], 0xff00ffff, 0xff0000);
        if (j < 4)
            FUN_a00a7488(port, DAT_a00b3b10[j], 0xffffff00, 0xa0);
        if (j < 4)
            FUN_a00a7424(0, 0x10, port, DAT_a00b3b70[j]);
        if (j < 4)
            FUN_a00a7424(0, 0x11, port, DAT_a00b3b70[j]);
    }
    if ((unsigned char)(rate - 2) < 3) {
        DAT_a807cc50[3] = 0;
        DAT_a807cc50[2] = 0;
        rct[0] = DAT_a00b3ae4[0];
        DAT_a807cc50[1] = 0;
        DAT_a807cc50[0] = 0;
        rct[1] = DAT_a00b3ae4[0];
        rct[2] = DAT_a00b3ae4[0];
        rct[3] = DAT_a00b3ae4[0];
        DAT_a807cc60[3] = 0;
        DAT_a807cc60[2] = 0;
        DAT_a807cc60[1] = 0;
        DAT_a807cc60[0] = 0;
        cft[0] = DAT_a00b3adc[0];
        cft[1] = DAT_a00b3adc[0];
        cft[2] = DAT_a00b3adc[0];
        cft[3] = DAT_a00b3adc[0];
    } else if (rate == 1) {
        unsigned char *rec = ARR_a807d680[k];

        DAT_a807cc50[3] = 1;
        DAT_a807cc50[2] = 1;
        rec[0x18] = 1;
        rec[0x17] = 1;
        rec[0x16] = 1;
        rct[0] = DAT_a00b3ae4[1];
        DAT_a807cc50[1] = 1;
        DAT_a807cc50[0] = 1;
        rec[0x15] = 1;
        rct[1] = DAT_a00b3ae4[1];
        rct[2] = DAT_a00b3ae4[1];
        rct[3] = DAT_a00b3ae4[1];
        DAT_a807cc60[3] = 1;
        DAT_a807cc60[2] = 1;
        DAT_a807cc60[1] = 1;
        cft[0] = DAT_a00b3adc[1];
        cft[1] = DAT_a00b3adc[1];
        cft[2] = DAT_a00b3adc[1];
        cft[3] = DAT_a00b3adc[1];
        DAT_a807cc60[0] = 1;
    } else if ((unsigned char)(rate - 5) < 2) {
        rct[0] = 8;
        rct[1] = 8;
        rct[2] = 8;
        rct[3] = 8;
        cft[0] = 0xf;
        cft[1] = 0xf;
        cft[2] = 0xf;
        cft[3] = 0xf;
    }
    for (j = 0; j < 4; j++) {
        if (j < 4)
            FUN_a00a7488(port, DAT_a00b3b18[j], 0xff0000f0, (rct[j] & 0xf) | (cft[j] << 8));
    }
    FUN_a00a7424(1, 7, port, 0x201c);
    FUN_a00a7424(1, 7, port, 0x241c);
    FUN_a00a7424(1, 7, port, 0x281c);
    FUN_a00a7424(1, 7, port, 0x301c);
    if ((unsigned char)(rate - 4) < 3) {
        FUN_a00a7488(port, 0x201c, 0xfffffff9, 6);
        FUN_a00a7488(port, 0x241c, 0xfffffff9, 6);
        FUN_a00a7488(port, 0x281c, 0xfffffff9, 6);
        FUN_a00a7488(port, 0x301c, 0xfffffff9, 6);
    } else if (rate == 1 || rate == 3 || rate == 2) {
        FUN_a00a7488(port, 0x201c, 0xfffffff9, 4);
        FUN_a00a7488(port, 0x241c, 0xfffffff9, 4);
        FUN_a00a7488(port, 0x281c, 0xfffffff9, 4);
        FUN_a00a7488(port, 0x301c, 0xfffffff9, 4);
    }
    if (rate == 6) {
        FUN_a00a7488(port, 0x3614, 0xffffff00, 0x55);
        FUN_a00a7488(port, 0x3614, 0xffff00ff, 0x5500);
    } else {
        FUN_a00a7488(port, 0x3614, 0xffffff00, 0);
        FUN_a00a7488(port, 0x3614, 0xffff00ff, 0);
    }
    if ((unsigned char)(rate - 2) < 5)
        FUN_a00a7488(port, 0x2f44, 0xffffffc0, 0x3f);
    else if (rate == 1)
        FUN_a00a7488(port, 0x2f44, 0xffffffc0, 0x1f);
    if (rate == 6) {
        FUN_a00a7488(port, 0x360c, 0xffff0000, 0x3fd0);
        FUN_a00a7488(port, 0x360c, 0xffff, 0x3fd00000);
        FUN_a00a7488(port, 0x3610, 0xffff0000, 0x3fd0);
        FUN_a00a7488(port, 0x3610, 0xffff, 0x3fd00000);
        FUN_a00a7488(port, 0x2020, 0xffcfffff, 0x300000);
        FUN_a00a7488(port, 0x2420, 0xffcfffff, 0x300000);
        FUN_a00a7488(port, 0x2820, 0xffcfffff, 0x300000);
        FUN_a00a7488(port, 0x3020, 0xffcfffff, 0x300000);
    } else {
        if ((unsigned char)(rate - 4) < 2) {
            FUN_a00a7488(port, 0x360c, 0xffff0000, 0x3d0);
            FUN_a00a7488(port, 0x360c, 0xffff, 0x3d00000);
            FUN_a00a7488(port, 0x3610, 0xffff0000, 0x3d0);
            FUN_a00a7488(port, 0x3610, 0xffff, 0x3d00000);
            FUN_a00a7488(port, 0x2020, 0xffcfffff, 0x100000);
            FUN_a00a7488(port, 0x2420, 0xffcfffff, 0x100000);
            FUN_a00a7488(port, 0x2820, 0xffcfffff, 0x100000);
            FUN_a00a7488(port, 0x3020, 0xffcfffff, 0x100000);
        } else {
            FUN_a00a7488(port, 0x360c, 0xffff0000, 0x83d0);
            FUN_a00a7488(port, 0x360c, 0xffff, 0x83d00000);
            FUN_a00a7488(port, 0x3610, 0xffff0000, 0x83d0);
            FUN_a00a7488(port, 0x3610, 0xffff, 0x83d00000);
            FUN_a00a7488(port, 0x2020, 0xffcfffff, 0x100000);
            FUN_a00a7488(port, 0x2420, 0xffcfffff, 0x100000);
            FUN_a00a7488(port, 0x2820, 0xffcfffff, 0x100000);
            FUN_a00a7488(port, 0x3020, 0xffcfffff, 0x100000);
        }
    }
    FUN_a00a7488(port, 0x23c0, 0xffff00ff, 0x5000);
    FUN_a00a7488(port, 0x27c0, 0xffff00ff, 0x1000);
    FUN_a00a7488(port, 0x2bc0, 0xffff00ff, 0x1000);
    FUN_a00a7488(port, 0x33c0, 0xffff00ff, 0x1000);
    FUN_a00a7488(port, 0x3614, 0xff00ffff, 0x7c0000);
    FUN_a00a7488(port, 0x3614, 0xffffff, 0xff000000);
    FUN_a00a7488(port, 0x3618, 0xffffff00, 0xff);
    FUN_a00a7488(port, 0x3620, 0xffffff00, 0);
    FUN_a00a7488(port, 0x3620, 0xffff00ff, 0x100);
    FUN_a00a7488(port, 0x2020, 0xffffff, 0xa2000000);
    FUN_a00a7424(1, 0x10, port, 0x2004);
    FUN_a00a7424(1, 0x10, port, 0x2404);
    FUN_a00a7424(1, 0x10, port, 0x2804);
    FUN_a00a7424(1, 0x10, port, 0x3004);
    FUN_a00a7424(1, 0, port, 0x3600);
    FUN_a00a7424(1, 1, port, 0x3600);
    FUN_a0075360(port);
    FUN_a00a7424(1, 0x10, port, 0x361c);
    FUN_a00a7424(1, 0x11, port, 0x361c);
    FUN_a00a7424(1, 0x12, port, 0x361c);
    FUN_a00a7488(port, 0x361c, 0xff8fffff, 0x600000);
    if ((unsigned char)(rate - 4) < 3) {
        FUN_a00a7488(port, 0x2028, 0xffffff, 0x31000000);
        FUN_a00a7488(port, 0x2008, 0xffffff, 0x3a000000);
    } else if ((unsigned char)(rate - 1) < 3) {
        FUN_a00a7488(port, 0x2028, 0xffffff, 0x30000000);
        FUN_a00a7488(port, 0x2008, 0xffffff, 0x3b000000);
    }
    FUN_a00a7424(1, 8, port, 0x200c);
    if (rate == 1)
        FUN_a00a7488(port, 0x200c, 0xfffff9ff, 0x400);
    else if ((unsigned char)(rate - 2) < 2)
        FUN_a00a7488(port, 0x200c, 0xfffff9ff, 0x200);
    else
        FUN_a00a7488(port, 0x200c, 0xfffff9ff, 0);
    FUN_a00a7488(port, 0x2034, 0xff00ffff, 0xf00000);
    if (rate == 1) {
        FUN_a00a7488(port, 0x2014, 0xff0fffff, 0x800000);
        FUN_a00a7488(port, 0x2414, 0xff0fffff, 0x800000);
        FUN_a00a7488(port, 0x2814, 0xff0fffff, 0x800000);
        FUN_a00a7488(port, 0x3014, 0xff0fffff, 0x800000);
    } else {
        FUN_a00a7488(port, 0x2014, 0xff0fffff, 0xf00000);
        FUN_a00a7488(port, 0x2414, 0xff0fffff, 0xf00000);
        FUN_a00a7488(port, 0x2814, 0xff0fffff, 0xf00000);
        FUN_a00a7488(port, 0x3014, 0xff0fffff, 0xf00000);
    }
    if ((unsigned char)(rate - 2) < 5)
        FUN_a00a7424(1, 8, port, 0x3600);
    else
        FUN_a00a7424(0, 8, port, 0x3600);
    FUN_a00a7488(port, 0x3534, 0xffff00ff, 0xe000);
    if ((unsigned char)(rate - 1) < 3) {
        FUN_a00a7424(1, 0x11, port, 0x2014);
        FUN_a00a7424(1, 0x11, port, 0x2414);
        FUN_a00a7424(1, 0x11, port, 0x2814);
        FUN_a00a7424(1, 0x11, port, 0x3014);
        FUN_a00a7488(port, 0x2018, 0xff9fffff, 0x200000);
        FUN_a00a7488(port, 0x2418, 0xff9fffff, 0x200000);
        FUN_a00a7488(port, 0x2818, 0xff9fffff, 0x200000);
        FUN_a00a7488(port, 0x3018, 0xff9fffff, 0x200000);
        FUN_a00a7488(port, 0x2018, 0xffff9fff, 0);
        FUN_a00a7488(port, 0x2418, 0xffff9fff, 0);
        FUN_a00a7488(port, 0x2818, 0xffff9fff, 0);
        FUN_a00a7488(port, 0x3018, 0xffff9fff, 0);
    } else {
        FUN_a00a7424(0, 0x11, port, 0x2014);
        FUN_a00a7424(0, 0x11, port, 0x2414);
        FUN_a00a7424(0, 0x11, port, 0x2814);
        FUN_a00a7424(0, 0x11, port, 0x3014);
        FUN_a00a7488(port, 0x2018, 0xff9fffff, 0x400000);
        FUN_a00a7488(port, 0x2418, 0xff9fffff, 0x400000);
        FUN_a00a7488(port, 0x2818, 0xff9fffff, 0x400000);
        FUN_a00a7488(port, 0x3018, 0xff9fffff, 0x400000);
        FUN_a00a7488(port, 0x2018, 0xffff9fff, 0x4000);
        FUN_a00a7488(port, 0x2418, 0xffff9fff, 0x4000);
        FUN_a00a7488(port, 0x2818, 0xffff9fff, 0x4000);
        FUN_a00a7488(port, 0x3018, 0xffff9fff, 0x4000);
    }
    FUN_a00a7488(port, 0x2154, 0xffffff, 0x2000000);
    FUN_a00a7424(1, 0x15, port, 0x2148);
    FUN_a00a7424(1, 0x15, port, 0x2548);
    FUN_a00a7424(1, 0x15, port, 0x2948);
    FUN_a00a7424(1, 0x15, port, 0x3148);
    FUN_a00a7488(port, 0x2104, 0xffffff00, 3);
    FUN_a00a7488(port, 0x2108, 0xffffff00, 5);
    FUN_a00a7488(port, 0x2108, 0xffff00ff, 0x100);
    FUN_a00a7488(port, 0x2504, 0xffffff00, 3);
    FUN_a00a7488(port, 0x2508, 0xffffff00, 5);
    FUN_a00a7488(port, 0x2508, 0xffff00ff, 0x100);
    FUN_a00a7488(port, 0x2904, 0xffffff00, 3);
    FUN_a00a7488(port, 0x2908, 0xffffff00, 5);
    FUN_a00a7488(port, 0x2908, 0xffff00ff, 0x100);
    FUN_a00a7488(port, 0x3104, 0xffffff00, 3);
    FUN_a00a7488(port, 0x3108, 0xffffff00, 5);
    FUN_a00a7488(port, 0x3108, 0xffff00ff, 0x100);
    FUN_a00a7488(port, 0x2154, 0xffffff00, 0xf0);
    FUN_a00a7488(port, 0x2154, 0xffffe0ff, 0);
    FUN_a00a7488(port, 0x214c, 0xffff00ff, 0x600);
    FUN_a00a7488(port, 0x2160, 0xfcffffff, 0x3000000);
    FUN_a00a7488(port, 0x2160, 0xf3ffffff, 0x8000000);
    FUN_a00a7424(1, 0x1c, port, 0x2160);
    FUN_a00a7424(1, 0x1d, port, 0x2160);
    FUN_a00a7424(1, 0x1e, port, 0x2160);
    FUN_a00a7424(1, 0x12, port, 0x215c);
    FUN_a00a7424(0, 0x13, port, 0x215c);
    FUN_a00a7424(0, 0x14, port, 0x215c);
    FUN_a00a7424(0, 0x15, port, 0x215c);
    FUN_a00a7424(1, 0x16, port, 0x215c);
    if (rate > 3) {
        FUN_a00a7424(1, 0, port, 0x2140);
        FUN_a00a7424(1, 0, port, 0x2540);
        FUN_a00a7424(1, 0, port, 0x2940);
        FUN_a00a7424(1, 0, port, 0x3140);
    } else {
        FUN_a00a7424(0, 0, port, 0x2140);
        FUN_a00a7424(1, 0, port, 0x2540);
        FUN_a00a7424(1, 0, port, 0x2940);
        FUN_a00a7424(1, 0, port, 0x3140);
    }
    FUN_a00a7488(port, 0x21f0, 0xffffff00, 0x80);
    if (rate == 1)
        FUN_a00a7488(port, 0x21f4, 0xffff0fff, 0x8000);
    else
        FUN_a00a7488(port, 0x21f4, 0xffff0fff, 0xf000);
    if (rate == 1)
        FUN_a00a7488(port, 0x21f4, 0xfffffc00, 0x96);
    else if ((unsigned char)(rate - 2) < 2)
        FUN_a00a7488(port, 0x21f4, 0xfffffc00, 300);
    else if (rate == 4)
        FUN_a00a7488(port, 0x21f4, 0xfffffc00, 400);
    else if (rate == 5)
        FUN_a00a7488(port, 0x21f4, 0xfffffc00, 500);
    else if (rate == 6)
        FUN_a00a7488(port, 0x21f4, 0xfffffc00, 600);
    FUN_a00a7424(0, 0x1b, port, 0x3604);
    FUN_a00a7488(port, 0x2f44, 0xffff00ff, 0x7100);
    FUN_a00a7488(port, 0x2f44, 0xff00ffff, 0x710000);
    FUN_a00a7488(port, 0x2f44, 0xffffff, 0x71000000);
    FUN_a00a7488(port, 0x2f48, 0xffffff00, 0x71);
    sel = 0;
    if ((unsigned char)(rate - 5) < 2) {
        sel = 1;
        c = 3;
    } else {
        c = 0x13;
        if (rate == 4) {
            sel = 1;
            c = 5;
        }
    }
    FUN_a00a7488(port, 0x2060, 0xffcfffff, 0);
    FUN_a00a7488(port, 0x2460, 0xffcfffff, 0);
    FUN_a00a7488(port, 0x2860, 0xffcfffff, 0);
    FUN_a00a7488(port, 0x3060, 0xffcfffff, 0);
    FUN_a00a7488(port, 0x2060, 0xff3fffff, 0x800000);
    FUN_a00a7488(port, 0x2460, 0xff3fffff, 0x800000);
    FUN_a00a7488(port, 0x2860, 0xff3fffff, 0x800000);
    FUN_a00a7488(port, 0x3060, 0xff3fffff, 0x800000);
    if (rate == 1) {
        FUN_a00a7424(0, 0x13, port, 0x2c34);
        FUN_a00a7424(1, 0x19, port, 0x2c34);
        FUN_a00a7424(0, 0x10, port, 0x2c34);
        FUN_a00a7424(0, 0x11, port, 0x2c34);
        FUN_a00a7424(0, 0x12, port, 0x2c34);
        FUN_a00a7488(port, 0x2c30, 0xfff0ffff, 0xb0000);
        FUN_a00a7488(port, 0x2c30, 0xff0fffff, 0x400000);
        FUN_a00a7488(port, 0x2c30, 0xf0ffffff, 0xd000000);
        FUN_a00a7488(port, 0x2c30, 0xfffffff, 0x20000000);
        FUN_a00a7424(0, 0, port, 0x2c30);
        FUN_a00a7488(port, 0x2c34, 0xff1fffff, 0xc00000);
        FUN_a00a7488(port, 0x2c38, 0xfffff1ff, 0);
        FUN_a00a7488(port, 0x2c34, 0xfffff3ff, 0);
        FUN_a00a7424(0, 0x14, port, 0x2c34);
        FUN_a00a7488(port, 0x2c24, 0xfcffffff, 0);
        FUN_a00a7424(0, 5, port, 0x2c20);
        FUN_a00a7424(0, 4, port, 0x2c20);
    } else if ((unsigned char)(rate - 2) < 2) {
        FUN_a00a7424(0, 0x13, port, 0x2c34);
        FUN_a00a7424(1, 0x19, port, 0x2c34);
        FUN_a00a7424(0, 0x10, port, 0x2c34);
        FUN_a00a7424(0, 0x11, port, 0x2c34);
        FUN_a00a7424(0, 0x12, port, 0x2c34);
        FUN_a00a7488(port, 0x2c30, 0xfff0ffff, 0xb0000);
        FUN_a00a7488(port, 0x2c30, 0xff0fffff, 0x400000);
        FUN_a00a7488(port, 0x2c30, 0xf0ffffff, 0xd000000);
        FUN_a00a7488(port, 0x2c30, 0xfffffff, 0x20000000);
        FUN_a00a7424(0, 0, port, 0x2c30);
        FUN_a00a7488(port, 0x2c34, 0xff1fffff, 0xc00000);
        FUN_a00a7488(port, 0x2c38, 0xfffff1ff, 0);
        FUN_a00a7488(port, 0x2c34, 0xfffff3ff, 0);
        FUN_a00a7424(0, 0x14, port, 0x2c34);
        FUN_a00a7488(port, 0x2c24, 0xfcffffff, 0);
        FUN_a00a7424(0, 5, port, 0x2c20);
        FUN_a00a7424(0, 4, port, 0x2c20);
    } else if (rate == 4) {
        FUN_a00a7424(1, 0x13, port, 0x2c34);
        FUN_a00a7424(0, 0x19, port, 0x2c34);
        FUN_a00a7424(1, 0x10, port, 0x2c34);
        FUN_a00a7424(0, 0x11, port, 0x2c34);
        FUN_a00a7424(1, 0x12, port, 0x2c34);
        FUN_a00a7488(port, 0x2c30, 0xfff0ffff, 0xa0000);
        FUN_a00a7488(port, 0x2c30, 0xff0fffff, 0x300000);
        FUN_a00a7488(port, 0x2c30, 0xf0ffffff, 0xc000000);
        FUN_a00a7488(port, 0x2c30, 0xfffffff, 0x10000000);
        FUN_a00a7424(1, 0, port, 0x2c30);
        FUN_a00a7488(port, 0x2c34, 0xff1fffff, 0x800000);
        FUN_a00a7488(port, 0x2c38, 0xfffff1ff, 0x600);
        FUN_a00a7488(port, 0x2c34, 0xfffff3ff, 0xc00);
        FUN_a00a7424(1, 0x14, port, 0x2c34);
        FUN_a00a7488(port, 0x2c24, 0xfcffffff, 0x3000000);
        FUN_a00a7424(1, 5, port, 0x2c20);
        FUN_a00a7424(0, 4, port, 0x2c20);
        FUN_a00b1794(1);
        FUN_a00a7424(1, 4, port, 0x2c20);
    } else if (rate == 5) {
        FUN_a00a7424(1, 0x13, port, 0x2c34);
        FUN_a00a7424(0, 0x19, port, 0x2c34);
        FUN_a00a7424(1, 0x10, port, 0x2c34);
        FUN_a00a7424(1, 0x11, port, 0x2c34);
        FUN_a00a7424(0, 0x12, port, 0x2c34);
        FUN_a00a7488(port, 0x2c30, 0xfff0ffff, 0xa0000);
        FUN_a00a7488(port, 0x2c30, 0xff0fffff, 0x300000);
        FUN_a00a7488(port, 0x2c30, 0xf0ffffff, 0xc000000);
        FUN_a00a7488(port, 0x2c30, 0xfffffff, 0x10000000);
        FUN_a00a7424(1, 0, port, 0x2c30);
        FUN_a00a7488(port, 0x2c34, 0xff1fffff, 0x800000);
        FUN_a00a7488(port, 0x2c38, 0xfffff1ff, 0x600);
        FUN_a00a7488(port, 0x2c34, 0xfffff3ff, 0xc00);
        FUN_a00a7424(1, 0x14, port, 0x2c34);
        FUN_a00a7488(port, 0x2c24, 0xfcffffff, 0x3000000);
        FUN_a00a7424(1, 5, port, 0x2c20);
        FUN_a00a7424(0, 4, port, 0x2c20);
        FUN_a00b1794(1);
        FUN_a00a7424(1, 4, port, 0x2c20);
    } else if (rate == 6) {
        FUN_a00a7424(1, 0x13, port, 0x2c34);
        FUN_a00a7424(0, 0x19, port, 0x2c34);
        FUN_a00a7424(1, 0x10, port, 0x2c34);
        FUN_a00a7424(1, 0x11, port, 0x2c34);
        FUN_a00a7424(0, 0x12, port, 0x2c34);
        FUN_a00a7488(port, 0x2c30, 0xfff0ffff, 0xa0000);
        FUN_a00a7488(port, 0x2c30, 0xff0fffff, 0x300000);
        FUN_a00a7488(port, 0x2c30, 0xf0ffffff, 0xc000000);
        FUN_a00a7488(port, 0x2c30, 0xfffffff, 0x10000000);
        FUN_a00a7424(1, 0, port, 0x2c30);
        FUN_a00a7488(port, 0x2c34, 0xff1fffff, 0x800000);
        FUN_a00a7488(port, 0x2c38, 0xfffff1ff, 0x600);
        FUN_a00a7488(port, 0x2c34, 0xfffff3ff, 0xc00);
        FUN_a00a7424(1, 0x14, port, 0x2c34);
        FUN_a00a7488(port, 0x2c24, 0xfcffffff, 0x3000000);
        FUN_a00a7424(1, 5, port, 0x2c20);
        FUN_a00a7424(0, 4, port, 0x2c20);
        FUN_a00b1794(1);
        FUN_a00a7424(1, 4, port, 0x2c20);
    }
    FUN_a00a7488(port, 0x2068, 0xff00ffff, c << 16);
    FUN_a00a7488(port, 0x2468, 0xff00ffff, c << 16);
    FUN_a00a7488(port, 0x2868, 0xff00ffff, c << 16);
    FUN_a00a7488(port, 0x3068, 0xff00ffff, c << 16);
    FUN_a007ab94(port);
    if (sel) {
        FUN_a00a7424(1, 3, port, 0x2070);
        FUN_a00a7424(1, 3, port, 0x2470);
        FUN_a00a7424(1, 3, port, 0x2870);
        FUN_a00a7424(1, 3, port, 0x3070);
        FUN_a00a7488(port, 0x2028, 0xff00ffff, 0x20000);
        FUN_a00a7488(port, 0x2428, 0xff00ffff, 0x20000);
        FUN_a00a7488(port, 0x2828, 0xff00ffff, 0x20000);
        FUN_a00a7488(port, 0x3028, 0xff00ffff, 0x20000);
        FUN_a00a7488(port, 0x2008, 0xff00ffff, 0x120000);
        FUN_a00a7488(port, 0x2408, 0xff00ffff, 0x120000);
        FUN_a00a7488(port, 0x2808, 0xff00ffff, 0x120000);
        FUN_a00a7488(port, 0x3008, 0xff00ffff, 0x120000);
        FUN_a00a7424(1, 0x11, port, 0x2008);
        FUN_a00a7424(1, 0x11, port, 0x2408);
        FUN_a00a7424(1, 0x11, port, 0x2808);
        FUN_a00a7424(1, 0x11, port, 0x3008);
        FUN_a00a7424(1, 0x18, port, 0x2028);
        FUN_a00a7424(0, 0x18, port, 0x2008);
    } else if (rate == 6) {
        FUN_a00a7488(port, 0x2028, 0xff00ffff, 0x20000);
        FUN_a00a7488(port, 0x2428, 0xff00ffff, 0x20000);
        FUN_a00a7488(port, 0x2828, 0xff00ffff, 0x20000);
        FUN_a00a7488(port, 0x3028, 0xff00ffff, 0x20000);
        FUN_a00a7488(port, 0x2008, 0xff00ffff, 0x120000);
        FUN_a00a7488(port, 0x2408, 0xff00ffff, 0x120000);
        FUN_a00a7488(port, 0x2808, 0xff00ffff, 0x120000);
        FUN_a00a7488(port, 0x3008, 0xff00ffff, 0x120000);
        FUN_a00a7424(1, 3, port, 0x2070);
        FUN_a00a7424(1, 3, port, 0x2470);
        FUN_a00a7424(1, 3, port, 0x2870);
        FUN_a00a7424(1, 3, port, 0x3070);
    } else {
        FUN_a00a7488(port, 0x2028, 0xff00ffff, 0);
        FUN_a00a7488(port, 0x2428, 0xff00ffff, 0);
        FUN_a00a7488(port, 0x2828, 0xff00ffff, 0);
        FUN_a00a7488(port, 0x3028, 0xff00ffff, 0);
        FUN_a00a7488(port, 0x2008, 0xff00ffff, 0x100000);
        FUN_a00a7488(port, 0x2408, 0xff00ffff, 0x100000);
        FUN_a00a7488(port, 0x2808, 0xff00ffff, 0x100000);
        FUN_a00a7488(port, 0x3008, 0xff00ffff, 0x100000);
        FUN_a00a7424(0, 3, port, 0x2070);
        FUN_a00a7424(0, 3, port, 0x2470);
        FUN_a00a7424(0, 3, port, 0x2870);
        FUN_a00a7424(0, 3, port, 0x3070);
        FUN_a00a7424(0, 0x18, port, 0x2028);
        FUN_a00a7424(0, 0x11, port, 0x2028);
        FUN_a00a7424(0, 0x11, port, 0x2428);
        FUN_a00a7424(0, 0x11, port, 0x2828);
        FUN_a00a7424(0, 0x11, port, 0x3028);
    }
    FUN_a00a7488(port, 0x2c00, 0xffffff00, 0);
    if ((unsigned char)(rate - 1) < 2) {
        FUN_a00a7424(1, 0x1b, port, 0x2e5c);
        FUN_a00a7424(1, 0x1b, port, 0x2e38);
        FUN_a00a7488(port, 0x2e00, 0xfffffff0, 7);
        FUN_a00a7424(1, 0x17, port, 0x2e04);
    } else {
        FUN_a00a7424(0, 0x1b, port, 0x2e5c);
        FUN_a00a7424(0, 0x1b, port, 0x2e38);
        FUN_a00a7488(port, 0x2e00, 0xfffffff0, 0xf);
        FUN_a00a7424(0, 0x17, port, 0x2e04);
    }
    FUN_a00b1794(10);
    FUN_a0079778(port, 0, 1);
    FUN_a00b1794(1);
    for (j = 0; j < ARR_a807d680[k][0]; j++) {
        if (j < 4)
            rct[j] = FUN_a00a7314(port, DAT_a00b3b18[j]) & 0xf;
        if (j < 4)
            cft[j] = (FUN_a00a7314(port, DAT_a00b3b18[j]) & 0xffff00) >> 8;
        if (DAT_a8078634 & 0x800)
            FUN_a0073044("[HDMI21]:     1st_AEQ CH%d RCT=0x%02X, CFT=0x%04X\n", j, rct[j], cft[j]);
    }
    if (ARR_a807d680[k][0x34] == 0)
        return;
    ok = 1;
    for (j = 0; j < ARR_a807d680[k][0]; j++)
        if (rct[j] != 0xf || cft[j] > 7)
            ok = 0;
    if (ok) {
        FUN_a00734c4("Run optical flow");
        FUN_a007a630(port);
        FUN_a007a6f0(port);
    } else if ((unsigned char)(rate - 5) < 2) {
        if (rate == 6) {
            FUN_a00a7488(port, 0x360c, 0xffff0000, 0xbfd0);
            FUN_a00a7488(port, 0x360c, 0xffff, 0xbfd00000);
            FUN_a00a7488(port, 0x3610, 0xffff0000, 0xbfd0);
            FUN_a00a7488(port, 0x3610, 0xffff, 0xbfd00000);
        } else {
            FUN_a00a7488(port, 0x360c, 0xffff0000, 0x83d0);
            FUN_a00a7488(port, 0x360c, 0xffff, 0x83d00000);
            FUN_a00a7488(port, 0x3610, 0xffff0000, 0x83d0);
            FUN_a00a7488(port, 0x3610, 0xffff, 0x83d00000);
        }
        FUN_a00734c4("Run Triangle search flow\n");
        FUN_a00a7424(1, 0x17, port, 0x2e5c);
        rct[0] = 0xf;
        cft[0] = 0xff;
        rct[1] = 0xf;
        cft[1] = 0xff;
        rct[2] = 0xf;
        cft[2] = 0xff;
        rct[3] = 0xf;
        cft[3] = 0xff;
        FUN_a0079a20(port, 0xf);
        FUN_a007a9c0(port, 0xf, rct, cft);
        for (j = 0; j < ARR_a807d680[k][0]; j++)
            E[j] = FUN_a0079ac4(port, j, rate);
        for (i = 0; i < 4; i++) {
            M[i][0] = (1 << (i * 2 + E[0])) - 1;
            R[i][0] = 8;
            M[i][1] = (1 << (i * 2 + E[1])) - 1;
            M[i][2] = (1 << (i * 2 + E[2])) - 1;
            R[i][1] = 8;
            R[i][2] = 8;
            R[i][3] = 8;
            M[i][3] = (1 << (i * 2 + E[3])) - 1;
            FUN_a007a79c(port, 0xf);
            FUN_a00802cc(port, 0xf, R[i], M[i]);
            FUN_a00b1794(1);
            FUN_a007a630(port);
            FUN_a007a6f0(port);
            FUN_a00b1794(1);
            FUN_a0079aac(port);
            for (j = 0; j < ARR_a807d680[k][0]; j++) {
                if (j < 4)
                    R[i][j] = FUN_a00a7314(port, DAT_a00b3b18[j]) & 0xf;
                N[i][j] = FUN_a0079b84(port, j, rate, E[j]);
            }
        }
        for (i = 0; i < 4; i++) {
            mask = 0;
            for (j = 0; j < ARR_a807d680[k][0]; j++) {
                if ((1 << R[i][j]) - 1 < M[i][j]) {
                    mask |= 1 << j;
                    R[i][j] = i * 2 + E[j];
                }
            }
            FUN_a007a9c0(port, 0xf, R[i], M[i]);
            for (j = 0; j < ARR_a807d680[k][0]; j++) {
                if ((mask >> j) & 1)
                    N[i][j] = FUN_a0079b84(port, j, rate, E[j]);
                if (j == 0)
                    P[i][j] = FUN_a00a7314(port, 0x2e64) & 0x7fff;
                else if (j == 1)
                    P[i][j] = (FUN_a00a7314(port, 0x2e64) & 0x7fffffff) >> 16;
                else if (j == 2)
                    P[i][j] = FUN_a00a7314(port, 0x2e68) & 0x7fff;
                else if (j == 3)
                    P[i][j] = (FUN_a00a7314(port, 0x2e68) & 0x7fffffff) >> 16;
                t = P[i][j];
                w = d2;
                if (t != 0)
                    w |= (1 << i) << (j << 2);
                d2 = w;
                if ((d2 & ((1 << i) << (j << 2))) == 0) {
                    if (N[i][j] >= n1[j]) {
                        n1[j] = N[i][j];
                        s38[j] = i;
                    }
                } else if (t <= c0[j]) {
                    c0[j] = t;
                    s40[j] = i;
                }
            }
        }
        for (j = 0; j < ARR_a807d680[k][0]; j++) {
            if (((d2 >> (j << 2)) & 0xf) == 0xf) {
                s30[j] = R[s40[j]][j];
                m0[j] = M[s40[j]][j];
                n1[j] = 0;
            } else {
                n1[j] = N[s38[j]][j];
                s30[j] = R[s38[j]][j];
                m0[j] = M[s38[j]][j];
            }
        }
        for (j = 0; j < ARR_a807d680[k][0]; j++) {
            if (s30[j] == 0xf) {
                rct[j] = 0xf;
                d9 |= 1 << j;
            } else if (s30[j] == 0xe) {
                rct[j] = 0xf;
            } else {
                rct[j] = s30[j] + 2;
            }
        }
        while (d9 != 0xf) {
            FUN_a007a9c0(port, ~d9 & 0xf, rct, m0);
            for (j = 0; j < ARR_a807d680[k][0]; j++) {
                if ((~d9 >> j) & 1) {
                    n0[j] = FUN_a0079b84(port, j, rate, E[j]);
                    if (j == 0)
                        v = FUN_a00a7314(port, 0x2e64) & 0x7fff;
                    else if (j == 1)
                        v = (FUN_a00a7314(port, 0x2e64) & 0x7fffffff) >> 16;
                    else if (j == 2)
                        v = FUN_a00a7314(port, 0x2e68) & 0x7fff;
                    else if (j == 3)
                        v = (FUN_a00a7314(port, 0x2e68) & 0x7fffffff) >> 16;
                    if (n1[j] == 0) {
                        if (v == 0) {
                            n1[j] = n0[j];
                            s30[j] = rct[j];
                        } else if (v <= c0[j]) {
                            c0[j] = v;
                            s30[j] = rct[j];
                            n1[j] = 0;
                        }
                    } else if (v == 0 && n0[j] >= n1[j]) {
                        n1[j] = n0[j];
                        s30[j] = rct[j];
                    }
                }
                if (rct[j] > 14)
                    d9 |= 1 << j;
                c = rct[j] + 2;
                rct[j] = c;
                if (c == 16)
                    rct[j] = 15;
            }
        }
        for (j = 0; j < ARR_a807d680[k][0]; j++) {
            z0[j] = m0[j] != (1 << s30[j]) - 1 && m0[j] < (1 << (E[j] + 6)) - 1;
            cft[j] = ((m0[j] + 1) << z0[j]) - 1;
        }
        FUN_a007a9c0(port, 0xf, s30, cft);
        for (j = 0; j < ARR_a807d680[k][0]; j++) {
            if (z0[j]) {
                n0[j] = FUN_a0079b84(port, j, rate, E[j]);
                if (j == 0)
                    v = FUN_a00a7314(port, 0x2e64) & 0x7fff;
                else if (j == 1)
                    v = (FUN_a00a7314(port, 0x2e64) & 0x7fffffff) >> 16;
                else if (j == 2)
                    v = FUN_a00a7314(port, 0x2e68) & 0x7fff;
                else if (j == 3)
                    v = (FUN_a00a7314(port, 0x2e68) & 0x7fffffff) >> 16;
                if (n1[j] == 0) {
                    if (v == 0) {
                        n1[j] = n0[j];
                        m0[j] = cft[j];
                    } else if (v <= c0[j]) {
                        n1[j] = 0;
                        m0[j] = cft[j];
                        c0[j] = v;
                    }
                } else if (v == 0 && n0[j] >= n1[j]) {
                    n1[j] = n0[j];
                    m0[j] = cft[j];
                }
            }
        }
        FUN_a007a9c0(port, 0xf, s30, m0);
        FUN_a00a7424(0, 0x17, port, 0x2e5c);
    } else {
        FUN_a00a7488(port, 0x360c, 0xffff0000, 0x83d0);
        FUN_a00a7488(port, 0x360c, 0xffff, 0x83d00000);
        FUN_a00a7488(port, 0x3610, 0xffff0000, 0x83d0);
        FUN_a00a7488(port, 0x3610, 0xffff, 0x83d00000);
        FUN_a007a630(port);
        FUN_a007a6f0(port);
    }
    if (DAT_a8078634 & 0x800)
        FUN_a00734c4("[HDMI21]: Final register R/C:\n");
    if (DAT_a8078634 & 0x800)
        FUN_a0073044("[HDMI21]:  CH0 0x%lX, 0x%04lX\n", FUN_a00a7314(port, 0x2178) & 0xf, (FUN_a00a7314(port, 0x2178) & 0xffff00) >> 8);
    if (DAT_a8078634 & 0x800)
        FUN_a0073044("[HDMI21]:  CH1 0x%lX, 0x%04lX\n", FUN_a00a7314(port, 0x2578) & 0xf, (FUN_a00a7314(port, 0x2578) & 0xffff00) >> 8);
    if (DAT_a8078634 & 0x800)
        FUN_a0073044("[HDMI21]:  CH2 0x%lX, 0x%04lX\n", FUN_a00a7314(port, 0x2978) & 0xf, (FUN_a00a7314(port, 0x2978) & 0xffff00) >> 8);
    if (DAT_a8078634 & 0x800)
        FUN_a0073044("[HDMI21]:  CH3 0x%lX, 0x%04lX\n", FUN_a00a7314(port, 0x3178) & 0xf, (FUN_a00a7314(port, 0x3178) & 0xffff00) >> 8);
}
