/* leon2m FUN_a0148aec @ 0xa0148aec-0xa0148bc4 (54 words).
 * Calls FUN_a00f93a0(port, a, b) with port = bits 12..15 of the first word of channel record ch (the
 * 0x78-byte records at 0xa802df30). A channel number outside 0..3 prints "SYS remapping channel OOR" and uses
 * channel 0.
 */
struct Chan { unsigned int w0; unsigned char rest[0x74]; };   /* 0x78-byte record */
extern struct Chan DAT_a802df30[4];
extern int FUN_a00df170();                     /* formatted output (vsnprintf) */
extern char s_001a6dd8[];                      /* "SYS remapping channel OOR\r\n" */

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

extern void FUN_a00f93a0(unsigned char, unsigned short, unsigned short);

void FUN_a0148aec(unsigned char ch, unsigned short a, unsigned short b)
{
    unsigned char i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    FUN_a00f93a0((DAT_a802df30[i].w0 >> 12) & 0xf, a, b);
}
