/* leon2m FUN_a0144144 @ 0xa0144144 (-mcpu=v8 -O3 -g)
 * Twin of FUN_a0143ff0: same code, other constants.
 * See FUN_a0143ff0 for the explanation; this copy's constants differ, so its comments were removed.
 */
struct Chan { unsigned int w0; unsigned char rest[0x74]; };
extern struct Chan DAT_a802df30[4];
struct Tab42 { unsigned char data[42]; };
extern struct Tab42 DAT_a802e224[];
extern int FUN_a00df170();
extern char s_001a6dd8[];
extern int FUN_a0142168(unsigned char);
extern int FUN_a0129aa4(int);

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

unsigned char FUN_a0144144(unsigned char ch)
{
    unsigned char i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    return FUN_a0129aa4(FUN_a0142168(DAT_a802e224[(DAT_a802df30[i].w0 >> 12) & 0xf].data[0xa]) & 0xff);
}
