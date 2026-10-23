/* FUN_a0143db8 (leon2m 0xa0143db8-0xa0143e70, 184 bytes), flags -mcpu=v8 -O3 -g.
 * Returns 1 when byte 2 of the 42-byte record DAT_a802e224[(word 0 of channel record c) >> 12 & 0xf] equals 4,
 * else 0. c = &DAT_a802df30[i], the 0x78-byte records at 0xa802df30, where i = remap(ch); a value of i above 3
 * calls FUN_a00df170 with "SYS remapping channel OOR" (s_001a6dd8) and uses channel 0. Same lookup as
 * FUN_a0143ff0. Source form: the channel record address is taken into the pointer local c first; indexing the
 * array inside the expression puts the operands of the word load the other way round ([base + index]).
 */
struct Chan { unsigned int w0; unsigned char rest[0x74]; };   /* 0x78-byte record */
extern struct Chan DAT_a802df30[4];
struct Tab42 { unsigned char data[42]; };
extern struct Tab42 DAT_a802e224[];
extern int FUN_a00df170();                     /* formatted output (vsnprintf) */
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

unsigned char FUN_a0143db8(unsigned char ch)
{
    unsigned char i = remap(ch);
    struct Chan *c;
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    c = &DAT_a802df30[i];
    return DAT_a802e224[(c->w0 >> 12) & 0xf].data[2] == 4;
}
