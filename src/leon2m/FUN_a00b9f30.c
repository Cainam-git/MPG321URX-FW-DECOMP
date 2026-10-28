/* leon2m FUN_a00b9f30 @ 0xa00b9f30-0xa00ba068 (78 words), -mcpu=v8 -O3 -g. Called by FUN_a00ba184.
 * Takes the byte tables t0, t1, t2 = FUN_a014aa48(0), FUN_a014aa48(1), FUN_a014aa48(2). For i = 0..0xff, when
 * y0 <= (i >> 4) <= y1 and x0 <= (i & 0xf) <= x1, it adds t0[i], t1[i] and t2[i] to the words *r, *g and *b.
 * Then each of the three words is divided by n = (x1 - x0 + 1) * (y1 - y0 + 1), taken as an unsigned short.
 * Source form: x0, y0 and x1 are int parameters converted to unsigned char where they are used; y1 (the
 * seventh argument, passed on the stack) is an unsigned char parameter. The product is computed by an inlined
 * static helper area() with unsigned char parameters and an int result, so each operand is masked separately.
 */
extern unsigned char *FUN_a014aa48(int);

static int area(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1)
{
    return (x1 - x0 + 1) * (y1 - y0 + 1);
}

void FUN_a00b9f30(unsigned int *r, unsigned int *g, unsigned int *b, int x0, int y0, int x1, unsigned char y1)
{
    unsigned char *t0 = FUN_a014aa48(0);
    unsigned char *t1 = FUN_a014aa48(1);
    unsigned char *t2 = FUN_a014aa48(2);
    unsigned short i, n;

    n = area(x0, y0, x1, y1);
    for (i = 0; i < 0x100; i++) {
        if ((unsigned char)y0 <= (unsigned)(i >> 4) && (unsigned)(i >> 4) <= y1 &&
            (unsigned char)x0 <= (unsigned)(i & 0xf) && (unsigned char)x1 >= (unsigned)(i & 0xf)) {
            *r += t0[i];
            *g += t1[i];
            *b += t2[i];
        }
    }
    *r /= n;
    *g /= n;
    *b /= n;
}
