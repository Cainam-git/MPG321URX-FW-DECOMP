/* leon2m FUN_a013bd00 @ 0xa013bd00-0xa013bdb8 (46 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Works on the record o = FUN_a013cd4c(port) (halfword fields). When o->h12 == o->h16 and o->h14 == o->h18:
 * tail-calls FUN_a00f8918(port) when FUN_a0121d4c(port) returns 1, else FUN_a00f88e8(port, 0) when flag is not 0.
 * Otherwise: with flag 0 tail-calls FUN_a00f8ef4(port); with flag not 0 calls FUN_a00f88e8(port, v) with
 * v = o->h20 - o->h1c when o->h1c is at most o->h20 (else o->h20) and tail-calls FUN_a00f8ef4(port). The second and
 * third parameters are not used.
 * Exact form: the unequal case is the first if arm (it fixes the register choice in the equal case).
 */
struct Out {
    unsigned char pad0[0x12];
    unsigned short h12, h14, h16, h18;
    unsigned char pad1a[2];
    unsigned short h1c, h1e, h20;
};
extern struct Out *FUN_a013cd4c(unsigned char port);
extern unsigned char FUN_a0121d4c(unsigned char);
extern void FUN_a00f8918(unsigned char);
extern void FUN_a00f8ef4(unsigned char);
extern void FUN_a00f88e8(unsigned char, unsigned short);

void FUN_a013bd00(unsigned char port, int a, int b, unsigned char flag)
{
    struct Out *o = FUN_a013cd4c(port);

    if (o->h12 != o->h16 || o->h14 != o->h18) {
        if (flag) {
            if (o->h1c <= o->h20)
                FUN_a00f88e8(port, o->h20 - o->h1c);
            else
                FUN_a00f88e8(port, o->h20);
        }
        FUN_a00f8ef4(port);
    } else {
        if (FUN_a0121d4c(port) == 1)
            FUN_a00f8918(port);
        else if (flag)
            FUN_a00f88e8(port, 0);
    }
}
