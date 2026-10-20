/* leon2m FUN_a0143e70 @ 0xa0143e70  Flags: -mcpu=v8 -O3 -g.
 * Channel 0..3 checked (otherwise prints "SYS remapping channel OOR" and uses 0); returns bit 29 of the channel
 * record word at +0x70 (DAT_a802df30[ch].w70, 0xA802DFA0 + 0x78 * ch). Called by the APP event generator
 * FUN_a0080c10 (row 1e).
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

unsigned char FUN_a0143e70(unsigned char ch)
{
    unsigned char i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    return (DAT_a802df30[i].w70 >> 29) & 1;
}
