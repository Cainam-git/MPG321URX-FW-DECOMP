/* leon2m FUN_a013bc5c @ 0xa013bc5c-0xa013bd00 (41 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Limits halfword fields of the record o = FUN_a013cd4c(port), with w = o->h16: when o->he is above 2 * w it
 * becomes w / 2 + w; when o->h1e is above o->he / 2 it becomes (o->he - w) / 2; when o->h20 is above o->h10 / 2
 * it becomes (o->h10 - o->h18) / 2. The differences are halved as signed ints.
 * Exact form: the unsigned doublings and halvings are written as shifts (<< 1, >> 1); written as * 2 and / 2 GCC
 * orders the operations differently.
 */
struct Out {
    unsigned char pad0[0xe];
    unsigned short he, h10;
    unsigned char pad12[4];
    unsigned short h16, h18;
    unsigned char pad1a[4];
    unsigned short h1e, h20;
};
extern struct Out *FUN_a013cd4c(unsigned char port);

void FUN_a013bc5c(unsigned char port)
{
    struct Out *o = FUN_a013cd4c(port);
    unsigned short w = o->h16;

    if (o->he > (unsigned short)(w << 1))
        o->he = (w >> 1) + w;
    if (o->h1e > o->he >> 1)
        o->h1e = (o->he - w) / 2;
    if (o->h20 > o->h10 >> 1)
        o->h20 = (o->h10 - o->h18) / 2;
}
