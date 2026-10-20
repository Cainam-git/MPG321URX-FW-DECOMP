/* FUN_a00ad0c4 (leon2s 0xa00ad0c4-0xa00ad27c, 440 bytes), flags -mcpu=v8 -Os -g.
 * v = FUN_a00acc54(port); FUN_a00a6c98(port, 0x45, 0x40, 0); FUN_a00a6c98(port, 0x45, 0x80, 0);
 * FUN_a00a6c00(port, 0x47, x) with x = FUN_a00acac0(port) >> 8 when v > 0x104, else >> 6, limited to 0xff.
 * When FUN_a00a6bb8(port, 0x46) has bit 2 set: FUN_a00a6c00(port, 0x47, 0xff) if FUN_a00a6bb8(port, 0xc0)
 * has bit 0 set, else FUN_a00b1794(1) and FUN_a00a6c00(port, 0x47, FUN_a00a6da8(port, 0x48) >> 3 limited to
 * 0xff); then FUN_a00a6c98(port, 0x45, 0x40, 1). Then b = FUN_a00a6bb8(port, 0x47) & 0xff,
 * FUN_a00a6c98(port, 0x45, 0x80, 1), FUN_a00a6c00(port, 0x47, b), FUN_a00a6c98(port, 0x45, 0x80, 0),
 * FUN_a00a6c98(port, 3, 8, 1 if FUN_a00a6bb8(port, 0x80) & 3 else 0), and FUN_a00ad09c(port) as a tail call.
 * Source form: FUN_a00acc54 is declared returning int (its value is narrowed to 16 bits at the compare),
 * and the one unsigned short variable v also holds b.
 */
extern int FUN_a00acc54(unsigned int);
extern unsigned short FUN_a00acac0(unsigned int);
extern unsigned short FUN_a00a6da8(unsigned int, unsigned short);
extern unsigned int FUN_a00a6bb8(unsigned int, unsigned short);
extern void FUN_a00a6c00(unsigned int, unsigned short, unsigned char);
extern void FUN_a00a6c98(unsigned int, unsigned short, unsigned int, unsigned int);
extern void FUN_a00b1794(int);
extern void FUN_a00ad09c(unsigned int);

void FUN_a00ad0c4(unsigned int port)
{
    unsigned short v;

    port &= 0xff;
    v = FUN_a00acc54(port);
    FUN_a00a6c98(port, 0x45, 0x40, 0);
    FUN_a00a6c98(port, 0x45, 0x80, 0);
    if (v > 0x104)
        v = FUN_a00acac0(port) >> 8;
    else
        v = FUN_a00acac0(port) >> 6;
    if (v > 0xff)
        v = 0xff;
    FUN_a00a6c00(port, 0x47, v & 0xff);
    if (FUN_a00a6bb8(port, 0x46) & 4) {
        if (FUN_a00a6bb8(port, 0xc0) & 1) {
            FUN_a00a6c00(port, 0x47, 0xff);
        } else {
            FUN_a00b1794(1);
            v = FUN_a00a6da8(port, 0x48) >> 3;
            if (v > 0xff)
                v = 0xff;
            FUN_a00a6c00(port, 0x47, v & 0xff);
        }
        FUN_a00a6c98(port, 0x45, 0x40, 1);
    }
    v = FUN_a00a6bb8(port, 0x47) & 0xff;
    FUN_a00a6c98(port, 0x45, 0x80, 1);
    FUN_a00a6c00(port, 0x47, v);
    FUN_a00a6c98(port, 0x45, 0x80, 0);
    if (FUN_a00a6bb8(port, 0x80) & 3)
        FUN_a00a6c98(port, 3, 8, 1);
    else
        FUN_a00a6c98(port, 3, 8, 0);
    FUN_a00ad09c(port);
}
