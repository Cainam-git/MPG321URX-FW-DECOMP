/* leon2s DRV_HDMI_EQScan_FSM_PHY_BA_Turning @ 0xa0075508-0xa0075858 (848 bytes, 212 words)
 * BYTE-EXACT with -mcpu=v8 -Os -g (gcc 3.4.4): jf 100.00 match=True, rawcmp_l2s 0/212.
 * Code facts: port is a u8 parameter (the fw keeps the raw %i0 copy in %l4 and re-extends it at each
 * use). Three separate debug ifs on bit 1 of _DAT_a8078634, each prints "[EQ]: Port%c, ChN, %s [0x%02lx]"
 * (DAT_a0066b30/b58/b80) with (char)(port + 'A'), the function name and bits 16..19 of PHY register
 * 0x1148/0x1548/0x1948 (FUN_a00a7314). Jump threading turns the three ifs into the nested shape Ghidra
 * showed. Then it returns 0 unless all three channel fields are 0xf. eq = bits 4..7 of 0x1168; v = reg 0x1018:
 * v in 0x80..0x90 keeps eq, 0x70..0x7f adds 3, 0x50..0x6f and 0xb0..0xc0 add 2 (each arm clamps to 15
 * on its own; crossjumping shares the clamp), any other v sets flag = 1 and skips the EQ write. The EQ write
 * puts 0x10 in 0x1168 bits 8..15, pulses bit 0x15 of 0x1100/0x1500/0x1900 around two writes of eq << 8
 * into bits 8..11, then calls FUN_a00b1794(1). Always: 0x1018 low byte rewritten with its own value,
 * 0x1038 = 7, 0x1154 = 0x1e (low bytes), and the 12-byte record ARR_a807ccc4[port] word 0 = 0xd, or 8/6
 * when its byte +8 is 1 (8 when ARR_a8078998[port] == 1).
 * BEHAVIOUR fixes against the draft: the print takes the a7314 result (not the param) as its 4th arg;
 * the record store is a full word (st), not a byte; the param is u8, not short.
 * Levers: u8 param (an int param swaps %i0/%l4), per-arm clamp, per-arm record stores (one variable
 * gives a branch-free subx form). No aids, no volatile.
 */
extern unsigned int _DAT_a8078634;
extern unsigned char DAT_a0066b30[];
extern unsigned char DAT_a0066b58[];
extern unsigned char DAT_a0066b80[];
extern int FUN_a0073044(const void *, ...);
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);
extern void FUN_a00a7424(int, unsigned int, unsigned char, unsigned short);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);
extern void FUN_a00b1794(int);
struct Rec12 { unsigned int w0; unsigned int w4; unsigned char b8; unsigned char pad[3]; };
extern struct Rec12 ARR_a807ccc4[];
extern unsigned char ARR_a8078998[];

int DRV_HDMI_EQScan_FSM_PHY_BA_Turning(unsigned char port)
{
    unsigned int v;
    unsigned char eq;
    unsigned char flag = 0;
    int s;
    unsigned int t;

    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0066b30, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_BA_Turning",
                     FUN_a00a7314(port, 0x1148) >> 16 & 0xf);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0066b58, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_BA_Turning",
                     FUN_a00a7314(port, 0x1548) >> 16 & 0xf);
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0066b80, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_BA_Turning",
                     FUN_a00a7314(port, 0x1948) >> 16 & 0xf);
    if ((FUN_a00a7314(port, 0x1148) >> 16 & 0xf) != 0xf) return 0;
    if ((FUN_a00a7314(port, 0x1548) >> 16 & 0xf) != 0xf) return 0;
    if ((FUN_a00a7314(port, 0x1948) >> 16 & 0xf) != 0xf) return 0;
    v = FUN_a00a7314(port, 0x1018);
    eq = FUN_a00a7314(port, 0x1168) >> 4 & 0xf;
    if ((unsigned char)(v - 0x80) <= 0x10) {
    } else if ((unsigned char)(v - 0x70) <= 0xf) {
        s = eq + 3; if (s > 0xf) s = 0xf; eq = s;
    } else if ((unsigned char)(v - 0x50) <= 0x1f) {
        s = eq + 2; if (s > 0xf) s = 0xf; eq = s;
    } else if ((unsigned char)(v + 0x50) <= 0x10) {
        s = eq + 2; if (s > 0xf) s = 0xf; eq = s;
    } else {
        flag = 1;
    }
    if (flag == 0) {
        FUN_a00a7488(port, 0x1168, 0xffff00ff, 0x1000);
        FUN_a00a7424(1, 0x15, port, 0x1100);
        FUN_a00a7424(1, 0x15, port, 0x1500);
        FUN_a00a7424(1, 0x15, port, 0x1900);
        t = (eq & 0xf) << 8;
        FUN_a00a7488(port, 0x1168, 0xfffff0ff, t);
        FUN_a00a7488(port, 0x1168, 0xfffff0ff, t);
        FUN_a00a7424(0, 0x15, port, 0x1100);
        FUN_a00a7424(0, 0x15, port, 0x1500);
        FUN_a00a7424(0, 0x15, port, 0x1900);
        FUN_a00b1794(1);
    }
    FUN_a00a7488(port, 0x1018, 0xffffff00, FUN_a00a7314(port, 0x1018) & 0xff);
    FUN_a00a7488(port, 0x1038, 0xffffff00, 7);
    FUN_a00a7488(port, 0x1154, 0xffffff00, 0x1e);
    if (ARR_a807ccc4[port].b8 == 1) {
        if (ARR_a8078998[port] == 1) ARR_a807ccc4[port].w0 = 8;
        else ARR_a807ccc4[port].w0 = 6;
    } else {
        ARR_a807ccc4[port].w0 = 0xd;
    }
    return 0;
}
