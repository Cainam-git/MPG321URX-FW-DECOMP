/* leon2m FUN_a0144298 @ 0xa0144298-0xa0144350 (46 words).
 * Returns 1 when byte 9 of the port record selected by channel ch equals 5, else 0. The port record is
 * entry (bits 12..15 of the channel's first word) of the 42-byte records at 0xa802e224; the channel record is entry
 * ch of the 0x78-byte records at 0xa802df30. A channel number outside 0..3 prints "SYS remapping channel OOR" and
 * uses channel 0. Same lookup as FUN_a0143ff0.
 */
struct Chan { unsigned int w0; unsigned char rest[0x74]; };   /* display channel record, 0x78 bytes */
extern struct Chan DAT_a802df30[4];
struct Tab42 { unsigned char data[42]; };
extern struct Tab42 DAT_a802e224[];
extern int FUN_a00df170();                     /* debug printf */
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

unsigned char FUN_a0144298(unsigned char ch)
{
    unsigned char i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    return DAT_a802e224[(DAT_a802df30[i].w0 >> 12) & 0xf].data[9] == 5;
}
