/* leon2m FUN_a013bbb8 @ 0xa013bbb8-0xa013bc5c (41 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Works on the record o = FUN_a013cd4c(port) (halfword fields): with a = o->h28 and m = min(a, 0x32) stores
 * o->h2e = a - m and o->h30 = a + m; with b = o->h2a and n = min(b, 0x32) stores o->h32 = b - n and o->h34 = b + n;
 * clears o->h36. Then o->h38 = v - o->h18 - 3, where v = o->h10, doubled when FUN_a0121258(port) returns non-zero.
 * Exact form: the o->h38 store is written out in both arms (GCC merges the tails).
 */
struct Out {
    unsigned char pad0[0x10];
    unsigned short h10;
    unsigned char pad12[6];
    unsigned short h18;
    unsigned char pad1a[0xe];
    unsigned short h28, h2a, h2c, h2e, h30, h32, h34, h36, h38;
};
extern struct Out *FUN_a013cd4c(unsigned char port);
extern unsigned char FUN_a0121258(unsigned char port);

void FUN_a013bbb8(unsigned char port)
{
    struct Out *o = FUN_a013cd4c(port);
    unsigned short m;

    m = o->h28;
    if (m > 0x32)
        m = 0x32;
    o->h2e = o->h28 - m;
    o->h30 = o->h28 + m;
    m = o->h2a;
    if (m > 0x32)
        m = 0x32;
    o->h32 = o->h2a - m;
    o->h34 = o->h2a + m;
    o->h36 = 0;
    if (FUN_a0121258(port))
        o->h38 = o->h10 * 2 - o->h18 - 3;
    else
        o->h38 = o->h10 - o->h18 - 3;
}
