/* leon2s DRV_HDMI_EQScan_FSM_PHY_PreChkError @ 0xa007796c-0xa0077e68 (1276 bytes), flags -mcpu=v8 -Os -g.
 * u8 port; returns 0. With bit 1 of _DAT_a8078634 set (tested before each print) it prints, through
 * FUN_a0073044 with (char)(port + 'A'): DAT_a0066b30/b58 and DAT_a0067290 with the function name and bits
 * 16..19 of PHY register 0x1148/0x1548/0x1948 (FUN_a00a7314), DAT_a00672c0 with the low byte of 0x11f0,
 * DAT_a00672f0 with 0x11f4 >> 16 and DAT_a0067318 with bits 12..15 of 0x11f4.
 * flag = 1 when bits 16..19 of 0x1148, 0x1548 and 0x1948 are all 0xf.
 * When the low byte of 0x1018 is above 0xdf: ivco = bits 4..7 of 0x1168, print DAT_a0067358 (name) and
 * DAT_a0067388 (ivco); bit 0x15 of 0x1100/0x1500/0x1900 set (FUN_a00a7424), 0x1168 bits 8..11 = ivco + 1
 * (ivco when it is 0xf, FUN_a00a7488), bit 0xd of 0x1168 set, bit 0x15 of the three registers cleared,
 * FUN_a00b1794(5). When the low byte of 0x1018 is then at most 0x1f: print DAT_a0067398 (name), and the
 * same sequence writes the old ivco back and clears bit 0xd. flag = 1 in both cases.
 * flag set: DAT_a80761a0[port] = 6, byte 0x30 of the 0x898-byte record ARR_a807a9f0[port] = 0, and word 0
 * of the 12-byte record ARR_a807ccc4[port] = 0xb when its byte +8 is 1 (after printing DAT_a00673d0 with
 * FUN_a00b2064()), else 6. flag clear: that word = 0.
 * Source form: ivco is copied into an unsigned char before its print and test; the incremented value is an
 * unsigned char set in an if/else (an unsigned int is turned into addx arithmetic).
 */
extern unsigned int _DAT_a8078634;
extern unsigned char DAT_a0066b30[];
extern unsigned char DAT_a0066b58[];
extern unsigned char DAT_a0067290[];
extern unsigned char DAT_a00672c0[];
extern unsigned char DAT_a00672f0[];
extern unsigned char DAT_a0067318[];
extern unsigned char DAT_a0067358[];
extern unsigned char DAT_a0067388[];
extern unsigned char DAT_a0067398[];
extern unsigned char DAT_a00673d0[];
extern int FUN_a0073044(const void *, ...);
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);
extern void FUN_a00a7424(int, unsigned int, unsigned char, unsigned short);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);
extern void FUN_a00b1794(int);
extern unsigned int FUN_a00b2064(void);
struct Rec12 { unsigned int w0; unsigned int w4; unsigned char b8; unsigned char pad[3]; };
extern struct Rec12 ARR_a807ccc4[];
extern unsigned char ARR_a807a9f0[][0x898];
extern unsigned char DAT_a80761a0[];

int DRV_HDMI_EQScan_FSM_PHY_PreChkError(unsigned char port)
{
    unsigned char flag = 0;
    unsigned int ivco;
    unsigned char old;
    unsigned char n;

    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0066b30, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_PreChkError",
                     FUN_a00a7314(port, 0x1148) >> 16 & 0xf);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0066b58, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_PreChkError",
                     FUN_a00a7314(port, 0x1548) >> 16 & 0xf);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0067290, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_PreChkError",
                     FUN_a00a7314(port, 0x1948) >> 16 & 0xf);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a00672c0, (char)(port + 'A'), FUN_a00a7314(port, 0x11f0) & 0xff);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a00672f0, (char)(port + 'A'), FUN_a00a7314(port, 0x11f4) >> 16);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0067318, (char)(port + 'A'), FUN_a00a7314(port, 0x11f4) >> 12 & 0xf);

    if ((FUN_a00a7314(port, 0x1148) >> 16 & 0xf) == 0xf &&
        (FUN_a00a7314(port, 0x1548) >> 16 & 0xf) == 0xf &&
        (FUN_a00a7314(port, 0x1948) >> 16 & 0xf) == 0xf)
        flag = 1;

    if ((unsigned char)FUN_a00a7314(port, 0x1018) > 0xdf) {
        ivco = FUN_a00a7314(port, 0x1168) >> 4 & 0xf;
        old = ivco;
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(DAT_a0067358, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_PreChkError");
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(DAT_a0067388, old & 0xf);
        FUN_a00a7424(1, 0x15, port, 0x1100);
        FUN_a00a7424(1, 0x15, port, 0x1500);
        FUN_a00a7424(1, 0x15, port, 0x1900);

        if (old != 0xf)
            n = ivco + 1;
        else
            n = ivco;
        FUN_a00a7488(port, 0x1168, 0xfffff0ff, (n & 0xf) << 8);
        FUN_a00a7424(1, 0xd, port, 0x1168);
        FUN_a00a7424(0, 0x15, port, 0x1100);
        FUN_a00a7424(0, 0x15, port, 0x1500);
        FUN_a00a7424(0, 0x15, port, 0x1900);
        FUN_a00b1794(5);
        if ((unsigned char)FUN_a00a7314(port, 0x1018) <= 0x1f) {
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044(DAT_a0067398, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_PreChkError");
            FUN_a00a7424(1, 0x15, port, 0x1100);
            FUN_a00a7424(1, 0x15, port, 0x1500);
            FUN_a00a7424(1, 0x15, port, 0x1900);
            FUN_a00a7488(port, 0x1168, 0xfffff0ff, old << 8);
            FUN_a00a7424(0, 0xd, port, 0x1168);
            FUN_a00a7424(0, 0x15, port, 0x1100);
            FUN_a00a7424(0, 0x15, port, 0x1500);
            FUN_a00a7424(0, 0x15, port, 0x1900);
        }
        flag = 1;
    }

    if (flag) {
        DAT_a80761a0[port] = 6;
        ARR_a807a9f0[port][0x30] = 0;
        if (ARR_a807ccc4[port].b8 == 1) {
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044(DAT_a00673d0, (char)(port + 'A'), FUN_a00b2064());
            ARR_a807ccc4[port].w0 = 0xb;
        } else {
            ARR_a807ccc4[port].w0 = 6;
        }
    } else {
        ARR_a807ccc4[port].w0 = 0;
    }
    return 0;
}
