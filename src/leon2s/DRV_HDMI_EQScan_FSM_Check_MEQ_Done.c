/* DRV_HDMI_EQScan_FSM_Check_MEQ_Done (leon2s 0xa007d21c-0xa007d688, 1132 bytes), flags -mcpu=v8 -Os -g.
 * While byte +0x30 of the 0x898-byte record ARR_a807a9f0[port] is below 6 it counts up (DRV_HDMI_PHY_Clr_EQ_Err
 * first when it is 0) and returns 0. Otherwise per channel 0..2 the 16-bit value assembled from bytes of the
 * registers 0x1ea0 / 0x1ea4 (FUN_a00a7314) goes to the local word s[ch], printed (bit 1 of _DAT_a8078634) with
 * DAT_a0067ba8. With byte 8 of ARR_a807ccc4[port] == 0: prints DAT_a0067bd0, done[0..2] = 1,
 * DRV_HDMI_PHY_Clr_EQ_Err(port); FUN_a007d140(port) == 0: prints the retrain message (99), clears
 * DAT_a8076198[port] when a value is below 0x7fff and the three FUN_a00a7468(0x10..0x12, port, 0x1e94) are 1,
 * calls FUN_a0077e68(port, 0) when FUN_a007517c(port) is non-zero, counts DAT_a8078990[port] (Deskew_HotPlug and
 * reset after more than 10), clears DAT_a8078998[port], word 0 = 0, returns 0; a value of 0x7fff or a clear
 * bit 15 prints the "CED wrong" message, word 0 = 0, returns 0; else DAT_a8078998[port] = 1 when DAT_a807619f
 * is set, byte +0x896 = 0. With byte 8 set it prints "This function is MEQ only". Then word 0 = 0x10, returns 1.
 * Source form: the channel loop as in DRV_HDMI_EQScan_FSM_PHY_ChkError: 'for (; ch < 3; ch++)' with each arm
 * storing its whole expression in s[ch] (an intermediate variable lets cse fold the ch == 1 address early).
 */
struct EqRec {
    unsigned char vga[3];
    unsigned char b3[3];
    unsigned char _6[3];
    unsigned char idx[3];
    unsigned char _c[4];
    unsigned int w10[3];
    unsigned char _1c[0x28 - 0x1c];
    unsigned char b28;
    unsigned char _29;
    unsigned char b2a[3];
    unsigned char b2d[3];
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
extern unsigned char DAT_a8076198[];
extern unsigned char DAT_a807619f;
extern unsigned char DAT_a8078990[];
extern unsigned char DAT_a8078998[];
extern unsigned int _DAT_a8078634;
extern unsigned char DAT_a0067ba8[];
extern unsigned char DAT_a0067bd0[];
extern int FUN_a0073044(const void *, ...);
extern int FUN_a00734c4(const char *);
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);
extern unsigned int FUN_a00a7468(unsigned int, unsigned char, unsigned short);
extern void DRV_HDMI_PHY_Clr_EQ_Err(unsigned int);
extern unsigned char FUN_a007d140(unsigned char);
extern unsigned char FUN_a007517c(unsigned int);
extern void FUN_a0077e68(unsigned int, unsigned char);
extern void Deskew_HotPlug(unsigned char);

static const char fn_[] = "DRV_HDMI_EQScan_FSM_Check_MEQ_Done";

int DRV_HDMI_EQScan_FSM_Check_MEQ_Done(unsigned char port)
{
    unsigned int s[3] = {0, 0, 0};
    unsigned char ch = 0;

    if (ARR_a807a9f0[port].b30 < 6) {
        if (ARR_a807a9f0[port].b30 == 0)
            DRV_HDMI_PHY_Clr_EQ_Err(port);
        ARR_a807a9f0[port].b30++;
        return 0;
    }
    for (; ch < 3; ch++) {
        if (ch == 0)
            s[ch] = (FUN_a00a7314(port, 0x1ea0) & 0xff00) | ((FUN_a00a7314(port, 0x1ea0) >> 16) & 0xff);
        else if (ch == 1)
            s[ch] = ((FUN_a00a7314(port, 0x1ea0) & 0xff000000) >> 16) | (FUN_a00a7314(port, 0x1ea4) & 0xff);
        else
            s[ch] = (FUN_a00a7314(port, 0x1ea4) & 0xff00) | ((FUN_a00a7314(port, 0x1ea4) >> 16) & 0xff);
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(DAT_a0067ba8, (char)(port + 'A'), ch, s[ch] & 0x7fff);
    }
    if (ARR_a807ccc4[port].b8 == 0) {
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(DAT_a0067bd0, fn_, (char)(port + 'A'));
        for (ch = 0; ch <= 2; ch++)
            ARR_a807a9f0[port].done[ch] = 1;
        DRV_HDMI_PHY_Clr_EQ_Err(port);
        if (FUN_a007d140(port) == 0) {
            FUN_a0073044("MEQ:Yung TMDS Skew Fail retrain %d\n\n", 99);
            if ((s[0] & 0x7fff) < 0x7fff || (s[1] & 0x7fff) < 0x7fff || (s[2] & 0x7fff) < 0x7fff) {
                if (FUN_a00a7468(0x10, port, 0x1e94) == 1 && FUN_a00a7468(0x11, port, 0x1e94) == 1 &&
                    FUN_a00a7468(0x12, port, 0x1e94) == 1) {
                    DAT_a8076198[port] = 0;
                    if ((_DAT_a8078634 & 2) != 0)
                        FUN_a0073044("[EQ]: Port%c Skew Fail bTMDS_BIT_RATIO_GUESS[phyidx] = 0\r\n",
                                     (char)(port + 'A'));
                }
            }
            if (FUN_a007517c(port))
                FUN_a0077e68(port, 0);
            DAT_a8078990[port]++;
            DAT_a8078998[port] = 0;
            if (DAT_a8078990[port] > 10) {
                Deskew_HotPlug(port);
                DAT_a8078990[port] = 0;
            }
            ARR_a807ccc4[port].w0 = 0;
            return 0;
        }
        if ((s[0] & 0x7fff) == 0x7fff || (s[1] & 0x7fff) == 0x7fff || (s[2] & 0x7fff) == 0x7fff ||
            !(s[0] & 0x8000) || !(s[1] & 0x8000) || !(s[2] & 0x8000)) {
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044("[EQ]: Port%c CED wrong, Back to Phy init\r\n", (char)(port + 'A'));
            ARR_a807ccc4[port].w0 = 0;
            return 0;
        }
        if (DAT_a807619f != 0)
            DAT_a8078998[port] = 1;
        ARR_a807a9f0[port].b896 = 0;
    } else {
        FUN_a00734c4("This function is MEQ only\n");
    }
    ARR_a807ccc4[port].w0 = 0x10;
    return 1;
}
