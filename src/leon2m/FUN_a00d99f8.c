/* leon2m FUN_a00d99f8 @ 0xa00d99f8-0xa00d9fdc (145 words).
 * Chooses an EDID mode m (0..13) from the record at 0xa802d290: byte +0x1f (2: by byte +0x2f, 0 -> 3,
 * 1/2 -> 4, else 0; 1 -> 2), byte +0x1a4 == 3 -> 6, otherwise bit 7 of word +0xa8, bits 18..19 of word +0xac and
 * bit 31 of word +0x1f4 pick 7..13 (or 0). Prints "UserSwitchEDID (%x %x)" with the previous mode (byte
 * 0xa8025c64) and m, calls FUN_a014b980(0xfe, byte +0x1a4 == 3). When m differs from the previous mode or sel is
 * nonzero, the mode's FUN_a00ce958(port, index) calls, FUN_a01439d8(n, 1) and its debug message follow (modes 10..13
 * add two more FUN_a00ce958 calls when how is nonzero; modes 0, 1, 5 and others act on how = 0, 1, 2).
 * The new mode is stored in byte 0xa8025c64.
 * Source forms: bit 31 of word +0x1f4 is a signed 1-bit bit-field (an unsigned mask or field gives a sign-bit
 * or shift test instead of the and / addx sequence); the bit-7-clear arm and the how == 0 arms come first.
 */
struct R290 {
    unsigned char pad0[0x1f];
    unsigned char b1f;
    unsigned char pad20[0x2f - 0x20];
    unsigned char b2f;
    unsigned char pad30[0xa8 - 0x30];
    unsigned int wa8;
    unsigned int wac;
    unsigned char padb0[0x1a4 - 0xb0];
    unsigned char b1a4;
    unsigned char pad1a5[0x1f4 - 0x1a5];
    struct {
        int top : 1;
        unsigned int rest : 31;
    } w1f4;
};
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c64;
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a014b980(unsigned char p, unsigned char v);
extern void FUN_a00ce958(int, int);
extern void FUN_a01439d8(int, int);

void FUN_a00d99f8(unsigned char how, unsigned char sel)
{
    unsigned char m = 0;

    if (DAT_a802d290.b1f == 2) {
        if (DAT_a802d290.b2f == 0)
            m = 3;
        else if (DAT_a802d290.b2f == 1)
            m = 4;
        else if (DAT_a802d290.b2f == 2)
            m = 4;
    } else if (DAT_a802d290.b1f == 1)
        m = 2;
    else if (DAT_a802d290.b1a4 == 3)
        m = 6;
    else if (!(DAT_a802d290.wa8 & 0x80)) {
        if (DAT_a802d290.wac & 0xc0000)
            m = DAT_a802d290.w1f4.top ? 8 : 13;
        else
            m = DAT_a802d290.w1f4.top ? 7 : 12;
    } else {
        if (DAT_a802d290.wac & 0xc0000)
            m = DAT_a802d290.w1f4.top ? 9 : 11;
        else if (!DAT_a802d290.w1f4.top)
            m = 10;
    }
    FUN_a00df170("UserSwitchEDID (%x %x)\r\n", DAT_a8025c64, m);
    if (DAT_a802d290.b1a4 == 3)
        FUN_a014b980(0xfe, 1);
    else
        FUN_a014b980(0xfe, 0);
    if (DAT_a8025c64 != m || sel != 0) {
        switch (m) {
        case 2:
            FUN_a00ce958(5, 4);
            FUN_a00ce958(6, 5);
            FUN_a00ce958(0xc, 6);
            FUN_a00ce958(0xd, 7);
            FUN_a01439d8(0, 1);
            break;
        case 3:
            FUN_a00ce958(5, 8);
            FUN_a00ce958(6, 9);
            FUN_a00ce958(0xc, 0xa);
            FUN_a00ce958(0xd, 0xb);
            FUN_a01439d8(0, 1);
            break;
        case 4:
            FUN_a00ce958(5, 0xc);
            FUN_a00ce958(6, 0xd);
            FUN_a00ce958(0xc, 0xe);
            FUN_a00ce958(0xd, 0xf);
            FUN_a01439d8(0, 1);
            break;
        case 6:
            FUN_a00ce958(5, 0x18);
            FUN_a00ce958(6, 0x19);
            FUN_a00ce958(0xc, 0x1a);
            FUN_a00ce958(0xd, 0x1b);
            FUN_a01439d8(0, 1);
            FUN_a00df170("_user_Edid_16to10\r\n");
            break;
        case 7:
            FUN_a00ce958(0xc, 2);
            FUN_a00ce958(0xd, 3);
            FUN_a00ce958(5, 0x14);
            FUN_a00ce958(6, 0x15);
            FUN_a01439d8(0, 1);
            FUN_a00df170("_user_Edid_VRR_OFF\r\n");
            break;
        case 8:
            FUN_a00ce958(0xc, 0x12);
            FUN_a00ce958(0xd, 0x13);
            FUN_a00ce958(5, 0x16);
            FUN_a00ce958(6, 0x17);
            FUN_a01439d8(0, 1);
            FUN_a00df170("_user_Edid_VRR_OFF_HDR1000\r\n");
            break;
        case 9:
            FUN_a00ce958(5, 0x10);
            FUN_a00ce958(6, 0x11);
            FUN_a00ce958(0xc, 0x12);
            FUN_a00ce958(0xd, 0x13);
            FUN_a01439d8(0, 1);
            FUN_a00df170("_user_Edid_displayHDR1000\r\n");
            break;
        case 10:
            if (!how) {
                FUN_a00ce958(5, 0x2c);
                FUN_a00ce958(6, 0x2d);
                FUN_a01439d8(1, 1);
            } else {
                FUN_a00ce958(5, 0x2c);
                FUN_a00ce958(6, 0x2d);
                FUN_a00ce958(0xc, 0x34);
                FUN_a00ce958(0xd, 0x35);
                FUN_a01439d8(0, 1);
            }
            FUN_a00df170("_user_Edid_DSC_OFF_VRR_ON\r\n");
            break;
        case 11:
            if (!how) {
                FUN_a00ce958(5, 0x2e);
                FUN_a00ce958(6, 0x2f);
                FUN_a01439d8(1, 1);
            } else {
                FUN_a00ce958(5, 0x2e);
                FUN_a00ce958(6, 0x2f);
                FUN_a00ce958(0xc, 0x36);
                FUN_a00ce958(0xd, 0x37);
                FUN_a01439d8(0, 1);
            }
            FUN_a00df170("_user_Edid_DSC_OFF_VRR_ON_HDR1000\r\n");
            break;
        case 12:
            if (!how) {
                FUN_a00ce958(5, 0x30);
                FUN_a00ce958(6, 0x31);
                FUN_a01439d8(1, 1);
            } else {
                FUN_a00ce958(5, 0x30);
                FUN_a00ce958(6, 0x31);
                FUN_a00ce958(0xc, 0x34);
                FUN_a00ce958(0xd, 0x35);
                FUN_a01439d8(0, 1);
            }
            FUN_a00df170("_user_Edid_DSC_OFF_VRR_OFF\r\n");
            break;
        case 13:
            if (!how) {
                FUN_a00ce958(5, 0x32);
                FUN_a00ce958(6, 0x33);
                FUN_a01439d8(1, 1);
            } else {
                FUN_a00ce958(5, 0x32);
                FUN_a00ce958(6, 0x33);
                FUN_a00ce958(0xc, 0x36);
                FUN_a00ce958(0xd, 0x37);
                FUN_a01439d8(0, 1);
            }
            FUN_a00df170("_user_Edid_DSC_OFF_VRR_OFF_HDR1000\r\n");
            break;
        default:
            if (how == 2) {
                FUN_a00ce958(0xc, 2);
                FUN_a00ce958(0xd, 3);
                FUN_a00ce958(5, 0);
                FUN_a00ce958(6, 1);
                FUN_a01439d8(0, 1);
            } else if (how == 0) {
                FUN_a00ce958(5, 0);
                FUN_a00ce958(6, 1);
                FUN_a01439d8(1, 1);
            } else if (how == 1) {
                FUN_a00ce958(0xc, 2);
                FUN_a00ce958(0xd, 3);
                FUN_a01439d8(2, 1);
            }
            break;
        }
    }
    DAT_a8025c64 = m;
}
