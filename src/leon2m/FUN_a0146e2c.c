/* leon2m FUN_a0146e2c @ 0xa0146e2c-0xa0146ef4 (50 words), flags -mcpu=v8 -O3 -g.
 * Twin of FUN_a0147560 (same
 * remap function and channel check), tail callee FUN_a00f6d00.
 * Code facts: mapped = u8 remap(ch) (1 / 0 / 2 / 3 -> itself, else -1; case tree rooted at 1); mapped > 3 ->
 * FUN_a00df170(s_001a6dd8 "SYS remapping channel OOR\r\n") and mapped = 0. v = bits 4..7 of word
 * DAT_a802df30[mapped] (0x78-byte records); v == 4 returns. Else FUN_a00f63bc(v) and tail FUN_a00f6d00(a, b,
 * c, d) with the four u16 params (sll/srl around the f63bc call). void.
 * Required forms: FUN_a00f63bc takes v, FUN_a00f6d00 takes 4 u16 args (its own entry overwrites
 * %i4/%i5), void. Aids: none.
 */
struct Chan { unsigned int w0; unsigned char rest[0x74]; };
extern struct Chan DAT_a802df30[4];
extern int FUN_a00df170(const char *fmt, ...);
extern int FUN_a00f63bc(int);
extern void FUN_a00f6d00(unsigned short, unsigned short, unsigned short, unsigned short);
extern char s_001a6dd8[];

static int remap(int ch)
{
    switch (ch) {
    case 1: return 1;
    case 0: return 0;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

void FUN_a0146e2c(unsigned char ch, unsigned short a, unsigned short b, unsigned short c, unsigned short d)
{
    unsigned char mapped = (unsigned char)remap(ch);
    unsigned int w;
    unsigned int v;

    if (mapped > 3) {
        FUN_a00df170(s_001a6dd8);
        mapped = 0;
    }

    w = DAT_a802df30[mapped].w0;
    v = (w >> 4) & 0xf;

    if (v == 4)
        return;

    FUN_a00f63bc(v);
    FUN_a00f6d00(a, b, c, d);
}
