/* leon2m FUN_a013aae4 @ 0xa013aae4-0xa013ab9c (184 bytes), flags -mcpu=v8 -O3 -g.
 * Reads a word w (preset to 0xFFFFFFFF) through func_0x4008c4d0(2, 0x20, &w, 1); while it is nonzero, calls
 * func_0x4008d1a0(1) and reads again, at most 100 times. When w reads 0, writes ((a & 0xff) << 16) | 0x61000000 |
 * (b & 0xff) through func_0x4008c5f8(2, 0x20, &w, 1); otherwise returns without a write. Two-byte variant of
 * FUN_a01398bc.
 * Source form: the low byte b is converted into a short at the start (as in FUN_a01398bc); the constant
 * 0x61000000 is held in a local k, which keeps the or order (a << 16) | k before | b (a literal is
 * reassociated to the outside).
 */
extern void func_0x4008c4d0();
extern void func_0x4008c5f8();
extern int func_0x4008d1a0();
void FUN_a013aae4(unsigned char a, unsigned char b)
{
    short nb;
    unsigned int w;
    int n;
    unsigned int k = 0x61000000;

    w = 0xffffffff;
    nb = b & 0xff;
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
        w = ((a << 16) | k) | nb;
        func_0x4008c5f8(2, 0x20, &w, 1);
    }
}
