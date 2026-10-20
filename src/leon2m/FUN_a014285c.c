/* leon2m FUN_a014285c @ 0xa014285c-0xa0142910 (180 bytes)  fill a port timing record from the input measurement
 * Flags: -mcpu=v8 -O2 -g and -mcpu=v8 -O3 -g both give this code.
 * FUN_a00f92d4(port) != 0: values from the FUN_a00f93xx getters (+0x24 = 8); else from the measurement block:
 * +0x1E = FUN_a0120a18(port) = line rate in 100 Hz units ((96e6/count + 50)/100), +0x20 = FUN_a0120b38(port) =
 * vfreq in 0.1 Hz, +0x22/+0x23/+0x24 bytes and +0x26 from FUN_a0120c58/c74/bf4/c90. FUN_a00f92d4(port) is bit 7
 * of register 0x8C read through FUN_a00f1a90.
 */
struct Rec {
    unsigned char pad0[0x1e];
    unsigned short h1e, h20;
    unsigned char b22, b23, b24, pad25;
    unsigned short h26;
};
extern unsigned char FUN_a00f92d4(unsigned char port);
extern unsigned short FUN_a00f9390(unsigned char port);
extern unsigned short FUN_a00f9398(unsigned char port);
extern unsigned char FUN_a0120c58(unsigned char port);
extern unsigned char FUN_a0120c74(unsigned char port);
extern unsigned short FUN_a00f9314(unsigned char port);
extern unsigned short FUN_a0120a18(unsigned char port);
extern unsigned short FUN_a0120b38(unsigned char port);
extern unsigned char FUN_a0120bf4(unsigned char port);
extern unsigned short FUN_a0120c90(unsigned char port);

void FUN_a014285c(struct Rec *r, unsigned char port)
{
    if (FUN_a00f92d4(port)) {
        r->h1e = FUN_a00f9390(port);
        r->h20 = FUN_a00f9398(port);
        r->b22 = FUN_a0120c58(port);
        r->b23 = FUN_a0120c74(port);
        r->b24 = 8;
        r->h26 = FUN_a00f9314(port);
    } else {
        r->h1e = FUN_a0120a18(port);
        r->h20 = FUN_a0120b38(port);
        r->b22 = FUN_a0120c58(port);
        r->b23 = FUN_a0120c74(port);
        r->b24 = FUN_a0120bf4(port);
        r->h26 = FUN_a0120c90(port);
    }
}
