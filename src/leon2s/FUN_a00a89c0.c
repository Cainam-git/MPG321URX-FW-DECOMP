/* leon2s FUN_a00a89c0 @ 0xa00a89c0-0xa00a8cac (203 words), flags -mcpu=v8 -Os -g.
 * unsigned char (u8 sel, u8 mode, u8 port, u16 d, u8 e, u8 f). ok = bit 0 of FUN_a00a88b8(sel, mode, port).
 * sel 0: FUN_a00a8260(port, 0x59, 4, e), (port, 0x50, 1, f). sel 1: FUN_a00a6440(4, port, 0x55, 0xff, low
 * byte of d), (4, port, 0x56, 0xff, high byte of d), FUN_a00a8260(port, 0x59, 0x10, e), (port, 0x54, 7, f),
 * (port, 0x54, 0x80, 1), (port, 0x54, 0x80, 0). For sel 0 and 1, ok = 0 unless mode is 0x31..0x81.
 * sel 2: mode 0x31/0x41/0x51/0x61: FUN_a00a6440(4, port, 0x57, 0xff, 0xa when bit 30 of word 0 of the 7-word
 * record ARR_a807d580[port] is set, else 0xb), (4, port, 0x58, 0x1f, 0), FUN_a00a8260(port, 0x59, 2, 0);
 * mode 0x71/0x81: FUN_a00a6440(4, port, 0x57, 0xff, 4), (4, port, 0x58, 0x1f, 0x10),
 * FUN_a00a8260(port, 0x59, 2, 1); other modes: ok = 0; then FUN_a00a8260(port, 0x59, 9, (e << 3) | f).
 * Other sel: ok = 0. When f & e is not 0: ok = 0 unless bits 4..5 of FUN_a00a7fd8(port, 0, 0x33) equal
 * bits 0..1 of FUN_a00a7fd8(port, 0, 0x3f). ok = 0 for port >= 2. Returns ok.
 * Source form: switch on sel; bit 30 read through a bit-field; the compared bits as an unsigned char local
 * x = (... >> 4) & 3 written on the right of the compare.
 */
struct Dst {
    unsigned int a31 : 1;
    unsigned int a30 : 1;
    unsigned int a0 : 30;
    unsigned int w[6];
};
extern struct Dst ARR_a807d580[];
extern unsigned int FUN_a00a88b8(unsigned char, unsigned char, unsigned char);
extern void FUN_a00a8260(unsigned char, unsigned char, unsigned char, unsigned char);
extern void FUN_a00a6440(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern unsigned int FUN_a00a7fd8(unsigned char, unsigned short, unsigned short);

unsigned char FUN_a00a89c0(unsigned char sel, unsigned char mode, unsigned char port, unsigned short d,
                           unsigned char e, unsigned char f)
{
    unsigned char ok;
    unsigned char x;

    ok = FUN_a00a88b8(sel, mode, port) & 1;
    switch (sel) {
    case 0:
        FUN_a00a8260(port, 0x59, 4, e);
        FUN_a00a8260(port, 0x50, 1, f);
        if ((unsigned char)(mode - 0x31) > 0x50)
            ok = 0;
        break;
    case 1:
        FUN_a00a6440(4, port, 0x55, 0xff, d);
        FUN_a00a6440(4, port, 0x56, 0xff, d >> 8);
        FUN_a00a8260(port, 0x59, 0x10, e);
        FUN_a00a8260(port, 0x54, 7, f);
        FUN_a00a8260(port, 0x54, 0x80, 1);
        FUN_a00a8260(port, 0x54, 0x80, 0);
        if ((unsigned char)(mode - 0x31) > 0x50)
            ok = 0;
        break;
    case 2:
        if (mode == 0x31 || mode == 0x41 || mode == 0x51 || mode == 0x61) {
            if (ARR_a807d580[port].a30)
                FUN_a00a6440(4, port, 0x57, 0xff, 0xa);
            else
                FUN_a00a6440(4, port, 0x57, 0xff, 0xb);
            FUN_a00a6440(4, port, 0x58, 0x1f, 0);
            FUN_a00a8260(port, 0x59, 2, 0);
        } else if (mode == 0x71 || mode == 0x81) {
            FUN_a00a6440(4, port, 0x57, 0xff, 4);
            FUN_a00a6440(4, port, 0x58, 0x1f, 0x10);
            FUN_a00a8260(port, 0x59, 2, 1);
        } else
            ok = 0;
        FUN_a00a8260(port, 0x59, 9, (e << 3) | f);
        break;
    default:
        ok = 0;
        break;
    }
    if (f & e) {
        x = FUN_a00a7fd8(port, 0, 0x33) >> 4 & 3;
        if ((FUN_a00a7fd8(port, 0, 0x3f) & 3) != x)
            ok = 0;
    }
    if (port >= 2)
        ok = 0;
    return ok;
}
