/* FUN_a00980a8 (leon2s 0xa00980a8-0xa0098240, 408 bytes, including the ret/restore tail), flags -mcpu=v8 -Os -g.
 * Does nothing when byte +2 of the 400-byte port record ARR_a807d7e0[port] is 0. When FUN_a00a0588(port, 4) is
 * non-zero and byte +0x189 is not 2: FUN_a00a73ac(0x18, word +0 of the 0x34-byte record ARR_a807db00[port] + 0xc),
 * top byte of register +0x9c of the register block at +8 = 9, byte +0x189 = 2. Otherwise FUN_a0098048(port), then
 * by bit 12 of register +0x80: set and byte +0x189 != 1: FUN_a00a73d4(0x18, ..), top byte of +0x9c = 2,
 * FUN_a00a73ac(0x17, ..), byte +0x189 = 1; clear and byte +0x189 != 0: the same with FUN_a00a73d4(0x17, ..)
 * and byte +0x189 = 0. Always ends with FUN_a00a73ac(8, word +0 + 0x84) and FUN_a00a73d4(8, word +0 + 0x84).
 * The register block is volatile (hardware); its pointer type is volatile unsigned long (the alias set keeps
 * the next record load ahead of the register store, as in the firmware). Bit 12 is tested as a byte of
 * (register >> 8).
 */
struct Port34 {
    unsigned int w0;
    unsigned int w4;
    volatile unsigned long *r8;
    unsigned char rest[0x34 - 0xc];
};
extern struct Port34 ARR_a807db00[];
extern unsigned char ARR_a807d7e0[][400];
extern unsigned char FUN_a00a0588(unsigned char, unsigned char);
extern void FUN_a0098048(unsigned char);
extern void FUN_a00a73ac(unsigned int, unsigned int);
extern void FUN_a00a73d4(unsigned int, unsigned int);

void FUN_a00980a8(unsigned char port)
{
    unsigned char *rec = ARR_a807d7e0[port];

    if (rec[2] == 0)
        return;
    if (FUN_a00a0588(port, 4)) {
        if (rec[0x189] != 2) {
            FUN_a00a73ac(0x18, ARR_a807db00[port].w0 + 0xc);
            ARR_a807db00[port].r8[0x9c / 4] = (ARR_a807db00[port].r8[0x9c / 4] & ~0xff000000) | 0x09000000;
            rec[0x189] = 2;
        }
    } else {
        FUN_a0098048(port);
        if ((unsigned char)(ARR_a807db00[port].r8[0x80 / 4] >> 8) & 0x10) {
            if (rec[0x189] != 1) {
                FUN_a00a73d4(0x18, ARR_a807db00[port].w0 + 0xc);
                ARR_a807db00[port].r8[0x9c / 4] = (ARR_a807db00[port].r8[0x9c / 4] & ~0xff000000) | 0x02000000;
                FUN_a00a73ac(0x17, ARR_a807db00[port].w0 + 0xc);
                rec[0x189] = 1;
            }
        } else {
            if (rec[0x189] != 0) {
                FUN_a00a73d4(0x18, ARR_a807db00[port].w0 + 0xc);
                ARR_a807db00[port].r8[0x9c / 4] = (ARR_a807db00[port].r8[0x9c / 4] & ~0xff000000) | 0x02000000;
                FUN_a00a73d4(0x17, ARR_a807db00[port].w0 + 0xc);
                rec[0x189] = 0;
            }
        }
    }
    FUN_a00a73ac(8, ARR_a807db00[port].w0 + 0x84);
    FUN_a00a73d4(8, ARR_a807db00[port].w0 + 0x84);
}
