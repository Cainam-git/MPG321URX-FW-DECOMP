/* leon2m FUN_a01461dc @ 0xa01461dc-0xa0146298 (188 bytes), flags -mcpu=v8 -O3 -g.
 * Builds a zero-initialised 16-byte record m on the stack: halfword +0 = p->h0, word +4 = 0xa0 / 0xb0 / 0xc0 / 0xc1
 * for p->b2 = 0 / 1 / 2 / 3 (left 0 otherwise), words +8 and +0xc = p->w4 and p->w8. Then calls
 * FUN_a011c4cc(x == 1, &m, c).
 * Source form: the x == 1 flag is a _Bool local computed first (the firmware keeps it and masks it with 1 at the
 * call).
 */
struct Req { unsigned short h0; unsigned char b2; unsigned int w4, w8; };
struct Msg { unsigned short h0; unsigned int code; unsigned int a, b; };
extern void FUN_a011c4cc(unsigned int flag, struct Msg *m, unsigned char c);

void FUN_a01461dc(unsigned char x, struct Req *p, unsigned char c)
{
    _Bool f = x == 1;
    struct Msg m = {0};

    m.h0 = p->h0;
    switch (p->b2) {
    case 0: m.code = 0xa0; break;
    case 1: m.code = 0xb0; break;
    case 2: m.code = 0xc0; break;
    case 3: m.code = 0xc1; break;
    }
    m.a = p->w4;
    m.b = p->w8;
    FUN_a011c4cc(f, &m, c);
}
