/* leon2s FUN_a0095f20 @ 0xa0095f20-0xa00961e8, -mcpu=v8 -Os -g.
 * void (u8 port, u8 frl, u8 a, u8 b, u8 c, u8 d). clk = word +8 of the 0x1c-byte record DAT_a807d580[port]
 * * (b >> 1) / (4 >> a) (frl == 0, printed as "[HDMI_TX]: video_clk = %d") or * (d >> 1) / (4 >> c) (frl != 0,
 * "FRL_video_clk"). frl == 0: FUN_a00a80cc(port, 1, 0, 0x10, 0) and (port, 1, 5, 0xc0, 1), then (a, b) = (2, 8)
 * for clk <= 12, (1, 8) for <= 24, (1, 8) and FUN_a00a80cc(port, 1, 0, 0x10, 1) for <= 49, (0, 8) for <= 79,
 * else (0, 8) and FUN_a00a80cc(port, 1, 5, 0xc0, 0); frl != 0 the same on (c, d) with registers 0x80 (mask 1)
 * and 0x7f. Then FUN_a008d980 / d920 / da34 / d9d4(port, a / b / c / d) and the read-backs of registers
 * 0x00, 0x05, 0x06 (frl == 0) or 0x80, 0x7f through FUN_a00a7fd8(port, 1, reg), each printed as "[HDMI_TX]:
 * 87xx = %02X".
 * Source form: each clock range assigns both values (the firmware repeats the b = 8 store).
 */
struct TxRec { unsigned int w0; unsigned int w4; int clk; unsigned char _c[0x1c - 0xc]; };
extern struct TxRec DAT_a807d580[];
extern int FUN_a0073044(const char *, ...);
extern void FUN_a00a80cc(unsigned int port, unsigned int sub, short reg, unsigned int mask, unsigned int mode);
extern void FUN_a008d980(unsigned int, unsigned char);
extern void FUN_a008d920(unsigned int, unsigned char);
extern void FUN_a008da34(unsigned int, unsigned char);
extern void FUN_a008d9d4(unsigned int, unsigned char);
extern short FUN_a00a7fd8(unsigned int, unsigned short, unsigned short);

void FUN_a0095f20(unsigned char port, unsigned char frl, unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    int clk;

    if (frl == 0) {
        clk = DAT_a807d580[port].clk * (b >> 1) / (4 >> a);
        FUN_a0073044("\x1b[0;34m[HDMI_TX]: video_clk = %d\n\r", clk);
        FUN_a00a80cc(port, 1, 0, 0x10, 0);
        FUN_a00a80cc(port, 1, 5, 0xc0, 1);
        if (clk <= 12) {
            a = 2;
            b = 8;
        } else if (clk <= 24) {
            a = 1;
            b = 8;
        } else if (clk <= 49) {
            a = 1;
            b = 8;
            FUN_a00a80cc(port, 1, 0, 0x10, 1);
        } else if (clk <= 79) {
            a = 0;
            b = 8;
        } else {
            a = 0;
            b = 8;
            FUN_a00a80cc(port, 1, 5, 0xc0, 0);
        }
    } else {
        clk = DAT_a807d580[port].clk * (d >> 1) / (4 >> c);
        FUN_a0073044("\x1b[0;34m[HDMI_TX]: FRL_video_clk = %d\n\r", clk);
        FUN_a00a80cc(port, 1, 0x80, 1, 0);
        FUN_a00a80cc(port, 1, 0x7f, 0xc0, 1);
        if (clk <= 12) {
            c = 2;
            d = 8;
        } else if (clk <= 24) {
            c = 1;
            d = 8;
        } else if (clk <= 49) {
            c = 1;
            d = 8;
            FUN_a00a80cc(port, 1, 0x80, 1, 1);
        } else if (clk <= 79) {
            c = 0;
            d = 8;
        } else {
            c = 0;
            d = 8;
            FUN_a00a80cc(port, 1, 0x7f, 0xc0, 0);
        }
    }
    FUN_a008d980(port, a);
    FUN_a008d920(port, b);
    FUN_a008da34(port, c);
    FUN_a008d9d4(port, d);
    if (frl == 0) {
        FUN_a0073044("\x1b[0;34m[HDMI_TX]: 8700 = %02X\n\r", FUN_a00a7fd8(port, 1, 0) & 0xff);
        FUN_a0073044("\x1b[0;34m[HDMI_TX]: 8705 = %02X\n\r", FUN_a00a7fd8(port, 1, 5) & 0xff);
        FUN_a0073044("\x1b[0;34m[HDMI_TX]: 8706 = %02X\n\r", FUN_a00a7fd8(port, 1, 6) & 0xff);
    } else {
        FUN_a0073044("\x1b[0;34m[HDMI_TX]: 8780 = %02X\n\r", FUN_a00a7fd8(port, 1, 0x80) & 0xff);
        FUN_a0073044("\x1b[0;34m[HDMI_TX]: 877F = %02X\n\r", FUN_a00a7fd8(port, 1, 0x7f) & 0xff);
    }
}
