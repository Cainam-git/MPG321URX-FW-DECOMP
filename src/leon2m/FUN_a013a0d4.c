/* leon2m FUN_a013a0d4 @ 0xa013a0d4-0xa013a1a4 (208 bytes), flags -mcpu=v8 -O3 -g.
 * FUN_a013a0d4(p1, p2): y = p2 | (bits 0..1 of the low halfword of p1) << 14. Word w = 0xffffffff is read with
 * func_0x4008c4d0(2, 0x20, &w, 1) until it is 0, at most 100 times, calling func_0x4008d1a0(1) before each
 * repeat. When w is 0, w = (bits 2..9 of the low halfword of p1) << 16 | 0x39000000 | y (16 bits) is written
 * with func_0x4008c5f8(2, 0x20, &w, 1).
 * Source form: p2 is an unsigned short parameter updated in place (the firmware truncates it only at the final
 * use); the low halfword of p1 is copied to an unsigned short and its shifted byte is taken before the 2-bit field;
 * the constant 0x39000000 is a local k (as in FUN_a013aae4).
 */
extern void func_0x4008c4d0();
extern void func_0x4008c5f8();
extern int func_0x4008d1a0();

void FUN_a013a0d4(unsigned int p1, unsigned short p2)
{
    unsigned short a = p1;
    unsigned char x = a >> 2;
    unsigned int w;
    int n;
    unsigned int k = 0x39000000;

    p2 |= (a & 3) << 14;
    w = 0xffffffff;
    func_0x4008c4d0(2, 0x20, &w, 1);
    n = 100;
    while (w != 0) {
        func_0x4008d1a0(1);
        n--;
        func_0x4008c4d0(2, 0x20, &w, 1);
        if (n == 0)
            break;
    }
    if (w == 0) {
        w = (x << 16 | k) | p2;
        func_0x4008c5f8(2, 0x20, &w, 1);
    }
}
