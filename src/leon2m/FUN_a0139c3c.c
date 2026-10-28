/* leon2m FUN_a0139c3c @ 0xa0139c3c-0xa0139d38 (63 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a015209c.
 * Counts the right shifts that bring 0x20 down to 1 (a = 5) and 0x40 down to 1 (b = 6) at run time, then
 * v = a | b << 8. Reads one word w (preset 0xffffffff) with ROM func_0x4008c4d0(2, 0x20, &w, 1); while w != 0
 * (at most 100 rounds) calls ROM func_0x4008d1a0(1) and reads again. If w ended 0, writes
 * 0x2b000000 | (u16)v with ROM func_0x4008c5f8(2, 0x20, &w, 1).
 * Source form: b is an unsigned short set to 0 after the first count loop (the firmware then starts b in the
 * register of the first loop's final test value, which is 0).
 */
extern void func_0x4008c4d0(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void func_0x4008c5f8(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void func_0x4008d1a0(int ms);

void FUN_a0139c3c(void)
{
    unsigned int buf;
    unsigned int v;
    unsigned short x, y;
    unsigned int a;
    unsigned short b;
    int n;

    x = 0x20;
    y = 0x40;
    a = 0;
    while (x >> 1) {
        x >>= 1;
        a++;
    }
    b = 0;
    while (y >> 1) {
        y >>= 1;
        b++;
    }
    v = a | (b << 8);
    buf = 0xffffffff;
    func_0x4008c4d0(2, 0x20, &buf, 1);
    n = 100;
    while (buf != 0) {
        func_0x4008d1a0(1);
        n--;
        func_0x4008c4d0(2, 0x20, &buf, 1);
        if (n == 0)
            break;
    }
    if (buf == 0) {
        buf = (unsigned short)v | 0x2b000000;
        func_0x4008c5f8(2, 0x20, &buf, 1);
    }
}
