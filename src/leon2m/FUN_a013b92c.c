/* leon2m FUN_a013b92c @ 0xa013b92c-0xa013ba14 (58 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Returns 1 when the halfword +0x3c of the record FUN_a013cd4c(port) is one of 0x5b01, 0x5c01, 0x5d01, 0x800,
 * 0x5f01, 0x6001, 0x6101, 0x5800, 0x5900, 0x2200, 0x5700, 0x5a00, 0x6301 or 0x6201 (tested in that order), else 0.
 * Exact form: the first two values are one || test that returns 1 directly; the other twelve are separate ifs that
 * jump to a shared return 1 (an || chain becomes flag arithmetic, a final == test becomes a set-on-equal).
 */
struct Out { unsigned char pad[0x3c]; unsigned short h3c; };
extern struct Out *FUN_a013cd4c(unsigned char port);

unsigned char FUN_a013b92c(unsigned char port)
{
    unsigned short h = FUN_a013cd4c(port)->h3c;

    if (h == 0x5b01 || h == 0x5c01)
        return 1;
    if (h == 0x5d01)
        goto yes;
    if (h == 0x800)
        goto yes;
    if (h == 0x5f01)
        goto yes;
    if (h == 0x6001)
        goto yes;
    if (h == 0x6101)
        goto yes;
    if (h == 0x5800)
        goto yes;
    if (h == 0x5900)
        goto yes;
    if (h == 0x2200)
        goto yes;
    if (h == 0x5700)
        goto yes;
    if (h == 0x5a00)
        goto yes;
    if (h == 0x6301)
        goto yes;
    if (h == 0x6201)
        goto yes;
    return 0;
yes:
    return 1;
}
