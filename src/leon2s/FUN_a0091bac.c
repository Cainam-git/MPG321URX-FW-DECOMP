/* leon2s FUN_a0091bac @ 0xa0091bac-0xa0091be8 (15 words), flags -mcpu=v8 -Os -g.
 * Code facts: leaf; r = &ARR_a807d580[port] (0x1c-byte records, port*7*4, computed before the range
 * test); returns bit 1 of word +0x10 when port (u8) < 2, else 0.
 * Fixes vs the autoc draft (53.33): real base ARR_a807d580 (the draft used the mid-record a807d590 and
 * a byte cast), a record pointer taken before the test (as in a0091ebc). Aids: none.
 */
struct Rec { unsigned char pad[0x10]; unsigned int w10; unsigned char pad2[0x1c - 0x14]; };
extern struct Rec ARR_a807d580[];

unsigned int FUN_a0091bac(unsigned char port)
{
    struct Rec *r = &ARR_a807d580[port];
    unsigned int v = 0;

    if (port < 2)
        v = (r->w10 >> 1) & 1;
    return v;
}
