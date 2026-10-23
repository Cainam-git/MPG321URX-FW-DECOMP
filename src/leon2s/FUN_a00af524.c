/* leon2s FUN_a00af524 @ 0xa00af524-0xa00af690, -mcpu=v8 -Os -g.
 * (u8 port), returns u8. Returns 2 when bit 6 of FUN_a00a6f78(port, 5) is clear. Otherwise writes 3 to
 * register 0x61 (FUN_a00a6c00), saves s = register 0x60, and with hi = s & 0xe0 writes hi | 1, hi | 2, hi | 3
 * to register 0x60, reading register 0x62 after each (a, b, c). When a == 0x1a, b == 0 and c == 0: r = 2 when
 * bit 5 of register 0x62 after writing hi | 6 is clear (else 0), and r |= 1 when bit 5 of register 0x62 after
 * writing hi | 9 is set; otherwise r = 2. Register 0x60 is restored to s and r returned.
 * The register accessors are declared with u8 values here (the firmware masks at each use).
 */
extern unsigned int FUN_a00a6f78(unsigned char, unsigned short);
extern unsigned char FUN_a00a6bb8(unsigned char, unsigned short);
extern void FUN_a00a6c00(unsigned char, unsigned short, unsigned char);

unsigned char FUN_a00af524(unsigned char port)
{
    unsigned char s, hi, a, b, c, r;

    r = 0;
    if ((FUN_a00a6f78(port, 5) & 0x40) == 0)
        return 2;
    FUN_a00a6c00(port, 0x61, 3);
    s = FUN_a00a6bb8(port, 0x60);
    hi = s & 0xe0;
    FUN_a00a6c00(port, 0x60, hi | 1);
    a = FUN_a00a6bb8(port, 0x62);
    FUN_a00a6c00(port, 0x60, hi | 2);
    b = FUN_a00a6bb8(port, 0x62);
    FUN_a00a6c00(port, 0x60, hi | 3);
    c = FUN_a00a6bb8(port, 0x62);
    if (a == 0x1a && b == 0 && c == 0) {
        FUN_a00a6c00(port, 0x60, hi | 6);
        if ((FUN_a00a6bb8(port, 0x62) & 0x20) == 0)
            r = 2;
        FUN_a00a6c00(port, 0x60, hi | 9);
        if (FUN_a00a6bb8(port, 0x62) & 0x20)
            r |= 1;
    } else {
        r = 2;
    }
    FUN_a00a6c00(port, 0x60, s);
    return r;
}
