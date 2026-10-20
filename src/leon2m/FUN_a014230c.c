/* leon2m FUN_a014230c @ 0xa014230c-0xa0142360 (21 words).
 * Returns 1 when i is 0 or 1 and bit 7 of halfword +2 of record i of the 18-byte records at 0xa802e116 is set,
 * otherwise 0 (result variable r, returned as r & 1). The record address is computed before the test.
 * Source form: the range test is a static helper returning unsigned char 1 or 0 from two return statements; GCC
 * keeps its result as a flag register that is tested afterwards. Called from FUN_a014505c.
 */
struct Rec12 { unsigned short h0, h2; unsigned char pad[0xc]; unsigned char b10, b11; };
extern struct Rec12 DAT_a802e116[7];

static unsigned char valid(unsigned int i)
{
    if (i <= 1)
        return 1;
    return 0;
}

int FUN_a014230c(unsigned int i)
{
    struct Rec12 *e = &DAT_a802e116[i];
    unsigned char r = 0;

    if (valid(i))
        if (e->h2 & 0x80)
            r = 1;
    return r & 1;
}
