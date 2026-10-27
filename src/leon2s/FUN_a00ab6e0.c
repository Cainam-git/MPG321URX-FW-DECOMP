/* leon2s FUN_a00ab6e0 @ 0xa00ab6e0-0xa00ab884, -mcpu=v8 -Os -g.
 * (u8 port, u16 val, u8 force), void. Returns when val is 0, or when val equals DAT_a807931a and force is 0.
 * q = 48000 / val (signed division), h = q >> 1; stores val in DAT_a807931a; lo = h, limited to 0xff;
 * rest = (u16)(q - lo). When rest >> 1 is above 0xff, writes 0x80, 0xff, 0xff, 0xf0 to registers 0x26..0x29
 * of port (FUN_a00a6c00); otherwise 0x26 = (u16)lo >> 1, 0x27 = lo, 0x28 = rest >> 1 and 0x29 = rest minus
 * the read-back of register 0x28 (FUN_a00a6bb8). Then 0x2a = 0x36, FUN_a00a6c98(port, 0x2e, 0x31, 1),
 * 0x2b = 0xcc when byte +0x11f of the 0x12c-byte record ARR_a807dc18[port] is 1, else 0xd9, and 0x2c = 0xf.
 * Source forms: rest is an unsigned short local; the clamp is 'lo = 0xff; if (h <= 0xff) lo = h;'.
 */
struct Port {
    unsigned char _0[0x11f];
    unsigned char b11f;
    unsigned char _120[0x12c - 0x120];
};
extern struct Port ARR_a807dc18[];
extern unsigned short DAT_a807931a;
extern void FUN_a00a6c00(unsigned char, unsigned short, unsigned char);
extern unsigned int FUN_a00a6bb8(unsigned int, unsigned short);
extern void FUN_a00a6c98(unsigned char, unsigned short, unsigned char, unsigned char);

void FUN_a00ab6e0(unsigned char port, unsigned short val, unsigned char force)
{
    unsigned int q, h, lo;
    unsigned short rest;

    if (val == 0)
        return;
    if (DAT_a807931a == val && force == 0)
        return;
    q = 48000 / val;
    h = q >> 1;
    DAT_a807931a = val;
    lo = 0xff;
    if (h <= 0xff)
        lo = h;
    rest = q - lo;
    if ((rest >> 1) > 0xff) {
        FUN_a00a6c00(port, 0x26, 0x80);
        FUN_a00a6c00(port, 0x27, 0xff);
        FUN_a00a6c00(port, 0x28, 0xff);
        FUN_a00a6c00(port, 0x29, 0xf0);
    } else {
        FUN_a00a6c00(port, 0x26, (unsigned short)lo >> 1);
        FUN_a00a6c00(port, 0x27, lo);
        FUN_a00a6c00(port, 0x28, rest >> 1);
        FUN_a00a6c00(port, 0x29, rest - FUN_a00a6bb8(port, 0x28));
    }
    FUN_a00a6c00(port, 0x2a, 0x36);
    FUN_a00a6c98(port, 0x2e, 0x31, 1);
    if (ARR_a807dc18[port].b11f == 1)
        FUN_a00a6c00(port, 0x2b, 0xcc);
    else
        FUN_a00a6c00(port, 0x2b, 0xd9);
    FUN_a00a6c00(port, 0x2c, 0xf);
}
