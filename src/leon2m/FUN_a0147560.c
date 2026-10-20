/* leon2m FUN_a0147560 @ 0xa0147560 (-mcpu=v8 -O3 -g)
 * Twin of FUN_a01474b0: same code, other constants.
 * See FUN_a01474b0 for the explanation; this copy's constants differ, so its comments were removed.
 */
struct Chan { unsigned int w0; unsigned char rest[0x74]; };
extern struct Chan DAT_a802df30[4];
extern int FUN_a00df170(const char *fmt, ...);
extern int FUN_a00f63bc(int);
extern int FUN_a00f643c(int, int, int, int, int, int);
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

int FUN_a0147560(unsigned int param_1, unsigned int param_2, int param_3,
                 unsigned int param_4, unsigned int param_5, unsigned int param_6)
{
    unsigned char mapped = (unsigned char)remap(param_1 & 0xff);
    unsigned int w;
    unsigned int v;

    if (mapped > 3) {
        FUN_a00df170(s_001a6dd8);
        mapped = 0;
    }

    w = DAT_a802df30[mapped].w0;
    v = (w >> 4) & 0xf;

    if (v == 4) {
        return param_1 & 0xff;
    }

    FUN_a00f63bc(v);
    return FUN_a00f643c(param_2, param_2, param_3, param_4, param_5, param_6);
}
