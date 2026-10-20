/* leon2m FUN_a0148540 @ 0xa0148540  (hand; byte-exact at -mcpu=v8 -O3 -g)
 *
 * Asks whether the input port behind display channel ch is flagged in the port bitmask at 0xA802CBD4.
 *   1. remap(ch): channels 0..3 map to themselves; anything else prints "SYS remapping channel OOR" (string
 *      0x1A6DD8) and uses channel 0. (The same inline function is in FUN_a0145360.)
 *   2. Bits 12..15 of the first word of the channel's 0x78-byte record at 0xA802DF30 + 0x78 * ch give a port
 *      number P.
 *   3. FUN_a0140098(P) returns bit P of the byte at 0xA802CBD4.
 * Who sets that bit: FUN_a013f370(port) sets bit 'port' of 0xA802CBD4 when bit 0x400 of that port's status
 * halfword (0xA802E224 + 0x2A * port) is set, and clears it otherwise.
 * FUN_a00dac38 calls FUN_a0148540(0). When it returns 1 the panel row is chosen from the
 * measured line rate (hfreq * 2160 / active * 1000 / 2348) instead of the vertical refresh rate.
 */
struct Chan { unsigned int w0; unsigned char rest[0x74]; };   /* display channel record, 0x78 bytes */
extern struct Chan DAT_a802df30[4];
extern int FUN_a00df170();                     /* debug printf */
extern char s_001a6dd8[];                      /* "SYS remapping channel OOR\r\n" */
extern unsigned char FUN_a0140098(unsigned char);   /* bit n of DAT_a802cbd4 */

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

unsigned char FUN_a0148540(unsigned char ch)
{
    unsigned char i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    return FUN_a0140098((DAT_a802df30[i].w0 >> 12) & 0xf);
}
