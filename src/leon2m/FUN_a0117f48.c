/* leon2m FUN_a0117f48 @ 0xa0117f48-0xa0118174 (139 words), flags -mcpu=v8 -O3 -g. Called by FUN_a014d5f4.
 * Saves the low bytes of the registers 0xcf012e00, 0xcf011bf8, 0xcf011a00 and 0xcf011800, calls FUN_a011855c(),
 * clears 0xcf011bf8, 0xcf011a00 and 0xcf011800, waits 20 ms (func_0x4008d1a0) and saves 0xcf013454; for port 0, 1
 * and 2 bits 4..7 of 0xcf013454 become 0x10, 0x40 and 0x20 (bits 0..3 kept). Saves 0xcf009bb8, register 0x54 of
 * block 0 (FUN_a00f2254), 0xcf012e60 and 0xcf012e64; then 0xcf009bb8 = 0x59, FUN_a00f2298(0, 0x54, 0x31), 2 ms
 * delay, 0xcf012e60 = 1, 0xcf012e64 = 0. mode 0 calls FUN_a0115bd4(port, sel, x), mode 1 FUN_a0116ff4(port, sel,
 * x); their byte result is returned (0 for other modes). Afterwards FUN_a011855c(), 20 ms delay and every saved
 * value is written back (0xcf013454, 0xcf009bb8, register 0x54 of block 0, 0xcf012e60, 0xcf012e64, 0xcf011800,
 * 0xcf011a00, 0xcf011bf8); FUN_a01185d4() runs when bit 0 of the saved 0xcf012e00 byte is set.
 * Source form: switch with case order 0, 2, 1 (decides the register names in the case blocks).
 */
extern unsigned char FUN_a00f2254(unsigned char blk, unsigned char reg);
extern void FUN_a00f2298(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned char FUN_a0115bd4(unsigned char port, unsigned short sel, unsigned char x);
extern unsigned char FUN_a0116ff4(unsigned char port, unsigned short sel, unsigned char x);
extern void FUN_a01185d4(void);
extern void FUN_a011855c(void);
extern void func_0x4008d1a0(int ms);

#define R(a) (*(volatile unsigned int *)(a))

unsigned char FUN_a0117f48(unsigned char port, unsigned short sel, unsigned char mode, unsigned char x)
{
    unsigned char e00, bf8, a00, r800, r454, bb8, v54, e60, e64, ret;

    e00 = R(0xcf012e00);
    bf8 = R(0xcf011bf8);
    a00 = R(0xcf011a00);
    r800 = R(0xcf011800);
    FUN_a011855c();
    R(0xcf011bf8) = 0;
    R(0xcf011a00) = 0;
    R(0xcf011800) = 0;
    func_0x4008d1a0(0x14);
    r454 = R(0xcf013454);
    switch (port) {
    case 0:
        R(0xcf013454) = (R(0xcf013454) & 0xf) | 0x10;
        break;
    case 2:
        R(0xcf013454) = (R(0xcf013454) & 0xf) | 0x20;
        break;
    case 1:
        R(0xcf013454) = (R(0xcf013454) & 0xf) | 0x40;
        break;
    }
    bb8 = R(0xcf009bb8);
    v54 = FUN_a00f2254(0, 0x54);
    e60 = R(0xcf012e60);
    e64 = R(0xcf012e64);
    R(0xcf009bb8) = 0x59;
    FUN_a00f2298(0, 0x54, 0x31);
    func_0x4008d1a0(2);
    R(0xcf012e60) = 1;
    R(0xcf012e64) = 0;
    ret = 0;
    if (mode == 0)
        ret = FUN_a0115bd4(port, sel, x);
    else if (mode == 1)
        ret = FUN_a0116ff4(port, sel, x);
    FUN_a011855c();
    func_0x4008d1a0(0x14);
    R(0xcf013454) = r454;
    R(0xcf009bb8) = bb8;
    FUN_a00f2298(0, 0x54, v54);
    R(0xcf012e60) = e60;
    R(0xcf012e64) = e64;
    R(0xcf011800) = r800;
    R(0xcf011a00) = a00;
    R(0xcf011bf8) = bf8;
    if (e00 & 1)
        FUN_a01185d4();
    return ret;
}
