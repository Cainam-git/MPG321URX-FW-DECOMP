/*
 * DRV_HDMI_EQScan_FSM_PHY_R_Turning (leon2s 0xa007769c-0xa007796c, 720 bytes), flags -mcpu=v8 -Os -g.
 * int (u8 port), returns 0. Increments byte +0x30 of the 0x898-byte record ARR_a807a9f0[port]; when byte 8 of the
 * 12-byte record ARR_a807ccc4[port] is 1 and that count is <= 5, calls DRV_HDMI_PHY_Clr_EQ_Err(port) and returns.
 * Otherwise, under bit 1 of _DAT_a8078634, prints DAT_a0066df8 (port letter, function name, count), the
 * "Jay_EQ_R_Turning" line with FUN_a00b2064(), and for the registers 0x1178 / 0x1578 / 0x1978 the CCT
 * ((FUN_a00a7314(port, reg) & 0xffff00) >> 8) and RCT (low nibble of a second read) of CH0..CH2.
 * For ch 0..2: rct = low nibble of FUN_a00a7314(port, DAT_a00b3b78[ch]); when rct <= 7 prints the "RCT < 8"
 * line (bit 1 of _DAT_a8078634) and calls FUN_a00a7424(1, 0x10, port, DAT_a00b3b04[ch]).
 * Finally word 0 of ARR_a807ccc4[port] = 0xb and the count byte = 0.
 * Source form: each table access is guarded by 'ch < 3' (as in DRV_HDMI_EQScan_FSM_PHY_RunAEQ); the rct read is
 * an if/else that sets rct = 0 in the else arm; the CCT values are passed as the shifted expression.
 */
struct EqRec {
    unsigned char _0[0x30];
    unsigned char b30;
    unsigned char _31[0x898 - 0x31];
};
struct Rec12 { unsigned int w0; unsigned int w4; unsigned char b8; unsigned char pad[3]; };
extern struct EqRec ARR_a807a9f0[];
extern struct Rec12 ARR_a807ccc4[];
extern unsigned int _DAT_a8078634;
extern const unsigned short DAT_a00b3b04[];
extern const unsigned short DAT_a00b3b78[];
extern unsigned char DAT_a0066df8[];
extern int FUN_a0073044(const void *, ...);
extern unsigned int FUN_a00b2064(void);
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);
extern void FUN_a00a7424(int, unsigned int, unsigned char, unsigned short);
extern void DRV_HDMI_PHY_Clr_EQ_Err(unsigned int);

static const char fn_[] = "DRV_HDMI_EQScan_FSM_PHY_R_Turning";

int DRV_HDMI_EQScan_FSM_PHY_R_Turning(unsigned char port)
{
    unsigned char ch;
    unsigned char rct;

    ARR_a807a9f0[port].b30++;
    if (ARR_a807ccc4[port].b8 == 1 && ARR_a807a9f0[port].b30 <= 5) {
        DRV_HDMI_PHY_Clr_EQ_Err(port);
        return 0;
    }
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0066df8, (char)(port + 'A'), fn_, ARR_a807a9f0[port].b30);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044("[EQ]: ## Port%c => Jay_EQ_R_Turning [%ld] ##\n\n", (char)(port + 'A'), FUN_a00b2064());
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044("[EQ]: # Port%c  CH0 CCT [0x%04lx] RCT [0x%02lx]\n", (char)(port + 'A'),
                     (FUN_a00a7314(port, 0x1178) & 0xffff00) >> 8, FUN_a00a7314(port, 0x1178) & 0xf);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044("[EQ]: # Port%c  CH1 CCT [0x%04lx] RCT [0x%02lx]\n", (char)(port + 'A'),
                     (FUN_a00a7314(port, 0x1578) & 0xffff00) >> 8, FUN_a00a7314(port, 0x1578) & 0xf);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044("[EQ]: # Port%c  CH2 CCT [0x%04lx] RCT [0x%02lx]\n\n", (char)(port + 'A'),
                     (FUN_a00a7314(port, 0x1978) & 0xffff00) >> 8, FUN_a00a7314(port, 0x1978) & 0xf);
    for (ch = 0; ch <= 2; ch++) {
        if (ch < 3)
            rct = FUN_a00a7314(port, DAT_a00b3b78[ch]) & 0xf;
        else
            rct = 0;
        if (rct <= 7) {
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044("[EQ]: # Port%c, CH%d, RCT = 0x%02x < 8 \n", (char)(port + 'A'), ch, rct);
            if (ch < 3)
                FUN_a00a7424(1, 0x10, port, DAT_a00b3b04[ch]);
        }
    }
    ARR_a807ccc4[port].w0 = 0xb;
    ARR_a807a9f0[port].b30 = 0;
    return 0;
}
