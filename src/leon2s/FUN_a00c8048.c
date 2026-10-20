/* FUN_a00c8048 (leon2s 0xa00c8048-0xa00c80f0, 168 bytes), flags -mcpu=v8 -Os -g.
 * Returns 1 without any access when the 16-bit count n is 0. Otherwise writes registers of port through
 * func_0xa0fb8054(port, 0, reg, value): 0xed = a, 0xee = 0, 0xef = b, 0xf0 = low byte of n, 0xf1 = high
 * byte of n, 0xf3 = 2, and returns 0. Same register sequence as the start of FUN_a00c80f0.
 * Source form: the result is an unsigned char set in both arms and returned as r & 1.
 */
extern void func_0xa0fb8054(unsigned char, int, int, unsigned char);

unsigned char FUN_a00c8048(unsigned char port, unsigned char a, unsigned char b, unsigned short n)
{
    unsigned char r = 0;

    if (n == 0) {
        r = 1;
    } else {
        func_0xa0fb8054(port, 0, 0xed, a);
        func_0xa0fb8054(port, 0, 0xee, 0);
        func_0xa0fb8054(port, 0, 0xef, b);
        func_0xa0fb8054(port, 0, 0xf0, n);
        func_0xa0fb8054(port, 0, 0xf1, n >> 8);
        func_0xa0fb8054(port, 0, 0xf3, 2);
    }
    return r & 1;
}
