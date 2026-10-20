/* leon2m FUN_a013cd4c @ 0xa013cd4c-0xa013cda8 (23 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/23 mismatches. Twin of FUN_a013ce10.
 * Code facts: leaf; scans the 4 port records DAT_a802df30[i] (0x78 bytes each: i*15*8) for i = 0..3
 * (u8 counter, cmp 3; bleu) and returns &DAT_a802df30[i] for the first one whose word +0 bits
 * 12..15 ((w >> 12) & 0xf) equal id (u8 param); NULL when none matches.
 * Fixes vs the autoc draft (53.85 / 50.00): one struct array of 0x78-byte records indexed by i (the
 * draft carried a byte offset), a plain for loop with an early return. Aids: none.
 */
struct Port { unsigned int w00; unsigned char pad[0x78 - 4]; };
extern struct Port DAT_a802df30[4];

struct Port *FUN_a013cd4c(unsigned char id)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        if (id == ((DAT_a802df30[i].w00 >> 12) & 0xf))
            return &DAT_a802df30[i];
    }
    return 0;
}
