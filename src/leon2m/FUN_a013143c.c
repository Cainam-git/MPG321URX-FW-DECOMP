/* leon2m FUN_a013143c @ 0xa013143c-0xa0131510 (53 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a01517f4.
 * Works on record port of the 0x2a-byte records at 0xa802e224. With a == 0 stores 0xff into byte +0xd. Otherwise
 * c = FUN_a00fd820(byte +0xb); for c == 0xb1, c becomes 0xff when byte 0xa802a44c is 0xff, else byte +0xa of the
 * record selected by bits 12..15 of word 0 of channel record (byte 0xa802a44c) (0x78-byte records at 0xa802df30).
 * When c is one of the 4 bytes of the ROM table 0x1a5238 {0x61, 0x51, 0x81, 0x71}, its index is stored into byte
 * +0xc; then byte +0xc is copied into byte +0xd.
 * Exact form: the table byte is read through a small static helper (inlined; it sets the compare operand order);
 * the 0xb1 replacement goes through an int local (-1 for 0xff).
 */
struct Port { unsigned char pad[0xa]; unsigned char ba, bb, bc, bd; unsigned char rest[0x1c]; };
struct Chan { unsigned int hi16 : 16, f12 : 4, lo12 : 12; unsigned char rest[0x74]; };
extern struct Port DAT_a802e224[];
extern struct Chan DAT_a802df30[];
extern unsigned char DAT_a802a44c;
extern const unsigned char DAT_001a5238[];
extern unsigned char FUN_a00fd820(unsigned char blk);

static unsigned char code_of(unsigned char i)
{
    return DAT_001a5238[i];
}

void FUN_a013143c(unsigned char a, unsigned char port)
{
    struct Port *r = &DAT_a802e224[port];
    unsigned char c, i;
    int v;

    if (a == 0) {
        r->bd = 0xff;
        return;
    }
    c = FUN_a00fd820(r->bb);
    if (c == 0xb1) {
        if (DAT_a802a44c == 0xff)
            v = -1;
        else
            v = DAT_a802e224[DAT_a802df30[DAT_a802a44c].f12].ba;
        c = v;
    }
    for (i = 0; i <= 3; i++)
        if (c == code_of(i)) {
            r->bc = i;
            break;
        }
    r->bd = r->bc;
}
