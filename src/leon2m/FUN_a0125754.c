/* leon2m FUN_a0125754 @ 0xa0125754-0xa01257f0 (39 words).
 * Handles only index k = 0 and returns 0 for any other k. For k = 0 it stores a in byte 6, 1 in byte 7 and h in
 * halfword 4 of element k of the 10-byte structures at 0xa802a430, copies that element to the stack and returns
 * func_0x4008b058(&copy, x, p, buf, n, m, 1). Same form as FUN_a01257f0; called by FUN_a0147b28.
 */
struct Bus { unsigned char b0, b1, b2, b3; unsigned short h4; unsigned char b6, b7; unsigned short h8; };
extern struct Bus DAT_a802a430[];
extern unsigned short func_0x4008b058(struct Bus *, int, unsigned short, unsigned char *, unsigned short,
                                      unsigned char, int);

unsigned short FUN_a0125754(unsigned char a, int x, unsigned short p, unsigned short h, unsigned char k,
                            unsigned char *buf, unsigned short n, unsigned char m)
{
    struct Bus bus;
    unsigned short r = 0;

    if (k == 0) {
        DAT_a802a430[k].b6 = a;
        DAT_a802a430[k].b7 = 1;
        DAT_a802a430[k].h4 = h;
        bus = DAT_a802a430[k];
        r = func_0x4008b058(&bus, x, p, buf, n, m, 1);
    }
    return r;
}
