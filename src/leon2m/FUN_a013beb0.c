/* leon2m FUN_a013beb0 @ 0xa013beb0-0xa013bfa8 (62 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table). port is the parameter. With o = FUN_a013cd4c(port) (halfword fields) a flag is
 * set when ((o->h10 - o->h14) * o->he) >> 1 (unsigned) is above 0x1fff. Calls FUN_a00f8918(port), then runs the body
 * of FUN_a013bd00 with that flag on a new FUN_a013cd4c(port) record: when o->h12 != o->h16 or o->h14 != o->h18,
 * FUN_a00f88e8(port, o->h20 - o->h1c or o->h20) when the flag is set and FUN_a00f8ef4(port); otherwise
 * FUN_a00f8918(port) when FUN_a0121d4c(port) returns 1, else FUN_a00f88e8(port, 0) when the flag is set.
 * Exact form: the body is written out (not as an inlined static function) with the unequal case as the first if arm.
 */
struct Out {
    unsigned char pad0[0xe];
    unsigned short he, h10, h12, h14, h16, h18;
    unsigned char pad1a[2];
    unsigned short h1c, h1e, h20;
};
extern struct Out *FUN_a013cd4c(unsigned char port);
extern unsigned char FUN_a0121d4c(unsigned char);
extern void FUN_a00f8918(unsigned char);
extern void FUN_a00f8ef4(unsigned char);
extern void FUN_a00f88e8(unsigned char, unsigned short);

void FUN_a013beb0(unsigned char port)
{
    struct Out *o = FUN_a013cd4c(port);
    unsigned char big = 0;

    if ((unsigned int)((o->h10 - o->h14) * o->he) >> 1 > 0x1fff)
        big = 1;
    FUN_a00f8918(port);
    o = FUN_a013cd4c(port);
    if (o->h12 != o->h16 || o->h14 != o->h18) {
        if (big) {
            if (o->h1c <= o->h20)
                FUN_a00f88e8(port, o->h20 - o->h1c);
            else
                FUN_a00f88e8(port, o->h20);
        }
        FUN_a00f8ef4(port);
    } else {
        if (FUN_a0121d4c(port) == 1)
            FUN_a00f8918(port);
        else if (big)
            FUN_a00f88e8(port, 0);
    }
}
