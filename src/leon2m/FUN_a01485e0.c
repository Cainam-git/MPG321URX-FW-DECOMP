/* leon2m FUN_a01485e0 @ 0xa01485e0 (-mcpu=v8 -O3 -g, twin of FUN_a0148540)
 * Asks whether the input port behind channel ch is flagged in the port bitmask at 0xA802CBD3: channel
 * remap 0..3 (else "SYS remapping channel OOR" and channel 0), port P = bits 12-15 of the channel record's first
 * word (0xA802DF30 + 0x78 * ch), FUN_a01400bc(P) = bit P of 0xA802CBD3. FUN_a013f370(port) sets that bit when bit
 * 0x80 of the port status halfword (0xA802E224 + 0x2A * port) is set.
 * Callers: FUN_a008380c (APPGetFRCMode).
 */
struct Chan { unsigned int w0; unsigned char rest[0x74]; };   /* display channel record, 0x78 bytes */
extern struct Chan DAT_a802df30[4];
extern int FUN_a00df170();                     /* debug printf */
extern char s_001a6dd8[];                      /* "SYS remapping channel OOR\r\n" */
extern unsigned char FUN_a01400bc(unsigned char);   /* bit n of DAT_a802cbd3 (set by FUN_a013f370 from port status bit 0x80) */

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

unsigned char FUN_a01485e0(unsigned char ch)
{
    unsigned char i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    return FUN_a01400bc((DAT_a802df30[i].w0 >> 12) & 0xf);
}
