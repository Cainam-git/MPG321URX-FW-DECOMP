/* leon2m FUN_a0147064 @ 0xa0147064-0xa01470fc (38 words).
 * Returns bits 4..7 of the first word of display channel record ch (the 0x78-byte records at 0xa802df30). A channel
 * number outside 0..3 prints "SYS remapping channel OOR" and uses channel 0. Same code as FUN_a0143e70, which returns
 * bit 29 of the word at +0x70.
 */
struct Chan { unsigned int w0; unsigned char pad[0x6c]; unsigned int w70; unsigned int w74; };   /* display channel record, 0x78 bytes */
extern struct Chan DAT_a802df30[4];
extern int FUN_a00df170();                     /* debug printf */
extern char s_001a6dd8[];                      /* "SYS remapping channel OOR\r\n" */

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

unsigned char FUN_a0147064(unsigned char ch)
{
    unsigned char i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    return (DAT_a802df30[i].w0 >> 4) & 0xf;
}
