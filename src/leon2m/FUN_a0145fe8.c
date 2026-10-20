/* leon2m FUN_a0145fe8 @ 0xa0145fe8  per-port full-screen fill colour. Flags: -mcpu=v8 -O3 -g (also -msoft-float).
 *
 * FUN_a0145fe8(ch, r, g, b, on): channel 0..3 (anything else: return, nothing done); FUN_a010385c(0);
 * when 'on': FUN_a0106bfc(port, r, g, b) first; then FUN_a0103808, FUN_a0118a80 and (tail call) FUN_a010aae8, all
 * with (port, r, g, b), where port = bits 12..15 of the channel record word 0 (DAT_a802df30[ch].w0).
 * Used by the colour cycler FUN_a0082b00 (row 1e: Burn In colour table) and the fill-colour tool command.
 */
struct Chan { unsigned int w0; unsigned char rest[0x74]; };   /* display channel record, 0x78 bytes */
extern struct Chan DAT_a802df30[4];
extern void FUN_a010385c(int);
extern void FUN_a0106bfc(int, int, int, int);
extern void FUN_a0103808(int, int, int, int);
extern void FUN_a0118a80(int, int, int, int);
extern int FUN_a010aae8(int, int, int, int);

/* channel number check: 0..3 pass, anything else is -1 */
static int remap(int ch)
{
    switch (ch) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

int FUN_a0145fe8(unsigned char ch, unsigned char r, unsigned char g, unsigned char b, unsigned char on)
{
    unsigned char i = remap(ch);
    if (i > 3)
        return ch;
    FUN_a010385c(0);
    if (on)
        FUN_a0106bfc((DAT_a802df30[i].w0 >> 12) & 0xf, r, g, b);
    FUN_a0103808((DAT_a802df30[i].w0 >> 12) & 0xf, r, g, b);
    FUN_a0118a80((DAT_a802df30[i].w0 >> 12) & 0xf, r, g, b);
    return FUN_a010aae8((DAT_a802df30[i].w0 >> 12) & 0xf, r, g, b);
}
