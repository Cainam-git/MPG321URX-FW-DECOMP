/* leon2m FUN_a01474b0 @ 0xa01474b0  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
struct Chan { unsigned int w0; unsigned char rest[0x74]; };   /* display channel record, 0x78 bytes */
extern struct Chan DAT_a802df30[4];
extern int FUN_a00df170(const char *fmt, ...);
extern int FUN_a00f63bc(int);
extern int FUN_a00f7434(int, int, int, int, int, int);
extern char s_001a6dd8[];  /* "SYS remapping channel OOR\r\n" */

/* channel number check: 0..3 pass, anything else is -1 */
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

int FUN_a01474b0(unsigned int param_1, unsigned int param_2, int param_3,
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
    return FUN_a00f7434(param_2, param_2, param_3, param_4, param_5, param_6);
}
