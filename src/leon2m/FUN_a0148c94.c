/* leon2m FUN_a0148c94 @ 0xa0148c94  MATCH (-mcpu=v8 -O3 -g, twin)
 * Twin of FUN_a0148540: same code, constants swapped; byte-exact.
 */
struct Chan { unsigned int w0; unsigned char rest[0x74]; };   /* display channel record, 0x78 bytes */
extern struct Chan DAT_a802df30[4];
extern int FUN_a00df170();                     /* debug printf */
extern char s_001a6dd8[];                      /* "SYS remapping channel OOR\r\n" */
extern unsigned char FUN_a0121258(unsigned char);   /* bit n of DAT_a802cbd4 */

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

unsigned char FUN_a0148c94(unsigned char ch)
{
    unsigned char i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    return FUN_a0121258((DAT_a802df30[i].w0 >> 12) & 0xf);
}
