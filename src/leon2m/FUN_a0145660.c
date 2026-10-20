/* leon2m FUN_a0145660 @ 0xa0145660  input timing getter (hand; byte-exact at -mcpu=v8 -O3 -g)
 *
 * Returns field 'id' of display channel ch's input timing record (0x78-byte records at 0xA802DF30; channel number
 * through the same 0..3 remap helper as FUN_a0148540; out of range ids return 0xFFFF):
 *   0 +0x06 line rate ("hfrq" in FUN_a00dac38)   1 +0x08 vfreq (tenths of Hz)   2 port record +0x20 (port P =
 *   bits 12-15 of word +0, records 0x2A bytes at 0xA802E224)   3 code from byte +0x0A: 2 -> 1, 4 -> 2, 8 -> 3,
 *   else 0   4 +0x0E   5 +0x30   6 +0x2E   7 +0x12   8 +0x14   9 +0x16   10 +0x18 active lines ("active_in")
 *   11 +0x1A   12 +0x1E   13 +0x34   14 +0x32   15 +0x1C   16 +0x20   17 +0x2C   18 +0x38   19 +0x36
 *   20 byte +0x26   21 byte 0xA802E222 (global)   22 byte +0x3A   23 +0x3C
 * FUN_a00dac38 (row select) and FUN_a008380c (APPGetFRCMode) read the input vfreq (id 1),
 * line rate (id 0), active lines (id 10) and ids 7, 8 through this function.
 * Source order of the cases matters: the original lists case 23 between 21 and 22 (gcc emits the second-to-last
 * case block first, which is where the original has id 23).
 */
struct Chan {
    unsigned int w0; unsigned short h04, h06, h08; unsigned char b0a, b0b; unsigned short h0c, h0e, h10, h12, h14,
    h16, h18, h1a, h1c, h1e, h20, h22, h24; unsigned char b26, b27; unsigned short h28, h2a, h2c, h2e, h30, h32, h34,
    h36, h38; unsigned char b3a, b3b; unsigned short h3c; unsigned char rest[0x3a];
};
struct Port { unsigned char b[0x20]; unsigned short h20; unsigned char rest[8]; };
extern struct Chan DAT_a802df30[4];
extern struct Port DAT_a802e224[];
extern unsigned char DAT_a802e222;
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
unsigned short FUN_a0145660(unsigned char ch, unsigned int id)
{
    struct Chan *c = &DAT_a802df30[(unsigned char)remap(ch)];
    unsigned short v = 0xffff;
    switch (id) {
    case 0: v = c->h06; break;
    case 1: v = c->h08; break;
    case 2: v = DAT_a802e224[(c->w0 >> 12) & 0xf].h20; break;
    case 3:
        switch (c->b0a) {
        case 4: v = 2; break;
        case 8: v = 3; break;
        case 2: v = 1; break;
        default: v = 0; break;
        }
        break;
    case 4: v = c->h0e; break;
    case 5: v = c->h30; break;
    case 6: v = c->h2e; break;
    case 7: v = c->h12; break;
    case 8: v = c->h14; break;
    case 9: v = c->h16; break;
    case 10: v = c->h18; break;
    case 11: v = c->h1a; break;
    case 12: v = c->h1e; break;
    case 13: v = c->h34; break;
    case 14: v = c->h32; break;
    case 15: v = c->h1c; break;
    case 16: v = c->h20; break;
    case 17: v = c->h2c; break;
    case 18: v = c->h38; break;
    case 19: v = c->h36; break;
    case 20: v = c->b26; break;
    case 21: v = DAT_a802e222; break;
    case 23: v = c->h3c; break;
    case 22: v = c->b3a; break;
    }
    return v;
}
