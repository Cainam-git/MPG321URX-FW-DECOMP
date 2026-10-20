/* leon2m FUN_a01438dc @ 0xa01438dc-0xa014398c (44 words), flags -mcpu=v8 -O3 -g.
 * Code facts: i = remap(ch) (0..3, else print s_001a6dd8 "SYS remapping channel OOR" and use 0); returns bit 6 of
 * the u16 at +0 of port record 0xa802e224[(DAT_a802df30[i].w0 >> 12) & 0xf] (0x2a-byte records).
 * Same remap helper as src/leon2m/FUN_a0143f0c.c.
 * Source form: u8 i (fw 'and 0xff' after the remap), struct records (0x78-byte channel, 0x2a-byte port),
 * u8 return. Aids: none.
 */
struct Chan { unsigned int w0; unsigned char pad[0x74]; };
struct Port { unsigned short h00; unsigned char rest[0x28]; };
extern struct Chan DAT_a802df30[4];
extern struct Port DAT_a802e224[];
extern int FUN_a00df170();
extern char s_001a6dd8[];

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

unsigned char FUN_a01438dc(unsigned char ch)
{
    unsigned char i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    return (DAT_a802e224[(DAT_a802df30[i].w0 >> 12) & 0xf].h00 >> 6) & 1;
}
