/* leon2s SR_detect_fail_ch @ 0xa009a698-0xa009ae98 (2048 bytes), flags -mcpu=v8 -Os -g.
 * u8 port (0 -> PHY page 2, 1 -> page 3, other ports return 0); returns a u8 lane bit mask. Calls
 * DRV_HDMI21_PHY_Freq_Detection(port); the value f follows byte +2 of the 0xb0-byte record
 * DAT_a807d680[port] (6: 0x4b0, 5: 1000, 4: 800, 2..3: 600, 1: 300, else 0), and the first lane (count = byte
 * +0 of the record) whose ARR_a807905a[port * 4 + lane] differs calls DRV_HDMI21_PHY_PICDR_Reset(page) once.
 * Clears bits 4..7 of 0x2e5c, writes bit 0x1c of 0x2d08 = (record byte 0x3a == 1), clears and then sets bit
 * 0xe of the per-lane registers 0x2e08/0x2e18/0x2e28/0x2e38, waits FUN_a00b1794(1), and collects mask bit n
 * when FUN_a00a7468(0x15, page, lane register n) returns 0 (lane 3 only with 4 lanes), each with a debug
 * print s_a006a2c8 (lane) when bit 11 of _DAT_a8078634 is set; prints s_a006a2f8 (mask). Then fixed writes
 * to 0x2d08/0x2e04, per-lane fields of 0x2d04 and 0x2d0c/0x2d10, the 0x2d00 bit sequence, FUN_a00b1794(1),
 * and ORs bits 28..31 of 0x2d00 into the mask (prints s_a006a320 / s_a006a340). A zero mask clears the
 * 0x2d00 low byte and the per-lane 0x2d0c/0x2d10 bytes.
 * Source form: per-lane registers chosen by if/else-if chains on the lane index (a switch becomes a
 * balanced compare tree); the error nibble is an unsigned char variable that is reused for the final mask.
 */
extern unsigned char DAT_a807d680[][0xb0];
extern unsigned short ARR_a807905a[];
extern unsigned int _DAT_a8078634;
extern char s_a006a2c8[], s_a006a2f8[], s_a006a320[], s_a006a340[];
extern int FUN_a0073044(const void *, ...);
extern void DRV_HDMI21_PHY_Freq_Detection(unsigned char);
extern void DRV_HDMI21_PHY_PICDR_Reset(unsigned char);
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);
extern void FUN_a00a7424(int, unsigned int, unsigned char, unsigned short);
extern unsigned int FUN_a00a7468(unsigned int, unsigned char, unsigned short);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);
extern void FUN_a00b1794(unsigned short);

unsigned char SR_detect_fail_ch(unsigned char port)
{
    unsigned char r = 0;
    unsigned short f = 0;
    unsigned char ch;
    unsigned char i;
    unsigned char c;
    unsigned char e;

    if (port == 0)
        ch = 2;
    else if (port == 1)
        ch = 3;
    else
        return 0;
    DRV_HDMI21_PHY_Freq_Detection(port);
    c = DAT_a807d680[port][2];
    if (c == 6)
        f = 0x4b0;
    else if (c == 5)
        f = 1000;
    else if (c == 4)
        f = 800;
    else if ((unsigned char)(c - 2) <= 1)
        f = 600;
    else if (c == 1)
        f = 300;
    for (i = 0; i < DAT_a807d680[port][0]; i++) {
        if (ARR_a807905a[port * 4 + i] != f) {
            DRV_HDMI21_PHY_PICDR_Reset(ch);
            break;
        }
    }
    FUN_a00a7488(ch, 0x2e5c, 0xffffff0f, 0);
    FUN_a00a7424(DAT_a807d680[port][0x3a] == 1, 0x1c, ch, 0x2d08);
    for (i = 0; i < DAT_a807d680[port][0]; i++) {
        if (i == 0)
            FUN_a00a7424(0, 0xe, ch, 0x2e08);
        else if (i == 1)
            FUN_a00a7424(0, 0xe, ch, 0x2e18);
        else if (i == 2)
            FUN_a00a7424(0, 0xe, ch, 0x2e28);
        else if (i == 3)
            FUN_a00a7424(0, 0xe, ch, 0x2e38);
    }
    for (i = 0; i < DAT_a807d680[port][0]; i++) {
        if (i == 0)
            FUN_a00a7424(1, 0xe, ch, 0x2e08);
        else if (i == 1)
            FUN_a00a7424(1, 0xe, ch, 0x2e18);
        else if (i == 2)
            FUN_a00a7424(1, 0xe, ch, 0x2e28);
        else if (i == 3)
            FUN_a00a7424(1, 0xe, ch, 0x2e38);
    }
    FUN_a00b1794(1);
    if (FUN_a00a7468(0x15, ch, 0x2e08) == 0) {
        if ((_DAT_a8078634 & 0x800) != 0)
            FUN_a0073044(s_a006a2c8, 0);
        r = 1;
    }
    if (FUN_a00a7468(0x15, ch, 0x2e18) == 0) {
        if ((_DAT_a8078634 & 0x800) != 0)
            FUN_a0073044(s_a006a2c8, 1);
        r |= 2;
    }
    if (FUN_a00a7468(0x15, ch, 0x2e28) == 0) {
        if ((_DAT_a8078634 & 0x800) != 0)
            FUN_a0073044(s_a006a2c8, 2);
        r |= 4;
    }
    if (FUN_a00a7468(0x15, ch, 0x2e38) == 0 && DAT_a807d680[port][0] == 4) {
        if ((_DAT_a8078634 & 0x800) != 0)
            FUN_a0073044(s_a006a2c8, 3);
        r |= 8;
    }
    if ((_DAT_a8078634 & 0x800) != 0)
        FUN_a0073044(s_a006a2f8, r);
    FUN_a00a7488(ch, 0x2d08, 0xffffff0f, 0x10);
    FUN_a00a7424(1, 8, ch, 0x2e04);
    FUN_a00a7424(1, 0xc, ch, 0x2e04);
    FUN_a00a7424(1, 0x19, ch, 0x2d08);
    for (i = 0; i < DAT_a807d680[port][0]; i++) {
        if (i == 0)
            FUN_a00a7488(ch, 0x2d04, 0xfff0ffff, 0x50000);
        else if (i == 1)
            FUN_a00a7488(ch, 0x2d04, 0xff0fffff, 0x600000);
        else if (i == 2)
            FUN_a00a7488(ch, 0x2d04, 0xf0ffffff, 0x7000000);
        else if (i == 3)
            FUN_a00a7488(ch, 0x2d04, 0x0fffffff, 0x80000000);
        if (i == 0)
            FUN_a00a7488(ch, 0x2d0c, 0xffff00ff, 0xff00);
        else if (i == 1)
            FUN_a00a7488(ch, 0x2d0c, 0x00ffffff, 0xff000000);
        else if (i == 2)
            FUN_a00a7488(ch, 0x2d10, 0xffff00ff, 0xff00);
        else if (i == 3)
            FUN_a00a7488(ch, 0x2d10, 0x00ffffff, 0xff000000);
    }
    FUN_a00a7488(ch, 0x2d00, 0xffffff00, 0);
    FUN_a00a7424(1, 0xb, ch, 0x2d00);
    FUN_a00a7424(1, 0xc, ch, 0x2d00);
    FUN_a00a7424(1, 0, ch, 0x2d00);
    FUN_a00a7424(1, 1, ch, 0x2d00);
    FUN_a00a7424(0, 1, ch, 0x2d00);
    FUN_a00a7424(1, 3, ch, 0x2d00);
    FUN_a00a7424(0, 3, ch, 0x2d00);
    FUN_a00a7424(1, 1, ch, 0x2d00);
    FUN_a00a7424(0, 1, ch, 0x2d00);
    FUN_a00a7424(1, 5, ch, 0x2d00);
    FUN_a00b1794(1);
    e = FUN_a00a7314(ch, 0x2d00) >> 28;
    if ((_DAT_a8078634 & 0x800) != 0)
        FUN_a0073044(s_a006a320, e & 0xf);
    e = e | r;
    if ((_DAT_a8078634 & 0x800) != 0)
        FUN_a0073044(s_a006a340, e);
    if (e == 0) {
        FUN_a00a7488(ch, 0x2d00, 0xffffff00, 0);
        for (i = 0; i < DAT_a807d680[port][0]; i++) {
            if (i == 0)
                FUN_a00a7488(ch, 0x2d0c, 0xffff00ff, 0);
            else if (i == 1)
                FUN_a00a7488(ch, 0x2d0c, 0x00ffffff, 0);
            else if (i == 2)
                FUN_a00a7488(ch, 0x2d10, 0xffff00ff, 0);
            else if (i == 3)
                FUN_a00a7488(ch, 0x2d10, 0x00ffffff, 0);
        }
    }
    return e;
}
