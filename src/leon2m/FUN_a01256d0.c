/* leon2m FUN_a01256d0 @ 0xa01256d0-0xa0125754 (33 words).
 * Handles only index k = 0 and returns 0 for any other k. For k = 0 it stores a and b in bytes 6 and 7 and h in
 * halfword 4 of element k of the 10-byte structures at 0xa802a430, copies that element to the stack and returns
 * func_0x4008bb28(&copy, p, n, buf). Same form as FUN_a0125644.
 */
struct Bus { unsigned char b0, b1, b2, b3; unsigned short h4; unsigned char b6, b7; unsigned short h8; };
extern struct Bus DAT_a802a430[];
extern unsigned short func_0x4008bb28(struct Bus *, unsigned short, unsigned short, unsigned char *);

unsigned short FUN_a01256d0(unsigned char a, unsigned char b, unsigned short p, unsigned short h, unsigned char k,
                            unsigned char *buf, unsigned short n)
{
    struct Bus bus;
    unsigned short r = 0;

    if (k == 0) {
        DAT_a802a430[k].b6 = a;
        DAT_a802a430[k].b7 = b;
        DAT_a802a430[k].h4 = h;
        bus = DAT_a802a430[k];
        r = func_0x4008bb28(&bus, p, n, buf);
    }
    return r;
}
