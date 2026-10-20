/* leon2m FUN_a014505c @ 0xa014505c-0xa014512c (52 words).
 * Returns 1 when FUN_a014230c(FUN_a0142168(byte 0xa of the port record)) is non-zero, else 0. The port record is
 * entry (bits 12..15 of the first word of display channel record ch) of the 42-byte records at 0xa802e224. A
 * channel number outside 0..3 prints "SYS remapping channel OOR" and uses channel 0. Same lookup as FUN_a0143ff0.
 */
struct Chan { unsigned int w0; unsigned char rest[0x74]; };   /* display channel record, 0x78 bytes */
extern struct Chan DAT_a802df30[4];
struct Tab42 { unsigned char data[42]; };
extern struct Tab42 DAT_a802e224[];
extern int FUN_a00df170();                     /* debug printf */
extern char s_001a6dd8[];                      /* "SYS remapping channel OOR\r\n" */
extern int FUN_a0142168(unsigned char);
extern unsigned char FUN_a014230c(unsigned char);

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

unsigned char FUN_a014505c(unsigned char ch)
{
    unsigned char ok = 0;
    unsigned char i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    if (FUN_a014230c(FUN_a0142168(DAT_a802e224[(DAT_a802df30[i].w0 >> 12) & 0xf].data[0xa]) & 0xff))
        ok = 1;
    return ok & 1;
}
