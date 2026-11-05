/* FUN_a00b0738 (leon2s 0xa00b0738-0xa00b0e54, 1820 bytes), flags -mcpu=v8 -Os -g.
 * void (unsigned char port), called by FUN_a006d050 with port 0 and 1.
 * c = FUN_a0083ed0(port). Calls FUN_a00aeb6c(port) when byte +0x11f of DAT_a807dc18[port] (0x12c-byte rows)
 * is 1 and DAT_a8079310[port] is 0; FUN_a00a7614(c, 0x499, 1 or 0) by bits 6..7 of FUN_a00a6bb8(port, 0x21e)
 * being 2; FUN_a00ae3e4(port) or FUN_a00a6c00(port, 0xd6, 0x86). Returns for port > 1. Otherwise s = byte
 * +0x129 (byte +0x128 set) or +0x125 of the row; when s differs from DAT_a8079368[port] it calls
 * FUN_a00b0724(port), sets DAT_a8079360[port] to 1 with the four words DAT_a807933c/9344/934c/9354[port]
 * loaded from FUN_a00b2064() when s is 1, else to 0, and stores s in DAT_a8079368[port].
 * The words are compared with later FUN_a00b2064() values (limits 5000, 1500, 600, 1500) to clear
 * DAT_a8079360[port], call FUN_a00ad060, FUN_a00ad27c, FUN_a00ad644 and FUN_a00ad38c(port, 1, 2 or 4) and to
 * reload them. FUN_a00a6bb8(port, 0x256) with bit 7 set and a low byte unlike DAT_a8079370[port] prints
 * "DPCD 270 start phy test\r", stores the byte, selects a 2-bit field of FUN_a00a74b8(d, 0xab) by it
 * (0x80, 0x90, 0xa0, 0xb0) and writes the FUN_a00a7614 register list; a negative DAT_a8079370[port] copies
 * register 0x2b9, 0x2ba or 0x2bb to 0x2b8 between two FUN_a00a6c98(port, 0x30, 0x80, 1 / 0) calls.
 * Source form: the four tick arrays DAT_a807933c, DAT_a8079344, DAT_a807934c and DAT_a8079354 are volatile:
 * each store of a FUN_a00b2064() result into them stays in front of the next call with an empty delay slot
 * (st %o0; call; nop at 0xa00b0880, 0xa00b0894, 0xa00b08a8, 0xa00b0a38 and 0xa00b0abc); no other listing
 * addresses these arrays. port is an old-style (K&R) unsigned char parameter; the second FUN_a0083ed0 result
 * has its own local d; 'ne = (byte != byte)' is its own statement before 'if ((v >> 7) & ne)'; case 0x80 of
 * the last switch keeps the unused 's = FUN_a00a6bb8(port, 0x2b8)'.
 */
struct rec12c {
    unsigned char _0[0x11f];
    unsigned char b11f;
    unsigned char _120[5];
    unsigned char b125;
    unsigned char _126[2];
    unsigned char b128;
    unsigned char b129;
    unsigned char _12a[2];
};
extern struct rec12c DAT_a807dc18[];
extern unsigned char DAT_a8079310[];
extern unsigned char DAT_a8079360[];
extern unsigned char DAT_a8079368[];
extern signed char DAT_a8079370[];
extern volatile unsigned int DAT_a807933c[];
extern volatile unsigned int DAT_a8079344[];
extern volatile unsigned int DAT_a807934c[];
extern volatile unsigned int DAT_a8079354[];
extern unsigned char FUN_a0083ed0(unsigned char);
extern void FUN_a00aeb6c(unsigned char);
extern unsigned int FUN_a00a6bb8(unsigned char, unsigned short);
extern void FUN_a00a6c00(unsigned char, unsigned short, unsigned char);
extern void FUN_a00a6c98(unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a00a7614(unsigned char, unsigned short, unsigned char);
extern unsigned char FUN_a00ad668(unsigned char);
extern void FUN_a00ae3e4(unsigned char);
extern void FUN_a00b0724(unsigned char);
extern unsigned int FUN_a00b2064(void);
extern unsigned char FUN_a00ad5a4(unsigned char);
extern void FUN_a00ad060(unsigned char);
extern unsigned char FUN_a00ad27c(unsigned char);
extern unsigned char FUN_a00ad644(unsigned char);
extern void FUN_a00ad38c(unsigned char, unsigned char);
extern int FUN_a00734c4(const char *);
extern unsigned int FUN_a00a74b8(unsigned char, unsigned short);
extern unsigned char FUN_a008d800(void);
extern void FUN_a00b1794(unsigned short);

void FUN_a00b0738(port)
    unsigned char port;
{
    unsigned char c, d, s, w;
    unsigned int v, r;
    unsigned int ne;

    c = FUN_a0083ed0(port);
    if (DAT_a807dc18[port].b11f == 1 && DAT_a8079310[port] == 0)
        FUN_a00aeb6c(port);
    if ((FUN_a00a6bb8(port, 0x21e) & 0xc0) == 0x80)
        FUN_a00a7614(c, 0x499, 1);
    else
        FUN_a00a7614(c, 0x499, 0);
    if (DAT_a807dc18[port].b11f == 1 && FUN_a00ad668(port))
        FUN_a00ae3e4(port);
    else
        FUN_a00a6c00(port, 0xd6, 0x86);
    if (port > 1)
        return;
    if (DAT_a807dc18[port].b128)
        s = DAT_a807dc18[port].b129;
    else
        s = DAT_a807dc18[port].b125;
    if (DAT_a8079368[port] != s) {
        FUN_a00b0724(port);
        if (s == 1) {
            DAT_a8079360[port] = 1;
            DAT_a807933c[port] = FUN_a00b2064();
            DAT_a8079344[port] = FUN_a00b2064();
            DAT_a807934c[port] = FUN_a00b2064();
            DAT_a8079354[port] = FUN_a00b2064();
        } else {
            DAT_a8079360[port] = 0;
        }
        DAT_a8079368[port] = s;
    }
    if (FUN_a00b2064() - DAT_a807933c[port] > 5000 && DAT_a8079360[port] == 1)
        DAT_a8079360[port] = 0;
    if (FUN_a00ad5a4(port) == 1) {
        DAT_a8079360[port] = 0;
        DAT_a8079344[port] = FUN_a00b2064();
        FUN_a00ad060(port);
    }
    if (DAT_a8079360[port] == 1) {
        if (FUN_a00ad27c(port) == 1) {
            DAT_a807934c[port] = FUN_a00b2064();
            if (!FUN_a00ad644(port))
                DAT_a8079354[port] = FUN_a00b2064();
        }
    }
    if (DAT_a8079360[port] == 1) {
        if (FUN_a00b2064() - DAT_a8079344[port] > 1500) {
            if (FUN_a00b2064() - DAT_a807934c[port] > 600) {
                FUN_a00ad38c(port, 1);
                DAT_a807934c[port] = FUN_a00b2064();
                DAT_a8079354[port] = FUN_a00b2064();
            } else if (FUN_a00b2064() - DAT_a8079354[port] > 1500) {
                if ((FUN_a00a6bb8(port, 0x21d) & 0x1f) == 1) {
                    FUN_a00ad38c(port, 2);
                    DAT_a807934c[port] = FUN_a00b2064();
                    DAT_a8079354[port] = FUN_a00b2064();
                } else if ((FUN_a00a6bb8(port, 0x21d) & 0x1f) == 2) {
                    FUN_a00ad38c(port, 4);
                    DAT_a807934c[port] = FUN_a00b2064();
                    DAT_a8079354[port] = FUN_a00b2064();
                }
            }
        }
    }
    v = FUN_a00a6bb8(port, 0x256);
    w = 0;
    ne = (unsigned char)DAT_a8079370[port] != (unsigned char)v;
    if ((v >> 7) & ne) {
        FUN_a00734c4("DPCD 270 start phy test\r");
        DAT_a8079370[port] = FUN_a00a6bb8(port, 0x256);
        d = FUN_a0083ed0(port);
        r = FUN_a00a74b8(d, 0xab);
        switch ((unsigned char)DAT_a8079370[port]) {
        case 0x80:
            w = r & 3;
            break;
        case 0x90:
            w = (r & 0xc) >> 2;
            break;
        case 0xa0:
            w = (r & 0x30) >> 4;
            break;
        case 0xb0:
            w = (r & 0xc0) >> 6;
            break;
        }
        if (FUN_a008d800() <= 0x80) {
            FUN_a00a6c00(port, 0x21d, 0x84);
            FUN_a00a6c00(port, 0xc0, 0);
            FUN_a00a7614(d, 0x403, 0x80);
            FUN_a00a6c00(port, 0xc0, 0x80);
        }
        FUN_a00b1794(5);
        FUN_a00a7614(d, 0x47d, 0);
        FUN_a00a7614(d, 0x525, 0);
        FUN_a00a7614(d, 0x625, 0);
        FUN_a00a7614(d, 0x725, 0);
        FUN_a00a7614(d, 0x825, 0);
        FUN_a00a7614(d, 0x469, 0x2d);
        FUN_a00a7614(d, 3, 0x90);
        FUN_a00a7614(d, 0x43, 0xf0);
        FUN_a00a7614(d, 0x471, 0xf0);
        FUN_a00a7614(d, 2, (w << 1) | 0x80);
        FUN_a00a7614(d, 0x470, 0);
        FUN_a00a7614(d, 0x510, 1);
        FUN_a00a7614(d, 0x610, 1);
        FUN_a00a7614(d, 0x710, 1);
        FUN_a00a7614(d, 0x810, 1);
    }
    if (DAT_a8079370[port] < 0) {
        switch ((unsigned char)DAT_a8079370[port]) {
        case 0x80:
            s = FUN_a00a6bb8(port, 0x2b8);
            break;
        case 0x90:
            if ((unsigned char)FUN_a00a6bb8(port, 0x2b9) != (unsigned char)FUN_a00a6bb8(port, 0x2b8)) {
                FUN_a00a6c98(port, 0x30, 0x80, 1);
                FUN_a00a6c00(port, 0x2b8, FUN_a00a6bb8(port, 0x2b9));
                FUN_a00a6c98(port, 0x30, 0x80, 0);
            }
            break;
        case 0xa0:
            if ((unsigned char)FUN_a00a6bb8(port, 0x2ba) != (unsigned char)FUN_a00a6bb8(port, 0x2b8)) {
                FUN_a00a6c98(port, 0x30, 0x80, 1);
                FUN_a00a6c00(port, 0x2b8, FUN_a00a6bb8(port, 0x2ba));
                FUN_a00a6c98(port, 0x30, 0x80, 0);
            }
            break;
        case 0xb0:
            if ((unsigned char)FUN_a00a6bb8(port, 0x2bb) != (unsigned char)FUN_a00a6bb8(port, 0x2b8)) {
                FUN_a00a6c98(port, 0x30, 0x80, 1);
                FUN_a00a6c00(port, 0x2b8, FUN_a00a6bb8(port, 0x2bb));
                FUN_a00a6c98(port, 0x30, 0x80, 0);
            }
            break;
        }
    }
}
