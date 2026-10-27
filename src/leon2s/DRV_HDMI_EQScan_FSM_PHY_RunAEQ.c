/* DRV_HDMI_EQScan_FSM_PHY_RunAEQ (leon2s 0xa007731c-0xa007769c, 896 bytes), flags -mcpu=v8 -Os -g.
 * int (u8 port, old-style definition), returns 0. Under bit 1 of _DAT_a8078634 prints DAT_a0067170 with
 * (char)(port + 'A') and the function name, then DAT_a0066b30 / b58 / b80 with bits 16..19 of
 * FUN_a00a7314(port, 0x1148 / 0x1548 / 0x1948). For ch 0..2: writes (rct & 0xf) | (cft << 8) of the 4-byte entry
 * ch at +0x884 of the 0x898-byte record ARR_a807a9f0[port] into register DAT_a00b3b78[ch] (FUN_a00a7488, mask
 * 0xff0000f0); when byte 8 of the 12-byte record ARR_a807ccc4[port] is set: FUN_a00a7424(1, 4, port,
 * DAT_a00b3b0a[ch]), (0, 0, port, DAT_a00b3b04[ch]), FUN_a00a7488 of 0x2c0000 / 0xff0000 into bits 16..23 of
 * DAT_a00b3b04[ch] / DAT_a00b3b0a[ch], FUN_a00b1794(1), FUN_a00a7424(1, 0, ..b04), (0, 4, ..b0a), and writes
 * rct / cft again, taken from DAT_a00b3ad4[DAT_a807cc58[ch]] / DAT_a00b3acc[DAT_a807ccf8[ch]] when
 * FUN_a0073520(port) is set, else from DAT_a807619e / DAT_a807619c. Then clears byte +0x30 of the record,
 * sets DAT_a80761a0[port] = 0x32 and clears byte +0x28 when that byte is set (else 6), and sets word 0 of the
 * ARR_a807ccc4 record to 0xb when its byte 8 is set, else 0xf.
 * Source form: K&R byte parameter (masked at each use); rct and cft read into locals before the 'ch < 3' guards;
 * the last store as an if/else (a conditional expression is if-converted); the format strings are the shared
 * DAT_ objects (as in DRV_HDMI_EQScan_FSM_PHY_BA_Turning).
 */
struct AeqRes { unsigned char rct; unsigned char _1; unsigned short cft; };
struct EqRec {
    unsigned char _0[0x28];
    unsigned char b28;
    unsigned char _29[7];
    unsigned char b30;
    unsigned char _31[0x884 - 0x31];
    struct AeqRes res[3];
    unsigned char _890[8];
};
struct Rec12 { unsigned int w0; unsigned int w4; unsigned char b8; unsigned char pad[3]; };
extern struct EqRec ARR_a807a9f0[];
extern struct Rec12 ARR_a807ccc4[];
extern unsigned char DAT_a80761a0[];
extern unsigned char DAT_a807cc58[];
extern unsigned char DAT_a807ccf8[];
extern unsigned int DAT_a00b3acc[];
extern unsigned int DAT_a00b3ad4[];
extern unsigned char DAT_a807619e;
extern unsigned short DAT_a807619c;
extern unsigned int _DAT_a8078634;
extern const unsigned short DAT_a00b3b04[];
extern const unsigned short DAT_a00b3b0a[];
extern const unsigned short DAT_a00b3b78[];
extern unsigned char DAT_a0067170[];
extern unsigned char DAT_a0066b30[];
extern unsigned char DAT_a0066b58[];
extern unsigned char DAT_a0066b80[];
extern int FUN_a0073044(const void *, ...);
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);
extern void FUN_a00a7424(int, unsigned int, unsigned char, unsigned short);
extern void FUN_a00b1794(int);
extern unsigned char FUN_a0073520(unsigned char);

static const char fn_[] = "DRV_HDMI_EQScan_FSM_PHY_RunAEQ";

int DRV_HDMI_EQScan_FSM_PHY_RunAEQ(port)
    unsigned char port;
{
    unsigned char ch = 0;
    unsigned char p;
    unsigned char rct;
    unsigned short cft;

    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0067170, (char)(port + 'A'), fn_);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0066b30, (char)(port + 'A'), fn_,
                     (FUN_a00a7314(port, 0x1148) >> 16) & 0xf);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0066b58, (char)(port + 'A'), fn_,
                     (FUN_a00a7314(port, 0x1548) >> 16) & 0xf);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0066b80, (char)(port + 'A'), fn_,
                     (FUN_a00a7314(port, 0x1948) >> 16) & 0xf);
    for (; ch <= 2; ch++) {
        p = port;
        rct = ARR_a807a9f0[p].res[ch].rct;
        cft = ARR_a807a9f0[p].res[ch].cft;
        if (ch < 3)
            FUN_a00a7488(p, DAT_a00b3b78[ch], 0xff0000f0, (rct & 0xf) | (cft << 8));
        if (ARR_a807ccc4[p].b8 == 0)
            continue;
        if (ch < 3) {
            FUN_a00a7424(1, 4, p, DAT_a00b3b0a[ch]);
            FUN_a00a7424(0, 0, p, DAT_a00b3b04[ch]);
            FUN_a00a7488(p, DAT_a00b3b04[ch], 0xff00ffff, 0x2c0000);
            FUN_a00a7488(p, DAT_a00b3b0a[ch], 0xff00ffff, 0xff0000);
        }
        FUN_a00b1794(1);
        if (ch < 3) {
            FUN_a00a7424(1, 0, p, DAT_a00b3b04[ch]);
            FUN_a00a7424(0, 4, p, DAT_a00b3b0a[ch]);
        }
        if (FUN_a0073520(p)) {
            rct = DAT_a00b3ad4[DAT_a807cc58[ch]];
            cft = DAT_a00b3acc[DAT_a807ccf8[ch]];
        } else {
            rct = DAT_a807619e;
            cft = DAT_a807619c;
        }
        if (ch < 3)
            FUN_a00a7488(p, DAT_a00b3b78[ch], 0xff0000f0, (rct & 0xf) | (cft << 8));
    }
    p = port;
    ARR_a807a9f0[p].b30 = 0;
    if (ARR_a807a9f0[p].b28) {
        DAT_a80761a0[p] = 0x32;
        ARR_a807a9f0[p].b28 = 0;
    } else
        DAT_a80761a0[p] = 6;
    if (ARR_a807ccc4[p].b8)
        ARR_a807ccc4[p].w0 = 0xb;
    else
        ARR_a807ccc4[p].w0 = 0xf;
    return 0;
}
